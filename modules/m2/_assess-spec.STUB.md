# M2 — Assess-beat Spec STUB

> **NOT YET AUTHORED — STUB.**
> This file describes the *shape* of the artifact the Assess beat will grade.
> It is not the lab itself. Deep-build runs the `lab-creator` skill against
> this stub (and `rubric-converter` for the final rubric) to produce the real
> assignment.

---

## What the assessed artifact WILL be (from spine)

Spine Assess one-liner: *"Receive a working C++ program; describe what it
does in your own words; draw its flowchart. (Our version of CTI's
'Perspective Flip.')"*

Unlike most later modules, **the student does not write C++ here.** The
artifact under test is the student's *reading* of a program someone else
wrote — a description and a flowchart — not a program they authored. This is
a deliberate spine choice — comprehension before composition, per PRIMM.
Deep-build should not "fix" it into a coding assignment.

---

## Acceptance criteria (type-signature style — skeleton)

```
GIVEN:
  program        : a short, complete, provided C++ source file
                   — compiles clean under g++ -std=c++17 -Wall -Wextra
                   — pre-M6 form: everything in main(), no functions
                   — NOT authored by the student; instructor/lab-provided
  student_reads(program) -> (description, flowchart)

REQUIRES (of `program`, the provided artifact):
  - clean compile, zero warnings                              [invariant]
  - single-file, pre-M6 form (no prototypes/functions)        [invariant]
  - small enough to fully trace by hand in one sitting          [TBD: size cap]

PRODUCES (student submission):
  description : prose, ~10th-grade readability
                — states, in the student's own words, what the program does
                — TBD: must it also state *why* line-by-line, or behavior-only?
  flowchart   : Mermaid flowchart (```mermaid fenced block)
                — recovers the program's actual control flow
                — TBD: does branching/looping appear in the M2 sample program,
                  or is M2's sample straight-line only (loops/branches are
                  M4/M5 content — a looping sample here would be reaching
                  ahead of the taught curriculum)?

ACCEPTANCE (informal — deep-build sharpens into checkable criteria):
  - description accurately matches program behavior
      (no invented functionality, no omitted major step)
  - flowchart's node sequence matches the program's actual statement order
  - flowchart is valid Mermaid and renders (a broken ```mermaid block fails)
  - any error-taxonomy vocabulary used is one of the four fixed words
    (Syntax / Static semantic / Runtime / Logic) — no invented synonyms
```

### Failure cases (named — not trick questions, just the ways this can miss)

- **FAIL — invented behavior**: the description claims the program does
  something it doesn't do. That's a mismatch between the student's account
  and the code — not a *logic* bug in the code itself.
- **FAIL — missing step**: description or flowchart skips a real step the
  program performs.
- **FAIL — misordered flow**: flowchart sequences steps in an order the
  program does not follow.
- **FAIL — non-rendering diagram**: the Mermaid block does not render (syntax
  error in the diagram itself).
- **FAIL — wrong taxonomy word**: student mislabels an error class, or coins
  a synonym instead of one of the four fixed words.
- **FAIL — submission**: wrong file name / folder / repo, not committed and
  pushed (student flow: commit + push, no branches — ADR-004).

**No trick questions.** All failure cases above test the stated objectives
(read comprehension + diagramming + taxonomy vocabulary) — none test stamina,
lawyer-reading, or an untaught edge case.

---

## Tier ladder (inherits `_contracts/rubric-template.md` — skeleton, not filled)

| Tier | Fixed meaning (course-wide) | M2 slot (deep-build fills this in) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; complete and passing. | [TBD] Accurate plain-language description + a flowchart that matches a **straight-line** (no branch/loop) provided program. |
| **B — depth** | One added concept or a harder case of the first. | [TBD] Provided program includes something slightly gnarlier to describe/trace (e.g., a multi-step arithmetic sequence) — still pre-M4, no branching. |
| **A — synthesis** | Concepts combined, or pushed past the taught case. | [TBD] Student also classifies a *given, seeded* error in the program by taxonomy (Syntax/Static semantic/Runtime/Logic) as part of the write-up. |
| **Badge — above & beyond** | Documentation/reflection beyond the artifact itself. | [TBD] `prompts.md` (if AI used) + a short reflection on where their first mental model of the program was wrong, and how reading it corrected that. |

## Four-column scoring table (fixed columns/order/weights — fill cells later)

| Criterion | Points | M2 slot (deep-build fills this in) |
|---|---|---|
| **Correctness** | 8 | [TBD] Description and flowchart accurately reflect what the provided program actually does. |
| **Completeness** | 6 | [TBD] Everything the attempted tier requires is present (description + flowchart + any tier-specific extra). |
| **Format** | 3 | [TBD] Readable prose; Mermaid diagram renders; **provided program still compiles clean under `g++ -std=c++17 -Wall -Wextra`** (this is the invariant the Format cell must always name for a C++ tier — here it's the *given* program's cleanliness, since the student isn't authoring the code). |
| **Submission** | 3 | [TBD] Correct file names/folder/repo; committed and pushed (ADR-004); `prompts.md` present if AI was used. |
| **Total** | **20** | |

> No hidden criteria — once authored, this page must be the whole rubric.

---

## Standing invariants (apply to every M2 artifact, not just Assess)

- **Clean compile.** Any C++ shown to students (including the provided
  Assess-beat program) builds under `g++ -std=c++17 -Wall -Wextra` — zero
  warnings, zero errors. Verified by running it, not assumed.
- **Single-file, pre-M6 form.** M2 is before M6: everything lives in `main`,
  no functions, no prototypes.
- **Four-word error taxonomy only.** Syntax / Static semantic / Runtime /
  Logic — no synonyms, no new names.
- **Mermaid flowcharts.** All diagrams are Mermaid-in-Markdown; verify they
  actually render.
- **Make-gradient position: type-in 100%** (M2–M4 band) governs the *Apply*
  beat, not Assess — the Assess artifact here is read/describe/diagram, not
  a type-in program. Do not conflate the two beats' scaffolding rules during
  deep-build.
