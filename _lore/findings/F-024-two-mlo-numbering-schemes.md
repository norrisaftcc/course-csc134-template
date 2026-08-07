---
name: F-024-two-mlo-numbering-schemes
description: Two documents number M2's objectives differently — the LO companion has four MLOs, the module skeleton has seven — so a bare "MLO 2.2" resolves to two different objectives depending on which file you were holding. Recorded as an open question, not a ruling.
---

# F-024 — Two MLO numbering schemes, and a bare number that resolves to both

**Date:** 2026-08-06 · **Status:** Recorded · **Open question — needs a human ruling**
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
