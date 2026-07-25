---
name: F-009-fallthrough-warning-claim-is-toolchain-dependent
description: M4 tells students two deliberate-break demos "compile clean". Confirmed false — fall-through warns on GCC, dangling-else warns on BOTH compilers. Needs a content fix.
---

# F-009 — Two M4 "compiles clean" claims are false under the course's own flags

**Date:** 2026-07-25 · **Status:** **Confirmed** — needs a content fix (#25) · **Branch:** `phase0/canvas-compositor`
**Found by:** composing M4 Learn Reading 3, while testing a factual claim before emitting it
**Affects:** `modules/m4/learn.md` (Trap 2), `modules/m4/apply-tutorial.md` (The Deliberate Break, Break B)
**Severity:** **major** — M4 is certified **Ready**, and both claims are load-bearing for their beat's lesson

## Summary

M4 tells students, in three places, that a deliberately broken program **compiles with zero warnings**.
Tested under the exact course flags. **Both claims are false**, and the second is false everywhere:

| Claim | Where | Apple clang 21 | GNU g++ 16.1.0 | Verdict |
|---|---|---|---|---|
| `switch` fall-through compiles silently | `learn.md` Trap 2; `apply-tutorial.md` Deliberate Break | **silent** ✅ | **warns** ❌ | false on the course toolchain |
| dangling `else` compiles clean | `apply-tutorial.md` Break B | **warns** ❌ | **warns** ❌ | **false on both** |

The second is the more embarrassing one: it is wrong even on the machine it was presumably written on.

## Evidence

Course flags throughout: `-std=c++17 -Wall -Wextra`.

**Fall-through**, GNU g++ 16.1.0:

```
warning: this statement may fall through [-Wimplicit-fallthrough=]
   13 |             cout << "\"A Warrior. Strong arms, I hope.\"\n";
      |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
note: here
   15 |         case 2:
```

**Which flag is responsible** — this is the whole story:

| Flags | Fall-through warning? |
|---|---|
| `-Wall` alone | **no** |
| `-Wextra` alone | **yes** |
| `-Wall -Wextra` (course flags) | **yes** |
| with a `// falls through` marker comment | no — GCC accepts it as intentional |

So it is **`-Wextra`**, which GCC has carried since version 7 and which clang does not enable by name.
That single flag difference is the entire discrepancy. Neither source comment
(`// BUG: no break here!`, `// break;   <-- deliberately removed`) matches the marker patterns that
would suppress it.

**Dangling `else`**, the verbatim Break B snippet, on both compilers:

```
GCC:   warning: suggest explicit braces to avoid ambiguous 'else' [-Wdangling-else]
clang: warning: add explicit braces to avoid dangling else [-Wdangling-else]
```

## Why this matters more than an ordinary inaccuracy

Under the course's **zero-warning rule a warning is a failed build.** So on GCC — Codespaces, which is
where students are — the deliberate break does not demonstrate *clean compile, wrong behaviour*. It
demonstrates a build that fails the course's own Format standard. The student is promised silence and
handed a diagnostic, and the lesson inverts from *the compiler cannot save you here* to *the compiler
caught it*.

It is also self-undermining in a course that teaches reading compiler output closely: the one moment
the material tells students to expect nothing is a moment their compiler is talking.

## This invalidates the fix originally proposed here

The first draft of this finding suggested rebuilding the deliberate break on the **dangling `else`**,
on the assumption it was silent. **It is not** — `-Wdangling-else` fires on both compilers. Recorded
explicitly so nobody re-proposes it.

Of M4's three named traps, checked under the course flags:

| Trap | clang | GCC | Usable as a "compiles clean" demo? |
|---|---|---|---|
| `=` vs `==` | warns | warns | No — and the material correctly says so already |
| `switch` fall-through | silent | **warns** | No, not on the target toolchain |
| dangling `else` | **warns** | **warns** | No |

**None of the three is silent on GCC.** That is the real finding, and it is bigger than a wording fix:
`-Wall -Wextra` is a genuinely good pair of flags, and the course chose them precisely because they
catch this class of mistake. The material wants a trap the compiler misses; these flags were selected
so that it would not miss things.

## What needs to happen (#25)

The demo and the lesson can no longer both survive in their current form. Three honest options:

1. **Keep the demos, change the prose.** Show the real warning as verbatim compiler output and teach
   *the compiler caught this one — read what it says*. Costs the deliberate break its punchline, but it
   is truthful, it uses output students will actually see, and reading diagnostics is a course goal in
   its own right.
2. **Keep the lesson, swap the demo for a genuinely silent Logic error.** Two candidates were
   **tested, not assumed** — the mistake this finding was created by:

   | Candidate | GCC 16 | clang 21 | Misbehaves? |
   |---|---|---|---|
   | Mis-ordered chain — `>= 40` before `>= 70`, making a branch unreachable | **silent** | **silent** | yes: strength 85 prints *"Borderline. A riddle."* |
   | Off-by-one at the boundary — `> 70` where `>= 70` was meant | **silent** | **silent** | yes: strength 70 prints *"Turned away."* |

   Both compile with **zero warnings on both compilers** and both do visibly the wrong thing, which is
   exactly the demonstration the deliberate break was built to give. Both are **Logic** errors by the
   course's own taxonomy, and both are already in M4's vocabulary — the module already teaches
   "highest bar first," and `assess-lab.md` already calls boundary off-by-one "the most common Logic
   error here." So the replacement reinforces existing material instead of introducing a new idea.
3. **Drop the zero-warning framing for the demo only**, telling students explicitly that this one
   exercise is expected to warn. Cheapest, but it puts an exception inside the rule the course is
   strictest about, and exceptions to a zero-tolerance rule teach that the rule is negotiable.

**Recommended: option 2, using the mis-ordered chain.** It is the only candidate that is silent on both
compilers, genuinely wrong at runtime, and already taught in the module. Option 1 remains a good
*addition* rather than a replacement: the fall-through warning is real output students will meet, and
showing it as verbatim compiler text is worth doing on its own merits — just not while claiming the
compiler said nothing.

Whichever is chosen, **`learn.md` and `apply-tutorial.md` must be fixed together.** They make the same
claim, and issue #14 was the last time these files were allowed to disagree about a compiler warning.

## The gate itself has been running on the wrong compiler

The reason this survived M4's certification is bigger than the claim: **this repo's compile gate has
been running under Apple clang, not GCC.** `g++` on the build machine *is* clang. The course targets
GCC/Ubuntu via Codespaces. Every "clean compile" certification to date was made against a compiler
students do not use.

Re-gated everything on this branch under GNU g++ 16.1.0, course flags:

| Artifact set | Result |
|---|---|
| `_contracts/m4_gatekeeper.cpp`, `_contracts/m5_menu.cpp` | **both clean** — the frozen contracts survive the swap |
| `modules/m4/code/` — 9 of 10 files | **clean** |
| `modules/m4/code/practice-item5-fallthrough.cpp` | **WARNS** — `this statement may fall through [-Wimplicit-fallthrough=]` |

So M4's certification very nearly survives: **one shipped code file** fails mechanical bar #1 on the
real toolchain, and it is — consistently with everything above — the fall-through demo. It backs an
M4 exit-ticket item, so this is not only prose: a student compiling that file in Codespaces gets a
warning the course's own zero-warning rule calls a failed build.

**Two consequences beyond fixing the file:**

1. **The compile-warden should run GCC**, not whatever `g++` resolves to locally. Until it does, "gate
   green" means "green on clang." Options: a `gcc:13` container, a CI job on `ubuntu-latest` (this repo
   has **no CI at all** today), or requiring the warden to run in Codespaces.
2. **M5 has not been re-checked.** Its sources live on `module/m5-deep` (PR #20) and were not on this
   branch, so they were never compiled under GCC here. M5 is **Built-not-Ready** and its cohort round
   is still ahead of it — re-gating it under GCC belongs in that round, before certification, not after.

## Verification status

Confirmed locally on **GNU g++ 16.1.0** (Homebrew) and **Apple clang 21.0.0**. Still worth confirming
on **Codespaces / Ubuntu**, which ships an older GCC (12–14) and is the environment students actually
use. `-Wimplicit-fallthrough` has been in `-Wextra` since GCC 7 and `-Wdangling-else` far longer, so
the result is expected to hold — but "expected to hold" is exactly the reasoning this finding exists to
punish. Handoff procedure: `_lore/findings/F-009-verification-procedure.md`.

## The general lesson

The compile-warden runs on one machine, and **`-Wall -Wextra` is not the same warning set on GCC and
clang**. Any material asserting compiler **silence** — as opposed to quoting compiler output — must be
verified on the toolchain students actually use. Silence is the one result that looks identical whether
or not you tested it.
