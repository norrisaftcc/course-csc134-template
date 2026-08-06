# ADR-018 — Colliding lore numbers stand; citations disambiguate by slug

**Date:** 2026-08-06 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Claude Code session
**Relates to:** [[ADR-000-the-repo-is-the-wiki]] · **Context:** [[F-021-claude-md-refresh]]
**Numbering note:** ADR-013 remains **reserved** and unwritten (#23, the Haiku persona). This is 018.

## Context

Three lore numbers name two files each:

| Number | Used by | |
|---|---|---|
| `ADR-016` | `ADR-016-breadth-first-pass` | `ADR-016-editorial-gate-ste100-derived` |
| `F-009` | `F-009-fallthrough-warning-claim-is-toolchain-dependent` | `F-009-verification-procedure` |
| `F-014` | `F-014-breadth-pass-state-audit` | `F-014-m4-m5-hardening` |

Every one has the same cause: **two sessions acting on the same tree without
seeing each other.** Both ADR-016s were written on 2026-07-29. F-021 documents the
same collision happening again at a larger scale — two independent full rewrites
of `CLAUDE.md`, two days apart, neither branch aware of the other.

`CLAUDE.md` already said *do not grab an ADR number when numbering is contested*,
which stopped the collisions growing but did not settle the ones that exist.

## Decision

**1. The collisions stand. Nothing is renumbered.**

`ADR-016-breadth-first-pass` and `ADR-016-editorial-gate-ste100-derived` both keep
their number, as do the F-009 and F-014 pairs.

**2. Citations disambiguate by slug.** A reference to a colliding number names the
file, not the number alone:

```
[[ADR-016-editorial-gate-ste100-derived]]     ← unambiguous
ADR-016                                        ← ambiguous; only acceptable for
                                                 numbers that name one file
```

Non-colliding numbers may still be cited bare. `[[wiki-style]]` refs already carry
the slug, so the convention costs nothing where it is already followed.

**3. Existing bare citations are not swept.** They are ambiguous to a machine and
almost never to a reader — surrounding context says which ADR-016 is meant. A
repo-wide edit to fix them would touch workflows, gate scripts, and ledgers to
gain very little.

**4. New collisions are a build break.** The `lpaa-gate` grows a `lore-numbers`
check: any number naming two files fails, except the three above, which are
grandfathered by this ADR. That makes this the **last** set.

## Why not renumber

Renumbering is the clean end state and it was rejected on blast radius:

- Both ADR-016s are cited **by bare number** across `.github/workflows/`,
  `.github/scripts/`, `_tracking/`, and other lore. A sweep that misses one leaves
  a citation pointing at a decision that no longer exists — a false claim about
  the repo, which is exactly what the LPAA gate exists to catch. **The fix would
  risk creating the defect class it was meant to clean up.**
- The numbers are already in merged PR titles, commit messages, and issue threads.
  Those cannot be swept at all, so renumbering does not actually retire the old
  number — it adds a second meaning to it.
- Nothing downstream reads lore numbers programmatically. The cost of the
  collision is a reader's half-second, paid only when the surrounding text is
  ambiguous, which is rare.

**What tipped it:** the cheap half of the value is in prevention, not cleanup.
Grandfathering three known pairs and gating the next one gets that half for the
price of a check, without touching a single existing citation.

## Consequences

- **Readers must carry the slug** for three numbers, forever. That is the honest
  cost of this option and it does not get better with time.
- **The gate needs a grandfather list**, which is a small piece of history encoded
  in a script. It is spelled out in `lpaa-gate.py` with a pointer here, and it
  should never grow — a fourth entry means the check was bypassed rather than
  fixed.
- **`_lore/README.md` gains the citation convention** so it is findable from the
  tree it governs, not only from `CLAUDE.md`.
- **The root cause is untouched.** Sessions still cannot see each other's
  branches; the check catches the collision at commit time rather than preventing
  it. Checking open PRs before starting a repo-wide pass remains a human habit,
  and F-021 records what it costs when it is skipped.
