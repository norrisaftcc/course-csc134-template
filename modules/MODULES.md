# MODULES.md — build status of the nine-module tree

This is the canonical spine-truth home for module content (ADR-008, two-tree
layout). `assignments/` and `_past_work/` are legacy source — frozen, mined for
material, never scaffold targets.

**Status vocabulary**

| Status | Means |
|---|---|
| **Skeleton** | Structure-only pass: `_overview.md`, `_mlos.md`, `_assets.md`, `_assess-spec.STUB.md`. No student-facing content authored. |
| **First pass** | One real, gate-green, student-facing artifact — the **Learn beat**. That means `learn.md`, plus gated sources in `code/` **for modules that have C++ to gate**. M0 and M1 are pre-C++ and correctly have **no `code/` directory at all**; for them, gate-green means the markdown gate passes at zero blocks. Authored in the breadth pass **without graduate seeding**, so humans can open any module and review something real. Not all four beats; not cohort-tested. See [[ADR-016]]. |
| **Built** | All four LPAA beats authored and through the compile-warden gate (every C++ block clean under `g++ -std=c++17 -Wall -Wextra`, Mermaid renders, rubric lineage verified). |
| **Ready** | Built, *plus* taken end to end by a synthetic student cohort, with every finding filed and closed. |

A module is not **Ready** until a cohort has actually failed at it and those
failures have been fixed.

---

## Current state

Titles are the spine's, verbatim (`_storming/CSC-134-course-spine.md`). Where a
module has a working nickname — M0's Mail Run, M1's Robot Sandwich — it is named
in the module's own `_overview.md`, not substituted for the title here.

| Module | Title | Status | Beats present | Evidence |
|---|---|---|---|---|
| **M0** | Welcome to Programming | **First pass** | Learn | F-015 (breadth pass). Pre-C++ — no `code/`, no compile-gate surface. No cohort round. |
| **M1** | Talk to Computers (and Your Team) | **First pass** | Learn | F-015 (breadth pass). Pre-C++ — no `code/`, no compile-gate surface. No cohort round. |
| **M2** | How to Solve Problems | **First pass** | Learn | F-015 (breadth-pass pilot). Both gates green; no cohort round. |
| **M3** | Program Basics | **First pass** | Learn | F-015 (breadth pass). First breadth module with C++ — 5 gated sources. No cohort round. |
| **M4** | Decisions | **Ready** | Learn · Practice (+key) · Apply · Assess | F-004 (build), F-005 (cohort round 1), F-006 (fixes + certification) |
| **M5** | Loops | **Ready** | Learn · Practice (+key) · Apply · Assess | F-007 (build) + F-017 (cohort round 1). Four should-fix closed (#48-#51). |
| **M6** | Functions | **First pass** | Learn | F-015 (breadth pass). First module using the full single-file form. No cohort round. |
| **M7** | Structured Data & Objects | **First pass** | Learn | F-015 (breadth pass). Arrays → structs → by-reference; classes named, not taught. No cohort round. |
| **M8** | Capstone Miniproject | **First pass** | Learn | F-015 (breadth pass). Problem formulation — design document; the capstone itself is not authored. No cohort round. |

**The breadth pass is complete** ([[ADR-016]]) — all nine modules carry a Learn
beat at `First pass` or better, so a human review meeting can open any of them.
Work list and the live backlog behind it: `_tracking/breadth-pass-ledger.md`.

**M5 reached `Ready` on 2026-07-31** — cohort round 1 ran (#21, [[F-017]]), four
should-fix were found and closed (#48–#51). **One caveat travels with that
badge:** F-017 records that the round was *too easy* — three personas scored 7/7
cold with identical answers and none produced the `&&`-for-`||` error the lab
predicts. `Ready` here means *cohort-tested and its findings closed*, not
*proven against real student failure*. The first human cohort will still find
things.

---

## Per-module file shape

A **First pass** module carries one artifact beyond the four skeleton files:

```
modules/mN/
  learn.md                      Learn beat — the reading
  code/learn-*.cpp              Every C++ source that beat quotes
```

A **Built** module carries these, beyond the four skeleton files:

```
modules/mN/
  learn.md                      Learn beat — the reading
  practice-exit-ticket.md       Practice beat — student-facing, completion-gated
  practice-exit-ticket-key.md   Practice beat — INSTRUCTOR-FACING answer key
  apply-tutorial.md             Apply beat — the in-class session
  assess-lab.md                 Assess beat — the graded lab, with rubric
  code/                         Every C++ source the beats reference
```

**`_assess-spec.STUB.md` stops being a stub once its lab is authored.** In a Built
or Ready module it is the **build record** — the acceptance criteria and contract
the lab was written against, kept for the reasoning. It is never handed to a
student, and if it disagrees with `assess-lab.md`, the lab wins. Retarget its
banner when the lab lands; leaving "NOT YET AUTHORED" on a shipped module tells
every reader the opposite of the truth (F-014 §5).

`code/` holds **sources only**. Compiled binaries are extensionless on
macOS/Linux, which no `*.ext` rule catches, so `.gitignore` excludes everything
in `modules/*/code/` and allows `.cpp` / `.h` / `.md` back in. If you add another
source type, add it to that allow-list or git will silently ignore your file.

---

## The Make gradient, by module

Apply-beat scaffolding shifts as the course goes on. Build each beat at its
module's position; do not hand M4 a spec or M7 a full type-in.

| Modules | Mode | Student does |
|---|---|---|
| M2–M4 | **FULL** | Types 100% of the program, in compiling stages |
| M5–M7 | **EIGHTY** | Receives a working ~80% program with one spec'd gap; finishes it |
| M8 | *spec-only* | Gets a brief; builds the thing |

**M5 is the seam and is deliberately split**: Part 1 of its Apply beat is the
last FULL type-in, Part 2 is the first EIGHTY gap — both in one class session.
See `modules/m5/_overview.md` and `modules/m5/apply-tutorial.md`.

---

## Contracts these modules build against

Frozen; changing one is a breaking change needing spine-owner sign-off + an ADR.

- `_contracts/m4_gatekeeper.cpp` — canonical M4 decision program
- `_contracts/m5_menu.cpp` — canonical M5 menu program (the M4→M5 seam)
- `_contracts/rubric-template.md` — four columns × four tiers, inherited by every lab
