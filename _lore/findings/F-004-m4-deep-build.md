---
name: F-004-m4-deep-build
description: Phase 1 M4 (Decisions) deep build — four LPAA beats against the frozen gatekeeper contract, compile-gated green
---

# F-004 — Phase 1 M4 (Decisions) deep build

**Date:** 2026-07-24 · **Status:** Recorded · **Branch:** `module/m4-deep`
**Authors:** module-builder ×4 (one per LPAA beat, opus/exemplar tier), compile-warden (gate, haiku),
linx (voice unification, sonnet) — dispatched via the `m4-deep-build` workflow. Orchestrator made
one post-gate taxonomy correction (below).

## What was built

The first deep module. All four LPAA beats authored against the frozen
[[ADR-008-two-tree-module-layout]] `modules/m4/` tree, anchored on the frozen
`_contracts/m4_gatekeeper.cpp` (the contract is the coherence anchor that let the four beats be
authored in parallel without drift).

| Beat | File(s) | Skill | Shape |
|---|---|---|---|
| **Learn** | `learn.md` + `code/learn-gate-{strength,class,full}.cpp` | reading-generator | Gatekeeper as running worked example, built in 3 stages; 3 predict-the-output blocks (PRIMM Predict), 2 Mermaid flowcharts (one forward, one code→flowchart for MLO 4.3). |
| **Practice** | `practice-exit-ticket.md` + `-key.md` + 5 `.cpp` | exit-ticket-generator | 7-item comprehension check: trace-the-branch, predict, classify-the-error, code→flowchart **recognition** (Item 7). Instructor key with seed misconception bank. |
| **Apply** | `apply-tutorial.md` + `code/apply-gatekeeper.cpp` | apply-tutorial-generator | Type-in-100% instructor-led build of the gatekeeper in 4 cumulative stages; delivered program logic byte-identical to the contract. |
| **Assess** | `assess-lab.md` + `code/assess-reference.cpp` | lab-creator + rubric-converter | CYOA decision lab from spec; from-scratch (no starter file); four-column rubric filled (8/6/3/3), C/B/A/Badge nesting; A-tier reference is a river-ferryman **re-skin** of the gatekeeper (proves theme strips clean). |

## Gate result — PASS (0 fix rounds)

Compile Warden verified: **all 10 `.cpp` under `modules/m4/code/` compile clean** (zero warnings,
`g++ -std=c++17 -Wall -Wextra`); **all 6 complete programs extracted from the markdown** compile
clean; all Mermaid blocks parse; the Assess rubric carries the correct four columns / 8-6-3-3
weights / no placeholders. See [[ADR-002-phase0-rulings]] (Correctness column) and
[[ADR-009-teach-using-namespace-std]] (`using namespace std;` used throughout on purpose).

## Deep-build decisions (converged across the four beats — for ratification)

1. **Gatekeeper = taught/worked skin, freely re-skinnable** (not a required skin). All four beats
   agree. Learn/Practice/Apply teach the gatekeeper; Assess spec is theme-neutral (bouncer / gate
   agent / loan officer offered; theme does not score). Honors CLAUDE.md "skin ≠ structure".
2. **Compound `&&/||/!` tier boundary:** plain `if`/`else if`/`switch` is the **C-tier baseline**;
   the first compound condition is the **B-tier reach**. `&&` is *taught* in Learn (Stage C) and
   Apply (Stage 4), then *graded* as a B-tier reach in Assess — taught before tested (no trick
   questions). Only `&&` is exercised (matches the contract); `||`/`!` are named in Learn.
3. **MLO 4.3 reverse direction (code→flowchart)** appears twice, cleanly split: **recognition** in
   Practice (Item 7, match code to flowchart) and **graded production** at Assess **Badge** (recover
   a flowchart from a fresh snippet). C-tier keeps the forward direction (flowchart→code). Satisfies
   the spine's "at least once, the reverse."
4. **The three classic traps (`=` vs `==`, dangling `else`, `switch` fall-through)** are named and
   taught up front in every beat (fair warning, no gotchas). Fall-through is the marquee deliberate
   break — verified to emit **no warning** under `-Wall -Wextra`, which is the strongest reason to
   name it rather than spring it. All classified as **Logic** errors.

## Orchestrator correction (post-gate, flagged for veto)

Linx surfaced a content inconsistency the mechanical gate can't catch: `assess-lab.md` classified
`=` vs `==` as **Static semantic** in two spots while the other three beats (and the taxonomy's own
definition) classify it as **Logic** — it compiles with only a `-Wall` warning and runs wrong.
Corrected the two spots in `assess-lab.md` to **Logic** for taxonomy consistency. This is a defect
fix against the course's four-word taxonomy, not a design change.

## Open items (carried forward, not blocking)

- **Mermaid render spot-check.** Diagrams validated by syntax parse (and one `mmdc`/SVG render in
  the Apply author's env), but a GitHub-preview render check before student hand-off is recommended —
  flagged by three of the four authors. Belongs to the pre-publication gate, not this PR.
- **Cohort dry-run** (cohort-lead) is the deliberate next step — held separate so the module is
  human-reviewed before synthetic students take it. Personas are approved (F-003) so it is unblocked.
- **`_assets.md` reconciliation:** the Learn author mined the legacy GameFAQs guide as primary voice
  and did not merge the Canvas-formal variant. A spine-owner note confirming "one Learn reading"
  closes the `modules/m4/_assets.md` pending-reconciliation item.

Relates to [[F-003-module-skeleton-and-persona-review]], [[F-002-interface-contracts]],
[[ADR-004-two-tier-git-workflow]] (built on branch `module/m4-deep`, PR-gated).
