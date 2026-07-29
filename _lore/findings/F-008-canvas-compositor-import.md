---
name: F-008-canvas-compositor-import
description: Canvas compositor skill imported, validated and installed; M4 Learn + Assess composed end to end. Seven seam findings, all now ruled; Haiku alone stays pended to ADR-013.
---

# F-008 — Canvas compositor import, validation, and the M4 end-to-end run

**Date:** 2026-07-25 · **Rulings closed:** 2026-07-26 · **Status:** Closed · **Branch:** `phase0/canvas-compositor`
**Relates to:** [[ADR-012-canvas-compositor-enters-alpha-scope]] · **Pends:** ADR-013 (Haiku persona)
**Closes:** #18 · **Partially answers:** #19

## Rulings (2026-07-26)

Three seam findings were left open for a human call. All three are now settled, and the
principle behind all three is the same: **the compositor derives, it does not author.** Every
place that rule pinched, the answer was to keep the rule and move the work elsewhere — not to
soften it.

| | Ruling | Effect on this PR |
|---|---|---|
| **F-008-4** Apply has no student-facing source | **Out of compositor scope.** M4 Apply is not composed, and the missing student handout is filed as module-tree work | none — ships Learn + Assess |
| **F-008-6** Learn does not fit one page | **Multi-page series; the budget does not bend** (ruled 2026-07-25, confirmed) | already built, 3 readings |
| **F-008-1** Exemplars contradict a frozen contract | **Quarantine stands.** Kept as visual reference, mechanically barred from output | none — already enforced |

**F-008-3 (Haiku) is not a blocker.** The persona is frozen in `SKILL.md` under a STATUS banner
and `gate.py` fails any emitted page containing a check-in. That is a *shipping* state, not a
pending one: the compositor works with Haiku frozen, and ADR-013 can rule later without
reopening this PR. Issue #23 keeps the question.

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

**Ruling taken (2026-07-26): the quarantine stands. Do not delete them.**

Deleting was the tempting simplification — the repo would stop carrying C++ that contradicts a frozen
contract, and we now have four canon-correct pages of our own. It is the wrong call because of *which*
pages these are. Our four are all M4, all Learn and Assess. The exemplars cover M1, M2 Learn, M2
Practice, M4 Apply and M7 Apply — they are the only worked examples of the Practice exit-ticket shape
and of the **Apply stage-group** device, which is exactly the beat just ruled out of scope above. Burning
the only reference for the beat we cannot yet compose would cost more than the divergence does.

The quarantine is not documentation alone; it is mechanically enforced, and that is why keeping them is
safe. Verified 2026-07-26:

| Command | Exit | Meaning |
|---|---|---|
| `gate.py references` | **1** — 13 failures across 5 fragments | strict mode refuses them; they cannot pass as output |
| `gate.py references --reference` | **0** | usable for their one stated purpose, looking at |
| `gate.py _outputs/canvas-html` | **0** | canon pages clear the strict bar |

The failure mode worth guarding against was an exemplar being copied into `_outputs/` and shipped. It
cannot survive there: strict mode requires the provenance header and the derived-dial these predate, and
fails the Haiku check-ins four of them carry. The guard already existed; this ruling adds no machinery,
it records that the machinery was checked.

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

### F-008-4 — The Apply beat has no student-facing source *(closed: out of compositor scope)*

`modules/m4/apply-tutorial.md` is an **instructor script** — per-stage timings, "Ask the room", "where
students typically stall". Composing it into a student Canvas page would require rewriting prose, which
breaks #18's *derived, not duplicated* criterion outright. So M4 Apply was **not** composed.

This is a gap in the module tree, not a defect in the skill, and it explains the drift in F-008-1: the
parallel session had to author an Apply page fresh, and fresh authoring is how it left the contract behind.

**Ruling taken (2026-07-26): neither — M4 Apply is out of compositor scope, and the missing student
handout is filed as module-tree work (#33).**

Both framed options were rejected, for the same reason. Authoring a student companion doc is a
*module build* — it needs the `apply-tutorial-generator` skill at its EIGHTY/FULL setting, Linx's
readability pass, and both gates. Authoring the Canvas page directly costs more: it spends the one
invariant that makes this PR trustworthy. The acceptance evidence for the compositor is mechanical —
C++ extracted back *out of* the emitted HTML is byte-identical to the gated `.cpp`, and the Mermaid is
byte-identical to `learn.md`. That proof only exists because nothing was authored. Accept one authored
page and "derived, not duplicated" becomes a preference, and the next reviewer has no way to tell which
pages carry the guarantee.

So the compositor ships composing **Learn and Assess**, which is what it can honestly derive.

**What this exposed, and it is worth more than the ruling.** `modules/m4/` contains no student-facing
Apply artifact at all — only `apply-tutorial.md`, which is an instructor script. M4 is on the Make
gradient at **type-in 100%** (CLAUDE.md bar #8), so students are meant to type a program in; today the
only place that program exists in student-readable form is the instructor's screen. That gap was
invisible until something tried to derive from it. **This is the compositor earning its keep before it
has shipped a single Apply page:** a derive-only tool cannot paper over a missing source, so it reports
one. Filed as #33 against the module tree, not against this skill.

### F-008-5 — PRIMM predict/reveal has no device on Canvas *(resolved; pattern set)*

`learn.md` uses **six `<details>` blocks** for predict-then-reveal. The skill forbids `<details>` on
evidence, not assumption: it does not survive this instance's sanitizer. There is no spoiler device on
tier one and nothing may be authored expecting one.

Resolved by making the boundary **visible prose** — "Decide your answer before you read past the program"
— then a hairline gutter labelled *Have your answer? Read on.* The honest move is to state the boundary
rather than fake a widget. Note this means GitHub and Canvas render the same reading differently, and the
Markdown remains the richer of the two.

### F-008-6 — A Learn beat does not fit one Canvas page *(closed: multi-page series)*

The tier-one budget is three to five breakouts. M4's reading carries ten-plus code blocks, two Mermaid
diagrams, and two operator tables across 17KB — roughly three pages' worth.

**Ruling taken (norrisa, 2026-07-25): Learn beats become a multi-page Canvas series.** The budget does
not bend. All three readings are built:

| Page | Covers | Breakouts |
|---|---|---|
| `m4-learn-1-when-programs-fork.html` | why programs fork; if/else; the chain; comparison operators; the decision drawn | 5 |
| `m4-learn-2-switch-and-combining.html` | `switch` and `default`; `&&` `\|\|` `!`; nesting and the whole gate | 5 |
| `m4-learn-3-three-traps.html` | the three traps; wrap-up; common questions; check yourself | 5 |

Each lands **exactly at the ceiling**, which is the evidence the split was necessary rather than
tidy-minded: as one page it would have been three times over budget.

Both Mermaid blocks in `learn.md` survive composition byte-for-byte, and the C++ extracted back out of
Reading 2 is byte-identical to `modules/m4/code/learn-gate-class.cpp`, compiles clean, and reproduces
both claimed outputs verbatim.

**Pattern for later modules:** split at section boundaries the source already has, carry a `Reading N of
M` kicker, and end each page with a *Next* gutter carrying a placeholder link to the following one. The
series is a Canvas module sequence, not a single page with anchors — there are no anchors on tier one.

One thing the split surfaced that a single page would have hidden: composing Reading 3 meant testing a
factual claim about compiler silence, which turns out to be toolchain-dependent. See
[[F-009-fallthrough-warning-claim-is-toolchain-dependent]].

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
