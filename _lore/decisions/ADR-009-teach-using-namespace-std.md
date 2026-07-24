# ADR-009 — Teach `using namespace std;` on purpose

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Cowork session
**Relates to:** `CLAUDE.md` voice/quality bars; the `_contracts/` programs; the skill guild.

## Context

Most C++ references advise against `using namespace std;` — it pollutes the global namespace
and, in large multi-TU codebases, invites ambiguity and hard-to-trace collisions. CSC-134 is an
intro course: single-file, single-translation-unit, `main`-only programs written by students who
have never programmed. For that audience, `std::` prefixed onto `cout`, `cin`, `string`, `endl`
on nearly every line is a constant, per-line stumbling block that adds visual noise to exactly
the moments a beginner is trying to parse basic I/O.

The convention was already de facto in the build (both `_contracts/*.cpp` and the guild templates
use it); this ADR makes it an **explicit, defended decision** rather than an unexamined habit —
which matters precisely because the standard advice runs the other way, so instructors, reviewers,
and program-review audiences will ask.

## Decision

**Student-facing CSC-134 code teaches and uses `using namespace std;`.** It appears in readings,
tutorials, labs, and the canonical contract programs. `std::` prefixes are not required in
student deliverables and are not marked wrong.

Owner's framing, for the record: *namespace pollution is a mote, compared to the beam that is
making a brand-new coding student trip over `std::cout` on every line.* The pollution objection is
knowingly set aside because it does not bite in single-file, single-TU freshman programs; the
readability gain for beginners is real and immediate.

## Consequences

- `CLAUDE.md`'s honest-freshman-C++ bar is upgraded from "`using namespace std;` is fine" to
  "taught on purpose," pointing here.
- No reconciliation needed in `_contracts/` or the guild templates — they already comply.
- Compiler diagnostics still print `std::` (e.g. `std::string`); that is the compiler's output,
  not student-authored code, and is left as-is in error-reading examples.
- Where/if the program later reaches multi-file work (capstone territory), a follow-up ADR may
  introduce the `std::`-qualified habit as a graduation step — deferred, out of alpha scope.
- This is a locked course convention; changing it requires a superseding ADR.
