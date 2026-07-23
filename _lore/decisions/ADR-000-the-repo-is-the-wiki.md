# ADR-000 — The repo is the wiki

**Date:** 2026-07-23 · **Status:** Accepted · **Deciders:** norrisa + Cowork session

## Context

The build fleet (and its humans) need durable memory: decisions, QA findings, vocabulary.
Options considered: external memory services (Letta/MemGPT, Zep, graph stores), GitHub's
wiki (a separate git repo outside PR flow), reverse-engineering from commit history later,
or plain markdown in-repo.

## Decision

Plain markdown in-repo, under `_lore/`, riding the same PRs as the work it describes.
No PR merges without its lore entry; Kevin (repo warden) enforces. External memory
infrastructure is rejected as overkill: our recall needs are greppable, diffable, and
reviewable, which is what git already is.

## Consequences

- Memory costs one convention instead of one service.
- Commit archaeology is never needed; the convention starts before the build does.
- The lore tree doubles as the accreditation/dean-facing paper trail ("the boss key"):
  a clean fork can present course + decisions without storming clutter.
- Risk accepted: discipline decay. Mitigation: the merge gate is mechanical, not aspirational.
