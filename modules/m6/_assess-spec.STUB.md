---
> **NOT YET AUTHORED — STUB**
> This is a skeleton of what the M6 Assess-beat artifact *will be*, not the lab
> itself. No student-facing prose below is final; no acceptance criteria here
> are complete. Deep-build (via the `lab-creator` skill) replaces this file's
> content with the real lab — do not hand this stub to students.
---

# M6 Assess Spec — STUB

**Spine anchor:** "the refactor lab — take your M5 program and decompose it
into functions" — `_storming/CSC-134-course-spine.md`, M6 Assess line.
**Signature move (spine, Content section):** "refactor a prior M4 or M5
program into functions — same behavior, better structure." **Measured by**
(learning-objectives doc): "the refactor-into-functions lab."

**MLOs this artifact must exercise:** MLO 6.1 (define/call functions with
prototypes, parameters, return values, in the completed single-file
convention), MLO 6.2 (pass-by-value vs. pass-by-reference, applied
appropriately), MLO 6.3 (refactor without changing behavior). See `_mlos.md`.

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete function names, signatures, and messages at deep-build time.

```
refactor(source_program: a working M4-or-M5-shaped single-`main` program)
  -> refactored_program: same single-file, now with prototypes/main/definitions

  PRECONDITIONS (what the C-tier submission may assume):
    - the starting program already compiles clean and behaves correctly
      (it is the student's own M4 or M5 submission, or the frozen
      `_contracts/m5_menu.cpp` shape used as a class-provided starting point —
      candidate choice, TBD at deep-build)
    - the starting program is pre-M6 form: everything in `main`, no functions

  POSTCONDITIONS (what "correct" means):
    - the refactored program produces IDENTICAL observable behavior to the
      original for the same inputs (same prompts, same output, same control
      flow) — the refactor changes structure, not behavior
    - at least N functions extracted [N: TBD — candidate 3-4], each with a
      single, nameable responsibility (e.g., displayMenu(), getValidChoice(),
      runGatekeeperCheck())
    - every extracted function has a prototype above `main` and a definition
      below `main` (the completed single-file convention)
    - at least one function takes a parameter and returns a value (not just
      void functions)
    - at least one function demonstrates pass-by-reference used correctly
      (a parameter that the caller expects to see changed, actually changes)
    - the program still compiles clean: g++ -std=c++17 -Wall -Wextra,
      zero warnings

  FAILURE CASES (must be named, not just handled silently):
    - calling a function before its prototype is declared
        -> classify per the four-word taxonomy: SYNTAX or STATIC SEMANTIC,
           depending on the exact compiler complaint (undeclared identifier
           is static-semantic; a malformed prototype line is syntax) —
           deep-build to pick the exact example and pin the classification
    - refactor changes behavior (e.g., dropped a line while moving code into
      a function, so an edge case no longer prints the message it used to)
        -> this is a LOGIC error: the program still runs, still compiles,
           but no longer does what the original did
    - expecting a pass-by-value parameter to mutate the caller's variable
      (the single most common M6 pitfall: "I changed it in the function, why
      didn't it change outside?")
        -> this is a LOGIC error, and it is THE trap this module exists to
           teach — see "Known trap" below; it must be taught directly, not
           sprung as a gotcha
    - a variable declared inside one function referenced from another
      function (a scope violation)
        -> STATIC SEMANTIC: "grammar fine, meaning impossible" — the compiler
           rejects the out-of-scope name outright
```

**Known trap to resolve at deep-build, not left implicit:** the
pass-by-value-when-you-meant-pass-by-reference bug (function appears to work,
compiles clean, runs without crashing, but the caller's variable is silently
unchanged) is the canonical M6 pitfall — arguably *the* reason this module
exists. The spec must decide, on purpose, where in the tier ladder a student
first has to diagnose this bug themselves (candidate: it's the built-in "gotcha"
of the B tier, explicitly taught first in Learn/Apply so it is recognition, not
a surprise) rather than inheriting it as an accidental stumbling block.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template; right column is skeleton-only,
**not yet filled with this lab's real requirements.**

| Tier | Fixed meaning (course-wide) | M6 slot (TBD at deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] Take a working M4/M5-shaped program and decompose it into 3+ functions (prototypes top, definitions bottom); behavior unchanged; proves MLO 6.1/6.3. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: add a function with a return value used in a decision (e.g., a `bool isValidChoice(int)` gate), or correctly apply pass-by-reference where the C tier didn't require it. |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: refactor the full `_contracts/m5_menu.cpp`-shaped menu-loop program (multiple decision branches, the validation loop) into a clean function set, mixing value and reference parameters purposefully. |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: `prompts.md` + a short reflection naming one bug the student hit while refactoring (ideally the pass-by-value trap) and how they diagnosed it. |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide; "what we're looking
for" cells are **unfilled placeholders**, not this lab's real rubric text.

| Criterion | Points | What we're looking for (TBD — deep-build fills per this lab) |
|---|---|---|
| **Correctness** | 8 | [ ] |
| **Completeness** | 6 | [ ] |
| **Format** | 3 | [ ] — must include: compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings; prototypes top / `main` middle / definitions bottom. |
| **Submission** | 3 | [ ] — correct file/folder/repo, committed and pushed (no branches — ADR-004), `prompts.md` if AI was used. |
| **Total** | **20** | |

"No hidden criteria" applies once this stub is instantiated: what's on the lab
page will be the whole rubric.

---

## Standing invariants (apply to every M6 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors. Run it; never claim a clean compile that wasn't executed.
- **Single-file form, completed shape.** M6 is where the full convention lands:
  prototypes at top, `main` in the middle, definitions at the bottom. This is
  the first module where functions are allowed and expected — do not carry
  forward the pre-M6 "everything in `main`" restriction.
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories.
- **Mermaid flowcharts**, where a flowchart is called for (e.g., tracing a
  function call and return) — renders natively, verified before hand-off.
- **Make-gradient position: M5–M7 band, here's-80%-finish-it.** The Apply
  beat's starting scaffold is a mostly-built program with prototypes given and
  bodies to fill in; the Assess artifact's starting point is the student's own
  prior working program (or the frozen `m5_menu.cpp` reference shape) — do not
  hand M6 an M2–M4 type-in-100% scaffold or an M8 spec-only brief.
- **No trick questions.** Failure cases above, especially the pass-by-value
  trap, must be named and taught, not sprung on the student as a gotcha.
