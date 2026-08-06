# Glossary

One line per term. Add on first use; point to where it's defined.

- **LPAA** — Learn / Practice / Apply / Assess, the module delivery loop (spine §"module delivery loop").
- **PRIMM** — Predict, Run, Investigate, Modify, Make; rides inside LPAA.
- **Make gradient** — Apply beat slides from type-in-100% (M2–M4) to finish-the-80% (M5–M7) to spec-only (M8).
- **Robot Sandwich** — M1 precise-instructions assignment; ancestor of every rubric's four columns.
- **Error taxonomy** — syntax / static semantic / runtime / logic; the four words used all term.
- **PRISM** — program-wide skills ladder (INFRARED→…→GREEN→…); fleet roles and course arcs both map to it.
- **Graduate-and-teach** — build pipeline: take module N as a student, build module N+1.
- **Fresh spawn** — a student agent with no prior exposure to the module under test; the only kind allowed in a cohort.
- **Contamination** — knowledge that disqualifies an agent as a naive tester (having taken or built the module).
- **Dry** — cohort state: two consecutive QA rounds with no new above-threshold findings.
- **Harvest** — converting cohort failure transcripts into common-mistakes entries and distractor banks.
- **Skin / structure** — theme flavor vs. load-bearing content; must separate cleanly (Two-Skin Exemplar).
- **Boss key** — the buttoned-up fork option: course + decisions, minus storming clutter, for external audiences.
- **The wall** — `_lore/`; marks go on it daily.
- **Mail Run** — 134's submission loop, pull → commit → push: check the mailbox, box it and write the label (the commit message), hand it to the carrier and check the tracking (ADR-003).
- **Exit ticket (134 sense)** — completion-gated comprehension checkpoint (predict/classify/trace). NOT the weekly *reflection* instrument other program courses call by the same name — imports get renamed (ADR-003).
- **Compile gate / markdown gate** — the two enforcers of bar #1: `compile-gate.sh` builds each `.cpp` on GCC (ADR-014); `markdown-gate.sh` proves each fenced listing is a faithful view of one (ADR-015). Neither is sufficient alone.
- **Editorial gate** — the instrument for bar #2 (readability): `editorial-gate.sh` scores reading grade and sentence length on student-facing prose, STE-100-derived, advisory by default (ADR-016).
- **LPAA gate** — the third enforcer: `lpaa-gate.sh` checks whether the repo's structural claims about itself are true — status vs. files, frontmatter vs. path, no shipped module calling itself unauthored (F-019). Enforcing since 2026-08-01.
- **Audience boundary** — the heading containing `not part of the student handout`, below which instructor content sits. A *label* is not a boundary: it tells a careful reader to skip and does not stop a student who scrolls (ADR-017, F-018).
- **Status vocabulary** — Skeleton → First pass → Built → Ready, defined in `modules/MODULES.md` and read from there by the LPAA gate. `Ready` means cohort-tested with findings closed, not proven against real students.
- **The seam (M4→M5)** — the M4 gatekeeper grown a loop: same decision, dropped into a do/while menu as one action, with `return 0`→`continue` and a cin-validation loop. Frozen in `_contracts/m5_menu.cpp`.
