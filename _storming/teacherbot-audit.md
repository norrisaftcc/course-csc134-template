# tool-teacherbot — Prompt & Retheme Audit (2026-07-23)

*Audit performed by fleet agent against staged copies of README.md, CLAUDE.md, SYSTEM1_CLAUDE.md, SYSTEM2_CLAUDE.md, TA_SYSTEMS_PARALLEL_PLAN.md, claude_handler.py, routes.py, and the csc114 crosswalk. Caveat: auth.py was not staged, so `load_group_context`'s exact concatenation behavior is inferred from routes.py comments and docs.*

## What it is

tool-teacherbot is an alpha-grade "AI TA" platform (live on Render). **System 1** (built) is a Flask web chat: group login → per-group context file injected into a Claude system prompt → conversation + token logging in Postgres, with an admin dashboard. **System 2** (docs only, not started) is a planned Claude Code CLI distribution: per-group API keys, spend caps, and guardrails via generated CLAUDE.md templates.

## Where the prompts live

The only real LLM prompt is `system1-flask-chat/claude_handler.py:build_system_prompt()` — a ~20-line f-string (pedagogical rules, AlgoCratic vocabulary, style) with one hole: `{group_context}`. Per request, `routes.py` loads the group's context file and inlines it; message history is **client-supplied and unbounded**; no caching, no truncation, no retrieval. Output capped at `MAX_TOKENS=1024`.

## The 30k-token question

**Verdict: no statically coded 30k prompt — the hardcoded shell is ~180 tokens. The bloat is operational, not static.** Whatever lands in the context file is re-sent verbatim, uncached, on every request.

| Component | Size | ~Tokens |
|---|---|---|
| Static prompt shell | 0.7 KB | ~180 |
| csc114 crosswalk.md alone | 13.8 KB | ~3,500 |
| Full corpus if week folders get stuffed in | ~95 KB | ~24,000 |
| 20-turn history resent | ~15 KB | ~4,000 |
| **Worst case per request** | | **~28–32k, zero cached** |

The prompt design is fine; the delivery is wasteful. The system+context block is identical across a group's session — the textbook case for Anthropic prompt caching (~90% input-cost cut). History should be rebuilt server-side from the DB with a sliding window (also a trust problem: the client sends it).

## Retheme scope for CSC-134

Small. (a) Prompt: rewrite one f-string — drop Sacred Workflow/clearance/AlgoCratic vocabulary (wrong register for intro C++ freshmen; the CSC-134 style guide and LPAA voice slot straight in). (b) Corpus: the crosswalk format already uses Learn → Practice → Apply → Assess columns — identical to CSC-134's LPAA beats, so module docs port into `context/csc134/` with no format change. (c) Auth: hardcoded group1–5 plaintext credentials need replacing with sections. (d) Make `load_group_context` module-aware so only the current module's beats load.

## Recommendations (ranked)

1. Retheme is one function edit plus a context-folder swap — do it; don't fork or rewrite.
2. Add prompt caching on the system block before any classroom use — biggest cost lever by far.
3. Load per-module context (current LPAA beat only); cap injected context ~5k tokens.
4. Rebuild history from the DB server-side with a sliding window; stop trusting client-sent history.
5. Fix the alpha security list pre-classroom: query-string admin password, no CSRF, token-budget race, plaintext credentials.
