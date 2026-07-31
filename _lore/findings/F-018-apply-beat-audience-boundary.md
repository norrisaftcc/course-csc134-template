---
name: F-018-apply-beat-audience-boundary
description: The Apply beats mix student handout and instructor script in one file with no boundary — including a reference solution the same file says not to distribute. The course already had the convention; Apply just never used it.
---

# F-018 — The Apply beat has no audience boundary

**Date:** 2026-07-31 · **Status:** Recorded · **Issue:** #33 · **Branch:** `module/m33-apply-instructor-boundary`

#33 asked for an audit before any authoring — *"if this is a pattern, it is bigger than M4… the fix
may be a convention rather than one document."* It is a pattern, the fix is a convention, and the
convention already existed somewhere else in the repo.

## #33's premise was half wrong, and the correction matters

The issue says M4's type-in program *"exists only in the instructor script"* and that the only place
it lives in student-readable form is the instructor's screen. **That is not what is in the file.**

`modules/m4/apply-tutorial.md` is ~700 lines and most of it is written **to the student**, in second
person, with the code to type — 124 instances of *you* / *your*. Stages 1–4, the predict-first
moments, the expected outputs and the Deliberate Break are all student-facing prose. The student
content was never missing.

**What is missing is a boundary.** The file also contains instructor-only material, unmarked, and
places it *before* the student reaches Stage 1.

The compositor's report (F-008-4) was accurate about the symptom — nothing derivable — but the
diagnosis "no student-facing source" was wrong. The accurate diagnosis is **no *separable*
student-facing source**, which needs a different fix and a much smaller one.

## The audit: three conventions for one problem

Across the two `Built`/`Ready` modules, instructor content is handled three different ways:

| File | Instructor content | Boundary |
|---|---|---|
| `m4/learn.md`, `m5/learn.md` | none | — |
| `m4/practice-exit-ticket.md`, `m5/practice-exit-ticket.md` | none — key is **a separate file** | ✅ strongest form |
| `m4/assess-lab.md` | none | — |
| `m5/assess-lab.md` | yes, **at the end** | ✅ `## Instructor notes (not part of the student handout)` |
| `m4/apply-tutorial.md` | yes, **lines 76–140, before Stage 1** | ❌ none |
| `m5/apply-tutorial.md` | yes, at the top **plus two inline sections** | ⚠️ partial — inline ones marked, top block not |

**The Apply beat is the only beat that puts instructor content in front of the student with no
boundary.** Everywhere else the course already solved this, twice, in two good ways.

## The defect that makes this more than tidiness

`m5/apply-tutorial.md` carried a section titled **"Instructor-only: the reference solution"** —
inside the student region — whose own first sentence reads:

> The finished file is `modules/m5/code/apply-menu-complete.cpp`. **Do not distribute it before the
> Make movement ends.**

The document instructs against distributing the answer **while containing the answer**, in the file
handed to students. The Make movement is the entire point of Part 2 — the one gap the student is
asked to close — and the completed validation loop sat about eighty lines below the exercise.

It was *labelled* correctly. Labelling is not a boundary: a label tells a careful reader to skip; it
does not stop a student who scrolls.

## What changed here

Applied the convention `m5/assess-lab.md` already uses, to both Apply beats:

- The top `## Instructor Notes` block moved to the end, renamed
  **`## Instructor notes (not part of the student handout)`** — 62 lines in M4, 57 in M5.
- M5's two `### Instructor-only:` sections — the reference solution and the `&&` note — moved from
  the student region into that block.
- Everything before the boundary heading is now the student handout. Nothing was rewritten, deleted,
  or reordered within a block; this is a move, and the diff should read as one.

Both gates green: compile 72 files (60 clean, 12 expected-marked), markdown 71/71.

## What is deliberately NOT fixed — and why it is a spine question

**Inline teaching directions remain in the student region.** M4 and M5 both address the instructor
mid-stage: *"Ask the room: which of the four error names is this?"*, *"Trace one path out loud as a
class."* Those are woven into the teaching prose, not separable blocks.

Removing them would change what the Apply document *is* — from a lesson plan that a student can also
read, into two documents. **#33 says that call is a spine question before it is an authoring one, and
it still is.** The three options, none taken here:

1. **Leave them.** They read as classroom colour and cost a solo student little.
2. **Rewrite them student-first** (*"Which of the four error names is this?"*) so the same sentence
   serves both readers.
3. **Split into two files** — `apply-tutorial.md` (instructor) and a student handout — which is
   what a compositor wants, and the largest change.

**The boundary landed here is a precondition for all three**, not a substitute for choosing.

## Why this was invisible for so long

The gap survived a deep build, a cohort round, a `Ready` certification, and a second cohort round.
Three synthetic students read `m5/apply-tutorial.md` end to end in round 1 (F-017) and **not one
mentioned that the answer was in their handout** — because an agent handed a document has no
instinct that part of it was not meant for them. A real student would either not notice, or notice
and say nothing.

It took a tool with a hard *derived-not-duplicated* rule (the Canvas compositor) to make it visible,
and then only as the wrong diagnosis. **This is the class of defect issue #54 proposes gating:** not
"is the content good," which needs cohorts, but "does the repo's structure match what it claims,"
which is cheap and mechanical. A one-line check — *does every file containing an instructor block
declare a boundary* — would have caught it the day M4's Apply beat was written.
