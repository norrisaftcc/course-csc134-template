---
name: rubric-converter
description: "Transform CSC-134 assignment requirements into tiered C/B/A/Badge rubrics built on the four Robot Sandwich columns"
allowed-tools: "Read,Write,Glob,Grep"
---

# Rubric Converter

Transform assignment requirements into the course-standard tiered rubric: **C / B / A / Badge** tiers scored across the four columns every CSC-134 rubric inherits from the Robot Sandwich — **Correctness, Completeness, Format, Submission**.

## When to Use This Skill

- Creating the rubric for a new lab, project, or the capstone
- Converting a legacy or external rubric into course format
- Standardizing evaluation across sections/graders
- When asked to "create a rubric for X"

## The CSC-134 Rubric Model

### Tiers, not levels

Grading is **tiered by what the student attempted and completed**, not a 1–4 quality scale. Tiers nest: B contains all of C; A contains all of B.

| Tier | Meaning |
|------|---------|
| **C** | Core competency demonstrated — the module's MLO, working |
| **B** | Added depth or a second concept |
| **A** | Synthesis or extension |
| **Badge** | Documentation/reflection above and beyond (e.g., a complete `prompts.md`, a hand-drawn trace table). Not extra code. |

A student who earns a clean C has a **working program** and a passing grade. The tiers are an invitation upward, not a deduction ladder downward.

### The four columns (inherited from the Robot Sandwich)

Every tier is evaluated on the same four columns:

| Column | Asks | For C++ work, typically |
|---|---|---|
| **Correctness** | Does it do what the spec says? | Matches sample runs; correct results on listed test inputs |
| **Completeness** | Is everything there? | All requirements of the claimed tier present; required design artifacts (Mermaid flowchart, pseudocode) included |
| **Format** | Is it professionally presented? | **Clean compile under `g++ -std=c++17 -Wall -Wextra` — zero warnings (hard bar for any C++ tier)**; single-file convention (prototypes top, `main` middle, definitions bottom — from M6 on); meaningful names; readable output |
| **Submission** | Did it arrive correctly? | Right files, right names, pushed to GitHub, visible in the repo |

The Format column's clean-compile requirement is **non-negotiable** on any tier of any C++ assignment. Warnings are not style points; they fail the column.

### Rubric Structure

```markdown
---
rubric_type: "[lab|project|capstone|communication]"
assignment: "[Assignment name]"
module: M0X
version: "1.0"
---

# Rubric: [Assignment Name]

## Overview
[What this evaluates; which MLOs it measures]

## Tier Requirements

### C Tier — [grade value]
| Column | Criteria |
|--------|----------|
| Correctness | [Observable: which sample runs must match, which inputs must work] |
| Completeness | [Observable: which requirements/artifacts must be present] |
| Format | Clean compile, zero warnings (`g++ -std=c++17 -Wall -Wextra`); [naming/structure specifics] |
| Submission | [Exact files, pushed to GitHub by deadline] |

### B Tier — [grade value]
Everything in C, plus:
| Column | Criteria |
...

### A Tier — [grade value]
Everything in B, plus:
...

### Badge — [name of badge]
[Observable documentation/reflection criteria — e.g., prompts.md contents]

## Grading Notes
[Partial-credit guidance, calibration examples, common borderline calls]
```

## Writing Observable Criteria

**Observable** = verifiable by running the program or looking at the repo. **Not observable** = requires mind-reading.

| Not Observable ❌ | Observable ✅ |
|-------------------|---------------|
| "Understands loops" | "Menu re-displays after each choice and exits only on option 4" |
| "Good input validation" | "Entering a word at a number prompt re-prompts instead of looping forever (`cin` fail state cleared)" |
| "Shows effort" | "At least 3 commits with messages describing what changed" |
| "Clean code" | "Compiles with zero warnings under `-Wall -Wextra`; variables named for their contents" |
| "Used AI responsibly" | "`prompts.md` lists each prompt used and one sentence on what was changed before use" |

Criteria formula: **[Artifact] + [behavior when run/inspected] + [specific threshold]**.

### Differentiating tiers

Tiers differ by **what was built**, not by adjectives:
- ❌ B = "C but done well" — that's a quality scale in disguise
- ✅ B = "C's menu, plus input validation surviving the `cin` fail state"
- ✅ A = "B, plus an array search feature with aligned table output"

If you can't name the *additional concept or synthesis* a tier adds, the tier isn't defined yet — go back to the assignment.

### Badge criteria

Badge is the honesty-and-communication tier. Standard badge patterns:
- **AI citation badge**: `prompts.md` present, lists every prompt, notes what the student changed or rejected
- **Trace badge**: hand-drawn (photographed) or Markdown trace table for the core loop, committed to the repo
- **Reflection badge**: short written answer connecting the lab to the module concept, meeting a stated word floor

Badge never requires more code, and never rescues a failed column elsewhere.

## Error-Taxonomy Alignment

When rubrics reference bugs or testing, use the course's four terms — **syntax, static semantic, runtime, logic** — exactly. Example Correctness criterion: "Program handles the three listed hostile inputs without runtime errors; any remaining defects are logic-level, documented in the README."

## Mapping Grades

Default mapping (adjust to the syllabus if it specifies otherwise):

| Outcome | Grade |
|---|---|
| A tier, all four columns met | A |
| B tier, all four columns met | B |
| C tier, all four columns met | C |
| Attempted, columns partially met | D-range at grader's discretion, with notes |
| Badge | Recorded toward the module badge/microcredential; may bump a borderline call up |

Grading notes should state how column failures interact with tiers — the standard rule: **you earn the highest tier at which all four columns pass.** An A-tier feature set with a warning-laden build grades as the highest tier that passes Format… which is none until it compiles clean. Say this kindly and plainly in the rubric.

## Calibration Examples

Include at least one per ambiguous criterion:

```markdown
## Grading Notes

**Correctness, B tier**: "Validated input" means: entering `banana` at the
menu re-prompts. It does NOT require handling Ctrl-D/EOF — that's beyond
scope this module. If the program survives `banana` but accepts `-3` as a
menu choice, that's B-tier Correctness partially met: note it, grade C+notes.

**Format, all tiers**: One warning = Format not met. Point the student at
the exact warning text; this is a fix-and-resubmit conversation, not a
penalty conversation, where resubmission policy allows.
```

## Quality Checklist

Before completing a rubric:

- [ ] Uses C / B / A / Badge tiers; tiers nest explicitly ("Everything in C, plus…")
- [ ] All four Robot Sandwich columns present at every tier
- [ ] Format column includes the `g++ -std=c++17 -Wall -Wextra` zero-warning bar (for C++ assignments)
- [ ] Single-file convention referenced only from M6 onward
- [ ] Every criterion is an observable behavior with a threshold
- [ ] Tiers differ by added concept/synthesis, not adjectives
- [ ] Badge is documentation/reflection, never code
- [ ] Bug/testing language uses the four-term error taxonomy
- [ ] Highest-tier-where-all-columns-pass rule stated
- [ ] Calibration notes cover the predictable borderline calls
- [ ] No trick criteria; a student reading the rubric can self-grade before submitting
- [ ] A different grader would land on the same tier

## Common Conversions

### From a checklist
Group items into columns, then ask of each: is this core (C), depth (B), or synthesis (A)? Anything about docs/reflection becomes Badge.

### From a percentage rubric
Drop the point math. Find the "passing" description → C tier. Find what distinguished 85% from 75% → that concept is the B increment. The 95% distinguishers → A.

### For non-code assignments (M0–M2)
Same four columns; Correctness becomes "Precision" where the artifact is instructions or a flowchart (the Robot Sandwich's own usage). The clean-compile bar is replaced by the artifact's format bar (e.g., Mermaid renders on GitHub without errors).

### For the M8 capstone
Weight formulation and presentation heavily: the design document (problem statement, user stories, spec, Mermaid flowchart, due before code) and the demo/defense are their own graded artifacts with the same four columns. The rubric grades the two things AI cannot do: knowing what to build, and standing behind what was built.
