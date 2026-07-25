# CLAUDE.md — CSC-134 Builder Conventions

Guidance for Claude Code building CSC-134 (C++ Programming) course materials.
This is the **conventions pack**, distilled from the course spine. It tells you
the bars every deliverable must clear and where the details live. The spine
(`_storming/CSC-134-course-spine.md`) is ground truth; where this file and the
spine disagree, the spine wins and the disagreement gets an ADR.

> Building a specific beat? Load the matching **skill** first (see *Skill guild*
> below). The skills carry the step-by-step; this file carries the invariants.

---

## Mechanical quality bars (no exceptions)

Every deliverable clears all of these. The compile-warden gates on them; a PR
that fails any is not done.

1. **Clean compile.** Every C++ block in every artifact builds under
   `g++ -std=c++17 -Wall -Wextra` with **zero warnings and zero errors**. Not
   "compiles with a note" — zero. Actually run it; never claim a clean compile
   you did not run.
   **On GCC, and CI is the authority** (ADR-014). On macOS `g++` is Apple clang,
   which does *not* enable `-Wimplicit-fallthrough` under `-Wextra` — so a local
   "clean" can be a warning for every student. That is not hypothetical: it
   shipped a warning inside a module certified Ready (F-009). Run the gate the
   students' compiler runs: `bash .github/scripts/compile-gate.sh`, or read the
   CI result. **Never assert compiler _silence_ from a macOS run** — quoting
   output is safe, promising there was none is not.
2. **10th-grade readability** on all student-facing prose (code excluded).
   Complexity lives in the *problem*, never in the sentence describing it. Linx
   owns the readability pass.
3. **Single-file convention.** No multi-file projects. **Its form is
   module-dependent:** before M6, everything lives in `main` — no functions, no
   prototypes (the "pre-M6 incomplete form"). From M6 on, the full shape:
   prototypes at top, `main` in the middle, definitions at the bottom. Do not
   use functions in M2–M5 material; they are not taught yet.
4. **Four-word error taxonomy, used consistently.** The only names for errors:
   **Syntax** ("broke the grammar"), **Static semantic** ("grammar fine, meaning
   impossible"), **Runtime** ("ran, then fell over"), **Logic** ("did what you
   said, not what you meant"). Use these words; do not coin synonyms.
5. **Mermaid renders.** All flowcharts are Mermaid-in-Markdown (renders natively
   on GitHub, reuses the M1 skill). Verify the diagram actually renders — a
   broken ` ```mermaid ` block is a failed deliverable.
6. **Rubrics descend from the four columns.** Every lab rubric inherits
   `_contracts/rubric-template.md`: **Correctness / Completeness / Format /
   Submission** × **C / B / A / Badge**. Column one is **Correctness** (ADR-002,
   never "Precision"). No new columns, no hidden criteria.
7. **No trick questions.** Stated policy. Assessments verify the objectives, not
   stamina or lawyer-reading. Exit tickets are low-stakes and completion-gated.
8. **Stay on the Make gradient.** Apply-beat scaffolding shifts by module:
   **M2–M4 type-in 100%**, **M5–M7 finish-the-80%**, **M8 spec-only**. Build the
   beat at its module's position; do not hand M4 a spec or M7 a full type-in.
9. **Staged builds.** Demos and instructor examples build in stages; each stage
   compiles and runs standalone, so complexity accumulates visibly. Mark the
   stages in comments.

---

## The interface contracts (`_contracts/`)

Three frozen files everything downstream builds against. **Changing one is a
breaking change** — spine-owner sign-off + an ADR + a version bump, never a
silent edit. See `_contracts/README.md`.

- `m4_gatekeeper.cpp` — canonical M4 decision program (Dungeon Gatekeeper).
- `m5_menu.cpp` — canonical M5 menu program; the M4 gatekeeper grown a loop
  (the M4→M5 seam). M6 refactors it into functions; M7 extends it.
- `rubric-template.md` — the four-column × four-tier rubric every lab inherits.

---

## Voice

- **Dungeon is canon.** Instructor-facing material uses the RPG/dungeon theme —
  the gatekeeper, the dungeon door, Room/Hero/Monster, stats that level up. It
  pays off at the M8 capstone. Liza owns the skin.
- **Skin ≠ structure.** The theme must strip cleanly. A student may reskin
  (nightclub bouncer, airport gate, loan approval) and the *decisions* stay put.
  If a reskin breaks the exercise, the theme was welded to the structure — a bug.
- **GameFAQs register, not a textbook.** Warm, direct, second person, a little
  playful. Talk *to* the student. The style guide
  (`_past_work/materials/style-guide-cpp.md`) is the reference: friendly intro,
  runnable example, name the common pitfall, acknowledge C++ is hard, celebrate
  when it clicks.
- **Honest freshman C++ in deliverables.** Student-facing code is imperative and
  plain: `cin`, `cout`, loops, and mutation, taught proudly. **`using namespace
  std;` is taught on purpose** (ADR-009) — beginners should not trip over `std::`
  on every line; the namespace-pollution objection does not bite in single-file,
  single-TU freshman work. No clever one-liners, no functional flourishes — the
  code models what a freshman writes, not what an expert would compress.
- **Debugging is celebrated, not hidden.** The first error is a planned event.
  Break working programs on purpose and read the compiler's complaint together.

---

## File layout

- `_storming/` — the spine, learning objectives, PRISM mapping, personas, the
  agent fleet and skill-guild sources, and existing assets to port. **Ground
  truth.** (Some subtrees are other sessions' WIP — do not touch what you did not
  open.)
- `_contracts/` — the frozen interface contracts (above).
- `_lore/` — the project's memory: ADRs (`_lore/decisions/`), glossary, findings
  ledger. The wall of record.
- `_past_work/` — legacy course materials for reference/porting. **Has its own
  `_past_work/CLAUDE.md`; that file is legacy and does not govern this build** —
  in particular its issue-first / feature-branch student workflow is superseded
  by ADR-004 (below). This root file governs.
- `_tracking/` — the machine-readable course manifest.
- Module deliverables land in per-module folders as the skeleton pass defines
  them.

**Port before authoring.** The spine's asset table says what adapts vs. what is
new. Adapt existing assets (cheaper, safer); do not duplicate them. Treat
`csc134-refresh-plan/` as a stale fork — mine it for material, trust the spine.

---

## Git: two-tier workflow (ADR-004)

Two workflows, keyed to who is acting. Do not mix them.

- **Student flow** — fresh-spawn cohort agents, and the materials early modules
  teach: **commit and push directly, no branches, no PRs.** This mirrors the real
  early-module student experience. **Do not bake branching into student-facing
  conventions** — branching is a capstone-tier topic (M8), out of alpha depth.
  Worktree isolation for parallel students is plumbing, not a branching lesson.
- **Build flow** — the build fleet (you, when producing deliverables):
  **branch + PR-per-deliverable**, conventional commits, human review at every
  PR. Branch naming: `phase0/<topic>`, `module/m4-deep`, `cohort/m4-round<N>`.

## The `_lore/` merge gate

**No PR merges without its lore entry** — a decision (ADR), a finding, or a
glossary delta. Kevin enforces it; marks on the wall, daily. If your change
embodies a decision, write the ADR. If a genuine decision surfaces that you
cannot make, record it as an open question for a human ruling — **do not grab an
ADR number** when numbering is contested.

---

## Skill guild (load these for the details)

Building a beat? Invoke the skill; it carries the procedure this file
deliberately does not inline.

| Beat / task | Skill |
|---|---|
| Learn (reading) | `reading-generator` |
| Practice (exit ticket) | `exit-ticket-generator` |
| Apply (type-in tutorial) | `apply-tutorial-generator` (FULL for M2–M4, EIGHTY for M5–M7) |
| Assess (lab) | `lab-creator` |
| Rubric | `rubric-converter` (builds on the four columns) |
| Voice / philosophy on any content | `course-content-writer` |

When in doubt: the spine decides *what*, the contracts fix the *shapes*, the
skills carry the *how*, and this file holds the *invariants*.
