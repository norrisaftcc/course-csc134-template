# Option 1 Adoption Plan — thinkcpp as CSC 134 Companion Text (Spike)

**Scope:** Adopt *How to Think Like a Computer Scientist – C++ Edition* (thinkcpp) on Runestone Academy as a pre-class reading + checkpoint layer. No authoring, no LTI, no changes to existing presentations or labs. Completion-graded only.

**Decision this plan serves:** Does the checkpoint-reading mechanism change student behavior enough to justify Path 2 (fork) or Path 3 (build our own)?

---

## 1. Good News from the TOC Pull

The sequencing fear was mostly unfounded. thinkcpp's order aligns with the current module map better than expected:

- **Functions are Chapter 3** — matching M02 exactly. No "functions pushed later" problem at all; the fallback "what is main()?" explainer is barely needed (Ch 1.6 shows `main` in the first program; a one-slide gloss in M00/M01 covers it).
- **Chapter 8 (Structures) covers call-by-value vs. call-by-reference** — precisely the B-tier beat planned for M7LAB1. The book can carry the concept load there.

The real gaps are narrower than "wrong sequencing":

1. **For loops arrive late and thin** (§10.4, inside the Vectors chapter). M04 leans on `for`; the book leans on `while`. Supplement with existing M04 materials — the book covers `while` and loop logic well (Ch 6), your deck covers `for`.
2. **File I/O is Chapter 15**, assigned out of order for M05. Runestone handles out-of-order assignment fine; skip §15.7–15.10 (Set/matrix — out of scope).
3. **Recursion is embedded in Ch 4** (§4.7–4.9). Out of CSC 134 scope — mark those sections "optional / badge-curious."
4. **Style is dated in places** (pre-modern C++ idioms). Acceptable for a spike; note divergences from the course style guide when they matter (e.g., the book's formatting vs. compile-clean `-Wall -Wextra` conventions).

---

## 2. Chapter → Module Map

| Module | Weeks | Assign from thinkcpp | Skip / mark optional |
|---|---|---|---|
| M00 Hello World / GitHub | 1 | Ch 1 (way of the program, debugging taxonomy) | — |
| M01 Variables & I/O | 2 | Ch 2 (variables and types) | — |
| M02 Functions | 3–4 | Ch 3 (functions); Ch 5 §5.1–5.4, 5.9 (return values, composition) | — |
| M03 Decisions | 5–6 | Ch 4 §4.1–4.6 (conditionals); Ch 5 §5.5–5.8 (booleans, logical ops) | §4.7–4.9 recursion → optional |
| M04 Loops | 7–8 | Ch 6 (iteration, while); §7.9 (looping and counting) | Book's `for` coverage thin — course deck carries `for` |
| M05 File I/O | ~9–10 | Ch 15 §15.1–15.6 (streams, file in/out, parsing) | §15.7–15.14 (Set, matrix) |
| M06 Arrays / Vectors / Text Adventure | ~11–13 | Ch 10 §10.1–10.6 (vectors, for loops, size); Ch 7 selections (strings) as needed | §10.7–10.14 (stats/histogram) → optional practice |
| M07 Structs | ~14 | Ch 8 (structures, call by value/reference) — direct M7LAB1 support | Ch 9 → badge-track enrichment |
| Final Project | 15–16 | None required; Ch 11–14 (classes) listed as "going further" for Track A ambition | — |

Rough reading load: 1 chapter or less per module, chunked across the module's weeks. Target ≤ 20 min reading + ~5 min checkpoints per class session.

---

## 3. Spike Checklist (instructor-only, one afternoon)

1. Create Runestone instructor account; create sandbox course from thinkcpp
2. Enroll a second account as a fake student; complete one section's exercises
3. Verify instructor dashboard: per-section completion view, most-missed questions, assignment builder
4. Test Scratch ActiveCode with C++: confirm `-std=c++17 -Wall -Wextra` compileargs work (documented examples show c++11; expect fine, verify)
5. Build one real assignment in the assignment builder: Ch 4 §4.1–4.6 reading + its MCQs + one Parsons problem, points = completion
6. Time yourself: how long does building one module's assignments take? (Multiply by 8 for total setup estimate)
7. Check the ad experience logged out vs. enrolled (enrolled students see no ads)

**Exit criteria:** all 7 done, no blockers → schedule the student-facing pilot.

---

## 4. Assignment Structure (per module, completion-graded)

Using Runestone's assignment builder — no LTI, dashboard is source of truth:

- **Pre-class Check Me** (per class session): assigned reading sections + their built-in MCQ / mixed-up-code exercises. Due before class. Runestone auto-tracks; grade = attempted/complete
- **Try It** (1 per module where it fits): one ActiveCode exercise from the chapter's Activecode Exercises section. Completion, not correctness
- **Exit Ticket** (1 per module): thinkcpp has no short-answer prompts of ours — two options: (a) use a Runestone short-answer question in a custom assignment, or (b) keep exit tickets in Canvas as-is and let the book handle only reading + practice. **Recommend (b) for the spike** — one less thing to migrate

**Weekly instructor loop (~15 min):**
1. Morning of class: dashboard scan → who read, which question missed most → open class with that question
2. Friday: export/eyeball completion, enter one weekly completion grade in Canvas manually (or fold into participation)

---

## 5. Canvas & Student Onboarding

- **Canvas side:** each module overview page gets one block: "📖 Field Manual: read §X.X–X.X and complete the checkpoints before Tuesday" + one-way link to the book section. No embedding, no passback
- **Framing (coherence-tax mitigation):** don't present the book as "the textbook" competing with course materials. In-world framing: it's the **Field Manual / training grounds** — generic-issue equipment, where the course itself is the campaign. Costs one paragraph in the syllabus; buys tonal consistency
- **Module 00 addition:** 10-minute onboarding — register on Runestone with the course code, complete Ch 1 §1.1 as the "did it work" check. This doubles as the first completion data point
- **Syllabus line:** book is free, no purchase, account required; data note if the college asks (Runestone is a 501(c)(3); the $100 contract fee only applies if the college requires a signed data agreement — confirm with admin only if they raise it)

---

## 6. Pilot Design & Decision Gates

**Pilot scope suggestion:** M00–M03 (weeks 1–6, Fall 2026). Long enough to see behavior change, short enough to abandon cheaply.

**Collect:**
- Checkpoint completion rate per section (dashboard)
- Before/after gut-check: are students arriving having seen the material? Fewer "what's a variable" moments in M03 than historical?
- Lab-grading signal: fewer first-contact compile errors in M02/M03 labs?
- One informal student pulse question at week 6: "Is the Field Manual helping? Keep/change/drop"

**Week 6 decision gate:**
- **Completion consistently < ~40%** or no observable class-prep change → mechanism isn't landing as deployed; diagnose (load? friction? incentive?) before investing further. Drop or adjust, don't author
- **Completion healthy + JIT teaching working** → continue through M07; start Path 2/3 evaluation
- **Signal strong AND the voice mismatch is the main student complaint** → that's the specific evidence that justifies Path 3 (your corpus, PreTeXt conversion) over Path 2

**Path 2 vs. 3 tiebreaker to note during the semester:** every time you think "I wish this section said X instead," log it. If the log is mostly *rewrites*, fork (Path 2). If it's mostly *restructuring*, build (Path 3).

---

## 7. Known Risks & Mitigations

| Risk | Mitigation |
|---|---|
| Dated C++ idioms conflict with course style guide | One "book vs. our style" note in M01; treat divergences as teachable (style guides exist for a reason) |
| `for`-loop gap in M04 | Course deck already carries it; book assigned for `while`/logic only |
| Student account fatigue (one more login) | Module 00 onboarding + completion counts from day one so the account immediately "pays" |
| Two-voice coherence tax | Field Manual framing; book never referenced during lecture except JIT question of the day |
| Runestone platform changes (fall 2026 modernization roadmap) | Spike is low-investment by design; nothing to lose but setup time |

---

## 8. Timeline (exploratory → pilot)

- **July:** spike afternoon (Section 3). Go/no-go on pilot
- **Early August:** build M00–M03 assignments (est. 1–2 hrs/module based on spike timing); add Module 00 onboarding step; syllabus line
- **Fall 2026 weeks 1–6:** pilot runs; log rewrite-vs-restructure notes
- **Week 6:** decision gate → continue / adjust / drop, and open the Path 2/3 question with real data
