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

Every deliverable clears all of these. Bars 1–3 are enforced mechanically by CI
and the compile-warden; the rest are enforced by review. A PR that fails any is
not done.

1. **Clean compile.** Every C++ source in every artifact builds under
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
2. **Fenced blocks are views of gated source** (ADR-015). A ` ```cpp ` block in
   Markdown is not source — it is a view of a gated `.cpp`, and it must say so on
   the fence info-string: `source=<path>` for a whole file, `excerpt=<path>` for
   part of one. Matching is exact text, comments included; the only softener is a
   `// ...` elision line. No line numbers, no skip, no mute. Write the `.cpp`
   first, then quote it; `bash .github/scripts/markdown-gate.sh` checks the rest.
   Broken-on-purpose code is an `excerpt=` of a file marked
   `// GATE: EXPECT-WARNING` or `// GATE: EXPECT-ERROR` — **assertions, not
   mutes**: a marked file that stops misbehaving fails the gate.
3. **The repo's claims about itself are checked too** (`lpaa-gate.sh`, blocking
   since 2026-08-01; F-019). Six false status claims shipped in one week before
   this existed. Three things it makes non-optional:
   - **Frontmatter.** Every beat file carries `module:` matching its directory
     (`M4`) and `lpaa_beat:` matching its filename (`Learn` / `Practice` /
     `Apply` / `Assess`). Missing frontmatter is a failure, not a warning.
   - **Status and file set agree, in both directions.** `modules/MODULES.md`
     holds the status table the gate parses. Shipping a beat without bumping the
     module's status fails; so does bumping the status before the files exist.
     Landing a beat means editing that table **in the same PR**. And no
     `NOT YET AUTHORED` survives inside a `Built` or `Ready` module (F-014 §5) —
     retarget the stub banner when its lab lands.
   - **Audience boundary** (ADR-017, F-018). Apply beats are written *to the
     student*. Instructor-only material stays in the same file but below a
     heading containing the literal phrase **`not part of the student handout`**,
     and every instructor marker sits under it. A student-facing beat never names
     `practice-exit-ticket-key.md`.
4. **10th-grade readability** on all student-facing prose (code excluded).
   Complexity lives in the *problem*, never in the sentence describing it. Linx
   owns the readability pass.
5. **Single-file convention.** No multi-file projects. **Its form is
   module-dependent:** before M6, everything lives in `main` — no functions, no
   prototypes (the "pre-M6 incomplete form"). From M6 on, the full shape:
   prototypes at top, `main` in the middle, definitions at the bottom. Do not
   use functions in M2–M5 material; they are not taught yet.
6. **Four-word error taxonomy, used consistently.** The only names for errors:
   **Syntax** ("broke the grammar"), **Static semantic** ("grammar fine, meaning
   impossible"), **Runtime** ("ran, then fell over"), **Logic** ("did what you
   said, not what you meant"). Use these words; do not coin synonyms.
7. **Mermaid renders.** All flowcharts are Mermaid-in-Markdown (renders natively
   on GitHub, reuses the M1 skill). Verify the diagram actually renders — a
   broken ` ```mermaid ` block is a failed deliverable.
8. **Rubrics descend from the four columns.** Every lab rubric inherits
   `_contracts/rubric-template.md`: **Correctness / Completeness / Format /
   Submission** × **C / B / A / Badge**. Column one is **Correctness** (ADR-002,
   never "Precision"). No new columns, no hidden criteria.
9. **No trick questions.** Stated policy. Assessments verify the objectives, not
   stamina or lawyer-reading. Exit tickets are low-stakes and completion-gated.
10. **Stay on the Make gradient.** Apply-beat scaffolding shifts by module:
    **M2–M4 type-in 100%**, **M5–M7 finish-the-80%**, **M8 spec-only**. Build the
    beat at its module's position; do not hand M4 a spec or M7 a full type-in.
11. **Staged builds.** Demos and instructor examples build in stages; each stage
    compiles and runs standalone, so complexity accumulates visibly. Mark the
    stages in comments. A stage is **a shorter whole program, not a slice of the
    final one** — so each stage is its own gated file (`apply-stage1-*.cpp`,
    `apply-stage2-*.cpp`, …) and this bar is actually checked.

### Run the gates before you push

Three gates, three jobs, one workflow (`.github/workflows/compile-gate.yml`) —
all blocking on every PR. They compose; nothing exempts an artifact from any:

```bash
bash .github/scripts/compile-gate.sh    # zero warnings under the student toolchain
bash .github/scripts/markdown-gate.sh   # every cpp fence declares source= / excerpt=
bash .github/scripts/lpaa-gate.sh       # frontmatter, status, stubs, audience boundary
```

Scope a fast loop with `SEARCH_PATHS=modules/m6 bash .github/scripts/compile-gate.sh`
(it takes directories or single files). Exit `2` means a configuration problem —
compiler missing, no files found — **not** a pass. Each gate has self-tests under
`.github/scripts/selftest/`; if you change a gate, they must still bite. Full
reference: `.github/scripts/README.md`.

What the gates deliberately do **not** judge is whether the content is any good.
That takes a cohort round (below).

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
- `_tracking/` — the machine-readable course manifest, the breadth-pass ledger,
  and cohort round records.
- `_outputs/` — **generated artifacts, not ground truth** (ADR-012). Composed Canvas
  HTML lands here, never in `modules/`. Never hand-edit a file in `_outputs/`: edit the
  Markdown source and re-emit, or the change is lost on the next build — after surviving
  just long enough to be believed. Committed so formatting churn is reviewable in a diff.
- `.github/scripts/` — the three gates and their self-tests. Read its README
  before changing anything that runs in CI.
- `assignments/` — **frozen legacy tree** (ADR-008). `modules/` is the only build
  target; never scaffold into `assignments/`. Ports out of it land per-module,
  each with its own ruling.
- `instructor-guide/`, `outline/`, `_claude_sage/` — supporting material outside
  the module build. Leave them alone unless the task names them.

**Port before authoring.** The spine's asset table says what adapts vs. what is
new. Adapt existing assets (cheaper, safer); do not duplicate them. Treat
`csc134-refresh-plan/` as a stale fork — mine it for material, trust the spine.

---

## `modules/` — the build target

`modules/m0` … `modules/m8`, one folder per module. **`modules/MODULES.md` is the
index**: it carries the status table (which the LPAA gate parses), the per-status
file shape, and the Make gradient by module. Read it before building into a
module; update it in the same PR when you land a beat.

Four status words, and they mean specific things:

| Status | Means |
|---|---|
| **Skeleton** | Structure only — `_overview.md`, `_mlos.md`, `_assets.md`, `_assess-spec.STUB.md`. |
| **First pass** | One real, gate-green, student-facing artifact: the **Learn beat** (ADR-016). |
| **Built** | All four LPAA beats authored and gate-green. |
| **Ready** | Built, *plus* taken end to end by a synthetic cohort with every finding closed. |

Today: **M4 and M5 are `Ready`**; **M0–M3 and M6–M8 are `First pass`** — Learn
beat only. M0 and M1 are pre-C++ and correctly have **no `code/` directory**.

Beat files are named for the beat (`learn.md`, `practice-exit-ticket.md`,
`practice-exit-ticket-key.md`, `apply-tutorial.md`, `assess-lab.md`) — the gate
maps filename to `lpaa_beat`, so these names are not cosmetic.

`modules/mN/code/` holds **sources only**, named `<beat>-<slug>.cpp`
(`learn-gate-full.cpp`, `apply-stage2-class.cpp`, `practice-item4-doors.cpp`).
Deliberate breakers are `*-break-*.cpp` and carry a `// GATE:` marker.

> **`.gitignore` trap:** `modules/*/code/*` is ignored with `.cpp` / `.h` / `.md`
> allowed back in, because compiled binaries are extensionless on macOS/Linux and
> no `*.ext` rule catches them. Add a new source type to that allow-list or git
> will **silently** ignore your file.

`_assess-spec.STUB.md` stops being a stub once its lab is authored — it becomes
the build record for why the lab asks what it asks. If it ever disagrees with
`assess-lab.md`, the lab wins.

---

## How content gets certified

Gates prove an artifact is *mechanically* sound. They cannot tell you it teaches.
That is what the **synthetic cohort** is for: fresh-spawn student agents take a
module end to end, and their failure transcripts become findings.

The three approved personas live in `_storming/personas-134/` — **Maria** (the
Literalist; Chromebook-only, so Codespaces is her only path), **Jaylen** (the
Skimmer), **Dee** (the Rules-Lawyer). Two rules travel with them: a cohort student
must be a **fresh spawn** (any prior exposure is contamination and disqualifies
them as a naive tester), and **no transcript citation, no finding** — a fabricated
finding is worse than none. Rounds are recorded in `_tracking/cohort/` and
`_lore/findings/`; `Ready` is what a closed round buys you.

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
embodies a decision, write the ADR. If a PR genuinely changed nothing worth
remembering, say so in the description and let Kevin disagree.

Two amendments worth knowing:

- **Breadth-pass module PRs take a lighter shape** (ADR-016 §7): a row in
  `_tracking/breadth-pass-ledger.md` plus a build note appended to F-015
  satisfies the gate, instead of a fresh ADR per module.
- **Do not grab a contested ADR number.** If a decision surfaces that you cannot
  make, record it as an open question for a human ruling. **ADR-013 is reserved
  and deliberately unwritten** (the Haiku persona ruling, issue #23) — ADR-014,
  015, and 017 each carry a note saying they skipped it rather than take it.
  Findings numbering has the same texture: F-011 and F-012 do not exist and
  F-009 has two files. Check `ls _lore/decisions/` before you number anything.

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

The skills are installed at `.claude/skills/` and the agent fleet at
`.claude/agents/`, so both travel with a clone. **The installed copies are
authoritative** — `_storming/skills-134/` and `_storming/agents-134/` are the
sources they were built from and have drifted (their frontmatter disagrees with
ADR-003 on four model assignments). Edit the installed file; sync the source.

When in doubt: the spine decides *what*, the contracts fix the *shapes*, the
skills carry the *how*, and this file holds the *invariants*.

## Copilot CI triage guardrail

When investigating a failed GitHub Actions run from a `Fix with Copilot` link,
keep tool output small: call `actions_list` with narrow filters (`per_page`,
`branch`, `event`, `status`) and then jump to `actions_get` for the exact run
ID plus `get_job_logs` for the failed job. Avoid unfiltered run listings.
