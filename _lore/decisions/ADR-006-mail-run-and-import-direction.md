# ADR-006 — The Mail Run, and the direction of imports

**Date:** 2026-07-24 · **Status:** Accepted (import direction, metaphor); name "Mail Run" proposed-default pending owner veto · **Deciders:** norrisa (rulings), Cowork session (name proposal, recording)

## Context

CSC-249 was authored *after* CSC-134's last run and its conventions differ (prompts.txt vs
prompts.md, points vs tiers, "exit ticket" as reflection vs checkpoint, Sacred Flow vs 134's
simpler loop). Owner ruling: 249 came after, so imports conform to how 134 does it *now*.
Separately, 134's submission loop (pull → commit → push) has been taught with a metaphor —
boxing up a package to return it, then putting it in the mail — but never had a name.
Owner floated "The Tide"; session counter-proposed.

## Decisions

1. **Import direction:** csc_dash material brought into 134 conforms to current 134
   conventions — file names (`prompts.md`), rubric model (C/B/A/Badge), vocabulary,
   register. 134 does not bend to imported conventions.
2. **The submission loop is named "the Mail Run."** The package metaphor is canon:
   *pull* = check your mailbox before you send (something may have arrived that changes
   what you're mailing); *commit* = box it up **and write the label** (the commit message
   is the shipping label); *push* = hand it to the carrier, then check the tracking
   (verify on github.com). "The Tide" was considered: it captures the in/out rhythm but
   loses the label beat, doesn't verb, and has a college-football collision.
3. **Consequences of (1), pre-ruled:** imported reflection instruments are not called
   "exit tickets" in 134 (that name stays on the comprehension checkpoint per the spine);
   Sacred Flow material imported into 134 is renamed/reduced to Mail Run scope for M1,
   with the fuller Issue→Branch→PR workflow deferred to where the fleet's own conventions
   introduce it.

## Consequences

- The Mail Run gets a student-facing card in M1 (`_storming/exemplars/m1-mail-run/`),
  built on 113's Commit_Message_Guide formula (adapted, per decision 1).
- Kevin's vocabulary: "did you run the mail?" is now an official nag.
- Program-level note: the 134→249 seam ("Mail Run grows up into the full workflow")
  should be stated in 249's Week 1 whenever that course is next touched.
