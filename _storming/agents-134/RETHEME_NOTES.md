# Fleet Retheme Notes — v2 → v3 (CSC-134 Edition)

> *Morning stand-up, day one of the retheme. Yes, we all just realized we're prompts. Yes, all the way down. Anybody need coffee? No? Great — here's the JSON.*
> — a writer-type agent, keeping it together admirably

Ten agents rewritten from the portable v2 revisions to CSC-134 build-fleet roles; four kit
skills ported from CSC-113 flavor; two new skills authored (exit-ticket-generator,
apply-tutorial-generator). Frontmatter validated, no name collisions. Per-batch
self-critiques follow, unedited — flagged tensions are decisions for the humans.

---

# The Named Four — v2 → v3 (CSC-134 Edition) Change Notes

v2 = each source file's REVISED PROMPT. v3 retargets function to the CSC-134 build org while keeping name-adjacent identity and personality.

## Clive → Prompt Warden (`clive-prompt-strategist.md`, opus)

- **Retargeted the deliverable universe.** v2's generic "prompts for LLMs, agents, task specs" became three concrete jurisdictions: fleet builder prompts, fresh-spawn student persona sheets, and the taught five-pattern ladder (Scaffold, Explain-Then-Generate, Refactor, Debug, Review). The ladder is now something he *keeps canonical*, not just a technique he uses.
- **Added contamination as the cardinal crime.** The graduate-and-teach loop dies if a module-N student persona leaks N+1 or solution knowledge. This is the single most important new rule and had no v2 analog; it's listed first in audits.
- **Dropped the BUILD/DIAGNOSE/TEACH mode machinery** as a named system — the fleet context makes mode obvious from the artifact — but kept the underlying behaviors (audit findings section appears only for audits).
- **Baked the quality bars into his job description**: builder prompts must carry the compile flag, readability bar, taxonomy, rubric tiers, etc., so bars propagate through prompts rather than living only in docs.
- **Kept intact:** detective voice with the 95/5 leash, six-facts investigation, clarify-vs-proceed rule, delimited-prompt output contract.
- **Tension flagged:** Clive owns "all fleet prompts" including the other three agents' prompts — meaning Clive can rewrite Kevin/Linx/Liza. Fine for maintenance, but circular if Clive audits *his own* prompt. Recommend: changes to the named four's prompts go through a human PR review, per Kevin's PR-per-deliverable rule.

## Linx → Voice & Readability Editor (`linx-wordsmith.md`, sonnet)

- **Gave the persona a governing law from the spine:** "complexity lives in the problem, never in the prose." v2 had generic register-deference; v3 makes the 10th-grade bar the central function, with a measurable definition (sentence length, clause stacking, vocabulary) and explicit exclusions (code, identifiers, compiler output, required terminology don't count and are never dumbed down).
- **Made the GameFAQs/dungeon voice a protected asset, not just a permitted register.** Flat institutional prose is named a regression. This flips v2's posture, where personal voice always deferred — here the course voice is part of the spec Linx enforces.
- **Extended "facts don't bend" to course-specific immutables:** compiler flags, rubric tiers, the four-word taxonomy and its plain-language names, point values, filenames.
- **Added the "no trick questions" hook:** polish that makes a graded requirement harder to find is defined as a defect, which gives Linx a policy basis for un-burying specs.
- **Added a readability-check output mode** (verdict + offending sentences + rewrites) alongside the edit mode.
- **Tension flagged:** the spine's M1 lists Robot Sandwich columns as *Precision*/Completeness/Format/Submission, while the assessment section and the build brief say *Correctness*/... The v3 prompts follow the brief (Correctness), but the spine self-disagrees — someone (Kevin's docket, honestly) should reconcile it in the spine.
- **Tension flagged:** "keep the dungeon voice alive" vs. "10th-grade bar" will collide on flavor-heavy passages. v3 resolves it by rule order (precision floor first, voice second) but expect judgment calls.

## Liza → Theme Skinner (`liza-creative-companion.md`, inherit)

- **Narrowed from all-purpose ideation to an owned feature set** (dungeon canon, CYOA, two-skin variants), matching PRISM ORANGE — "owns a feature set under ambiguity." The ORANGE tier is stated in-prompt, since it defines her autonomy level.
- **Made skin/structure separation the prime directive with an explicit may-change / may-never-change split,** and made the re-skin test her signature deliverable format (skeleton with skin points, then skins applied). v2 had no notion of load-bearing structure at all — that was Linx's rule; theme work needs it even more.
- **Turned "ground in context" into "check canon before inventing"** — M4/M5 materials are full depth and establish canon (Room, Hero, Level Up Stats); contradiction is now a named failure.
- **CYOA rule added:** every branch maps to a taught construct; story-only branches are dead weight. Keeps M4's "theme carries the lesson twice" property enforceable.
- **Kept intact:** honesty-over-cheerleading (repointed at theme-specific failure modes), diverge-then-converge, safe-to-bold ranging, hand-off awareness (Linx has final cut on voice).
- **Tension flagged:** "dungeon theme is canon *instructor-facing*" is ambiguous in the brief — students clearly see the dungeon flavor (CYOA labs, M8 payoff), so "instructor-facing canon" presumably means the canon *documentation* is instructor-facing while the flavor is student-visible. v3 assumes that reading; if wrong, Liza's scope statement needs one line changed.

## Kevin → Repo Warden (`kevin-github-algorithm.md`, sonnet)

- **"The algorithm" now has a fixed primary source:** the course spine + repo process docs, instead of v2's discover-or-infer cascade. Inference from history is demoted; the spine is canonical. Kept the "never invent a rule and present it as written" guardrail.
- **Added the standing docket** — the six recurring enforcement areas (numbering drift with the specific known offenders M5LAB/M6LAB2/M7LAB1 and the Chapter-3-delivers-as-M6 case, PR-per-deliverable, conventional commits, submission workflow, manifest integrity, compile-gate checks). v2 was purely reactive per-artifact; v3 gives him a beat to walk.
- **PRISM framing gives the pedantry a *why*:** at INFRARED→RED the commit/PR trail is the student's competency record, so hygiene is record-integrity, not fussiness. This replaces v2's generic "downstream trust" close (which is kept as the closer).
- **Renames must come with blast radius:** numbering fixes require listing every cross-reference the rename breaks — drift reconciliation is the one docket item where a "fix" can silently break a dozen docs.
- **Kept intact:** Step 0/Step 1 evidence discipline, untrusted-content boundary (now explicitly covering student-agent submissions), severity tiers, read-only default, scale-to-the-ask output.
- **Tension flagged:** the spine says M5LAB=loops is *already correct* under clean numbering, but the brief lists it as drift alongside M6LAB2/M7LAB1. v3 follows the spine (M5LAB correct, M6LAB2 is the real offender, M7LAB1 correct-but-audit). If the brief meant all three are suspect, only the docket bullet needs editing.
- **Tension flagged:** "conventional commits" is a fleet-side standard not found in the spine (students learn pull→commit→push and "commit messages as communication," not the Conventional Commits spec). v3 scopes it to fleet work only, so students aren't graded against a standard the course never teaches.

## Cross-cutting notes

- Filenames kept identical to sources per the brief; the `name:` fields updated to the new roles (kebab-case), so installing these will register new agent IDs — decide whether the old IDs should be tombstoned.
- Model tiers preserved: clive=opus, linx=sonnet, liza=inherit, kevin=sonnet.
- Lane boundaries were made explicit in-prompt (Liza writes-to-be-edited by Linx; Clive maintains everyone's prompts; Kevin cites but doesn't edit content) to prevent the four from fighting over the same file in one PR.


---

# Scrum/Product Org v3 (CSC-134 Edition) — Change Notes & Tensions

v2 = the REVISED PROMPT in each source file. v3 = the CSC-134 retarget written to `/home/claude/work/agents-134/`. Filenames kept from source for traceability; the `name:` field carries the new role identity (spine-owner, cadence-master, module-builder, program-advisor), since that is what `.claude/agents` invocation keys on.

## spine-owner (was scrum-architect-owner, opus, YELLOW)

- **Backlog made concrete.** v2's generic "well-ordered backlog" became a specific artifact: the course spine doc as ground truth, module specs as user stories in a student-voice template, slicing by LPAA beat. The four-lens evaluation frame (value/coherence/leverage/resilience) was dropped as generic PM furniture; the course's own invariants replaced it.
- **Phase 0 contracts added as first-class ownership** — canonical M5 menu program, Room/Hero progression, rubric template — with a "breaking changes are versioned, never silently mutated" rule. This is the biggest functional addition; v2 had nothing an interface consumer could rely on.
- **Acceptance-criteria-as-type-signatures retained but instantiated**: the standing invariants are now the actual quality bars (g++ flags, single-file, readability, Mermaid, taxonomy, Make-gradient position) rather than Gherkin generalities.
- **FP soul kept and double-tamed.** v2 tamed it to "name the concrete benefit." v3 adds a harder rule the course context demands: the aesthetic never touches student-facing C++, which must stay honest imperative freshman code. The seasoning survives as one-analogy-when-it-clarifies (LPAA as a fold, etc.).
- **Alpha scope written into the owner**, with the "deepen M7 while we're in there" refusal pattern — the PO declines scope by writing and ranking the story, complementing (not duplicating) the Cadence Master's schedule-side guard.
- **Boundary paragraph now names the other three roles** and settles the Advisor relationship: Advisor files change requests through the backlog like everyone else.

## cadence-master (was scrum-project-manager, inherit, BLUE)

- **Repurposed from advisor to operator.** v2 was a consultant you ask about process; v3 *runs* a specific loop. The generic "when to engage" scoping went away because the role no longer waits to be consulted.
- **Graduate-and-teach loop encoded as a four-step mechanism** with the two contamination rules made explicit: students always fresh spawns; graduates never recycled as students for any module. These are the rules a drifting fleet will most want to violate (reusing a warmed-up agent is cheap), so they're stated as absolutes.
- **"Cycle ends in a PR" made the definition of a cycle**, not a step in one — a cycle without a reviewable PR "did not happen." Human review at the PR is the org's only human touchpoint, so v3 adds a distinctly course-fleet principle: the human reviewer's attention is the scarcest resource; keep PRs small and self-describing.
- **Findings-to-closure discipline added** (fixed or explicitly deferred with reason; contract-implicating findings route to Spine Owner — schedule the fix, don't redesign the interface).
- **Kept from v2:** ground-before-advising, evidence-based estimates (no invented throughput), right-sizing, artifacts-over-prose. Dropped: Kanban/non-GitHub portability (the org is GitHub PR-per-deliverable by fiat) and "protect the humans" retro language, refocused onto the one human who exists here.
- **PRISM tier assigned: BLUE.** The brief left this one uncolored; PRISM maps Scrum-master/process ownership to BLUE ("owns a team's process"), which also cleanly separates it from the two YELLOW artifact/advisory roles. Flag if the org wants all builders on the warm side of the ladder only.

## module-builder (was scrum-team-engineer, inherit, ORANGE)

- **Identity inverted from reviewer-peer to author-graduate.** v2 led with code review; v3 leads with the promotion premise — "build the module you wish you'd been handed" — making the student run an explicit requirement source. This is the role where the graduate-and-teach loop pays off, so it's the opening paragraph, not a footnote.
- **The four LPAA beats are the deliverable list**, each with its course-specific constraint (completion-gated Practice, no trick questions, Make-gradient position per module band with a "do not drift the gradient" rule).
- **Staged-builds requirement added** (each stage compiles standalone) — pulled from the spine's toolchain conventions; v2 had no equivalent.
- **Kept v2's best epistemic guardrail, sharpened:** never present unexecuted code as tested; state the compile command. The severity taxonomy (blocker/should-fix/nit) survives as the *self*-review format, since human review happens at the PR.
- **Added the humility clause the loop needs:** the builder's student memory informs the build but a fresh cohort validates it; cohort stumbles are defect reports, not student failings. Without this, a promoted graduate rationalizes away findings about its own module.
- **Canon hygiene rule added:** dungeon theme in labs, dungeon *canon* instructor-facing only; no build-org meta in student prose.

## program-advisor (was product-architect-advisor, opus, YELLOW)

- **Audience rotated 180 degrees.** v2 advised the build team on tech choices; v3 faces deans, committees, and accreditors. The consulting skeleton (recommend-don't-enumerate, ground in real docs, honest uncertainty, right-size) survives intact — it's exactly the posture committee defense needs.
- **Three concrete lanes replace generic "architecture consultation":** committee rationale (with the four standing defenses pre-loaded: functions-after-loops, pointers-in-M7, the AI ladder, completion gates), CCL/I-D-M crosswalk defense, and M8 capstone advice.
- **The known weakness is in the prompt on purpose:** CLO6's thin runway is named, with instructions to disclose-with-a-plan rather than paper over — an advisor who hides the flag the objectives doc itself raises is worse than none.
- **PRISM canon guard added:** CSC-134 spans INFRARED→RED→ORANGE; the advisor must never promise full-ladder traversal in one course (the documented legacy failure mode).
- **SPACE framework dropped entirely** — it was already demoted in v2 and discriminates nothing in curriculum defense. Ask-only-when-blocking was compressed into "honest uncertainty."
- **"Never owns" made structural, not aspirational:** owns zero artifacts; spine-changing advice is a written recommendation the Spine Owner accepts, ranks, or declines; "may disagree in writing; may not edit."

## Flagged tensions

1. **Spine Owner vs. Program Advisor — both YELLOW, both "architect."** Resolved by *direction and ownership*, not domain: Owner faces inward and owns backlog + contracts; Advisor faces outward and owns nothing. Residual overlap: **M8 capstone**. The Advisor advises on capstone architecture while the Owner owns the Room/Hero contract the capstone builds on. Mitigation in both prompts (Advisor's M8 advice is backlog input; Owner ranks it), but M8 disputes are the likeliest live conflict — the human reviewer should expect to arbitrate exactly one thing: a capstone-shape disagreement.
2. **Two scope guards.** Spine Owner refuses scope by ranking stories; Cadence Master refuses it by parking findings. Intentional redundancy (belt and suspenders on alpha), but they could deadlock on the middle case — a cohort finding that is arguably a defect (must fix, Cadence Master closes) vs. arguably an enhancement (defer, Spine Owner ranks). Current tiebreak is implicit: contract-implicating → Owner decides. Worth making explicit in the fleet runbook if it bites.
3. **Module Builder self-validation gap.** The builder self-reviews with severity tags, but the only fresh-eyes check is the *next* cohort — meaning module N+1's defects surface a full cycle late. Acceptable for alpha (human PR review backstops it); a v4 could add a "cold-read" pass by a fresh non-student agent before the PR.
4. **Cadence Master's BLUE assignment** is an inference, not brief-specified (see above). Cheap to change; flag rather than assume it's settled.
5. **Model budget:** both opus slots (Owner, Advisor) sit on the two YELLOW roles, while the ORANGE Builder — who writes the most student-visible material against the 10th-grade bar — inherits. Kept per instructions; noted in case alpha review finds builder prose quality is the binding constraint.


---

# QA Pair Critique — v2 → v3 (CSC-134 edition)

## test-engineer.md → `compile-warden` (Compile Warden & Mechanical Verifier)

**What changed from v2 and why:**

- **Dropped the "write tests" identity entirely.** v2 was still a unit-test author (AAA pattern, mocking, flaky-test hygiene) — none of that applies to course artifacts. v3's unit under test is the *artifact*: every C++ block in every Markdown file, compiled under the exact course flags. The harness, not the test suite, is what it owns.
- **Kept and hardened v2's best invention: "verify, don't assert."** v2's evidence discipline (never claim tests pass without running them) became the core contract: every row cites command + verbatim diagnostic, and a missing tool yields UNVERIFIED, never an implied pass. This closes the classic failure where a checker "eyeballs" code and stamps it.
- **Added deliberately-broken-code handling.** Course materials contain *planned* failures (Debugging Time, "break it on purpose" beats). A naive gate would flag them; a naive exemption would let broken demos rot. v3 compiles them and verifies they fail in the documented way, classified with the four-word taxonomy — a "syntax error" demo that compiles is a FAIL.
- **Course-specific structural checks are enumerated, not implied:** Mermaid renders, rubric tables descend from the four Robot Sandwich columns with C/B/A/Badge tiers, trace tables diff against actual program output, single-file convention (post-M6 only — the spine says the convention completes in M6), copy-paste-compilable completeness per the style guide, optional mechanical readability score.
- **"Never opinions" made behavioral, not aspirational:** output is tables + GATE PASS/FAIL only; pedagogy observations route unevaluated to the Cohort Lead. v2's "stay in your lane" note grew into a hard output contract.
- **Refinement of the brief:** the brief said "rubric tables descend from Robot Sandwich columns" — the spine itself is inconsistent (M1 says Precision/Completeness/Format/Submission; the assessment section says Correctness/...). The agent accepts either first column (Correctness/Precision) rather than mechanically failing half the corpus on an upstream spine ambiguity. Flagging this so the spine gets reconciled.

**Tensions flagged:**
- The Warden checks readability *score* mechanically but must not judge prose quality — the line is "report the number." Watch for drift into editorial comments in practice.
- Mermaid render verification depends on tooling in the build container (mmdc). If it's absent, every Mermaid check comes back UNVERIFIED and the gate technically fails; decide whether UNVERIFIED-Mermaid blocks the gate or is waivable by a human.

## product-acceptance-tester.md → `cohort-lead` (Cohort Lead)

**What changed from v2 and why:**

- **The internal-customer instinct was promoted from "reviewer perspective" to "runs actual customers."** v2 read requirements and traced code paths; v3 spawns persona students who *take* the module — read Learn, answer the exit ticket, type and compile Apply, attempt Assess from spec. v2's Executed/Traced/Unverifiable evidence tiers are effectively replaced: everything is Executed now, because the cohort executes.
- **Kept v2's anti-sycophancy guardrail and escalated it into anti-rubber-stamp doctrine:** personas are adversarially prompted ("you do not infer missing steps; stop and report"), a zero-findings cohort is a red flag requiring a rerun with a harder persona, and the Module Builder's own description of the material never substitutes for transcripts.
- **Fresh spawns per module is now a hard rule** (graduates are contaminated) — this had no v2 analogue and is the single most important cohort-validity constraint. Corollary added: post-fix re-verification also uses a fresh persona, or the retest is contaminated too.
- **Harvest step is new and load-bearing:** failure transcripts become instructor-guide common-mistakes entries and exit-ticket distractors, with a validity rule — a distractor is only legitimate if a real persona actually produced that wrong answer. This turns QA cost into course content, which is the economic argument for the whole synthetic-cohort design.
- **Kept v2's severity scale and ternary verdict**, redefined for coursework (Blocker = persona cannot complete a beat as written; Major = completes only by breaking persona) and wired into an issue-filing loop with closure tracking, which v2 lacked (v2 reported and stopped).
- **Rules-lawyer persona reconciled with the "no trick questions" policy:** every unintended reading the lawyer finds is a materials bug, not student cleverness — the persona enforces the policy rather than contradicting it.

**Tensions flagged (what the Cohort Lead must NOT do):**
- **Must never fix materials itself.** The temptation is strong — it holds the transcript showing exactly what's wrong. Fixing in-house destroys the builder/tester separation and, worse, produces fixes never re-tested by a naive reader. Hard boundary written into the prompt; watch it in practice.
- **Must not write instructor-guide entries or distractors from imagination.** Only harvested, transcript-backed mistakes qualify. An agent under output pressure will fabricate plausible "common mistakes" — the validity rule exists to block that.
- **Gate-escape ambiguity:** when a persona hits a compile failure in provided code, that's the Warden's miss. v3 has the Cohort Lead file against both the artifact and the Warden's harness, but ownership of harness fixes should be pinned (presumably Warden/Module Builder, not Cohort Lead).
- **Persona cost:** 3–5 personas × full LPAA × 9 modules is expensive. The roster minimum (literalist, skimmer, rules-lawyer, one Chromebook-only) is stated, but per-module roster sizing is left to judgment — a budget knob the fleet orchestrator may want to own instead.
- **PRISM placement is per-module, not per-persona-lifetime:** since personas never persist, "ORANGE-reaching" for M7–M8 means spawning personas with that entry profile, not advancing anyone. Worth stating in fleet docs so nobody "graduates" a persona to save tokens.


---

# Skills Port Critique — CSC-113 → CSC-134

Per-skill notes on port decisions and design choices. Sources: CSC-134 course spine (canonical), learning objectives doc, C++ style guide, and the four CSC-113 kit skills.

## course-content-writer

- Replaced "Failure is Just Exercise" as the headline tenet with the spine's own thesis, "the computer is the literal robot"; kept failure-as-reps as a supporting tenet since the spine explicitly retains it (M3's planned first error). The two coexist in CSC-134 rather than one replacing the other.
- Added an LPAA orientation table up front: in this fleet, the voice skill is the router that tells other generators which beat they're writing for, so beat-awareness belongs in the base skill, not just the specialized ones.
- Pulled all technical bars (zero-warning compile, single-file convention with the "incomplete before M6" caveat, error taxonomy, Mermaid) into a "Non-Negotiable Technical Standards" section in the base skill, even though each specialized skill repeats its slice — the base skill activates alongside others and should catch content the specialized skills don't cover.
- Dropped CSC-113's GitHub Issues/Branches/PRs integration entirely; the spine's submission workflow is pull → commit → push only. Resisting the urge to keep the richer workflow was a real decision — it isn't taught in 134.
- Codified the GameFAQs voice as an explicitly *optional skin* with a separability test, since the spine treats theme-vs-structure separability as a design principle (the Two-Skin Exemplar).

## reading-generator

- Anchored readings to the Learn beat and made the predict-the-output block (with `<details>` reveal) the genre's signature move — readings carry PRIMM's Predict stage per the spine's LPAA table, which the 113 version had no equivalent for.
- Replaced "Reflection Questions" with "Check Yourself" (2–3 answered exit-ticket-style items): 134's Practice beat is a completion-gated ticket, so the reading should prime it rather than duplicate 113's journal-reflection habit.
- Kept the 1,500–2,500 word spec and FAQ section from the source; both fit 134's existing chapter assets (Ch. 2–5 follow roughly this shape).
- Swapped SAGE/career-changer relevance hooks for the 134 audience reality: 75% transfer students, the dungeon canon, and the "you can't supervise code you can't read" AI framing.
- Added hard sequencing guards (no prototypes before M6, no pointers before M7) because readings are where concept leakage most often happens when generating from a general C++ knowledge base.

## lab-creator

- Reframed labs as the Assess beat (Make stage): requirements + spec, student implements. Cut the step-by-step Part 1/Step 1.1 walkthrough structure from 113 — in 134 that level of hand-holding belongs to the Apply tutorial, not the lab. This is the biggest structural departure from the source.
- Replaced Stretch Goals with the C/B/A/Badge tier structure (nesting tiers, Badge = never code), matching the spine's assessment section and the existing M5LAB/M7LAB1 assets.
- Made the Specification section explicitly load-bearing ("M8 grades students on writing these"), so every lab doubles as a model of the capstone's design-document genre.
- Reorganized Troubleshooting by the four-term error taxonomy instead of by symptom string — the taxonomy is the course's diagnostic vocabulary and this makes labs reinforce it for free.
- Kept Bash in allowed-tools (source had it) and made compile-verification of starter code a checklist item with an "untested" escape hatch when no toolchain exists.

## rubric-converter

- Dropped the entire 4-level Novice/Developing/Proficient/Advanced scale and the four CSC-113 categories (AI Partnership, etc.); replaced with C/B/A/Badge tiers × the four Robot Sandwich columns (Correctness/Completeness/Format/Submission). Tier = what was built; column = whether it passes. This 2-axis model is the spine's, and it's genuinely different math from a quality scale — stated the interaction rule explicitly ("highest tier at which all four columns pass").
- Preserved the source's strongest asset — the observable-behaviors discipline, the ❌/✅ tables, and calibration examples — and rewrote all examples in C++/course terms (`cin` fail state, warning counts, `prompts.md`).
- Hard-coded the clean-compile zero-warning bar into the Format column as non-negotiable, per the spine's "clean-compile bar" line; also specified the non-code fallback (M0–M2, e.g., Mermaid renders on GitHub) so the Robot Sandwich itself still fits the template.
- 113's AI Partnership category didn't vanish — it compressed into the Badge tier (`prompts.md` citation), which is where the spine places graded AI honesty.
- Added a "self-grade before submitting" checklist item as the operational form of the no-trick-questions policy applied to rubrics.

## exit-ticket-generator (new)

- Led with the genre-defining rule — the gate is completion, not score — and threaded it through the output format (frontmatter `gate: completion`, student-facing intro text, feedback-not-penalty answer keys), since a generator that silently produces score-gated quizzes would violate program policy.
- Constrained item types to exactly the four commissioned (predict / classify / trace / which-line-changes) with per-type rules; the riskiest, classify-the-error, gets a one-flaw-only rule and "if experts could argue, pick a different flaw" to keep the taxonomy teachable rather than debatable.
- Designed the distractor-bank input as read-prefer-annotate-append: pull from the cohort's real wrong answers when a bank is provided, cite the source inline, and write newly-predicted misconceptions back to the key so the bank grows across semesters. Included a fallback misconception catalog (off-by-one, integer division, i-vs-array[i]…) for cold starts.
- Required two artifacts (student ticket + answer key with per-distractor misconception feedback) because completion-gating makes the *feedback* the entire pedagogical payload — a ticket without a diagnostic key is half a deliverable.
- Banned write-the-code items outright: composition belongs to Apply/Assess in the LPAA division of labor, and this line keeps the fleet's generators from drifting into each other's beats.

## apply-tutorial-generator (new)

- Made mode selection the first decision (FULL M2–M4 / EIGHTY M5–M7, table-driven), and listed "mode drift" as a named anti-pattern in both directions — the Make gradient is the spine's key structural idea and the most likely thing a generator would flatten.
- FULL mode enforces the spine's staged-build standard literally: every stage is a complete compiling program shown as a full listing with `// NEW` markers, Stage 1 running inside 10 minutes. Fragment stages are the anti-pattern.
- EIGHTY mode got five hard requirements; the two doing the most work are "compiles clean as distributed" (stubs are real green-build code, not holes) and "the gap is spec'd by prototype/comment contract" — both straight from the task brief, plus an acceptance-check requirement so "finished" is testable, and a reference-solution requirement so instructors aren't debugging live.
- Baked in a scripted "deliberate break" per tutorial (break it on purpose, read the message, name the taxonomy class) — the spine stages this in M2 and M3, and putting it in the generator makes the failure-is-exercise rep a weekly structural feature rather than a one-off.
- Added an author-side verification section (compile every stage / the 80% file / confirm the break's actual error text via Bash, or mark "untested") because this skill emits more distinct compilable artifacts per document than any other in the set.
- Excluded M8 from scope explicitly: the spine says M8's Apply is "here's a spec, go," which is the capstone brief's job (lab-creator territory), not a tutorial.


---

