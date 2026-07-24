# ADR-011 — Descope STL/`std::string`-as-a-topic and File I/O from the alpha

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Cowork session
**Relates to:** [[F-001-numbering-reconciliation]] (OQ2), [[ADR-009-teach-using-namespace-std]],
[[ADR-010-m3-remap-recreate-with-salvage]] · **Addendum:** `_tracking/spine-addendum-deferred-scope.md`

## Context

The legacy manifest had a focused STL/`std::string` unit (old M06) and a File I/O unit (old M07).
The spine reorg carried neither. Key facts: **neither is CCL-required** (no accreditation risk),
and **incidental `std::string` is already woven into M3/M5** (students write `string name;` etc. —
and per ADR-009's `using namespace std;`, with no `std::` prefix to explain). What is actually
homeless is the *dedicated* STL/string-manipulation topic (`.substr`/`.find`/`<vector>`) and File I/O.

## Decision

**Both are descoped from the alpha, and the descope is recorded — not silent.**

1. No dedicated STL/string-manipulation unit and no File I/O unit in M0–M8 for the alpha.
2. Incidental `std::string` keeps its existing woven-in role (M3/M5); it needs **no dedicated slot**.
3. The deferral is logged in `_tracking/spine-addendum-deferred-scope.md` as *deferred, not
   CCL-required, known-future* — honoring the announce-never-mutate-silently rule.

## Pocketed option (deliberately preserved, not discarded)

If a future run surfaces **genuine student confusion** attributable to these gaps, the **fold-in**
approach is the ready answer — pull it out of the pocket rather than re-deriving it:
- `std::string` manipulation → a focused slice in **M3**;
- File I/O → an **M8 Badge**-tier extension.
Judged unlikely (hence descoped now), but kept on the shelf for a possible next-year deployment.
This preserves the idea at ~zero cost instead of throwing it away.

## Consequences

- No module gains an unplanned STL unit; no rubric grades untaught File I/O.
- The addendum ledger is the honest paper trail for program review ("what did the refresh defer, and why").
- Reversing the descope (deploying the pocketed fold-in) is a lightweight call recorded against this
  ADR — no superseding ADR needed to *deploy the already-documented option*; a new topic beyond it would need one.
