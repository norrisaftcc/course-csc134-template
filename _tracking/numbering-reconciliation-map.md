# Numbering Reconciliation Map — Phase 0.2

**Author:** Kevin (repo warden) · **Date:** 2026-07-23 · **Branch:** `phase0/numbering-reconciliation`
**Status:** Rename PLAN only. No files renamed or moved in this pass, per `ULTRACODE_ALPHA_PLAN.md` §0.2.

## The algorithm (sources cited in every finding below)

- **Canonical module map:** `_storming/CSC-134-course-spine.md` — M0–M8, nine modules, weeks and content given in "The Modules" and "Sequencing & the 16-week map" (lines 96–290, 273–290).
- **Locked scope/process:** `_lore/decisions/ADR-001-alpha-scope-and-locked-decisions.md`, `ADR-002-phase0-rulings.md` (rubric column one = Correctness, PR target = `main`), `ADR-004-two-tier-git-workflow.md` (student flow = commit+push, no branches/PRs before capstone).
- **Manifest:** `_tracking/course-manifest-csc134.yaml` (v0.2, `last_updated: 2026-01-01` — predates the spine's July 2026 reorg) and its sibling trackers `_tracking/content-inventory.md`, `_tracking/module-status-review.md`, `_tracking/course-manifest-template.yaml`.
- **Plan:** `_storming/ULTRACODE_ALPHA_PLAN.md` §0.2 (this deliverable's own brief) and §2 (asset inputs).
- **Docket:** `_storming/agents-134/kevin-github-algorithm.md` / `.claude/agents/kevin-repo-warden.md` (my own standing charter — cited only as provenance for the known-drift list, not as an independent standard).

Everything below is evaluated against these; nothing here is vibes.

---

## 1. Rename-map table

| # | Current path / name | Canonical M-number (spine) | Proposed new name | Lands with | Cross-refs it will break |
|---|---|---|---|---|---|
| 1 | `M5LAB` (loops: while/for/array-search) | **M5** | *No rename* — already correct. | N/A | None. **Tension resolved:** `RETHEME_NOTES.md:52` flags a self-contradiction where the docket brief lists `M5LAB` as drift alongside `M6LAB2`/`M7LAB1`. The spine itself (`CSC-134-course-spine.md:207,211,366`) and `CSC-134-learning-objectives.md:105` are unanimous that `M5LAB` = loops = M5 = correct. Ruling: **the docket bullet is imprecise, not the filename.** No action; the docket text in `kevin-github-algorithm.md:18` / `kevin-repo-warden.md:18` should be read as "audit these three, only one is actually wrong," not "all three are wrong." |
| 2 | `M6LAB2` (parallel arrays → `Room` struct) | **M7** | `M7LAB0_ParallelArraysToStruct` (or equivalent — see open question #1) | M7, when ported | `CSC-134-course-spine.md:252,368` (asset table); `csc134_updated_outline.md:86` (AI-log gap note references `M6LAB2` by name); `agents-134/kevin-github-algorithm.md:18`, `.claude/agents/kevin-repo-warden.md:18`, `RETHEME_NOTES.md:48,52,176` (docket provenance — update once the rename lands). **Not yet a physical file anywhere in this repo** (confirmed: no `find` hit for `M6LAB2`/`M6LAB*` under any extension) — it is prior-offering material referenced by codename in planning prose, not yet imported. |
| 3 | `M7LAB1` (structs, tiered: Room→Hero→Monster→class) | **M7** | *No rename* — already correct. | N/A | None. Same not-yet-imported status as #2 — confirmed no physical file in this repo yet. |
| 4 | Functions content authored as **"Chapter 3"** / **"Module 02"** | **M6** | Add an explicit position-note header; do not renumber the chapter itself (content stays "Chapter 3" internally per spine's own ruling) | M6, when the M6 module scaffold is built | See §3 below — full exact-text diff. Breaks: `_past_work/_claudes_input/02-functions-week3-4/README.md:1-2,28`; ripples to `chapter-03-functions.md:1` (title only, no renumber needed — spine already ruled "content correct, position moves," `CSC-134-course-spine.md:361`). |
| 5 | **`module: M0X`** placeholder in all five skill-guild templates | N/A (template bug, not a module) | `module: MX` (bare, matches every *other* placeholder in the same files: `MXLABY`, `MX Apply`, `mX-exit-ticket.md`) | Immediate — this is upstream of every module the fleet will build | **CRITICAL — live generator bug.** Exact hits: `_storming/skills-134/reading-generator/SKILL.md:33`, `_storming/skills-134/lab-creator/SKILL.md:48`, `_storming/skills-134/rubric-converter/SKILL.md:52`, `_storming/skills-134/exit-ticket-generator/SKILL.md:102`, `_storming/skills-134/apply-tutorial-generator/SKILL.md:49` — each mirrored byte-for-byte at the same line in `.claude/skills/<name>/SKILL.md` (diffed, confirmed identical). See finding below the table. |
| 6 | `_storming/exemplars/m3-taco-receipt/M3LAB2_TacoReceipt.md:3` — frontmatter `module: M03` | **M3** | `module: M3` | M3 (already built as the M3 exemplar) | Direct casualty of #5 — this is the bug already firing in real output. **Not touched in this pass** (uncommitted WIP belonging to another session per my task brief) — flagged for that session/maintainer, not acted on. |
| 7 | `course-manifest-csc134.yaml` — entire `modules:` list (`M00`…`M08`, 8 modules, textbook-chapter order) | Should be **M0–M8, 9 modules**, spine order | See §2 (manifest delta) — this is a structural rebuild, not a filename swap | Manifest owner / spine-owner | Every `id:`, every `weeks:` array, and the `progress.by_module` block (`course-manifest-csc134.yaml:59-431`). Too large and structural for a single-row rename; broken out in §2. |
| 8 | `_tracking/course-manifest-template.yaml:53-142` — generic template ids `M01`…`M08` (1-indexed, padded, 8 modules) | Cross-course template; CSC-134 instance should override to bare `M0`–`M8` | *No rename to the template itself* — flag as a trap | Whoever regenerates `course-manifest-csc134.yaml` from this template next | Nothing breaks yet, but this is the likely **source** of the current manifest's wrong scheme (see open question #6) — a second course instantiating this template inherits the same drift blind. |
| 9 | `csc134-refresh-plan/CSC-134-course-spine.md` — full duplicate fork of the canonical spine | N/A (documentation-integrity finding, not a module number) | Mark clearly as an archival fork of a specific point-in-time, or relocate out of this repo | N/A | Already diverged from canonical: `csc134-refresh-plan/CSC-134-course-spine.md:128` still reads **"Precision"** for rubric column one; the canonical `_storming/CSC-134-course-spine.md:128` was patched to **"Correctness"** by ADR-002 (`_lore/decisions/ADR-002-phase0-rulings.md:14-20`). Committed at `816e2b5` ("csc134 refresh planning docs, need their own fork"), one commit before the canonical spine's ADR-002 patch at `56b15ae`. Anyone reading the wrong copy inherits a superseded ruling. |
| 10 | `assignments/m0/02_first_pull_request.md` | N/A (workflow-convention finding surfaced during the audit, not a numbering item — flagged for the record) | Rewrite to teach commit+push only, or explicitly carve out an ADR exception | M0 (already live, students-facing) | Teaches the full `Fork → Clone → Branch → … → Pull Request → Review → Merge` cycle (`assignments/m0/02_first_pull_request.md:10,87-109,122-128`) to Module-0 students. This is the exact shape ADR-004 rules out for student flow: *"commit + push directly, no branches, no PRs… Branching enters as a capstone-tier topic (M8 territory, out of alpha depth scope)"* (`_lore/decisions/ADR-004-two-tier-git-workflow.md:21-22,37`). Also the spine's own M1 Apply beat says "repo → README → commit → push, **no branch**" (`CSC-134-course-spine.md` M1 section). This is a **Critical, docket-relevant finding** (Submission workflow: *"If a lab's submission instructions and the repo's actual mechanics disagree, that's Critical"*) surfaced while auditing `assignments/m0/`; out of strict numbering scope, so not actioned here, but too load-bearing to hold back. |
| 11 | `_past_work/_claudes_input/03-decisions-week5-6/README.md:1` ("Module 03: Decision Structures") and `04-loops-week7-8/README.md:1` ("Module 04: Loops") | M4, M5 respectively | *No rename needed* | Already reconciled | The spine's own asset table already accounts for this exact drift without ambiguity (`CSC-134-course-spine.md:362-363`: "Chapter 4 / Module 03 — Decision Structures → M4"; "Chapter 5 / Module 04 — Loops → M5"). Checked and confirmed clean — listed here only to show the `_past_work/_claudes_input/0{3,4}-*` legacy folder names were audited, not skipped. |

### Finding detail — Row 5, the skill-guild `module: M0X` bug

Every one of the five skill templates uses **two different placeholder conventions in the same file** for the same concept:

```
title: "MXLABY: [Lab Title]"      ← bare X, correct
module: M0X                       ← zero-padded, WRONG
```

(`lab-creator/SKILL.md:47-48`; the same split pattern repeats in `reading-generator/SKILL.md:31,33`, `rubric-converter/SKILL.md:50,52`, `exit-ticket-generator/SKILL.md:99,102`, `apply-tutorial-generator/SKILL.md:47,49`.)

Filled in, `M0X` produces `M03`, `M04`, `M07` — the same zero-padded scheme as the stale pre-spine manifest, not the spine's bare `M0`–`M8`. This has already fired once for real: `_storming/exemplars/m3-taco-receipt/M3LAB2_TacoReceipt.md:3` carries `module: M03`. A cached fill-in in `_claude_sage/files/skill-reading-generator.md:183` (and its two duplicates under `_claude_sage/files/`) shows `module: M01` — same bug, same source. Because every future module the fleet builds runs through these templates (`reading-generator`, `lab-creator`, `rubric-converter`, `exit-ticket-generator`, `apply-tutorial-generator` — the entire Learn/Practice/Assess skill guild per `ULTRACODE_ALPHA_PLAN.md` §6 step 3), **this is the highest-leverage fix in this reconciliation**: five one-line edits now vs. an unknown number of drifted student-facing frontmatter fields later, each one corrupting a competency record the way this docket exists to prevent.

**Proposed fix (for the module owner to apply, not applied in this pass):** in each of the 5 files × 2 locations (10 lines total), change `module: M0X` → `module: MX`.

---

## 2. Manifest delta — `_tracking/course-manifest-csc134.yaml`

The manifest is not a numbering-only problem. It was last updated 2026-01-01 ("reconciled with existing high-quality materials," `course-manifest-csc134.yaml:5`), **before** the spine's reorg — it encodes the *old* textbook-chapter-order sequence, not the spine's decisions/loops-before-functions order. `_tracking/module-status-review.md:17` and `:236` already say this out loud: *"The manifest structure follows textbook chapter order, while `_past_work/` content follows a different pedagogical sequence."* Confirming that diagnosis still holds against the current spine:

| Manifest entry (current) | Spine module it actually matches | Gap |
|---|---|---|
| `M00` Introduction & Environment Setup, wk 1 (`:59-82`) | M0 Welcome to Programming | Mostly matches, **except** the PR-workflow deliverable (`02_first_pull_request.md`) — see rename-map row 10. |
| `M01` Variables and Basic I/O, wk 2 (`:84-124`) | **M3** Program Basics (variables, cin/cout, arithmetic) — not M1 | Wrong id *and* wrong slot. Content has no relationship to spine M1 (Talk to Computers: Markdown, Robot Sandwich, pull/commit/push). |
| `M02` User Input and Advanced Calculations, wk 3 (`:126-166`) | Also **M3** Program Basics | Same problem — this and `M01` are both Program-Basics content split across two manifest entries with no M3 entry at all. |
| `M03` Functions, wks 4-5, all `planned` (`:168-204`) | **M6** Functions, wks 9-10 | Id and weeks both wrong; content stubs are all unbuilt (`status: planned`) so this is a clean number/week fix, nothing to break. |
| `M04` Decision Structures, wks 6-7, all `planned` (`:206-243`) | **M4** Decisions, wks 5-6 | Id happens to collide with spine's bare `M4` in spelling only (`M04` vs `M4`) — still needs the padding stripped and weeks corrected. |
| `M05` Loops, wks 8-9, all `planned` (`:245-283`) | **M5** Loops, wks 7-8 | Same shape as M04 row — strip padding, fix weeks. |
| `M06` Arrays and Strings (STL, `std::string`), wks 10-11, all `planned` (`:285-321`) | Partially **M7** (raw arrays are in M7's progression) | Spine's M7 has no STL-algorithms or `std::string`-focused content — **open question #2**, needs a ruling on whether this content survives, and where. |
| `M07` File I/O and Structs, wks 12-13, all `planned` (`:323-359`) | Structs half → **M7**. File I/O has **no home anywhere in the current spine** (absent from the CCL crosswalk, absent from all nine module descriptions). | **Open question #2** again — File I/O may be descoped entirely; needs an explicit ruling, not a silent drop. |
| `M08` Introduction to OOP, wks 14-16, all `planned` (`:361-408`) | Classes/OOP half → **M7** (struct→class arc). Capstone-shaped deliverables (`project-oop-rpg`, `capstone-portfolio`) → **M8** Capstone, but M8's actual shape is "design doc before code," not a reading+lab+project ladder. | Needs splitting across two modules, not a renumber. |
| **Missing entirely:** spine M1 (Talk to Computers) and M2 (How to Solve Problems) | — | No manifest module currently represents these at all. The manifest has 8 modules; the spine has 9. |
| `progress.total_deliverables: 54`, `progress.by_module` (`:413-431`) | — | Downstream of every row above — must be recomputed after the module list is rebuilt, not hand-patched entry by entry. |

**What I am *not* doing:** rewriting the manifest. This table describes the target shape; actually moving `assignments/m1/*` and `assignments/m2/*` deliverables into a rebuilt M3 entry, deciding the STL/File-I/O question, and splitting the M08 entry across M7/M8 all require a maintainer ruling first (see open questions). None of this is "trivial and unambiguous" — it's a full manifest rebuild against a module map that didn't exist when the manifest was last touched.

---

## 3. Functions-chapter position-note relabel

**Exact file:** `_past_work/_claudes_input/02-functions-week3-4/README.md`

**Exact current text (lines 1–2):**

```
# Module 02: Functions - Breaking Down Problems Like a Pro Chef
## Weeks 3-4 | Badge: Program Design and Implementation
```

**Exact proposed text:**

```
# Module 02: Functions - Breaking Down Problems Like a Pro Chef
## Delivered as M6 (Weeks 9-10) | Badge: Program Design and Implementation

> **Position note:** This content is authored as "Chapter 3 / Module 02" — a legacy of the
> old functions-first ordering. Under the current spine (`_storming/CSC-134-course-spine.md`),
> decisions and loops now come before functions, so this content delivers as **M6**, weeks 9-10,
> not weeks 3-4. The content itself is correct and unchanged — only its position in the
> sequence moved. See `CSC-134-course-spine.md:289` for the full reconciliation note.
```

Same position-note treatment applies to the companion chapter file's title line:

**Exact file:** `_past_work/_claudes_input/02-functions-week3-4/chapter-03-functions.md`

**Exact current text (line 1):**
```
# Chapter 3: Introduction to Functions
```

**Exact proposed text (line 1, one-line position note inserted directly below, not a renumber):**
```
# Chapter 3: Introduction to Functions
> *(Delivered as Module M6 in the current sequence — see the course spine's sequencing note.)*
```

**Caveat (see open question #4):** `_past_work/` is a self-declared archival/legacy directory (`_past_work/README.md`, `_past_work/CLAUDE.md`) — it is possible the spine's asset-table entry "Chapter 3 / Module 02 — Functions" (`CSC-134-course-spine.md:361`) actually refers to a not-yet-imported external document (an instructor's own working copy) rather than this archived file, in which case the relabel should land on the external source, not here. This is the only file in the repo whose title literally matches "Chapter 3" + "Functions," so I'm citing it as the best available candidate, not a certainty.

---

## 4. Open questions

1. **M6LAB2's landing shape.** Does the parallel-arrays-to-struct material become a standalone ported file (`M7LAB0` or similar) under M7, or does it get absorbed as the C-tier section *inside* `M7LAB1` itself? The spine's Assess section (`CSC-134-course-spine.md:248`) describes M7LAB1's C-tier as exactly "refactor parallel arrays into a Room struct array" — i.e., M6LAB2's job — while the Assets table (`:252,368`) lists them as two separate assets. Needs a builder/maintainer call before either lands.
2. **STL/`std::string` (manifest M06) and File I/O (manifest M07) have no home in the current spine.** Descoped entirely, or does the spine need an addendum? This can't be resolved by renumbering — it's a scope ruling, likely its own ADR.
3. **`assignments/m0/02_first_pull_request.md` teaches fork/branch/PR to Module-0 students**, contradicting ADR-004's student-flow rule (commit+push only, no PRs before capstone). Rewrite the lab, or is ADR-004 understood as forward-looking only and this pre-existing asset gets a grandfather exception? Needs an explicit ruling either way — right now the taught workflow and the locked convention disagree.
4. **Is `_past_work/_claudes_input/02-functions-week3-4/` the actual asset the spine's "Chapter 3 / Module 02 — Functions" table entry refers to**, or a different not-yet-imported document? Confirm before actioning §3's relabel.
5. **`csc134-refresh-plan/` is a full duplicate fork of the spine that has already drifted** (still shows the pre-ADR-002 "Precision" ruling). Is this meant to become CTI-110's independent spine per its own commit message ("need their own fork")? If so it should be clearly marked archival or relocated out of this repo before someone edits the wrong copy.
6. **`_tracking/course-manifest-template.yaml` defaults to `M01`–`M08` (1-indexed, padded)** — likely the ancestral source of the current manifest's wrong scheme. Should the CSC-134 rebuild explicitly override to bare `M0`–`M8`, and should the template itself carry a comment warning that per-course spines may be 0-indexed?
7. **The ten completed deliverables currently split across manifest `M01`+`M02`** (`assignments/m1/*`, `assignments/m2/*`) all need a landing spot inside a single rebuilt spine-M3 entry — do all ten survive as M3's Apply/Assess artifacts (heavier than the spine's stated M3 scope), or does some content get trimmed/reassigned? A content-scope call, not a rename.

---

*Prepared per `ULTRACODE_ALPHA_PLAN.md` §0.2. No files renamed, moved, or edited outside this map. The M3 exemplar WIP (`INSTRUCTOR_GUIDE.md`, `M3LAB2_TacoReceipt.md`) and the untracked `CSC_DASH_CROSSWALK.md` / `persona-museum-live.html` were read only where directly relevant to a finding (row 6) and were not modified.*
