---
name: F-007-m5-deep-build
description: M5 (Loops) deep build — the three missing LPAA beats authored, the Make-gradient seam split inside one Apply session, gate green; M5 Built, not yet Ready
---

# F-007 — M5 (Loops) deep build

**Date:** 2026-07-25 · **Status:** Recorded · **Branch:** `module/m5-deep`
**Predecessor:** [[F-006-m4-fixes-and-ready]] (M4 certified Ready). M5 grows M4's
gatekeeper a loop via `_contracts/m5_menu.cpp` — the seam.

## Starting state was worse than "in progress"

M5 was found as **untracked files on disk** on a branch sitting at main's HEAD
with zero commits. Nothing was recoverable through git; a stray `checkout` would
have destroyed the whole build. First action of this pass was to commit it as-is.

Two defects came with that starting state:

1. **Eight compiled binaries were staged for accidental commit.** `.gitignore`
   covered `*.out` / `*.exe` but nothing catches the *extensionless* binaries a
   single-file `g++ -o prog prog.cpp` produces on macOS/Linux. Fixed by ignoring
   everything under `modules/*/code/` and allowing `.cpp` / `.h` / `.md` back in.
   **This is a course-wide trap, not an M5 one** — every future module's `code/`
   folder had the same hole.
2. **Two practice sources were numbered against the wrong exit-ticket items.**
   `practice-item3-offbyone.cpp` was Item **4** in the ticket, and
   `practice-menu.cpp` was Item **3**. Renamed to `practice-item4-offbyone.cpp`
   and `practice-item3-menu.cpp`, header comments corrected.

## What was authored

Present on arrival: `learn.md`, `practice-exit-ticket.md`, 18 `.cpp` sources.
Missing, and written in this pass:

| File | Beat | Note |
|---|---|---|
| `practice-exit-ticket-key.md` | Practice | Instructor-facing key for all 7 items; filled trace tables; per-distractor feedback; misconception seed bank |
| `apply-tutorial.md` | Apply | **Split-mode** — see below |
| `assess-lab.md` | Assess | Two-part lab + full rubric inheriting `_contracts/rubric-template.md` |
| `code/assess-warmup-starter.cpp` | Assess | New. Part 1 student scaffold (three loop-fundamentals exercises) |
| `code/assess-warmup-reference.cpp` | Assess | New. Instructor-facing Part 1 reference |
| `modules/MODULES.md` | — | Replaced a two-line stub with a real status table + status vocabulary |

## Decisions taken (would otherwise have been drift)

- **The Apply beat is split inside one class session, and this is now written
  down.** `_overview.md` mandated it; the tutorial implements it as Part 1 FULL
  type-in (Level Up Stats) → Part 2 EIGHTY (the 80% menu, one spec'd gap). The
  `apply-tutorial-generator` skill offers only FULL *or* EIGHTY, so the
  frontmatter declares `mode: "SPLIT"` explicitly rather than mislabeling it.
  **M5 is the only module where the gradient shifts mid-session** — this is the
  seam module in the scaffolding sense as well as the code sense.
- **Two failure reps, one per part, each mode-appropriate.** The skill asks for
  one deliberate break. Part 1 breaks code students just typed (`<=` → `<`, the
  off-by-one, Logic, compiler silent). Part 2's Investigate movement runs the
  *provided* unguarded scaffold and watches it spin (Runtime). Recorded in the
  tutorial's instructor notes so it does not read as mode drift.
- **The trace-table artifact lives in both Practice and Assess, at different
  stakes.** `_mlos.md` left this open. Resolved: Practice uses trace tables as
  ungraded scratchpads (the ticket is completion-gated); Assess grades a
  hand-completed one at Badge tier. Producing beats recognizing.
- **`_assess-spec.STUB.md`'s "known trap" is resolved in Practice.** The stub
  asked whether the *why* behind the two-call `cin` recovery gets forced in
  Practice or Assess. Forced in Practice, by exit-ticket Item 6: predict what
  happens when `cin.ignore(...)` is deleted. That cannot be answered by
  pattern-matching the idiom. Assess then requires writing it unprompted.
- **Array-search sits in Assess Part 1, not Part 2 below A tier.** `_mlos.md`
  flagged drift risk into M7 (which owns arrays proper). Resolved: M5 borrows a
  fixed-size array purely as *a sequence to iterate* — no manipulation, no
  passing (there are no functions until M6). Every student meets it once in Part
  1; folding it into the game is the A-tier synthesis ask.
- **Assess starts no blanker than Apply earned.** Per the stub's explicit
  instruction. Part 1's array-search exercise *gives* the walk loop and asks only
  for the search, because students have only ever **read** a search (ticket Item
  7), never written one.

## Gate — compile-warden

Toolchain: Apple clang 21.0.0. Flags: `g++ -std=c++17 -Wall -Wextra`.

| Target | Result |
|---|---|
| 18 pre-existing `.cpp` in `modules/m5/code/` | **CLEAN** — zero warnings, zero errors |
| 13 whole-program blocks in `learn.md` + `practice-exit-ticket.md` | **CLEAN** |
| 3 Mermaid blocks in `learn.md` | **RENDER** (mmdc → 101 KB, 101 KB, 107 KB SVG) |
| Runtime behavior of all 7 exit-ticket items | **Matches the key** (see key's run log) |
| 2 new `.cpp` (`assess-warmup-starter`, `assess-warmup-reference`) | **CLEAN** |
| 3 whole-program blocks in `apply-tutorial.md` | **CLEAN** (5 further blocks are excerpts, no `main`) |
| 1 Mermaid block in `assess-lab.md` | **RENDERS** (108 KB SVG) |
| Every sample-run block in `assess-lab.md` | **CAPTURED, not asserted** — see below |

**No output block in the M5 deliverables is hand-written.** Each was produced by
running the program and pasting the result:

- Part 1's sample run is `assess-warmup-reference` output verbatim.
- The Part 1 starter was confirmed to compile clean *and* produce the visibly
  wrong answers the lab promises ("Rested 0 hours", an empty table, "No rune 22
  in the bag") — the wrong answers are the student's to-do list, so they have to
  be real.
- Part 2's C-tier sample run was produced by actually writing the C-tier
  validation loop into the starter and feeding it `banana`, `9`, `2`, `3`.
  That solution compiles clean and its output matches the lab byte for byte.

One defect was caught this way: the Part 2 sample run originally omitted the
starter's opening line (`You duck into the Adventurer's Rest.`). Asserted output
drifts from real output; captured output cannot.

Every exit-ticket answer was verified by running the program, not by reading it:
Item 1 → 3 lines (B); Item 2 → 3 HP lines (B); Item 3 → 3 banners (C); Item 4 →
9 rows (D/Logic); Item 5 → confirmed hanging under alarm (C/Runtime); Item 6 →
recovery works, and the `cin.ignore`-deleted variant confirmed spinning (B);
Item 7 → found (A).

### Two testing traps worth keeping

Both bit this verification run and are recorded in the exit-ticket key:

1. **The taught validation pattern spins forever at EOF.** Piped stdin runs out →
   `cin >> x` fails → `clear()` clears eofbit → `ignore()` hits EOF again → loop.
   Harmless for a human at a terminal (EOF is not a human), fatal for automation.
   **Every automated run of M5 code needs a hard timeout.** macOS ships no
   `timeout`; `perl -e 'alarm 5; exec @ARGV' -- ./prog` works.
2. **Feed one input per line.** This shell is zsh, which does *not* word-split
   unquoted expansions, so `"5 x 2"` arrives as one line and
   `cin.ignore(..., '\n')` eats the rest of it — silently changing what is under
   test. Use `printf '5\nx\n2\n'`.

## Caught in review: a cognitive-load derailer in A tier

Worth recording as a **generalizable authoring lesson**, not just an M5 fix.

A tier was first drafted as four requirements: ① an M4-style decision inside the
loop, ② a `continue` retry, ③ a fourth menu option that searches a sequence, and
④ a value persisting across turns. It passed every mechanical bar — tiers nested,
each item was observable by running the program, nothing came from a future
module. It looked fine.

It was not fine, and **the problem was not the workload.** Measured against the
reference: ①+② cost 29 lines, ③ cost 26, ④ cost 2. The total is defensible for a
synthesis tier. What was wrong was the **shape**:

- ①②④ tell **one** story — the program remembers what you have, decides what it
  is worth, and sends you back to try again when the answer is impossible. That
  is the M4→M5 seam, which is the entire thesis of the module.
- ③ tells a **second, unrelated** story, and re-assesses a skill every student
  already demonstrated at C tier (Part 1, Exercise 3 *is* a search). A student
  reaching for A would have written a search twice and the seam once — with the
  module's central idea taking up less of the assignment than a review exercise.

The derailer is that ③ pulls attention *off* the thesis at the exact moment the
student is finally equipped to meet it. A tier is where the module's idea should
land hardest; instead the idea was competing for room with a checklist item.

**The rule this yields:** a tier's cost is a weight question, but a tier's
coherence is a *design* question, and the two are easy to confuse. "Is this too
much?" is the wrong review question. Ask **"how many stories does this tier
tell?"** One is right. Two means the tier has no thesis, however reasonable each
half looks alone.

**Cross-check against M4, which got this right by instinct:** its A tier is a
single ask (a branching tree with four or more distinct outcomes and at least one
genuinely nested condition). One idea, pushed further. M5's A tier now reads the
same way. **Any future module whose A tier enumerates independent features should
be re-read against this finding before it ships.**

Fix applied in four places in `assess-lab.md`: the A-tier section (rewritten as
one idea in three inseparable pieces), the tier-ladder row, the instructor notes
(with the reasoning preserved so it is not silently re-added later), and the time
estimate. `assess-reference.cpp` keeps its satchel search — a reference may
exceed the tier it exemplifies, and that is now stated.

## Status: **M5 (Loops) is Built — not Ready**

All four LPAA beats authored, gate green, contracts honored
(`_contracts/m5_menu.cpp` unmodified; rubric inherits the four columns and 8/6/3/3
weights). **No synthetic cohort has taken M5.** Its ledger is a build record, not
a field record — M4 needed a cohort round plus a seven-finding fix pass before it
earned Ready ([[F-005-m4-cohort-round1]], [[F-006-m4-fixes-and-ready]]), and there
is no reason to think M5 is cleaner than M4 was.

**Next:** the M5 cohort round — spawn the persona students, have them take the
module end to end, file findings as tracked issues. Do not certify M5 Ready
before that runs.

Relates to [[ADR-004-two-tier-git-workflow]] (this was build flow: branch + PR),
[[ADR-008-two-tree-module-layout]], and [[ADR-011-descope-stl-and-file-io]].
