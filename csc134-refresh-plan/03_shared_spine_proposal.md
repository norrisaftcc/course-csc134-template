# The Shared Spine: CSC 134 × CTI 110

*Proposal draft v0.3 — five fan-out decisions now resolved (see decision log). Grounds the abstract skeleton (v0.1) against the real CTI 110 spine and its sample M0/M1 artifacts.*

---

## The proposal in one paragraph

CTI 110's spine is already the thing we were trying to design. Its own working thesis — *"not intro to Python; intro to solving problems with systems, using Python as the instrument"* — is a language-independent claim. Swap the instrument and the sentence still holds. So the realignment is not "build a shared spine from scratch." It is: **treat CTI 110's problem-solving spine as the canonical skeleton, and build CSC 134 as its C++ instantiation.** The two courses share bones almost completely through the orientation, communication, and core-procedural phases, then fan out on purpose in the final third — CTI toward systems, data, and IT breadth; CSC toward objects, pointers, and the metal. That divergence is a feature, not a failure of the model.

The single strongest piece of evidence is already sitting in the uploads: the **Robot Sandwich assignment is portable to CSC 134 essentially unchanged.** It contains no Python, because it comes before code. Build once, use twice, skin never.

---

## Reconciling our vocabulary with CTI 110's

We coined three content spines (Concept, Communication, Practice). CTI 110 already ships a process spine (Understand → Decompose → Represent → Implement → Verify → Communicate) drawn for students as the SDLC arc. These are not competing taxonomies — one is *nouns*, one is *verbs*, and they interlock:

| Our content thread | Maps onto CTI's process stages | Carries |
|---|---|---|
| **Communication** | Represent + Communicate | Markdown, user stories, specs, the prompt ladder, robot sandwich |
| **Concept** | Decompose + Implement | State, selection, iteration, decomposition, data aggregation |
| **Practice** | Verify + the toolchain/submission thread | VSCode/GitHub, version control, "submitted correctly or it doesn't exist," trace-tables |

Recommendation: **adopt CTI's SDLC arc as the shared student-facing visual** (it already exists and is good), and keep Concept/Communication/Practice as the internal design vocabulary for what threads through both courses. One picture for students, three threads for us.

---

## The shared skeleton

Phases, not module numbers — because CTI runs 8 modules and CSC runs 16 weeks. The bones are the phases; each course maps its own units into them.

| Phase | Shared bones (language-independent) | CTI 110 — Python skin | CSC 134 — C++ skin |
|---|---|---|---|
| **A · Orientation** | What this field is; how software actually gets made; the AI stance ("you still have to know what you're doing"); account + toolchain setup | **M0 Welcome to IT** — systems = people+process+tech; self-checkout example; IT roles/paths; zip/unzip, files-on-disk, GitHub account | **Full M0, kept** — the "why are we even in this building in front of computers" step-back is unskippable. Reframed for a ~75% CS/Engineering-transfer audience (AS/AE) vs. ~25% programming (AAS): the foundational *why* stays; the IT-roles/help-desk content flexes toward "why computation is foundational to your transfer degree" |
| **B · Talk to Computers** | Plain text is native to the work; the Markdown ladder; the GitHub submit workflow; decomposition + precise instruction *before any code* | **M1** — VSCode vs Word; `.txt→.md→.html`; Codespaces as the equalizer; **Robot Sandwich** → `module-01` | **Same** — Robot Sandwich adopted as-is (only the folder path changes); Codespaces primary; single-file convention flagged for later |
| **C · How to Solve Problems** | Why languages exist; flowcharts (Mermaid); pseudocode; user stories; **read-and-run working code before writing any (PRIMM front half)**; the error taxonomy; compiler-vs-interpreter made physical | **M2** — receive a working Python program, run it, describe it in your own words; Perspective Flip; Python landscape tour | Parallel — receive working C++, **predict/trace it (this is the Runestone `thinkcpp` spike)**, then run it; the Hello World tour; **the build step becomes visible here** |
| **D · Core Procedural** | State/IO → selection → iteration → decomposition; verification via trace tables and predict-then-run | **M3** basics · **M4** branches · **M5** loops · **M6** functions; FIGURE debugging; refactor-into-functions | Variables/IO → decisions → loops → **functions (re-sequenced to follow loops)**; the turtle iteration bridge; `g++ -Wall -Wextra` clean-compile bar; tiered C/B/A rubrics; RPG theming |
| **E · Data Aggregation** | Aggregate data; *same problem, more than one representation* | **M7** — lists/dicts → **sqlite3** recapitulation (database fundamentals); Car MPG | **Diverges, but time-aligned** — raw arrays → structs → **pointers (demonstrated in context, not as a separate unit)** → **classes/OOP**. Positioned in M7 to match CTI's complex-data timing; the struct→class arc is the natural on-ramp (a struct *is* a class without behavior) |
| **F · Synthesis** | Run the whole cycle end-to-end; front-load problem formulation; present and defend working software; AI permitted at implementation | **M8** miniproject + live presentation | Final themed (RPG/dungeon) project — the arc run once, end to end; builds on the M7 classes just introduced |

Read the table vertically: phases A–D are close to identical bones, and E–F are where the skins fully separate. Roughly **two-thirds shared, one-third divergent — by design.**

---

## What is genuinely shared (build once)

These are the concrete artifacts and moves that live in *one* place and serve both courses:

- **The Robot Sandwich assignment.** Already written, already excellent, already language-free. Adopt verbatim in CSC 134; change `module-01`'s path if needed and nothing else. Its rubric (Precision / Completeness / Format / Submission) is the template for every tiered rubric that follows.
- **The Error Taxonomy card** (syntax / semantic / runtime / logic). Same four words, both courses. This is also where the compiled/interpreted split does its teaching work — see below.
- **The prompt ladder** (Markdown → spec → user story → prompt). CTI's M1→M2→M8 progression *is* this ladder; CSC walks the same rungs.
- **PRIMM as the shared instructional model.** CTI states it outright (Predict → Run → Investigate → Modify → Make). CSC already does the front half without naming it: the Runestone `thinkcpp` tracing/prediction exercises *are* Predict-Run-Investigate. Naming PRIMM in CSC unifies the two courses' pedagogy for free and gives the thinkcpp spike a documented rationale.
- **Delivery standards — now program-level.** These are being adopted as a program standard, not just a CSC borrow: 10th-grade readability on prompts, Mermaid-in-Markdown as the flowchart standard, "no trick questions" as stated policy, and exit-ticket completion gates. CSC 134 and CTI 110 are the initial implementation.
- **AI Assistance Ladder — two ladders, on purpose.** CTI and CSC keep *separate* ladders. CSC's current policy stands because it carries a goal CTI's doesn't: *learn enough C++ to talk to an LLM assistant about C++ fluently.* A companion CSC ladder doc gets built out; the divergence is documented rather than reconciled away.

---

## The one deliberate divergence in the Practice spine

The courses diverge on the toolchain in exactly one place, and it is a teaching asset, not a problem: **CTI's Python is interpreted; CSC's C++ is compiled.** That difference has hands-on fingerprints and it lands precisely on Phase C, where the error taxonomy is introduced.

- **CTI (interpreted):** save, run. Many errors — including type mistakes — wait until the offending line *executes*.
- **CSC (compiled):** save, **build**, run. The same class of mistake is caught at build time; the program never runs.

Same taxonomy, surfacing at a different phase depending on the skin. This is the clearest possible demonstration that "compiled vs. interpreted" is a lived reality, not trivia — and because both courses share the taxonomy vocabulary, a student who moves between tracks sees the *same concept* behave differently, which teaches the concept better than either course could alone.

---

## Why share a spine at all (since these are siblings, not a sequence)

CTI 110 feeds CSC 121 (Python) and the IT track; CSC 134 is the C++ intro. They run in parallel, not in series. Sharing a spine buys three things: a **consistent foundation** for students who take both or transfer between tracks; **shared materials** (the robot sandwich, the taxonomy card, the rubric template, the SDLC visual) maintained once instead of twice; and a **coherent program identity** — the two front doors of the same building, not two unrelated rooms.

---

## Decisions resolved (this pass)

1. **M0 stays, in full, reframed.** The "why are we here" step-back is unskippable in CSC 134. It is reframed for the transfer-heavy audience (~75% CS/Engineering, ~25% programming): the foundational framing holds; IT-roles content shifts toward computation-as-foundation-for-a-transfer-degree.
2. **OOP/classes lands in M7 (Phase E)**, time-aligned with CTI's complex-data module. The struct→class progression makes M7 its natural home.
3. **Pointers fold into arrays/structs** in M7 — demonstrated in context where their use is motivated, not taught as a standalone unit.
4. **Delivery standards go program-level** (readability, Mermaid, no-trick-questions, exit-ticket gating); CSC 134 + CTI 110 are the first implementation.
5. **Two AI ladders, documented.** CSC keeps its current policy for the distinct "fluent-C++-with-your-LLM" goal; a companion CSC ladder doc gets written.

## Still open (not blocking)

6. **Shared-artifact ownership.** For single-source-of-truth artifacts (robot sandwich, taxonomy card, rubric template, SDLC visual), who owns each and in which repo, so a fix propagates to both courses?
7. **Phase labels vs. module numbers.** Adopt shared phase names (A–F) as a cross-course lingua franca, or keep native numbering and map informally? Related cleanup regardless: CSC's chapter materials still sit functions-before-decisions; the shared spine puts functions after loops, so the chapter numbering needs re-sequencing.

---

## Suggested next step

The proof-of-concept that would de-risk the most is a **single side-by-side lab spec for one Phase-D concept** (loops is the natural pick — the turtle bridge already exists on both sides), written once with two skins, using the shared rubric template and the PRIMM structure. If that reads clean in both languages, the model is validated for the whole procedural core, and the back-third divergences (E–F) become the only genuinely course-specific design work left.
