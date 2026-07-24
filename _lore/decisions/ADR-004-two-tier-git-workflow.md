# ADR-004 — Two-tier git workflow: student flow vs. build flow

**Date:** 2026-07-23 · **Status:** Accepted · **Deciders:** norrisa (human) + Cowork session
**Relates to:** `ULTRACODE_ALPHA_PLAN.md` §4.2 (PR-per-deliverable) and §8 (worktree isolation)

## Context

The plan makes PR-per-deliverable law for the fleet. Separately, the course does **not** teach
branching in the early modules — in-person consensus (and the spine's M1 Apply beat: repo →
README → commit → push, no branch) treats branch/PR use as a capstone-tier skill. Left
unstated, these could collide: Kevin might "enforce" branch/PR conventions on a cohort agent
that is only supposed to be modelling a fresh student.

## Decision

Two distinct git workflows, matched to the actor's tier — and the distinction is itself the
alignment, not a compromise:

- **Student flow** (fresh-spawn cohort agents taking early modules; the materials those modules
  teach): **commit + push directly, no branches, no PRs.** Mirrors the real early-module student
  experience and fuzzes the actual student path. Worktree isolation (§8) is plumbing to keep
  parallel students from colliding — it is *not* a branching lesson and must not be taught as one.
- **Build flow** (the build fleet producing deliverables — module-builder, spine-owner, Kevin,
  et al.): **branch + PR-per-deliverable**, conventional commits, human review at every PR, the
  `_lore/` merge gate. Capstone-grade work earns capstone-grade workflow.

The graduate-and-teach pipeline encodes the progression: a fresh student commits to main; the
promoted graduate becomes a builder who branches and PRs. The agent climbs the same workflow arc
a real student climbs by capstone — the promotion *is* the step-up.

## Consequences

- Kevin enforces branch/PR conventions on **build-flow** deliverables only. He does **not** flag a
  student-flow cohort run for "not branching" — that would be enforcing a capstone skill on an
  INFRARED actor.
- Early student-facing materials (M0–M5) teach commit/push, not branching. Branching enters as a
  capstone-tier topic (M8 territory, out of alpha depth scope).
- This is a workflow-tier rule, not a per-repo toggle: the same repo hosts both flows, keyed to
  who is acting. See [[ADR-001-alpha-scope-and-locked-decisions]] (contamination + fresh-spawn rules).
