# F-000 — Fleet and skill-guild installed into repo `.claude/`

**Date:** 2026-07-23 · **Status:** Recorded · **Branch:** `phase0/install-fleet-and-guild`

## What

Installed the v3 build fleet and the skill guild into the repo so they travel with a
clone/fork instead of depending on a user-level Claude config:

- `_storming/agents-134/*.md` → `.claude/agents/`, each file named by its frontmatter
  role slug (`spine-owner`, `cadence-master`, `module-builder`, `program-advisor`,
  `compile-warden`, `cohort-lead`, `clive-prompt-warden`, `linx-voice-readability-editor`,
  `liza-theme-skinner`, `kevin-repo-warden`).
- `_storming/skills-134/*/` → `.claude/skills/` (six generators: `reading-generator`,
  `exit-ticket-generator`, `apply-tutorial-generator`, `lab-creator`, `rubric-converter`,
  `course-content-writer`).

Closes the two install gaps flagged at 26FA kickoff: agents were only present at user
level (`~/.claude/agents/`), and the guild was source-only under `_storming/`.

## Finding: three fleet versions existed

Three distinct copies of the fleet were on disk and did **not** match each other:

| Source | Identity | Notes |
|---|---|---|
| `_storming/agents-134/` | v3 role names (`kevin-repo-warden`, …) | Plan §2 ground truth — **installed** |
| `_storming/agents/` | portable v2 revisions | museum / ancestry |
| `~/.claude/agents/` (user level) | older generic (`kevin-github-algorithm`, …) | pre-retheme; what was live before this |

Per `ULTRACODE_ALPHA_PLAN.md` §2, `_storming/agents-134/` is the fleet to install; the v3
frontmatter names align 1:1 with the plan §3 org chart. The user-level copies are left
untouched and are superseded for this project by the repo-level v3 set.

## Follow-up

- Open rulings in ADR-001 §0.1 (Precision vs. Correctness; cadence-master BLUE tier; PR
  target) still owed by humans before Phase 0 exit — see [[ADR-001-alpha-scope-and-locked-decisions]].
