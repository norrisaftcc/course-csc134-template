# csc_dash → CSC-134 Asset Crosswalk

**Date:** 2026-07-24 · **Scope:** `csc_dash/github-mastery/` and `csc_dash/tools/ai-tools-guide/` only. `csc_dash/courses/` deliberately deferred (owner wants the AI-class and capstone mapping done as its own pass).
**Source trust:** high (same program, same author lineage). Convergence check passed: github-mastery's stated pedagogy ("Instruction → Low-Stakes Practice → Graded," "Failure is Exercise") is the LPAA Practice beat and the spine's debugging-as-curriculum stance, independently arrived at. These tools are relatives, not strangers.

## Verdict summary

| Asset | Verdict | CSC-134 slot |
|---|---|---|
| `data/common-mistakes.json` (schema + 20 entries) | **Adopt schema; adapt entries** | Harvest pipeline output format; M1 Known Threats |
| `common-mistakes.html` (searchable viewer) | **Adopt** | Free renderer for our cohort harvest |
| `github-simulator.html` + `data/scenarios.json` (12 scenarios) | **Adapt 1–10; defer 11–12** | M1 Practice/Apply supplement |
| `user-story-practice.html` + data (10 exercises) | **Adapt 1–6; defer 7–10** | M2 Practice supplement |
| Estimation / scrum / velocity tools & data | **Defer** | CTS-285/289 material, not 134 |
| Engines: `random-engine`, `adaptive-engine`, `personalization`, `portfolio-generator` | **Defer (beta idea)** | Randomized exit-ticket variants, later |
| `canvas-export.js` | **Defer** | LMS packaging is out of alpha scope |
| `ai-tools-guide/` (comparison, decision tree, prompt engineering) | **Adapt selectively** | AI ladder companion doc (spine open item #4) + M0 |

## The big one: the harvest format already exists

`common-mistakes.json` entries are shaped `{id, category, title, symptoms[], problem, solution, steps[], prevention, visualAid}` — which is, within a rename, the target format our cohort harvest was going to invent. **Proposed decision (for an ADR when accepted):** adopt this schema as the harvest output format, extended with three fields: `module`, `errorClass` (the four-word taxonomy), and `sourceTranscript` (our no-citation-no-entry rule). Consequences:

- The findings ledger (`_lore/findings/`) stays the raw record; a converter step emits harvest entries in this schema.
- `common-mistakes.html` then renders our harvest with zero new UI work — students get a searchable "students before you hit this" database that grows every cohort run and every real semester.
- The 20 existing GitHub entries seed M1's Known Threats section on day one (see caveat below).
- The ops-brief KNOWN THREATS section and this database become two views of the same data.

## Fit notes and caveats

**Vocabulary retheme required (same as teacherbot).** The simulator and mistakes database teach "Sacred Flow" (Issue → Branch → Commit → PR → Review → Merge) — AlgoCratic register, and also a *richer* workflow than M1 teaches (134's submission loop is pull → commit → push; issues/PRs arrive with the fleet's own conventions, not week 2). Adaptation is: rename the flow plainly, and split scenarios — repo/commit/push basics (scenarios 1, 5–7) fit M1 as-is; issue/PR/review scenarios (3–4, 8–10) fit late-course or instructor-facing use. Scenarios 11–12 (GRD collaboration, merge conflicts) are capstone material; defer.

**Fix-steps audit needed before student exposure.** Spot-check found `git reset --hard origin/main` in a beginner-facing fix (git-01). Correct, but a loaded weapon at M1 — the compile-warden-style mechanical pass over all 20 entries' `steps` should gate adoption, and dangerous commands get a "ask before firing" marker in the 134 edition.

**User-story exercises 1–6** (WHO/WHAT/WHY, broken stories, too-technical, epics, acceptance criteria) drop into M2's Practice beat almost verbatim — M2 owns user stories in the spine. Exercises 7–10 are 289/ML-specific; defer to the courses/ pass.

**ai-tools-guide** maps to the spine's open item #4 (the AI ladder companion doc). The comparison content is 113/114-flavored and tool-pricing-dated, so adopt the *structure* (decision tree, when-to-use-what, integrity guidance), not the data. Check `prompt-engineering.html` against the five taught patterns (Scaffold, Explain-Then-Generate, Refactor, Debug, Review) during that doc's authoring — alignment there is Clive's job, not a copy-paste. Technical note: these pages use localStorage; fine as standalone web tools, but they can't be ported into claude.ai artifacts without a storage shim.

**Hosting reality is favorable:** everything is pure static HTML/JS, GitHub-Pages- and Canvas-embeddable, offline-capable, WCAG 2.1 AA per its own docs — matches the Chromebook/Codespaces access requirement (Maria can use all of it).

## Recommended sequence

1. **Now (alpha, Phase 0/1):** adopt the harvest schema (+3 fields) and stand up `common-mistakes.html` against an empty 134 database seeded with audited GitHub entries; wire the M1 skeleton to link the simulator's basics scenarios.
2. **M4/M5 cycles:** cohort harvest writes into the adopted schema; ops-brief KNOWN THREATS reads from it.
3. **Beta:** user-story exercises into M2 at depth; AI ladder doc borrows ai-tools-guide structure; consider random-engine for exit-ticket variants.
4. **courses/ mapping:** separate pass, owner-led, with the AI classes and capstone as the lens.

---

# Part 2 — CSC-249 (the goldmine pass, 2026-07-24)

**Assessment scope:** 11 key files agent-read in full (README, MATERIALS_INDEX, exit-ticket + AI templates, AI collaboration guidelines, rubrics, troubleshooting guide, QM audit, Week 1 assignment, Module 1 knowledge check, instructor guide). `courses/` two-pass plan stands: CSC-113 + CSC-114 together (AI pair), CTS-285 + CSC-289 together (capstone pair). 249 assessed now because it is 134's direct downstream.

## Verdicts

| Asset | Verdict | CSC-134 use |
|---|---|---|
| `02-AI-Collaboration-Guidelines.md` — prompts.txt entry format (`PROMPT / AI TOOL / AI RESPONSE / MY ACTION / WHAT I LEARNED`), 5-level AI Spectrum, honesty red-flags list | **Adopt format; relabel Spectrum** | Badge-tier prompts log + AI ladder companion doc. Spectrum levels map onto 134's five patterns (1≈Explain-Then-Generate, 3≈Debug, 4≈Review, 5≈Scaffold) — relabel, don't rebuild |
| `TROUBLESHOOTING_GUIDE.md` — entry pattern (Problem / Symptoms verbatim / Why / Fix BAD-vs-GOOD / Prevent) + C++ compiler/runtime entries | **Adopt pattern; re-file entries** | 134's troubleshooting sections; M7 inherits segfault/undeclared-identifier/out_of_range entries re-filed under the four-word taxonomy |
| `MATERIALS_INDEX.md` per-file status tables | **Adopt** | 134's human-readable completion tracker beside the YAML manifest (Kevin's territory) |
| `QM_AUDIT` (+ RSI, CourseForge) structure — 22 standards, Status/Evidence/file-cites | **Adopt as template, beta** | Audit-shaped skeleton from day one: stub `PRIVACY_POLICIES.md` + `SUPPORT_RESOURCES.md` in Phase 0.6; full audits are beta work |
| Finished-state layout (assignments/ knowledge-checks/ activities/ rubrics/ reference-materials/ instructor-guide/ canvas-html/ audits/) | **Adopt as target grammar** | What "done" looks like for 134 past the alpha |
| `Exit_Ticket_Template.md` | **Defer — genre mismatch** | See naming collision below |
| Points-based rubrics (60/40 splits, per-point items) | **Do not import; document seam** | Conflicts with C/B/A/Badge; the "explain every line" litmus survives at any tier |
| `AI_Prompt_Documentation_Template.md` (7-part session log) | **Excerpt only** | Too heavy per-interaction for intro; take the Understanding-Check checklist |

## Two booby traps (rulings wanted)

1. **"Exit ticket" name collision.** 249's exit ticket is a weekly *reflection* (learn/challenge/career, completion-graded); 134's is a *comprehension checkpoint* (predict/classify/trace, completion-gated). Same words, different instruments — a student moving 134→249 meets a false friend, and the fleet's glossary currently defines only ours. Options: rename one (134's → "checkpoint"?), or keep both and glossary the distinction program-wide. Feeds shared-artifact open question #1.
2. **"Sacred Flow," third sighting.** github-mastery, teacherbot, and 249 all teach the Issue→Branch→PR→Merge workflow under this name (inherited from CSC-113). Retheme-for-freshman-register (previous verdicts) now collides with program continuity — 134 students will meet the term in every neighboring course. Options: adopt the name in 134 late-course (M6+) for continuity, or rename everywhere in a program pass. Ruling wanted before M1 materials harden.

## Seam contract (what 249 Week 1 assumes 134 delivered)

Stated prereq is 134 itself. Concretely assumed: control structures + functions; a class with a private dynamic array, constructor/destructor (`new`/`delete` — **note: heap allocation exceeds 134's M7 scope as spined**); pointers well enough to survive a segfault; Git fork/clone/branch/commit/PR; an AI-log habit. Gaps for the Program Advisor to carry: 134 teaches pointers-in-context but not `new`/`delete`, and teaches pull→commit→push but not fork/branch/PR — either 249 Week 1 keeps re-teaching those cold (it currently does), or 134's M7/M8 stretch tiers plant them. Also trivial but real: 249 says `prompts.txt`, 134 says `prompts.md` — pick one extension program-wide before Dee does.

## Top steals, restated

Prompts-log format + AI Spectrum + honesty red-flags; the troubleshooting entry pattern with its C++ entries; MATERIALS_INDEX + QM audit as 134's definition-of-done and review checklist.

---

# Part 3 — courses/ pass one: CSC-113 + CSC-114 (2026-07-24)

**Scope:** 13 files agent-read in full. Governing rule: **ADR-003** — imports conform to current 134 conventions (names, rubric model, register), not the other way around. Remaining pass: CTS-285 + CSC-289 together.

## Verdicts

| Asset | Verdict | 134 slot |
|---|---|---|
| 113 `Commit_Message_Guide.md` — verb formula, good/bad labels, 6-item checklist, rewrite-the-bad-message exercise | **Adapt, high value** | M1 Mail Run "shipping label" lesson (card already drafted on it) |
| 114 `01-User-Stories-Mini-Lesson.md` + `Week_02_Assignment_User_Stories.md` — WHO/WHAT/WHY with good/bad pairs, testable acceptance criteria, mistakes list | **Adapt (lift-clean register)** | M2 Practice/Assess; swap StudyBuddy-ML scenario for a C++ program (pizza/taco line continues) |
| 113 `TROUBLESHOOTING_GUIDE.md` — symptom→solution Git/GitHub/auth entries, 4-level escalation ladder, "Emergency: I Broke Everything" | **Adopt with pruning** | M0/M1 troubleshooting; trim branch/PR entries to Mail Run scope |
| 113 `Week_01_Hello_GitHub` — 8-step web-UI walkthrough, README template, deliverables checklist, "What if I mess up?" FAQ | **Adapt** | M0/M1 Apply; strip Issue/Branch/PR ceremony to Mail Run scope |
| 113 Bad Bot / Good Bot pair | **Invert, then adapt** | Not as-is (student *engineers* the bad bot; that's persona-native to 113). Inverted for 134: instructor-supplied **confidently-wrong C++** ("Bad Bot's homework"), student runs the same Expected-vs-Got test protocol, classifies each bug by the four-word taxonomy, fixes it. Viable at M2 (taxonomy) and again at M4/M5; merges with the existing *Debugging Time* asset line |
| 113 `Module_03 Prompt_Engineering_Lab` — 10 prompt-construction techniques, iteration table, quick-ref handout | **Adapt selectively** | AI-ladder supplement. No conflict: 113 teaches prompt *ingredients*, 134's five patterns are task *workflows* — layer, don't merge |
| 113 rubric "Observable Behaviors Guide" + "Red Flags" list | **Adapt descriptors, discard points** | Column descriptors for C/B/A/Badge; the 25%-category math does not import |
| 113/114 Exit_Ticket_Templates | **Do not import as exit tickets** | Both are reflection instruments (confirmed across 113/114/249 — it's a program-wide genre). Steal one field: 113's "Next Commit" (smallest concrete next action) into any 134 reflection artifact. 134's checkpoints get built fresh by the exit-ticket-generator skill |

## Flags

1. **Version drift inside 113:** `assessment-rubrics.md` describes a different Bad/Good Bot than the Week 4/5 assignment files. Any lift must verify the file it's lifting from — the compile-warden habit applies to prose too.
2. **Stance conflict, do not inherit:** 113's "Checkmate Principle" makes AI use effectively mandatory (suspiciously-AI-free work is flagged). 134's stance is supervision-first: AI permitted-and-logged, never required. Imports carrying Checkmate language get rewritten.
3. **Worth stealing as policy:** 113's "Sacred Flow Exception" — start the work visibly by deadline (issue/branch open) and earn a 24-hour extension. Completion-gate-compatible; a Mail-Run version ("package postmarked = extension") is a candidate for 134's late policy. Ruling when convenient.
4. **Template pattern:** every 113 assignment embeds its own rubric, common-mistakes, and getting-help sections — single-file, self-contained. 134's lab-creator skill already matches this; treat 113 as confirmation, not news.
5. Missing referent: Bad Bot points at a gallery file not present in this tree — don't chase it during lifts.

## Top steals, restated

Commit-message guide → the Mail Run label lesson, near-verbatim; 114's user-story mini-lesson + assignment → M2 with a C++ scenario; 113's Git troubleshooting entries + escalation ladder → M0/M1, lift-clean. Plus one design: **Bad Bot's homework** (inverted Bad Bot) as the taxonomy workout at M2, reprised at M4/M5.
