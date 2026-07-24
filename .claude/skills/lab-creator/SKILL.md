---
name: lab-creator
description: "Create Assess-beat labs for CSC-134: spec-driven C++ assignments with tiered C/B/A/Badge requirements and GitHub submission"
allowed-tools: "Read,Write,Glob,Grep,Bash"
---

# Lab Creator

Create labs and homework for CSC-134's **Assess** beat — the Make stage of PRIMM. A lab hands students requirements + spec; they implement, test, and submit. This is where the training wheels from the Apply tutorial come off.

## When to Use This Skill

- Creating new lab assignments or module projects
- Converting an existing exercise into the tiered C/B/A/Badge format
- Building the capstone-stage briefs (M8)
- When asked to "create a lab for X"

## Lab Specifications

### Scope & Position
- **Duration**: 60–90 minutes of focused work (module projects may run longer; say so)
- **Deliverable**: one or more `.cpp` files (single-file convention) plus any required Markdown, committed and pushed to GitHub
- **Independence**: completable without the instructor present — the Apply tutorial already walked the pattern; the lab varies it
- **Tiered**: requirements are structured **C → B → A → Badge** (see below). Every lab has all four tiers.
- **Readability**: 10th-grade prose. The challenge is the problem, not decoding the prompt. **No trick requirements** — stated course policy.

### The Tier Structure

All labs descend from the Robot Sandwich's four rubric columns (Correctness / Completeness / Format / Submission) and use the program-wide tier ladder:

| Tier | Meaning | Example (loops module) |
|---|---|---|
| **C** | Core competency demonstrated | Menu loop runs, one option works, exits cleanly |
| **B** | Added depth or a second concept | All menu options work; input validated against the `cin` fail state |
| **A** | Synthesis or extension | Nested loop feature (e.g., room-by-room search); aligned output table |
| **Badge** | Documentation/reflection above and beyond | Complete `prompts.md` AI log, or a hand-drawn trace table photo committed to the repo |

Tier rules:
- Tiers **nest**: B includes all of C; A includes all of B. Write them so a student can stop at C with a working, submittable program.
- Each tier is testable by running the program — write tiers as observable behaviors, not effort.
- Badge is never code. It is communication: documentation, reflection, honest AI citation.

### Required Structure

```markdown
---
title: "MXLABY: [Lab Title]"
module: M0X
lpaa_beat: Assess
estimated_time: "XX minutes"
prerequisites:
  reading: "[Learn-beat reading]"
  exit_ticket: "Module X exit ticket (completion-gated)"
  tutorial: "[Apply tutorial]"
deliverables:
  - "mXlabY.cpp"
  - "[README.md / prompts.md if required]"
---

# MXLABY: [Title]

## The Mission
[1-2 paragraphs: what you're building and why. Dungeon skin welcome here.]

## Specification
[The contract: inputs, processing, outputs. Sample runs. This section must
survive with all theme removed.]

## Requirements by Tier
### C Tier — [name]
### B Tier — [name] (everything in C, plus...)
### A Tier — [name] (everything in B, plus...)
### Badge — [name]

## Sample Runs
[Exact expected terminal sessions, one per tier where behavior differs]

## Design First
[Required design artifact if any: Mermaid flowchart, pseudocode, user story]

## Getting Started
[Starter code if provided; build/run commands]

## Testing Your Work
[Concrete cases to try, including the failure cases; trace-table prompt where relevant]

## Troubleshooting
[Common issues, organized by error class]

## Submission
[Exact files, exact GitHub workflow, quality check]
```

## Section-by-Section Guidance

### Specification
This is the load-bearing section — M8 grades students on writing these themselves, so every lab models a good one:
- Inputs (what the user types), processing (what the program computes), outputs (what prints)
- At least one **sample run** in a fenced block, showing the exact terminal session including user input
- If the lab starts from a design artifact, include the **Mermaid flowchart** or pseudocode and require code to match it. At least once per course, run the reverse: give code, require the recovered flowchart.

### Starter Code
When providing starter code:
- It must **compile clean** under `g++ -std=c++17 -Wall -Wextra` exactly as given, with stubs clearly marked:

```cpp
// TODO(C tier): validate the menu choice here.
// A wrong choice should re-prompt, not crash.
```

- Follow the single-file convention: prototypes top, `main` middle, definitions bottom — **from M6 onward**. M3–M5 starter code is `main`-only.
- No machinery from future modules (no functions before M6, no pointers before M7).

### Build & Run Commands
Always the course-standard invocation, spelled out:

```bash
g++ -std=c++17 -Wall -Wextra -o mXlabY mXlabY.cpp
./mXlabY
```

State the quality bar explicitly: **zero warnings**. Warnings fail the Format column.

### Testing Your Work
Make verification a taught behavior, not an afterthought:
- List concrete inputs to try, including hostile ones ("type `banana` when asked for a number")
- For loop labs, prompt a trace table: "Before running, fill in the table for i = 0..4"
- Frame each anticipated failure by its error class: *"If it compiles but repeats forever, that's a logic error — the loop condition never becomes false."*

### Troubleshooting
Organize by the error taxonomy, so the taxonomy does the diagnostic work:

```markdown
### It won't compile (syntax / static semantic)
**`expected ';' before ...`** — syntax: check the line above the one reported.
**`cannot convert 'std::string' to 'int'`** — static semantic: the types disagree...

### It compiles but crashes or hangs (runtime)
...

### It runs but the answer is wrong (logic)
...
```

### Submission
The workflow is always the same and always spelled out:

```markdown
## Submission

1. Pull first: `git pull`
2. Confirm a clean build: `g++ -std=c++17 -Wall -Wextra -o mXlabY mXlabY.cpp` (zero warnings)
3. Commit: `git add mXlabY.cpp` then `git commit -m "M X Lab Y: [what works]"`
4. Push: `git push`
5. Check on github.com that your file is there. If you can't see it, neither can your instructor.

Going for the Badge? Also commit `prompts.md` with every AI prompt you used and what you changed about the answers.
```

## Theme Discipline

The dungeon/RPG canon (Rooms, Hero, Monster, menus, the M8 payoff) is the default skin. Rules:
- **Skin is separable from structure.** The Specification and Requirements sections must read correctly with all flavor deleted. Test this by stripping theme words and re-reading.
- Reuse established canon nouns; don't fork the lore.
- An instructor should be able to re-skin the lab (bank account, pizza shop) by editing nouns and sample output only.

## Quality Checklist

Before completing a lab:

- [ ] Frontmatter complete (title, module, beat, time, prereqs, deliverables)
- [ ] Spec includes inputs/processing/outputs and at least one exact sample run
- [ ] All four tiers present; tiers nest; each tier observable by running the program
- [ ] Badge tier is documentation/reflection, not code
- [ ] Starter code (if any) compiles clean under `g++ -std=c++17 -Wall -Wextra` — verified with Bash where available, else marked "untested"
- [ ] Build command shown verbatim; zero-warning bar stated
- [ ] Single-file convention respected for the module's position (no prototypes before M6)
- [ ] No concepts from future modules required
- [ ] Troubleshooting organized by the four-term error taxonomy
- [ ] Any flowchart is Mermaid
- [ ] Submission steps are the pull → commit → push workflow, spelled out
- [ ] Theme strips cleanly; requirements survive unskinned
- [ ] Prose at 10th grade; no trick requirements
- [ ] Time estimate realistic for the C tier (B/A add time; say roughly how much)

## Common Lab Types

### Spec Lab (the default)
Requirements + spec → student implements from scratch. The Pizza Calculator (M3) and decision CYOA (M4) pattern.

### Refactor Lab
Take a working prior program and restructure it without changing behavior — the M6 signature move ("decompose your M5 menu program into functions"). Grade on identical behavior + improved structure.

### Fix-It Lab
Provide broken programs; students diagnose and repair, naming each bug's error class. (The *Debugging Time* asset pattern, M3 onward.)

### Tiered Build Lab
A program that grows across tiers — C: parallel arrays work; B: refactor to a struct array; A: add a second struct and interaction. The M7 pattern.
