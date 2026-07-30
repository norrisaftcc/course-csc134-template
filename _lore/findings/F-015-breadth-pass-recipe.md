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
