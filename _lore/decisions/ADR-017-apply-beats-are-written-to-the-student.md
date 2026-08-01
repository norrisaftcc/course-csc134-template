# ADR-017 — Apply beats are written to the student; instructor content sits behind a boundary

**Date:** 2026-08-01 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Claude Code session
**Relates to:** [[ADR-008-two-tree-module-layout]], [[ADR-012-canvas-compositor-enters-alpha-scope]],
[[ADR-015-markdown-blocks-mirror-gated-source]] · **Context:** [[F-018-apply-beat-audience-boundary]]
**Closes:** #33 · **Unblocks:** F-008-4 (Canvas Apply page)
**Numbering note:** ADR-013 remains **reserved** and unwritten (#23, the Haiku persona). This is 017.

## Context

The Apply beat is the only beat in the course that serves two readers from one file. Learn and
Assess are student documents; the exit-ticket key is a separate file. Apply is a lesson plan a
student also reads.

That was never ruled on — it accumulated. And it produced a defect that survived a deep build,
a cohort round, a `Ready` certification, and a second cohort round.

`modules/m5/apply-tutorial.md` carried a section headed **"Instructor-only: the reference
solution"**, sitting in the middle of the student's document, whose own first sentence read:

> The finished file is `apply-menu-complete.cpp`. **Do not distribute it before the Make movement ends.**

The document instructed against distributing the answer **while containing the answer**, about
eighty lines below the exercise it answers. It was labelled correctly. **A label tells a careful
reader to skip; it does not stop a student who scrolls.**

Three synthetic students read that file end to end in [[F-017-m5-cohort-round1]] and **not one
mentioned it** — an agent handed a document has no instinct that part of it was not meant for them.
It took a tool with a hard *derived-not-duplicated* rule (the Canvas compositor, ADR-012) to make
the problem visible, and even then it reported the wrong cause: *"no student-facing source"* when
the truth was *no **separable** student-facing source*.

**The course had already solved this twice, elsewhere, and never applied it to Apply:**

| Beat | Instructor content | Boundary |
|---|---|---|
| Practice | the answer key | **a separate file** — strongest form |
| Assess (M5) | pacing, reference notes | **end-of-file heading** — `## Instructor notes (not part of the student handout)` |
| **Apply** | pacing, stall notes, reference solution | **none** — placed *before* the student reached Stage 1 |

## Decision

**1. Everything before the boundary heading is the student handout.**

Every beat file that contains instructor-only material declares it with a heading containing the
exact phrase **`not part of the student handout`**, and places all such material below it. This is
`m5/assess-lab.md`'s existing convention, promoted from local habit to course rule.

**2. The student region is written to the student.** No sentence in it directs the reader to run a
classroom. *"Ask the room…"*, *"out loud as a class"*, *"someone read it to the room"* become plain
second-person questions. The pedagogy is unchanged — an instructor can still ask the room a question
that happens to be written to the student. What is removed is **the document telling the student to
run the class.**

**3. One file, not two.** The Apply beat stays a single document serving both readers. A split into
`apply-tutorial.md` (instructor) plus a student handout was considered and **rejected** — see below.

**4. The `lpaa-gate` enforces (1).** Its `boundary` check fails any student-facing beat that holds
instructor content without a declared boundary, or that places an instructor block above one. The
rule is now mechanical rather than remembered (#54, [[F-019-lpaa-content-gate]]).

## Why one file and not two

The split is the obvious architecture and it was rejected on cost, not principle:

- **It creates a second file to keep in sync**, which is precisely the drift risk
  [[F-013-markdown-blocks-are-unversioned-copies]] documented and ADR-015 exists to stop. A student
  handout derived by hand from a lesson plan is an unversioned copy with extra steps.
- **The compositor does not need it.** ADR-012's rule is *derive, never author*. A file with a
  declared boundary is derivable — take everything above the heading. The split solves a problem the
  boundary already solved.
- **It is reversible.** Nothing here forecloses a split later; the boundary is a precondition for it.
  If the instructor material grows past a section or two, revisit.

**And the honest reason the decision was easy:** the rewrite turned out to be **four sentences**
across both Apply beats. F-018 presented three options as a real trade-off. Counting them collapsed
it — a ten-minute edit against a project. **The trade-off was an artifact of not having counted.**

## What this does not change

- **Instructor content stays in the repo.** Nothing was deleted — pacing, "where students typically
  stall," the reference-solution pointer, and the `&&` note all still exist, below the boundary.
- **Apply is still a lesson plan.** It keeps its timings, its stage structure, and its classroom
  rhythm. Only the *addressee* of four sentences changed.
- **The other beats are untouched.** Learn and Assess were already student documents; the exit-ticket
  key stays a separate file, which remains the strongest form of separation and the right one for
  answer keys specifically.
- **The Make gradient is untouched.** FULL / EIGHTY / spec-only are unaffected by who a sentence
  addresses.

## Consequences

**Good.**

- A student can be handed `apply-tutorial.md` without being handed the answer, the pacing, or a note
  about where students like them typically stall.
- The Canvas Apply page becomes derivable for the first time (F-008-4), by a rule a tool can apply:
  *everything above the boundary heading.*
- Every future Apply beat inherits a stated convention instead of re-deriving one, and the gate
  catches it on arrival rather than four months later.

**Costs, stated plainly.**

- **The instructor's pacing notes moved to the end of the file.** An instructor reading before class
  now scrolls past the whole session to find timings. That is a real ergonomic loss, accepted because
  an instructor reads the document once per term and a student reads it during class.
- **A single file still asks one document to do two jobs.** This decision makes that survivable, not
  ideal. If Apply beats grow substantially more instructor apparatus, the split becomes right and this
  ADR should be superseded rather than stretched.

**The meta-lesson, recorded because it is now a pattern.** Three times this month a piece of work has
been mis-sized by estimating from shape instead of counting instances — #30's fence migration (twice,
in both directions, per [[F-016-m4-fence-migration-partial]]) and this. Every time, the fix was the
same: **count first, then choose.** Cheap, and it changed the answer here.
