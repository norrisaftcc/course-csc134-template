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

## Where things stand (read before claiming status)

**`modules/MODULES.md` is the canonical build-status index.** Not this file, not
the manifest, not a ledger. `_tracking/course-manifest-csc134.yaml` is **stale by
its own banner** — never read it for "what is done"; its rebuild is queued behind
the settled index.

Status vocabulary, in order: **Skeleton** (four planning files, no student
content) → **First pass** (Learn beat authored and gate-green, nothing else,
ADR-016) → **Built** (all four LPAA beats through the gates) → **Ready** (Built,
*plus* a synthetic cohort took it end to end and every finding is closed).

As of the breadth pass (ADR-016, F-015): **all nine modules M0–M8 carry a Learn
beat.** M4 and M5 are **Ready**; M0–M3 and M6–M8 are **First pass**. A human can
open any module and review something real. The live backlog is
`_tracking/breadth-pass-ledger.md` §6.

**Finishing a piece of work is what makes the surrounding status text false**
(F-019). Nobody writes a stale claim on purpose — they write a true one and then
make it false somewhere else. When you author past a status, fix the status in
the same PR: `modules/MODULES.md`, the module's `_overview.md`, the ledger, and
any stub banner that now lies.

---

## Mechanical quality bars (no exceptions)

Every deliverable clears all of these. The gates enforce 1, 2, 10, and 11
mechanically; the compile-warden checks the rest. A PR that fails any is not
done.

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
   owns the readability pass, and now has an instrument: `editorial-gate.sh`
   (ADR-016, STE-100-derived) scores grade and sentence length with code, tables,
   Mermaid, and frontmatter stripped first. It is **advisory by design** — a
   syllable heuristic must not veto a warm, correct sentence at grade 10.2 — and
   enforcing in CI on one thing only, the grade at the loose band (12.0). Current
   corpus: median grade 5.9, nothing above the band.
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
   (`-stage1.cpp`, `-stage2.cpp`, …) — that turns this bar into something checked
   rather than asserted.
10. **The audience boundary** (ADR-017). A beat file that carries instructor-only
    material declares it with a heading containing the exact phrase
    **`not part of the student handout`**, and puts *all* of it below that line.
    **Everything above the boundary is the student handout** and is written *to
    the student* — no "ask the room", no "out loud as a class". A label is not a
    boundary: `### Instructor-only:` tells a careful reader to skip, and does not
    stop a student who scrolls. Apply stays **one file**, not two (a hand-derived
    student copy is an unversioned duplicate, the exact drift F-013 documents).
    Answer keys remain **separate files** — the strongest form — and a
    student-facing beat never links its own key.
11. **The repo's claims about itself are true.** Every beat file carries
    frontmatter whose `module:` and `lpaa_beat:` match the path it sits at
    (`learn.md` → Learn, `practice-exit-ticket.md` → Practice,
    `apply-tutorial.md` → Apply, `assess-lab.md` → Assess). No "NOT YET AUTHORED"
    banner survives inside a `Built` or `Ready` module. A module's status implies
    a file set, **both ways** — a `First pass` module holding a lab is not a
    filing mistake, it is a status that went stale. `lpaa-gate.sh` enforces all
    of this (F-019).

---

## The three gates

All three run in CI on every PR and are enforcing. Run them locally exactly as CI
does — no packages, stock `python3` and `g++`:

```bash
bash .github/scripts/compile-gate.sh    # does the C++ build, on GCC?
bash .github/scripts/markdown-gate.sh   # is this fenced listing the real file?
STRICT=1 bash .github/scripts/lpaa-gate.sh   # is what the repo says about itself true?
bash .github/scripts/editorial-gate.sh  # advisory: grade + sentence length table
```

| Gate | Workflow | Asks | Compiles? |
|---|---|---|---|
| `compile-gate.sh` | Compile gate → *g++ -std=c++17 -Wall -Wextra* | Does this `.cpp` build clean on the students' compiler? | yes |
| `markdown-gate.sh` | Compile gate → *markdown blocks* | Is this fenced listing a faithful view of a gated `.cpp`? | no |
| `lpaa-gate.sh` | Compile gate → *LPAA content* | Are the repo's structural claims about itself true? | no |
| `editorial-gate.sh` | Editorial gate | Does this page read at grade level, in short sentences? | no |

Separate jobs on purpose: a compiler failure and a structural failure want
different readers, and folding them together trains everyone to ignore both.

**Every gate proves it can still fail, on every run.** A gate that cannot fail is
not a gate, so each ships with fixtures under `.github/scripts/selftest/` that
must go red. Do not "fix" a self-test by relaxing it — if a self-test breaks, the
gate stopped enforcing something.

Dials (env vars locally, `workflow_dispatch` inputs in the Actions tab) are
listed in `.github/scripts/README.md`. Defaults gate `_contracts modules`.

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

**Canonical (ADR-008, two-tree layout):**

- `modules/` — the nine-module tree, and the only home for spine-truth module
  content. `modules/MODULES.md` is the status index. Per module:
  ```
  modules/mN/
    _overview.md  _mlos.md  _assets.md  _assess-spec.STUB.md   skeleton four
    learn.md                     Learn beat — the reading
    practice-exit-ticket.md      Practice beat — student-facing
    practice-exit-ticket-key.md  Practice beat — INSTRUCTOR-FACING key
    apply-tutorial.md            Apply beat — the in-class session
    assess-lab.md                Assess beat — the graded lab + rubric
    code/                        every C++ source the beats quote, gated
  ```
  M0 and M1 are pre-C++ and correctly have **no `code/` directory at all**.
  `_assess-spec.STUB.md` stops being a stub once its lab is authored — it becomes
  the build record, and if it disagrees with `assess-lab.md`, the lab wins.
- `_contracts/` — the frozen interface contracts (above).
- `_lore/` — the project's memory: ADRs (`_lore/decisions/`), findings ledgers
  (`_lore/findings/`), verbatim canonical text (`_lore/invariants/`, e.g. the CCL
  catalog entry), and `glossary.md`. The wall of record.
- `_storming/` — the spine, learning objectives, PRISM mapping, personas, the
  alpha plan, and the agent-fleet and skill-guild sources. **Ground truth for
  *what*.** (Some subtrees are other sessions' WIP — do not touch what you did
  not open.)
- `_tracking/` — build ledgers and the course manifest. `breadth-pass-ledger.md`
  carries the live ranked backlog. **The manifest YAML is stale** (see above).
- `_outputs/` — **generated artifacts, not ground truth** (ADR-012). Composed
  Canvas HTML lands here, never in `modules/`. Never hand-edit a file in
  `_outputs/`: edit the Markdown source and re-emit, or the change is lost on the
  next build — after surviving just long enough to be believed. Committed so
  formatting churn is reviewable in a diff.
- `.github/scripts/` — the gates and their self-test fixtures.
- `.claude/agents/`, `.claude/skills/` — the installed fleet and skill guild
  (sources live in `_storming/agents-134/` and `_storming/skills-134/`).

**Legacy — mine it, never scaffold into it:**

- `_past_work/` — legacy course materials for reference/porting. **Has its own
  `_past_work/CLAUDE.md`; that file is legacy and does not govern this build** —
  in particular its issue-first / feature-branch student workflow is superseded
  by ADR-004 (below). This root file governs.
- `assignments/`, `instructor-guide/`, `outline/`, `csc134-refresh-plan/`,
  `_claude_sage/` — frozen source material. Note `assignments/m2/` holds drifted
  content belonging to spine **M3**; check the module's `_assets.md` before
  quarrying anything.

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

> **Numbering is currently contested.** `ADR-016` is used twice
> (`ADR-016-breadth-first-pass` and `ADR-016-editorial-gate-ste100-derived`), as
> are `F-009` and `F-014`. `ADR-013` is **reserved and unwritten** (#23, the
> Haiku persona). Next free numbers: **ADR-018** and **F-021**. Do not renumber
> the collisions unilaterally — they are cited by number across the repo; that is
> a human ruling.

---

## The fleet (`.claude/agents/`)

Named agents, each owning a band of the PRISM ladder. Spawn the owner rather than
doing their job by hand.

| Agent | Owns |
|---|---|
| `spine-owner` | Product ownership: spine-as-backlog, module specs, acceptance criteria, the frozen contracts |
| `cadence-master` | The graduate-and-teach cycle: cohorts, promotions, PR-per-deliverable, alpha scope |
| `module-builder` | One module's four LPAA beats, built after taking the prior module as a student |
| `compile-warden` | The mechanical gate — compiles, Mermaid, rubric lineage, trace tables. Evidence, never opinions |
| `cohort-lead` | Synthetic student cohorts; harvests failure transcripts into findings |
| `linx-voice-readability-editor` | Bar #2: readability and voice on everything a student reads |
| `liza-theme-skinner` | Dungeon canon, CYOA branching, two-skin lab variants |
| `kevin-repo-warden` | Repo hygiene: numbering, branches, conventional commits, the lore merge gate |
| `clive-prompt-warden` | Prompt integrity across builder agents, personas, and the taught prompt ladder |
| `program-advisor` | Outward-facing counsel: dean/committee rationale, CCL crosswalk, capstone architecture |

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
| 016 | Breadth first: a Learn beat in every module before more depth |
| 016 | An STE-100-derived editorial gate gives bar #2 an instrument (advisory) |
| 017 | Apply beats are written to the student; instructor content sits behind the boundary |

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
