---
name: F-005-m4-cohort-round1
description: M4 (Decisions) cohort dry-run round 1 — three approved personas took the module end-to-end; verdict ready-with-fixes, zero blockers
---

# F-005 — M4 (Decisions) cohort dry-run, round 1

**Date:** 2026-07-24 · **Status:** Recorded · **Branch:** `cohort/m4-round1`
**Roster:** Maria (literalist / Chromebook / community-garden skin), Jaylen (skimmer / streamer-chat skin),
Dee (rules-lawyer / tavern-keeper + bouncer skin) — the three approved personas ([[F-003-module-skeleton-and-persona-review]]).
**Synthesizer:** cohort-lead (sonnet). Ran as the `m4-cohort-round1` workflow (students in isolated worktrees,
real `g++` toolchain), then a resume to recover a failed student (below).

## Verdict: `ready-with-fixes` — zero content blockers

All three personas ran the full LPAA loop independently and **converged clean**: every Learn predict-the-output
block correct, a perfect 7/7 on the Practice ticket (1B/2C/3B/4C/5D/6A/7A, all three matched the key), the Apply
Gatekeeper typed and compiled clean at every checkpoint (incl. the Deliberate Break), and each reached **B tier**
on Assess with a zero-warning `g++ -std=c++17 -Wall -Wextra` build. cohort-lead independently re-compiled the
claims: switch fall-through really emits no warning, and `if (x = 70)` really trips `-Wparentheses`. Re-skinning
survived three unrelated themes with zero gatekeeper-noun leakage into instructions or rubric — the skin/structure
separation and the no-trick-questions promise both held.

## Process note — student model tier

The first run spawned all students at **haiku**; Maria (literalist) **failed** the StructuredOutput cap (5 retries)
after 54 tool calls — a heavy literalist run overflowed haiku's structured-return reliability, not a material defect.
Recovered by resuming the workflow with **Maria at sonnet** (Jaylen/Dee/synthesis replayed from cache). Operational
lesson for future cohorts: keep students on haiku by default, but **escalate the literalist (and any deep-audit
persona) to sonnet** — the schema-conformance burden on top of heavy tool use is where haiku drops out. See
[[fleet-model-tiering-preference]].

## Consolidated findings (union of both synthesis passes + raw persona findings)

Deduped across the 2-student and 3-student synthesis passes (round-2 was not a strict superset of round-1, so both
are folded in here). None block; all are one-to-few-line edits.

### should-fix
1. **Assess — submission folder is never named.** The rubric grades files being "in the correct folder," but the
   Submission steps go straight from `git pull` to `git add m4lab.cpp m4lab-plan.md` with no path / `cd` / `mkdir`.
   M4 is the first deep-built module ([[F-004-m4-deep-build]]), so there's no earlier convention to infer from.
   *(cohort-lead audit, round 1 — grep-confirmed; the exact class of unstated-step gap the literalist exists to catch.)*
   **Fix:** name the folder in one line before the `git add` step.
2. **Cross-document — two different `=`/`==` warning strings.** `learn.md` quotes an Apple-clang paraphrase;
   `assess-lab.md`'s troubleshooting quotes the real GNU **g++** wording. The course targets g++ on Codespaces, so a
   literalist searching her terminal for Learn's phrase finds it only in Assess, three artifacts later. *(Dee,
   sharpened by cohort-lead's own recompile.)* **Fix:** pin the canonical g++ string and use it identically in
   `learn.md`, `apply-tutorial.md` notes, and `assess-lab.md`. Consider a Compile-Warden harness check that any
   quoted compiler-output string matches the pinned toolchain's real output.
3. **Apply — trap-treatment asymmetry.** Trap 2 (switch fall-through) gets a guaranteed hands-on "Deliberate Break"
   where every student removes a `break;` and watches it fail; Traps 1 (`=`/`==`) and 3 (dangling `else`) get only
   Learn prose + an "instructor point-at-it" aside. *(Maria — "if it's worth 5 minutes for the switch, it feels
   worth 5 minutes for the other two.")* **Fix:** add two short optional break-it beats after Stage 3 (assignment-
   in-condition → read the `-Wall` warning → restore `==`; strip Stage-3 braces → watch the dangling `else`).
4. **Assess — A-tier "distinct endings" undefined.** "4+ distinct endings" doesn't say whether "distinct" means
   different text, different code paths, or both. *(Dee, round 1.)* **Fix:** "4+ distinct outcome **messages**, each
   for a different combination of category and score."

### nit
5. **Apply — `cin` glued-digit output** looks like a typo on first read (typed digit lands with no space after the
   prompt). *(Maria.)* Fix: one-line callout the first time it appears.
6. **Assess — model the low-end boundary.** Testing section shows 70/69 but never `score = 0` (valid input under
   `< 0 || > 100`). *(Dee, round 1.)* Fix: a `0` sample run or a one-line note that 0 is valid.
7. **Assess — thresholds not pinned / say so.** The spec leaves threshold values to the student (intentional), but a
   rules-lawyer had to read closely to confirm it wasn't a spec/rubric mismatch. *(Dee, round 2.)* Fix: one line —
   "your thresholds needn't match the model's; only rule is highest bar first."
8. **Practice — Item 6 wording** foregrounds the line number, not the threshold-value reasoning being tested. *(Dee,
   round 1.)*
9. **Practice — Item 1→2 jump** from plain `if/else` to the full 4-branch compound chain; an optional 2-branch
   bridge item would scaffold. *(Jaylen, round 1.)*
10. **Practice — trace-table scratchpad** helped on Item 2; Maria wanted one on Items 3 and 6 too. *(Maria, wish.)*

### model-noise (excluded — not material defects)
Jaylen's "add 'clean compile ≠ correct'" (already in `apply-tutorial.md` twice) · "default isn't explained" (it is,
`learn.md` line ~171) · a stale-binary hiccup (his own recompile habit) · and a **fabricated** claim that
`work/apply.cpp` arrived pre-filled (no such scaffold exists — caught by cohort-lead in round 2). These are
weak-novice-simulation artifacts, filtered out so they don't masquerade as course bugs.

## What worked (preserve)
Predict-then-verify matched the material's stated output for all three personas · the three traps named up front
(no gotchas) · the Deliberate Break was independently the single most memorable moment for all three · flowchart-
first caught a real design error before code (Maria almost mis-ordered the compound branch, then self-corrected) ·
tier-stopping language was legible enough that all three made a deliberate, documented B-tier choice · re-skin
survived three themes cleanly.

## Instructor-guide harvest (→ M4 instructor guide when written)
- Name fall-through "the trap with zero compiler warning" out loud before students hit it.
- Pre-warn the compound-`&&`-ordering trap before Assess — all three discovered "order it first or it's unreachable."
- Predict reveals are honor-system `<details>` gates — tell students to write the guess before expanding.
- Until finding #1 ships, state the submission folder verbally / in the LMS.
- Until finding #3 ships, expect to manually walk Traps 1 & 3 (no student is currently forced through them).

## Next
Fix pass (module-builder) on the above, re-gate (compile-warden), PR — **scope pending human ruling.** Raw student
feedback preserved at `_tracking/cohort/m4-round1/feedback.md`. Relates to [[F-004-m4-deep-build]],
[[ADR-004-two-tier-git-workflow]].
