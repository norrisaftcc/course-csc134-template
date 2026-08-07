---
name: F-025-claim-decay-in-one-session
description: Five false claims in one session, none catchable by any gate here. Two went false when the work around them completed, three were never true — including one written into this finding itself. Every one lived on a surface the gates do not walk, and every one was caught by a reader. A process record, not an audit.
---

# F-025 — Five claims went false in one session, and no gate could see any of them

**Date:** 2026-08-07 · **Status:** Recorded · **Scope: our own process**
**Extends:** [[F-019-lpaa-content-gate]] — same defect class, surfaces the gate cannot reach

## What this is, and what it is not

**This is a process record.** It documents how five false claims entered and left this session's
work, with enough detail that someone reconciling findings from another session or another user
can compare against their own run.

**It is not an audit, and it proposes no instrument.** Auditing this repo's claims across
sessions is an outside-context problem — it needs a view of more than one session, which nothing
inside a session has. Recording the shape is what a session *can* honestly do. What follows is
evidence, not a recommendation.

## The five

Two distinct failures, not one, and the difference matters more than the count.

### Class A — the claim went false when the work around it completed

This is [[F-019-lpaa-content-gate]]'s original class: *finishing a piece of work is what makes
the surrounding status text false.*

**A1. A PR description.** #68 opened saying "Two files, 39 insertions, no behaviour change."
True when written. `F-023` was then folded into the same PR on a later commit, making it three
files and 122 insertions. **The PR whose subject was stale claims shipped one in its own
description.** Caught in review.

**A2. An exemplar's prose.** `_storming/exemplars/running-the-bases/README.md` said
`modules/m2/learn.md` "does not contain the word pseudocode" and that "both rails of this seam
are currently unauthored." #69 added the pseudocode section **twenty lines away in the same
diff**. Caught in review.

A2 has the sharper detail: **the author edited that exact sentence in that exact PR**, adding a
citation to its parenthetical, and did not read the main clause the parenthetical hangs off.
Proximity to the change was not protective. It may have been the opposite — the sentence had
just been "handled."

### Class B — the claim was never true

Not decay. Assertion from memory or from the wrong instrument.

**B1. A correction that was itself wrong.** The M2 pseudocode gap was cited as "MLO 2.2 requires
it" — correct against `_storming/CSC-134-learning-objectives.md`. It was then "corrected" to
`MLO-M2.3` after reading `modules/m2/_mlos.md` — also correct, against *that* file. **Both
citations were true; the bare number was the defect.** The correction was announced with more
confidence than the original claim had been.

**B2. A false claim inside a document about false claims.** The first draft of
[[ADR-020-module-mlos-govern-cite-by-slug]] asserted that every module beat already used an
`M`-prefixed citation form, so the ruling would need no sweep. The tree actually holds three
forms — 174 bare, 16 hyphenated, 12 module-lettered — and the module-lettered form existed in
**exactly one file, written the day before, by the same author, who then cited it as
pre-existing convention.**

**B3. A false number inside this finding.** ADR-020 and the first draft of F-025 both reported
"~142 bare citations," in a table whose own row said the count covered *m3–m8 and the LO
document*. The 142 figure came from an earlier per-module tally that had never included the LO
document. The real numbers: **142 in m3–m8, 32 in the LO document, 174 bare, 202 in total.**

B3 happened **while writing the paragraph about B2**, in the document arguing that numbers get
asserted from memory. It was caught by re-running `rg -o` during verification, the same way B2
was — and by then the wrong figure had been copied into four files.

B2 and B3 are the only two caught **before commit**, and both died to a command rather than a
re-reading.

### Not counted: a convention divergence

#69 also shipped callouts with the label on its own line, where `learn.md`'s other five put label
and text on one line. A reviewer caught it. **That is drift against an unwritten convention, not
a false claim**, and folding it in would inflate this finding by one. Recorded here only so a
later reader does not re-add it.

## What every one of them had in common

**None was catchable by any gate in this repo.** Not because the gates are weak — because of
where the claims lived:

| Claim | Surface | Why no gate sees it |
|---|---|---|
| A1 | a PR description | lives on GitHub, outside every tree the gates walk |
| A2 | `_storming/` prose | LPAA checks structural claims about `modules/`, not prose about repo state |
| B1 | a citation in prose | no instrument reads objective numbers |
| B2 | an ADR's own argument | nothing checks a decision record against the tree it describes |
| B3 | a count inside a finding | no gate re-derives a number a document quotes about the repo |

**The detection mechanism in all five cases was a reader or a command — never CI.** Twice an
automated reviewer, twice the author re-running a count before commit, once the author noticing
after the fact. **CI was green for all five**, correctly: nothing they broke was anything CI
measures.

## The one that is not a false claim at all — and matters most across sessions

[[F-024-two-mlo-numbering-schemes]] was written as a discovery. It was not one.

`modules/m0/_mlos.md` carries a banner describing the same collision for M0 — four slots against
three, with the AI-collaboration objective at `MLO-0.4` in one file and `MLO 0.3` in the other.
[[F-015-breadth-pass-recipe]] recorded it on **2026-07-30**, a week earlier.

F-024 found it again on 2026-08-06 and framed it as new. It was found the second time by tripping
over it, and the prior art surfaced only when an unrelated blast-radius grep happened to hit
`F-015`'s text.

**This is a different failure from the other five.** Nothing was false — F-024's content is
accurate. What failed is that a finding already in the tree did not reach the session that needed
it. A claim going stale is a writing problem. **A finding not being found is a retrieval problem**,
and it is the one that scales badly across sessions and across users, because every additional
session adds prior art that the next session has no reliable way to consult.

## For whoever reconciles this against another run

Stated as observations, with no remedy attached:

- **Five false claims, one session, all outside gate coverage.** If another session reports zero,
  the interesting question is whether it had fewer, or looked in fewer places.
- **Proximity did not protect.** The worst case (A2) was a sentence the author had just edited.
  B3 was written into the paragraph describing the same failure.
- **Confidence did not track correctness.** All three Class B claims were asserted more firmly
  than the true statements they replaced. B1 was framed as a *correction*.
- **Both pre-commit catches came from running a command, not from re-reading.** B2 and B3 each
  died to one `rg`. The other three survived every re-reading they got, including A2, which was
  re-read while being edited.
- **A number, once written, propagates before it is checked.** B3's wrong figure reached four
  files between being written and being verified — all within one session, none reviewed.
- **One finding a week old did not reach the session that needed it**, in a tree small enough to
  read end to end.

**No count here is a rate.** One session, one author, one busy day. Whether five is high, low, or
typical is not answerable from inside the session that produced it — which is the point of
reconciling it against others.
