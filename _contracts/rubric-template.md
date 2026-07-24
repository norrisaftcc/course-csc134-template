# CSC-134 Rubric Template (frozen interface contract)

**This is the template every module lab rubric inherits.** It fixes two things
that never change across the course: the **four columns** every lab is scored
on, and the **four tiers** a student can attempt. Individual labs fill in the
tier rows with module-specific requirements; they do **not** invent new columns,
rename columns, or add hidden criteria.

Column one is **Correctness** (locked by ADR-002 — never "Precision"). The four
columns descend from the Robot Sandwich (M1), so one rubric shape runs the whole
program: Robot Sandwich → every C++ lab, prose to code, unchanged in shape.

> **No hidden criteria.** What is on the rubric page is the whole rubric. This is
> a stated promise to students and a course-wide "no trick questions" guarantee.

---

## Two axes, kept separate

A lab rubric has two independent axes. Do not collapse them.

- **Tiers (C / B / A / Badge) — *what you attempt*.** A ladder of ambition. Each
  tier includes everything in the tier below it. A student picks how far to climb.
- **Columns (Correctness / Completeness / Format / Submission) — *how the attempt
  is scored*.** Every tier is graded on all four columns.

You choose a tier; you are scored on the columns.

---

## The tier ladder (reusable semantics)

Fill the right column per lab. The left-column *meaning* is fixed course-wide.

| Tier | Fixed meaning (course-wide) | What a lab puts here |
|---|---|---|
| **C — core** | The core competency of the module, demonstrated end to end. This is a *complete, passing* submission — C is not "partial credit," it is "the objective, met." | The minimum program that proves the module's main MLO. |
| **B — depth** | Added depth: a second concept from the module, or a harder case of the first (e.g., a compound condition, one round of input validation). | The one extra concept the module wants reinforced. |
| **A — synthesis** | Synthesis or extension: concepts combined, or the idea pushed past the taught case (e.g., a real branching tree, nested loops). | The integrative challenge for students who want it. |
| **Badge — above & beyond** | Documentation and reflection beyond the code: evidence of *how* the work was done and *why*. Never a substitute for C/B/A — it rides on top. | A complete `prompts.md`, a hand-drawn trace table, a short written reflection. |

**Make-gradient note.** The tier ladder is stable, but the *starting scaffold*
shifts by module: M2–M4 hand students 100% to type in, M5–M7 hand them ~80% to
finish, M8 hands them a spec. The tiers describe the finished artifact; the Apply
beat decides how much was pre-built.

---

## The four-column scoring table (fixed columns, fixed weights)

Copy this table into every lab. Fill the "What we're looking for" cell with
module-specific language; keep the columns, order, and point weights.

| Criterion | Points | What we're looking for (fill per lab) |
|---|---|---|
| **Correctness** | 8 | The program produces the right result for the given inputs; the logic does what it claims. |
| **Completeness** | 6 | Everything the *attempted tier* requires is present; stated edge cases are handled. |
| **Format** | 3 | Readable code, helpful comments, clear output. **For any C++ tier: compiles clean under `g++ -std=c++17 -Wall -Wextra` — zero warnings.** |
| **Submission** | 3 | Correct file names, correct folder, correct repo, committed and pushed; `prompts.md` present if AI was used. |
| **Total** | **20** | |

Point weights (8 / 6 / 3 / 3) are the course default. A lab may re-weight only
with the spine-owner's sign-off; the four columns and their order never change.

### Column meanings (course-wide, do not drift)

- **Correctness** — *Did it produce the right result?* The behavioral bar. Wrong
  branch, off-by-one, wrong total — all land here.
- **Completeness** — *Is everything the tier asked for present?* Coverage of the
  requirements, including the edge cases the tier names.
- **Format** — *Is it readable, and does it build clean?* Style, comments, output
  clarity, and — for C++ — the zero-warning clean-compile bar lives here.
- **Submission** — *Is it turned in correctly?* File names, folder, repo, the
  commit/push (student flow: commit and push, no branches — ADR-004), `prompts.md`.

---

## How a module author instantiates this template

1. Copy the **tier ladder** table; fill the right column with this lab's C/B/A/Badge
   requirements (each tier includes the ones below it).
2. Copy the **four-column scoring table**; fill each "what we're looking for" cell
   in this module's language. Keep columns, order, and weights.
3. State **"No hidden criteria — what is on this page is the whole rubric."**
4. Verify the **Format** cell names the clean-compile bar for every C++ tier.
5. Prefer the `rubric-converter` skill to generate the first draft — it is built
   on exactly these four columns and these four tiers.

*Worked instances of this template: `CSC-134-M4-dungeon-gatekeeper-lab.md` (M4)
and the Loops Two-Skin Exemplar (M5). Read either to see the template filled in.*
