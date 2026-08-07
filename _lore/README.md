# _lore/ — the repo is the wiki

Long-term memory for the CSC-134 build (humans and agents alike). `CLAUDE.md` is working
memory and stays small; this tree is where decisions, findings, and vocabulary accumulate.
Marks on the wall, daily.

**The rule (Kevin enforces it):** no PR merges without its lore entry — a decision in
`decisions/`, a finding in `findings/`, or a glossary delta. If a PR changed nothing worth
remembering, that fact goes in the PR description and Kevin gets to disagree.

## Layout

| Path | What lives there | Format |
|---|---|---|
| `decisions/` | ADR-lite records, numbered `ADR-NNN-slug.md` | Context → Decision → Consequences, ~1 page max |
| `findings/` | Cohort QA findings ledgers, one file per module cycle | Transcript-cited entries; feeds common-mistakes + distractor banks |
| `invariants/` | Canonical course or catalog text preserved verbatim | Exact-text snapshots for audit and drift checks |
| `glossary.md` | Project vocabulary, one line per term | Term — definition — first-use pointer |

## Numbers and citations

**Check the directory before taking a number.** `ADR-013` is reserved and unwritten.

Three numbers name two files each — `ADR-016`, `F-009`, `F-014` — because two sessions
took the same number on the same day. [[ADR-018-lore-numbers-disambiguate-by-slug]] rules
that they **stand as history and are cited by slug**:

```
[[ADR-016-editorial-gate-ste100-derived]]   ← unambiguous
ADR-016                                      ← ambiguous; fine only for numbers
                                               that name one file
```

They are the last three. The `lore-numbers` check in `lpaa-gate.sh` fails any new
collision, and its grandfather list must never grow.

### Objective numbers — the same discipline, a different tree

**`modules/mN/_mlos.md` governs MLO numbering** ([[ADR-020-module-mlos-govern-cite-by-slug]]).
`_storming/CSC-134-learning-objectives.md` numbers M2 differently — four objectives where the
module file has seven — so a bare number resolves to two different objectives
([[F-024-two-mlo-numbering-schemes]]).

```
MLO-M2.3 (read-flowchart-and-pseudocode)   ← crossing documents: carry the slug
MLO 4.1                                     ← fine inside modules/m4/, where location says which
```

**The slug disambiguates; the punctuation does not.** Three citation forms exist in the tree
(`MLO 4.1`, `MLO-0.4`, `MLO-M2.3`) and **no prefix is mandated** — unifying ~170 citations would
buy nothing the slug does not. The LO document keeps its own numbering for the CLO mapping and
coverage matrix it serves; that view is not a citation target for build work. No gate enforces
this: see ADR-020 for why, and what would have to change first.

## Why ADR-lite

PRISM canon: ORANGE banks ADRs. The fleet writing decision records is in-character for the
program it's building. Keep them short — an ADR nobody reads is a mark on a wall nobody looks at.

## The boss key

Because lore is plain markdown in git, a **buttoned-up fork** of this repo — course content
plus `_lore/decisions/`, minus the storming scratch — can be produced for external audiences
(deans, committees, program review) at any time. The paper trail is the same files; only the
clutter differs.
