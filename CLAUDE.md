# CLAUDE.md — CSC-134 Builder Conventions

Guidance for Claude Code building CSC-134 (C++ Programming) course materials.
This is the **conventions pack**, distilled from the course spine. It tells you
the bars every deliverable must clear and where the details live. The spine
(`_storming/CSC-134-course-spine.md`) is ground truth; where this file and the
spine disagree, the spine wins and the disagreement gets an ADR.

> Building a specific beat? Load the matching **skill** first (see *Skill guild*
> below). The skills carry the step-by-step; this file carries the invariants.

House style, from `.github/instructions/`: check `_lore/invariants/` first for
world state, then take the extreme-programming route — **the simplest thing that
could work, and iterate.**

---

## Mechanical quality bars (no exceptions)

Every deliverable clears all of these. Four scripts gate bars #1, #2 and #10
mechanically (see *The gates* below); the compile-warden owns the rest. A PR that
fails any is not done.

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
   **Fenced blocks count as artifacts** (ADR-015). A ` ```cpp ` block in Markdown
   is not source — it is a view of a gated `.cpp`, and it must say so:
   `source=<path>` for a whole file, `excerpt=<path>` for part of one. Matching is
   exact text, comments included. There is no skip. Write the `.cpp` first, then
   quote it; `bash .github/scripts/markdown-gate.sh` checks the rest. Broken-on-
   purpose code is an `excerpt=` of a file marked `// GATE: EXPECT-WARNING` or
   `EXPECT-ERROR` — assertions, not mutes: a marked file that stops misbehaving
   fails. See `.github/scripts/README.md` for how the gates compose.
2. **10th-grade readability** on all student-facing prose (code excluded).
   Complexity lives in the *problem*, never in the sentence describing it. Linx
   owns the readability pass — and now has an instrument:
   `bash .github/scripts/editorial-gate.sh` scores reading grade and sentence
   length, STE-100-derived (ADR-016). It is **advisory by default** — a syllable
   heuristic must not veto a warm, correct sentence at grade 10.2 — and enforcing
   in CI on the grade only, at the loose `target + 2.0` band (12.0). Student prose
   scores 5–8, so a red editorial gate means a breakdown, not a nuance.
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
   stages in comments. Each stage gets its **own gated `.cpp`**
   (`apply-gatekeeper-stage1.cpp`, `-stage2.cpp`, …) — a stage is a shorter whole
   program, not a slice of the final one, and that turns this bar into something
   checked rather than asserted.
10. **Audience boundary, not an audience label** (ADR-017). Every beat is written
    **to the student**. Instructor content — pacing, stall notes, reference
    solutions — sits *below* a heading containing the exact phrase
    `not part of the student handout`, at the end of the file. A label
    (`### Instructor-only:`) tells a careful reader to skip; it does not stop a
    student who scrolls, and an M5 Apply beat shipped the answer eighty lines
    under one through a build, two cohort rounds, and a `Ready` badge (F-018).
    Answer keys stay in their **own file** (`practice-exit-ticket-key.md`), and a
    student-facing beat never links its key. The LPAA gate checks both.

---

## The gates (run them before you claim anything)

Four scripts, same invocation shape, same result on a laptop and in CI. Run them
from the repo root; no packages needed beyond a compiler and Python 3.

```bash
bash .github/scripts/compile-gate.sh    # bar #1a — does the .cpp build clean on GCC?
bash .github/scripts/markdown-gate.sh   # bar #1b — is this fenced listing the real file?
bash .github/scripts/lpaa-gate.sh       # bar #10 — are the repo's claims about itself true?
bash .github/scripts/editorial-gate.sh  # bar #2  — does the prose read at grade level?
```

| Gate | Question it answers | Compiles? | CI |
|---|---|---|---|
| `compile-gate.sh` | Does this `.cpp` build clean on the students' compiler? | yes | enforcing |
| `markdown-gate.sh` | Is this fenced listing a faithful view of one of those `.cpp` files? | no | enforcing |
| `lpaa-gate.sh` | Is what the repo **says about itself** true? | no | enforcing (since 2026-08-01) |
| `editorial-gate.sh` | Does this page read at grade level, in short sentences? | no | grade only, at 12.0 |

Two workflows run them: `.github/workflows/compile-gate.yml` (three separate jobs
— compile, markdown, LPAA — so the signals stay independently readable) and
`.github/workflows/editorial-gate.yml`. Every dial is an env var locally and a
`workflow_dispatch` input in the Actions tab; the table lives in
`.github/scripts/README.md`.

**The LPAA gate is the one you will trip.** It exists because *finishing a piece
of work is what makes the surrounding status text false* — six false claims landed
in one week, every one checkable, none visible to the other gates (F-019). Its
checks: `status-files` (MODULES.md's status implies a file set — asserted **both
ways**, so authoring past a `First pass` status fails too), `frontmatter`
(`module:` and `lpaa_beat:` must agree with the path), `stale-stub` (no "NOT YET
AUTHORED" inside a `Built`/`Ready` module), `key-leak`, `boundary`,
`lore-numbers` (one lore number, one file — ADR-018), and `open-questions`
(reports only, never fails).

**So when you author past a status, fix the status in the same PR** — all of it:
`modules/MODULES.md`, the module's `_overview.md`, `_tracking/breadth-pass-ledger.md`,
and any stub banner that the work just made false.

**Every gate has self-tests, because a gate that cannot fail is not a gate:**

```bash
bash .github/scripts/selftest/markdown/run.sh
bash .github/scripts/selftest/lpaa/run.sh
bash .github/scripts/selftest/editorial/run.sh
SEARCH_PATHS=.github/scripts/selftest/must-warn.cpp bash .github/scripts/compile-gate.sh
```

**Do not trust a local run on macOS** for bar #1 — `g++` there is Apple clang. The
other three gates compile nothing, so their results are identical everywhere.

---

## The module tree (`modules/`)

`modules/m0…m8/` is the **canonical, spine-numbered home** for all module
deliverables (ADR-008). Legacy `assignments/` and `_past_work/` are frozen source —
mined for material, never scaffold targets. `modules/MODULES.md` is the canonical
status table; **read it, not `_tracking/course-manifest-csc134.yaml`**, which is
marked stale in its own header.

**Status vocabulary** (the LPAA gate reads it from `MODULES.md`, so it is not
hard-coded anywhere):

| Status | Means |
|---|---|
| **Skeleton** | `_overview.md`, `_mlos.md`, `_assets.md`, `_assess-spec.STUB.md`. No student-facing content. |
| **First pass** | One real, gate-green student-facing artifact — the **Learn beat**, plus gated `code/` where there is C++ to gate. |
| **Built** | All four LPAA beats authored and through the gates. |
| **Ready** | Built, *plus* taken end to end by a synthetic student cohort, with every finding filed and closed. |

A module is not **Ready** until a cohort has actually failed at it and those
failures have been fixed. As of the breadth pass (ADR-016) all nine modules are
`First pass` or better; **M4 and M5 are `Ready`**.

**Per-module file shape** — a Built module:

```
modules/mN/
  learn.md                      Learn beat — the reading
  practice-exit-ticket.md       Practice beat — student-facing, completion-gated
  practice-exit-ticket-key.md   Practice beat — INSTRUCTOR-FACING answer key
  apply-tutorial.md             Apply beat — the in-class session
  assess-lab.md                 Assess beat — the graded lab, with rubric
  code/                         every C++ source the beats quote — sources only
```

- **Frontmatter is checked.** `module: M5` and `lpaa_beat: Learn` must match the
  file's path.
- **`_assess-spec.STUB.md` stops being a stub once its lab is authored** — retarget
  its banner to "build record". Leaving "NOT YET AUTHORED" on a shipped module
  tells every reader the opposite of the truth, and fails the gate.
- **`.gitignore` ignores everything in `modules/*/code/`** and allows `.cpp`, `.h`,
  `.md` back in — compiled binaries are extensionless on macOS/Linux. Add a new
  source type to that allow-list or git will silently ignore your file.

---

## The interface contracts (`_contracts/`)

Three frozen files everything downstream builds against. **Changing one is a
breaking change** — spine-owner sign-off + an ADR + a version bump, never a
silent edit. See `_contracts/README.md`.

- `m4_gatekeeper.cpp` — canonical M4 decision program (Dungeon Gatekeeper).
- `m5_menu.cpp` — canonical M5 menu program; the M4 gatekeeper grown a loop
  (the M4→M5 seam). M6 refactors it into functions; M7 extends it.
- `rubric-template.md` — the four-column × four-tier rubric every lab inherits.

**Descoped, deliberately** (ADR-011): STL containers and File I/O are out of the
alpha. M7 teaches arrays → structs → by-reference; classes are *named*, not
taught. Do not reach for `std::vector` or `fstream` in student-facing material.

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
- `modules/m0…m8/` — **the canonical build target** (ADR-008). Status in
  `modules/MODULES.md`; shape and rules above.
- `_lore/` — the project's memory and the wall of record: ADRs
  (`_lore/decisions/`), findings (`_lore/findings/`), `glossary.md`, and
  `_lore/invariants/` — canonical external text (the CCL catalog entry)
  preserved **verbatim** for audit and drift checks. Never paraphrase an
  invariant; it is a snapshot, not prose.
- `instructor-guide/` — behind-the-screen orientation: which compiler runs where,
  cohort-harvest material, per-module teaching notes. Derived and freely
  rewritten. `_lore/` answers *why is it like this*; this answers *how do I work
  here*. When they disagree, `_lore/` is right and the guide is stale.
- `_past_work/` — legacy course materials for reference/porting. **Has its own
  `_past_work/CLAUDE.md`; that file is legacy and does not govern this build** —
  in particular its issue-first / feature-branch student workflow is superseded
  by ADR-004 (below). This root file governs.
- `assignments/`, `outline/` — legacy chapter-ordered material, **frozen** by
  ADR-008. Provenance only; never a scaffold target. Its numbering drifts from
  the spine (legacy `m1`/`m2` hold content that maps to spine **M3**).
- `_tracking/` — build ledgers: `breadth-pass-ledger.md`, `module-status-review.md`,
  `numbering-reconciliation-map.md`, and cohort round records under
  `_tracking/cohort/`. `course-manifest-csc134.yaml` is **stale and says so** —
  `modules/MODULES.md` supersedes it for "what is done".
- `_outputs/` — **generated artifacts, not ground truth** (ADR-012). Composed Canvas
  HTML lands here, never in `modules/`. Never hand-edit a file in `_outputs/`: edit the
  Markdown source and re-emit, or the change is lost on the next build — after surviving
  just long enough to be believed. Committed so formatting churn is reviewable in a diff.
- `.claude/agents/` — the build fleet's agent definitions (compile-warden,
  cohort-lead, module-builder, spine-owner, Kevin, Linx, Liza, Clive,
  cadence-master, program-advisor). `.claude/skills/` — the skill guild below.
- `.github/scripts/` — the gates and their self-test fixtures.
  `.github/instructions/` and `.github/agents/` are GitHub Copilot's equivalents;
  they point back here and at `_lore/invariants/`.
- `_claude_sage/`, `csc134-refresh-plan/` — reference kits from other builds. Mine
  them; neither governs this repo.

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

Shape: ADRs are `ADR-NNN-slug.md`, Context → Decision → Consequences, ~1 page max.
Findings are `F-NNN-slug.md`, transcript-cited. Cross-link with `[[wiki-style]]`
refs. **Check the directory before taking a number** — `ADR-013` is reserved and
unwritten.

**Three numbers name two files each** (ADR-018): `ADR-016` (breadth-first pass,
editorial gate), `F-009`, and `F-014`. They stand as history and are **cited by
slug** — `[[ADR-016-editorial-gate-ste100-derived]]`, never a bare `ADR-016`.
Numbers that name one file may still be cited bare. **They are the last three:**
the LPAA gate's `lore-numbers` check fails any new collision, and that
grandfather list must never grow — a fourth entry means the check was silenced
rather than the number fixed.

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
| Canvas page / assignment HTML | `csc134-canvas-compositor` (ADR-012; output to `_outputs/`, never `modules/`) |
| Turning a vague ask into a buildable spec | `the-algorithm-lite` — **provisional** stand-in for house style (ADR-019, expires 2026-11-04) |
| Teaching that same floor test to students | `running-the-bases` (the teaching form; the operating form above wins on conflict) |

Agents in `.claude/agents/` carry the roles. Named agents keep their capitals —
**Linx** (readability, bar #2), **Liza** (theme and skin), **Kevin** (repo
hygiene, the lore merge gate), **Clive** (prompt integrity) — and the rest are
role slugs: **compile-warden** (the mechanical gate — evidence, never opinions),
**spine-owner** (contracts and acceptance criteria), **module-builder**
(graduate-and-teach: take module N as a student, build N+1), **cohort-lead**
(fresh-spawn synthetic students), **cadence-master** (the promotion cycle),
**program-advisor** (outward-facing rationale).

When in doubt: the spine decides *what*, the contracts fix the *shapes*, the
skills carry the *how*, and this file holds the *invariants*.

---

## Decisions worth knowing before you start

The full set is `_lore/decisions/`; these bite most often.

| ADR | Ruling |
|---|---|
| 002 | Column one of every rubric is **Correctness**, never "Precision" |
| 004 | Two-tier git workflow — student flow vs. build flow |
| 008 | `modules/` is canonical; `assignments/` and `_past_work/` are frozen legacy |
| 009 | `using namespace std;` is taught on purpose |
| 011 | STL and File I/O are descoped from the alpha |
| 012 | The Canvas compositor derives, never authors; output to `_outputs/` |
| 014 | The compile gate runs GCC in CI, and **CI is the authority** |
| 015 | Fenced blocks mirror a gated source file — `source=` / `excerpt=`, no skip |
| 016 *(`-breadth-first-pass`)* | Breadth first: a Learn beat in every module before more depth |
| 016 *(`-editorial-gate-ste100-derived`)* | An STE-100-derived editorial gate gives bar #2 an instrument (advisory) |
| 017 | Apply beats are written to the student; instructor content sits behind the boundary |
| 018 | Colliding lore numbers stand; citations disambiguate by slug |
| 020 | **`modules/mN/_mlos.md` governs MLO numbering**; a citation crossing documents carries the objective slug |

Findings that changed how the build works: **F-009** (a macOS "clean" is not a
clean), **F-013** (Markdown blocks were unversioned copies), **F-018** (the Apply
audience boundary), **F-019** (six false status claims in one week), **F-020**
(the haiku ladder calibration — 30/30 clean, zero variance, and two material gaps
no gate can see).

## Copilot CI triage guardrail

When investigating a failed GitHub Actions run from a `Fix with Copilot` link,
keep tool output small: call `actions_list` with narrow filters (`per_page`,
`branch`, `event`, `status`) and then jump to `actions_get` for the exact run
ID plus `get_job_logs` for the failed job. Avoid unfiltered run listings.
