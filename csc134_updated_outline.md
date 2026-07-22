# CSC 134 — Updated Course Outline & Timeline (Review Draft)

**Purpose:** Reconcile the original 16-week outline with the as-built modules, integrate the thinkcpp reading/checkpoint layer, and flag gaps found on the polish pass. Weeks are relative (Week X), not dated.

**Status:** DRAFT FOR REVIEW — decisions needing sign-off are marked ⚠️.

---

## What Changed From the Original Outline

The original outline (`CSC_134__C___Programming_-_16_Week_Course_Outline.md`) no longer matches what was actually built. Three structural corrections:

1. **Sequence:** Original ran Decisions (3–4) → Loops (5–6) → Functions (7–8). As-built modules run **Functions (3–4) → Decisions (5–6) → Loops (7–8)**, confirmed in the module docs. This draft codifies the as-built order — which also matches thinkcpp's chapter order (Functions = Ch 3).
2. **Classes descoped:** Original had "Classes (Intro/Advanced)" in weeks 11–12. Current scope discipline puts classes at A-tier/badge only, inside the final project. Weeks 11–12 now carry the as-built M6 content (arrays, text adventure). ⚠️ *Confirm this is the intended resolution — see Gap 2.*
3. **Recursion removed** from Week 8 core (out of scope; optional reading only, thinkcpp §4.7–4.9).

---

## Canonical Week-by-Week Timeline

### Phase 1: Foundations — "Earn Your C" (Weeks 1–8)

| Wk | Module | Topics | thinkcpp Reading (checkpoints) | Milestone |
|----|--------|--------|-------------------------------|-----------|
| 1 | M0: Hello World | Toolchain (Codespaces/VS Code), GitHub, compile cycle, computational thinking. **Runestone onboarding** (register, complete §1.1) | Ch 1 — way of the program, debugging taxonomy | Setup complete; first commit; first checkpoint |
| 2 | M1: Variables & I/O | Types, `const`, arithmetic, `cin`/`cout`. One-slide "what is `main()`?" gloss | Ch 2 — variables and types | **Project 1: Pizza Calculator** |
| 3 | M2: Functions I | Prototypes/definitions/calls, IPO decomposition, hierarchy charts ("Pro Chef") | Ch 3 — functions | Lab: decomposed calculator |
| 4 | M2: Functions II | Return values, composition, scope. Course code-structure convention (prototypes top / main middle / definitions bottom) | Ch 5 §5.1–5.4, 5.9 | Functions lab set complete |
| 5 | M3: Decisions I | `if/else`, relational ops, CYOA structure begins | Ch 4 §4.1–4.6 (skip recursion §4.7–4.9) | CYOA in progress |
| 6 | M3: Decisions II | `switch`, ternary, booleans, logical ops, **input validation beat #1** (`cin` failure states) | Ch 5 §5.5–5.8 | **Project 2: CYOA Game** (badge major #1) |
| 7 | M4: Loops I | `while`, `for`, loop patterns (regen / level-up / inventory), arrays-with-loops preview | Ch 6 — iteration | Loop fundamentals lab |
| 8 | M4: Loops II + Checkpoint | Nested loops, accumulator patterns, **Debugging Gauntlet** (fix-broken-programs review, Ch 2–5 material), **input validation beat #2** (validation loops) | §7.9 — looping and counting | **"C achieved" milestone**; light week / drift absorber ⚠️ |

### Phase 2: AI-Assisted Engineering — "Build Your B" (Weeks 9–12)

| Wk | Module | Topics | thinkcpp Reading | Milestone |
|----|--------|--------|------------------|-----------|
| 9 | M5: File I/O I | `ifstream`/`ofstream`, streams, file formats. **AI-assist patterns begin** (Scaffold, Explain-Then-Generate; `prompts.md` citation habit) | Ch 15 §15.1–15.3 | Read/write lab |
| 10 | M5: File I/O II | Parsing, save/load state, `getline` vs `>>` gotchas | Ch 15 §15.4–15.6 (skip §15.7+) | Save-system lab |
| 11 | M6: Arrays & Data I | Raw arrays, parallel arrays (**deliberate scaffolding — pain before structs**), enums | Ch 7 selections (strings) — *note: thinkcpp is thin on raw arrays; course materials carry this* | Parallel-array lab |
| 12 | M6: Arrays & Data II | Adjacency lists, text-adventure architecture, **pointers-lite beat** (arrays & functions, reference vs. pointer) ⚠️ | — (course materials) | **Project 3: Text Adventure** (badge major #2) — **"B achieved"** |

### Phase 3: Advanced Concepts — "Achieve Your A" (Weeks 13–15)

| Wk | Module | Topics | thinkcpp Reading | Milestone |
|----|--------|--------|------------------|-----------|
| 13 | M6.5: Vectors | Refactor arrays → vectors, `size()`, range-for, push_back; why vectors beat raw arrays | Ch 10 §10.1–10.6 | Refactored adventure |
| 14 | M7: Structs | `Room` struct collapses parallel arrays; `Hero` struct → pass-by-value vs. pass-by-reference; `Monster` + combat (A-tier) | Ch 8 — structures (Ch 9 = badge enrichment) | M7LAB1 per planning doc |
| 15 | Final Sprint | Design doc → build → iterate. AI patterns: Refactor, Debug, Review. Three tracks (C++ / C++→HTML / HTML) | Ch 11–14 listed as optional "going further" (classes) | Working draft due; peer preview |

### Phase 4: Demonstration — "Badge Defense" (Week 16)

- Project presentations; code review & defense
- Portfolio completion (labs, four projects, AI logs, reflections)
- **Capstone due** (badge candidates): requirements analysis, design doc, test plan, reflection

---

## Assessment Map (reconciled)

| Deliverable | Week | Role |
|---|---|---|
| Project 1: Pizza Calculator | 2 | Onboarding project (existing rubric) |
| Project 2: CYOA Game | 6 | **Badge major project #1** — control structures, functions |
| Project 3: Text Adventure | 12 | **Badge major project #2** — arrays, file I/O, AI-assisted dev |
| Final Project (3 tracks) | 15–16 | Capstone; classes/OO at A-tier & badge track |
| Runestone checkpoints | weekly | Completion-graded; folded into participation ⚠️ *(or standalone category — decide)* |
| Weekly labs | ongoing | C/B/A tiered rubrics, portfolio evidence |

---

## Polish-Pass Findings (Gaps & Flags)

**Gap 1 — Numbering drift (⚠️ decision needed).** Three schemes are live: module docs (M02 = Functions, wks 3–4), lab filenames (M5LAB_A = *Loops*, "Week 7"), and the old outline (Functions wks 7–8). This draft uses the module-doc scheme as canonical (M0–M7 + M6.5 vectors). Recommend a rename pass on lab files next revision (e.g., M5LAB_A → M4LAB_A) *or* renumbering modules to match labs — either works, but pick one before the thinkcpp assignment names bake in a third scheme.

**Gap 2 — "Object-oriented" in the official course description.** The syllabus entry promises OOP; classes were descoped from weeks 11–12. Coverage now = structs (wk 14) → optional classes reading → A-tier/badge classes in the final project. Defensible as "OOP foundations + guided exposure," but ⚠️ confirm this satisfies departmental expectations for the course description.

**Gap 3 — Pointers.** The official description lists pointers; no current module teaches them. Added a **pointers-lite beat** in week 12 (arrays decay into pointers when passed to functions; `&` reference vs. `*` pointer at recognition level, not mastery). ⚠️ Approve scope, or expand.

**Gap 4 — Input validation had no home.** The final-project rubric requires it at every tier, but no module explicitly taught it. Added two beats: wk 6 (`cin` failure states with decisions) and wk 8 (validation loops). Cheap fix, closes a rubric/instruction gap.

**Gap 5 — No buffer week existed.** Real semesters have holidays, snow days, and modules that run long. Week 8 is now deliberately light (checkpoint + debugging gauntlet) so it can absorb drift without cascading. If the semester runs clean, the gauntlet expands.

**Gap 6 — thinkcpp raw-array hole.** The book jumps essentially to vectors; M6's parallel-arrays scaffolding is fully carried by course materials. No book checkpoints in wks 11–12 except strings selections — expect the completion dashboard to go quiet those weeks; that's by design, not student drop-off.

**Gap 7 — AI-log start line.** Original outline says AI logs "Weeks 9+", but M6LAB2 already allows unlimited cited AI help earlier. Recommend: citation habit (`prompts.md`) introduced wk 9 formally, but *permitted-with-citation from wk 5* so CYOA projects aren't in a gray zone. ⚠️ Confirm.

**Gap 8 — Week 8 "C achieved" vs. gradebook reality.** The milestone is motivational, but nothing currently *computes* it. Suggest a simple visible artifact: a wk-8 progress report (labs + projects 1–2 + checkpoint completion) so "you've earned your C" is a statement about the gradebook, not vibes.

---

## Review Checklist (sign-offs needed)

1. ⚠️ Canonical numbering: module-doc scheme (this draft) vs. lab-file scheme
2. ⚠️ Gap 2 resolution acceptable for the official description (OOP via structs + final project)
3. ⚠️ Pointers-lite scope (wk 12) sufficient
4. ⚠️ AI-with-citation start week (5 vs. 9)
5. ⚠️ Runestone checkpoints: participation fold-in vs. standalone grade category
6. Week 8 buffer design OK
7. Reading load check: heaviest weeks are 5–6 (Ch 4 + Ch 5 split) — acceptable, or thin further?
