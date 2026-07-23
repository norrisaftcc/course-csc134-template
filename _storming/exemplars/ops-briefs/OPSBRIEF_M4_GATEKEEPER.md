```text
UNCLASSIFIED // COURSE USE ONLY // READABILITY: 10TH GRADE
```

# OPERATION GATEKEEPER
### Module 4: Decisions · Weeks 5–6

> **BLUF:** By the end of this module you can make a program choose — `if`, `else if`, `else`,
> and `switch`, driven by comparisons and logic you write. You will deliver a decision lab
> (the Dungeon Gatekeeper) built from a flowchart, and you must complete the exit ticket
> before the Apply tutorial unlocks.

## SITUATION
On the arc, you can already build a program that runs straight through: input, math, output
(your taco receipt did exactly that). But every flowchart you drew in Module 2 had diamonds
in it — points where the path splits. Until now the diamonds were drawings. This module makes
them executable. This is also where "filters" begins: programs that treat different input
differently.

## MISSION
By end of module, you can:
- Write selection with `if` / `else if` / `else` and `switch` (MLO 4.1)
- Build boolean expressions with comparison and logical operators (MLO 4.2)
- Turn a flowchart's decisions into code — and recover the flowchart from someone else's code (MLO 4.3)

## EXECUTION (the four beats)
| Phase | What | Deliverable | Gate |
|---|---|---|---|
| **Learn** | Chapter 4 reading + predict-the-branch exercises | — | — |
| **Practice** | M4 exit ticket: trace which branch runs for given inputs | completed ticket | **completion-gated: no ticket, no Apply** |
| **Apply** | Type in the build-your-own-adventure decision program (FULL mode — you type 100%) | working CYOA program | compiles clean |
| **Assess** | M4 Decision Lab: the Dungeon Gatekeeper, built from its flowchart | `m4lab1.cpp` (+ Badge files) | tier attempted: C / B / A / Badge |

## KNOWN THREATS (intel from students before you)
- **Logic errors arrive this module.** Your program will compile, run, and calmly do the
  wrong thing. The compiler cannot see a wrong branch — only a trace can.
- **`=` where you meant `==`.** Assignment inside a condition is legal C++ and almost never
  what you meant. `-Wall` flags it; zero warnings is the bar for a reason.
- **The dangling else.** Without braces, an `else` binds to the *nearest* `if`, not the one
  your indentation suggests. Braces are cheap. Use them.
- **`switch` fall-through.** A missing `break` runs the next case too. Sometimes a tool,
  usually a surprise.

## LOGISTICS
- Toolchain: Codespaces or local VSCode + g++ · build: `g++ -std=c++17 -Wall -Wextra -o m4lab1 m4lab1.cpp` · zero warnings
- Files live in: `m4/` in your course repo · submit: pull → commit → push

## COMMS
- Stuck 20 minutes? Post in the course channel — quote the exact error text or the exact
  wrong output, don't describe it from memory.
- AI assistance this module: permitted and logged (`prompts.md`). Prompt pattern of the
  module: **Explain-Then-Generate** — make it explain branching back to you before you accept
  its code. You can't supervise a branch you can't trace.

```text
END OF BRIEF // GOOD HUNTING
```
