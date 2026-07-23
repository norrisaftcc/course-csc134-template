# CSC-134 Alpha Build — Ultracode Orchestration Plan

**Status:** Handoff-ready draft · July 23, 2026
**Audience:** The Claude Code session (ultracode mode) that will execute this build, and the two humans supervising it.
**Ground truth:** `_storming/CSC-134-course-spine.md` is the spec. Where this plan and the spine disagree, the spine wins and the disagreement gets an ADR in `_lore/decisions/`.

---

## 1. Mission and alpha definition (locked)

Build the **alpha** of the CSC-134 course refresh:

- **All nine modules (M0–M8) scaffolded**: module directory, README, module learning objectives, and an Assess spec stub each.
- **M4 (Decisions) and M5 (Loops) built to full LPAA depth** — all four beats, assessed artifacts, rubrics — with the **M4→M5 seam demonstrated** (M5 material visibly builds on the M4 program, per the Make gradient).
- **Dungeon theme is canon** for instructor-facing material. Student-side re-skinning is supported and used as a test (see §6).
- Out of scope for alpha: M8 capstone content beyond its scaffold stub, multi-file projects, Canvas/LMS packaging, thinkcpp fork decisions.

The alpha exists so humans can review a *calibration exemplar pair* before the remaining modules are built at depth.

## 2. Inputs

| Input | Path | Role |
|---|---|---|
| Course spine | `_storming/CSC-134-course-spine.md` | Canonical spec |
| Learning objectives (forward + by-outcome) | `_storming/CSC-134-learning-objectives.md`, `_storming/CSC-134-objectives-by-outcome.md` | MLO/CLO conformance |
| PRISM mapping | `_storming/PRISM_Course_Mapping_csc134.md` | Tier canon for fleet + course |
| Agent fleet (v3) | `_storming/agents-134/*.md` | Install as `.claude/agents/` |
| Skill guild (134 edition) | `_storming/skills-134/*/SKILL.md` | Install as `.claude/skills/` |
| Student personas | `_storming/personas-134/*.md` | Cohort inputs — **human-reviewed before first use** |
| C++ style guide | `_past_work/materials/style-guide-cpp.md` | Format column source |
| Existing assets | Per the spine's asset table | Port/adapt before authoring new |
| Manifest | `_tracking/course-manifest-csc134.yaml` | Machine-readable work list (renumber in Phase 0) |

## 3. The fleet (PRISM-tiered org chart)

| Agent (file) | Role | PRISM | Model |
|---|---|---|---|
| `scrum-architect-owner` → **spine-owner** | Backlog + Phase 0 interface contracts | YELLOW | opus |
| `scrum-project-manager` → **cadence-master** | Promotion cycles, PR gates, scope guard | BLUE* | inherit |
| `scrum-team-engineer` → **module-builder** | Builds module N+1 after taking N | ORANGE | inherit |
| `product-architect-advisor` → **program-advisor** | Dean/committee-facing rationale, reviews | YELLOW | opus |
| `clive-prompt-strategist` | Prompt warden; owns persona sheets + AI ladder | YELLOW | opus |
| `linx-wordsmith` | 10th-grade readability + voice editor | — | sonnet |
| `liza-creative-companion` | Theme skinner; dungeon canon; two-skin variants | ORANGE | inherit |
| `kevin-github-algorithm` | Repo warden: numbering, PRs, commits, manifest, `_lore/` gate | INFRARED→RED enforce | sonnet |
| `test-engineer` → **compile-warden** | Mechanical gate: compile every block, verify tables | RED gate | sonnet |
| `product-acceptance-tester` → **cohort-lead** | Runs the synthetic student cohort | — | sonnet |

*\*BLUE tier is inferred, pending human confirmation (open ruling #2).*

**Model economics:** INFRARED/RED mechanical tasks run cheap (haiku or low-effort sonnet); ORANGE building runs at session default; YELLOW review runs opus or high effort. Synthetic students run cheap-to-mid — confusion does not require intelligence, and an over-smart student defeats the persona.

## 4. Standing rules (all phases)

1. **The `_lore/` gate:** no PR merges without its lore entry (decision, finding, or glossary delta). Kevin enforces. Marks on the wall, daily.
2. **PR-per-deliverable**, conventional commits, human review at every PR. Branch naming: `phase0/<topic>`, `module/m4-deep`, `cohort/m4-round<N>`.
3. **Contamination rules:** students are always fresh spawns; a graduate never re-enters a cohort; the builder of module N never sits in module N's cohort.
4. **Quality bars (mechanical, no exceptions):** `g++ -std=c++17 -Wall -Wextra` zero-warning compile on every C++ block in every artifact; 10th-grade readability on student-facing prose (code excluded); Mermaid renders; rubrics descend from the Robot Sandwich four columns as C/B/A/Badge tiers; single-file convention (noting its pre-M6 incomplete form); four-word error taxonomy used consistently; no trick questions.
5. **Skin ≠ structure:** dungeon flavor must strip cleanly. Liza proves it; the cohort fuzzes it.
6. **Port before authoring:** the spine's asset table says what adapts vs. what's new. Adapting is cheaper and safer.

## 5. Phase 0 — Contracts and scaffolding (mostly sequential, by design)

Phase 0 items are barriers on purpose: everything downstream builds against them.

- **0.1 Open rulings (humans, before or during Phase 0):**
  1. Rubric column one: **Precision vs. Correctness** — the spine disagrees with itself (Robot Sandwich lineage says Precision; assessment section says Correctness). One word, one ADR.
  2. Confirm cadence-master's BLUE tier.
  3. Confirm the spine-owner / program-advisor boundary (proposed: owner decides inward, advisor argues outward and may dissent in writing; M8 conflicts deferred — M8 depth is out of alpha scope).
  4. PR target: `main` of `course-csc134-template`, or a `alpha` integration branch? (Proposed: `alpha` branch, merged to main at alpha acceptance.)
- **0.2 Numbering reconciliation (Kevin):** manifest updated to clean M0–M8; lab filename drift (`M5LAB`, `M6LAB2`, `M7LAB1`) audited and mapped in a table (rename plan, not mass renames — renames land with the module that owns them). Includes re-labeling the Functions chapter position note.
- **0.3 Interface contracts (spine-owner):**
  - Canonical **M4 decision program** (CYOA gatekeeper) and **M5 menu program** — the actual .cpp files later modules refactor. Each compiles clean, carries the spine's staged-build structure.
  - **Rubric template** instantiating the four columns × C/B/A/Badge (uses ruling #1).
  - **Builder `CLAUDE.md`** for the repo: conventions pack distilled from the spine (quality bars above, voice pointers, file layout). Keep under ~1,500 words; skills carry the details.
- **0.4 `_lore/` scaffold:** README, ADR-000 (the convention itself), ADR-001 (locked alpha decisions), glossary seed, findings ledger stub. *(Done in the same delivery as this plan — the wall has its first marks.)*
- **0.5 Persona sheets:** Clive reviews the three drafts in `_storming/personas-134/`, humans approve. No cohort runs on unapproved sheets.
- **0.6 Skeleton pass (parallel fan-out, cheap):** all nine module directories scaffolded from the spine's module sections — README, MLOs, Assess spec stub, asset-slotting notes. Linx does a readability pass on all student-facing stubs. One PR per module or one batch PR; Kevin's call.

**Exit criteria:** rulings recorded as ADRs; contracts merged; skeleton merged; personas approved.

## 6. Phases 1–2 — The promotion cycles (deep builds)

The dependency chain is the mechanism: **an agent takes module N as a student, then builds module N+1.**

**Cycle structure (runs twice: M4, then M5):**

1. **Enrollment.** Cohort-lead spawns fresh students (Maria, Jaylen, Dee at minimum) against module N−1/N's existing materials (first cycle: M2/M3 assets as-is — their rough edges are findings for the backlog, not blockers). Each student runs in an **isolated worktree** with the real toolchain: reads Learn, answers the exit ticket, types the Apply program, compiles it, attempts the Assess from spec. Per-student theme re-skin is active (skin/structure fuzz).
2. **Graduation & promotion.** One passing agent's transcript seeds the **module-builder** instance for module N+1. The builder carries fresh memory of being a student — that's the point.
3. **Build.** Module-builder produces all four LPAA beats for N+1 using the skill guild: `reading-generator` (Learn), `exit-ticket-generator` (Practice), `apply-tutorial-generator` (Apply — FULL mode for M4, EIGHTY mode opens in M5 per the Make gradient), `lab-creator` + `rubric-converter` (Assess). Staged builds; every stage compiles standalone. Liza flavors; Linx edits; existing assets (Ch. 4/Module 03 for M4; Ch. 5/Module 04, M5LAB_A, Two-Skin Exemplar for M5) are ported, not duplicated.
4. **Mechanical gate.** Compile-warden extracts and compiles everything, verifies trace tables against real runs, checks Mermaid/rubric lineage/convention. FAIL returns to builder; no cohort tokens spent on material that doesn't compile.
5. **Cohort QA, loop-until-dry.** Fresh cohort takes the new module for real. Findings filed as issues (severity-tagged) to the builder; fixed; **new fresh cohort** each round. Dry = two consecutive rounds with no new above-threshold findings. Zero findings in round one is treated as a red flag (rubber-stamp check), not a pass.
6. **Harvest.** Failure transcripts → instructor-guide common-mistakes entries and exit-ticket distractor banks (via the generator's distractor-bank input). This is deliverable content, not exhaust.
7. **PR + human review.** Cadence-master opens the module PR with the lore entry, cohort report, and harvest attached. Humans review; merge closes the cycle.

**Phase 1 = M4 cycle. Phase 2 = M5 cycle**, with the seam exhibit: M5's Apply/Assess visibly extend the canonical M4 program, and the EIGHTY-mode debut is called out for reviewers.

## 7. Phase 3 — Verification sweep and alpha report

Parallel, after Phase 2 merges:

- **Full mechanical sweep** (compile-warden): every artifact in the repo, one pass/fail table.
- **Continuity check:** cross-module seams (M4→M5 references, contract programs actually used), theme coherence, numbering consistency against the manifest.
- **Objective conformance:** every M4/M5 artifact maps to its MLOs; the I/D/M table's M4/M5 rows hold.
- **Completeness critic:** one agent asks "what's missing — beat not built, claim unverified, asset unported, finding unclosed?" Its findings are the alpha report's open-items list, not silently dropped.
- **Alpha report** (program-advisor): what was built, what the cohort found, what's open, and the recommendation for the beta pass (remaining modules at depth). Written to `_lore/` and the PR.

**Definition of done:** nine scaffolds merged; M4+M5 full LPAA with all gates green and cohorts dry; harvest banks populated; manifest clean; sweep table all-pass or exceptions ADR'd; alpha report delivered.

## 8. Workflow shape notes (for the ultracode session)

- Phase 0 is sequential where it's contracts, parallel where it's scaffolds. Don't parallelize rulings.
- Cohort personas run as a **parallel fan-out with worktree isolation** (they compile and mutate files). Rounds are barriers by nature (findings must be consolidated before the fix pass).
- The promotion cycles are **serial by design** — do not "optimize" M4 and M5 into parallel builds; the graduate seeding is the point.
- Loop-until-dry needs a cap: max 4 cohort rounds per module before escalating to humans (a module that can't dry in 4 has a spec problem, not a polish problem).
- Log every bounded choice (`log()` what was skipped/capped). Silent truncation reads as coverage.
- Budget note: cohort rounds dominate cost. Cheap students, fresh spawns, tight persona prompts.

## 9. Risk register

| Risk | Mitigation |
|---|---|
| Rubber-stamp cohort | Adversarial persona sheets (approved by humans); zero-findings-round-one = red flag; Dee exists |
| Theme leak (skin welded to structure) | Per-student re-skins as fuzz; Liza's re-skin test on canon artifacts |
| Contamination (graduates as testers) | Cadence-master enforces fresh-spawn rule; Clive audits persona provenance |
| Scope creep past alpha | Cadence-master guards; anything M6+ deep goes to backlog with an ADR |
| Fabricated distractors/mistakes | Harvest entries must cite a transcript; compile-warden spot-verifies claimed error outputs |
| Spine self-disagreements discovered mid-build | Spine wins; disagreement gets an ADR and a spine patch PR, never a silent local fix |

---

*Prepared for handoff by the Cowork session of 2026-07-23. The fleet is in `_storming/agents-134/`, the guild in `_storming/skills-134/`, the ancestors in the museum, and the wall is ready for marks.*
