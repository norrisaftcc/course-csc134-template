---
name: F-009-fallthrough-warning-claim-is-toolchain-dependent
description: M4 learn.md and apply-tutorial.md claim switch fall-through produces no warning; true on clang, likely false on GCC — the course's stated toolchain. Needs GCC verification.
---

# F-009 — The "fall-through produces no warning" claim is toolchain-dependent

**Date:** 2026-07-25 · **Status:** Open — needs verification on GCC · **Branch:** `phase0/canvas-compositor`
**Found by:** composing M4 Learn Reading 3, while testing a factual claim before emitting it
**Affects:** `modules/m4/learn.md` (Trap 2), `modules/m4/apply-tutorial.md` (The Deliberate Break)
**Severity:** major — M4 is certified **Ready**, and this is a factual claim about compiler behaviour
in student-facing material, load-bearing for the beat's whole lesson

## The claim

`learn.md`, Trap 2:

> Here's the scary part: on our compiler this produces **no warning at all** — it compiles clean and
> just does the wrong thing quietly. That's why fall-through is the most dangerous of the three.

`apply-tutorial.md`, The Deliberate Break, makes the same claim:

> **What actually happens — it compiles with zero warnings, then:** … A clean compile is not proof of
> a correct program.

The entire pedagogical point of the deliberate break rests on it: the student removes a `break;`,
sees a **clean** build, and learns that a clean compile does not mean a correct program.

## What was actually tested

Built the exact fall-through case (case 1 losing its `break;`, falling into a non-empty case 2)
under the course flags `-std=c++17 -Wall -Wextra`:

| Toolchain | Result |
|---|---|
| **Apple clang 21.0.0** (this machine) | **No warning.** Compiles clean. Prints both the Warrior and the Mage line. Claim holds. |
| **GCC** (the course's stated toolchain) | **Not verified — no GCC on this machine.** |

## Why GCC probably contradicts it

Three independent reasons to expect GCC to warn:

1. **GCC enables `-Wimplicit-fallthrough=3` as part of `-Wextra`** (GCC 7 onward), and `-Wextra` is a
   course flag. Clang does not enable it under `-Wall -Wextra`; it must be asked for by name. That
   difference alone explains the split.
2. **Level 3 only accepts specific fall-through marker comments** matching patterns like *"falls
   through"*. Neither source comment qualifies — `learn.md` has `// BUG: no break here!` and
   `apply-tutorial.md` has `// break;   <-- deliberately removed`. Both would warn.
3. **The parallel session's own notes say GCC warns.** Their `PLACEHOLDERS.md`, verified on GCC/Ubuntu,
   records: *"The fallthrough warning is verbatim output at the line numbers students see in the
   stage-1 file."* Independent corroboration from a different author on the target toolchain.

The course targets GCC/Ubuntu — Codespaces, and the compile-warden's stated environment. If GCC warns,
**the claim is false in exactly the environment the students are in**, and true only on an instructor's
Mac.

## Why this is worse than an ordinary inaccuracy

Under the course's **zero-warning rule**, a warning is a failed build. So on GCC the deliberate break
does not demonstrate "clean compile, wrong behaviour" — it demonstrates a build that fails the course's
own Format standard. The student is told to expect silence and gets a diagnostic. The lesson inverts:
instead of *the compiler cannot save you here*, they learn *the compiler caught it*, which is the
opposite of why fall-through was chosen as the most dangerous trap.

It is also self-undermining in a course that teaches reading compiler output closely. The one moment
the material tells students to expect nothing is a moment their compiler may be talking.

## What was done about it here

**Nothing to the content.** M4's material was composed to Canvas faithfully, claim intact. Rewriting
prose during a composition pass is the exact move that put the imported exemplars out of sync with
`_contracts/m4_gatekeeper.cpp` (see [[F-008-canvas-compositor-import]] § F-008-1), and content changes
to a certified-Ready module do not belong in a formatting PR.

The composed page carries a source comment pointing here.

## What needs to happen

1. **Verify on GCC.** `docker run --rm -v "$PWD":/w -w /w gcc:13 g++ -std=c++17 -Wall -Wextra …`, or any
   Ubuntu box, or Codespaces — which is the most honest place to test it, being where students are.
2. **If GCC warns**, decide which way to fix it. Two options, and they are not equivalent:
   - **Keep the demo, change the prose.** Show the fall-through warning as real compiler output, and
     move "a clean compile is not proof of a correct program" onto a trap the compiler genuinely
     misses. Costs the deliberate break its punchline.
   - **Keep the lesson, change the demo.** Find a Logic error that is genuinely silent under
     `-Wall -Wextra` on GCC and build the deliberate break on that instead. The dangling `else`
     (Trap 3) is silent on both toolchains and is already in the module.
3. **Either way, re-gate M4 and re-emit the composed pages.** The composed page is build output; it
   costs seconds to regenerate once the source is right.

## The general lesson

The compile-warden gate runs on one machine. A claim of the form *"the compiler says X"* is only as
portable as that machine, and `-Wall -Wextra` is not the same set of warnings on GCC and clang. Any
material asserting compiler **silence** — rather than quoting compiler output — should be verified on
the toolchain students actually use, because silence is the one result that looks identical whether
you tested it or not.
