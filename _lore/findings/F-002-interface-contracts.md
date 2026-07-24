---
name: F-002-interface-contracts
description: Phase 0.3 interface contracts landed — canonical M4/M5 programs, rubric template, builder CLAUDE.md
---

# F-002 — Phase 0.3 interface contracts

**Date:** 2026-07-23 · **Status:** Recorded · **Branch:** `phase0/interface-contracts`
**Author:** spine-owner (authored) + Cowork session (verify + record)

## What

Phase 0.3 deliverable — the frozen interface contracts the deep M4/M5 builds refactor against.
See [[ADR-001-alpha-scope-and-locked-decisions]] §0.3.

- `_contracts/m4_gatekeeper.cpp` — canonical M4 decision program (dungeon CYOA gatekeeper).
  `if/else`/`switch`, no loops, single-file `main`-only (pre-M6 convention).
- `_contracts/m5_menu.cpp` — canonical M5 menu program that **literally extends** the M4
  gatekeeper: same decision core, now menu action #1 inside a `do/while` loop with `cin`
  fail-state validation. The M4→M5 seam is diff-legible, not just thematic — the tier shift
  shows as M4's `return 0` becoming M5's `continue`.
- `_contracts/rubric-template.md` — the template every module rubric inherits: four columns
  **Correctness / Completeness / Format / Submission** (8/6/3/3, Correctness locked per
  [[ADR-002-phase0-rulings]]) × C/B/A/Badge tiers. Tiers = what you attempt; columns = how it's
  scored. Clean-compile bar lives in Format.
- `_contracts/README.md` — contracts are frozen; changes need spine-owner sign-off + an ADR.
- `CLAUDE.md` (repo root, new — 1,127 words) — builder conventions pack: the nine mechanical
  bars, voice pointers, file layout, [[ADR-004-two-tier-git-workflow]], the `_lore/` gate, and a
  skill-guild routing table. Flags `_past_work/CLAUDE.md`'s feature-branch student flow as legacy.

## Verification

Both programs compile **zero-warning** under `g++ -std=c++17 -Wall -Wextra` (independently
re-run by the orchestrator, exit 0). Runtime smoke tests pass (rogue-shortcut, warrior-open,
menu cin-reject/leave).

## Open questions (non-blocking)

1. Rubric point re-weighting authority — 8/6/3/3 default; per-lab re-weight needs spine-owner
   sign-off. No alpha module needs it yet.
2. Turtle Learn beat in M5 — required or optional in a compiled course? Affects M5 Apply build,
   not these contracts.

## Note

Concurrent-session ADR collisions (`ADR-003-mail-run`, `ADR-004-postmark-rule`) still uncommitted
WIP at pause time — to be renumbered to 006+ once that session commits. See [[F-001-numbering-reconciliation]].
