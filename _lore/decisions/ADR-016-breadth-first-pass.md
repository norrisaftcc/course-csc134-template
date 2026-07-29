# ADR-016 — The breadth pass: a Learn beat in every module, before more depth

**Date:** 2026-07-29 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Claude Code session
**Supersedes:** [[ADR-001-alpha-scope-and-locked-decisions]] Decision 1 ·
**Relates to:** [[ADR-004-two-tier-git-workflow]], [[ADR-010-m3-remap-recreate-with-salvage]],
[[ADR-011-descope-stl-and-file-io]], [[ADR-014-compile-gate-runs-on-gcc-in-ci]],
[[ADR-015-markdown-blocks-mirror-gated-source]] · **Context:** [[F-014-breadth-pass-state-audit]]
**Amends:** `_storming/ULTRACODE_ALPHA_PLAN.md` §1 and §8
**Defers:** #21 (M5 cohort round), #30 (M4 fence migration)

## Context

ADR-001 Decision 1 locked the alpha's shape:

> **Alpha = skeleton + exemplar pair.** All nine modules scaffolded; M4 and M5 built to
> full LPAA depth, with the M4→M5 seam demonstrated. (Rejected: full horizontal build at
> C-tier polish — review checkpoint before bulk spend won.)

That was the right call for the question it answered — *don't spend on nine modules before
anyone has confirmed one module is any good.* M4 has since answered that question: built,
cohort-tested across three personas, seven findings closed, certified Ready (F-006).

A new requirement arrived that the exemplar-pair shape cannot meet. Humans need to sit down
together, **open any module, and review a representative example.** Today they cannot: on
`main`, one module in nine has content. Eight hold a scaffold and a stub whose own banner
says *"NOT YET AUTHORED — STUB… do not hand this stub to students."* A review meeting that
can only ever discuss M4 is a review of M4, not of the course.

The exemplar pair proved the *recipe*. What it cannot prove is that the recipe fits M0's
"what is a program," M6's arrival of functions, or M8's capstone framing — and those are
exactly the seams a human reviewer is best placed to catch, and worst placed to catch from a
scaffold.

ADR-001's own Consequences section requires this be settled by a superseding ADR rather than
a quiet edit. This is that ADR.

## Decision

**Breadth before further depth. Every module M0–M8 gets one real, gate-green,
human-reviewable artifact before any further deep-build or cohort work runs.**

1. **The representative artifact is the Learn beat** — `modules/mN/learn.md` plus its gated
   `modules/mN/code/learn-*.cpp`. It is the beat every module has regardless of its position
   on the Make gradient, and it is what a reviewer actually reads: voice, the 10th-grade bar,
   PRIMM predict moments, the four-word error taxonomy, and real code. `modules/m4/learn.md`
   is the calibration reference; its composed pages already exist in `_outputs/canvas-html/m4/`.

2. **A new status tier: `First pass`.** A module with an authored Learn beat and nothing else
   is `First pass`. It is **not** `Built` (all four beats) and **not** `Ready` (cohort-tested,
   findings closed). Recorded in `modules/MODULES.md`. Mislabelling here is how a stub ends up
   in front of a student, so the tiers do not blur.

3. **Breadth-pass Learn beats are authored without graduate seeding.** This is the real cost
   and it is recorded rather than hidden. `ULTRACODE_ALPHA_PLAN.md` §8 says the promotion
   cycles are *"serial by design — do not 'optimize' M4 and M5 into parallel builds; the
   graduate seeding is the point."* Seven modules cannot be seeded serially at reasonable
   cost. So: **the graduate-and-teach chain is suspended for the breadth pass and resumes for
   depth work afterward.** `First pass` exists precisely because material authored without
   seeding has not earned a stronger word.

4. **New material is born ADR-015-compliant.** Every fenced ` ```cpp ` block authored in the
   breadth pass carries `source=` or `excerpt=` from the first commit. Write the `.cpp` first,
   let the compile gate build it, then quote it. The markdown gate's violation count **must
   not grow from new material** — #30's debt stays at its measured size and is paid later, not
   compounded now.

5. **M8 gets a Learn beat only.** The capstone project, its spec, and its rubric stay out of
   scope. ADR-001's exclusion of *"M8 capstone content beyond its scaffold stub"* is otherwise
   untouched — a Learn beat framing what a capstone is does not reopen it.

6. **One PR per module, human review at every PR.** ADR-004 is unchanged. Batching the breadth
   pass into one PR would destroy the exact thing this ADR exists to buy: the ability to review
   a module at a time.

7. **The `_lore/` merge gate is satisfied per module by the ledger, not by seven ADRs.** A
   breadth-pass module PR clears the gate by appending its row to
   `_tracking/breadth-pass-ledger.md` **and** recording its build notes in
   `_lore/findings/F-015-breadth-pass-recipe.md` (opened by the pilot, appended per module).
   Seven ADRs for one decision would be noise on a wall meant to be read.

8. **Per-PR gate evidence is scoped and pasted.** Both gates accept a `SEARCH_PATHS` dial, so a
   module proves itself green while the tree-wide markdown job is still red:

   ```bash
   SEARCH_PATHS=modules/mN bash .github/scripts/compile-gate.sh
   SEARCH_PATHS=modules/mN bash .github/scripts/markdown-gate.sh
   ```

   Both must exit 0, pasted into the PR body. **CI on GCC remains the authority** for the
   compile result (ADR-014) — a scoped local run is a fast loop, not evidence of silence.

9. **Deferred, not dropped:** the M5 cohort round (#21) and the M4 fence migration (#30) resume
   after the ninth Learn beat lands. Neither is cancelled; both are ahead of any new deep build
   in the queue.

## What this does not change

- Every mechanical bar in `CLAUDE.md`. A `First pass` artifact clears all nine or it is not
  done. Breadth is a statement about *how much* is authored, never about *how well*.
- **CI on GCC is the authority** (ADR-014). Faster authoring does not license a local clean-compile
  claim, and never a claim of compiler *silence*.
- ADR-010's recreate-with-salvage rule for M3, and ADR-011's descope of STL/`std::string`-as-a-topic
  and File I/O. The breadth pass is not a back door for either.
- The spine remains ground truth. A module whose Learn beat cannot be written from its spine
  section has found a spine problem, which gets an ADR and a spine patch — never a silent local fix.

## Consequences

- **The review meeting the priority asks for becomes possible.** `modules/MODULES.md` is the index;
  a reviewer picks any module and opens its `learn.md`.
- **The alpha's definition of done changes.** `ULTRACODE_ALPHA_PLAN.md` §7's exit criteria assumed
  M4+M5 depth and seven scaffolds. Breadth-pass rows are now part of the sweep.
- **M5 merges as `Built`, not `Ready`.** PR #20's only remaining blocker was #21, which this ADR
  defers. Holding a complete module out of `main` to protect a certification word costs coverage
  and buys nothing that `Built` does not already say.
- **Seven modules will carry material no synthetic student has taken.** That is the accepted risk.
  M4 looked finished too, and its cohort round surfaced seven findings — one of which no amount of
  self-review had caught. `First pass` is the label that keeps this honest, and the cohort rounds
  are queued, not cancelled.
- **Issue #33 gets a cheap partial answer.** It asks whether "no student-facing artifact" is an M4
  quirk or a course-wide pattern. Authoring the student-facing entry point in all nine modules
  answers the half that matters most; the Apply-beat half stays open.

- **Known rework risk: #23 (the Haiku persona) lands in Learn and Apply beats.** If ADR-013 later
  adopts the persona as canon, seven freshly authored Learn beats are the retrofit surface.
  Accepted, with eyes open: the alternative was choosing a representative artifact for its
  convenience to an unwritten ruling rather than for what a reviewer needs to read. **#23 becomes
  cheaper to answer, not more expensive** — the breadth pass produces the corpus a Haiku ruling
  would have to be judged against, and #23's own acceptance criteria already require a cohort
  round that "actually tests whether the rose decodes."

- **Authoring cost is front-loaded by the born-compliant rule.** M4's `learn.md` carries 8 `cpp`
  fences; seven Learn beats imply roughly 50 more, each needing a real gated `.cpp` behind it
  before it may be quoted. That is the price of the rule and it is worth paying — it is also
  precisely the work that turns CLAUDE.md bar #9 ("each stage compiles and runs standalone") from
  an assertion into a checked fact. The markdown gate's violation count still does not move.
