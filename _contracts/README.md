# `_contracts/` — Frozen interface contracts

These files are the **interface contracts** for the CSC-134 alpha build. Every
deep module build compiles and reasons against them. They are frozen on purpose:
downstream work assumes they do not move.

Think of them as type signatures for the course. Each later module consumes what
an earlier one produced — the contracts are the shared shapes that make the
modules compose.

## What lives here

| File | What it is | Who builds against it |
|---|---|---|
| `m4_gatekeeper.cpp` | The canonical M4 decision program (Dungeon Gatekeeper). M4 machinery only: `if`/`else`/`switch`, no loops, no functions. | M4 Apply/Assess; the seam anchor for M5. |
| `m5_menu.cpp` | The canonical M5 menu program — the M4 gatekeeper wrapped in a validated menu loop. The M4→M5 seam made concrete. | M5 Apply/Assess; refactored by M6; extended by M7. |
| `rubric-template.md` | The four columns (**Correctness / Completeness / Format / Submission**) × four tiers (**C / B / A / Badge**). | Every module lab rubric inherits it. |

## The rule

**Changing a contract is a breaking change.** It requires:

1. The **spine-owner's sign-off** (these are owned inward, per ADR-002).
2. An **ADR** in `_lore/decisions/` recording what changed and why.
3. A version bump and an announcement — never a silent mutation.

Later modules *refactor these exact files* (M6 pulls `m5_menu.cpp` into functions;
M7 extends it with structs and classes). That only works if the baseline is
stable. If you think a contract is wrong, do not patch it in place — file the
finding, get the sign-off, write the ADR.

## Verification

Both programs compile clean, zero warnings:

```
g++ -std=c++17 -Wall -Wextra -o m4_gatekeeper m4_gatekeeper.cpp
g++ -std=c++17 -Wall -Wextra -o m5_menu       m5_menu.cpp
```

The zero-warning bar is itself part of the contract — a later refactor that
introduces a warning has broken conformance.
