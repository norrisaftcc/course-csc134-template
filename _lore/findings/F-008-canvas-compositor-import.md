---
name: F-008-canvas-compositor-import
description: Canvas compositor skill imported, validated and installed; M4 Learn + Assess composed end to end. Records seven seam findings, three needing a ruling.
---

# F-008 — Canvas compositor import, validation, and the M4 end-to-end run

**Date:** 2026-07-25 · **Status:** Recorded · **Branch:** `phase0/canvas-compositor`
**Relates to:** [[ADR-012-canvas-compositor-enters-alpha-scope]] · **Pends:** ADR-013 (Haiku persona)
**Closes:** #18 · **Partially answers:** #19

The skill arrived by hand-off rather than by import PR (the etiquette path #18 was written for), staged
in `_storming/_tools/` on this branch and installed from there. Everything below was verified before
installation, not after.

## The skill validates honestly

Run against the five imported reference fragments, using the skill's own self-check as the gate:

| Check | Result |
|---|---|
| Sanitizer rules — forbidden tags, `class`, `<h1>`, fixed px widths, `background-color` without `color` | **0 failures** |
| Unescaped `<` / `>` inside `<pre>` | **0 failures** |
| Character diagram column budget | 27 / 28 / 16 cols — matches its own `PLACEHOLDERS.md` exactly, ceiling 40 |
| Rose fence gate `count("(@") == count("@)") == check-ins` | balanced across 5 check-ins |
| Placeholder marker accounting | sums correctly on every fragment |
| Both complete C++ listings under `g++ -std=c++17 -Wall -Wextra` | **clean, 0 warnings** |
| Claimed runtime output | reproduced verbatim, including M7's teaching point `Reachable gold: 0` with the TODO unfilled |

**It does not claim a gate it did not run.** That is why it was trusted enough to install.

## The M4 end-to-end run (acceptance criteria)

Composed from student-facing M4 source into `_outputs/canvas-html/m4/`:

- `m4-assess-lab-the-crossing.html` ← `modules/m4/assess-lab.md`
- `m4-learn-1-when-programs-fork.html` ← `modules/m4/learn.md`

**Derived, not duplicated — proven mechanically.** C++ extracted back *out of* the composed HTML is
byte-identical to `modules/m4/code/learn-gate-strength.cpp` (comments aside), compiles clean under the
course flags, and prints exactly what the page's predict moment claims for input `55`. The Mermaid block
is byte-for-byte identical to the one in `learn.md`. Mechanical bars #1 and #5 hold on HTML output.

## Seam findings

### F-008-1 — The reference exemplars contradict a frozen contract *(closed: quarantined)*

`m04-page-apply-gatekeeper.html` is not this repo's M4. Against `_contracts/m4_gatekeeper.cpp`:
`playerClass` vs `characterClass`; `endl` where the repo uses `endl` **zero** times; different
gatekeeper dialogue; no opening beat. Good prose, clean compile, different program wearing the same name.

Kept for visual inspection — a human eyeballing device rhythm is a judgment no gate makes — but labelled
non-canon in `references/README.md` and never usable as CSC-134 output.

### F-008-2 — The manifest is short a fragment *(closed: filled with canon content)*

`PLACEHOLDERS.md` lists six fragments; five arrived. Missing is `m04-assignment-dungeon-gatekeeper.html`,
the set's **only Assess exemplar** — so the beat whose pre-flight panel is *mandatory* had no worked
example. `m4-assess-lab-the-crossing.html` now fills that role with canon-correct content.

### F-008-3 — Haiku is content wearing formatting's clothes *(open: ADR-013)*

The skill carries a named AI assistant with a register, an ASCII rose glyph, rationing rules, and six
self-check gates. `Haiku` appears **nowhere else in this repo**. CLO8 genuinely covers "the responsible,
cited use of AI assistance" (`_storming/CSC-134-learning-objectives.md:29`), so the reasoning holds — but
a persona is course content, and content enters by ADR, not on a formatting PR.

Frozen, not deleted: the design stays in `SKILL.md` under a STATUS banner so the ruling has something
concrete to rule on. `gate.py` **fails** any emitted page containing a check-in. The persona descends
from the project's original Gemini Flash assistant; the rename is already noted in the skill.

ADR-013 also carries an authorship task the compositor cannot do: students are not issued Claude
accounts, but the course means to suggest Haiku is the better use of a free account's token budget. That
is M1 Learn prose, and the existing naming passage ends one sentence short of it.

### F-008-4 — The Apply beat has no student-facing source *(open: needs a ruling)*

`modules/m4/apply-tutorial.md` is an **instructor script** — per-stage timings, "Ask the room", "where
students typically stall". Composing it into a student Canvas page would require rewriting prose, which
breaks #18's *derived, not duplicated* criterion outright. So M4 Apply was **not** composed.

This is a gap in the module tree, not a defect in the skill, and it explains the drift in F-008-1: the
parallel session had to author an Apply page fresh, and fresh authoring is how it left the contract behind.

**Ruling needed:** does the Apply beat get a student-facing companion document that the compositor can
derive from, or does the Canvas Apply page get authored directly and accept that it is authored?

### F-008-5 — PRIMM predict/reveal has no device on Canvas *(resolved; pattern set)*

`learn.md` uses **six `<details>` blocks** for predict-then-reveal. The skill forbids `<details>` on
evidence, not assumption: it does not survive this instance's sanitizer. There is no spoiler device on
tier one and nothing may be authored expecting one.

Resolved by making the boundary **visible prose** — "Decide your answer before you read past the program"
— then a hairline gutter labelled *Have your answer? Read on.* The honest move is to state the boundary
rather than fake a widget. Note this means GitHub and Canvas render the same reading differently, and the
Markdown remains the richer of the two.

### F-008-6 — A Learn beat does not fit one Canvas page *(open: needs a ruling)*

The tier-one budget is three to five breakouts. M4's reading carries ten-plus code blocks, two Mermaid
diagrams, and two operator tables across 17KB — roughly three pages' worth. Composed as
**Reading 1 of 3**; readings 2 and 3 are not yet built.

**Ruling needed:** are Learn beats a multi-page Canvas series (proposed split: the chain / `switch` and
logical operators / the three traps), or does the budget bend for Learn? The budget was calibrated for a
course with shorter readings, so this is a genuine fork rather than a mistake.

### F-008-7 — The skill says never restate the rubric; the course says the opposite *(resolved toward the course)*

The skill's `Deferred #2` avoids rubric restatement so the description cannot contradict the attached
Canvas rubric. But `assess-lab.md` states outright: **"No hidden criteria — what is on this page is the
whole rubric."** Course policy wins (mechanical bar #7, no trick questions).

The four-column table is also 3 columns, over the tier-one ceiling of 2, so it was restructured into four
labelled gutter blocks — one per column, weights included. The tier ladder stayed a 2-column table because
Canvas rubrics are criterion × rating and cannot express nesting.

Also followed the skill's `Deferred #1`: numbered `<ol>` for tier requirements so feedback can cite "see 3",
drawn checkboxes reserved for the pre-flight panel.

## Two conventions set on this branch

- **`_outputs/` is build output**, never ground truth, never hand-edited, and carries its own README.
  Composed pages churn on every formatting tweak; keeping them out of `modules/` means a diff there is
  always a content change, never a re-render.
- **No dial declarations exist in `modules/`.** Rather than edit nine modules to add
  `<!-- compositor: M4 · assess -->`, the dial is **derived from the source path** and stamped into the
  emitted file along with a `SOURCE:` provenance line. `gate.py` requires both on emitted pages.

## The gate

`gate.py` ships with the skill and enforces the sanitizer rules, the Haiku freeze, table column ceilings,
character-diagram box-width shear and column budgets, placeholder accounting, breakout budgets, the
one-caution rule, and provenance. Two modes: strict for emitted output, `--reference` for imported material
that legitimately predates the provenance and freeze rules.

Writing it caught a bug in itself worth recording: a flat breakout count failed both Apply exemplars, which
are legal under the skill's Apply-only exception where a *stage group* counts as one. The gate now reads
the dial and applies the stage rule — and when there is no dial to read, it says so rather than failing.
A gate that cannot tell "violation" from "cannot check" is worse than no gate.

Run:

```bash
python3 .claude/skills/csc134-canvas-compositor/gate.py _outputs/canvas-html
python3 .claude/skills/csc134-canvas-compositor/gate.py .claude/skills/csc134-canvas-compositor/references --reference
```

Both green at time of writing.
