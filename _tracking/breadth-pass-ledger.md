# Breadth-pass ledger — a Learn beat in every module

**Ruling:** [[ADR-016-breadth-first-pass]] · **Audit:** [[F-014-breadth-pass-state-audit]]
**Opened:** 2026-07-29 · **Status:** in progress

The work list for getting all nine modules to a state where a human can open **any** of them and
review a real artifact. `modules/MODULES.md` is the reviewer's index; this file is the builder's
work list and the ranked backlog behind it.

> **Status vocabulary is `modules/MODULES.md`'s**, plus one tier this pass introduces:
> **`First pass`** — Learn beat authored and gate-green, nothing else. Not `Built` (all four
> beats), not `Ready` (cohort-tested). See ADR-016 §2.

---

## 1. The work list

| # | Module | Title | Gradient | Status | Learn beat | Notes |
|---|---|---|---|---|---|---|
| — | **M4** | Decisions | type-in 100% | **Ready** | ✅ | Calibration reference. `learn.md` + 3 gated `learn-*.cpp` + composed Canvas pages |
| 1 | **M5** | Loops | SPLIT (FULL→EIGHTY) | **Built** *(in PR #20)* | ✅ | Unblock and merge — see §2 |
| 2 | **M2** | How to Solve Problems | type-in 100% | Skeleton | ☐ | **Pilot.** See §3 |
| 3 | **M1** | Talk to Computers (and Your Team) | pre-gradient | Skeleton | ☐ | Wave A — largely pre-C++ |
| 4 | **M0** | Welcome to Programming | pre-gradient | Skeleton | ☐ | Wave A — largely pre-C++ |
| 5 | **M3** | Program Basics | type-in 100% | Skeleton | ☐ | Wave B — **recreate-with-salvage** (ADR-010) |
| 6 | **M6** | Functions | finish-the-80% | Skeleton | ☐ | Wave B — first full single-file form |
| 7 | **M7** | Structured Data & Objects | finish-the-80% | Skeleton | ☐ | Wave C — respect ADR-011 descope |
| 8 | **M8** | Capstone Miniproject | spec-only | Skeleton | ☐ | Wave C — **Learn beat only**, no capstone content |

**Done overall:** every row at `First pass` or better, every module's `compile` job green on GCC in
CI, and no growth in the markdown gate's violation count from new material.

---

## 2. Step 1 — unblock M5 (PR #20)

M5 is complete and its two review items are closed. It has been held open only by #21, the cohort
round, which ADR-016 defers.

- [x] Merge `origin/main` into `module/m5-deep` — clean, no conflicts (`07d2408`)
- [x] Let CI run **for the first time** — PR #20's base predated the compile gate (F-014 §2)
- [x] `compile` job **green on GCC**: 32 files, 31 clean, 1 expected (marked). All 20 M5 sources clean
- [x] `markdown` job went 23 → **45** unmigrated, exactly as predicted. Pre-existing debt arriving,
      not a regression (F-014 §3)
- [x] Reported on PR #20; **awaiting human merge** (ADR-004: human review at every PR)
- [ ] Fix on the way through: `MODULES.md` rows for M2 and M3 read "First Programs" and
      "Arithmetic & I/O"; the spine titles are **"How to Solve Problems"** and **"Program Basics"**
- [ ] Add the `First pass` row to `MODULES.md`'s status-vocabulary table

## 3. Step 2 — pilot the recipe on M2

M2 is the pilot because it stresses the recipe hardest: first `g++` invocation in the course, home
of the **four-word error taxonomy**, and an Apply beat that breaks a program on purpose — which
exercises the `EXPECT-ERROR` / `EXPECT-WARNING` markers and the ADR-015 "excerpt of a marked file"
path together. Survive M2 and the recipe survives every C++ module.

- Branch `module/m2-learn` (ADR-004 build flow)
- `reading-generator` → `course-content-writer` → `linx-voice-readability-editor` → `compile-warden`
- **Pre-M6 incomplete form**: everything in `main`, no functions, no prototypes (CLAUDE.md bar #3)
- **No legacy to port** — `modules/m2/_assets.md` records that `assignments/m2/` holds drifted
  content belonging to spine **M3**. Quarry it for M3, not M2.
- Compose to `_outputs/canvas-html/m2/` — pilot only, to prove the compositor still derives cleanly
  from a fresh source (ADR-012)

## 4. Step 3 — the waves

One PR per module. Batching would destroy the exact thing this pass exists to buy.

| Wave | Modules | Why grouped |
|---|---|---|
| A | M1, M0 | Largely pre-C++ (Robot Sandwich; what a program is + the AI stance). Proves the no-compile-gate-surface shape. |
| B | M3, M6 | M3 salvages from `assignments/m2/` (ADR-010). M6 is where functions arrive — first Learn beat using the full single-file form. |
| C | M7, M8 | M7 under ADR-011's descope. M8 Learn beat only. |

---

## 5. Per-module definition of done

- `modules/mN/learn.md` — 10th-grade readable, GameFAQs register, dungeon skin strippable,
  four-word error taxonomy verbatim, no trick questions
- `modules/mN/code/learn-*.cpp` — **green on GCC in CI** (ADR-014; a local run is not evidence, and
  never assert compiler *silence* from one)
- Every ` ```cpp ` fence **born ADR-015-compliant** (`source=` / `excerpt=`); Mermaid renders
- `_overview.md`'s `SKELETON` banner updated to say the Learn beat is authored
- `modules/MODULES.md` row → **`First pass`**
- **Merge gate** (ADR-016 §7): append the module's row to §1 of this file **and** its build notes
  to `_lore/findings/F-015-breadth-pass-recipe.md`. Not seven ADRs.
- **PR body** carries the review card and both scoped gate runs, pasted
- Human review on the PR

**Verification**

```bash
# fast loop, per module — both must exit 0, pasted into the PR body
SEARCH_PATHS=modules/mN bash .github/scripts/compile-gate.sh
SEARCH_PATHS=modules/mN bash .github/scripts/markdown-gate.sh

# tree-wide, exactly as CI runs them
bash .github/scripts/compile-gate.sh
bash .github/scripts/markdown-gate.sh
bash .github/scripts/selftest/markdown/run.sh   # if you touch a gate or add a marker file

python3 .claude/skills/csc134-canvas-compositor/gate.py _outputs/canvas-html/m2   # pilot only
```

**CI on GCC is the authority** (ADR-014). A scoped local run is a fast loop, not evidence —
and never assert compiler *silence* from one.

### The review card (every breadth PR body)

So a reviewer never has to reconstruct the context:

1. What the Learn beat teaches, in one sentence.
2. What it assumes from the prior module — **name the artifact**.
3. What is deliberately withheld until a later module (loops before M5, functions before M6,
   pointers before M7).
4. Where it sits on the Make gradient, and the form its code takes (pre-M6 incomplete vs. full).
5. Both gate results.

---

## 6. Deferred queue — resumes after the ninth Learn beat

Ranked. Nothing here is cancelled; ADR-016 defers, it does not drop.

| Rank | Item | Why it waits |
|---|---|---|
| 1 | **#30** — migrate M4 + M5 fences to ADR-015 | Debt is bounded at 45 by the born-compliant rule. Paying it now buys no coverage. |
| 2 | **#21** — M5 cohort round 1 (semi-interactive, human in the loop) | The depth gate ADR-016 defers. First thing back when breadth lands. |
| 3 | **#33** — M4 Apply has no student-facing artifact | The breadth pass answers half of it (every module gains a student-facing entry point). The Apply-beat half stays open. |
| 4 | **#23** — ADR-013 ruling on the Haiku AI-assistant persona | Course-wide voice addition; a breadth pass is the wrong moment to widen surface. **ADR-013's number stays reserved.** |
| 5 | **#22** — `.gitignore` / source-vs-binary in the early modules | Lands naturally with M2's or M3's Apply beat, which the breadth pass does not author. |
| 6 | **#27** — tool installation guide (Codespaces → Mac → Windows) | Instructor-facing; unblocked by nothing here. |
| 7 | **#19** — mini-textbook / course pack | Explicitly *"do not start building from this issue"* — needs a brainstorm → design → spec pass first. |
| 8 | **Manifest rebuild** — `_tracking/course-manifest-csc134.yaml` | Banner applied now (F-014 §4); rebuild once `MODULES.md` is the settled index. |

### Also still shelved (ADR-010's ranked backlog, unchanged by this pass)

M1HW1 Budget Analyzer · M2HW1 Multi-Program · spare calculators. Shelved, not retired —
announced, never a silent drop.
