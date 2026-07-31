---
name: F-016-m4-fence-migration-partial
description: The first real payment on issue #30 — a student-facing M4 program that no gate had ever built is now gated, and M4's exit ticket is fully migrated. Corrects F-013's bucket sizing with measured numbers.
---

# F-016 — Paying the half of #30 that was not bookkeeping

**Date:** 2026-07-29 · **Status:** Recorded · **Branch:** `phase0/m4-fence-migration-partial`
**Acts on:** #30 · **Convention:** [[ADR-015-markdown-blocks-mirror-gated-source]] ·
**Context:** [[F-013-markdown-blocks-are-unversioned-copies]], [[F-014-breadth-pass-state-audit]],
[[ADR-016-breadth-first-pass]]

## Why now, and why only half

ADR-016 deferred #30 behind the breadth pass. That was right for one PR at a time. It
stopped being right at two: PR #35 and PR #36 both carried a red `markdown blocks`
job, and the fan-out would have taken it to four or more. **A red job that every PR
carries is a red job nobody reads** — which is the failure the workflow's own comments
warn about, and it would have arrived exactly when born-compliant most needed a signal
that means something.

So: pay the part that is not bookkeeping, defer the part that is.

## 1. The defect — student-facing C++ no gate had ever built

`modules/m4/practice-exit-ticket.md:60`, Item 1.5's "Bridge" program, was a **complete
C++ program with no `.cpp` twin anywhere.** `modules/m4/code/` held
`practice-item1-vault.cpp` for Item 1 and nothing for Item 1.5. It sat inside a module
**certified Ready** (F-006), in a completion-gated beat students must pass.

The answer key had already noticed and left a note:

> *"Item 1.5 bridge snippet is inline (not yet a code/ file)… compiled clean with zero
> warnings under -Wall -Wextra when this beat was updated. If it graduates to code/, add
> `practice-item1_5-mana.cpp` and fold it into the canonical run."*

That note is the finding in miniature. The claim was **true and unverifiable** — someone
did compile it once, by hand, and nothing carried that forward. It is the same shape as
F-009 (a compiler claim that stopped holding) and F-014 §5 (a status banner that stopped
matching): *a fact checked once, then trusted forever.*

**Fixed:** authored as `modules/m4/code/practice-item1_5-mana.cpp` — **the filename the
key itself proposed**, so the note comes true rather than needing a correction. Gated:
clean, zero warnings. Run: prints `You cast a minor spell.`, matching the key's answer B
and its filled trace table. The listing now mirrors it via `excerpt=`, and the key's note
and canonical-run list are updated to match.

## 2. Bucket sizing — F-013's estimate was close but not right

F-013 put six listings in the "already match on code, just drop the header" bucket. Measured
by matching every M4 block against every gated source programmatically, the real split is:

| Shape | Count | Fix |
|---|---|---|
| Exact contiguous match already | **4** | Add `excerpt=`, nothing else |
| Match except a **compressed header comment** | **2** | `learn.md` had squashed a 3-line file header to one line |
| Match except **de-indentation** | **1** | The page stripped the 4 spaces the fragment has inside `main` |
| No `.cpp` at all | **1** | §1 above |

So **eight**, not six, and three of them needed more than adding an annotation. The
estimate was not wrong about difficulty — every one of these was minutes, not hours — but
"already match" was doing more work in that sentence than it could carry. **Worth knowing
before someone schedules the rest of #30 off F-013's numbers.**

**On the two compressed headers.** `learn.md` labelled its staged builds inside the code
block — `// learn-gate-strength.cpp — Stage A` — where the file carries a fuller three-line
header. The cheap fix is to drop the line, but the Stage A/B label is load-bearing: CLAUDE.md
bar #9 makes staged builds a requirement, and the label is how a reader sees the stages. So
the label was **lifted into the prose above the fence** instead — a bold *Stage A* followed
by the filename in a code span, on its own line directly above the listing. The information
survives, the listing becomes a clean excerpt, and the page arguably reads better: the label
is now visible before the code rather than buried in its first line.

**On the de-indented fragment.** Item 7's chain was shown flush-left; in
`practice-item7-status.cpp` it lives inside `main` with four spaces. Re-indenting the
listing to match is the whole fix. Nothing is lost — the fragment is *more* honest indented,
because that is where it actually lives.

## 3. The countdown

| | Unmigrated | Matched |
|---|---|---|
| Before | 45 | 0 |
| After | **37** | **8** |

**`modules/m4/practice-exit-ticket.md` is fully migrated** — it has left the countdown
entirely, the first file in the repo to do so.

Compile gate: 33 files, 32 clean, 1 expected (marked). Markdown gate self-tests still pass
in both directions — the gate can still go red.

## What is deliberately left

**37 blocks**, and the shape of the remaining work is genuinely different from what was
paid here:

- `apply-tutorial.md` × 2 modules, 16 blocks — **the staged builds.** These are *shorter
  whole programs*, not slices of the finished file, so each stage needs its own gated
  `.cpp` (`apply-gatekeeper-stage1.cpp`, `-stage2.cpp`, …). This is the bulk of #30 and the
  only part that is real authoring rather than annotation. It also converts bar #9 from an
  assertion into a checked fact, which is worth doing properly rather than quickly.
- `learn.md` × 2 modules, 12 blocks — fragments and the deliberately-broken one-liners,
  which need `EXPECT-WARNING`/`EXPECT-ERROR` files behind them.
- `assess-lab.md` × 2, 2 blocks.
- `m5/practice-exit-ticket.md`, 7 blocks — likely the same easy shapes as M4's were; M5 was
  never measured the way M4 was here.

**The gate stays red.** That is correct and unchanged: the remaining 37 are still
unverifiable, and red is what unverifiable should look like.

---

## Closed: #30 is paid in full (2026-07-31)

**71 blocks, 71 matched, 0 unmigrated. The markdown gate is green** — the first time since
it shipped. It went 45 → 37 (#37) → 18 (#44) → **0**, and it is now a regression test
rather than a countdown: a new un-annotated block fails it on arrival.

### The remaining work was mis-sized here, in both directions

The section above predicted the 37 as "16 staged builds + 12 learn.md fragments + 2
assess-lab + 7 exit-ticket, likely easy." Measured against the actual `.cpp` files, the
split was different:

| Predicted | Actual |
|---|---|
| `m5/practice-exit-ticket.md` "likely the same easy shapes" | **Correct** — 6 exact excerpts, 1 near-miss. Whole file migrated in minutes. |
| `learn.md` × 2 = 12 blocks of broken one-liners | **Half wrong.** M5's six were whole programs with trimmed headers (elision, minutes). M4's six had **no gated file anywhere** and needed five new sources. |
| 16 staged builds, "the bulk of #30" | **Wrong by half.** Only **7** were true stages needing new files; the other 9 were exact excerpts of sources that already existed, or one-liners. |

**Both errors came from estimating by file name instead of by content.** `apply-tutorial.md`
was assumed to be all staged builds because that is what an Apply beat mostly is; it also
contained four break-it exercises and four already-matching excerpts. The lesson from
F-013 and from this file's own top section keeps re-proving itself: **measure the blocks,
do not count the files.**

### Bar #9 is now a checked fact

Seven staged-build programs exist that never did — four for M4's gatekeeper, three for
M5's level-up table. Every one compiles clean under the course flags **and was run** to
confirm behaviour actually accumulates:

- M4 stage 3 → stage 4: a Rogue with a lockpick takes a branch stage 3 did not have.
- M5 stage 1 → 2 → 3: banner, then headers, then ten rows.

The compile gate can prove a stage builds. It cannot prove a stage *runs*, or that stage
N+1 does more than stage N — those were checked by hand and are worth re-checking by hand
whenever a stage is edited.

**`// NEW` markers live in the `.cpp` files.** The tutorials mark each stage's additions
with a trailing `// NEW`, and ADR-015 requires exact text, so the markers had to go
somewhere. Putting them in the source is the right call twice over: bar #9 already says
*"mark the stages in comments,"* and a stage file whose markers disagreed with the printed
listing would be the exact defect this gate exists to catch. The invariant the files hold:
**at stage N, only stage N's lines carry `// NEW`.**

### Two files broken on purpose that no compiler will ever complain about

`apply-break-swapped.cpp` (M4) and `apply-break-and-validation.cpp` (M5) are the first
deliberately-wrong files in the repo that are **NOT** marked `EXPECT-WARNING` — because
there is nothing to warn about. Both compile perfectly clean under `-Wall -Wextra`:

- `&&` where `||` belongs: the condition is never true, so the validation loop never runs.
- An if/else-if ladder with the branches out of order: a strength-90 hero is told they are
  "borderline", verified by running it.

They needed a header explaining *why the absence of a marker is itself the assertion*,
because a future reader finding an unmarked broken file will reasonably assume someone
forgot the marker. **A clean-compiling wrong program is the sharpest available teaching
example of the fourth error word**, and the gate now holds both of them in place.

### Stale-claim sweep

Closing the debt made two status claims false, both fixed here:

- `.github/workflows/compile-gate.yml` — the job comment read *"EXPECTED RED until M4's 23
  blocks are migrated."*
- `ADR-015 §6` — *"the gate ships enforcing, and `main` goes red."* The decision text
  stands as the record of why; a status note now says the state it describes is over.

This is the **fifth shape of stale claim** in the ledger, and the first that lives in
**CI configuration** rather than in prose: a comment on a job that tells the next reader
to expect a failure that can no longer happen. Grep for status claims does not reach into
`.github/` unless someone thinks to look there.
