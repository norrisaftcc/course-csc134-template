---
name: F-006-m4-fixes-and-ready
description: M4 fix pass closing all seven cohort findings; re-gate green, spot-checks clean — M4 certified Ready
---

# F-006 — M4 fix pass + Ready certification

**Date:** 2026-07-24 · **Status:** Recorded · **Branch:** `module/m4-fixes`
**Authors:** module-builder ×4 (one per file, opus), compile-warden (re-gate, haiku), Maria + Dee (persona
spot-check, sonnet) — via the `m4-fix-pass` workflow. Closes the [[F-005-m4-cohort-round1]] round.

## What changed — all seven findings closed

Fanned out per file (disjoint, parallel). The canonical GNU **g++** warning string was hardcoded into the
shared brief so the three files quoting it cannot diverge again (that divergence was issue #14).

| Issue | File | Fix |
|---|---|---|
| **#13** should-fix | assess-lab.md | Submission step now names the exact **`m4/`** folder + `cd m4` before `git add` (sets the first deep-module submission convention). |
| **#14** should-fix/bug | learn.md, apply-tutorial.md, assess-lab.md | All quotes of the `=`/`==` warning pinned to the verbatim g++ string **`suggest parentheses around assignment used as truth value [-Wparentheses]`**. (assess-lab.md's copy was missing the `[-Wparentheses]` suffix — now fixed too.) |
| **#15** should-fix | apply-tutorial.md | New optional "Two Quick Breaks" section after Stage 3: Break A (assignment-in-condition → read the `-Wall` warning → restore), Break B (dangling `else`), both instruction-based, both classified **Logic**. |
| **#16** should-fix | assess-lab.md | A-tier "distinct endings" → "four or more distinct outcome **messages**, each for a different combination of category and score," applied in the checklist, tier ladder, and rubric row. |
| #5 nit | apply-tutorial.md | Callout that the `cin` glued-digit in sample output is the keystroke echo, not a typo. |
| #6 nit | assess-lab.md | Testing note that **score 0 is valid** low-end input (range check rejects only `< 0`). |
| #7 nit | assess-lab.md | Line stating threshold **values are the student's choice** (70/40 non-binding); only rule is highest bar first. |
| #8 nit | practice-exit-ticket.md (+key) | Item 6 stem reworded to foreground the threshold-value change. |
| #9 nit | practice-exit-ticket.md (+key) | New **Item 1.5** two-branch bridge (traces `mana` `>=50 / else if >=20`, compiles clean) before the gatekeeper program. |
| #10 nit | practice-exit-ticket.md | Trace-table scratchpads added to Items 3 and 6 (mirroring Item 2). |

## Re-gate — PASS
compile-warden: all **10 `.cpp` + 6 markdown-extracted programs** compile zero-warning under
`g++ -std=c++17 -Wall -Wextra`; Mermaid parses; rubric lineage intact (4 cols, 8/6/3/3); and a grep
confirmed the **warning string now reads identically** in learn.md, apply-tutorial.md, and assess-lab.md.
The Break A/B demos are instruction-based edits, not complete programs, so the deliberate `-Wparentheses`
warning is a teaching moment, not a gate failure.

## Spot-check — clean, with one caught-and-closed follow-on
- **Dee** (assess + practice): all six items confirmed; rubric still maps every gradeable row to a stated
  requirement; no new ambiguity.
- **Maria** (learn + apply + assess): all four items confirmed. Caught one small ambiguity **in the newly
  added Break B text** — "replace your two top strength branches" could let a literalist leave the final
  `else`, yielding a *syntax* error instead of the intended silent dangling-`else` *logic* bug. **Fixed in
  the same pass**: reworded to "replace your whole strength `if / else if / else` block (delete all of it,
  paste this in its place)."

## Certification: **M4 (Decisions) is Ready**

All four LPAA beats authored ([[F-004-m4-deep-build]]), cohort-tested across three personas
([[F-005-m4-cohort-round1]]), every should-fix and nit closed, re-gate green, persona spot-checks clean.
No content blockers remain. **M4 is certified Ready** — it is the frozen exemplar M5 extends via the seam
(`_contracts/m5_menu.cpp` wraps `_contracts/m4_gatekeeper.cpp` in a loop).

**Next:** Phase 2 — the M5 (Loops) deep build, with the seam exhibit and the finish-the-80% (EIGHTY-mode)
gradient debut. Relates to [[ADR-004-two-tier-git-workflow]].
