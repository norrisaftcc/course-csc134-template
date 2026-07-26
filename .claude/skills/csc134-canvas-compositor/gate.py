#!/usr/bin/env python3
"""
Mechanical gate for CSC-134 Canvas fragments.

Enforces the sanitizer, device, and budget rules in SKILL.md against emitted HTML.
Evidence, not opinions: every finding names the file and what it saw.

    python3 .claude/skills/csc134-canvas-compositor/gate.py _outputs/canvas-html/m4

Exit status is 1 if anything failed, so it works in a pre-merge check.
"""
import re, sys, glob, os, html

FAILS, NOTES = [], []
def fail(f, m): FAILS.append((os.path.basename(f), m))
def note(f, m): NOTES.append((os.path.basename(f), m))

MONO = "ui-monospace,SFMono-Regular,Menlo,Consolas,monospace"


def check_boxes(path, body):
    """Every box row must be exactly the same width or the borders shear.

    For each line opening a box (┌...┐) find its left/right columns, then locate the
    line that closes it (└...┘) and require the corners to sit at the same columns.
    """
    lines = body.split("\n")
    for i, line in enumerate(lines):
        if "┌" not in line:
            continue
        L, R = line.index("┌"), line.rindex("┐") if "┐" in line else None
        if R is None:
            fail(path, f"box opened at line {i+1} with no closing ┐")
            continue
        for j in range(i + 1, len(lines)):
            nxt = lines[j]
            if "└" in nxt:
                lc = nxt.index("└")
                rc = nxt.rindex("┘") if "┘" in nxt else None
                if rc is None:
                    fail(path, f"box closed at line {j+1} with no ┘")
                elif (lc, rc) != (L, R):
                    fail(path, f"box borders shear: top ({L},{R}) vs bottom ({lc},{rc})")
                break


def check(path, reference=False):
    """reference=True relaxes two rules for imported material that legitimately
    predates them: the provenance header, and the ADR-013 Haiku freeze."""
    src = open(path, encoding="utf-8").read()
    dial = re.search(r'<!--\s*compositor:\s*(M\d)\s*(?:·|&middot;)\s*(\w+)', src)
    beat = dial.group(2).lower() if dial else None

    # ---------- sanitizer ----------
    for tag in ["<style", "<script", "<link", "<svg", "<details", "<summary", "<input"]:
        if tag in src.lower():
            fail(path, f"forbidden tag {tag}> — the sanitizer destroys it silently")
    if re.search(r'\sclass\s*=', src):
        fail(path, "class attribute — stripped on save")
    if re.search(r'<h1[\s>]', src, re.I):
        fail(path, "<h1> present — Canvas renders the title outside the body")
    for m in re.finditer(r'(?<!max-)width\s*:\s*(\d+)px', src):
        fail(path, f"fixed px width {m.group(0)} — breaks the 375px webview")
    for m in re.finditer(r'style="([^"]*)"', src):
        st = m.group(1)
        if "background-color:" in st and not re.search(r'(?<!-)\bcolor\s*:', st.replace("background-color:", "BG:")):
            fail(path, "background-color without color — halves under high contrast")
    if "☐" in src or "☑" in src:
        fail(path, "Unicode ballot box — tofus on some Android webviews")

    # ---------- escaping inside <pre> ----------
    for m in re.finditer(r'<pre\b[^>]*>(.*?)</pre>', src, re.S):
        raw = re.sub(r'&[a-zA-Z]+;|&#\d+;', '', m.group(1))
        if "<" in raw or ">" in raw:
            bad = next(l for l in raw.split("\n") if "<" in l or ">" in l)
            fail(path, f"unescaped < or > in <pre>: {bad.strip()[:58]!r}")

    # ---------- Haiku (frozen pending ADR-013) ----------
    opens, closes = src.count("(@"), src.count("@)")
    checkins = len(re.findall(r'Haiku\s*&middot;\s*check-in', src))
    if checkins and not reference:
        fail(path, f"{checkins} Haiku check-in(s) — frozen pending ADR-013, do not emit")
    elif checkins:
        note(path, f"{checkins} Haiku check-in(s) — frozen for emitted pages (ADR-013)")
    if not (opens == closes == checkins):
        fail(path, f"rose fence: open={opens} close={closes} check-ins={checkins}")
    for m in re.finditer(r'Haiku\s*&middot;\s*([A-Za-z\- ]+)', src):
        if m.group(1).strip() != "check-in":
            fail(path, f"Haiku label must read 'check-in', saw {m.group(1).strip()!r}")

    # ---------- tables ----------
    for m in re.finditer(r'<table\b.*?</table>', src, re.S):
        if "overflow-x:auto" not in src[:m.start()][-260:]:
            fail(path, "table not wrapped in an overflow-x:auto div")
        for r in re.findall(r'<tr\b.*?</tr>', m.group(0), re.S):
            n = len(re.findall(r'<t[dh]\b', r))
            if n > 2:
                fail(path, f"table row has {n} columns — two is the tier-one ceiling")
                break

    # ---------- character diagrams ----------
    for m in re.finditer(r'<pre\b[^>]*>(.*?)</pre>', src, re.S):
        body = html.unescape(m.group(1))
        if not any(c in body for c in "┌└├─│┴┬┘"):
            continue
        widths = [len(l) for l in body.split("\n") if l.strip()]
        if max(widths) > 40:
            fail(path, f"character diagram {max(widths)} cols — 40 is the hard ceiling")
        else:
            note(path, f"character diagram {max(widths)} cols")
        check_boxes(path, body)

    # ---------- placeholders ----------
    ph = len(re.findall(r'href="#(?:LINK|UPLOAD)-PENDING-', src)) + len(re.findall(r'src="UPLOAD-PENDING-', src))
    counted = sum(int(x) if x else 1 for x in re.findall(r'\[(\d*)\s*LINKS? PENDING\]', src))
    if ph != counted:
        fail(path, f"marker count {counted} != placeholder count {ph}")
    elif ph:
        note(path, f"{ph} placeholder(s), markers balanced")

    # ---------- budget ----------
    code = len(re.findall(r'<pre\b', src))
    diagram = len(re.findall(r'border-radius:6px', src))
    panel = len(re.findall(r'border-radius:4px', src))
    total = code + diagram + panel
    if beat == "apply":
        # In an Apply walkthrough the unit is the stage, not the block: code, its output,
        # and at most one check-in count as ONE breakout group. Ceiling is five stages.
        stages = len(re.findall(r'<h2[^>]*>\s*Stage\b', src, re.I))
        if stages > 5:
            fail(path, f"{stages} stages — five is the ceiling for an Apply walkthrough")
        else:
            note(path, f"{stages} stage group(s), {total} raw blocks — Apply stage rule applies")
    elif total > 5 and beat is None:
        note(path, f"{total} breakouts, no dial to check against — over the flat ceiling of five, "
                   f"but an Apply beat's stage rule may permit it. Cannot verify without a dial.")
    elif total > 5:
        fail(path, f"{total} breakouts — five is the ceiling (code={code} diagram={diagram} panel={panel})")
    else:
        note(path, f"{total} breakouts (code={code} diagram={diagram} panel={panel})")
    cautions = len(re.findall(r'2px solid #9A6700', src))
    if cautions > 1:
        fail(path, f"{cautions} cautions — one per page; a second means the first was not the common mistake")

    # ---------- provenance ----------
    if not reference:
        if "<!-- compositor:" not in src:
            fail(path, "no dial declaration — every emitted page records its module and beat")
        if "SOURCE:" not in src:
            fail(path, "no SOURCE provenance line — a reader cannot tell what to edit")


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    reference = "--reference" in sys.argv
    target = args[0] if args else "_outputs/canvas-html"
    files = sorted(glob.glob(os.path.join(target, "**", "*.html"), recursive=True))
    if not files:
        print(f"no .html found under {target}")
        return 1
    for f in files:
        check(f, reference=reference)

    print("=" * 72)
    print(f"FAILURES ({len(FAILS)})")
    print("=" * 72)
    for f, m in FAILS or []:
        print(f"  FAIL  {f:42s} {m}")
    if not FAILS:
        print("  none")
    print()
    print("=" * 72)
    print("OBSERVATIONS")
    print("=" * 72)
    for f, m in NOTES:
        print(f"  ....  {f:42s} {m}")
    print()
    print(f"{len(FAILS)} failure(s) across {len(files)} fragment(s)")
    return 1 if FAILS else 0


if __name__ == "__main__":
    sys.exit(main())
