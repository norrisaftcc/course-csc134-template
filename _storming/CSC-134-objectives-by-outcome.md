# CSC 134 — Objectives Mapped by Outcome (Reverse View)

*Companion to the CSC 134 Learning Objectives doc. Same objectives, inverted: each CLO is shown with every MLO that builds toward it, where it's reinforced through continued practice, and where it's mastered. This is the by-outcome view for program review and accreditation.*

**Levels:** **I** = Introduced · **D** = Developed · **M** = Mastered / assessed.
**"Reinforced through practice"** = modules where the outcome is exercised without a *new* named MLO (e.g., students keep writing and compiling programs after M3, so CLO2 is reinforced even though those modules' new objectives lie elsewhere). The distinction matters for review: it separates explicit instruction from continued use.

---

## CLO1 — Design a solution by decomposing it and representing it before coding

| Module | MLO | Level |
|---|---|---|
| M0 | 0.1 — Explain what a program is and how it sits within a system | I (foundational) |
| M1 | 1.3 — Write precise, decomposed, assumption-free instructions (Robot Sandwich) | I |
| M2 | 2.1 — Explain why languages exist; compiled vs. interpreted | D |
| M2 | 2.2 — Represent a solution with pseudocode, flowchart, user stories | D |
| M4 | 4.3 — Translate a flowchart's decisions into code, and recover a flowchart from code | D |
| M8 | 8.1 — Produce a full design document before implementation | **M** |

**Reinforced through practice:** M6 (decomposing into functions is design in action).
**Mastered at:** M8 (the design document, graded before code is written).

---

## CLO2 — Write, compile, and run C++ programs with I/O and arithmetic

| Module | MLO | Level |
|---|---|---|
| M0 | 0.2 — Set up the environment; compile and run a first program | I |
| M2 | 2.3 — Read a working C++ program and describe its behavior | I (comprehension) |
| M3 | 3.1 — Declare and use variables of appropriate types | D |
| M3 | 3.2 — Perform input, processing, and output with arithmetic | D |
| M8 | 8.2 — Implement a working program that meets a spec | **M** |

**Reinforced through practice:** M4, M5, M6, M7 (every module writes, compiles, and runs programs).
**Mastered at:** M8.

---

## CLO3 — Control program flow with selection and iteration to filter and process data

| Module | MLO | Level |
|---|---|---|
| M4 | 4.1 — Implement selection with `if`/`else if`/`else` and `switch` | I |
| M4 | 4.2 — Construct boolean expressions with comparison and logical operators | I |
| M4 | 4.3 — Translate flowchart decisions into code | I |
| M5 | 5.1 — Implement `while`, `do-while`, and `for` loops | D |
| M5 | 5.2 — Validate input and prevent loop failures | D |
| M5 | 5.4 — Combine loops and selection to filter a sequence of data | D |
| M8 | 8.2 — Implement a working program that meets a spec | **M** |

**Reinforced through practice:** M7 (traversing and processing collections relies on loops + selection).
**Mastered at:** M8.

---

## CLO4 — Apply functional decomposition with functions

| Module | MLO | Level |
|---|---|---|
| M6 | 6.1 — Define and call functions with prototypes, parameters, return values | I |
| M6 | 6.2 — Distinguish and apply pass-by-value vs. pass-by-reference | D |
| M6 | 6.3 — Refactor a program into functions without changing behavior | D |
| M8 | 8.2 — Implement a working program that meets a spec | **M** |

**Reinforced through practice:** M7 (structured-data work is organized into functions).
**Mastered at:** M8.

---

## CLO5 — Represent and manipulate aggregated data with arrays, structs, pointers

| Module | MLO | Level |
|---|---|---|
| M6 | 6.2 — Pass-by-reference (the pointer/reference on-ramp) | I (touch) |
| M7 | 7.1 — Declare, initialize, and traverse arrays | I |
| M7 | 7.2 — Model related data with structs; access members | D |
| M7 | 7.3 — Use pointers to pass and modify structured data by reference | D |
| M8 | 8.2 — Implement a working program that meets a spec | **M** |

**Mastered at:** M8.

---

## CLO6 — Apply object-oriented programming with classes

| Module | MLO | Level |
|---|---|---|
| M7 | 7.4 — Design and use a class that encapsulates data and behavior | I |
| M8 | 8.2 — Implement a working program (built on classes) | **M** |

**Mastered at:** M8.

> **Narrowest coverage — flagged for review.** CLO6 is introduced once (M7) and mastered at M8, with no intermediate development module. This is a consequence of OOP living late in an intro course. If the committee wants more runway, the options are: (a) split M7 so classes get their own sub-unit with its own assessed step, or (b) add a small class-based checkpoint between M7 and M8. Noted rather than silently accepted.

---

## CLO7 — Test and debug across the error taxonomy

| Module | MLO | Level |
|---|---|---|
| M2 | 2.3 — Read and describe a working program (comprehension precondition) | I |
| M2 | 2.4 — Classify errors as syntax, semantic, runtime, or logic | I |
| M3 | 3.3 — Locate and correct errors by reading compiler/runtime messages | D |
| M5 | 5.2 — Prevent common loop failures (infinite loops, `cin` fail state) | D |
| M5 | 5.3 — Predict output with a trace table before running | D |
| M8 | 8.3 — Test against a spec and debug across the taxonomy | **M** |

**Reinforced through practice:** M4, M6, M7 (debugging is continuous once programs are written).
**Mastered at:** M8.

---

## CLO8 — Communicate technical work, including responsible AI use

| Module | MLO | Level |
|---|---|---|
| M0 | 0.2 — Set up and use GitHub | I |
| M0 | 0.3 — Explain why programming literacy is needed to supervise AI | I |
| M1 | 1.1 — Create and format Markdown documents | I |
| M1 | 1.2 — Submit correctly via pull → commit → push | I |
| M8 | 8.4 — Present and defend working software; document AI assistance | **M** |

**Reinforced through practice:** every module (commit hygiene, meaningful messages, `prompts.md` logging).
**Mastered at:** M8.

---

## At-a-glance: contribution counts

| CLO | Named MLOs feeding it | Modules touched (incl. reinforcement) | Mastery |
|---|:--:|:--:|:--:|
| CLO1 Design | 6 | M0, M1, M2, M4, M6, M8 | M8 |
| CLO2 I/O & arithmetic | 5 | M0, M2, M3, M4–M7, M8 | M8 |
| CLO3 Selection & iteration | 7 | M4, M5, M7, M8 | M8 |
| CLO4 Functions | 4 | M6, M7, M8 | M8 |
| CLO5 Arrays/structs/pointers | 5 | M6, M7, M8 | M8 |
| CLO6 Classes | 2 | M7, M8 | M8 |
| CLO7 Test & debug | 6 | M2–M8 | M8 |
| CLO8 Communicate & AI | 5 | M0, M1, every module, M8 | M8 |

**Two things a reviewer should look at:**
1. **CLO6 (classes)** has the thinnest development runway — see the flag above.
2. The **M0 orientation edges** (MLO 0.1 → CLO1, MLO 0.2 → CLO2/CLO8) count environment-setup and conceptual framing as *Introduction*. Some designers reserve "I" for the first *instructional* treatment of a skill. If the committee prefers that stricter reading, those M0 marks shift to the next module and the mastery/development picture is unchanged.
