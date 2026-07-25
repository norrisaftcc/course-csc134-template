#!/usr/bin/env python3
"""
CSC-134 Markdown block gate — the other half of mechanical quality bar #1.

    "Every C++ block in every artifact builds under g++ -std=c++17 -Wall -Wextra
     with zero warnings and zero errors."
                                                              -- CLAUDE.md

ADR-014 built a gate over complete .cpp files and recorded what it could not see:
fenced blocks inside Markdown. Every M4 defect found this week (F-009, F-010) lived
in one of those blocks. This closes that class.

WHAT THIS DOES NOT DO: compile anything.

That is deliberate, and it is the whole design (ADR-015). A fenced block is not
source -- it is a *view* of a .cpp file that the existing compile gate already
builds. So this gate only ever answers one question:

    Is this listing a faithful view of a file the compile gate checks?

Compilation stays in compile-gate.sh. A block that is broken on purpose is an
excerpt of a file marked `// GATE: EXPECT-WARNING` (or EXPECT-ERROR), and that
marker -- not this script -- asserts the compiler behaviour. The two gates compose;
neither duplicates the other.

WHY IDENTITY AND NOT SIMILARITY (F-013): modules/m4/learn.md and its .cpp twin were
born in the SAME COMMIT, from one authoring pass, and came out non-identical. They
never drifted; they were never the same. A duplicate listing is not a copy, it is an
independent sample -- and what varies between samples is the prose, not the program.
That is exactly F-009's shape: four false claims in comments sitting on correct code.
Hence: exact text, comments included.

---------------------------------------------------------------------------
THE ANNOTATIONS -- declared on the fence's info-string, never in frontmatter.
---------------------------------------------------------------------------

    ```cpp source=modules/m4/code/learn-gate-strength.cpp
    ```cpp excerpt=modules/m4/code/apply-gatekeeper.cpp

  source=   the block is that WHOLE file.        Any difference FAILS.
  excerpt=  the block APPEARS WITHIN that file.  Any difference FAILS.

An un-annotated cpp block FAILS. There is no skip.

No line numbers (`#L18-L44`): insert a line above the slice and the anchor silently
points elsewhere while the gate stays green. `excerpt=` matches by CONTENT, so
unrelated edits to the source cannot break a match, and edits to the quoted code
always do.

Matching is exact text with exactly two rules:
  1. trailing whitespace is trimmed per line;
  2. a line whose stripped form begins `// ...` is an ELISION -- it matches zero or
     more source lines.

---------------------------------------------------------------------------
THE DIALS -- override any of these as environment variables.
---------------------------------------------------------------------------

    SEARCH_PATHS="modules"  ...        # which trees to walk
    GATED_PATHS="_contracts modules"   # trees the compile gate covers
    FAIL_ON_UNANNOTATED=0 ...          # report un-annotated blocks, do not fail
    VERBOSE=1 ...                      # print every diff in full
"""

import difflib
import os
import re
import sys
from pathlib import Path

SEARCH_PATHS = os.environ.get("SEARCH_PATHS", "_contracts modules").split()
GATED_PATHS = os.environ.get("GATED_PATHS", "_contracts modules").split()
FAIL_ON_UNANNOTATED = os.environ.get("FAIL_ON_UNANNOTATED", "1") == "1"
VERBOSE = os.environ.get("VERBOSE", "0") == "1"
DIFF_LINES = int(os.environ.get("DIFF_LINES", "24"))

_tty = sys.stdout.isatty() or os.environ.get("GITHUB_ACTIONS")
BOLD, RED, GREEN, YELLOW, DIM, OFF = (
    ("\033[1m", "\033[31m", "\033[32m", "\033[33m", "\033[2m", "\033[0m")
    if _tty else ("", "", "", "", "", "")
)

FENCE = re.compile(r"^(\s*)(`{3,}|~{3,})\s*(.*)$")
# key=value or key="value with spaces"; also bare `gate=...` for the error message.
ATTR = re.compile(r'([A-Za-z_][A-Za-z0-9_-]*)\s*=\s*("([^"]*)"|\S+)')


# --------------------------------------------------------------------------
# Extraction
# --------------------------------------------------------------------------

def fenced_cpp_blocks(path):
    """Yield (line_no, info_string, [body lines]) for every cpp block in a file.

    Tracks the opening fence's character and length so a ``` block nested inside a
    ```` block does not terminate the outer one -- the M4 skills files do this.
    """
    lines = path.read_text(encoding="utf-8", errors="replace").split("\n")
    opener = None
    info = ""
    start = 0
    buf = []
    for i, line in enumerate(lines):
        m = FENCE.match(line)
        if opener is None:
            if m:
                opener = m.group(2)
                info = m.group(3).strip()
                start = i + 1
                buf = []
        else:
            closing = (
                m
                and m.group(2)[0] == opener[0]
                and len(m.group(2)) >= len(opener)
                and not m.group(3).strip()
            )
            if closing:
                first = info.split()[0].lower() if info else ""
                if first in ("cpp", "c++", "cc", "cxx"):
                    yield start, info, buf
                opener = None
            else:
                buf.append(line)


def parse_attrs(info):
    return {
        m.group(1): (m.group(3) if m.group(3) is not None else m.group(2))
        for m in ATTR.finditer(info)
    }


# --------------------------------------------------------------------------
# Matching -- two rules, and no more (ADR-015 §3)
# --------------------------------------------------------------------------

def normalize(lines):
    """Trim trailing whitespace per line; drop leading/trailing blank lines."""
    out = [ln.rstrip() for ln in lines]
    while out and not out[0].strip():
        out.pop(0)
    while out and not out[-1].strip():
        out.pop()
    return out


def is_elision(line):
    return line.strip().startswith("// ...")


def segment(block):
    """Split a block on elisions.

    Returns (segments, leads_with_elision, trails_with_elision). Consecutive
    elisions collapse into one -- two adjacent gaps are the same gap.
    """
    segs, cur = [], []
    lead = trail = False
    seen_any = False
    for ln in block:
        if is_elision(ln):
            if not seen_any:
                lead = True
            elif cur:
                segs.append(cur)
                cur = []
            trail = True
        else:
            seen_any = True
            trail = False
            cur.append(ln)
    if cur:
        segs.append(cur)
    return segs, lead, trail


def find_run(haystack, needle, start):
    """Index of `needle` as a contiguous run in `haystack` at or after `start`."""
    if not needle:
        return start
    for i in range(start, len(haystack) - len(needle) + 1):
        if haystack[i:i + len(needle)] == needle:
            return i
    return -1


def matches(block, source, whole):
    """Does `block` match `source`?

    whole=True  (source=)  -- the block must account for the ENTIRE file.
    whole=False (excerpt=) -- the block must appear somewhere within it.

    Returns (ok, reason). A block that is nothing but an elision matches nothing:
    it asserts no content, so it cannot be a faithful view of anything.
    """
    segs, lead, trail = segment(block)
    if not segs:
        return False, "block has no content -- only elisions"

    pos = 0
    for idx, seg in enumerate(segs):
        anchored_start = (idx == 0 and not lead and whole)
        if anchored_start:
            if source[:len(seg)] != seg:
                return False, "does not match the start of the file"
            pos = len(seg)
        else:
            found = find_run(source, seg, pos)
            if found < 0:
                return False, "segment %d of %d not found in source" % (idx + 1, len(segs))
            pos = found + len(seg)

    if whole and not trail and pos != len(source):
        return False, "matches, but does not reach the end of the file (%d lines unaccounted for)" % (len(source) - pos)
    return True, ""


# --------------------------------------------------------------------------
# Reporting
# --------------------------------------------------------------------------

def under_gated_tree(target):
    parts = Path(target).parts
    return any(parts[:len(Path(g).parts)] == Path(g).parts for g in GATED_PATHS)


def show_diff(source_lines, block_lines, src_name):
    diff = list(difflib.unified_diff(
        source_lines, block_lines,
        fromfile=src_name, tofile="the Markdown listing",
        lineterm="", n=1,
    ))
    if not VERBOSE and len(diff) > DIFF_LINES:
        diff = diff[:DIFF_LINES] + ["... (%d more lines; VERBOSE=1 for all)" % (len(diff) - DIFF_LINES)]
    for ln in diff:
        print("           " + ln)


def main():
    print("%sCSC-134 Markdown block gate%s" % (BOLD, OFF))
    print("  paths        : %s" % " ".join(SEARCH_PATHS))
    print("  gated trees  : %s" % " ".join(GATED_PATHS))
    print("  un-annotated : %s" % ("a FAILURE" if FAIL_ON_UNANNOTATED else "reported only"))
    print("  compiles     : nothing -- provenance only (ADR-015); compile-gate.sh builds the sources")
    print()

    # Accept directories or individual files, matching `find $SEARCH_PATHS` in
    # compile-gate.sh. Gating one file while fixing it is the common local case.
    seen = set()
    md_files = []
    for root in SEARCH_PATHS:
        r = Path(root)
        found = [r] if r.is_file() else sorted(r.rglob("*.md"))
        for p in found:
            if p.is_file() and p.suffix == ".md" and p not in seen:
                seen.add(p)
                md_files.append(p)
    md_files.sort()
    if not md_files:
        print("%sNo Markdown files found under: %s%s" % (YELLOW, " ".join(SEARCH_PATHS), OFF))
        print("Nothing to gate. This is a configuration problem, not a pass.")
        return 2

    ok = 0
    failures = []        # (path, line, headline, kind)
    unannotated = []     # (path, line)

    for md in md_files:
        for lineno, info, body in fenced_cpp_blocks(md):
            where = "%s:%d" % (md, lineno)
            attrs = parse_attrs(info)
            src = attrs.get("source") or attrs.get("excerpt")
            whole = "source" in attrs

            if "source" in attrs and "excerpt" in attrs:
                print("  %sFAIL  %s %s" % (RED, OFF, where))
                print("         declares both source= and excerpt=; they are mutually exclusive.")
                failures.append((str(md), lineno, "declares both source= and excerpt=", "malformed"))
                continue

            if src is None:
                if "gate" in attrs:
                    # The convention has no gate= verb. Say so precisely rather than
                    # letting it read as an unrecognised-but-tolerated annotation.
                    print("  %sFAIL  %s %s" % (RED, OFF, where))
                    print("         `gate=%s` is not part of this convention. There is no skip and no" % attrs["gate"])
                    print("         expect-error verb here: a block that is broken on purpose is an")
                    print("         excerpt= of a .cpp marked `// GATE: EXPECT-WARNING`, and that marker")
                    print("         asserts the compiler behaviour. See ADR-015.")
                    failures.append((str(md), lineno, "unknown annotation gate=%s" % attrs["gate"], "malformed"))
                else:
                    print("  %sUNMIGRATED%s %s  %s(no source= or excerpt=)%s" % (YELLOW, OFF, where, DIM, OFF))
                    unannotated.append((str(md), lineno))
                continue

            target = Path(src)
            if not target.is_file():
                print("  %sFAIL  %s %s" % (RED, OFF, where))
                print("         declares %s, which does not exist." % src)
                failures.append((str(md), lineno, "source file not found: %s" % src, "missing"))
                continue

            if not under_gated_tree(src):
                print("  %sFAIL  %s %s" % (RED, OFF, where))
                print("         %s is outside the trees the compile gate covers (%s)," % (src, " ".join(GATED_PATHS)))
                print("         so matching it would prove the listing faithful to something unchecked.")
                failures.append((str(md), lineno, "source outside gated trees: %s" % src, "ungated"))
                continue

            block = normalize(body)
            source_lines = normalize(
                target.read_text(encoding="utf-8", errors="replace").split("\n")
            )
            good, why = matches(block, source_lines, whole)
            if good:
                kind = "source" if whole else "excerpt"
                print("  %smatch%s  %s  %s(%s=%s)%s" % (GREEN, OFF, where, DIM, kind, src, OFF))
                ok += 1
            else:
                print("  %sDRIFT %s %s" % (RED, OFF, where))
                print("         %s" % why)
                show_diff(source_lines, block, src)
                failures.append((str(md), lineno, why, "drift"))

    total = ok + len(failures) + len(unannotated)
    print()
    print("%s%d block(s): %d matched, %d failed, %d unmigrated%s"
          % (BOLD, total, ok, len(failures), len(unannotated), OFF))

    if unannotated:
        print()
        print("%sUnmigrated blocks by file%s  %s(the countdown -- this number only goes down)%s"
              % (BOLD, OFF, DIM, OFF))
        per_file = {}
        for path, _ in unannotated:
            per_file[path] = per_file.get(path, 0) + 1
        for path in sorted(per_file):
            print("  %3d  %s" % (per_file[path], path))

    summary_path = os.environ.get("GITHUB_STEP_SUMMARY")
    if summary_path:
        with open(summary_path, "a", encoding="utf-8") as fh:
            w = fh.write
            w("## CSC-134 Markdown block gate\n\n")
            w("Provenance only -- this gate compiles nothing. See ADR-015.\n\n")
            w("| | count |\n|---|---|\n")
            w("| matched | %d |\n| failed | %d |\n| unmigrated | %d |\n" % (ok, len(failures), len(unannotated)))
            if failures:
                w("\n### Failed\n\n")
                for path, line, why, _ in failures:
                    w("- `%s:%d` — %s\n" % (path, line, why))
            if unannotated:
                per_file = {}
                for path, _ in unannotated:
                    per_file[path] = per_file.get(path, 0) + 1
                w("\n### Unmigrated (the countdown)\n\n| file | blocks |\n|---|---|\n")
                for path in sorted(per_file):
                    w("| `%s` | %d |\n" % (path, per_file[path]))
                w("\n> These are **unmigrated, not defective**. See ADR-015 §6.\n")

    if failures:
        print()
        print("%sGATE FAILED%s — a listing is not a faithful view of its source." % (RED, OFF))
        print("Either the source changed and the listing did not, or the listing was")
        print("authored separately and never was the same. Fix the listing, not the .cpp:")
        print("the .cpp is the one the compile gate builds.")
        return 1

    if unannotated and FAIL_ON_UNANNOTATED:
        print()
        print("%sGATE FAILED%s — %d block(s) are UNMIGRATED, not defective."
              % (RED, OFF, len(unannotated)))
        print()
        print("Nothing here is known to be wrong. These blocks simply have not been")
        print("annotated yet, so the gate cannot tell whether they are wrong -- which is")
        print("the state ADR-014 recorded and ADR-015 exists to end.")
        print()
        print("This red is expected and tracked. The gate is the failing test; migrating")
        print("the blocks is the fix, in that order (ADR-015 §6).")
        issue = os.environ.get("MIGRATION_ISSUE", "")
        if issue:
            print("Tracked at: %s" % issue)
        print()
        print("To migrate a block: give it `source=<path>.cpp` if it is a whole file, or")
        print("`excerpt=<path>.cpp` if it is part of one, and make the text match exactly.")
        return 1

    if unannotated:
        print("%s%d unmigrated block(s), not failing (FAIL_ON_UNANNOTATED=0).%s"
              % (YELLOW, len(unannotated), OFF))
    print("%sGATE PASSED%s" % (GREEN, OFF))
    return 0


if __name__ == "__main__":
    sys.exit(main())
