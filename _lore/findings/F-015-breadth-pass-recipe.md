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

### M1 — Talk to Computers (and Your Team)

**Artifact:** `modules/m1/learn.md` — *"Talk to Computers (and Your Team): Why Plain
Text Wins"*. **No `modules/m1/code/` directory exists**, and that is the result worth
recording.

| Measure | Value | vs. M2 |
|---|---|---|
| Total words | 2,140 | 2,617 |
| **Prose** words | **973** | 1,806 |
| Flesch–Kincaid grade | **6.3** | 6.0 |
| Gated `.cpp` authored | **0** | 5 |
| Fenced `cpp` blocks | **0 top-level** | 5 |
| Mermaid diagrams | 1 (the markup ladder) | 2 |
| Markdown gate, scoped | `0 blocks: 0 matched, 0 failed, 0 unmigrated` — **PASSED** | 5 matched |

**The pre-C++ shape works, and it is not just "the same minus code."** Two things
came out differently:

**1. Prose-to-table ratio flips.** M1 is 973 prose words against M2's 1,806, but only
477 total words shorter. The difference is tables: Markdown syntax is genuinely a
reference, and a syntax table teaches it better than paragraphs do. The
`reading-generator` skill's 1,500–2,500 target counts the document, not the prose, and
M1 sits inside it at 2,140. **Do not pad a pre-C++ reading to hit a prose number** —
the number that matters is whether the objectives are covered, and M1's are.

**2. PRIMM's Predict beat survives without code.** The skill frames predict-the-output
around a program. M1 has no program, so the predict moment is *predict-the-render*:
here is Markdown source, say what it will look like before you scroll. It exercises the
same habit — commit to an answer, then check — and it has its own misconception to
catch (more `#` means *smaller*, and the blank line before a list is load-bearing).
**Recommended for M0**, which is the other pre-C++ module.

**A nested-fence result worth knowing.** Teaching code fences means showing a ` ```cpp `
block *inside* a Markdown listing. Written as a four-backtick outer fence, the gate
correctly reports **0 blocks** — it reads nested fences the way a renderer does, so the
inner fence is content, not a listing to verify. That path had a self-test but had never
met real material; it holds.

**Cost.** The cheapest module so far by a wide margin — no `.cpp` to author, gate, or
run, and no captured output to verify. Boundary research was still the expensive part,
and still does not amortise.

---

## Authoring rules learned the hard way

**The instructor note goes *after* the whole list, never between items.** Every
breadth-pass Learn beat ends with a `> **📋 Instructor note — not yet authored.**`
blockquote, because `First pass` means the beats it routes to do not exist yet. On M2
that blockquote was placed between list items 2 and 3 — **which silently terminates the
numbered list.** Item 3 then starts a *new* list and renders as "1". It shipped to
`main` that way and was caught on the M1 review, not by any gate.

Nothing checks this. The markdown gate reads provenance, not rendering, and there is no
Markdown linter in CI. **Put the note below the last item, and eyeball the rendered list
in the PR's Files-changed view** — the same manual check Mermaid needs (bar #5).

**Say "do not yet exist," not "do not."** *"This reading exists, the exit ticket and
Apply tutorial do not"* is grammatical by ellipsis and still reads as an unfinished
sentence. On a warning whose whole job is to stop someone handing students a file that
is not there, ambiguity is the one thing it cannot afford.

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
