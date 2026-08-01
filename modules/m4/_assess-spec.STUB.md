---
> **SUPERSEDED — THE LAB IS AUTHORED.**
> The M4 Assess beat exists: **`modules/m4/assess-lab.md`**. That is the file
> students receive, and M4 is certified **Ready** (F-006).
>
> This file is kept as the **build record** — the acceptance criteria, MLO map,
> and contract the lab was authored against, as they stood at deep-build time.
> Read it to see *why* the lab asks what it asks. Two rules: never hand it to a
> student, and if it disagrees with `assess-lab.md`, **the lab wins.**
>
> *(The `.STUB` in the filename is legacy. It is kept so existing links and the
> nine-module file shape stay consistent; this banner is the authority on the
> file's status, not its name.)*
---

# M4 Assess Spec — build record

**Spine anchor:** "a decision lab from spec (the CYOA theme carries the
branching lesson twice — in the content *and* in the structure)" —
`_storming/CSC-134-course-spine.md`, M4 Assess line. **Measured by**
(learning-objectives doc): "the decision-structures (CYOA) lab."

**MLOs this artifact must exercise:** MLO 4.1 (`if`/`else if`/`else` and
`switch`), MLO 4.2 (comparison + logical operators), MLO 4.3 (flowchart →
code, and — at least once — code → flowchart). See `_mlos.md`.

**Contract this artifact builds against:** `_contracts/m4_gatekeeper.cpp` —
the frozen canonical M4 decision program (the Dungeon Gatekeeper). Deep-build
does not fork this file. It is the reference shape the lab's C-tier should
resemble in scope (switch on a class-like input, `if`/`else if`/`else` on a
threshold, one nested/compound condition — no loops, no functions).

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete values, endings, and messages at deep-build time.

```
program(class_input: int, stat_input: int, [optional_choice: int]) -> outcome_output: string

  PRECONDITIONS (what the C-tier program may assume):
    - inputs arrive in the prompted order, correct type, via cin
    - exactly one pass through the decision logic (no loops — those arrive in M5)

  POSTCONDITIONS (what "correct" means):
    - a switch statement selects a class-specific response from class_input
    - an if / else-if / else chain selects an outcome from stat_input,
      with at least three distinct branches (a high case, a middle case,
      a low case)
    - the printed outcome matches exactly one branch of a flowchart the
      student drew before writing code (Learn/Apply already establish the
      flowchart-first habit; Assess is where it's graded)
    - every branch is reachable — a branch that can never trigger given the
      stated input range is a LOGIC error, not a passing edge case

  FAILURE CASES (must be named, not just handled silently):
    - class_input outside the defined switch cases (e.g., an undefined class)
        -> C tier: the switch's `default` case handles it explicitly and
           ends the program gracefully — this is a designed branch, not a
           crash, and must be named as such
    - stat_input outside the documented range (e.g., a value above the
      stated maximum, or negative)
        -> C tier: out of scope, state so explicitly
        -> B/A tier: TBD whether this becomes a single-pass validated
           rejection (see "known trap" below — this is NOT a loop-until-
           valid check; that pattern is M5's, not M4's)
    - non-numeric input where cin expects a number (e.g., a letter typed
      for a numeric prompt)
        -> classify per the four-word taxonomy: this is a RUNTIME failure
           (cin enters a fail state) if unguarded; naming it correctly is
           part of what this lab measures (MLO 4.3 adjacent: reading a
           real failure against a program the student wrote)
```

**Known traps to resolve at deep-build, not left implicit.** These are the
classic M4-shaped C++ pitfalls. Name them on purpose — don't let a student
stumble into one as a "gotcha." That's the course's no-trick-questions rule.

- **`=` vs `==` inside a condition.** Assignment inside an `if` is legal C++
  and (almost) never what a student meant. `-Wall` catches this. The
  standing invariant below requires zero warnings for exactly this reason.
- **The dangling `else`.** Without braces, an `else` binds to the *nearest*
  `if`, not the one indentation suggests. That's a classic source of a LOGIC
  error — the code compiles clean and runs, just wrong. Deep-build should
  decide whether this is taught directly (a worked example) or left for a
  student to find via testing. If it's left for testing, the "fair warning"
  framing must say so up front — it can't spring silently.
- **`switch` fall-through.** A missing `break` after a `case` runs the next
  case too. Whether this is demonstrated as a deliberate broken example
  (Debugging-as-curriculum style, per M3's precedent) or just named in the
  reading is a deep-build call.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template. The right column records the
**candidates as they stood at spec time** — some were adopted, some changed.
**`modules/m4/assess-lab.md` carries the requirements that actually shipped;**
read this column for the reasoning, never for the current ask.

| Tier | Fixed meaning (course-wide) | M4 candidate at spec time |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] A flowchart (Mermaid) drawn first, then a program using `switch` for one input and `if`/`else if`/`else` (3+ branches) for another, matching the flowchart, compiling clean. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: a compound condition (`&&`/`\|\|`/`!`) that changes an outcome, plus a single-pass input-validation check (graceful `default`/`else` exit, no crash — not a validation loop). |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: a real branching tree with 4+ distinct endings depending on a mix of inputs, with genuinely nested (not just chained) conditions. |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: a plan file (`*-plan.md`) whose Mermaid flowchart matches the finished code exactly, `prompts.md`, and a short reflection naming where `&&` vs `\|\|` was used and why. |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide. The cells below were
**left unfilled at spec time on purpose** — the real rubric text is authored
against the finished lab, and it lives in `modules/m4/assess-lab.md`. They stay
empty here rather than being back-filled, so this file cannot drift into being a
second, competing rubric.

| Criterion | Points | Filled in `assess-lab.md` — kept empty here by design |
|---|---|---|
| **Correctness** | 8 | [ ] |
| **Completeness** | 6 | [ ] |
| **Format** | 3 | [ ] — must include: compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings; flowchart and code tell the same story. |
| **Submission** | 3 | [ ] — correct file/folder/repo, committed and pushed (no branches — ADR-004), `prompts.md` if AI was used. |
| **Total** | **20** | |

"No hidden criteria" is in force: what is on the lab page **is** the whole
rubric. Nothing in this build record adds to it.

---

## Standing invariants (apply to every M4 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors. Run it. Never claim a clean compile that wasn't executed.
- **Single-file form, pre-M6 shape.** Everything lives in `main` — no
  functions, no prototypes. Functions are not taught until M6. Do not use
  them in M4 code.
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories. M4 is where LOGIC errors become especially
  visible (a program that compiles, runs, and calmly takes the wrong branch).
- **Mermaid flowcharts, required (not optional) this module.** M4 is the
  module where flowchart-first is graded, not just modeled. At least one
  direction (flowchart → code) is required at C tier. MLO 4.3 calls for
  the reverse (code → flowchart) somewhere in the module's beats. Verify
  every diagram actually renders before hand-off.
- **Make-gradient position: top edge of the M2–M4 band, type-in 100%.** The
  Assess artifact's *starting scaffold* is a from-spec build — nothing is
  pre-typed for the student. This is independent of the Apply beat's
  type-in-100% tutorial, but both beats sit at the same gradient position.
  Do not hand M4 an M5-style "80%, finish it" scaffold anywhere in this
  module.
- **No trick questions.** Failure cases and traps above (the dangling
  `else`, `=` vs `==`, `switch` fall-through) must be named and taught, not
  sprung on the student as a gotcha. An "expect strange input" testing
  culture is fine and encouraged — an *untaught* trap in the rubric is not.
- **Dungeon canon stays instructor-facing.** If the Assess lab uses the
  Dungeon Gatekeeper theme (a strong candidate — see `_assets.md`), keep any
  build-org meta, canon notes, or answer-key reasoning out of the
  student-facing lab page. The theme must be freely re-skinnable — a
  bouncer, a gate agent, a loan officer — without breaking the exercise.
