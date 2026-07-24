# ADR-005 — Negative quantities at M3 (the Negative Taco Ruling)

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa (ruling), Cowork session (recording)

## Context

M3LAB2 (Taco Receipt) asks for item quantities. M3 students have no `if` (M4) and no input
validation (M5), so the program *cannot* refuse bad input yet. Dee-class question, pre-registered
in the instructor guide: are negative quantities valid input? An unruled hole violates the
"no trick questions / no silent holes" policy the moment a careful reader finds it.

## Decision

Negative quantities are **out of spec, not defended against, and ungraded** at M3:

1. The spec pins "quantities are whole numbers, zero or more."
2. The lab names the hole out loud ("The Negative Taco Problem" section) instead of hiding it —
   students are invited to try `-3` and watch the register offer to pay the customer.
3. The hole is a **planted forward reference**: M4's first `if` closes it; M5 makes it stick.
   The register's canonical refusal, for the record: *the exit code of a request for negative
   three tacos is not zero.* This doubles as the course's first explanation of why `main`
   returns 0 — zero means the request completed fine; refusals traditionally exit nonzero.

## Consequences

- Cohort runs treat negative-input behavior at M3 as not-a-finding (it's spec'd as unspecified).
- The M4 module inherits a ready-made opening exercise: same receipt, add the bouncer.
- Pattern generalizes: **when a module can't defend against something yet, say so in the lab
  and date the promise** — acknowledged holes are seams; silent holes are trick questions.
