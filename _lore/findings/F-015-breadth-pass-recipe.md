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

### M0 — Welcome to Programming

**Artifact:** `modules/m0/learn.md` — *"Welcome to Programming: Three Questions
Before the First Line of Code"*. No `modules/m0/code/`, same as M1.

| Measure | Value | vs. M1 |
|---|---|---|
| Total words | 2,009 | 2,140 |
| Prose words | 1,782 | 973 |
| Flesch–Kincaid grade | **6.3** | 6.3 |
| Gated `.cpp` authored | **0** | 0 |
| Fenced `cpp` blocks | **0** | 0 |
| Mermaid diagrams | 1 (people/processes/technology) | 1 |
| Markdown gate, scoped | `0 blocks … GATE PASSED` | same |

**Prose ratio is not a property of "pre-C++" — it is a property of the subject.**
M1 ran 973 prose words because Markdown syntax is a *reference* and belongs in
tables. M0 ran 1,782 in a shorter document, because its subject is an argument and
arguments are prose. The M1 entry's lesson stands but was stated too broadly: the
thing to match is what the material is, not what the module lacks.

**The spine said "short" twice.** Both the M0 spine section and `_overview.md`
qualify the Learn one-liner with *(short)*. At 2,009 words this is the shortest
breadth-pass reading so far and deliberately so — the instruction was followed
rather than noted.

## Two things M0 tested that M1 could not

**1. The scoped compile gate cannot pass on a pre-C++ module — it exits 2.**

```
$ SEARCH_PATHS=modules/m0 bash .github/scripts/compile-gate.sh
No .cpp files found under: modules/m0
Nothing to gate. This is a configuration problem, not a pass.
```

`compile-gate.sh` treats an empty file list as a **misconfiguration**, which is
right for the case it was written for and wrong for a module that legitimately has
no C++. **This contradicts the literal wording of ADR-016 §8 and ledger §5**
("both must exit 0, pasted into the PR body"). Neither can be satisfied for M0 or
M1, and M1 quietly worked around it by pasting the tree-wide compile result instead.

**Recorded rather than silently patched.** The workaround is correct — tree-wide
compile plus scoped markdown — but the documents say something that cannot be done.
Options: reword ADR-016 §8 and ledger §5 to say tree-wide-compile for pre-C++
modules, or teach `compile-gate.sh` a "legitimately empty" case. That is a ruling,
not a builder's call, and no ADR number has been taken for it.

**2. M0 carries a `SKELETON ONLY` banner M1 never had**, inside its top
"Canonical home" blockquote — a second, separate place claiming nothing is
authored. M1's overview had no such line, so nothing in the M1 precedent would have
caught it, and it is exactly the F-014 §5 failure: a status claim that goes stale
because nobody knew to look. Both banners are now updated. **Check every
`_overview.md` for more than one status claim before assuming the M1 diff transfers.**

## An open question M0 surfaced, deliberately not resolved

**The M0 MLO numbering disagrees with itself across two files.**
`modules/m0/_mlos.md` lists four slots; `_storming/CSC-134-learning-objectives.md`
lists three. The AI-collaboration objective is `MLO-0.4` in one and `MLO 0.3` in the
other — so a citation of "MLO 0.3" is ambiguous. The module file's `MLO-0.1` also
drops the **systems clause** ("people, processes, and technology") that both the
spine and the objectives doc require.

`learn.md` cites the module's own file and teaches the fuller, spine-true 0.1. The
reconciliation decides which document is authoritative for MLO numbering
**course-wide**, so it is a spine-owner call. Recorded in `modules/m0/_mlos.md`'s
banner as an open question. **No ADR number taken** — numbering is contested and
CLAUDE.md forbids grabbing one.

**Cost.** Cheapest module yet in mechanics, most expensive in reading: the spine's
big idea is three questions, and answering only "what is a program" would have
shipped a third of the module while looking complete.

### M3 — Program Basics

**Artifact:** `modules/m3/learn.md` — *"Program Basics: When a Program Starts
Remembering"*, plus **5 gated sources** in `modules/m3/code/`. The first
breadth-pass module with C++ since the M2 pilot.

| Measure | Value | vs. M2 (the other C++ module) |
|---|---|---|
| Total words | 2,187 | 2,617 |
| Prose words | 804 | 1,806 |
| Flesch–Kincaid grade | **7.0** | 6.0 |
| Gated `.cpp` authored | **5** — 4 clean, 1 `EXPECT-ERROR` | 5 — 3 clean, 2 `EXPECT-ERROR` |
| Fenced `cpp` blocks | 5, **all born-compliant** | 5 |
| Markdown gate, scoped | `5 matched, 0 failed, 0 unmigrated` | same |
| Compile gate, scoped | **PASSES** (5 files) | passes |
| Tree-wide unmigrated | **37 — unchanged** | unchanged |

**Born-compliant held on the first C++ module since the pilot.** Five more fenced
blocks entered the tree and the debt did not move.

**The gate caught a real drift, first time in the breadth pass.** The
integer-division listing was written flush-left while the source has it indented
inside `main`. `5 block(s): 4 matched, 1 failed` — with a diff pointing at the exact
segment. This is the same shape as M4's Item 7 fragment (F-016), and it is the first
time the gate has failed on *new* material rather than legacy. **It works.** Worth
recording that the failure mode is not "forgot the annotation" but "annotated and
then didn't match" — the annotation is the easy half.

**The scoped compile gate passes here.** M0 and M1 could not run it at all (exit 2,
"Nothing to gate"). M3 has `.cpp` files, so the trap recorded in the M0 entry is
confined to pre-C++ modules — it is not a general defect in the breadth-pass
instructions, only an unhandled case in them.

**M2's promise is now paid.** M2 taught all four error words but could only
demonstrate three, and said in student-facing text that the **Runtime** example
"arrives later… M3, then M5 in earnest." M3 delivers it: `cin >> torches` handed the
word `lots` leaves `torches` at `0`, and the program prints *"You asked for 0
torches. That comes to 0 gold."* — **no crash, exit 0.** The reading names the shape
plainly: *a program that finishes is not a program that worked.*

That is the first time a named gap in one module has been closed by the next one.
**The pattern of naming gaps instead of inventing demos (M2 entry) is now proven to
close**, not just to defer politely.

**Salvage under ADR-010, in practice.** `assignments/m1/` and `assignments/m2/` hold
spine-M3 content under old numbering. What was actually mined was **one framing** —
the legacy `M2T1_InteractiveMarketplace` "From Static to Interactive" progression,
which became the Stage A → Stage B shape. No text, no code, and no exercise was
ported. Recreate-with-salvage in practice means *the idea travels, the file does
not.* Neither legacy file was modified, per the non-clobber policy.

**A third distinct banner shape.** M0 hid a stale status claim in its top
"Canonical home" blockquote; M3 hides one in a section called **"Contracts
touched"** — *"This is a structure-only skeleton pass — no Learn/Practice/Apply/
Assess content authored."* Nothing in the M0, M1 or M2 diffs would have found it.
**Grep each module for every status claim before assuming the previous module's
diff transfers**; three modules have now had three different hiding places.

### M6 — Functions

**Artifact:** `modules/m6/learn.md` — *"Functions: The Same Program, Findable"*,
plus **4 gated sources** in `modules/m6/code/`.

| Measure | Value | vs. M3 |
|---|---|---|
| Total words | 2,074 | 2,187 |
| Prose words | 1,624 | 804 |
| Flesch–Kincaid grade | **6.7** | 7.0 |
| Gated `.cpp` authored | **4** — 3 clean, 1 `EXPECT-ERROR` | 5 |
| Fenced `cpp` blocks | 5, **all born-compliant, all matched first run** | 5 |
| Markdown gate, scoped | `5 matched, 0 failed, 0 unmigrated` | same |
| Tree-wide unmigrated | **37 — unchanged** | unchanged |

**Every source models the full single-file form.** M6 is where the convention
completes — prototypes at top, `main` in the middle, definitions at the bottom —
so all four `.cpp` demonstrate it, including the deliberately-broken one. A
pre-M6-shaped file in this module would teach against the module.

**Five blocks from four files: `excerpt=` slices the same source twice.**
`learn-read-choice.cpp` is quoted in two places — the extracted function, and the
single line in `main` that calls it. Both matched. That is the first use of two
disjoint excerpts from one source, and it is the natural shape for a refactor
narrative: *here is the thing lifted out, and here is what `main` looks like now.*

**The frozen contract earned its framing.** `_contracts/m5_menu.cpp`'s header says
*"M6 refactors it into functions"*, and it was read, never modified. The reading
lifts its validation loop into `readChoice(int low, int high)` — behaviour
identical, parameters added so a second menu can reuse it. Building against the
frozen contract rather than `modules/m5/code/` also means the M5 cohort round (#21)
cannot invalidate this material.

**The pty rule from M3 was applied first time, and paid.** One run captures three
behaviours — a word rejected, an out-of-range number rejected, a good answer
accepted — which is a better teaching transcript than three separate runs and was
free once the harness existed:

```
Choose (1-3): door
That is not a door. Choose 1-3: 9
That is not a door. Choose 1-3: 2
You chose 2.
```

**The grep-every-status-claim rule paid immediately.** M6 carried the *same* hiding
place M3 did — a *"structure-only skeleton pass — no Learn/Practice/Apply/Assess
content authored"* line inside **"Contracts touched"**, far from the beat map.
Four modules, and the rule caught this one before it shipped rather than after.
**That is the first time a recorded lesson prevented a defect instead of explaining
one.**

**Review round — extraction reveals what was caller-specific.** `readChoice`'s header
claimed *"any other prompt can reuse it"* while the function hard-coded M5's retry
line, *"That is not a door."* Reusable in structure, not in wording — and the reading
repeated the reusability claim, so the artifact undercut its own lesson.

Fixed by genericising the message, and **the fix became the better lesson**: pulling
code out reveals which parts of it were secretly about the caller. The loop was
reusable all along; the sentence was not. The reading now says so — *if you extract a
function and cannot name it without saying "for the menu", some of the caller is still
stuck to it.* Recommended wherever a breadth-pass module demonstrates a refactor.

**An excerpt that shows `main` should start at the includes.** Three M6 listings began
at the prototypes, omitting `#include`/`using`. Each displayed `int main()` and a
`return 0;`, so they **read as complete programs while not being buildable** — and one
of them claimed "exactly one flaw" while, as excerpted, a student typing it would have
hit several. The `reading-generator` skill already requires complete programs; the rule
in practice is: **if the block shows `main`, it starts at the includes.** A fragment
that is obviously a fragment (starting mid-function, like M3's integer division) does
not need them.

**A known fragility, deliberately not fixed: captured diagnostics carry `file:line:col`.**
`learn-break-scope.cpp:27:36:` is accurate today and verified, but nothing checks it —
the markdown gate reads `cpp` fences, not output blocks, so if the source gains a line
the reading goes silently wrong. This was raised in review with a suggestion to strip
the prefix.

**Kept, with reasons.** M2's reading explicitly teaches students to read that prefix —
*"it gives the line, the column, a caret pointing at the exact spot"* — so removing it
would delete a lesson to buy durability. M2 and M4 already show diagnostics this way,
so stripping it in M6 alone would also be inconsistent. **The real gap is that no gate
covers output blocks or compiler messages at all**, which is the same blind spot as
Mermaid rendering and Markdown list rendering. Three gaps now share one shape: the
gates verify provenance and compilation, and nothing verifies *what a page shows*.

**Prose ratio, third data point.** M0 1,782 / M1 973 / M3 804 / M6 1,624 prose words.
The pattern holds and is about subject, not module position: reference-shaped
material (Markdown syntax, type tables) goes to tables; argument-shaped material
(why functions, what a refactor is) goes to prose. **Stop treating the prose count
as a quality signal** — it measures what the subject is made of.

### M7 — Structured Data & Objects

**Artifact:** `modules/m7/learn.md` — *"Structured Data: When One Variable Is Not
Enough"*, plus **4 gated sources**. The densest excerpt use of the pass: **9 fenced
blocks from 4 files**, all matched first run.

| Measure | Value | vs. M6 |
|---|---|---|
| Total words | 1,975 | 2,074 |
| Flesch–Kincaid grade | **7.4** (highest of the pass) | 6.7 |
| Gated `.cpp` authored | **4** — 3 clean, 1 `EXPECT-ERROR` | 4 |
| Fenced `cpp` blocks | **9**, all born-compliant | 5 |
| Tree-wide unmigrated | **37 — unchanged** | unchanged |

**An objective deliberately not carried, and said so.** The spine gives M7 a
five-step arc — arrays → parallel arrays → structs → pointers → classes — and its
Learn line says *"readings"*, **plural**. One First-pass reading cannot honestly be
five. This one walks the first four steps and *names* classes as the destination
without teaching them, so **MLO 7.4 is explicitly not carried** — stated in the
`_overview.md` banner, in `_mlos.md`, and in the ledger row.

This is the first time a breadth-pass module has had to declare an objective **out
of scope for its own beat** rather than partly instantiated. The alternative was a
thin pass over all five steps, which would have been worse: parallel arrays only
teach anything if the reader feels the cost, and that needs room.

**The refactor lesson transferred from code to data, for free.** The parallel-array
program and the struct program produce **byte-identical output**. That is M6's
definition of a refactor — behaviour held still, structure improved — now applied to
data, and the reading points at it directly. Two modules teaching one idea in two
domains, with the identical transcript as the proof.

**Parallel arrays are taught, not skipped, and the spine is right about that.** They
are recorded in the source as a `FUTURE REFACTOR` comment pointing at the struct
file. The reading's line: *you cannot appreciate what a struct buys you until you
have felt what it costs not to have one.*

**Four disjoint excerpts from one source.** `learn-room-struct.cpp` is quoted four
times — the `struct` declaration, the array initialiser, the collapsed signature, and
the by-reference function. M6 established two; M7 shows the technique scales, and it
is what lets a single gated program carry a multi-step narrative without ever being
shown whole.

**Review round — declaring an objective out of scope takes four edits, not three.**
The M7 build stated MLO 7.4 out of scope in `_overview.md`, `_mlos.md`, and the ledger
— and left *"**Say** what a class adds to a struct… (MLO 7.4)"* sitting in the
reading's own **Learning Objectives** list. The one file a student actually reads
still claimed the objective the other three disclaimed.

**The scope declaration has a fourth home and it is the most important one.** Added to
the per-module checklist: when a beat does not carry an objective, the reading's
Learning Objectives list is the *first* place to fix, not the place that gets
forgotten. Reframed here as an explicit preview line beneath the objectives.

**One worked example, one set of numbers.** The array section used a four-room dungeon
while every other section used three, so the reading's own continuity broke at the
first code block. Unified to three throughout — one dungeon, one hazard list — which
also makes the parallel-arrays-to-struct collapse visibly *the same data*. **Cheap to
get right at authoring time and invisible to every gate**, since both versions
compiled and both transcripts were honestly captured.

**A checklist item that outlived its own ruling by six days.** `modules/m7/_mlos.md`
still listed *"Resolving F-001's open question on the STL/`std::string` and File I/O
legacy manifest content"* as open — but **ADR-011 ruled it on 2026-07-24**: both
descoped, neither CCL-required, incidental `string` keeps its woven-in role. Closed
with a pointer to the ADR.

**This is a fourth shape of stale claim**, and the most interesting one: not a status
banner, not a definition, not a transcript — **an open question that was answered
elsewhere and never struck through**. The grep rule finds banners; it does not find
these. Worth a sweep of every `- [ ]` in `_mlos.md` and `_assets.md` against
`_lore/decisions/` at the end of the pass.

### M8 — Capstone Miniproject *(the ninth, and the pass closes)*

**Artifact:** `modules/m8/learn.md` — *"Knowing What to Build: The Design Document"*,
plus **2 gated sources** (stages 1 and 2 of a staged build).

| Measure | Value | vs. M7 |
|---|---|---|
| Total words | 2,112 | 1,975 |
| Flesch–Kincaid grade | **5.7** (lowest of the pass) | 7.4 |
| Gated `.cpp` authored | **2** — both clean | 4 |
| Fenced `cpp` blocks | **2**, both born-compliant `source=` | 9 |
| Tree-wide unmigrated | **37 — unchanged** | unchanged |

**The scope was a judgment call, and this is the record of it.** M8 is the only module
whose spine names **no reading at all**. `_overview.md`'s beat map said so plainly:
*"No new reading content named by the spine for M8 itself — M8 draws on every prior
Learn beat (M0–M7) as its input. The 'reading' at this stage is the student's own
design document once drafted."* ADR-016 §5 meanwhile grants M8 a Learn beat and
nothing else — *"the capstone project, its spec, and its rubric stay out of scope."*

Those two are not in conflict, but they leave the beat's subject undetermined. The
resolution taken: **M8's Learn beat teaches problem formulation — the design document
itself (MLO 8.1)**, not the capstone.

The argument for it, in one line: **the design document is the one thing M8 asks a
student to do that no prior module taught them.** The spine front-loads it, grades it
heavily, and gates implementation behind it — while eight modules of material teach
nothing about how to write one. Every prior module handed the student the problem
already decided. Teaching the funnel (problem statement → user stories → spec →
flowchart) is genuinely Learn material, is *not* capstone content, and closes the
course's problem-solving arc: M0's inputs/process/outputs, M1's Robot Sandwich
precision, M2's flowcharts, all cashed in on the student's own problem.

**A different call was available** — leave M8's Learn beat deliberately empty and
record *why*, which the spine arguably licenses. That would have left the breadth pass
at 8 of 9 with a documented hole, and left the one genuinely-untaught skill in the
course untaught. Flagged here rather than settled quietly: **a spine-owner is entitled
to overrule this and shrink M8's reading to a pointer page.**

**A second thing the spine never taught, now taught.** CLAUDE.md bar #9 requires
staged builds — *"each stage compiles and runs standalone"* — and the course has
**shipped** them since M4 without ever telling students what a stage is or why. M8's
reading defines it (*a version you could hand to someone*), shows stages 1 and 2 as
two gated programs, and gives the reason: **a program that compiled at every step has
never been broken for longer than one change.**

**The staged build gave M8 a compile-gate surface it would not otherwise have had.**
A design-document reading is prose and diagrams; it would have been the third module
with zero gated sources, after M0 and M1. Two real staged programs make bar #9 a
demonstrated fact rather than a builder-facing convention.

**Stage 2 changes stage 1's function signature, on purpose.** `describeRoom(string,
int)` becomes `describeRoom(Room)`. The reading says so and rules it legal: stages may
change shape as they grow; the one rule a stage cannot break is that it compiles and
runs when you stop. Left unsaid, a reader could reasonably infer stages must be purely
additive — which is false and would make staging feel impossible.

**The fourth error word finally gets its module.** M2 named **Logic** and could not
demonstrate it honestly. M8 is where it lands: the error that compiles, runs, and is
wrong — *and the one an AI assistant cannot save you from, because it will faithfully
implement whatever you asked for.* The reading's claim is that **the spec is what
turns a Logic error into a checkable disagreement**, which is also the spine's own
assessment logic (*"we grade the two things AI cannot do for you"*) stated as a
mechanism rather than a policy.

**Stacked on M7's branch, not on `main`.** M8 and M7 both edit `MODULES.md`, the
ledger, and this file. Branching M8 from `main` would have produced three guaranteed
conflicts on shared status files. **Rule for any future parallel breadth work: the
per-module content never collides, the four status homes always do.**

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

**Capture interactive output from a real terminal, not from a pipe.** The rule
"never hand-write output, capture it" is necessary and **not sufficient**. M3's
transcripts *were* captured — from `echo "4" | ./prog`. With stdin not a terminal
**nothing is echoed**, so the captured text showed the prompt running straight into
the program's answer: `How many torches? You asked for 4 torches.` A student typing
at a real terminal sees their own keystrokes on the prompt line, and the answer on
the next one.

Every transcript in the reading was wrong the same way, and a sentence had been
written *explaining* the wrong behaviour — *"the prompt and the answer are on the
same line"* — which would have taught a false mental model of console I/O. Caught by
review on #40, not by any gate.

The fix is to run under a **pty**, and to **wait for the prompt before sending
input** — writing it immediately produces a second artifact, with the echo appearing
*above* the prompt rather than after it:

```python
pid, fd = pty.fork()
if pid == 0: os.execv(prog, [prog])
while b"? " not in out: out += os.read(fd, 1024)   # wait for the prompt
os.write(fd, b"4\n")                                # then "type"
```

**Applies to every module from M3 on** — any beat showing a `cin` program run. M0–M2
are unaffected; they have no interactive input to transcribe.

**Say "do not yet exist," not "do not."** *"This reading exists, the exit ticket and
Apply tutorial do not"* is grammatical by ellipsis and still reads as an unfinished
sentence. On a warning whose whole job is to stop someone handing students a file that
is not there, ambiguity is the one thing it cannot afford.

## Open items carried forward

- **Readability grades in this file are not comparable to each other.** Bar #2 sets a
  10th-grade ceiling and every module row quotes a Flesch–Kincaid number, but **there
  is no script in the repo that computes it** — each module's figure came from an
  ad-hoc measurement, and the tokenisers differ in how they strip fences, tables, and
  inline code. Re-measuring M2 with M8's script gave **5.6** against the **6.0**
  recorded in its row; both are far under the bar, so no module's *verdict* changes,
  but the module-to-module deltas in these tables should not be read as real. **Every
  reading is comfortably under 10th grade; that is the claim that holds.** A committed
  `.github/scripts/readability.sh` would make bar #2 checkable the way bars #1 and #3
  already are — the fourth item on the list of bars with no mechanical check.

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
