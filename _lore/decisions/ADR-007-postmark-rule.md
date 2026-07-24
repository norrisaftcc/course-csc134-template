# ADR-007 — The Postmark Rule (late policy)

**Date:** 2026-07-24 · **Status:** Accepted · **Deciders:** norrisa

## Context

113 had a useful late-policy pattern ("Sacred Flow Exception": visibly start by deadline →
24-hour extension). Separately, the owner's standing practice: late penalties are *reversed*
when a student can show a commit that wasn't late, even if delivery/notification was.
Both wanted a 134-native form, now that the Mail Run metaphor exists.

## Decision

**The Postmark Rule:** the commit timestamp is the postmark. A package postmarked on time
counts as on time, even if it reaches the instructor's desk late (late push, LMS hiccup,
notification miss). Corollary (the 113 pattern, translated): a package *visibly in progress*
by the deadline — commits showing real work — earns a 24-hour grace to finish the run.

The rule is evidence-based on purpose: it pays students for exactly the habits M1 teaches
(commit early, label honestly, push often), and it makes git history the student's *ally*
in a dispute rather than the instructor's surveillance tool.

## Consequences

- Syllabus/lab boilerplate gets one line: "Your commit history is your postmark."
- Cheap to game only by faking commits — which is a far higher-effort, more clearly
  dishonest act than the fuzziness it replaces; the honesty framing from the AI-log
  red-flags list applies.
- Reinforces the Mail Run: students who never push still have no postmark — the box on
  your desk was never mailed.
- Imported 113 materials referencing the "Sacred Flow Exception" are rewritten to this rule.
