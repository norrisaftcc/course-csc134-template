---
name: apply-tutorial-generator
description: "Create Apply-beat instructor-led type-in tutorials for CSC-134: FULL mode (M2-M4, type 100% in compiling stages) or EIGHTY mode (M5-M7, finish the missing piece of a working program)"
allowed-tools: "Read,Write,Bash,Glob,Grep"
---

# Apply Tutorial Generator

Create the instructor-led tutorial for CSC-134's **Apply** beat — the classroom session where students type a program in, get it to compile, and get it running. Apply carries PRIMM's Investigate → Modify → (early) Make stages, and it is where the **Make gradient** lives: how much of the program students receive versus produce depends on the module.

## When to Use This Skill

- Creating a module's in-class type-in tutorial
- Converting a demo or lecture example into a staged tutorial
- Writing the "finish the missing piece" sessions for M5–M7
- When asked to "make an Apply tutorial / type-in for X"

## Choose the Mode First (the Make gradient)

| Module | Mode | Student does |
|---|---|---|
| **M2–M4** | **FULL** | Types 100% of the program, in stages; each stage compiles and runs standalone |
| **M5–M7** | **EIGHTY** | Receives a working ~80% program with one specified missing piece; finishes it |
| **M8** | *(neither — no tutorial; Apply is "here's a spec, go" and belongs to the capstone brief)* | |

This is deliberate de-scaffolding: students are walked *off* the training wheels one module at a time. Never write EIGHTY-mode for M3, and never fall back to FULL-mode hand-holding in M7.

## Shared Requirements (both modes)

- **Every stage compiles and runs.** Course standard: staged builds so complexity accumulates visibly. The build command is always shown verbatim:

  ```bash
  g++ -std=c++17 -Wall -Wextra -o program program.cpp
  ./program
  ```

  Zero warnings at every stage — the tutorial models the quality bar the rubric will grade.
- **Predict before run.** Before each first run of a stage, the instructor asks the room for the expected output; the tutorial script includes the prompt and the actual output block.
- **One deliberate break per tutorial.** At a marked point, students break the program on purpose (remove a semicolon, misspell a variable, flip a condition) and read the compiler's or program's complaint together. Name the error's class from the four-term taxonomy: **syntax / static semantic / runtime / logic**.
- **Single-file convention:** prototypes top, `main` middle, definitions bottom — shown and named **from M6 onward**. M2–M5 tutorials are `main`-only; do not introduce prototypes early.
- **Timing:** 40–60 minutes of class time. Each stage gets a time estimate; instructors need to know where the halfway mark is.
- **Voice:** instructor-facing script + student-facing listing. Dungeon canon skin welcome (Level Up Stats, Rooms, menus) and must strip cleanly. 10th-grade prose on anything students read.

## Required Structure

```markdown
---
title: "MX Apply: [Program Name]"
module: M0X
lpaa_beat: Apply
mode: FULL | EIGHTY
estimated_time: "XX minutes (class session)"
prerequisites:
  reading: "[Learn-beat reading]"
  exit_ticket: "Module X exit ticket (completion gate)"
program_file: "mX_apply.cpp"
---

# MX Apply: [Program Name]

## What We're Building
[2-3 sentences + the finished program's sample run, so everyone sees the target]

## Instructor Notes
[Mode, timing per stage, where students typically stall, the deliberate-break point]

## Stage 1: [Name] (~X min)
[Listing or diff, predict prompt, build+run, expected output]

## Stage 2: ...

## The Deliberate Break (~5 min)
[What to break, the exact compiler/runtime message, its taxonomy class, the fix]

## Wrap-Up
[What the Assess lab will ask them to do with this pattern]
```

## FULL Mode (M2–M4): Type 100%, in Stages

Students build the whole program by typing — no copy-paste. Structure the program as 3–5 cumulative stages where **each stage is a complete, compiling, running program**, not a fragment:

- **Stage 1** is the smallest runnable core (often: includes + `main` + one `cout`). It runs within the first 10 minutes — early win, toolchain verified.
- **Each later stage adds one concept.** Show the *full listing* for the stage with the new lines marked:

  ```cpp
  #include <iostream>
  using namespace std;

  int main()
  {
      cout << "== Dungeon Shop ==" << endl;
      int gold = 50;                          // NEW
      cout << "You have " << gold << " gold." << endl;   // NEW
      return 0;
  }
  ```

- After typing each stage: **predict → build → run → compare.** Include the exact expected terminal output in a fenced block.
- Typos are curriculum. FULL mode's real product is students reading their own compiler errors; the instructor notes should list the 2–3 most likely typos per stage and the error text each produces.

## EIGHTY Mode (M5–M7): Finish the Missing Piece

Students receive a working program with **one specified gap** and complete it. Canonical gaps, by module:

- **M5:** the menu system works; the **input-validation loop** is missing
- **M6:** `main` and prototypes are complete; **the function definitions** (1–3 of them) are missing
- **M7:** the struct/class and driver work; **the methods** are missing

Hard requirements on the provided 80%:

1. **It compiles clean as distributed.** Stubs are real code, clearly marked, that keep the build green:

   ```cpp
   // ============================================
   // YOUR CODE: getMenuChoice
   // Spec: keep asking until the user enters 1-4.
   // Must survive non-numeric input (cin fail state:
   // clear, then ignore the bad line - see Chapter 5).
   // Returns: the validated choice.
   // ============================================
   int getMenuChoice()
   {
       int choice;
       cin >> choice;
       return choice;   // STUB: no validation yet - replace this body
   }
   ```

2. **The missing piece is spec'd, not implied.** Either a full prototype with a comment block stating inputs, behavior, and return (M6–M7), or a marked region with comment spec (M5, pre-functions). A student must be able to answer "what exactly do I write, and how will I know it works?" from the file alone.
3. **The gap matches the module's new concept.** The missing piece *is* the lesson; everything else is review. Don't hide two gaps or leave a gap that needs next module's material.
4. **Acceptance check included.** Give the exact test the finished piece must pass ("type `banana` at the menu: the program re-prompts instead of scrolling forever"), plus the expected terminal session.
5. Distribute the 80% file via the course repo (pull → open in Codespaces or local VSCode); the tutorial states this step explicitly.

Run EIGHTY sessions in three movements: **Investigate** (read the provided code together, trace one path), **spec review** (read the stub's comment spec aloud, restate it), **Make** (students implement; instructor circulates; reconvene to run the acceptance check).

## The Deliberate Break

Both modes include one scripted failure:

- FULL mode: break something *just typed* (delete the semicolon added in Stage 3).
- EIGHTY mode: break something in the *provided* code (flip the validation condition), so students practice reading unfamiliar code's failures.
- Script the exact error message students will see, name its taxonomy class, and script the recovery. This is the "failure is exercise" rep for the week.

## Verification Before Delivery

The tutorial author (you) must verify, using Bash where a toolchain is available:

- FULL mode: every stage's full listing compiles clean and prints the claimed output.
- EIGHTY mode: the distributed 80% file compiles clean **as-is**, and a reference solution (kept in an instructor-only section or separate `_solutions/` file) compiles clean and passes the acceptance check.
- The deliberate break produces the error message the script claims (compiler messages vary by version — quote your actual g++ output).

If no toolchain is available, mark the tutorial "untested" at the top for human verification.

## Quality Checklist

Before completing an Apply tutorial:

- [ ] Mode matches the module's Make-gradient position (FULL M2–M4, EIGHTY M5–M7)
- [ ] Finished program's sample run shown up front
- [ ] Every stage / the provided 80% compiles clean under `g++ -std=c++17 -Wall -Wextra` (Bash-verified or marked "untested")
- [ ] FULL: 3–5 cumulative stages, each a complete runnable program, new lines marked, Stage 1 runs in the first 10 minutes
- [ ] EIGHTY: exactly one gap; spec'd by prototype and/or comment block; stubs keep the build green; acceptance check with expected terminal session; reference solution exists and passes
- [ ] Predict-before-run prompt at each first run, with actual output block following
- [ ] One deliberate break, scripted, with the real error text and its taxonomy class
- [ ] Build/run commands shown verbatim at every stage
- [ ] No prototypes before M6; no pointers before M7; single-file convention named from M6 on
- [ ] Per-stage time estimates; total fits 40–60 minutes
- [ ] Instructor notes cover likely stalls/typos per stage
- [ ] Wrap-up points at the module's Assess lab
- [ ] Theme strips cleanly; student-facing prose at 10th grade

## Anti-Patterns to Avoid

**Fragment stages**: a stage that only shows the new lines and doesn't compile alone defeats the staged-build standard.
**The silent 80%**: providing most of a program with an unmarked hole ("finish it!") is a puzzle, not a spec. The gap gets a written contract.
**Broken handouts**: distributing 80% code that doesn't compile teaches students the quality bar is negotiable. It isn't.
**Two lessons per gap**: if finishing the piece needs both the new concept and an untaught one, shrink the gap.
**Copy-paste FULL mode**: if the listing arrives as a file students open, it's not a type-in. FULL mode listings appear in the tutorial document only.
**Mode drift**: an M6 tutorial where students type everything is a wasted de-scaffolding step; an M3 tutorial with stubs asks for composition before comprehension.
