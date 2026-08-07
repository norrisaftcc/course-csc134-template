# ADR-020 — Module `_mlos.md` governs MLO numbering; cross-document citations carry a slug

**Date:** 2026-08-07 · **Status:** Accepted
**Closes the open question in:** [[F-024-two-mlo-numbering-schemes]]
**Prior art:** [[F-015-breadth-pass-recipe]] recorded the same collision for M0
**Pattern borrowed from:** [[ADR-018-lore-numbers-disambiguate-by-slug]]

## Context

Module-level objectives are numbered in two places, and the two disagree by **decomposition**,
not by offset. `modules/m2/_mlos.md` gives M2 seven slots; `_storming/CSC-134-learning-objectives.md`
gives it four, and the module file splits the LO document's finer. A bare "MLO 2.2" therefore
resolves to the pseudocode objective in one file and compiler-vs-interpreter in the other.

**This is not new, and M2 is not the only case.** `modules/m0/_mlos.md` carries a banner saying
the same thing: four slots there, three in the LO document, with the AI-collaboration objective
sitting at `MLO-0.4` in one and `MLO 0.3` in the other. [[F-015-breadth-pass-recipe]] recorded it
during the breadth pass. **F-024 rediscovered for M2 what F-015 already knew about M0** — which
is itself the argument for a ruling rather than another finding.

Three citation forms are in the tree today:

| Form | Where | Count |
|---|---|---|
| `MLO 4.1` — bare | m3–m8 (142) and the LO document (32) | 174 |
| `MLO-0.4` — hyphenated | m0 | 16 |
| `MLO-M2.3` — hyphenated, module-lettered | m2 | 12 |

**202 citations in total**, counted with `rg -o` per tree.

## Decision

**1. `modules/mN/_mlos.md` governs.** It is the authoritative numbering for module-level
objectives. Where it and the LO document disagree, the module file is what a citation means.

**2. A citation that crosses documents carries a slug.** Inside a module's own files, the bare
number is unambiguous from location and stays that way. Outside it, name the objective:

```
MLO-M2.3 (read-flowchart-and-pseudocode)   ← in lore, exemplars, cross-module docs
MLO 4.1                                     ← fine inside modules/m4/
```

**3. No prefix is mandated, and no sweep is run.** The tree holds three forms because three
sessions wrote them; unifying them would touch all 202 citations to buy a cosmetic win. **The slug
is what disambiguates — the punctuation never did.** Existing forms stay as they are.

**4. The LO document is re-scoped, not demoted.** It remains the instructional-design and
accreditation-facing artifact: CLO mapping, the I/D/M coverage matrix, the CCL crosswalk. Its
numbering is internal to that view and is not a citation target for build work. Nothing in it is
wrong; it answers a different question.

## Why not renumber

The same blast-radius reasoning as ADR-018, and it lands harder here:

- **Renumbering would destroy information.** The schemes are different *granularities*, not
  different labels for one list. Collapsing M2's seven slots into the LO document's four loses
  M2.6 and M2.7, which have no LO-document parent at all. M0 has the mirror problem — its
  `MLO-0.3` (inputs/process/outputs) has no counterpart the other way.
- **The LO document is accreditation-facing.** Its numbers feed the CCL crosswalk and coverage
  matrix — the artifact least able to absorb churn.
- **202 citations.** A sweep that misses one leaves a citation pointing at an objective that no
  longer exists: a false claim about the repo, which is the defect class the LPAA gate exists to
  catch. **The fix would risk creating what it cleans up** — ADR-018's exact argument.

## Consequences

**Good.** "Which MLO 2.2?" now has an answer, and it is the same answer in M0, M2, and any module
the audit below turns up. The rule costs nothing to follow and nothing to retrofit.

**The cost, stated plainly.** Two numbering schemes and three citation forms remain in the tree,
permanently, by design. A reader comparing the LO document with a module `_mlos.md` still sees
different numbers for the same objective. **This ADR makes that survivable, not invisible** — the
note added to the LO document is what stops it being a trap for the next reader.

**Confirmed divergent: M0 and M2. Unaudited: seven modules.** M4 was spot-checked and looks
conventional. **The full M0–M8 crosswalk is worth commissioning and blocks nothing** — the ruling
holds whatever it finds. It is an open item, not a prerequisite.

**No gate was built, and that is a choice.** A check could flag cross-document citations lacking a
slug. It is not built here because the rule's boundary is *where the citation lives*, not its
text — a regex cannot tell a bare `MLO 4.1` inside `modules/m4/` (correct) from one in a lore file
(incomplete) without path logic, and the LO document uses the bare form legitimately throughout.
That is two exemptions on day one, which is the shape [[F-019-lpaa-content-gate]] warns about. If
slug-less cross-document citations start appearing, build it then, with the exemptions understood
rather than assumed.

## What this does not touch

- **`csc134-refresh-plan/CSC-134-learning-objectives.md`** — a stale fork by `CLAUDE.md`'s own
  reckoning. Not governed, not corrected.
- **Any module's objectives.** This is a citation ruling, not a curriculum change. No MLO was
  added, removed, renumbered, or reworded.
- **M0's open numbering question.** `modules/m0/_mlos.md` flags that its `MLO-0.1` drops a
  systems clause the spine requires. That is a *content* disagreement, not a numbering one, and
  it stays open.
