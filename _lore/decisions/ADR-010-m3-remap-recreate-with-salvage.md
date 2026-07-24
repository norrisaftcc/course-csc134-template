# ADR-010 — M3 remap: recreate-with-salvage (and the port precedent)

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Cowork session
**Relates to:** [[ADR-008-two-tree-module-layout]], [[F-001-numbering-reconciliation]],
[[F-003-module-skeleton-and-persona-review]] (OQ1), [[ADR-002-phase0-rulings]] (rubric columns)

## Context

Legacy `assignments/m1` + `assignments/m2` hold Program-Basics content that maps to the spine's
**M3** (spine M1/M2 are new modules). ADR-008 deferred *what* ports into `modules/mN/` to a
per-module owning ruling; this is that ruling for M3, and it sets the precedent for later modules.

An inventory of the ten legacy files (8 deliverables + 2 READMEs) showed the course was built by
**accretion**: content is front-loaded and redundant. Most starkly, **five** near-duplicate
"variables + arithmetic + formatted output" calculators exist (Coffee POS, Restaurant, Crates,
Budget Analyzer, plus the spine's Pizza Calculator); environment/git setup is duplicated inside an
M1 tutorial when it is the whole of M0; and two homeworks overshoot into decisions and rubric-tiering.

## Decision

**M3 is recreated to the spine, mining the legacy material as fodder — not ported wholesale.**
Where legacy structure misfits (Bronze/Silver/Gold rubric vs. ADR-002's C/B/A/Badge; eight full
labs vs. M3's one-Apply-one-Assess LPAA; wrong Make-gradient position), we re-author rather than
revise-in-place. The disposition:

| Legacy file | Disposition |
|---|---|
| M1T1 First Day | **Split** — env/git already lives in M0 (redundant, retire); hello-`cout` core → M3 **Learn** |
| M1T2 Digital Business Card | **Salvage → M3 Apply**, stage 1 (output-only type-in) |
| M2T1 Farmer's Market | **Salvage → M3 Apply**, stage 2 (add `cin` input) |
| M1LAB Coffee POS · M2T2 Restaurant · M2LAB1 Crates | **Reskin fodder** for the *one* M3 Assess (spine's Pizza Calculator), not four labs |
| M1HW1 Budget Analyzer | Conditional-advice logic **overshoots → mine for M4 (Decisions)**; backlog |
| M2HW1 Multi-Program | Bronze/Silver/Gold rubric **retired** (conflicts ADR-002); tier concept folds into C/B/A/Badge; sub-programs mined as isolated practice; backlog |

**M3 target shape:** lean **Learn** + **two-stage Apply** (output → input) + **one Assess**
(arithmetic lab with reskin variants).

## The precedent (applies to every later module port)

1. **Recreate-to-spine + salvage** is the default, not wholesale port. Legacy is a quarry.
2. **Isolate front-loaded redundancy and teach each piece at its right moment** (git → M0;
   decisions → M4; tiering → the rubric) rather than carrying the pile-up forward.
3. **One skill, taught once.** Duplicate exemplars collapse into a single canonical artifact plus
   reskins.
4. Anything cut-but-not-dead goes to a **ranked backlog** (shelved, not retired), announced —
   never a silent drop.

## Consequences

- M3 deep-build authors fresh into `modules/m3/`; `assignments/m1,m2` stay frozen provenance.
- The Bronze/Silver/Gold rubric is gone from live materials.
- M4 and M0 inherit named fodder (conditional-advice scenarios; nothing new for git — M0 already has it).
- Backlog items (M1HW1, M2HW1, spare calculators) need a home — a `_tracking/` backlog ledger,
  authored when M3 is built.
- Supersedes the wholesale-port option; changing the precedent requires a new ADR.
