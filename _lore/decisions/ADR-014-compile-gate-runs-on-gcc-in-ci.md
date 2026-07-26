# ADR-014 — The compile gate runs GCC in CI, not the developer's local compiler

**Date:** 2026-07-25 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Cowork session
**Relates to:** [[F-009-fallthrough-warning-claim-is-toolchain-dependent]], [[ADR-000-the-repo-is-the-wiki]]
**Numbering note:** ADR-012 is claimed by the Canvas compositor (PR #24) and **ADR-013 is reserved**
for the Haiku persona ruling (issue #23, pinned but unwritten). This takes 014 rather than filling the
gap, per the CLAUDE.md rule against grabbing a contested number.

## Context

Mechanical quality bar #1 says every C++ artifact builds under `g++ -std=c++17 -Wall -Wextra` with zero
warnings. For the whole alpha, that was checked by running `g++` on a developer's machine.

On macOS, **`g++` is Apple clang.** The course targets **GCC on Ubuntu** — Codespaces is the student
environment. The two do not implement `-Wextra` identically: GCC has included
`-Wimplicit-fallthrough` in `-Wextra` since version 7; clang does not enable it by name.

So "gate green" meant "green on clang," and the difference was not academic. [[F-009]] found:

- a **shipped code file** in M4 — a module certified **Ready** — that warns on GCC and is silent on clang;
- **two false claims in student-facing prose** telling students that deliberately broken programs
  "compile clean," one of which is false on *every* compiler tested.

None of it was caught, because the gate could not see it. A gate that cannot fail is not a gate.

## Decision

**The compile gate runs in CI on `ubuntu-latest`, and CI is the authority.**

1. `.github/workflows/compile-gate.yml` runs on every push to `main`, every pull request, and on
   demand. Ubuntu's `g++` is GNU GCC, so the gate matches the student toolchain by construction rather
   than by anyone remembering to.
2. **Deliberately not a matrix.** No macOS lane, no clang lane. A green clang lane beside a red GCC lane
   invites "well, it passes somewhere," and the course has exactly one target environment.
3. **A warning fails the build.** The course rule is zero warnings, not zero errors, so
   `FAIL_ON_WARNING=1` is the default and the gate exits non-zero on a warning. Encoding "should be
   clean" as anything softer makes the rule advisory, and it already was.
4. **The gate logic lives in a script, not in YAML.** `.github/scripts/compile-gate.sh` runs identically
   in CI and on a laptop — `bash .github/scripts/compile-gate.sh`. An instructor should never have to
   push a commit to find out whether something compiles.
5. **The dials are explicit and documented** — `CXX`, `CXX_STD`, `WARN_FLAGS`, `FAIL_ON_WARNING`,
   `SEARCH_PATHS`, `VERBOSE` — as environment variables locally and as `workflow_dispatch` inputs in the
   Actions tab. A gate whose behaviour can only be changed by editing it gets edited casually and
   permanently; a labelled dial gets turned back.
6. **The toolchain is printed on every run.** When a result surprises someone, the first question is
   always "which compiler, which version?" The answer is in the log before anyone asks.

## Consequences

- The repo gains its **first CI**. Before this there was none at all.
- **`main` goes red on merge until #25 is fixed.** `modules/m4/code/practice-item5-fallthrough.cpp`
  genuinely warns on GCC. This is correct: red CI telling the truth beats green CI that is lying, and
  the alternative — an allowlist — would encode the bug as acceptable on the very day it was found.
- **M4's "Ready" certification is provisional** until it passes on GCC. It passes 11 of 12 files today.
- **M5 has never been gated on GCC.** Its sources are on `module/m5-deep` (PR #20). It is
  Built-not-Ready with its cohort round ahead, so the round inherits a gate that finally works.
- Local `g++` results are no longer evidence for a claim about compiler behaviour on macOS. Developers
  wanting a truthful local check need real GCC (`brew install gcc`, then `CXX=g++-16`) — or can just
  read CI.

## Known limitation, recorded rather than hidden

The gate compiles complete `.cpp` files. Bar #1 says *"every C++ block in every artifact"*, which
includes fenced blocks inside Markdown — and many of those are deliberate fragments that cannot compile
standalone. Extracting them needs a wrapping convention that does not exist yet. **Until it does, a
warning can hide in a Markdown listing that no `.cpp` file mirrors**, which is exactly where two of the
three F-009 defects lived. Closing that gap is the obvious next increment.
