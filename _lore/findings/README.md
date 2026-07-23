# findings/ — cohort QA ledgers

One file per module cycle: `m4-round1.md`, `m4-round2.md`, … Written by the cohort-lead,
closed out by the cadence-master.

Every entry must cite its transcript (persona, worktree, step) and carry:

```
## F-<module>-<round>-<n>: <one-line title>
- Persona: <who hit it>
- Artifact: <file + section>
- Severity: blocker / major / minor / flavor
- What happened: <verbatim quote of instruction + verbatim output>
- Expected: <what the material implied>
- Disposition: open → fixed in <commit/PR> | wontfix (ADR link) | harvested (distractor/common-mistake ref)
```

No transcript citation, no entry — fabricated findings are worse than none.
