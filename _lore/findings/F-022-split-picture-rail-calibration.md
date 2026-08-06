---
name: F-022-split-picture-rail-calibration
description: Three builders wrote the same spec from three slices of the picture. Nobody got all six held-back requirements, the interview rail lost on Audience despite twelve questions, and the cause is that a well-documented repo pre-answers the question an interviewer would have to ask.
---

# F-022 — Split-picture calibration of the pseudocode and interview rails

**Date:** 2026-08-06 · **Status:** Recorded · **Run:** `wf_04ad828a-c90` · 10 agents, 0 errors, 14m14s
**Extends:** [[F-020-haiku-ladder-calibration]] · **Instrument for:** `_storming/exemplars/running-the-bases/`

F-020 gave every agent the same page and diffed the artifacts. This run gives each agent a
**different slice of the picture** and diffs the specs. F-017 collected opinions and found
convergent approval is the weakest evidence this process makes; F-020 collected artifacts;
this one collects artifacts built under **deliberately unequal information**.

**Method.** Three builders wrote a spec for the same unbuilt deliverable — the missing
pseudocode section of `modules/m2/learn.md`. One could read the repo and had no customer.
One could read nothing and had a customer who answered only what was directly asked. One had
both. A customer agent held **six requirements and volunteered none of them.** Three judges
then scored against those six through separate lenses. Scoring was compared in-script; the
six were fixed before the run.

## Headline

| | pseudocode-only | interview-only | both |
|---|---|---|---|
| Requirements produced | 29 | 33 | 30 |
| Questions asked | **0** | 12 | 8 |
| Held-back requirements found | **4 / 6** | **5 / 6** | **5 / 6** |

**Nobody got six.** Twelve questions bought one requirement over asking nothing at all.

## The result that falsifies our own exemplar

`running-the-bases/README.md` claimed the interview rail is *"strong on purpose — two
questions get you the Audience and the boundary."* **That is false, and this run measured it
false.**

All three specs missed *"the instructor is a second audience."* The interview rail missed it
**worst**: `interview-only` R26 requires that the section add no instructor content "by
default," and its R3 forbids touching any other module file — so the material the customer
wanted has nowhere to land. Twenty interview questions across two rails, and **not one asked
who else reads the page.**

**The cause is structural, and it is the finding worth keeping.** The repo pre-answers the
question. Bar #10, [[ADR-017-apply-beats-are-written-to-the-student]], and
[[F-018-apply-beat-audience-boundary]] all encode *written to the student* as the invariant,
and F-018 records instructor content leaking as **the failure**. A builder who reads
`CLAUDE.md` and then asks "who reads this?" has already been told. The question reads as
settled, so nobody asks it — at twelve questions, eight, or zero. All three specs treat
instructor content as a **hazard to fence**, never as a reader to serve.

> **A strong convention camouflages the requirement it is adjacent to.** No number of
> interview turns fixes that. Only the customer volunteering it would.

This is the same shape as F-020's two gaps: the defect lives *between* artifacts, not inside
one. Here it lives between the convention and the requirement.

## What each rail actually cannot discover

**The pseudocode rail's blind spot is quantities and intentions.**

- *The number.* `pseudocode-only` contains no length requirement at all. Nothing in the repo
  emits "2,200." A number the customer holds is not derivable from the tree.
- *"Not yet" versus "on purpose."* Its R13 gets the behavior right — no user stories,
  grep-checkable — but a repo read cannot distinguish *MLO-M2.4 is unfinished* from *it is
  deliberately excluded here*. Only `interview-only` R2 converts it into a recorded decision
  and requires that a reviewer **still find user stories missing** afterward. That clause is
  an assertion of intent, and no amount of reading produces it.

**But its strength is larger than we credited: structure already committed to disk.**
Placement, file identity, gate mechanics, status hygiene — all derived correctly, in more
mechanical detail than either interviewed spec. Its R18 cites `markdown-gate.py:126` for why
a pseudocode block must not be fenced `cpp`. That is the best-evidenced requirement in any of
the three, and it came from zero questions.

**One held-back requirement was never hidden.** `pseudocode-only` named both neighbors
exactly — `### The program, drawn` and `### What the compiler actually does` — with a grep to
check it. The file admits one slot, because the C++ listing and the Mermaid diagram are the
same four-statement program, so the third view has one place to go. **Asking bought nothing
here.** Both interviewed rails landed on the identical slot.

## Where the interview rail actively did damage

Interviewing is not free, and this run priced it.

- **`interview-only` R9 and R11 are jointly unsatisfiable.** R9 orders the builder to match a
  convention at `_past_work/materials/legacy/m2/m2.md:103-119`, described as "lowercase
  plain-English lines." The actual lines are `// Declare variables` — C++ comment syntax. R11
  then bans `//` and supplies a grep that rejects what R9 mandates. The spec cited a range and
  characterized the wrong lines inside it. **An interview produced that, not a repo read** —
  and it promotes a `_past_work` convention that ADR-008 marks frozen and non-governing.
- **`pseudocode-only` R10 mandates a visible keyword list** the customer had already ruled
  out. Deferring the *content* of a list while requiring the *list* forces a shape onto the
  page. Two rails made the correct move instead: reserve the decision.

## The quantity requirement nobody could check

The customer wanted "~2,200 words." Three defensible counts exist:

| Method | Count |
|---|---|
| `wc -w modules/m2/learn.md` | 2,620 |
| frontmatter and fences stripped | 2,302 |
| **the repo's own editorial gate** (also strips tables, headings) | **2,056** |

**On the only word-counting instrument the repo actually owns, the file is already under
budget.** `both` R16 asserts its method as fact and demands trimming 650–700 words — a
quarter of a passing reading — to satisfy a number the repo's own tool disagrees with.
Neither interviewed rail surfaced 2,056.

> **A quantity requirement without a named instrument is uncheckable, however checkable it
> looks.** The floor test's Scope noun needs a unit *and* the thing that measures it.

Related: `_tracking/breadth-pass-ledger.md` claims M2 is "1,806 words," which matches none of
the three. Recorded here, not fixed — F-015 says the breadth-pass figures were measured
ad-hoc before a committed script existed.

## What changed as a result

`README.md` and `WORKED.md` in `_storming/exemplars/running-the-bases/` had their rail table
corrected in the same PR. The old table credited the interview rail with Audience; the
measurement says it earns Scope and Format, and that **Audience is unreliable on both rails**
when a convention already speaks to it.

## What this method cannot see

Same caveat as F-020, carried forward deliberately. **This measures what a slice of
information yields, not whether the resulting section teaches anyone anything.** Every spec
here is untested against a student. Only a cohort round measures that.

One further limit specific to this run: **the six held-back requirements were chosen by the
same person who wrote the exemplar.** A scoreboard against my own six is evidence about
coverage, not about whether those were the right six.
