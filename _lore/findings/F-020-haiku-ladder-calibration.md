---
name: F-020-haiku-ladder-calibration
description: Four haiku agents worked the M4 and M5 LPAA ladders from the .md alone and emitted 30 .cpp files for mechanical diff. 30/30 compiled clean, zero cross-run variance, and two real material gaps that all three gates are blind to.
---

# F-020 — Haiku LPAA ladder calibration

**Date:** 2026-08-01 · **Status:** Recorded · **Run:** `wf_0cd28e6f-424` · 4 agents, 0 errors, 11m14s

A different instrument from a cohort round. F-017 collected **opinions** and found that convergent
approval is the weakest evidence this process makes. This run collects **artifacts** and diffs them,
so agreement cannot inflate the result.

**Method.** Four `haiku` agents, two independent runs each on M4 and M5 — the only two complete LPAA
ladders. Each worked `learn → practice → apply → assess` in its own worktree and returned the full
text of every `.cpp` a student would produce. Diffing was done mechanically afterward, not by an
agent.

**The one hard rule:** no reading `modules/*/code/*.cpp`, the answer key, the contracts, or anything
named `complete` / `reference` / `solution`. The measurement is *what the written material carries on
its own*. All four reported `peek_pressure: none`.

## Headline numbers

| | |
|---|---|
| Files emitted | **30** |
| Compiled clean on GCC, zero warnings | **30 / 30** |
| Beats completed | 4 of 4, all four runs |
| Self-reported stuck points | **0** |
| Cross-run variance | **0 lines** — independent runs byte-identical |
| Non-zero diffs vs reference | **2**, both identical across runs |

## Zero variance is the interesting number, and it cuts both ways

Two independent haiku runs produced **byte-identical files**. For M4 and M5's Apply beats that is
the right answer and a real endorsement: these sit at **type-in 100%** and **finish-the-80%**, where
the material is supposed to specify the artifact tightly enough that any two students converge.
They did, exactly, on a small model, with no stalls.

But it is also the ceiling. Zero variance means the model is **transcribing, not composing** — which
is what a type-in beat asks for and therefore proves nothing about beats that ask for judgement. The
Assess programs (spec-driven, reskinned to an airport gate and other themes) *did* diverge, and were
not diffable by design. **This method measures fidelity, not understanding.**

## The two findings — both real, both invisible to every gate

### 1. M4's Learn beat shows an abridged program while calling it the full scene — and I caused it

`modules/m4/learn.md:200` says:

> Here is **the full scene** — Stage C — putting the switch, the nesting, the compound `&&`, and the
> outcome chain together.

The block below it is missing the entire class `switch` — **17 code lines** — in both runs.

Before the ADR-015 migration (#44), that listing opened with:

```
// learn-gate-full.cpp — Stage C (abridged; full file in code/)
```

**My migration replaced that line with a bare `// ...`**, because the gate's elision rule needs a
line starting `// ...` and I took the shortest thing that satisfied it. The word *abridged* and the
pointer to the full file both vanished. The prose kept saying "the full scene."

**And the student's truncated program compiles clean**, because the `switch` was on a variable that
is still read. So the reader gets a working program that is not the program the page describes, with
nothing anywhere to say so.

**Fixed here.** The elision now names what it hides:
`// ... includes, main, and the Stage B class switch are above this line ...` — still a valid
elision, still gate-green, and now it tells the student a switch is missing rather than leaving a
silent ellipsis.

**Rule worth keeping: an elision should say what it elides.** `// ...` satisfies the gate and tells
a reader nothing. This is the second time an ADR-015 migration has quietly cost a page something —
the first was the `// <-- note the semicolon` annotation removed in #44, which was at least
deliberate.

### 2. M5's reference program has a line the tutorial never teaches

`apply-levelup.cpp:39` ends with:

```
cout << "Your hero grew from level 1 to level 10.\n";
```

`grep` for that string across `modules/m5/` finds it **only in the reference**. The Apply tutorial
never shows it, never asks for it, and none of its "Expected output" blocks contain it. A student who
follows the tutorial exactly finishes one line short of the reference — as both runs did, identically.

**No gate can see this.** The markdown gate is green because the tutorial's fences faithfully mirror
the stage files, and the stage files faithfully lack the line. Every artifact is internally
consistent; the *set* is not.

**Not fixed — it has two defensible answers and neither is mine to pick:**

1. **Teach the line.** Add it to the tutorial's Stage 3 as a final `// NEW`, updating
   `apply-stage3-loop.cpp` and the expected-output block. The program gets a closing beat.
2. **Drop it from the reference.** If the tutorial is the spec, the reference should match what the
   tutorial builds.

Option 2 is smaller; option 1 is probably better teaching, since a program that announces it
finished is friendlier than one that stops. **Filed for a ruling rather than chosen quietly.**

## What this says about the gates

Three gates are green and both findings walked straight past all of them:

- **compile-gate** — the truncated M4 program *compiles*. Compiling was never the question.
- **markdown-gate** — both listings faithfully mirror their sources. Provenance was never the question.
- **lpaa-gate** — every structural claim holds. Structure was never the question.

Each gate checks one relation and checks it well. **Neither of these defects lives inside a single
relation** — the M4 one is between *prose and listing*, the M5 one is between *tutorial and
reference*. What caught them was building the artifact and diffing it, which is the only instrument
so far that compares a page against what a reader would actually produce from it.

## Recommended as a standing check

Cheap, deterministic, and it found two real defects on its first run: **rebuild the type-in beats
from the page and diff.** It needs no personas, no opinions, and no judgement calls — the diff is
the result. Worth considering as a scheduled run rather than a one-off, at least for every beat at
FULL or EIGHTY on the Make gradient.

Its blind spot should be stated as plainly as its result: **it cannot see anything about a beat that
asks the student to compose.** For those, a cohort round is still the only instrument, with all the
weaknesses F-017 recorded.
