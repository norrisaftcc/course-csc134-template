---
name: F-015-breadth-pass-recipe
description: The breadth-pass build record — what a First pass Learn beat actually costs, opened by the M2 pilot and appended to per module. Also records that born-compliant fences work on first authoring, and the machinery-boundary calls each module had to make.
---

# F-015 — The breadth-pass recipe, module by module

**Date opened:** 2026-07-29 · **Status:** Open (appended per module) ·
**Branch:** `module/m2-learn` · **Decided in:** [[ADR-016-breadth-first-pass]] ·
**Context:** [[F-014-breadth-pass-state-audit]]

This is the merge-gate entry for every breadth-pass module PR (ADR-016 §7): one
appended row here plus the ledger row, rather than seven ADRs for one decision.

---

## The recipe (established by the M2 pilot)

1. **Read the boundary before writing a line.** `_overview.md` gives the
   Make-gradient position; `_mlos.md` gives the objective slots;
   `_assess-spec.STUB.md` names what machinery the module may assume. The
   boundary is the constraint that most shapes the reading — see §"Machinery
   boundary" below.
2. **Write the `.cpp` files first.** Non-negotiable (ADR-016 §4). Nothing may be
   quoted that has not been through the compile gate.
3. **Run the programs and capture real output.** Never hand-write a sample run
   or a compiler message. F-010's four false compiler-silence claims came from
   asserted output; captured output cannot drift.
4. **Author `learn.md`, quoting with `excerpt=`.** Whole-file `source=` forces the
   file's header comment into the listing, which reads badly on a student page.
   `excerpt=` takes any contiguous chunk, so the header stays in the file and out
   of the reading — F-013's bucket-1 technique, now confirmed on new material.
5. **Gate scoped, then tree-wide.** Both must pass.
6. **Update the three status files**: `_overview.md` banner, `_mlos.md` (which
   slots the reading actually instantiated), and the `MODULES.md` row.

---

## Per-module records

### M2 — How to Solve Problems (pilot)

**Artifact:** `modules/m2/learn.md` — *"How to Solve Problems: Why We Need
Languages at All"*, plus 5 gated sources in `modules/m2/code/`.

| Measure | Value |
|---|---|
| Prose words | 1,806 (target 1,500–2,500) |
| Flesch–Kincaid grade | **6.0** (bar: ≤ 10) |
| Gated `.cpp` authored | 5 — 3 clean, 2 marked `EXPECT-ERROR` |
| Fenced `cpp` blocks | 5, **all born-compliant, all matched on the first gate run** |
| Non-gated fences | 5 (`html`, `javascript`, `python`, `asm`, `bash`) — not C++, correctly outside the gate |
| Mermaid diagrams | 2 (the program's straight-line flowchart; the edit→compile→run→verify loop) |
| Compile gate | 37 files tree-wide: 34 clean, 0 warned, 0 errored, 3 expected |
| Markdown gate | 50 blocks: 5 matched, **0 failed, 45 unmigrated** — unmigrated **unchanged** |

**The headline number is the last one.** The breadth pass added five fenced C++
blocks and the unmigrated count did not move. Born-compliant is not aspirational;
it worked on first authoring, with no migration pass and no rework.

**Machinery boundary — the call that shaped the reading.** M2 sits at type-in
100%, but more importantly it sits *before* almost everything: no variables or
`cin` (M3), no decisions (M4), no loops (M5), no functions (M6). Every M2 program
is therefore **straight-line `cout` only**. That is a real constraint, not a
stylistic one, and it settles an open question `_assess-spec.STUB.md` left
explicit — *"does branching/looping appear in the M2 sample program, or is M2's
sample straight-line only?"* **Straight-line only.** The reading leans into it
rather than apologising: the flowchart has no diamonds *because the program has
no decisions*, and it says so, pointing forward to M4 for the first diamond.

**A gap named rather than papered over.** M2 teaches all four error-taxonomy
words but can only *demonstrate* three in code. **Runtime** needs machinery M2
does not have — an unbounded loop (M5) or a `cin` fail state (M3/M5). Fabricating
one would have meant reaching ahead of the taught curriculum, and skipping the
word would have broken the four-word taxonomy (CLAUDE.md bar #4). So the reading
teaches the name, gives the test that distinguishes it (*did a program get built
and start running?*), and says plainly that the honest example arrives later.
**Recommended as the pattern** for any breadth-pass module that meets the same
shape: name the gap in the student-facing text, do not invent a demo for it.

**Adopted opportunistically: the source-vs-binary distinction (#22).** M2 is the
course's first `g++` invocation, and #22 argues M2 is the natural home for the
"the thing you typed is the source; the thing the compiler made is the program"
callout. It costs three sentences and a two-row table here, so it was taken —
option 3 in that issue. **#22 is not closed**: the student-template `.gitignore`
half (option 1) is untouched, and the Apply-beat half is unwritten.

**Cost.** Roughly 25% of a depth build's Markdown, and the code is the cheap part
— 5 short programs, none over 20 lines. The expensive part was the boundary
research, and that cost is per-module and does not amortise.

---

## Open items carried forward

- **Mermaid render is unverified by any script.** Bar #5 requires the diagram to
  actually render; the gates check provenance and compilation, not Mermaid.
  Checked by eye in the PR's Files-changed view. Worth noting that this is the
  one mechanical bar with no mechanical check.
- **`_mlos.md` slots are now partly instantiated.** M2's reading authored real
  objective sentences for M2.1/2.2/2.3/2.5/2.6; M2.4 and M2.7 remain `[TBD]`. The
  banner says so. Whether the MLO files get a full rewrite pass — or stay slot
  files pointing at the authored beats — is a question for the end of the breadth
  pass, not a per-module call.
- **The `First pass` tier's honesty depends on the banners.** Every first-pass
  module now has three files describing its state (`_overview.md`, `_mlos.md`,
  `MODULES.md`). F-014 §5 is the record of what happens when one of those goes
  stale and nothing notices.
