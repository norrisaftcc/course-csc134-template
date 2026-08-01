# M4 — Module Learning Objectives

**Status: AUTHORED.** M4 is `Ready` — four beats and two cohort rounds ([[F-005]], [[F-006]]) — and every slot
this file once listed as pending is answered below under *Resolved*: behavioral statements
per MLO, the MLO→artifact mapping, and the module's two scope questions. The slot record
below is kept as the derivation. Where it and the authored beats differ, **the beats win.**

Derived from
`_storming/CSC-134-course-spine.md` ("## M4 — Decisions") and
`_storming/CSC-134-learning-objectives.md` ("### M4 — Decisions"). Deep-build
fills in beat-level detail; this file records the MLO shape and its CLO/CCL
wiring so downstream beats (Learn/Practice/Apply/Assess) build against the
same targets.

---

## MLO slots (feeding the CLOs)

| MLO | Statement (from the learning-objectives doc) | Feeds |
|---|---|---|
| **MLO 4.1** | Implement selection using `if` / `else if` / `else` and `switch`. | → CLO3 (Selection & iteration) |
| **MLO 4.2** | Construct boolean expressions using comparison and logical operators. | → CLO3 (Selection & iteration) |
| **MLO 4.3** | Translate a flowchart's decision points into working code, and recover a flowchart from existing code. | → CLO1 (Design & represent), CLO3 (Selection & iteration) |

*Measured by (per the objectives doc):* the decision-structures (CYOA) lab.
The Assess-beat spec stub (`_assess-spec.STUB.md`) is where this gets turned
into testable acceptance criteria.

---

## CCL crosswalk touch (this module)

Per the spine's M4 section: **filters (selection over data)** — this is the
module where "filters" (conditionally processing input) begins as a named
CCL concept.

CLO coverage-matrix row for M4 (from the learning-objectives doc's coverage
matrix, I=Introduced / D=Developed / M=Mastered):

| CLO | M4 |
|---|:--:|
| CLO1 — Design & represent | **D** |
| CLO2 — I/O & arithmetic | **D** |
| CLO3 — Selection & iteration | **I** |
| CLO4 — Functions | — |
| CLO5 — Arrays/structs/pointers | — |
| CLO6 — Objects / classes | — |
| CLO7 — Test & debug | **D** |
| CLO8 — Communicate & AI use | **D** |

M4 **introduces** CLO3 — selection & iteration begins here. M4 also develops
CLO1, CLO2, CLO7, and CLO8, all already introduced in earlier modules. All
CLOs master at M8's capstone.

---

## Resolved (2026-08-01)

All four items are answered by artifacts that shipped after this file was written. M4 is `Ready`:
four beats, two cohort rounds, seven findings closed ([[F-004]], [[F-005]], [[F-006]]).

### What a student can do — per MLO

- **MLO 4.1** — Given a scene with a category and a score, write a `switch` with at least three
  `case`s plus a `default`, and an `if` / `else if` / `else` chain with at least three branches,
  and explain why `break` is needed in the first and not the second.
- **MLO 4.2** — Write one compound condition using `&&`, `||`, or `!` that changes the outcome for
  at least one input, and say in plain words which combination it selects for.
- **MLO 4.3** — Both directions. Draw a flowchart before coding and produce code matching it; and,
  given code never seen before, recover its flowchart with the right number of decision diamonds.

### Which artifact measures each MLO

| MLO | Learn | Practice | Apply | Assess |
|---|---|---|---|---|
| **4.1** | `learn.md` — the `if` ladder and the `switch` | exit ticket Items 1, 4, 5 | Apply Stages 2–3 | **C tier** — both structures required |
| **4.2** | `learn.md` — the logic-operator section | exit ticket Item 7 | Apply Stage 4 (`&&`) | **B tier** — one compound condition |
| **4.3** | the flowchart-first framing | flowchart items | Apply's design-first opening | **A tier** (forward) + **Badge** (reverse) |

### MLO 4.3's "recover a flowchart from existing code" half — answered

**It lives at Badge.** `assess-lab.md`'s Badge item 1 is *"A recovered flowchart (the reverse
direction)… read the code, recover the diagram,"* against a temperature classifier the student has
never seen. It is deliberately **not** the dungeon: a familiar gatekeeper would let a student answer
from memory instead of from the code. Its snippet is now a gated source
(`code/assess-badge-reverse.cpp`, added in #44), so the thing being recovered is a program that
actually compiles.

The item's two candidate homes were "a Practice exit-ticket item, or an Assess-tier requirement."
Assess won, and Badge specifically — reverse recovery is documentation work, which is what the
Badge tier is for.

### The MLO 4.2 / 4.1 tier boundary — answered

**4.1 first appears at C; 4.2 first appears at B.** Verbatim from the lab:

- **C tier** — *"A `switch` on the category input with at least three `case`s"* and *"an `if` /
  `else if` / `else` chain with at least three branches."*
- **B tier** — *"One compound condition using `&&`, `||`, or `!` that actually changes"* the outcome.

That ordering satisfies the no-trick-questions rule: the compound condition is taught in Learn, typed
in Apply Stage 4, and only *required* one tier above the baseline. Nothing is sprung.
