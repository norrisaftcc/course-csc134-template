# `instructor-guide/` — behind the screen

Material for **instructors and developers**. Nothing in here is student-facing, and
nothing in here is graded.

The folder name is not invented: `_storming/CSC_DASH_CROSSWALK.md:61` already adopts
`instructor-guide/` as part of the finished-state layout it blesses as *target grammar*
for what "done" looks like past the alpha. This is that row coming due.

## What lives here

| Document | For |
|---|---|
| [`ENVIRONMENTS-AND-COMPILERS-FAQ.md`](ENVIRONMENTS-AND-COMPILERS-FAQ.md) | Which compiler runs where, why it matters, and every dial you can turn |

## What will live here

- **Cohort harvest material.** The cohort-lead turns synthetic-student failure
  transcripts into instructor-guide entries — "here is where students actually get
  stuck, in their words." That is the folder's main long-term job.
- **Per-module teaching notes**, as modules reach Ready.

## How this differs from `_lore/`

They answer different questions, and mixing them makes both worse.

- **`_lore/`** is the *wall of record* — ADRs and findings, written when a decision
  or discovery happens, never rewritten afterwards. It answers **"why is it like
  this?"** and its value is that it is immutable and dated.
- **`instructor-guide/`** is *orientation* — derived, rewritten freely as things
  change, organised for someone trying to get productive. It answers **"how do I
  work here?"**

So a finding gets recorded in `_lore/` once and stays put. The FAQ then summarises
what that finding means for daily work, and gets edited whenever the answer changes.
When they disagree, `_lore/` is right and the guide is stale.

## Voice

GameFAQs register, same as the student material — warm, direct, second person, a
little playful — because it is read the same way: skimmed under time pressure, with
Ctrl+F, by someone who wants an answer rather than a narrative.
