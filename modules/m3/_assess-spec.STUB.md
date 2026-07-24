---
> **NOT YET AUTHORED — STUB**
> This is a skeleton of what the M3 Assess-beat artifact *will be*, not the lab
> itself. No student-facing prose below is final; no acceptance criteria here
> are complete. Deep-build (via the `lab-creator` skill) replaces this file's
> content with the real lab — do not hand this stub to students.
---

# M3 Assess Spec — STUB

**Spine anchor:** "a small I/O + arithmetic program from spec (the Pizza
Calculator project slots here)" — `_storming/CSC-134-course-spine.md`, M3
Assess line. **Measured by** (learning-objectives doc): "the I/O + arithmetic
lab (e.g., Pizza Calculator)."

**MLOs this artifact must exercise:** MLO 3.1 (variable/type declaration),
MLO 3.2 (I/O + arithmetic-expression program), MLO 3.3 (reading a compiler/
runtime error against a program the student wrote). See `_mlos.md`.

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete values and messages at deep-build time.

```
program(order_inputs: {quantities/selections via cin}) -> receipt_output: string

  PRECONDITIONS (what the C-tier program may assume):
    - inputs arrive in the prompted order, correct type, via cin
    - at least one item is ordered (no zero/empty-order handling required at C)

  POSTCONDITIONS (what "correct" means):
    - subtotal = sum(unit_price[i] * quantity[i])
    - tax = subtotal * tax_rate                       [rounding rule: TBD at deep-build —
      see "Known trap" below before picking one]
    - total = subtotal + tax [+ optional tip, if B/A scope includes it]
    - every output value is dollar-formatted (fixed, setprecision(2))

  FAILURE CASES (must be named, not just handled silently):
    - malformed numeric input (e.g., letters where cin expects a number)
        -> classify per the four-word taxonomy: this is a RUNTIME failure
           (cin enters a fail state) if unguarded; a B/A tier that adds
           input validation converts it into a handled case, not a crash
    - negative quantity or price
        -> C tier: undefined/out of scope, state so explicitly
        -> B/A tier: TBD whether this becomes a validated rejection
    - integer-division truncation (e.g., splitting a total across N people
      with int arithmetic) -> this is a LOGIC error class if it silently
      truncates; C-tier spec must state whether double or int is required
      per field, so the trap is taught, not stumbled into
```

**Known trap to resolve at deep-build, not left implicit:** floating-point
rounding is a genuine representation-vs-display gap. For example, a computed
tax or tip value can be `1.71500000000000008` internally but display as
`1.72`. This gap already shows up in the M3 exemplar WIP at
`_storming/exemplars/m3-taco-receipt/` (see `_assets.md`). The stub flags it
here so deep-build decides on purpose whether M3's C tier avoids the trap
(round numbers only) or teaches it directly at B/A tier, instead of
inheriting it by accident.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template. The right column is skeleton-only
— **not yet filled with this lab's real requirements.**

| Tier | Fixed meaning (course-wide) | M3 slot (TBD at deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] Minimal input → arithmetic → formatted-output program proving MLO 3.1/3.2. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: a second calculation path, or basic input validation (guarding one bad-input case). |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: multi-item order, tax + tip combined, or the rounding trap made explicit and explained. |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: `prompts.md` + a short reflection naming which error(s) the student hit and how the taxonomy word for each was determined. |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide. The "what we're
looking for" cells are **unfilled placeholders**, not this lab's real rubric
text.

| Criterion | Points | What we're looking for (TBD — deep-build fills per this lab) |
|---|---|---|
| **Correctness** | 8 | [ ] |
| **Completeness** | 6 | [ ] |
| **Format** | 3 | [ ] — must include: compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings. |
| **Submission** | 3 | [ ] — correct file/folder/repo, committed and pushed (no branches — ADR-004), `prompts.md` if AI was used. |
| **Total** | **20** | |

"No hidden criteria" applies once this stub is instantiated: what's on the lab
page will be the whole rubric.

---

## Standing invariants (apply to every M3 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors. Run it; never claim a clean compile that wasn't executed.
- **Single-file form, pre-M6 shape.** Everything lives in `main` — no
  functions, no prototypes. Functions are not taught until M6; do not use them
  in M3 code.
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories.
- **Mermaid flowcharts.** Use them where a flowchart is called for — render
  natively, and verify before hand-off.
- **Make-gradient position: M2–M4 band, type-in 100%.** The Assess artifact's
  *starting scaffold* is a from-spec build — nothing pre-typed for the
  student. This is independent of the Apply beat's type-in-100% tutorial, but
  both beats sit at the same gradient position. Do not hand M3 an M5-style
  "80%, finish it" scaffold anywhere in this module.
- **No trick questions.** Failure cases above must be named and taught, not
  sprung on the student as a gotcha.
