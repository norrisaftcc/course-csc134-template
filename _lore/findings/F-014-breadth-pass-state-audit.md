---
name: F-014-breadth-pass-state-audit
description: Coverage audit before the breadth pass — one module in nine has content on main, M5 is complete but stranded in an unmerged PR whose CI has never run, and the module manifest actively contradicts the module tree.
---

# F-014 — What `main` actually has, before the breadth pass

**Date:** 2026-07-29 · **Status:** Recorded · **Branch:** `claude/backlog-prioritization-test-selection-b0o1m2`
**Decided in:** [[ADR-016-breadth-first-pass]] ·
**Context:** [[F-006-m4-fixes-and-ready]], [[F-009-fallthrough-warning-claim-is-toolchain-dependent]],
[[F-013-markdown-blocks-are-unversioned-copies]] · **Relates to:** #20, #21, #30

## Why this was measured

A new priority arrived — *humans must be able to open any module and review a representative
example*. Before choosing what to build, the question was what exists. The answer disagreed with
two of the three places that claim to track it.

## 1. Coverage on `main`: one module in nine

| Module | M0 | M1 | M2 | M3 | M4 | M5 | M6 | M7 | M8 |
|---|---|---|---|---|---|---|---|---|---|
| Authored beats | 0 | 0 | 0 | 0 | **4** | 0 | 0 | 0 | 0 |

Eight modules hold scaffold only: `_overview.md`, `_mlos.md`, `_assets.md`, and an
`_assess-spec.STUB.md` whose banner reads *"NOT YET AUTHORED — STUB… do not hand this stub to
students."* M4 alone carries `learn.md`, `practice-exit-ticket.md` (+ key), `apply-tutorial.md`,
`assess-lab.md`, and 10 gated `.cpp`.

**4 of 36 LPAA beats exist.** A review meeting held today can only discuss M4.

## 2. M5 is complete and stranded — and its CI has never run

PR #20 (`module/m5-deep`) carries a finished M5: 5 authored Markdown beats, **20 gated `.cpp`**,
`F-007`, and `modules/MODULES.md` — the status table `main` does not otherwise have.

Both review items on the PR thread are **closed**: the `mode: "SPLIT"` ruling (no ADR needed;
`_overview.md` is sufficient authority) and the A-tier trim in `e891fca`. The only thing holding
it open is #21, the M5 cohort round — a *depth* gate.

**The defect:** PR #20's base sha is `c3dbb62`, which **predates the compile gate landing**
(PR #26). Its only check run is `copilot-pull-request-reviewer`. **The `compile-gate` workflow has
never executed against a single M5 file.**

The gate evidence in the PR body is *Apple clang 21.0.0 on macOS*. That is precisely the toolchain
ADR-014 declares non-authoritative, and F-009 exists because that exact gap shipped a
`-Wimplicit-fallthrough` warning inside a module that had been certified Ready. **M5's 20 `.cpp`
files therefore carry an unverified clean-compile claim** — not a known-bad one, an unchecked one,
which is the same category of unknown ADR-014 was written to close.

Merging `main` into `module/m5-deep` makes CI run for the first time and settles it. That is the
first action ADR-016 schedules.

**Settled, same day.** `main` merged in as `07d2408`; CI ran against M5 for the first time.
`g++ -std=c++17 -Wall -Wextra` on ubuntu-latest reported **32 files: 31 clean, 0 warned,
0 errored, 1 expected (marked)** — the one expected being M4's `practice-item5-fallthrough.cpp`
asserting its `EXPECT-WARNING` marker. **All 20 `modules/m5/code/*.cpp` are clean.**

The macOS result was right. It is now also *evidence* — which is the whole distinction ADR-014
draws, and the reason this was worth checking rather than assuming. A claim that turns out true
was still unverified while it was unverified.

## 3. Gate counts, measured (not estimated)

Run on this branch, GCC on Linux, 2026-07-29:

| Gate | Result |
|---|---|
| `compile-gate.sh` | **PASSED** — 12 files: 11 clean, 0 warned, 0 errored, 1 expected (`practice-item5-fallthrough.cpp`, marked `EXPECT-WARNING`) |
| `markdown-gate.sh` | **FAILED** — 23 blocks: 0 matched, 0 failed, **23 unmigrated** (#30) |

The 23 break down as `apply-tutorial.md` 8, `learn.md` 8, `practice-exit-ticket.md` 6,
`assess-lab.md` 1 — matching the countdown in #30 exactly.

**Merging M5 will take that number to 45.** Counted directly on `origin/module/m5-deep`: M5 adds
**22 unannotated fences** (`learn.md` 6, `practice-exit-ticket.md` 7, `apply-tutorial.md` 8,
`assess-lab.md` 1; the exit-ticket key has none). Recorded here in advance so the jump reads as
pre-existing debt arriving, **not as a regression introduced by the merge**. #30's scope grows
from 23 to 45; nothing about it becomes newly wrong.

**Confirmed in CI after the merge**, file for file: `GATE FAILED — 45 block(s) are UNMIGRATED,
not defective.` The prediction is recorded above the result on purpose. A number written down
*before* the run is a check on the model of the system; the same number written down after is
only a transcript.

This is also the measurement behind ADR-016's born-compliant rule. Seven more Learn beats authored
the old way would put the count past 100 and turn a tracked debt into an unpayable one.

## 4. The manifest contradicts the module tree

`_tracking/course-manifest-csc134.yaml` is `manifest_version: "0.2"`, `last_updated:
"2026-01-01T00:00:00Z"` — six months stale and pre-spine. It is wrong in four ways at once:

- Legacy padded **`M00`–`M08`** numbering, not the spine's `M0`–`M8`.
- **`M04 Decision Structures` is listed `planned`.** M4 is built, cohort-tested, and Ready (F-006).
- It still carries **`M06` (Arrays/Strings)** and **`M07` (File I/O and Structs)** as live modules.
  ADR-011 descoped STL/`std::string`-as-a-topic and File I/O.
- Its rollup (`complete: 14`, `planned: 40`, `percentage: 26`) describes the frozen `assignments/`
  tree, not `modules/` — and ADR-008 made `modules/` canonical.

Its rebuild was deferred on purpose (`_tracking/skeleton-plan.md:108`, downstream of open question
1) and that deferral was reasonable. What is not reasonable is that it reads as authoritative while
being wrong. **Mitigation applied now: a staleness banner naming `modules/MODULES.md` as the real
index.** The rebuild stays deferred until the breadth pass completes.

## Disposition

| Item | Disposition |
|---|---|
| 1/9 coverage | Addressed by [[ADR-016-breadth-first-pass]] — a Learn beat in every module |
| M5 stranded in #20 | **Done** — `main` merged in as `07d2408`, CI run, handed back for human merge (ADR-004) |
| M5's unverified compile claim | **Closed, verified** — `compile` job green on GCC in CI; all 20 M5 sources clean |
| 23 → 45 unmigrated blocks | Predicted, then confirmed in CI. Recorded against #30; scope grows, nothing regresses. Born-compliant rule keeps it from growing further |
| Stale manifest | Banner now; rebuild after the breadth pass |
