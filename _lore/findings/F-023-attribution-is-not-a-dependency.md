---
name: F-023-attribution-is-not-a-dependency
description: The ask was to credit a source. The route nearly taken was to attach the repo, vendor its files, and schedule a reconciliation — a permanent relationship in place of a one-time statement. The floor test would have caught it at Scope.
---

# F-023 — Attribution is a statement; a dependency is a relationship

**Date:** 2026-08-06 · **Status:** Recorded · **Episode:** vendoring `the-algorithm-lite`
**Companion to:** [[ADR-019-the-algorithm-lite-provisional-house-style]] (see its Amendment)

## What happened

The ask was: *we can fork it with acknowledgement of the original repo.*

The route proposed was: attach `algocratic/the-algorithm-lite` to the session, vendor its files,
record the upstream commit SHA, and schedule a reconciliation diff — with an expiry clause whose
first trigger was *"the repo is attached."*

The human ruling cut it back in one sentence: **"as long as the attribution was captured
properly we are good — and it was."**

## The shape

These are not the same size, and the difference does not show up at the moment you choose.

| | Attribution | Dependency |
|---|---|---|
| What it is | a **statement** | a **relationship** |
| Where it lives | text, in-tree | across a boundary you do not control |
| Cost after landing | none | drift, re-checks, a diff someone owes |
| Fails by | being wrong — visible, fixable | going stale quietly |
| Finished when | written | never |

A `NOTICE` file discharges the obligation completely and permanently. An attachment discharges
nothing; it opens an account. **The second is strictly more expensive, and the extra cost is
all deferred**, which is exactly why it does not feel expensive when proposed.

## Which noun catches it

**Scope.** The boundary in the ask was *credit the source*, not *track the source*. One is a
sentence; the other is a subscription.

The failure is worth naming precisely because of what it is **not**:

> **The ask was not vague.** *"Fork it with acknowledgement"* clears the floor. This was a
> plausible **over-reading** of a clear ask — the proposed work was a superset of the work
> requested, and every extra piece was individually defensible.

That is a harder case than the usual one. The floor test is built to catch asks that are
*under*-specified and come back longer. Here the ask was adequately specified and the response
came back **larger than the ask**, which no amount of asking the customer more questions would
have fixed. The customer had already said what they wanted.

Compare [[F-022-split-picture-rail-calibration]], where twelve interview questions bought one
requirement: more elicitation is not the universal remedy. **Some errors are on the answering
side, not the asking side.**

## The check

Before proposing work that creates an ongoing obligation, name the obligation and ask whether
the request implied it:

1. **What does the ask oblige us to do once?** Do that.
2. **What would oblige us to do something repeatedly?** That is a separate ask. It needs its own
   yes.
3. If step 2 is larger than step 1, **say so out loud before building either** — the requester
   is the only one who can price a maintenance cost against their own plans.

Nothing here argues against dependencies. It argues that a dependency is a *decision*, and a
decision taken as a side effect of a smaller request was never actually decided.

## What it cost, and what it bought

Cost: near-zero. The over-reading was caught at the proposal stage by the person who made the
original request, which is the cheapest possible place.

Bought: the outcome was **better than the plan it replaced** — with upstream unreadable, the
alternative to attachment was compressing the form already on disk, and that produced a
*measured* 40.5% reduction where the vendoring route would only have repeated an unverified
claim. The constraint improved the artifact.

That is the second finding hiding in the first: **the cheap path was also the honest one.**
Not always true. Worth noticing when it is.
