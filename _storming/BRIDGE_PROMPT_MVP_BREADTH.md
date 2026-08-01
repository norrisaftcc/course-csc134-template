# BRIDGE PROMPT — plan the MVP breadth pass (M0–M8)

```text
UNCLASSIFIED // FLEET USE // drafted 2026-07-29 · for a Claude Code instance in course-csc134-template
```

> **BLUF:** You are planning, not building. The owner wants a **minimum-viable version of every
> module M0–M8** so the spine can be checked against something real instead of against nine
> scaffolds. Your job this run is to produce the fan-out spec, the scope amendment it requires,
> and the instrument that makes the exercise pay off. **Author no lesson content. Create no
> module files.** Work in plan mode; land your output by branch + PR (ADR-004 build flow).

## Read first (ground truth, in this order)

1. `_storming/CSC-134-course-spine.md` — ground truth for everything.
2. `CLAUDE.md` — the eight mechanical bars. They are not negotiable at MVP depth.
3. `_tracking/skeleton-plan.md` — v0.6, authoritative for the existing scaffold. **This is the
   house format for the document you are about to write.** Match its shape: namespace call,
   per-module file set as a table, strict non-clobber policy, module identity table.
4. `_lore/decisions/ADR-001-alpha-scope-and-locked-decisions.md` §1 — read it carefully; see
   *The scope problem* below.
5. `_lore/decisions/` — the whole wall, ADR-000…016. 013 is reserved (issue #23), 016 is
   Proposed, not Accepted.
6. `modules/m4/` — the depth benchmark. Everything you spec is defined relative to it.
7. `_storming/VERIFIER_BRIEF.md` — the read-only verifier; your plan schedules it, it does not
   report to you.

## The scope problem — name it, don't route around it

ADR-001 §1 locked the alpha as **skeleton + exemplar pair** and explicitly **rejected** the
alternative: *"full horizontal build at C-tier polish — review checkpoint before bulk spend won."*

What the owner is now asking for is that rejected option. That does not make it wrong: the
condition the rejection rested on has since been satisfied. M4 was built, taken by a cohort,
found defective in ways nobody predicted (F-005, F-009, F-010), fixed, and gated in CI. The
review checkpoint happened and it taught us things. Spending bulk effort now is a different bet
than spending it in week one.

So: **the amendment is legitimate, and it must be an ADR, not a reinterpretation.** ADR-012 is
your precedent — it amended a two-place descope rather than arguing the record had meant
something else all along. Draft **ADR-017** with `Status: Proposed`, superseding ADR-001 §1,
and let the owner rule. Your plan is contingent on that ruling; say so in its header.

While drafting it, argue the *actual* trade honestly, including the case against: nine MVP
modules is nine times the surface area for the F-009 defect class (false claims in prose sitting
on top of correct code), spread across material no cohort has taken. Depth found those defects.
Breadth will not. What breadth buys is the thing depth cannot: **whether the spine's arc
survives instantiation end to end.** Make the ADR say which of those the owner is buying.

## What you must decide (recommend; do not punt to the human)

The owner's instruction was one sentence. These are the decisions hiding inside it. Give each a
recommendation with a reason, in the plan.

1. **Define the MVP depth band.** There are now three: skeleton (the four `_`-prefixed files),
   MVP (new), deep (M4). Specify MVP as a **file set + obligation set**, the way skeleton-plan §2
   does — a table, one row per file, "must contain" written tightly enough that nine parallel
   builders produce comparable artifacts. State explicitly what MVP **excludes**, because that
   list is what stops this becoming a full build by accretion.
2. **Every gate applies at MVP depth.** A cheaper artifact does not get a cheaper bar. Work out
   what that costs: every `cpp` fence needs a gated `.cpp` behind it with exact `source=` /
   `excerpt=` provenance (ADR-015). Consider recommending that **M4's 23-block migration
   (issue #30) lands first**, so the markdown gate is green before eight more modules pile onto
   a known-red signal — a countdown nobody can read is a countdown nobody watches.
3. **Sequencing and parallelism.** Graduate-and-teach (ADR-001 §2) is serial by design and it is
   the mechanism, not overhead. But M0–M3 do not depend on M5+, and the plan's §8 warning against
   "optimizing M4 and M5 into parallel builds" was about the *deep* seam. Draw the real dependency
   graph: what genuinely fans out, what stays serial, and where MVP-depth builders may work from
   a contract instead of from a graduate.
4. **M5's status.** There is a `module/m5-deep` branch and M5 is skeleton-only on `main`. Decide
   whether M5 finishes deep first (preserving the M4→M5 seam ADR-001 promised) or drops to MVP
   with the rest. Recommend one. The seam is the demonstration the alpha was built to make.
5. **QA at breadth.** Loop-until-dry with three personas × nine modules is not affordable and you
   should not pretend otherwise. Propose a reduced instrument and say what it gives up — one
   persona per module, or a single fresh spawn reading M0→M8 in order as one continuous student.
   Note that the persona sheets in `_storming/personas-134/` are **still drafts pending owner
   approval** (Phase 0.5 gate); anything you schedule against them is contingent.
6. **The spine-check instrument — this is the point of the exercise.** An MVP pass that produces
   nine modules and no verdict on the spine has failed. Specify the deliverable that answers:
   does the LPAA loop hold in every module, does the Make gradient actually shift where the spine
   says (M2–M4 type-in → M5–M7 finish-80 → M8 spec-only), do the MLOs cover the CLOs with nothing
   orphaned, does the M(N)→M(N+1) prerequisite chain hold, and does the PRISM arc land where
   INFRARED→RED→ORANGE says it should. Name the artifact, its owner, and when it runs.
7. **Stopping rules.** What "MVP done" means per module as a checklist a builder can self-check,
   and what a builder does when a module's spine material is thin (M7's imports are not yet in
   the tree; M8 is deliberately spec-only). Blocked-and-reported beats improvised.

## Standing guards (violating these is a blocker finding, not a style note)

- **ADR-011** — no STL unit, no File I/O unit. Incidental `std::string` only, M3/M5.
- **ADR-010** — M3 is remap-and-recreate with salvage; don't re-litigate it.
- **ADR-008 / skeleton-plan §3** — `assignments/` is **frozen**, a porting source only. Nothing
  in it gets created, edited, moved, or deleted.
- **ADR-009** — `using namespace std` is taught on purpose. "Fixing" it is the defect.
- **ADR-002** — rubric column one is **Correctness**; PR target is **`main`**, no `alpha` branch.
- **ADR-005 / 006 / 007** — undefended inputs are named in the lab text; Mail Run (never "Sacred
  Flow"), `prompts.md`, "exit ticket" = comprehension checkpoint only; every Submission section
  carries the postmark line.
- **ADR-014** — CI on GCC is the authority on compiler behaviour. Never assert compiler *silence*
  from a local macOS run. Quote a gate log or say nothing.
- **M6+ deep content stays out** until an ADR says otherwise — including ADR-017, if the owner
  rules that way. MVP depth is not a loophole into deep builds.

## Output contract (three files, then stop)

1. `_tracking/mvp-breadth-plan.md` — the authoritative fan-out spec, in skeleton-plan's format,
   marked `Status: Contingent on ADR-017`.
2. `_lore/decisions/ADR-017-<slug>.md` — `Status: Proposed`, deciders `norrisa (ruling pending)`,
   superseding ADR-001 §1, with the case against stated in full and alternatives considered.
3. A findings entry in `_lore/findings/` (next free F-number — do not fill the F-007/011/012
   gaps) recording what you found while reading: anything already inconsistent between spine,
   CLAUDE.md, the manifest, and the skeleton. You will read all of it closely; that is worth
   capturing whether or not the plan proceeds.

Then **run the verifier** (`_storming/VERIFIER_BRIEF.md`) before the PR, or say why not.

End with a one-paragraph plain-language summary for the owner: what you are proposing, what it
will cost, what you recommend he rule on first.

```text
END OF BRIEF // PLAN IT BEFORE YOU BUILD IT
```
