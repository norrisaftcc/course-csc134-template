> ## ⚠️ NOT YET AUTHORED — STUB
> This file is a skeleton acceptance-criteria stub for the M1 Assess beat, not
> the lab. No lesson content, no worked examples, no student-facing prose lives
> here yet. The deep-build pass replaces this stub with the actual lab
> (`lab-creator` skill), instantiating the rubric below.

# M1 Assess-beat spec stub: the Robot Sandwich

**Artifact identity (per spine):** the Robot Sandwich — shared with CTI,
adopted essentially unchanged. **It contains no code.** It is a decomposition
exercise: write instructions precise enough that someone (or something) with
no context executes them literally.

---

## Acceptance criteria (type-signature style — skeleton)

Written as input → required-output contracts. Deep-build fills in the actual
task text; this stub fixes the *shape* the criteria must take.

```
submit(instructions: MarkdownDocument) -> ExecutionResult

  PRECONDITIONS:
    - instructions is a valid Markdown file (renders on GitHub)
    - instructions describes a physical/sequential task (e.g., building a
      sandwich) as an ordered list of atomic steps

  POSTCONDITIONS (must all hold for a PASS):
    - a literal-minded executor (human playing "robot," or instructor)
      following ONLY the written steps, in order, produces the intended
      result
    - no step assumes unstated context, prior knowledge, or common sense
      ("open the bag" is required if the bag is closed — do not assume
      "get the bread" implies "open the packaging first")
    - steps are atomic: one action per step, no compound instructions
      hiding two decisions in one line

  FAILURE CASES (name the class, do not invent new ones — four-word
  taxonomy still applies to the THINKING even though there's no compiler):
    - missing-step:      a required action is skipped; executor is stuck
                          or produces a broken result (maps to "logic" —
                          did what was said, not what was meant)
    - ambiguous-step:     step admits more than one literal reading, and at
                          least one reading fails (maps to "static semantic"
                          — the instruction "compiles" as language but its
                          meaning is impossible/underdetermined)
    - out-of-order-step:  steps are correct individually but sequenced
                          wrong, so an earlier step depends on something
                          only a later step provides
    - malformed-markdown: the submission itself does not render cleanly on
                          GitHub (maps to "syntax" — broke the grammar of
                          the format itself, before content is even judged)
```

**Note on the error taxonomy here:** M1 has no compiler, so "syntax /
static-semantic / runtime / logic" apply metaphorically to instruction-writing,
not literally to a build. Deep-build must decide whether to name this mapping
explicitly to students (useful foreshadowing of M2's taxonomy) or leave it
implicit. **Flagged as an open call for the deep-build author — not resolved
here.**

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the frozen template; right column is the
skeleton slot the deep-build pass fills with M1-specific requirements.

| Tier | Fixed meaning (course-wide) | M1 slot (fill in deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; complete and passing. | *(fill: a complete, literally-executable instruction set for the base task)* |
| **B — depth** | One added concept or a harder case of the first. | *(fill: e.g., branching instructions — "if no X, do Y" — or a second, harder task)* |
| **A — synthesis** | Concepts combined, or pushed past the taught case. | *(fill: e.g., instructions written for an executor with a stated constraint/limitation, or peer-tested against an actual literal-minded reader)* |
| **Badge — above & beyond** | Documentation/reflection beyond the artifact itself. | *(fill: e.g., a short reflection on where ambiguity crept in and how it was caught)* |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide; do not alter without
spine-owner sign-off.

| Criterion | Points | M1 slot (fill in deep-build) |
|---|---|---|
| **Correctness** | 8 | *(fill: does following the steps literally produce the intended result?)* |
| **Completeness** | 6 | *(fill: are all stated edge cases/tiers covered?)* |
| **Format** | 3 | *(fill: clean, readable Markdown — renders correctly on GitHub. NOTE: no C++ compile bar applies to this artifact — it contains no code.)* |
| **Submission** | 3 | *(fill: correct repo/folder/filename, committed and pushed — no branch, per ADR-004 student flow)* |
| **Total** | **20** | |

> No hidden criteria — what is on the finished lab page is the whole rubric.

---

## Standing invariants for this module (skeleton checklist)

| Invariant | Applies to M1's Assess artifact? |
|---|---|
| Clean compile (`g++ -std=c++17 -Wall -Wextra`, zero warnings) | **N/A** — the Robot Sandwich contains no C++ code. |
| Single-file convention (pre-M6 all-in-`main`) | **N/A** — no code artifact. |
| Four-word error taxonomy (syntax / static-semantic / runtime / logic) | Applies metaphorically to instruction quality (see mapping above); deep-build decides whether to surface it explicitly to students. |
| Mermaid flowcharts | Not required by the spine's M1 Assess description; deep-build may add one for the *decomposition process itself* if pedagogically useful, but it is not a stated M1 asset. |
| Make-gradient position | **N/A / pre-gradient** — M1 precedes the gradient's code-scaffold ladder (M2–M4 type-in / M5–M7 finish-80 / M8 spec-only); see `_overview.md`. |
| Rubric descends from the four columns | **Applies** — table above, inherited from `_contracts/rubric-template.md`. |
| No trick questions / no hidden criteria | **Applies** — stated above. |

---

## Cross-references

- Rubric contract: `_contracts/rubric-template.md`.
- Module identity: `modules/m1/_overview.md`.
- Asset source: `modules/m1/_assets.md` (Robot Sandwich port from CTI).
- Spine section: `_storming/CSC-134-course-spine.md`, `## M1 —` (line ~118).
