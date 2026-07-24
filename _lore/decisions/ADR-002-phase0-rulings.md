# ADR-002 — Phase 0.1 rulings resolved

**Date:** 2026-07-23 · **Status:** Accepted · **Deciders:** norrisa (human) + Cowork session
**Supersedes the "Open" section of** [[ADR-001-alpha-scope-and-locked-decisions]]

## Context

ADR-001 §0.1 left four items open, assigned to humans before Phase 0 exit. They were put
to the human in session, each relayed by the agent whose domain it is. This ADR records the
rulings so they become canon (changes hereafter require a superseding ADR, not a quiet edit).

## Decisions (locked)

1. **Rubric column one is `Correctness`.** The spine self-disagreed — M1's Robot Sandwich
   lineage said *Precision*; the assessment section and build brief said *Correctness*. Ruling:
   **Correctness**. Rationale: matches the assessment section, the build brief, and the v3
   fleet prompts already in place — zero rework, and "did it produce the right result" is the
   clearer bar for CSC-134. Spine patched at `CSC-134-course-spine.md:128` (Precision →
   Correctness) in the same change as this ADR; the rubric template instantiates the four
   columns as **Correctness / Completeness / Format / Submission**.
2. **cadence-master tier is `BLUE`.** The inferred tier is confirmed: promotion-cycle cadence,
   PR gates, and scope-guard authority. The plan §3 chart stands as drawn.
3. **spine-owner / program-advisor boundary adopted as proposed.** The owner decides inward
   (build and architecture calls); the advisor argues outward (dean/committee-facing rationale)
   and may file written dissent. M8 conflicts are deferred — M8 depth is out of alpha scope.
4. **PR target is `main` directly.** Deliverable PRs merge to `main` as they pass human review;
   no `alpha` integration branch. (Chosen over the plan's proposed alpha-branch staging — the
   two-human review-at-every-PR gate already protects main, and the extra branch is overhead the
   alpha doesn't need.) The `phase0/install-fleet-and-guild` branch therefore targets `main`.

## Consequences

- The rubric template (contract 0.3) and every descendant rubric use **Correctness** as column one.
- No `alpha` branch exists; Kevin's PR conventions apply against `main` as the integration target.
- ADR-001's Open list is now closed; the locked-decisions list in ADR-001 is unaffected.
