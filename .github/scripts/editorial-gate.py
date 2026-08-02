#!/usr/bin/env python3
"""
CSC-134 Editorial gate -- an instrument for mechanical quality bar #2.

    "10th-grade readability on all student-facing prose (code excluded).
     Complexity lives in the *problem*, never in the sentence describing it.
     Linx owns the readability pass."
                                                              -- CLAUDE.md

Bar #1 ("clean compile") has two gates (ADR-014, ADR-015). Bar #2 had none: a
human read it and vouched. That is exactly the state bar #1 was in before F-009
shipped four false claims inside a module certified Ready. A pass nobody can
re-run is a pass nobody can trust. This gate gives the readability pass an
instrument it did not have (ADR-016).

WHAT THIS DOES NOT DO: overrule the editor.

That is the whole design (ADR-016). Readability formulas are proxies. A syllable
heuristic that could veto a warm, correct sentence at grade 10.2 would be the gate
dictating prose -- which ADR-015 put out of a gate's remit ("requiring pages to
carry file headers they do not want would have been the gate dictating prose").
So by default this gate REPORTS: it prints a grade per file and names the
sentences most worth a second look. Linx keeps the call; the gate informs it. Set
FAIL_ON_GRADE=1 / FAIL_ON_LONG_SENTENCE=1 to make it enforcing (CI, or a final
sweep). The asymmetry with the markdown gate -- which ships enforcing because
provenance is exact, not fuzzy -- is deliberate and recorded in ADR-016.

STE-100, DERIVED NOT ADOPTED WHOLE (ADR-016). ASD-STE100 (Simplified Technical
English) is the mature controlled-language standard for making technical prose
comprehensible. We take the parts that serve a 10th-grade reader:

  * short sentences (STE-100 caps procedural sentences near 20 words),
  * a bounded reading grade,

and we deliberately LEAVE the parts that would flatten the course's voice. The
CLAUDE.md voice section requires "GameFAQs register, not a textbook" -- warm,
second person, a little playful. STE-100's article mandates, gerund bans, and
one-approved-word-per-meaning dictionary would sand exactly that off. A gate that
enforced them would be fighting another bar. So this gate never touches word
choice or grammar; it measures length and grade, nothing that has a voice.

WHAT IT MEASURES, on PROSE ONLY:
  * Flesch-Kincaid Grade Level   -- the reading grade; the bar's own number is 10.
  * Flesch Reading Ease          -- a second view (higher = easier).
  * Over-long sentences          -- the STE-100 length rule, as an actionable list.

PROSE ONLY matters as much here as "text a student sees" did for the markdown gate
(ADR-015). Counting a `for` loop or a Mermaid node as a sentence measures the wrong
thing. So before scoring, the gate strips: YAML frontmatter, fenced code and
Mermaid, inline `code` spans, HTML, Markdown tables, headings (navigation, not
prose), and link URLs -- keeping link text. What remains is what the student reads.

---------------------------------------------------------------------------
THE DIALS -- override any of these as environment variables.
---------------------------------------------------------------------------

    SEARCH_PATHS="modules"        # which trees/files to walk (student-facing)
    TARGET_GRADE="10.0"           # the bar; files above target+BAND get flagged
    GRADE_BAND="2.0"              # tolerance above target before a file is "high"
    MAX_SENTENCE_WORDS="30"       # STE-100-derived hard cap; longer = actionable
    SKIP_META="1"                 # skip _-prefixed planning files (not student prose)
    FAIL_ON_GRADE="0"             # 1 => a file above target+BAND fails the gate
    FAIL_ON_LONG_SENTENCE="0"     # 1 => any sentence over the cap fails the gate
    VERBOSE="0"                   # 1 => print every over-long sentence, not the top few

SCOPE -- what counts as student-facing prose. The repo names builder/instructor
planning notes with a leading underscore (`_overview.md`, `_mlos.md`,
`_assets.md`, `_assess-spec.STUB.md`); the four LPAA beats do not. Bar #2 governs
"student-facing prose", so SKIP_META=1 (default) drops the `_`-prefixed files. The
answer-key files (`*-key.md`) stay in: a student reads them after the ticket.
"""

import os
import re
import sys
from pathlib import Path

SEARCH_PATHS = os.environ.get("SEARCH_PATHS", "modules").split()
TARGET_GRADE = float(os.environ.get("TARGET_GRADE", "10.0"))
GRADE_BAND = float(os.environ.get("GRADE_BAND", "2.0"))
MAX_SENTENCE_WORDS = int(os.environ.get("MAX_SENTENCE_WORDS", "30"))
SKIP_META = os.environ.get("SKIP_META", "1") == "1"
FAIL_ON_GRADE = os.environ.get("FAIL_ON_GRADE", "0") == "1"
FAIL_ON_LONG_SENTENCE = os.environ.get("FAIL_ON_LONG_SENTENCE", "0") == "1"
VERBOSE = os.environ.get("VERBOSE", "0") == "1"
TOP_N = int(os.environ.get("TOP_N", "3"))

_tty = sys.stdout.isatty() or os.environ.get("GITHUB_ACTIONS")
BOLD, RED, GREEN, YELLOW, DIM, OFF = (
    ("\033[1m", "\033[31m", "\033[32m", "\033[33m", "\033[2m", "\033[0m")
    if _tty else ("", "", "", "", "", "")
)


# --------------------------------------------------------------------------
# Prose extraction -- strip everything the student does not read AS PROSE.
# --------------------------------------------------------------------------

FENCE = re.compile(r"^(\s*)(`{3,}|~{3,})")


def extract_prose(text):
    """Return student-facing prose: code, Mermaid, tables, headings, HTML removed."""
    lines = text.split("\n")

    # 1. Drop a leading YAML frontmatter block.
    if lines and lines[0].strip() == "---":
        for i in range(1, len(lines)):
            if lines[i].strip() == "---":
                lines = lines[i + 1:]
                break

    out = []
    fence = None
    in_html_comment = False
    for line in lines:
        # 2. Fenced code / mermaid / text blocks -- skip the whole block.
        m = FENCE.match(line)
        if fence is None and m:
            fence = m.group(2)[0]
            continue
        if fence is not None:
            s = line.strip()
            if s and set(s) <= set(fence) and len(s) >= 3:
                fence = None
            continue

        # 3. HTML comments (may span lines).
        if in_html_comment:
            if "-->" in line:
                in_html_comment = False
            continue
        if "<!--" in line:
            if "-->" not in line:
                in_html_comment = True
            line = re.sub(r"<!--.*?-->", "", line)

        stripped = line.strip()

        # 4. Markdown table rows and header separators -- reference, not prose.
        if stripped.startswith("|"):
            continue
        if re.match(r"^[\s|:\-]+$", stripped) and "-" in stripped:
            continue

        # 5. Headings -- navigation, not prose. Drop the whole line.
        if stripped.startswith("#"):
            continue

        # 6. Horizontal rules.
        if re.match(r"^([-*_])\1{2,}$", stripped.replace(" ", "")):
            continue

        out.append(line)

    prose = "\n".join(out)

    # 7. Inline spans and Markdown punctuation.
    prose = re.sub(r"`[^`]*`", " code ", prose)          # inline code -> neutral word
    prose = re.sub(r"!\[[^\]]*\]\([^)]*\)", " ", prose)   # images -> gone
    prose = re.sub(r"\[([^\]]*)\]\([^)]*\)", r"\1", prose)  # links -> link text
    prose = re.sub(r"<[^>]+>", " ", prose)                # stray HTML tags
    prose = re.sub(r"https?://\S+", " ", prose)           # bare URLs
    prose = re.sub(r"[*_>#]+", " ", prose)                # emphasis / quote / heading marks
    prose = re.sub(r"^\s*[-+]\s+", "", prose, flags=re.M)  # list bullets
    prose = re.sub(r"^\s*\d+\.\s+", "", prose, flags=re.M)  # ordered-list markers
    return prose


# --------------------------------------------------------------------------
# Sentence + syllable counting (heuristic, dependency-free)
# --------------------------------------------------------------------------

def sentences(prose):
    """Split prose into sentences on terminal punctuation, across paragraphs.

    Also split on two non-prose delimiters so the over-long-sentence lint stays
    high-signal: multiple-choice options (` A) `, ` B) `, ...) are separate units,
    not one run-on; and the `.`-metadata separator (`Type: .. . MLO: .. `) fields a
    tag line, not a sentence. Both otherwise read as one 40-word "sentence".
    """
    out = []
    for para in re.split(r"\n\s*\n", prose):
        para = " ".join(para.split())
        if not para:
            continue
        # multiple-choice options: break before ' A) ', ' B) ', ... (also at start)
        para = re.sub(r"(?<!^)\s+([A-E]\))\s", r". \1 ", para)
        for chunk in re.split(r"(?<=[.!?])\s+|\s*·\s*", para):
            chunk = chunk.strip()
            if chunk:
                out.append(chunk)
    return out


WORD = re.compile(r"[A-Za-z][A-Za-z'-]*")


def words(s):
    return WORD.findall(s)


def syllables(word):
    """Vowel-group heuristic, close enough for a grade estimate."""
    w = word.lower()
    w = re.sub(r"[^a-z]", "", w)
    if not w:
        return 0
    groups = re.findall(r"[aeiouy]+", w)
    n = len(groups)
    if w.endswith("e") and not w.endswith(("le", "ie", "ee", "ye")) and n > 1:
        n -= 1                      # silent trailing 'e'
    return max(1, n)


def score(prose):
    """Return (fk_grade, reading_ease, n_sentences, n_words, over_long[list])."""
    sents = sentences(prose)
    real = []            # (sentence, word_count) for sentences with >= 3 words
    over_long = []
    total_words = 0
    total_syll = 0
    for s in sents:
        ws = words(s)
        if len(ws) < 3:                 # fragments, captions, stubs: not a sentence
            continue
        real.append((s, len(ws)))
        total_words += len(ws)
        total_syll += sum(syllables(w) for w in ws)
        if len(ws) > MAX_SENTENCE_WORDS:
            over_long.append((len(ws), s))
    n_sent = len(real)
    if n_sent == 0 or total_words == 0:
        return (None, None, 0, 0, [])
    wps = total_words / n_sent
    spw = total_syll / total_words
    fk = 0.39 * wps + 11.8 * spw - 15.59
    ease = 206.835 - 1.015 * wps - 84.6 * spw
    over_long.sort(reverse=True)
    return (round(fk, 1), round(ease, 1), n_sent, total_words, over_long)


# --------------------------------------------------------------------------
# Reporting
# --------------------------------------------------------------------------

def collect_md():
    seen, files = set(), []
    for root in SEARCH_PATHS:
        r = Path(root)
        found = [r] if r.is_file() else sorted(r.rglob("*.md"))
        for p in found:
            if p.is_file() and p.suffix == ".md" and p not in seen:
                if SKIP_META and p.name.startswith("_"):
                    continue
                seen.add(p)
                files.append(p)
    files.sort()
    return files


def main():
    print("%sCSC-134 Editorial gate%s  %s(bar #2: 10th-grade readability)%s" % (BOLD, OFF, DIM, OFF))
    print("  paths        : %s" % " ".join(SEARCH_PATHS))
    print("  target grade : %.1f  (flag above %.1f)" % (TARGET_GRADE, TARGET_GRADE + GRADE_BAND))
    print("  sentence cap : %d words" % MAX_SENTENCE_WORDS)
    print("  mode         : %s" % (
        "ENFORCING" if (FAIL_ON_GRADE or FAIL_ON_LONG_SENTENCE)
        else "advisory -- reports only (ADR-016); set FAIL_ON_GRADE=1 to enforce"))
    print("  measures     : prose only -- code, Mermaid, tables, headings stripped")
    print()

    md_files = collect_md()
    if not md_files:
        print("%sNo Markdown files under: %s%s" % (YELLOW, " ".join(SEARCH_PATHS), OFF))
        print("Nothing to gate. This is a configuration problem, not a pass.")
        return 2

    high_grade = []      # (path, grade)
    long_hits = []       # (path, count)
    grades = []
    for md in md_files:
        prose = extract_prose(md.read_text(encoding="utf-8", errors="replace"))
        fk, ease, n_sent, n_words, over_long = score(prose)
        if fk is None:
            print("  %s----%s  %s  %s(no prose to score)%s" % (DIM, OFF, md, DIM, OFF))
            continue
        grades.append((fk, str(md)))
        flagged = fk > TARGET_GRADE + GRADE_BAND
        tag = ("%sGRADE%s" % (RED, OFF)) if flagged else ("%s ok  %s" % (GREEN, OFF))
        print("  %s %s  %sgrade %s%.1f%s  ease %.0f  %d sent  %d words%s"
              % (tag, md, BOLD, "" , fk, OFF, ease, n_sent, n_words, ""))
        if flagged:
            high_grade.append((str(md), fk))
        if over_long:
            long_hits.append((str(md), len(over_long)))
            shown = over_long if VERBOSE else over_long[:TOP_N]
            print("        %s%d sentence(s) over %d words:%s"
                  % (YELLOW, len(over_long), MAX_SENTENCE_WORDS, OFF))
            for wc, s in shown:
                clip = s if len(s) <= 100 else s[:97] + "..."
                print("          %s(%d w)%s %s" % (DIM, wc, OFF, clip))
            if not VERBOSE and len(over_long) > TOP_N:
                print("          %s... %d more (VERBOSE=1 for all)%s" % (DIM, len(over_long) - TOP_N, OFF))

    print()
    if grades:
        grades.sort()
        med = grades[len(grades) // 2][0]
        worst = grades[-1]
        print("%s%d file(s) scored. median grade %.1f; highest %.1f (%s)%s"
              % (BOLD, len(grades), med, worst[0], worst[1], OFF))
    total_long = sum(c for _, c in long_hits)
    print("%d file(s) above grade %.1f; %d over-long sentence(s) across %d file(s)."
          % (len(high_grade), TARGET_GRADE + GRADE_BAND, total_long, len(long_hits)))

    failed = False
    if FAIL_ON_GRADE and high_grade:
        failed = True
        print("%sFAIL_ON_GRADE: %d file(s) above the band.%s" % (RED, len(high_grade), OFF))
    if FAIL_ON_LONG_SENTENCE and total_long:
        failed = True
        print("%sFAIL_ON_LONG_SENTENCE: %d sentence(s) over the cap.%s" % (RED, total_long, OFF))

    if failed:
        print("%sGATE FAILED%s" % (RED, OFF))
        return 1
    if not (FAIL_ON_GRADE or FAIL_ON_LONG_SENTENCE):
        print("%sReport only -- no pass/fail asserted (advisory mode, ADR-016).%s" % (DIM, OFF))
    else:
        print("%sGATE PASSED%s" % (GREEN, OFF))
    return 0


if __name__ == "__main__":
    sys.exit(main())
