---
name: F-024-two-mlo-numbering-schemes
description: Two documents number M2's objectives differently — the LO companion has four MLOs, the module skeleton has seven — so a bare "MLO 2.2" resolves to two different objectives depending on which file you were holding. Recorded as an open question, not a ruling.
---

# F-024 — Two MLO numbering schemes, and a bare number that resolves to both

**Date:** 2026-08-06 · **Status:** Recorded · **Open question CLOSED 2026-08-07 by [[ADR-020-module-mlos-govern-cite-by-slug]]**
**Found:** while reconciling the M2 pseudocode gap
**Related:** [[ADR-018-lore-numbers-disambiguate-by-slug]] — same defect class, different tree

## What is true

Two files number M2's module-level objectives, and they do not agree.

**`_storming/CSC-134-learning-objectives.md`** — the instructional-design companion to the
spine, CLO-mapped, with a coverage matrix. **Four** objectives for M2:

| | |
|---|---|
| MLO 2.1 | languages exist; compiled vs. interpreted |
| **MLO 2.2** | **represent a solution using pseudocode, a Mermaid flowchart, and user stories** |
| MLO 2.3 | read a working program and describe its behavior |
| MLO 2.4 | classify errors |

**`modules/m2/_mlos.md`** — the module-local skeleton, self-described as *"PARTLY
INSTANTIATED"* and *"MLO **slots**"*. **Seven:**

| | |
|---|---|
| MLO-M2.1 | languages exist |
| **MLO-M2.2** | **compiler vs. interpreter** |
| **MLO-M2.3** | **read a flowchart and a piece of pseudocode; produce a simple one** |
| MLO-M2.4 | user stories |
| MLO-M2.5 | classify errors |
| MLO-M2.6 | predict output |
| MLO-M2.7 | perspective flip |

**They are not contradictory — they are different decompositions.** The module file splits the
LO document's objectives finer: LO 2.1 becomes M2.1 + M2.2; LO 2.2 becomes M2.3 + M2.4; LO 2.4
becomes M2.5. M2.6 and M2.7 have no LO-document parent at all.

## Why it bites

**A bare "MLO 2.2" resolves to two different objectives.** In the LO document it is the
pseudocode objective. In the module skeleton it is compiler-vs-interpreter. Both citations are
individually correct; the number alone carries no information about which shelf you took it
from.

This was found the hard way. Work on the M2 pseudocode gap cited "MLO 2.2 requires pseudocode"
— **true** against the LO document. It was then "corrected" to MLO-M2.3 after reading the module
skeleton — **also true**, against that file. Neither citation was wrong. **The error was citing
a bare number in a collision**, and it survived a review, a merge, and a self-correction that
introduced the opposite half of the same mistake.

`modules/m2/learn.md` uses the module scheme consistently for all five objectives it states, so
nothing inside that file is inconsistent. The ambiguity only appears when a document outside
`modules/mN/` cites a number.

## Scope

**Unknown, and deliberately not guessed.** M2 is confirmed divergent. M4 was spot-checked and
the LO document's numbering there looks conventional, but no full audit was run across M0–M8 —
this finding records what was observed, not an estimate of the blast radius. **A full crosswalk
is the first thing any ruling should commission.**

## The open question

**Which scheme governs a citation, and what should a citation look like?**

Three shapes, none chosen here:

1. **The LO document governs**, and module `_mlos.md` files are derived drafts that should
   re-number to match. Cost: rewrites `_mlos.md` across nine modules and every `learn.md`
   objective line that cites the module scheme.
2. **The module files govern** for module-local work, and the LO document is the
   accreditation-facing view. Cost: two permanent schemes, and every cross-document citation
   stays ambiguous unless qualified.
3. **Neither renumbers; citations disambiguate** — the [[ADR-018-lore-numbers-disambiguate-by-slug]]
   pattern, extended from lore numbers to objective numbers. Cost: nothing structural, but every
   citation gets longer, and nothing mechanical enforces it.

**No ADR number is taken.** `CLAUDE.md` is explicit: *"If a genuine decision surfaces that you
cannot make, record it as an open question for a human ruling — do not grab an ADR number when
numbering is contested."* Numbering is contested. This is the record, not the ruling.

### Ruled, 2026-08-07 — [[ADR-020-module-mlos-govern-cite-by-slug]]

**Shape 2 with shape 3's citation discipline.** `modules/mN/_mlos.md` governs; a citation that
crosses documents names the objective, not the number alone; the LO document keeps its numbering
for the accreditation view it serves. Nothing is renumbered — the schemes are different
*decompositions*, and collapsing them would lose M2.6 and M2.7 entirely.

### Two corrections this finding earned, made while writing the ruling

**1. M2 was not the first case.** `modules/m0/_mlos.md` carries a banner recording the same
collision — four slots there against three in the LO document, with the AI-collaboration
objective at `MLO-0.4` in one and `MLO 0.3` in the other. [[F-015-breadth-pass-recipe]] wrote it
up during the breadth pass. **This finding rediscovered for M2 what was already known about M0**,
which is the strongest argument that a finding was not enough and a ruling was needed.

Confirmed divergent is therefore **two modules, not one**. Seven remain unaudited.

**2. There is no established prefix convention to lean on.** The first draft of ADR-020 claimed
every module beat already used an `M`-prefixed form, so the ruling would need no sweep. That was
false, and checking it before commit is the only reason it did not ship:

| Form | Where | Count |
|---|---|---|
| `MLO 4.1` — bare | m3–m8, and the LO document | ~142 |
| `MLO-0.4` — hyphenated | m0 | 16 |
| `MLO-M2.3` — hyphenated, module-lettered | m2 | 12 |

The `MLO-M2.3` form exists in exactly one file — `modules/m2/learn.md`, written the day before,
by the same author who then cited it as a pre-existing convention. **The ruling was rewritten to
mandate no prefix at all**: the slug disambiguates, the punctuation never did.

The full M0–M8 crosswalk this finding commissioned is **still worth doing and blocks nothing** —
the ruling holds whatever it finds. See ADR-020 for why no gate was built and what would have to
be true first.

## What was done in the meantime

The M2 pseudocode section was authored, because **it is required under both schemes** and no
ruling is needed to close a gap that every numbering agrees exists. The one outward-facing
citation was qualified to name both numbers rather than pick one.

## Note for whoever rules

The `lore-numbers` check in `lpaa-gate.sh` catches this defect class for `_lore/` — one number,
one file — and it cannot see objective numbers at all. If ruling 1 or 2 is chosen, the
enforcement question is whether that check should grow a second mode, or whether MLO numbering
stays a human-reviewed convention. **Do not silence it into covering both**; F-019's lesson is
that a gate which quietly widens its remit stops being readable as evidence.
