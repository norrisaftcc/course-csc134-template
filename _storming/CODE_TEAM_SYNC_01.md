# CODE TEAM SYNC 01 — post-handoff deltas

```text
UNCLASSIFIED // FLEET USE // 2026-07-24
```

> ⚠️ **SUPERSEDED — historical record, do not act on this file.** Written by hand 2026-07-24;
> its ADR numbers were reassigned (002/003/004 here are now 005/006/007), its three "still open"
> rulings were closed by ADR-002, and it predates ADR-008–ADR-015 and both CI gates. The current
> picture is regenerated every run into `_storming/CODE_TEAM_SYNC.md` by the charter in
> `_storming/VERIFIER_BRIEF.md` (ADR-016). Kept as the record of why we stopped hand-writing it.

> **BLUF:** The plan (`_storming/ULTRACODE_ALPHA_PLAN.md`) stands. Since handoff: four ADRs
> are on the wall, the M1/M2 asset picture improved a lot (csc_dash crosswalk, 3 parts), two
> vocabulary rulings landed (Mail Run; exit ticket = checkpoint only), a late policy exists
> (Postmark Rule), and there are new exemplars in `_storming/exemplars/` you should treat as
> N-shot calibration. One Phase 0.1 ruling is STILL OPEN: Precision vs. Correctness.

## Rulings since handoff (all in `_lore/decisions/`)

- **ADR-002 — Negative Taco Ruling.** When a module can't defend against an input yet, the lab
  says so and dates the promise. Cohort treats spec'd-as-unspecified as not-a-finding.
- **ADR-003 — Mail Run + import direction.** 134's submission loop is **the Mail Run**
  (pull = check the mailbox; commit = box it + write the label; push = hand to carrier, check
  tracking). All csc_dash imports conform to current-134 conventions (`prompts.md`, C/B/A/Badge,
  register). "Sacred Flow" does NOT appear in 134 student materials — richer workflows belong to
  higher PRISM tiers/other courses. 134 touches ORANGE only at the end (agentic pair-programming
  on the M8 project); M1 GitHub interaction stays Mail-Run-simple by design.
- **ADR-004 — Postmark Rule.** Commit timestamp is the postmark; on-time commit reverses a late
  penalty; visible work by deadline earns 24-hr grace. One boilerplate line in every lab's
  Submission section: "Your commit history is your postmark."

## Plan deltas to apply

1. **Phase 0.6 skeleton:** each module scaffold now includes an `OPSBRIEF.md` front page —
   template + M4 worked example in `_storming/exemplars/ops-briefs/`. BLUF teach-box runs M0–M2,
   retires, returns once in M8.
2. **Harvest schema (default-adopt):** cohort harvest emits `github-mastery/data/common-mistakes.json`
   schema + three fields (`module`, `errorClass`, `sourceTranscript`); `common-mistakes.html` is the
   free viewer. Ops-brief KNOWN THREATS reads the same data. See crosswalk Part 1.
3. **M1 build inputs:** Mail Run card (`exemplars/m1-mail-run/`) is canon; adapt 113's
   Commit_Message_Guide + Hello_GitHub (stripped to Mail Run scope) + Git troubleshooting entries
   (symptom→solution, escalation ladder). See crosswalk Part 3.
4. **M2 build inputs:** 114's user-story mini-lesson + assignment, scenario swapped to C++;
   plus **"Bad Bot's homework"** (inverted 113 Bad Bot): instructor-supplied confidently-wrong C++,
   student classifies by taxonomy and fixes. Debuts M2, reprises M4/M5; merges with Debugging Time line.
5. **M3 exemplar pair:** Pizza Calculator + **M3LAB2 Taco Receipt** (`exemplars/m3-taco-receipt/`) —
   the N-shot pair for assignment authoring. Taco carries the representation≠display payload; all
   sample output is from real compiled runs; keep that standard (compile before you claim).
6. **Do NOT inherit from 113:** the Checkmate Principle (AI-mandatory stance — 134 is
   permitted-and-logged, never required) and anything from its version-drifted rubric file.
   General rule: verify the exact source file before lifting; 113 has internal drift.
7. **AI-ladder inputs:** 249's prompts-log entry format + 5-level Spectrum (relabel to our five
   patterns) + honesty red-flags. See crosswalk Part 2.

## Still open (Phase 0.1 — do not improvise past these)

1. **Precision vs. Correctness** as rubric column one — owner ruling pending. Blockers: rubric
   template (Phase 0.3). Flag it before building rubrics; do not pick silently.
2. Cadence-master BLUE tier — confirm with owner.
3. PR target (`alpha` integration branch proposed) — confirm with owner.

## New assets index

`_storming/exemplars/` (taco receipt, ops-briefs, m1-mail-run) · `_storming/CSC_DASH_CROSSWALK.md`
(3 parts: tools, 249, 113+114; CTS-285/289 pass not yet run) · `_storming/teacherbot-audit.md` ·
`_storming/personas-134/` (drafts; owner approval = Phase 0.5 gate) · `_lore/` (ADR-000…004,
glossary, findings format) · persona museum (static + live) in `_storming/`.

```text
END OF BRIEF // MIND THE POSTMARK
```
