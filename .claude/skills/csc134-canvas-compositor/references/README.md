# References — visual reference only, NOT CSC-134 output

Everything in this folder arrived with the skill from a parallel session. It is here for one
reason: **to look at.** These fragments let a human eyeball whether the skill produces good
pages — spacing, device rhythm, whether a character diagram reads at 375px — which is a
judgment no gate script makes.

They are **not** CSC-134 course content and must never be pasted into a CSC-134 Canvas course.

## Why not

They were authored against a parallel session's version of the course, not against this
repo. The M4 fragment contradicts a **frozen interface contract**
(`_contracts/m4_gatekeeper.cpp`), which per `_contracts/README.md` may only change with
spine-owner sign-off, an ADR, and a version bump:

| | `_contracts/m4_gatekeeper.cpp` (frozen) | `m04-page-apply-gatekeeper.html` |
|---|---|---|
| class variable | `characterClass` | `playerClass` |
| line ending | `\n` | `endl` — the repo uses `endl` **zero** times |
| gatekeeper's line | `"A Warrior. Strong arms, I hope."` | `A Warrior. She looks at your arms.` |
| opening beat | `A gatekeeper blocks the dungeon door.` | absent |
| unknown class | prints, then `The gate stays shut.` | `She has no idea what you are.` |

The prose is good and the code compiles. It is simply a different program wearing the same
name, and the M4→M5 seam is built on the contract's exact text — `m5_menu.cpp` reappears
"almost word for word" from it. Treat these pages as a photograph of a house that resembles
ours, not as our blueprints.

Canon-correct composed output lives in `_outputs/canvas-html/`, which is build output and
carries its own rules — see `_outputs/README.md`.

## What was verified about them anyway

Worth recording, because it is why the skill was trusted enough to install:

- All five fragments pass every sanitizer gate the skill sets for itself — **0 failures**.
- Character diagram widths measured 27 / 28 / 16 columns, matching `PLACEHOLDERS.md`
  exactly. The ceiling is 40.
- Both complete C++ listings compile under `g++ -std=c++17 -Wall -Wextra` with **zero
  warnings**, and their claimed runtime output reproduces verbatim — including the M7
  page's teaching point, `Reachable gold: 0` with the TODO unfilled.

Re-run with `python3 .claude/skills/csc134-canvas-compositor/gate.py <dir>`.

## Two known gaps in this set

1. **`PLACEHOLDERS.md` lists six fragments; five are on disk.**
   `m04-assignment-dungeon-gatekeeper.html` (`M4 · assess`) never arrived. It was the set's
   only Assess exemplar, so the beat with the *mandatory* pre-flight panel has no worked
   example here. `_outputs/canvas-html/m4/m4-assess-lab-the-crossing.html` fills that role
   with canon-correct content.

2. **Four of the five contain Haiku check-ins**, which are frozen pending **ADR-013**. That
   is another reason not to reuse them directly: they demonstrate a device the course has
   not yet adopted.
