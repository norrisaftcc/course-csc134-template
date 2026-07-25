---
name: F-010-m4-compiler-claim-fixes
description: Fixes the four false compiler-silence claims in M4 and restructures the Apply beat so the closing demo is a genuinely silent Logic error. Closes #25.
---

# F-010 — M4 compiler-claim fixes; the Deliberate Break gets an honest demo

**Date:** 2026-07-25 · **Status:** Recorded · **Branch:** `fix/m4-compiler-silence-claims`
**Closes:** #25 · **Acts on:** [[F-009-fallthrough-warning-claim-is-toolchain-dependent]]
(arriving via PR #24) · **Ruling:** norrisa, 2026-07-25 — swap roles rather than patch in place

## What was wrong

M4 told students, in four places, that a deliberately broken program compiles
**silently**. Under the course flags on GCC — which is what Codespaces runs — none of
those claims held.

The root cause is in F-009: **all three of M4's named traps are caught by `-Wall
-Wextra` on GCC.** `=` vs `==` gives `-Wparentheses`, the dangling `else` gives
`-Wdangling-else`, and fall-through gives `-Wimplicit-fallthrough`. The material was
written against Apple clang, which enables the third of those under neither flag.

That is not a wording problem. It means the Apply beat's closing demo — whose entire
job is *"a clean compile is not proof of a correct program"* — had no silent error to
demonstrate with.

## What changed

### 1. The Apply beat swapped roles (the ruling)

**Before:** the closing Deliberate Break was the missing `break;`, claimed silent.
**After:** the closing Deliberate Break is a **mis-ordered outcome ladder** — `>= 40`
placed above `>= 70` — which is genuinely silent on every compiler tested. Fall-through
moved down into the optional breaks as **Break C**, alongside the other two the compiler
catches.

The section is now structured around the contrast, which is a better lesson than either
half alone:

| Section | Traps | What it teaches |
|---|---|---|
| Optional: **Three Quick Breaks** | `=` vs `==`, dangling `else`, missing `break;` | The compiler sees these. Read the warning; it names the bug precisely. |
| **The Deliberate Break** | mis-ordered ladder | The compiler **cannot** see this. A clean compile only proves the grammar is fine. |

The new demo is visceral in the way the old one was: a Warrior with strength **85**
— comfortably over the top bar — gets the borderline riddle, because `85 >= 40` was
true first and the gate branch is now unreachable. The correct-looking `>= 70` line sits
right there in the program and never runs.

### 2. Four claims corrected

| File | Claim | Fix |
|---|---|---|
| `apply-tutorial.md` — Instructor Notes | deliberate break "compiles clean" | Rewritten for the new demo, with a note recording why fall-through moved |
| `apply-tutorial.md` — Break B | "It compiles clean, then prints…" | Now shows the verbatim `-Wdangling-else` warning **before** the run |
| `learn.md` — Trap 2 | "**no warning at all** … no red text to save you" | Now shows the real warning and teaches warning-is-not-error |
| `practice-exit-ticket-key.md` — Item 5 | "on our toolchain it produced **no** warning at all" | Corrected; see below |

### 3. The answer key was the worst of them

Item 5's key told the instructor that a student picking "Syntax" because *"the compiler
should have caught it"* held **the exact misconception to correct — the compiler did not
catch it here.**

On GCC it does. So the key instructed teachers to assert something false to a student who
may have just compiled the file and seen otherwise.

**The answer is unchanged — D, Logic — and it was always right.** What changed is the
reasoning offered for it. A warning does not stop a build: the compiler produced a
working program that printed the wrong thing. An *error* would have left nothing to run.
That distinction is what separates Logic from Syntax, and it is now the item's teaching
point rather than a claim about silence.

The misconception-bank entry was rewritten the same way: the student's instinct is half
right, and the useful correction is warning ≠ error.

### 4. `practice-item5-fallthrough.cpp` was never a bug

Recorded because F-009 originally mis-scoped it. The file was **already honest** — its
header said the compiler "may print a helpful fall-through warning," and its build line
deliberately omits `-Wall -Wextra`, the only file in M4 that does. Students never compile
it; Item 5 is a read-only predict/classify item.

The defect was in the **gate**, which compiles deliberately-broken teaching artifacts
under flags they were never meant to pass. The file now carries a machine-readable
marker:

```
// GATE: EXPECT-WARNING
```

plus an explicit "do not add the `break;`, do not add `[[fallthrough]]`" warning, because
the obvious fix destroys the exit-ticket item the file exists to support.

**The corresponding gate support belongs to PR #26** (ADR-014) and is not in this PR.
The marker is inert until the gate honours it. The stronger form — the gate *failing* when
a marked file stops warning — is the one to implement, since that verifies the teaching
artifact still demonstrates what it claims.

## Verification

Every warning quoted in the material is verbatim GCC output, captured from the actual
student file at the actual line numbers, not paraphrased. This matters: issue #14 was the
last time these files were allowed to disagree about a warning string.

```
mis-ordered ladder   GNU g++ 16.1.0   SILENT, exit 0
                     run 1 / 85       -> "Borderline. Answer me this..."  (wrong, as designed)

fall-through         GNU g++ 16.1.0   apply-gatekeeper.cpp:30:21: warning: this statement
                                      may fall through [-Wimplicit-fallthrough=]
                                      ...:32:9: note: here
                     run 1 / 90       -> Warrior AND Mage lines

dangling else        GNU g++ 16.1.0   apply-gatekeeper.cpp:60:8: warning: suggest explicit
                                      braces to avoid ambiguous 'else' [-Wdangling-else]
                     run 1 / 50       -> "Too weak... Turned away."
```

Break B also emits a second warning — `hasLockpick` set but not used, because pasting the
brace-free block over the ladder removes the branch that used it. The material now says so
rather than letting it look like a mistake.

Full M4 code re-gated on GNU g++ 16.1.0: **9 clean, 1 expected-warning (marked)**. Item 5's
output is unchanged.

## Consequence for the composed Canvas pages

`_outputs/canvas-html/m4/m4-learn-3-three-traps.html` derives from `learn.md` Trap 2 and is
now **stale**. It must be re-emitted after this merges — which is the ordering chosen
deliberately, so the pages are composed once against fixed source rather than twice.
