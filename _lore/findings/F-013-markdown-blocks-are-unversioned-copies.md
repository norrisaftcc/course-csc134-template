---
name: F-013-markdown-blocks-are-unversioned-copies
description: Fenced C++ listings are independent samples of gated .cpp files, not copies — divergent from birth, in the prose rather than the code. Inventories the ungated surface and the ADR-008 exclusion.
---

# F-013 — Markdown listings are independent samples, not copies

**Date:** 2026-07-25 · **Status:** Recorded · **Branch:** `phase0/markdown-block-gate`
**Acts on:** [[ADR-014-compile-gate-runs-on-gcc-in-ci]]'s known limitation ·
**Decided in:** [[ADR-015-markdown-blocks-mirror-gated-source]] ·
**Context:** [[F-009]], [[F-010]]

## Why this was measured

ADR-014 shipped a compile gate over `.cpp` files and recorded what it could not see: fenced
blocks inside Markdown. Every M4 defect found this week lived in one. Before designing a gate for
them, the question was what those blocks actually *are* — and the answer was not the expected one.

## The corpus

72 `cpp` blocks repo-wide (excluding `_past_work/`, `_storming/`, `csc134-refresh-plan/`).
**19 complete programs, 53 fragments** — three quarters cannot compile standalone.

Fragments are four distinct shapes, which is why a single wrapper template was never going to
work:

| Shape | Example | Compilable alone? |
|---|---|---|
| statements from inside `main`, using variables declared in an *earlier* block | `M1HW1:173`, `apply-tutorial.md:279` | no — undeclared identifiers |
| deliberately-broken one-liners | `learn.md:251` (`if (hp = 0)`) | no, on purpose |
| "add the marked lines" diff excerpts | `apply-tutorial.md:500` | no |
| stub bodies in skill templates | `.claude/skills/lab-creator/SKILL.md:106` | no |

## The finding: divergent at birth, and divergent in the prose

The expected story was edit drift — someone fixes the `.cpp`, forgets the listing. That is not
what the history shows.

`modules/m4/learn.md` and `modules/m4/code/learn-gate-strength.cpp` were **created in the same
commit** (`cc6e630`, "feat(m4): deep build"), one authoring pass, one intent. Measured at that
commit they were already **0.871 similar, not identical** — and today, after `learn.md` was
edited twice more, they are still exactly 0.871. Nothing drifted them. They were never the same.

Comparing **code only, comments stripped**, changes the picture again — and this is the part that
matters:

| Listing | Closest gated `.cpp` | full text | code only |
|---|---|---|---|
| `learn.md:56` | `learn-gate-strength.cpp` | 0.87 | **1.00** |
| `learn.md:129` | `learn-gate-class.cpp` | 0.91 | **1.00** |
| `practice-exit-ticket.md:31` | `practice-item1-vault.cpp` | 0.66 | **1.00** |
| `practice-exit-ticket.md:100` | `practice-gatekeeper.cpp` | 0.87 | **1.00** |
| `practice-exit-ticket.md:217` | `practice-item4-doors.cpp` | 0.74 | **1.00** |
| `practice-exit-ticket.md:254` | `practice-item5-fallthrough.cpp` | 0.37 | **1.00** |
| `apply-tutorial.md:149` | *(none — Stage 1)* | 0.31 | 0.46 |
| `apply-tutorial.md:194` | *(none — Stage 2)* | 0.21 | 0.84 |
| `practice-exit-ticket.md:60` | *(none)* | 0.38 | 0.66 |

**Six of nine complete listings reproduce their program byte-for-byte.** What varied is the prose
around it: the `.cpp` carries a three-line explanatory header, the listing trimmed it to one.

> Regenerating an artifact reproduces the part a compiler checks, and re-samples the part nothing
> checks.

That is [[F-009]]'s exact shape. F-009 was **four false claims in prose** sitting on top of code
that was fine. The explanation is the fragile half, and it is the half that reaches students.

An earlier reading of this data — circulated during the session — treated the 0.87/0.91/0.66
full-text figures as evidence that the *programs* had drifted. They had not. The code-only column
is the honest one, and it makes the real ungated surface much smaller and much more specific.

## The ungated surface: three blocks

| Listing | What it is |
|---|---|
| `modules/m4/apply-tutorial.md:149` | staged build Stage 1 — a shorter whole program; no stage `.cpp` exists |
| `modules/m4/apply-tutorial.md:194` | staged build Stage 2 — same |
| `modules/m4/practice-exit-ticket.md:60` | **a complete program with no `.cpp` twin at all** |

The third is the live one: student-facing C++ that has never been compiled by any gate, inside a
module certified **Ready**. M4's certification stays provisional until the migration lands.

Staged builds are the general case of the first two — a stage is not a *slice* of the final
program, it is a shorter whole program, so it needs its own gated file. ADR-015 §4 rules that
each stage gets one, which also turns CLAUDE.md bar #9 ("each stage compiles and runs standalone")
from an assertion into something checked.

## In-scope inventory — `modules/`, 23 blocks in 4 files

| File | complete | fragment |
|---|---|---|
| `modules/m4/apply-tutorial.md` | 2 | 6 |
| `modules/m4/learn.md` | 2 | 6 |
| `modules/m4/practice-exit-ticket.md` | 5 | 1 |
| `modules/m4/assess-lab.md` | 0 | 1 |
| **total** | **9** | **14** |

These are what `main` goes red on when the gate merges. Per ADR-015 §6 that is deliberate: the
gate is the failing test, the migration is the fix, in that order. **Tracked as issue #30**,
which carries the three-bucket breakdown (six easy header trims, the staged-build files, and the
one genuinely ungated program) so the work is assignable rather than a wall of 23.

## Out of scope, recorded rather than hidden — `assignments/`, 46 blocks in 10 files

Excluded because **[[ADR-008-two-tree-module-layout]] freezes this tree** — "frozen provenance
that is never edited, moved, or shipped." Annotating these blocks would mean editing frozen files.
The exclusion is a consequence of an existing ruling, not a scoping convenience, so the inventory
is recorded in full:

| File | complete | fragment |
|---|---|---|
| `assignments/m0/01_workspace_setup.md` | 1 | 0 |
| `assignments/m1/M1HW1_StudentBudgetAnalyzer.md` | 1 | 7 |
| `assignments/m1/M1LAB_CoffeeShopPOS.md` | 1 | 9 |
| `assignments/m1/M1T1_HelloWorld.md` | 1 | 1 |
| `assignments/m1/M1T2_DigitalBusinessCard.md` | 1 | 4 |
| `assignments/m2/M2HW1_MultiProgramChallenge.md` | 1 | 7 |
| `assignments/m2/M2LAB1_CrateManufacturing.md` | 1 | 1 |
| `assignments/m2/M2T1_InteractiveMarketplace.md` | 1 | 5 |
| `assignments/m2/M2T2_RestaurantCalculator.md` | 1 | 2 |
| `assignments/m2/README.md` | 0 | 1 |
| **total** | **9** | **37** |

**Caveat worth flagging to whoever owns the port.** `_tracking/numbering-reconciliation-map.md`
describes `assignments/m0/` as "already live, students-facing," while ADR-008 and
`_tracking/open-question-brief.md` describe `assignments/` as frozen and never shipped. If any of
these 46 blocks is in fact reaching students, they are ungated *and* unfixable under the current
freeze — a contradiction that belongs to the port ruling, not to this gate. Not actioned here.

`.claude/skills/*/SKILL.md` (1 complete, 2 fragment) is builder-facing template text and is also
out of scope.

## Open question for the spine owner — does this become taught content?

Not decided here, and **no ADR number claimed for it**, per the CLAUDE.md rule against grabbing a
contested number for a decision that is not ours.

Students arriving in CSC-134 increasingly believe code generation is deterministic — ask for the
file, get the file. This repo now holds measured counter-evidence from its own history: two
artifacts generated in one commit from one intent, where the program came back identical and the
explanation came back different. The compiler checked one and nothing checked the other, and the
result was four false claims shipped inside a module certified Ready.

The teachable form is not "AI is unreliable." It is sharper and more useful:

> **The code is the part that gets reproduced. The explanation is the part that gets re-wished.**
> Verify the half nothing checks.

That maps onto the course's existing AI prompt-pattern ladder (Clive's beat) and onto the four-word
error taxonomy — a re-wished explanation produces no Syntax, Static semantic, or Runtime error. It
is a **Logic** error in the prose.

Whether this is alpha scope, an M8-adjacent topic, or out of scope entirely is a course-content
call. Flagged for a ruling; the evidence is above and reproducible from git.
