# ADR-001 — Alpha scope and locked decisions

**Date:** 2026-07-23 · **Status:** Accepted · **Deciders:** norrisa + Cowork session

## Context

The spine (`_storming/CSC-134-course-spine.md`) is build-ready. Before handing off to a
Claude Code ultracode session, the alpha's shape and the fleet's operating rules needed pinning.

## Decisions (locked)

1. **Alpha = skeleton + exemplar pair.** All nine modules scaffolded; M4 and M5 built to
   full LPAA depth, with the M4→M5 seam demonstrated. (Rejected: full horizontal build at
   C-tier polish — review checkpoint before bulk spend won.)
2. **Graduate-and-teach pipeline.** An agent takes module N as a student, then builds
   module N+1. Dependency chain becomes the mechanism. Students are always fresh spawns;
   graduates are contaminated as testers.
3. **Synthetic cohort as QA.** Persona-driven student agents (Maria/Jaylen/Dee minimum)
   take each module for real, with the actual toolchain, loop-until-dry (cap: 4 rounds).
   Failure transcripts are harvested into instructor-guide common-mistakes entries and
   exit-ticket distractor banks.
4. **Dungeon is canon; skins are separable.** Instructor-facing material is dungeon-themed;
   per-student re-skinning is permitted and used as a skin/structure fuzzer.
5. **Fleet org is PRISM-tiered.** Roles and tiers per `_storming/agents-134/` and the plan §3.
6. **`_lore/` convention adopted** (see ADR-000).

## Open (assigned to Phase 0.1, humans)

- Rubric column one: Precision vs. Correctness (spine self-disagreement).
- Cadence-master's BLUE tier confirmation.
- PR target: `alpha` integration branch vs. `main` (proposed: `alpha`).

## Consequences

The ultracode plan (`_storming/ULTRACODE_ALPHA_PLAN.md`) encodes these; changes to any
locked item require a superseding ADR, not a quiet edit.
