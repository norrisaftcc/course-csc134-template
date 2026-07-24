# ADR-008 — Two-tree module layout: canonical `modules/`, frozen `assignments/`

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa (ratification) + Cowork session
**Relates to:** `CLAUDE.md` file-layout ("module deliverables land in per-module folders as the
skeleton pass defines them" — this ADR is that definition), [[F-003-module-skeleton-and-persona-review]],
[[F-001-numbering-reconciliation]]

## Context

The 0.6 skeleton had to scaffold canonical M0–M8 onto a repo whose existing `assignments/`
tree is chapter-ordered and drifts from the spine (legacy `assignments/m1`+`m2` hold
Program-Basics content that maps to spine **M3**; spine M1/M2 are new). Scaffolding into
`assignments/` would either clobber existing files or entrench the drift — and the numbering
reconciliation (F-001) is a structural rebuild still pending human rulings. spine-owner proposed
a two-tree model; the human ratified it.

## Decision

1. **`modules/m0…m8/` is the canonical, spine-numbered home** for all module deliverables
   (skeleton now; deep-build LPAA content later). This is the tree the fleet builds into.
2. **Legacy `assignments/` is frozen** — never a scaffold or build target. No-clobber holds by
   construction; nothing in it is moved, renamed, or deleted by build work.
3. Legacy content's true spine-home is **recorded, not relocated**: each `modules/mN/_assets.md`
   carries the ledger of which `assignments/` files belong to it, pending the F-001 remap.
4. The eventual port/renumber of legacy content into `modules/` **lands later, per-module, with
   an owning ruling** — it is not a mass migration and not this decision's scope.

## Consequences

- Deep builds (Phase 1+) author into `modules/mN/`; `_contracts/` remain the frozen interface
  programs those builds refactor.
- `assignments/` stays as an untouched provenance source until each module's port ruling fires.
- The M1/M2→M3 remap (F-001 OQ7 / F-003 OQ1) is **still open** — it governs *what* ports into
  `modules/m3/`, not *where* the canonical tree lives (that is settled here).
- Superseding this layout requires a new ADR, not a quiet move.
