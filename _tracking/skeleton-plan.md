# CSC-134 Skeleton Layout Plan — v0.6 (AUTHORITATIVE)

**Owner:** Spine Owner · **Date:** 2026-07-24 · **Status:** Authoritative for the M0–M8 scaffolding fan-out.
**Ground truth:** `_storming/CSC-134-course-spine.md`. **Inputs honored:** `_tracking/numbering-reconciliation-map.md` (F-001), `_contracts/rubric-template.md`, `CLAUDE.md` file-layout ("per-module folders as the skeleton pass defines them" — defined here).

This spec fixes *where* the nine module scaffolds land and *what files* each gets, so a parallel
fleet of module-builders can run without clobbering anything or baking numbering drift into the layout.
It authors **no lesson content**, creates **no ADRs**, and moves/renames/deletes **nothing**.

---

## 1. The namespace call (the load-bearing decision)

**Canonical spine skeleton lives in a NEW top-level `modules/` tree, spine-numbered `modules/m0/` … `modules/m8/`.**
**Legacy `assignments/` is FROZEN this pass** — a porting *source* only, never a scaffold target.

**Why a fresh tree instead of scaffolding into `assignments/mN`:** the `assignments/` numbering is drifted
(F-001). `assignments/m1` ("Variables and Basic I/O") and `assignments/m2` ("User Input and Advanced
Calculations") physically hold **spine-M3 (Program Basics)** content — while spine **M1 (Talk to Computers)**
and **M2 (How to Solve Problems)** are *new* modules with no directory at all. There is no way to place spine
M0–M8 into `assignments/mN` without either **moving files** (forbidden this pass — F-001 renames land later
with the owning module) or **baking drift into the layout** (a spine-M1 overview sitting in a folder full of
M3 content). A fresh spine-true namespace makes both impossible by construction: there is nothing to clobber,
and every directory number equals its spine number from the first byte.

- `modules/mN/` — **canonical.** Spine-numbered, ground truth, where the fan-out builds.
- `assignments/mN/` — **legacy, frozen.** Drifted numbering (F-001), not authoritative. Do **not** create,
  edit, move, or delete anything here in the skeleton pass. Referenced only as a porting source, recorded in
  each canonical module's `_assets.md`.

The two trees coexist through the transition. F-001 renames become "**port asset X from `assignments/` into
`modules/mN`**" operations, each owned by its module and landing later — exactly as the reconciliation map requires.

---

## 2. Per-module file set (identical for every M0–M8)

Each `modules/mN/` scaffold gets **exactly these four files**. All are `_`-prefixed — matching this repo's
convention that a leading underscore marks structure/meta (`_storming`, `_contracts`, `_lore`, `_tracking`),
sorting them above any future `Mx*` content, and guaranteeing **zero collision** with the legacy `README.md`
and `Mx{T,LAB,HW}n_*.md` filenames should any ruling later reuse the `assignments/` namespace.

| File | Role | Must contain (skeleton only — no authored lesson content) |
|---|---|---|
| `_overview.md` | Module README / overview | Spine header block: `M{N}`, title, phase, weeks, big idea (verbatim from spine); the LPAA beat map (Learn / Practice / Apply / Assess one-liners); the module's **Make-gradient position** (M2–M4 type-in-100 · M5–M7 finish-80 · M8 spec-only); the user-story line *"As a student finishing M{N-1}, I want …, so that …"* as a fill-in; a pointer stating this is the canonical home and `assignments/` is legacy source. |
| `_mlos.md` | Module Learning Objectives | MLO slots feeding the CLOs, plus this module's CCL-crosswalk touch (from the spine's CCL table). Skeleton bullets, not authored objectives. |
| `_assess-spec.STUB.md` | Assess-beat SPEC STUB | A **"NOT YET AUTHORED — STUB"** banner; acceptance-criteria skeleton written type-signature style (precise, testable, failure cases named); the C/B/A/Badge tier ladder inheriting `_contracts/rubric-template.md` (four columns: Correctness/Completeness/Format/Submission — do not invent columns); the standing invariants for this module (clean compile `g++ -std=c++17 -Wall -Wextra`; single-file form — pre-M6 all-in-`main`, M6+ prototypes/`main`/definitions; four-word error taxonomy; Mermaid flowcharts; Make-gradient position). The `.STUB` in the name signals unfinished. |
| `_assets.md` | Asset-slotting + legacy ledger | Which spine-asset-table / F-001 assets slot here, each tagged `PORT` (adapt existing), `NEW` (author fresh), or `CONTRACT` (build against a frozen `_contracts/` file). Where legacy content already exists on disk under a drifted number, **record it** ("legacy `assignments/m1/*` + `assignments/m2/*` hold this module's content — port + renumber later, owned by M{N}"). Records intent; reconciles nothing. |

No fifth file. Learn/Practice/Apply beat scaffolds are **backlog**, not skeleton — this pass ships the four
the fan-out needs to start: identity, objectives, the Assess contract stub, and the asset map.

---

## 3. Non-clobber policy (strict — module-builders MUST obey)

1. **Create-if-absent only.** A builder creates only the four `_`-prefixed files, only inside its own
   `modules/mN/`. If a target filename already exists (another builder reached it first), **STOP and report** —
   never overwrite, edit, append to, or delete an existing file. Writes are non-destructive by construction.
2. **Never touch anything outside `modules/mN/`.** No builder creates, edits, moves, renames, or deletes any
   file under `assignments/`, `_past_work/`, `_storming/`, `_contracts/`, `_lore/`, or `_tracking/`
   (this plan and the manifest are updated by their owners, not the fan-out).
3. **Legacy content in `assignments/m0`, `m1`, `m2` is recorded, never replaced.** Because the canonical tree
   is `modules/`, the legacy files are untouched by construction. Their existence and true spine-home is
   *recorded* in the relevant `modules/mN/_assets.md` (e.g., `modules/m3/_assets.md` records that
   `assignments/m1/*` and `assignments/m2/*` are its Program-Basics content pending the F-001 rename). The
   legacy `README.md` files stay exactly as-is; the new `_overview.md` is the spine-truth overview and lives
   in the canonical tree, not beside them.
4. **Renames land later, with the owning module — not in this pass.** The skeleton only *records* F-001 intent.

---

## 4. Module identities (per F-001)

| id | Title | Phase | Weeks | Maps to existing / NEW |
|---|---|---|---|---|
| M0 | Welcome to Programming | A | Wk 1 | `assignments/m0/*` (legacy ~matches spine M0) `PORT` + Ch.1 intro |
| M1 | Talk to Computers (and Your Team) | B | Wks 1–2 | **NEW** — Robot Sandwich + explainer decks `PORT` from CTI. *(Not `assignments/m1`, which is spine-M3 content.)* |
| M2 | How to Solve Problems | C | Wks 2–3 | **NEW** — Hello World tour, error taxonomy, flowcharts/pseudocode/user stories; Runestone `thinkcpp` + Communication decks |
| M3 | Program Basics | D | Wks 3–4 | `assignments/m1/*` + `assignments/m2/*` (legacy Program-Basics, F-001) `PORT` + Ch.2 + Pizza Calculator + Debugging-Time |
| M4 | Decisions | D | Wks 5–6 | Ch.4 / "Module 03 — Decision Structures" `PORT` + `_contracts/m4_gatekeeper.cpp` `CONTRACT` |
| M5 | Loops | D | Wks 7–8 | Ch.5 / "Module 04 — Loops" + `M5LAB` + Loops Two-Skin Exemplar `PORT` + `_contracts/m5_menu.cpp` `CONTRACT` |
| M6 | Functions | D | Wks 9–10 | Ch.3 / "Module 02 — Functions" `PORT` — content correct, position moves (authored as "Chapter 3") |
| M7 | Structured Data & Objects | E | Wks 11–13 | `M6LAB2` + `M7LAB1` + Terminal Graphics + "Turtle→Spaghetti" `PORT` (not-yet-imported per F-001) |
| M8 | Capstone Miniproject | F | Wks 14–16 | **NEW** — spec-only, builds on M7 structs/classes |

---

## 5. Open questions (need a human ruling — not resolvable by layout)

1. **The M1/M2/M3 content remap (the big one).** `assignments/m1` + `assignments/m2` legacy content maps to
   spine **M3**, and spine **M1/M2 are new**. This plan parks the legacy files in a frozen `assignments/` and
   builds the spine-true tree fresh — but the eventual **port + renumber** of that content into `modules/m3/`,
   and whether all ten legacy deliverables survive as M3 artifacts or some are trimmed/reassigned (F-001 OQ7),
   needs an owner ruling before M3 is built out.
2. **Ratify the two-tree transition model** (canonical `modules/` + frozen `assignments/`) vs. an alternative
   that renames `assignments/` into spine order *first*. I have made the call (fresh `modules/`) to satisfy
   "no clobber + no drift" without moving files; a human may override the namespace before the fan-out runs.
3. **STL/`std::string` (legacy manifest M06) and File I/O (legacy M07) have no home in the spine** (F-001 OQ2)
   — descoped, or spine addendum? A scope ruling, likely its own ADR; affects M7's `_assets.md`.
4. **`M6LAB2` landing shape** (F-001 OQ1) — standalone ported file under M7, or absorbed as M7LAB1's C-tier?
   Affects `modules/m7/_assess-spec.STUB.md` and `_assets.md`.
5. **`assignments/m0/02_first_pull_request.md` teaches fork/branch/PR to M0 students** (F-001 OQ3) — contradicts
   ADR-004 student-flow (commit+push, no PRs pre-capstone). Rewrite or grandfather? Affects M0's asset ledger.

---

*Skeleton only. No lesson content authored, no ADRs created, no files moved/renamed/deleted. The manifest
(`_tracking/course-manifest-csc134.yaml`) rebuild is downstream of open question 1 and is not done here.*
