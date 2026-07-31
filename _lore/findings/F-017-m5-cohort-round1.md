---
name: F-017-m5-cohort-round1
description: M5 (Loops) cohort dry-run round 1 — three personas took the module end-to-end; verdict ready-with-fixes, four should-fix, and the round itself was too easy to certify anything
---

# F-017 — M5 (Loops) cohort dry-run, round 1

**Date:** 2026-07-31 · **Status:** Recorded · **Branch:** `cohort/m5-round1-results` · **Issue:** #21
**Roster:** Maria (literalist, sonnet), Dee (rules-lawyer, sonnet), Jaylen (skimmer, haiku) —
the three approved personas ([[F-003-module-skeleton-and-persona-review]]).
**Synthesizer:** cohort-lead (opus). Ran as the `m5-cohort-round1` workflow, students in isolated
worktrees with the real `g++` 13.3.0 toolchain. Plan frozen before execution in
`_tracking/cohort/m5-round1/PLAN.md` (merged as #47). Verbatim transcripts alongside it in
`feedback.md`.

## Verdict: `ready-with-fixes` — four should-fix, zero blockers

No code defect. All 26 files in `modules/m5/code/` compile clean on GCC, both repo gates pass, and
the synthesizer independently reproduced the tutorial's documented Part 2 session (`x,1,1,80,3`)
character-for-character.

## The verdict's own caveat, which outranks it

**This round was too easy and must not be read as evidence M5 is sound.** All three personas
compiled clean on first try, all three scored **7/7 cold** on the exit ticket with *identical*
answer strings (`1B 2B 3C 4D 5C 6B 7A`), and not one produced the `&&`-for-`||` error the lab names
as its highest-yield failure.

Convergent approval from three language models reading a document they held **fully in context** is
the weakest evidence this process makes. F-005 said something similar about M4; this round makes it
concrete, because the mechanism is now visible (below).

## The four should-fix

1. **Part 2's scaffold hands students `continue` before anything teaches it.**
   `apply-tutorial.md` Movement 1 tells students to read the scaffold before writing anything and to
   trace a path line by line. Line 75 of that scaffold is `continue;`. The keyword appears **nowhere**
   in `learn.md` and nowhere in `apply-tutorial.md`'s prose — its only explanation in the module is
   `assess-lab.md`'s A-tier requirement, a file the student has not opened yet.
   *Verified:* `grep` for `continue` across `modules/m5/` returns three source hits plus the A-tier
   text; zero in `learn.md` or `apply-tutorial.md`. *(Maria.)*
   **Fix:** two sentences in Movement 1 naming what `continue` does — and that in a `do`/`while` it
   jumps to the `while (...)` at the **bottom**, not the top of the body.

2. **B tier requires "bad range re-prompts" but publishes no range, and never tests one.**
   The menu read's range is pinned by having three options. The barkeep's number has nothing pinning
   it — no range in the requirement, the sample runs, or the Testing table. The table's only B-tier
   row sends `banana`, which exercises *type*, not range. **A submission validating type only would
   pass every test a student is told to run while failing the requirement sentence a grader reads.**
   *(Dee, corroborated by three-way divergence.)*
   **Fix:** publish a range (0–100, matching `assess-reference.cpp:79`) and add an out-of-range row.

3. **Exit-ticket Item 7 is the first place a student ever meets array syntax.**
   Item 7 contains `int potions[5] = {...}` and `potions[i]`. `learn.md` contains **no square
   brackets at all**. The stem says "slot" but never connects the word to the syntax, or says slots
   count from 0. *(Maria — with the "out of scope" half of her claim rejected, see below.)*
   **Fix:** one sentence in the stem glossing the syntax, or the same gloss in `learn.md`'s `for` section.

4. **The rubric's Submission row contradicts the Badge tier on `prompts.md`.**
   The row says `prompts.md` is required "if AI was used"; Badge two headings earlier says submit it
   unconditionally and gives explicit no-AI instructions. *(Dee.)*
   **Fix:** "`prompts.md` present as the attempted tier requires."

### nits

5. **The exit-ticket key certifies compiler silence from a macOS toolchain.** The key's compile log
   reads *"Toolchain: Apple clang version 21.0.0"* followed by *"ZERO warnings, ZERO errors on all 18
   files."* That is the assertion **ADR-014 forbids** — never assert compiler silence from a macOS run.
   The claim may well be true on GCC; it is not evidenced by what is written.
6. **The `&&` trap is explained in the student handout, then called the highest-yield thing to look
   for.** The full explanation sits in Troubleshooting (student-facing; the instructor-only boundary
   starts later), so a student who reads the lab top-to-bottom is inoculated before writing a line.
7. **Round 1 produced no data for the seeded misconception bank.** The bank is labelled
   *"seed — grow after first cohort run."* 21 of 21 items correct means it is **unchanged after round 1.**

## The mechanism behind "too easy" — and it is measurable, not a hunch

**Read-ahead deleted the round's best finding for the persona best equipped to find it.**

Dee read `learn.md`, `apply-tutorial.md` and `assess-lab.md` in full before writing any code. That
means he met `assess-lab.md`'s A-tier explanation of `continue` **before** he met the bare keyword in
the Part 2 scaffold — so the hole was already filled by the time he reached it. Maria found the gap
only because she went in order and refuses to read past a token nothing taught her.

The students were handed the whole module at turn one. **The fix is not a bigger model or another
persona; it is information discipline** — release the beats one at a time, take the report, then
release the next. Same agents, same budget, strictly more signal. This is the single highest-value
change for round 2 and it costs nothing.

## Break-character — one disclosed, one not, and the undisclosed one is the problem

- **Dee disclosed his**, in the most useful way a persona can. His read-ahead compromises every
  predict-then-reveal moment in Learn and Apply; he protected the one measurement that mattered by
  writing the seven exit-ticket answers cold first. **His praise is disqualified; his two contract
  findings are not** — reading three documents against each other is exactly the procedure that
  surfaces them.
- **Jaylen reported "none," and that is the flag.** A skimmer persona who produced zero confusions,
  zero bugs, and 7/7 cold — *including Item 6, the item built specifically to catch a reader who
  skimmed the two-call `cin` recovery* — did not skim like a student. He pattern-matched a document
  held in full context. He also closed with *"No trick questions, just clean work,"* echoing the
  module's own policy back at it: the F-005 signature by name. **His clean run is not evidence M5 is
  skim-proof.** He filed no findings, so nothing here rests on him.
- **Maria disclosed two procedural slips** and was careful not to fabricate friction she never met —
  her Chromebook-only constraint does not bind in a sandbox with a terminal. That disclosure is
  load-bearing: it is the main reason the 90-minute estimate cannot be judged from this round.

## Model-noise filtered — 7 claims rejected

Required by the plan, and an empty list would have been suspicious. Highlights:

- **Maria: "three student-facing places assume `git pull`/`git push` just work, and all three
  failed."** Rejected as a **harness artifact** — her own quoted error names the worktree branch the
  round spawned in, not a student repo. *But it leaves a real operational note: worktree provisioning
  for cohort runs does not set upstream tracking, and a future round that tests the submission flow
  will hit this again.*
- **Maria: "Item 7's array is out of scope; M7 owns arrays."** Half-rejected — the key answers this
  directly and by name (*"intentional and spine-sanctioned: the M5 Assess line names array-search
  explicitly"*). The scope objection dies; the **untaught-syntax** half survives as should-fix 3.
- **Jaylen: "No trick questions, just clean work."** The document's own stated policy reflected back.
- **Maria and Dee: the four-beat sequence reinforces the pattern so well that "by the fourth exposure
  it's not memorization."** The material *announces* this outcome in two places, so agreement is
  circular.
- **Dee's "unusually tight" verdict** — disqualified by his own read-ahead disclosure.

## Watch-list answers (all six, including the unglamorous ones)

| # | Question | Answer |
|---|---|---|
| 1 | Does the SPLIT Apply session land? | No mode confusion observed, **but this round cannot establish it** — all three read the tutorial through, and the shift is signposted in a heading. The real friction is sharper: the first act of the new mode contains the `continue` hole. |
| 2 | Is A tier overloaded? | **No**, on this round's evidence. Two of three completed all three pieces, one inside the published 35-minute budget; the third stopped at B on time, not comprehension, and described the three pieces correctly as one refactor. **No finding promoted** — argument is not evidence. |
| 3 | Did anyone write `&&` for `||`? | **No. The prediction is unearned by round 1 and recorded as such.** Likely *unfalsifiable* by document-reading agents: the correct idiom appears verbatim four times in the module. The synthesizer re-compiled the trap itself — zero diagnostics, and `banana` prints `You chose 0.` exactly as claimed. |
| 4 | Is the ~90-minute C-tier estimate right? | **No evidence either way.** All three ran far under — and that data must **not** be used to lower it. Machine typing speed, local toolchain, no cold start, no debugging loop. Leave it alone until humans run it. |
| 5 | Do exit-ticket Items 4 and 5 land as a pair? | **Yes**, but at a ceiling that says little. All three answered 4=D / 5=C, one reproducing the key's own framing unprompted. 21/21 correct means zero data for the misconception bank. |
| 6 | Does anyone fill in the trace tables? | **Yes — two of three, voluntarily, and both reached Badge.** Jaylen filled none and stopped at B. **The design holds; no revisiting needed.** Caveat: voluntary use by an agent that could just run the program is a weak proxy for a student who cannot. |

## Operational lessons for the next cohort round

1. **Gate the beats.** Release `learn.md`, take the report, then release the next. Read-ahead is
   measurably destroying findings. Costs nothing; biggest single win.
2. **One model tier across the cohort.** Jaylen was the only student on haiku and produced zero
   findings — so *thin-because-skimmer* and *thin-because-small-model* are confounded and his run is
   unusable as evidence. F-005's rule was "escalate the literalist and any deep-audit persona"; the
   honest extension is that tier should not vary **within** a cohort at all.
3. **The roster cannot fail.** Three approved personas, all pass everything, misconception bank still
   empty. A persona that genuinely gets stuck — wrong prior knowledge, a defended off-by-one — needs a
   new sheet and human sign-off (F-003) before it can run.
4. **Worktree provisioning does not set upstream tracking.** Harmless this round because submission
   was out of scope; blocking for any future round that tests the submission flow.

## What this round did NOT do

Filed no issues, fixed nothing, did not touch `modules/MODULES.md`, and **did not certify M5 `Ready`.**
#21 is explicit that this round is necessary before `Ready` — it is not sufficient. The four
should-fix must close first, in a follow-on PR, under human review.
