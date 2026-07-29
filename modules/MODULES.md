# MODULES.md — build status of the nine-module tree

This is the canonical spine-truth home for module content (ADR-008, two-tree
layout). `assignments/` and `_past_work/` are legacy source — frozen, mined for
material, never scaffold targets.

**Status vocabulary**

| Status | Means |
|---|---|
| **Skeleton** | Structure-only pass: `_overview.md`, `_mlos.md`, `_assets.md`, `_assess-spec.STUB.md`. No student-facing content authored. |
| **Built** | All four LPAA beats authored and through the compile-warden gate (every C++ block clean under `g++ -std=c++17 -Wall -Wextra`, Mermaid renders, rubric lineage verified). |
| **Ready** | Built, *plus* taken end to end by a synthetic student cohort, with every finding filed and closed. |

A module is not **Ready** until a cohort has actually failed at it and those
failures have been fixed.

---

## Current state

| Module | Topic | Status | Beats present | Evidence |
|---|---|---|---|---|
| **M0** | Orientation / Mail Run | Skeleton | — | — |
| **M1** | Robot Sandwich | Skeleton | — | — |
| **M2** | First Programs | Skeleton | — | — |
| **M3** | Arithmetic & I/O | Skeleton | — | — |
| **M4** | Decisions | **Ready** | Learn · Practice (+key) · Apply · Assess | F-004 (build), F-005 (cohort round 1), F-006 (fixes + certification) |
| **M5** | Loops | **Built** | Learn · Practice (+key) · Apply · Assess | F-007 (build + gate). Cohort round not yet run. |
| **M6** | Functions | Skeleton | — | — |
| **M7** | Structured Data & Objects | Skeleton | — | — |
| **M8** | Capstone | Skeleton | — | — |

**Next cohort target:** M5. It is Built but not Ready — a synthetic cohort has
not taken it yet, so its findings ledger is a build record, not a field record.
Treat M5 content as unproven against real student failure until that round runs.

---

## Per-module file shape

A Built module carries these, beyond the four skeleton files:

```
modules/mN/
  learn.md                      Learn beat — the reading
  practice-exit-ticket.md       Practice beat — student-facing, completion-gated
  practice-exit-ticket-key.md   Practice beat — INSTRUCTOR-FACING answer key
  apply-tutorial.md             Apply beat — the in-class session
  assess-lab.md                 Assess beat — the graded lab, with rubric
  code/                         Every C++ source the beats reference
```

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
