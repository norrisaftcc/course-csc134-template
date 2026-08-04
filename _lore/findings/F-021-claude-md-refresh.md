---
name: F-021-claude-md-refresh
description: CLAUDE.md was refreshed against the repo's actual state — three enforcing gates, the boundary rule, MODULES.md as the status index. Surfaced one open question, an ADR/finding numbering collision, left for a human ruling.
---

# F-021 — CLAUDE.md refreshed against the built repo

**Date:** 2026-08-04 · **Status:** Recorded · **Branch:** `claude/claude-md-documentation-y98189`

`CLAUDE.md` is working memory and stays small (`_lore/README.md`). Small is not the
same as current. It described a two-gate repo with one status source, and the repo
had moved on: three enforcing gates plus an advisory fourth, a boundary rule, a
breadth pass complete across nine modules, and a status index that did not exist
when the file was last touched.

**The pattern F-019 named applies to this file too.** Finishing a piece of work is
what makes the surrounding status text false — and `CLAUDE.md` is surrounding text
for every piece of work in the repo.

## What was stale

| Was | Is |
|---|---|
| "See `.github/scripts/README.md` for how the **two** gates compose" | Three enforcing (compile, markdown, LPAA) + editorial advisory-with-one-enforcing-band |
| Bar #2 owned by a human who vouches | Bar #2 has an instrument — `editorial-gate.sh` (ADR-016), median grade 5.9 across 18 files |
| `_tracking/` = "the machine-readable course manifest" | The manifest is **stale by its own banner**; `modules/MODULES.md` is the status index and `breadth-pass-ledger.md` §6 is the live backlog |
| "Module deliverables land in per-module folders as the skeleton pass defines them" | The per-module file shape is settled and gated; M0/M1 correctly carry no `code/` |
| No mention of the audience boundary | ADR-017 — the `not part of the student handout` heading, mechanically enforced |
| No mention of frontmatter | `module:` / `lpaa_beat:` must agree with the path (LPAA gate check 2) |
| No mention of ADR-011's descope | STL and File I/O are out; M7 names classes rather than teaching them |
| `_lore/` = decisions, glossary, findings | Plus `invariants/` — and `.github/instructions/` says to read it **first** |

Added alongside: the fleet table (ten agents in `.claude/agents/`, previously
referenced only by first name — "Linx owns the readability pass" with no pointer to
`linx-voice-readability-editor`), a local-run block for the gates, and a short ADR
index.

## Verification

All four gates were run on this branch before the rewrite, so every claim about
gate state is measured rather than remembered (bar #1's own rule, applied to prose):

```
compile-gate    95 files: 77 clean, 0 warned, 0 errored, 18 expected (marked)   PASSED
markdown-gate   71 blocks: 71 matched, 0 failed, 0 unmigrated                   PASSED
lpaa-gate       STRICT=1 — every structural claim checks out                    PASSED
editorial-gate  18 files, median grade 5.9, highest 8.3; 0 above the band       advisory
```

## Open question — the numbering collision (for a human ruling)

CLAUDE.md says: *do not grab an ADR number when numbering is contested.* It is
contested, in three places:

| Number | Used by | |
|---|---|---|
| `ADR-016` | `ADR-016-breadth-first-pass` | `ADR-016-editorial-gate-ste100-derived` |
| `F-009` | `F-009-fallthrough-warning-claim-is-toolchain-dependent` | `F-009-verification-procedure` |
| `F-014` | `F-014-breadth-pass-state-audit` | `F-014-m4-m5-hardening` |

`ADR-013` is separately **reserved and unwritten** (#23, the Haiku persona).

**Not resolved here, on purpose.** Both ADR-016s are cited by bare number across
workflows, gate scripts, ledgers, and other lore; renumbering is a repo-wide edit
with a real chance of leaving a dangling citation — which is the same class of
defect the LPAA gate exists to catch. The collision is recorded in `CLAUDE.md`
with the next free numbers (**ADR-018**, **F-021**) so no one compounds it while
the ruling is pending.

Two options for whoever rules:

1. **Renumber the later of each pair** (editorial gate → ADR-018, and so on) and
   sweep every citation. Cleanest end state, widest blast radius.
2. **Let the collisions stand as history** and disambiguate by slug in all future
   citations. Zero blast radius; readers must carry the slug forever.

A third possibility worth naming: a `lpaa-gate` check for duplicate lore numbers,
which would have caught all three at the moment they were created. Cheap, and it
fits the gate's remit exactly — a claim the repo makes about itself.
