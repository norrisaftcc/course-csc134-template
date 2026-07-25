# ADR-012 — The Canvas page compositor enters alpha scope

**Date:** 2026-07-25 · **Status:** Accepted · **Deciders:** norrisa (ruling) + Cowork session
**Relates to:** [[ADR-000-the-repo-is-the-wiki]], [[ADR-004-two-tier-git-workflow]],
[[F-008-canvas-compositor-import]] · **Pends:** ADR-013 (Haiku persona)
**Amends:** `_storming/ULTRACODE_ALPHA_PLAN.md` §1, `_storming/CSC_DASH_CROSSWALK.md` row `canvas-export.js`
**Closes:** #18 · **Answers the shared-pipeline question in** #19

## Context

Canvas/LMS packaging was recorded as **out of alpha scope in two places**:

- `_storming/ULTRACODE_ALPHA_PLAN.md` — "Out of scope for alpha: … Canvas/LMS packaging"
- `_storming/CSC_DASH_CROSSWALK.md` — `canvas-export.js` → **Defer**, "LMS packaging is out of alpha scope"

A Canvas page compositor was then developed in a parallel session and judged the best fit for
CSC-134's uses. Issue #18 took the ruling in advance: **amend the scope by ADR rather than
reinterpret the record**, so the wall never sits in contradiction with itself.

The original descope was sound at the time. It was aimed at *packaging* — the export tooling and
LMS plumbing that turns a finished course into a deployable package, which is real work with no
bearing on whether the alpha's modules are any good. What arrived is a different animal: a
**composition** skill that renders existing module Markdown into sanitizer-safe Canvas HTML. It
produces the artifact an instructor pastes into a page. It ships nothing, packages nothing, and
automates no LMS API.

## Decision

**Canvas *composition* is in alpha scope. Canvas *packaging* stays out.**

1. The `csc134-canvas-compositor` skill is installed at `.claude/skills/csc134-canvas-compositor/`
   and is a builder-invoked skill, listed in the CLAUDE.md skill guild.
2. **Compositors are per-course forks.** This one is CSC-134's. Sibling courses fork it — a
   capstone carries considerations an intro C++ course does not. The shared 80% (sanitizer rules,
   design tokens, placeholder discipline, the wrapper trick) is what a fork inherits; the dial
   tables and the voice roster are what a fork replaces.
3. **Composed pages are build output and live in `_outputs/`,** never in `modules/`. The module
   Markdown is the single source of truth; a composed page is derived and is never hand-edited.
   Output is committed so formatting changes are reviewable in a diff, and for no other reason.
   See `_outputs/README.md`.
4. **The compositor is presentation only.** It decides how a voice is *shown*, never what the
   course *says*. Content arriving inside a formatting skill is a layering violation and is
   split back out — which is why the Haiku persona is frozen pending ADR-013 rather than adopted
   on this PR.
5. **Mechanical bars #1 and #5 apply to HTML output.** They do not get a pass because the target
   is not Markdown. `gate.py` ships with the skill and enforces them.
6. Still out of scope: `canvas-export.js`, LMS API automation, course-package generation, and
   term-rollover tooling. The `canvas-export.js` row stays **Defer**.

## The shared-pipeline question (#19)

Both #18 and #19 render module content to static HTML, and whichever was designed first had to
settle whether they share a pipeline. Designing #18 first answered it:

**Shared source, shared tokens, separate emitters.**

They target incompatible environments. A Canvas page is a *fragment* pasted into the RCE, which
sanitizes on save: no `<style>`, no `<script>`, no `<svg>`, no `<details>` — so Mermaid cannot
render and diagrams degrade to character diagrams or uploaded SVG. A mini-textbook page is a
*document* served as a static file, where all of those are available and Mermaid renders natively.

A single renderer spanning both would have to emit for the strictest target and throw away what
the looser one allows. That is not one pipeline; it is one pipeline plus a permanent apology.
What they genuinely share is upstream of the emitter — the module Markdown, the design tokens,
and the readability and compile bars — and that is where reuse belongs.

This is a decision about *rendering*, not a scope ruling for #19. Whether the mini-textbook is in
the alpha at all remains open.

## Consequences

- The record no longer contradicts itself: both `_storming/` files carry the amendment and point here.
- M4 gains composed Canvas output as the worked demonstration, verified end to end (see F-008).
- Every future module build acquires a fifth optional artifact — the composed page — which is
  cheap because it is derived, and which will churn as formatting is tuned.
- The per-course fork model means a compositor bug fixed here does **not** propagate to sibling
  courses automatically. Accepted deliberately: the alternative is a shared skill with a course
  switch, which is the drift-prone shape the fork was chosen to avoid.
- A page can now be authored that a student cannot read, because the sanitizer silently destroys
  violations. `gate.py` is the mitigation and is not optional.
