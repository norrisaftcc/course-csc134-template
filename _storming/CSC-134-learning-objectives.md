# CSC 134 — Learning Objectives (CLOs & MLOs)

*Companion to the CSC 134 Course Spine. Built for instructional-design use: course-level outcomes, measurable module-level objectives mapped to them, and a coverage matrix. Objectives are anchored to **modules**, so they remain stable as individual assignments are re-slotted during the overhaul.*

---

## How to read this

- **CLO** = Course Level Objective (what a student can do on completing the course). Derived from the CCL catalog description; CLO8 is a deliberate extension (noted below).
- **MLO** = Module Level Objective (what a student can do on completing that module). Each MLO is tagged with the CLO(s) it advances, e.g. `(→ CLO3)`.
- **Coverage matrix** uses the standard **I / D / M** scale: **I**ntroduced · **D**eveloped · **M**astered (assessed).
- **Measurability:** objectives use observable Bloom verbs (design, implement, classify, refactor…) so each is assessable by the module's *Assess* artifact. Lower-order verbs cluster early; higher-order (design, refactor, defend) arrive later — the same scaffolding-off-the-scaffolding curve as the LPAA Make gradient.
- **MLO numbering here is internal to this document.** `modules/mN/_mlos.md` decomposes the same objectives more finely and numbers them differently — M2 has four MLOs here and seven there; M0 has three here and four there. Per [[ADR-020-module-mlos-govern-cite-by-slug]], **the module files govern citations**, while this document's numbering serves the CLO mapping and coverage matrix below. Neither is wrong. But **`MLO 2.2` here is not `MLO-M2.2` there**, so a citation crossing between them must carry the objective's slug, not the number alone.

---

## Course Level Objectives

*Upon successful completion of CSC 134, students will be able to:*

| # | Course Level Objective | Bloom emphasis |
|---|---|---|
| **CLO1** | **Design** a solution to a programming problem by decomposing it into discrete steps and representing it with pseudocode and flowcharts before coding. | Create |
| **CLO2** | **Write, compile, and run** C++ programs that perform input/output and arithmetic operations. | Apply |
| **CLO3** | **Control program flow** using selection and iteration to filter and process data. | Apply |
| **CLO4** | **Apply functional decomposition** — using functions with parameters and return values — to organize a program. | Apply |
| **CLO5** | **Represent and manipulate aggregated data** using arrays, structs, and pointers. | Apply |
| **CLO6** | **Apply object-oriented programming** by designing and using classes that encapsulate data and behavior. | Apply / Create |
| **CLO7** | **Test and debug** C++ programs by identifying and correcting syntax, semantic, runtime, and logic errors. | Analyze / Evaluate |
| **CLO8** | **Communicate technical work** using Markdown documentation, version control, and clear presentation of working software — including the responsible, cited use of AI assistance. | Apply / Communicate |

### CCL traceability

Every CCL topic maps to at least one CLO; the catalog's outcome verbs ("design, code, test, debug") map across CLO1–7.

| CCL element | Satisfied by |
|---|---|
| Input/output operations | CLO2 |
| Arithmetic operations | CLO2 |
| Iteration | CLO3 |
| Filters | CLO3 |
| Arrays | CLO5 |
| Pointers | CLO5 |
| Object-oriented programming | CLO6 |
| Design / code / test / debug a C++ program | CLO1 (design) · CLO2–6 (code) · CLO7 (test, debug) |

> **CLO8 is an extension beyond the catalog minimum.** The CCL does not name documentation, version control, or AI use. CLO8 formalizes the spine's Communication and Practice threads because they are graded artifacts throughout the course and are core to how "design a C++ program" is practiced in a modern workflow. Flagged here so the ID can keep it, fold it into another CLO, or hold it as a program-level outcome, as preferred.

---

## Module Level Objectives

### M0 — Welcome to Programming
*By the end of M0, students will be able to:*
- **MLO 0.1** — Explain what a computer program is and how software operates within a system of people, processes, and technology. (→ CLO1)
- **MLO 0.2** — Set up and verify a C++ development environment (GitHub + Codespaces or local VSCode/MinGW) by compiling and running a first program. (→ CLO2, CLO8)
- **MLO 0.3** — Explain why programming literacy remains necessary for verifying and collaborating with AI tools. (→ CLO8)

*Measured by:* environment-verification proof + short "a program I used today" reflection.

---

### M1 — Talk to Computers (and Your Team)
- **MLO 1.1** — Create and format documents in Markdown using headings, lists, and code blocks. (→ CLO8)
- **MLO 1.2** — Submit work correctly through GitHub using the pull → commit → push workflow. (→ CLO8)
- **MLO 1.3** — Write precise, decomposed, assumption-free instructions for a literal agent. (→ CLO1)

*Measured by:* the Robot Sandwich assignment.

---

### M2 — How to Solve Problems
- **MLO 2.1** — Explain why multiple programming languages exist and distinguish compiled from interpreted execution. (→ CLO1)
- **MLO 2.2** — Represent a solution using pseudocode, a Mermaid flowchart, and user stories. (→ CLO1)
- **MLO 2.3** — Read a working C++ program and describe its behavior in plain language. (→ CLO2, CLO7)
- **MLO 2.4** — Classify program errors as syntax, semantic, runtime, or logic. (→ CLO7)

*Measured by:* the "describe-a-program + flowchart" lab; error-classification exit ticket.

---

### M3 — Program Basics
- **MLO 3.1** — Declare and use variables of appropriate data types. (→ CLO2)
- **MLO 3.2** — Write programs that perform input, processing, and output using arithmetic expressions. (→ CLO2)
- **MLO 3.3** — Locate and correct errors by reading compiler and runtime messages. (→ CLO7)

*Measured by:* the I/O + arithmetic lab (e.g., Pizza Calculator).

---

### M4 — Decisions
- **MLO 4.1** — Implement selection using `if` / `else if` / `else` and `switch`. (→ CLO3)
- **MLO 4.2** — Construct boolean expressions using comparison and logical operators. (→ CLO3)
- **MLO 4.3** — Translate a flowchart's decision points into working code, and recover a flowchart from existing code. (→ CLO1, CLO3)

*Measured by:* the decision-structures (CYOA) lab.

---

### M5 — Loops
- **MLO 5.1** — Implement iteration using `while`, `do-while`, and `for` loops. (→ CLO3)
- **MLO 5.2** — Validate user input and prevent common loop failures (infinite loops, `cin` fail state). (→ CLO3, CLO7)
- **MLO 5.3** — Predict loop output using a trace table before running the program. (→ CLO7)
- **MLO 5.4** — Combine loops and selection to filter and process a sequence of data. (→ CLO3)

*Measured by:* `M5LAB` loop fundamentals + Project 2 (menu-driven game).

---

### M6 — Functions
- **MLO 6.1** — Define and call functions using prototypes, parameters, and return values in the single-file convention. (→ CLO4)
- **MLO 6.2** — Distinguish pass-by-value from pass-by-reference and apply each appropriately. (→ CLO4, CLO5)
- **MLO 6.3** — Refactor an existing program into functions without changing its behavior. (→ CLO4)

*Measured by:* the refactor-into-functions lab.

---

### M7 — Structured Data & Objects
- **MLO 7.1** — Declare, initialize, and traverse arrays. (→ CLO5)
- **MLO 7.2** — Model related data using structs and access their members. (→ CLO5)
- **MLO 7.3** — Use pointers to pass and modify structured data by reference. (→ CLO5)
- **MLO 7.4** — Design and use a class that encapsulates data and behavior. (→ CLO6)

*Measured by:* the tiered `M7LAB1` (Room struct → Hero → Monster → class refactor).

---

### M8 — Capstone Miniproject
- **MLO 8.1** — Produce a design document (problem statement, user stories, spec, flowchart) before implementation. (→ CLO1)
- **MLO 8.2** — Implement, in stages, a working C++ program that meets a self-authored specification. (→ CLO2, CLO3, CLO4, CLO5, CLO6)
- **MLO 8.3** — Test a program against its specification and debug failures across the error taxonomy. (→ CLO7)
- **MLO 8.4** — Present and defend working software, documenting any AI assistance used. (→ CLO8)

*Measured by:* the capstone (design doc + staged implementation + presentation).

---

## Coverage matrix (CLO × Module)

**I** = Introduced · **D** = Developed · **M** = Mastered / assessed

| | M0 | M1 | M2 | M3 | M4 | M5 | M6 | M7 | M8 |
|---|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
| **CLO1** Design & represent | | I | D | | D | | D | | **M** |
| **CLO2** I/O & arithmetic | I | | I | D | D | D | D | D | **M** |
| **CLO3** Selection & iteration | | | | | I | D | | D | **M** |
| **CLO4** Functions | | | | | | | I | D | **M** |
| **CLO5** Arrays/structs/pointers | | | | | | | | I·D | **M** |
| **CLO6** Objects / classes | | | | | | | | I | **M** |
| **CLO7** Test & debug | | | I | D | D | D | D | D | **M** |
| **CLO8** Communicate & AI use | I | I | D | D | D | D | D | D | **M** |

Reading the matrix: every CLO is introduced, developed across multiple modules, and mastered at the M8 capstone — which is by design, since the capstone is "the whole spine, run once, by the student." CLO7 (test/debug) and CLO8 (communicate) show the widest spread because both are threads, not units — they run through nearly every module.

---

## Note on constructive alignment

Each MLO is written to be measured by that module's *Assess* artifact (listed under each module above), which is in turn graded by the shared tiered rubric (Correctness / Completeness / Format / Submission). This keeps the chain intact: **CLO → MLO → Assess artifact → rubric criterion.** If the ID re-slots an assignment during the overhaul, the MLO it satisfies moves with it, and this chain is what to re-verify.
