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
| `glossary.md` | Project vocabulary, one line per term | Term — definition — first-use pointer |

## Why ADR-lite

PRISM canon: ORANGE banks ADRs. The fleet writing decision records is in-character for the
program it's building. Keep them short — an ADR nobody reads is a mark on a wall nobody looks at.

## The boss key

Because lore is plain markdown in git, a **buttoned-up fork** of this repo — course content
plus `_lore/decisions/`, minus the storming scratch — can be produced for external audiences
(deans, committees, program review) at any time. The paper trail is the same files; only the
clutter differs.
