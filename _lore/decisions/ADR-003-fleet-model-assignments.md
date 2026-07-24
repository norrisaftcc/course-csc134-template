# ADR-003 — Fleet model assignments

**Date:** 2026-07-23 · **Status:** Accepted · **Deciders:** norrisa (human) + Cowork session
**Relates to:** `ULTRACODE_ALPHA_PLAN.md` §3 (org chart) and §4 (model economics)

## Context

The plan §3 listed models but left the mid-tier roles as `inherit`. Pinning them concretely,
under the §4 principle — mechanical work runs cheap, building runs at the workhorse tier,
senior review runs opus — keeps cost proportional to reasoning demand across the alpha.

Guiding rule (human): the highest few PRISM tiers run opus; sonnet 5 carries the workhorse
load; haiku is justified where work is genuinely mechanical (tool-driven, rule-matching).

## Decision

| Agent | PRISM | Model | Rationale |
|---|---|---|---|
| spine-owner | YELLOW | **opus** | architecture + interface contracts |
| program-advisor | YELLOW | **opus** | dean/committee-facing rationale |
| clive-prompt-warden | YELLOW | **opus** | prompt forensics across the graduate-and-teach loop |
| cadence-master | BLUE | **sonnet** | process judgment, PR gates, scope guard |
| module-builder | ORANGE | **sonnet** | authoring workhorse — **but M4/M5 exemplar builds override to opus at workflow-call time** (calibration pair humans review) |
| liza-theme-skinner | ORANGE | **sonnet** | creative flavor / CYOA / two-skin variants |
| linx-voice-readability | — | **sonnet** | voice preservation needs nuance |
| cohort-lead | — | **sonnet** | harvest judgment — **but the student spawns it runs are haiku** (per §4: an over-smart student defeats the persona) |
| kevin-repo-warden | INFRARED→RED | **haiku** | numbering / PR / commit rule-matching is mechanical |
| compile-warden | RED | **haiku** | extract-compile-diff runs the toolchain; it verifies, it does not opine |

## Consequences

- Two downgrades from the plan's draft (kevin, compile-warden: sonnet → haiku); three `inherit`
  roles pinned to sonnet; opus tier unchanged (the three YELLOWs).
- **module-builder** carries a sonnet file default; the workflow that runs the M4 and M5 deep
  builds passes `model: 'opus'` on those `agent()` calls. Scaffold builds keep sonnet.
- **cohort student spawns** are haiku regardless of cohort-lead's own model, set at spawn time.
- Model overrides are a workflow-call concern; changing a file default requires editing the
  agent frontmatter (and, for a locked role, a superseding ADR).
