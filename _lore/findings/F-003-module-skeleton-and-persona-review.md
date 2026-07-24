---
name: F-003-module-skeleton-and-persona-review
description: Phase 0.6 nine-module skeleton (new modules/ tree) + 0.5 persona review outcome
---

# F-003 — Phase 0.6 skeleton + 0.5 persona review

**Date:** 2026-07-24 · **Status:** Recorded · **Branch:** `phase0/module-skeleton`
**Authors:** spine-owner (layout), module-builder ×9 (scaffold), linx ×9 (clarity), clive-prompt-warden (persona review) — dispatched via workflow + follow-up agents.

## 0.6 — the skeleton (delivered)

All nine modules M0–M8 scaffolded, four files each (`_overview.md`, `_mlos.md`,
`_assess-spec.STUB.md`, `_assets.md`), per the layout spec at `_tracking/skeleton-plan.md`.
See [[ADR-001-alpha-scope-and-locked-decisions]] §0.6.

**Structural decision made by spine-owner (needs human ratification — open Q):** canonical
scaffolds land in a **NEW `modules/m0…m8/` tree**; legacy `assignments/` is **frozen** and never
a scaffold target, so legacy files cannot be clobbered by construction. Chosen to satisfy
no-clobber + no-drift without moving files. The alternative — renumber `assignments/` into spine
order first — was rejected for this pass but a human may override the namespace before deep builds
populate `modules/`.

**linx finding (applies to the whole skeleton):** these four files are *instructor-facing build
docs*, not student prose — so linx did a clarity pass (splitting run-on sentences), not the full
10th-grade + dungeon-voice treatment. That treatment lands at **deep-build**, when
`reading-generator`/`lab-creator` author the real Learn/Practice/Apply/Assess content.

**Execution note:** the fan-out hit 3 transient API errors (scaffold m4/m5/m7, "connection closed
mid-response"). m5/m7 had already written all files; m4 was missing `_assets.md`. Recovered with
targeted module-builder + linx follow-ups. No data loss.

## 0.5 — persona review (needs human approval)

clive-prompt-warden reviewed the three sheets in `_storming/personas-134/`:

- **Maria (Chromebook Literalist)** — **ready.** The contamination-hygiene exemplar (explicit
  transcript-bounded knowledge clause). Optional: add a one-line INFRARED PRISM anchor.
- **Jaylen (Skimmer)** — **ready.** Knowledge properly bounded; complements Dee (skim vs.
  adversarial-read). Optional: add a one-line RED PRISM anchor.
- **Dee (Rules-Lawyer)** — **needs-changes.** Two real fixes before use:
  1. **Contamination (cardinal crime):** her prompt body names co-persona "Maria"
     (`(where Maria is literal about procedures)`) — a fresh-spawn student must carry zero
     cohort-scaffolding awareness. Strip the co-persona reference.
  2. **Missing knowledge-boundary clause:** unlike Maria/Jaylen, Dee's "average coding skill" is
     unbounded, so she could solve around a genuine material gap with outside knowledge — masking
     the very findings the INFRARED→RED band exists to surface. Add a course+transcript knowledge bound.

No cohort runs until the human approves the sheets (ADR-001 §0.5). Dee is blocked pending fix.

## Open questions carried from spine-owner (need rulings)

1. **THE BIG ONE — M1/M2/M3 remap.** `assignments/m1` + `m2` legacy content maps to spine **M3**;
   spine M1/M2 are new. The eventual port+renumber into `modules/m3/`, and whether all ten legacy
   deliverables survive as M3 artifacts (F-001 OQ7), needs an owner ruling before M3 deep-build.
2. **Ratify the two-tree transition model** (canonical `modules/` + frozen `assignments/`) vs.
   renaming `assignments/` into spine order first.
3. **STL/std::string + File I/O** (legacy manifest M06/M07) have no spine home (F-001 OQ2) —
   descope or spine addendum? Likely its own ADR; affects `modules/m7/_assets.md`.
4. **M6LAB2 landing shape** (F-001 OQ1) — standalone M7 file or absorbed into M7LAB1's C-tier?
5. **`assignments/m0/02_first_pull_request.md`** teaches fork/branch/PR to M0 students — contradicts
   [[ADR-004-two-tier-git-workflow]] student-flow. Rewrite or grandfather?

See [[F-001-numbering-reconciliation]] and [[F-002-interface-contracts]] for lineage.
