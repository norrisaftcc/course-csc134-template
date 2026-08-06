---
name: F-021-claude-md-refresh
description: Two sessions refreshed CLAUDE.md against the same stale state within two days. PR #66 landed first and is canon; #65 kept only what #66 lacks. The collision is the finding — and the numbering collisions it documents have the same cause.
---

# F-021 — CLAUDE.md refreshed against the built repo (and refreshed twice)

**Date:** 2026-08-04, amended 2026-08-06 · **Status:** Recorded ·
**Branch:** `claude/claude-md-documentation-y98189` (#65) · **Landed first:** #66

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
| Bar #2 owned by a human who vouched | Bar #2 has an instrument — `editorial-gate.sh` (ADR-016), median grade 5.9 across 18 files |
| `_tracking/` = "the machine-readable course manifest" | The manifest is **stale by its own banner**; `modules/MODULES.md` is the status index and `breadth-pass-ledger.md` §6 is the live backlog |
| "Module deliverables land in per-module folders as the skeleton pass defines them" | The per-module file shape is settled and gated; M0/M1 correctly carry no `code/` |
| No mention of the audience boundary | ADR-017 — the `not part of the student handout` heading, mechanically enforced |
| No mention of frontmatter | `module:` / `lpaa_beat:` must agree with the path (LPAA gate check 2) |
| No mention of ADR-011's descope | STL and File I/O are out; M7 names classes rather than teaching them |
| `_lore/` = decisions, glossary, findings | Plus `invariants/` — and `.github/instructions/` says to read it **first** |

## Two sessions, one file, two days apart

**This is the finding.** #66 (`claude/claude-md-docs-bvb3mu`) and #65 (this branch)
were authored independently against the same stale `CLAUDE.md` and reached
substantially the same conclusions — same eight gaps, same evidence, different
prose. #66 merged on 2026-08-06; #65 was still open, and went `dirty`.

**#66 is canon.** #65's conflict was resolved by taking #66's file whole and
grafting back only what it did not carry:

| Kept from #65 | Why it survived |
|---|---|
| The house-style line | `.github/instructions/` says read `_lore/invariants/` **first**, then the XP route — the simplest thing that could work |
| The ADR-011 descope note by the contracts | The one ruling most likely to be violated by reflex (`std::vector`, `fstream`) and it appeared nowhere in the file |
| "Decisions worth knowing before you start" | An eleven-row ADR index plus the five findings that changed how the build works |
| "Fix the status in the same PR" | Names the four places a status claim lives, so F-019's lesson has an action attached |

Everything else in #65 was dropped as redundant — including a fleet **table**,
because #66 deliberately chose prose with the named agents capitalized.

**Cost of the collision:** one full duplicate authoring pass, and a conflict
resolution that had to be done by hand because both sides rewrote the same
sections. Neither session could see the other's branch. The cheap mitigation is
the same one Kevin already owns — check open PRs before starting a repo-wide doc
pass — and it is exactly the check that would have prevented the ADR-016
collision below.

## Verification

All four gates were run on this branch before the rewrite, so every claim about
gate state is measured rather than remembered (bar #1's own rule, applied to prose):

```
compile-gate    95 files: 77 clean, 0 warned, 0 errored, 18 expected (marked)   PASSED
markdown-gate   71 blocks: 71 matched, 0 failed, 0 unmigrated                   PASSED
lpaa-gate       STRICT=1 — every structural claim checks out                    PASSED
editorial-gate  18 files, median grade 5.9, highest 8.3; 0 above the band       advisory
```

Re-run green after the merge resolution.

## The numbering collision — RULED 2026-08-06

> **Closed by [[ADR-018-lore-numbers-disambiguate-by-slug]]:** option 2. The three
> pairs stand as history and are cited by slug; nothing is renumbered and no
> existing citation is swept. The gate grew a `lore-numbers` check the same day —
> the third possibility named at the bottom of this section — so the grandfathered
> three are the last three. The question below is kept as the reasoning that led
> there.

CLAUDE.md says: *do not grab an ADR number when numbering is contested.* It is
contested, in three places:

| Number | Used by | |
|---|---|---|
| `ADR-016` | `ADR-016-breadth-first-pass` | `ADR-016-editorial-gate-ste100-derived` |
| `F-009` | `F-009-fallthrough-warning-claim-is-toolchain-dependent` | `F-009-verification-procedure` |
| `F-014` | `F-014-breadth-pass-state-audit` | `F-014-m4-m5-hardening` |

`ADR-013` is separately **reserved and unwritten** (#23, the Haiku persona).

**Same cause as the duplicate refresh above** — two sessions acting on the same
tree without seeing each other. That is worth stating plainly, because it means
one fix addresses both.

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

A third possibility worth naming, and it is cheap: a `lpaa-gate` check for
duplicate lore numbers. It would have caught all three at the moment they were
created, and it fits the gate's remit exactly — a claim the repo makes about
itself.
