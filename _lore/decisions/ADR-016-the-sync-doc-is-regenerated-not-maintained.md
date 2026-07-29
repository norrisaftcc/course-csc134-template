# ADR-016 — The team sync doc is regenerated, never maintained

**Date:** 2026-07-29 · **Status:** Proposed (awaiting norrisa) · **Deciders:** norrisa (ruling pending) + Cowork session
**Relates to:** [[ADR-000-the-repo-is-the-wiki]], [[ADR-002-phase0-rulings]],
[[ADR-004-two-tier-git-workflow]], [[ADR-014-compile-gate-runs-on-gcc-in-ci]]
**Introduces:** `_storming/VERIFIER_BRIEF.md`
**Supersedes on adoption:** `_storming/CODE_TEAM_SYNC_01.md` (kept as history)

## Context

`CODE_TEAM_SYNC_01.md` was hand-written on 2026-07-24 to catch the code team up after a pivot.
Four days later it was wrong in three independent ways: the ADR numbers it cites were reassigned
(its 002/003/004 are now 005/006/007), it lists three Phase 0.1 rulings as open that ADR-002 had
already closed, and it predates the compile gate, the markdown gate, and ADR-008 through ADR-015.

Nobody was careless. A hand-written brief decays at exactly the rate the fleet works, and this
fleet works fast. The failure is structural: a document that must be *remembered* into currency
will not stay current, and a stale brief is worse than none because it is read with confidence.

## Decision

**No clerk-facing status document is maintained by hand. It is regenerated from repo reality by
a read-only verification instance, in full, every run.**

1. `_storming/VERIFIER_BRIEF.md` is the standing charter for that instance. It instantiates
   compile-warden and Kevin under one identity with **report-only** authority: it may read,
   build, grep, and query; it writes exactly two files; it never edits course material, never
   commits a fix, and never rules on an open question.
2. Its output contract is those two files: a findings file in `_lore/findings/` (next free
   F-number, ledger format, recording the HEAD it ran against) and a full regeneration of
   `_storming/CODE_TEAM_SYNC.md`. Anything in the sync doc that cannot be derived from the repo
   this run gets cut rather than carried.
3. CI is the authority on compiler behaviour (ADR-014). The verifier reads gate results; it does
   not re-run the compiler as primary evidence and never asserts compiler *silence* from a local
   macOS run.
4. The verifier runs **build flow** (ADR-004): its two files land by branch + PR to `main`,
   under the same human review as any deliverable.

## Consequences

- The sync doc gains a provenance guarantee and loses its edit history as a document; the history
  that matters lives in `_lore/` and in git.
- `CODE_TEAM_SYNC_01.md` stays in the tree, banner-marked superseded, because deleting the
  record of how we learned this would repeat the lesson.
- A run that finds nothing must say what it looked hardest at. Zero findings is a signal to
  check the verifier, not a clean bill of health.
- Cost: one PR of review per run. Cheap against a fleet building four days on a wrong picture.

## Alternatives considered

- **Keep hand-maintaining the brief, more diligently.** Rejected: this failure mode is not
  fixable with diligence, and the first four days are the evidence.
- **Let the verifier fix what it finds.** Rejected: a verifier that edits stops being a witness,
  and its findings become unfalsifiable — it grades its own repairs.
- **Put status in the GitHub issue tracker instead.** Rejected under ADR-000: the repo is the
  wiki, and a status picture that lives outside the tree cannot be reviewed by the same gate.
