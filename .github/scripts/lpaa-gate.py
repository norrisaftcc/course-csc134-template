#!/usr/bin/env python3
"""
CSC-134 LPAA content gate — the third gate, and the one that checks the claims.

    compile-gate.sh   does the C++ build?              (ADR-014)
    markdown-gate.sh  is this listing the real file?   (ADR-015)
    lpaa-gate.sh      is what the repo SAYS about itself true?   <- this one

WHY THIS EXISTS (issue #54)

Six false status claims shipped in one week. Every one was mechanically
checkable, and no gate could see any of them, because neither existing gate
knows what an LPAA beat is:

  m4/_assess-spec.STUB.md   "NOT YET AUTHORED" in a module certified Ready
  m5/_assess-spec.STUB.md   the same
  m7/learn.md               claimed MLO 7.4 while three sibling files disclaimed it
  m8/_overview.md           "structure-only skeleton pass" after the Learn beat landed
  ADR-015 / compile-gate.yml "EXPECTED RED until M4's 23 blocks are migrated"
  breadth-pass-ledger.md    its own status line, and two done-but-unticked boxes

The pattern, stated once: FINISHING A PIECE OF WORK IS WHAT MAKES THE
SURROUNDING STATUS TEXT FALSE. Nobody writes a stale claim on purpose; they
write a true one and then make it false somewhere else.

WHAT THIS GATE DOES NOT DO: judge whether content is any good. That needs a
cohort round (#21, F-017) and cannot be automated. This gate checks a much
cheaper and much more boring property -- that the repo's structural claims about
itself are true.

---------------------------------------------------------------------------
THE CHECKS
---------------------------------------------------------------------------

  1  status-files    MODULES.md's status implies a file set. Assert it.
  2  frontmatter     `module:` and `lpaa_beat:` agree with the path they sit at.
  3  stale-stub      No "NOT YET AUTHORED" inside a Built/Ready module.
  4  key-leak        A student-facing beat never links its own answer key.
  5  boundary        Instructor content sits behind a declared boundary heading.
  6  open-questions  `- [ ]` items are reported for review against _lore/decisions/.
                     REPORT ONLY -- whether a ruling closes an item is a human call.

---------------------------------------------------------------------------
THE DIALS
---------------------------------------------------------------------------

    MODULES_INDEX=modules/MODULES.md   # where the status table lives
    MODULES_ROOT=modules               # the module tree to walk
    STRICT=1                           # exit nonzero on violations (default: 0)
    ONLY=status-files,boundary         # run a subset of checks

Default is STRICT=0 so a local run reports rather than fails; CI runs it
ENFORCING as of 2026-08-01.

It shipped reporting-only on purpose. ADR-015 §6 shipped the markdown gate
enforcing-and-red and that worked -- but it worked because the debt was already
measured at 23 blocks. Here the debt was unmeasured until the first run, and a
gate that goes red before anyone knows how red is a gate people learn to ignore.
Measure first, pay it down, then enforce.

There turned out to be nothing to pay down: clean on the first run and clean
across every merge since, which is the only reason the flip needed no migration.
"""

import os
import re
import sys
from pathlib import Path

MODULES_INDEX = os.environ.get("MODULES_INDEX", "modules/MODULES.md")
MODULES_ROOT = os.environ.get("MODULES_ROOT", "modules")
STRICT = os.environ.get("STRICT", "0") == "1"
ONLY = [c for c in os.environ.get("ONLY", "").split(",") if c]

_tty = sys.stdout.isatty() or os.environ.get("GITHUB_ACTIONS")
BOLD, RED, GREEN, YELLOW, DIM, OFF = (
    ("\033[1m", "\033[31m", "\033[32m", "\033[33m", "\033[2m", "\033[0m")
    if _tty else ("", "", "", "", "", "")
)

# The beat files a module may hold, and the beat each one claims in frontmatter.
BEATS = {
    "learn.md":                    "Learn",
    "practice-exit-ticket.md":     "Practice",
    "practice-exit-ticket-key.md": "Practice",
    "apply-tutorial.md":           "Apply",
    "assess-lab.md":               "Assess",
}
STUDENT_FACING = {"learn.md", "practice-exit-ticket.md", "apply-tutorial.md", "assess-lab.md"}
KEY_FILES = {"practice-exit-ticket-key.md"}

# Status -> the beat files that status asserts are present.
# Ready and Built assert the same file set; Ready adds a cohort-finding requirement.
STATUS_REQUIRES = {
    "Skeleton":   set(),
    "First pass": {"learn.md"},
    "Built":      set(BEATS),
    "Ready":      set(BEATS),
}

BOUNDARY_HEADING = "not part of the student handout"
# Phrases that only ever address an instructor. Deliberately narrow: this gate
# flags STRUCTURE, not tone, and a false positive here costs an author real time.
INSTRUCTOR_MARKERS = [
    re.compile(r"^#+\s*instructor[- ]only\b", re.I | re.M),
    re.compile(r"^#+\s*instructor notes?\b", re.I | re.M),
]
STALE_STUB = re.compile(r"NOT YET AUTHORED", re.I)


class Finding:
    def __init__(self, check, path, msg, detail=""):
        self.check, self.path, self.msg, self.detail = check, path, msg, detail


def read(p):
    try:
        return Path(p).read_text(encoding="utf-8", errors="replace")
    except OSError:
        return None


def frontmatter(text):
    """Return the YAML-ish frontmatter as a dict of the scalar keys we care about."""
    if not text.startswith("---"):
        return {}
    end = text.find("\n---", 3)
    if end < 0:
        return {}
    out = {}
    for line in text[3:end].split("\n"):
        m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*):\s*(.+?)\s*$", line)
        if m:
            out[m.group(1)] = m.group(2).strip().strip('"').strip("'")
    return out


def parse_index(path):
    """Parse MODULES.md's status table -> {module_id: status}.

    Reads the vocabulary from the file rather than hard-coding a second copy;
    a gate that keeps its own list of statuses becomes the next stale claim.
    """
    text = read(path)
    if text is None:
        return None, f"cannot read the module index at {path}"
    rows = {}
    for line in text.split("\n"):
        m = re.match(r"^\|\s*\*\*(M\d)\*\*\s*\|[^|]*\|\s*\*?\*?([^|*]+?)\*?\*?\s*\|", line)
        if m:
            rows[m.group(1)] = m.group(2).strip()
    if not rows:
        return None, f"found no module rows in {path} — has the table shape changed?"
    bad = {mid: st for mid, st in rows.items() if st not in STATUS_REQUIRES}
    if bad:
        return None, ("unknown status %s in %s — the gate's vocabulary and the index disagree"
                      % (", ".join(sorted(set(bad.values()))), path))
    return rows, None


# --------------------------------------------------------------------------
# The checks
# --------------------------------------------------------------------------

def check_status_files(index, found):
    """1 — the status claims a file set. Assert it."""
    for mid, status in sorted(index.items()):
        d = Path(MODULES_ROOT) / mid.lower()
        if not d.is_dir():
            found.append(Finding("status-files", str(d),
                                 f"{mid} is listed as `{status}` but has no directory"))
            continue
        present = {b for b in BEATS if (d / b).is_file()}
        required = STATUS_REQUIRES[status]

        for missing in sorted(required - present):
            found.append(Finding("status-files", str(d / missing),
                                 f"{mid} is `{status}`, which requires {missing} — it is absent"))
        # A First pass module holding a lab is not a filing error; it is a status
        # that went stale when someone authored past it. That is check 1's whole point.
        for extra in sorted(present - required):
            if status in ("Skeleton", "First pass"):
                found.append(Finding("status-files", str(d / extra),
                                     f"{mid} is `{status}`, which does not claim {extra} — "
                                     f"the file exists, so the STATUS is what is stale"))


def check_frontmatter(index, found):
    """2 — `module:` and `lpaa_beat:` agree with the path."""
    for mid in sorted(index):
        d = Path(MODULES_ROOT) / mid.lower()
        for fname, beat in BEATS.items():
            p = d / fname
            if not p.is_file():
                continue
            fm = frontmatter(read(p) or "")
            if not fm:
                found.append(Finding("frontmatter", str(p), "no frontmatter block"))
                continue
            if fm.get("module") != mid:
                found.append(Finding("frontmatter", str(p),
                                     f"declares module: {fm.get('module')!r}, but sits in {mid}"))
            if fm.get("lpaa_beat") != beat:
                found.append(Finding("frontmatter", str(p),
                                     f"declares lpaa_beat: {fm.get('lpaa_beat')!r}, "
                                     f"but {fname} is the {beat} beat"))


def check_stale_stub(index, found):
    """3 — F-014 §5, as one grep. This exact defect shipped twice."""
    for mid, status in sorted(index.items()):
        if status not in ("Built", "Ready"):
            continue
        d = Path(MODULES_ROOT) / mid.lower()
        if not d.is_dir():
            continue
        for p in sorted(d.glob("*.md")):
            text = read(p) or ""
            if STALE_STUB.search(text):
                found.append(Finding("stale-stub", str(p),
                                     f"says NOT YET AUTHORED inside {mid}, which is `{status}`",
                                     "A shipped module telling readers it is unauthored is F-014 §5."))


def check_key_leak(index, found):
    """4 — a student-facing beat must not hand out the answer key."""
    for mid in sorted(index):
        d = Path(MODULES_ROOT) / mid.lower()
        for fname in sorted(STUDENT_FACING):
            p = d / fname
            if not p.is_file():
                continue
            text = read(p) or ""
            for key in KEY_FILES:
                if key in text:
                    found.append(Finding("key-leak", str(p),
                                         f"references {key} — a student-facing beat links its own key"))


def check_boundary(index, found):
    """5 — instructor content lives behind a declared boundary (F-018).

    A label is not a boundary. `### Instructor-only:` tells a careful reader to
    skip; it does not stop a student who scrolls. M5's Apply beat shipped a
    section headed "Instructor-only: the reference solution", whose own first
    sentence said not to distribute it, eighty lines below the exercise it
    answered -- inside the file handed to students.
    """
    for mid in sorted(index):
        d = Path(MODULES_ROOT) / mid.lower()
        for fname in sorted(STUDENT_FACING):
            p = d / fname
            if not p.is_file():
                continue
            text = read(p) or ""
            hits = [m for pat in INSTRUCTOR_MARKERS for m in pat.finditer(text)]
            if not hits:
                continue
            hit = text.lower().find(BOUNDARY_HEADING)
            if hit < 0:
                found.append(Finding("boundary", str(p),
                                     "holds instructor-only content with no declared boundary",
                                     f'Add a heading containing "{BOUNDARY_HEADING}" and put it below.'))
                continue
            # Compare against the START OF THE BOUNDARY'S LINE, not the phrase.
            # The phrase lives inside the heading, so a marker matching that same
            # heading starts before the phrase and would flag itself. Found on this
            # gate's first run against the real tree; the self-test pins it.
            bi = text.rfind("\n", 0, hit) + 1
            for m in hits:
                if m.start() < bi:
                    line = text[:m.start()].count("\n") + 1
                    found.append(Finding("boundary", f"{p}:{line}",
                                         f"instructor block {m.group(0).strip()!r} sits ABOVE the boundary",
                                         "Everything before the boundary heading is the student handout."))


def check_open_questions(index, found, report):
    """6 — REPORT ONLY. Unticked items, for a human to check against the rulings.

    M7's `_mlos.md` carried an open question ADR-011 had answered six days
    earlier. Whether a ruling closes an item is a judgement, so this never fails
    the gate -- it just refuses to let the list stay invisible.
    """
    decisions = sorted(Path("_lore/decisions").glob("*.md")) if Path("_lore/decisions").is_dir() else []
    report["decisions"] = len(decisions)
    for mid in sorted(index):
        d = Path(MODULES_ROOT) / mid.lower()
        if not d.is_dir():
            continue
        for p in sorted(list(d.glob("_mlos.md")) + list(d.glob("_assets.md"))):
            for i, line in enumerate((read(p) or "").split("\n"), 1):
                if re.match(r"^\s*[-*]\s*\[ \]", line):
                    report.setdefault("open_items", []).append(
                        (f"{p}:{i}", line.strip()[:96]))


CHECKS = [
    ("status-files",   check_status_files),
    ("frontmatter",    check_frontmatter),
    ("stale-stub",     check_stale_stub),
    ("key-leak",       check_key_leak),
    ("boundary",       check_boundary),
]


def main():
    print("%sCSC-134 LPAA content gate%s" % (BOLD, OFF))
    print("  index        : %s" % MODULES_INDEX)
    print("  module tree  : %s" % MODULES_ROOT)
    print("  mode         : %s" % ("ENFORCING (violations fail)" if STRICT
                                   else "reporting only (STRICT=1 to enforce)"))
    print("  checks       : does the repo's structure match what it CLAIMS")
    print("  does not     : judge whether the content is any good -- that is a cohort round")
    print()

    index, err = parse_index(MODULES_INDEX)
    if err:
        print("%sFATAL%s %s" % (RED, OFF, err))
        return 2

    print("  %d module(s) indexed: %s" % (
        len(index), ", ".join("%s=%s" % (m, s) for m, s in sorted(index.items()))))
    print()

    found, report = [], {}
    for name, fn in CHECKS:
        if ONLY and name not in ONLY:
            continue
        fn(index, found)
    if not ONLY or "open-questions" in ONLY:
        check_open_questions(index, found, report)

    by_check = {}
    for f in found:
        by_check.setdefault(f.check, []).append(f)

    for name, _ in CHECKS:
        if ONLY and name not in ONLY:
            continue
        hits = by_check.get(name, [])
        if not hits:
            print("  %sok%s     %-14s %sno violations%s" % (GREEN, OFF, name, DIM, OFF))
            continue
        print("  %sFAIL%s   %-14s %d" % (RED, OFF, name, len(hits)))
        for f in hits:
            print("           %s" % f.path)
            print("             %s" % f.msg)
            if f.detail:
                print("             %s%s%s" % (DIM, f.detail, OFF))

    items = report.get("open_items", [])
    if items:
        print()
        print("  %s%d unticked item(s)%s in _mlos.md / _assets.md %s(report only)%s"
              % (YELLOW, len(items), OFF, DIM, OFF))
        print("  %sCheck each against the %d file(s) in _lore/decisions/ — a ruling elsewhere"
              % (DIM, report.get("decisions", 0)))
        print("  does not strike an item through by itself.%s" % OFF)
        for where, line in items:
            print("    %s" % where)
            print("      %s%s%s" % (DIM, line, OFF))

    print()
    if not found:
        print("%sGATE PASSED%s — every structural claim checks out." % (GREEN, OFF))
        return 0

    print("%s%d violation(s)%s across %d check(s)." % (BOLD, len(found), OFF, len(by_check)))
    if STRICT:
        print("%sGATE FAILED%s" % (RED, OFF))
        return 1
    print("%sReporting only%s — run with STRICT=1 to make violations fail." % (BOLD, OFF))
    print("CI runs this gate ENFORCING, so anything listed above will fail there.")
    print("This local default reports instead, so a mid-edit run does not block you.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
