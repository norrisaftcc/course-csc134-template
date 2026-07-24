# F-001 — Phase 0.2 numbering reconciliation

**Date:** 2026-07-23 · **Status:** Recorded · **Branch:** `phase0/numbering-reconciliation`
**Author:** kevin-repo-warden (analysis) + Cowork session (fix + record)
**Artifact:** `_tracking/numbering-reconciliation-map.md` (the rename plan — 11 rows + manifest delta + open questions)

## What

Phase 0.2 deliverable: Kevin audited module-number drift against the spine's canonical M0–M8
and produced the rename-map (a *plan*, not mass renames — renames land later with the module
that owns them). See [[ADR-001-alpha-scope-and-locked-decisions]] §0.2.

## Fixed in this deliverable

- **Skill-template placeholder corruption (root cause).** All ten guild templates
  (`reading-generator`, `lab-creator`, `rubric-converter`, `exit-ticket-generator`,
  `apply-tutorial-generator`, in both `.claude/skills/` and `_storming/skills-134/`) carried
  frontmatter `module: M0X` where every sibling placeholder uses the bare `MX` form. This is
  upstream of all future numbering drift — every module the fleet builds runs through these
  templates — and had already leaked into an M3 exemplar. Corrected all ten to `module: MX`.

## Verified clean (no action)

- `M5LAB` (loops) is correctly M5 — resolves the self-contradiction where `RETHEME_NOTES.md`
  listed it alongside genuine offenders.
- `M7LAB1` (structs, tiered) is correctly M7. Neither it nor `M6LAB2` is a physical file yet
  (planning-prose references only).

## Open — needs human ruling or its own deliverable (full list in the map)

1. **`M6LAB2` landing shape** — standalone M7 file, or absorbed into `M7LAB1`'s C-tier?
2. **Manifest is a structural rebuild, not a rename.** `course-manifest-csc134.yaml` predates the
   spine reorg (8 chapter-order modules vs. the spine's 9; M1/M2 have no entry; manifest STL /
   File-I/O have no spine home). Needs rulings before applying.
3. **ADR-004 violation in existing content:** `assignments/m0/02_first_pull_request.md` teaches
   full fork→branch→PR to Module-0 students — contradicts the student-flow rule in
   [[ADR-004-two-tier-git-workflow]]. Critical; needs a content rewrite.
4. **Stale spine fork:** `csc134-refresh-plan/CSC-134-course-spine.md` is a drifted duplicate of
   the canonical spine (still shows pre-[[ADR-002-phase0-rulings]] "Precision"). Delete or reconcile?
5. Functions-chapter asset's true location; generic manifest template's `M01`-padded default;
   where the ten existing M1/M2 deliverables land in a rebuilt M3.

## Note

A concurrent session is adding untracked `_lore/decisions/ADR-003-mail-run-and-import-direction.md`,
which would collide with the merged `ADR-003-fleet-model-assignments`. Left untouched here; flagged
to humans (same class of drift as the taco ADR, now [[ADR-005-negative-tacos]]).
