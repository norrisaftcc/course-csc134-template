---
> **NOT YET AUTHORED — STUB**
> This is a skeleton of what the M8 Assess-beat artifact *will be*, not the
> lab itself. No student-facing prose below is final; no acceptance criteria
> here are complete. Deep-build (via the `lab-creator` skill) replaces this
> file's content with the real capstone brief — do not hand this stub to
> students.
---

# M8 Assess Spec — STUB

**Spine anchor:** "The whole arc, run once, end to end, by you... 1. Problem
formulation — front-loaded and graded heavily... a design document due
before any code. 2. Implementation... built in stages, each of which
compiles and runs as a standalone program. 3. Presentation. Demo working
software; explain what it does, what decisions were made, and show it meets
the spec." — `_storming/CSC-134-course-spine.md`, M8 section.

**Measured by** (learning-objectives doc): "the capstone (design doc +
staged implementation + presentation)."

**MLOs this artifact must exercise:** MLO 8.1 (design document before code),
MLO 8.2 (staged implementation against a self-authored spec), MLO 8.3 (test
and debug across the error taxonomy), MLO 8.4 (present and defend, AI use
documented). See `_mlos.md`.

**Shape difference from every earlier module's Assess artifact:** M7 and
earlier assess *one shared program* every student builds toward the same
spec. M8 assesses *the process and a student-authored spec* — the artifact
is design doc + staged build + defense, not a single fixed-signature
program. The acceptance-criteria skeleton below is written accordingly: as
contracts on the *process artifacts* (design doc, stage sequence,
presentation), not as function signatures on a shared program.

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete field names, counts, and thresholds at deep-build time. The four
tiers below are **cumulative** — each includes everything the tier below it
requires (per the rubric-template's tier-ladder semantics).

```
[C tier — the minimum complete arc]
designDocument(problem: student-chosen, scoped-to-M7-and-earlier-skills)
  -> DesignDoc: { problemStatement, userStories[], spec, flowchart }

  PRECONDITIONS (what the student may assume):
    - the problem is theirs to choose, within a scope boundary TBD at
      deep-build (e.g., "must use at least one struct or class from M7")
    - the design document is due and reviewed BEFORE any code is written
      (spine: "front-loaded and graded heavily") — a design doc submitted
      after code exists does not satisfy MLO 8.1, regardless of quality

  POSTCONDITIONS (what "correct" means):
    - problemStatement names a real, scoped problem (not "make a game" with
      no boundary)
    - userStories[] uses the "As a ___, I want ___, so that ___" form
      taught since M1
    - spec is concrete enough that a *different* reader could tell whether
      the finished program meets it (TBD: minimum spec content — inputs,
      outputs, at least one struct/class shape)
    - flowchart is Mermaid, renders, and traces the program's actual control
      flow (not a generic SDLC diagram restated)

  FAILURE CASES (must be named, not just handled silently):
    - a spec vague enough that "meets the spec" is unfalsifiable
        -> this is a SEMANTIC gap in the design document itself (the spec's
           meaning is ambiguous, not that any code is wrong yet) — TBD at
           deep-build how this is scored if caught only at presentation time
    - flowchart drawn from memory of the SDLC diagram rather than the
      student's actual planned logic
        -> not a compile-time error at all; a Completeness-column gap the
           rubric must name explicitly, not assume graders will catch

buildStage(n: int, priorStages: Program[]) -> Program
  each stage: compiles clean, runs standalone, demonstrably does MORE than
  stage n-1 (not a rewrite-from-scratch at each step)

  POSTCONDITIONS:
    - every stage compiles under g++ -std=c++17 -Wall -Wextra, zero warnings
    - every stage RUNS and produces observable output — "compiles" alone
      does not satisfy a stage
    - the final stage's behavior traces back to the design document's spec
      (a reviewer can point at a user story and find where the final
      program satisfies it)

  FAILURE CASES:
    - a stage that compiles but was never actually run/verified before the
      student moved to the next stage
        -> this is exactly the kind of unverified claim the course's own
           evidence-over-assumption principle exists to catch; TBD whether
           the rubric requires stage-by-stage run evidence (e.g., a captured
           terminal transcript) or trusts the final demo alone
    - a "staged" build that is actually one big program written at once and
      artificially split into commits after the fact
        -> LOGIC of the assignment's intent is violated even though the
           code may be correct; TBD at deep-build how staged-ness is
           verified rather than just claimed

[B tier — adds]
  TBD at deep-build: candidate is "a second, harder user story" — the
  design document commits to one additional feature beyond the C-tier
  minimum, and the staged build demonstrably implements it as its own
  stage, not folded silently into the C-tier stages.

  FAILURE CASES: TBD — likely candidate is scope creep discovered only at
  presentation time (a B-tier feature promised in the design doc but never
  actually built), which is a Completeness gap, not a Correctness one.

[A tier — adds]
  TBD at deep-build: candidate is "synthesis across M7's full struct→class
  arc" — e.g., more than one interacting class/struct type (the spine's
  running example: Room + Hero + Monster from M7, but the student's own
  problem need not literally reuse those names), with behavior that
  couldn't be achieved by a single struct alone.

  FAILURE CASES: TBD — likely candidate is classes that exist but never
  actually interact (e.g., two unrelated classes bolted together to satisfy
  a headcount, not because the problem needed them) — a Completeness/design
  gap the rubric must be explicit about, not an implicit taste judgment.

[Badge tier — adds]
  present(program: Program, designDoc: DesignDoc, promptsLog: prompts.md)
    -> Defense: { whatItDoes, decisionsMode, specMet: bool, aiUseDisclosed }

  POSTCONDITIONS:
    - the student can explain, live, a decision they made and why (not just
      read prepared text)
    - specMet is demonstrated against the ACTUAL design document submitted
      earlier — not a retroactively-rewritten spec that conveniently matches
      what got built
    - aiUseDisclosed matches the course's AI ladder (Scaffold /
      Explain-Then-Generate / Refactor / Debug / Review) — TBD at deep-build
      exactly how capstone's "formally owned at the capstone" AI-permission
      point (spine, AI collaboration policy section) changes what must be
      logged here versus at earlier labs; this is an open spine item, not
      decided by this stub.

  FAILURE CASES:
    - a student who can run the demo but cannot explain a decision when
      asked -> this is the exact gap MLO 8.4 and the spine's own
      "assessment logic" (grade what AI cannot do for you) exist to catch;
      TBD how heavily this weighs relative to the working code itself
    - AI assistance used but not disclosed -> a Submission-column violation
      (course-wide `prompts.md` honesty expectation), independent of
      whether the resulting code is correct
```

**Known trap to resolve at deep-build, not left implicit:** because M8 sits
at the spec-only end of the Make gradient, there is no shared "starting
program" every student's submission can be diffed against the way M2–M7
labs can be. Deep-build must decide how Correctness and Completeness are
scored against a *self-authored* spec without becoming purely subjective —
likely via the design document itself serving as the contract the finished
program is graded against (the student's own spec becomes the acceptance
test), rather than a single course-wide answer key. This is the single
biggest open design question this stub surfaces; it is not resolved here.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template; right column is skeleton-only,
**not yet filled with this capstone's real requirements.**

| Tier | Fixed meaning (course-wide) | M8 slot (TBD at deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] Design doc (problem statement, user stories, spec, flowchart) completed and reviewed BEFORE code; staged program that compiles/runs at every stage and meets its own spec's minimum case. MLO 8.1–8.3 proven. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: one additional user story, implemented as its own verifiable stage. |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: multiple interacting struct/class types (the M7 struct→class arc pushed into genuine composition), not a single-type program. |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: live presentation/defense that explains decisions, plus a complete `prompts.md` disclosing all AI assistance per the course's AI ladder. |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide; "what we're looking
for" cells are **unfilled placeholders**, not this capstone's real rubric
text.

| Criterion | Points | What we're looking for (TBD — deep-build fills per this capstone) |
|---|---|---|
| **Correctness** | 8 | [ ] — TBD: scored against the student's OWN design-document spec, not a shared answer key (see "Known trap" above). |
| **Completeness** | 6 | [ ] — TBD: every user story in the design doc has a corresponding, demonstrated stage. |
| **Format** | 3 | [ ] — must include: compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings, at every stage, not just the final one. |
| **Submission** | 3 | [ ] — correct file/folder/repo, committed and pushed (no branches — ADR-004; branching itself is named in the spine as "capstone-tier," so deep-build must confirm whether M8 is where branching enters the *student* workflow for the first time, or whether ADR-004's no-branches rule still holds through M8), `prompts.md` present and complete. |
| **Total** | **20** | |

"No hidden criteria" applies once this stub is instantiated: what's on the
capstone brief will be the whole rubric.

---

## Standing invariants (apply to every M8 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors, at every stage of the staged build. Run it; never claim a clean
  compile that wasn't executed.
- **Single-file form, post-M6 shape.** Prototypes at top, `main` in the
  middle, definitions at the bottom. No multi-file projects, no
  header/implementation split, even at capstone scale — the spine's
  single-file convention has no stated exception for M8.
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories. The capstone's own test/debug requirement
  (MLO 8.3) is exactly where a student must demonstrate fluency across all
  four, not just recognize them in a reading.
- **Mermaid flowcharts.** The design document's flowchart (MLO 8.1) is
  Mermaid-in-Markdown, renders natively, and is verified before hand-off —
  same standard as every earlier module's diagrams.
- **Make-gradient position: spec-only, the gradient's endpoint.** The Assess
  artifact hands the student a brief describing what the design document and
  staged build must contain — no starter codebase, no 80%-built program to
  finish. Do not backfill this with M5–M7-style scaffolding; the absence of
  a starting program is the point (see `_overview.md`).
- **No trick questions.** The design-document-first requirement and the
  staged-build requirement must both be stated up front, in full, before
  work begins — nothing sprung at presentation time that wasn't in the
  brief.
- **Dungeon theme, instructor-facing only.** The spine names the RPG/dungeon
  theme as "paying off" at M8 and the project as building on M7's structs
  and classes — this can inform the brief's example framing (e.g., a sample
  problem statement using Room/Hero/Monster) but the actual capstone problem
  is student-chosen; any build-org canon notes, contract provenance, or
  answer-key reasoning about *why* the dungeon theme was chosen must stay
  out of what students see.
