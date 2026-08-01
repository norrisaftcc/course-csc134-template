# M6 — Module Learning Objectives (skeleton)

**Status: PARTLY INSTANTIATED.** `learn.md` now states finished objective sentences
for **MLO 6.1** (define and call functions with prototypes, parameters and return
values, in the full single-file form) and **MLO 6.2** (distinguish pass-by-value
from pass-by-reference). It covers the *explaining* half of **MLO 6.3** — what a
refactor is, and that behaviour must not change — and demonstrates one, lifting the
M5 validation loop into `readChoice`. The *doing* half of 6.3 belongs to the Assess
refactor lab, which is not authored. Where this file and `learn.md` differ in
phrasing, the Learn beat is the authored version.

The rest below is the original slot record. Derived from
`_storming/CSC-134-course-spine.md` ("## M6 — Functions") and
`_storming/CSC-134-learning-objectives.md` ("### M6 — Functions"). Deep-build
fills in beat-level detail; this file records the MLO shape and its CLO/CCL
wiring so downstream beats (Learn/Practice/Apply/Assess) build against the
same targets.

---

## MLO slots (feeding the CLOs)

| MLO | Statement (from the learning-objectives doc) | Feeds |
|---|---|---|
| **MLO 6.1** | Define and call functions using prototypes, parameters, and return values in the single-file convention. | → CLO4 (Functions) |
| **MLO 6.2** | Distinguish pass-by-value from pass-by-reference and apply each appropriately. | → CLO4 (Functions), CLO5 (Arrays/structs/pointers) |
| **MLO 6.3** | Refactor an existing program into functions without changing its behavior. | → CLO4 (Functions) |

*Measured by (per the objectives doc):* the refactor-into-functions lab. The
Assess-beat spec stub (`_assess-spec.STUB.md`) is where this gets turned into
testable acceptance criteria.

---

## CCL crosswalk touch (this module)

The CCL catalog description does not name "functions" as its own topic word
(its list is I/O, iteration, arithmetic, arrays, pointers, filters, and
OOP — see the spine's CCL crosswalk table). M6's touch is indirect but real:
functional decomposition is the *mechanism* the CCL's closing clause names —
**"design, code, test, and debug C++ language programs"** — and MLO 6.3's
refactor move is where "design" first means *re-*design of working code, not
just first-draft structure.

CLO coverage-matrix row for M6 (from the learning-objectives doc's coverage
matrix, I=Introduced / D=Developed / M=Mastered):

| CLO | M6 |
|---|:--:|
| CLO1 — Design & represent | **D** |
| CLO2 — I/O & arithmetic | **D** |
| CLO3 — Selection & iteration | — |
| CLO4 — Functions | **I** |
| CLO5 — Arrays/structs/pointers | — |
| CLO6 — Objects / classes | — |
| CLO7 — Test & debug | **D** |
| CLO8 — Communicate & AI use | **D** |

M6 **introduces CLO4** (its home CLO) and develops CLO1, CLO2, CLO7, CLO8. All
CLOs master at M8's capstone.

**Flagged nuance, not resolved here:** the objectives doc lists MLO 6.2 as
feeding *both* CLO4 and CLO5 (pass-by-reference previews the pointer/reference
mechanics CLO5 needs), but the coverage matrix does not mark a CLO5 cell at M6
(CLO5's first marked cell is M7, "I·D"). This is not a contradiction to fix
here — pass-by-reference in M6 is taught as a function-parameter mechanic, not
yet named "a pointer" or "a reference type" in the CLO5 sense — but deep-build
should confirm the Learn-beat reading doesn't overclaim CLO5 coverage before
M7 introduces it formally.

---

## Resolved (2026-08-01)

### MLO 6.2's scope boundary — answered, and verified by grep

The item asked that the reference-vs-pointer boundary be stated explicitly in the Learn reading so
students don't conflate "reference parameter" with "pointer" a module early.

**`modules/m6/learn.md` contains the word "pointer" zero times.** It teaches the distinction as a
parameter-passing choice and names it in exactly those terms — *"Pass by value — the function gets a
copy"* / *"Pass by reference — the function gets your variable"* — plus the one-character reading
rule, `int hp` is a copy and `int &hp` is the original. The conflation this item guards against
cannot happen from M6's reading, because the other word never appears.

**One honest caveat, since the item framed the boundary as a handoff.** M7's Learn beat does not say
"pointer" either — it walks arrays → parallel arrays → structs → by-reference and names classes as
the destination without teaching them ([[F-015]]). So the *boundary* holds on M6's side; the
*pickup* on M7's side is not built yet. That is M7's business and is tracked by M7's own pending
slots, not this one.

## Slots pending deep-build authoring

- [ ] Per-MLO "what a student can do" behavioral statement (beyond the
      spine's one-line summary above). **Blocked:** M6 is `First pass` — the Learn beat is
      authored; Practice, Apply and Assess are not, so the artifact that would measure each
      objective does not exist to describe.
- [ ] Mapping each MLO to the specific Learn/Practice/Apply/Assess artifact
      that measures it. **Learn is built** (`learn.md` + 4 gated sources); Practice, Apply and
      Assess are not, and `_assess-spec.STUB.md` is the Assess build record.
- [ ] Scope basics (MLO 6.1's "scope" clause) — deep-build to decide how much
      time this gets relative to the refactor signature move; the spine lists
      it as content but does not name a dedicated Practice item beyond "identify
      scope" in the exit-ticket one-liner. **Blocked:** a timing question about a session that
      does not exist yet. The Learn beat does carry the planned scope error
      (`learn-break-scope.cpp`, `'torches' was not declared in this scope`).
