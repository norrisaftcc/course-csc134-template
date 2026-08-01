# M5 — Module Learning Objectives

**Status: AUTHORED.** M5 is `Ready` — four beats and cohort round 1 ([[F-017]]) — and every slot
this file once listed as pending is answered below under *Resolved*: behavioral statements
per MLO, the MLO→artifact mapping, and the module's two scope questions. The slot record
below is kept as the derivation. Where it and the authored beats differ, **the beats win.**

Derived from
`_storming/CSC-134-course-spine.md` ("## M5 — Loops") and
`_storming/CSC-134-learning-objectives.md` ("### M5 — Loops"). Deep-build
fills in beat-level detail; this file records the MLO shape and its CLO/CCL
wiring so downstream beats (Learn/Practice/Apply/Assess) build against the
same targets.

---

## MLO slots (feeding the CLOs)

| MLO | Statement (from the learning-objectives doc) | Feeds |
|---|---|---|
| **MLO 5.1** | Implement iteration using `while`, `do-while`, and `for` loops. | → CLO3 (Selection & iteration) |
| **MLO 5.2** | Validate user input and prevent common loop failures (infinite loops, `cin` fail state). | → CLO3, CLO7 (Test & debug) |
| **MLO 5.3** | Predict loop output using a trace table before running the program. | → CLO7 (Test & debug) |
| **MLO 5.4** | Combine loops and selection to filter and process a sequence of data. | → CLO3 |

*Measured by (per the objectives doc):* loop fundamentals (`while`/`for`/
array-search) + Project 2, the menu-driven game. The Assess-beat spec stub
(`_assess-spec.STUB.md`) is where this gets turned into testable acceptance
criteria.

---

## CCL crosswalk touch (this module)

Per the spine's M5 section: **iteration; filters (loop-and-select over
streams).**

CLO coverage-matrix row for M5 (from the learning-objectives doc's coverage
matrix, I=Introduced / D=Developed / M=Mastered):

| CLO | M5 |
|---|:--:|
| CLO1 — Design & represent | — |
| CLO2 — I/O & arithmetic | — |
| CLO3 — Selection & iteration | **I** *(loops introduced here; selection itself was introduced M4)* |
| CLO4 — Functions | — |
| CLO5 — Arrays/structs/pointers | — |
| CLO6 — Objects / classes | — |
| CLO7 — Test & debug | **D** |
| CLO8 — Communicate & AI use | **D** |

*(Confirm the exact letters against the learning-objectives doc's own
coverage-matrix row for M5 at deep-build time. This file transcribes the
per-module MLO list, which is the primary source. The matrix table itself
lives further down that same document; this skeleton pass did not recopy it
cell-by-cell.)*

M5 introduces the iteration half of CLO3 (selection was introduced in M4) and
develops CLO7 and CLO8. No CLO masters at M5 — all CLOs master at M8's
capstone.

---

## Resolved (2026-08-01)

M5 is `Ready` — four beats, cohort round 1 run and its four should-fix closed
([[F-007]], [[F-017]]).

### What a student can do — per MLO

- **MLO 5.1** — Write a `while`, a `do`/`while` and a counted `for`, and say which one a given job
  wants: unknown count, at-least-once, or known count.
- **MLO 5.2** — Write the loop-and-validate pattern from understanding: reject a non-number and an
  out-of-range number, recover the stream with `cin.clear()` and `cin.ignore(...)`, and re-prompt
  without spinning.
- **MLO 5.3** — Fill a trace table by hand for a non-trivial loop, including the pass where it
  stops, and use a disagreement between hand and machine to locate *which pass* went wrong.
- **MLO 5.4** — Walk a sequence with a counted loop and a decision inside it, and report a hit or a
  miss without reading past the end.

### Which artifact measures each MLO

| MLO | Learn | Practice | Apply | Assess |
|---|---|---|---|---|
| **5.1** | all three loop sections | Items 1, 2, 3 | Part 1 Stage 3 (`for`) | Part 1, all three exercises |
| **5.2** | the loop-and-validate section | Items 5, 6 | **Part 2** — the one gap the student closes | **C tier**, and again at **B** |
| **5.3** | the Level Up trace table | Items 2, 3 (trace tables) | Part 1 Stage 3 trace | **Badge** — a hand-completed table |
| **5.4** | the counted-loop / list section | Item 7 (array search) | — | Part 1 Exercise 3 |

### MLO 5.3's trace-table artifact shape — answered

**Both, plus a graded third.** The item asked whether the trace table is a Practice artifact, an
Apply scaffold element, or both. It is:

- **Practice** — Items 2 and 3 each ship an ungraded scratchpad table
- **Apply** — Part 1 Stage 3 asks for two rows by hand before building
- **Assess/Badge** — a **graded** hand-completed table, minimum four passes, including the stop

[[F-017]] tested the design and it held (watch-list Q6): two of three personas filled the ungraded
tables voluntarily, and **both were the personas who went on to earn Badge**. The one who skipped
them stopped at B. No revisiting needed.

## Slots pending deep-build authoring

- [ ] Confirming MLO 5.4's exact Assess-beat home. "Combine loops and selection to filter a
      sequence" is the array-search half of the Assess line. **This is now live rather than
      hypothetical:** closing #50 added a "walking a list" gloss — array syntax, slots counting
      from 0 — to `learn.md`, which is the drift toward M7 this item exists to warn about. It is
      defensible (the spine's M5 Assess line names array-search explicitly, so the *material* was
      already committed and only the *teaching* was missing) and it is a two-minute revert.
      **Open for a spine-owner ruling**; recorded in [[F-017]].
