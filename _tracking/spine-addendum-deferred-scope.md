# Spine Addendum — Deferred Scope

Topics the CSC-134 refresh **deferred, not dropped**. This is the honest ledger behind the spine's
M0–M8: what the reorg set aside, why, and what would bring it back. Deferral is a decision on the
wall, never a silent mutation. Program-review-facing.

| Topic | Legacy home | Status | Why deferred | Ready answer if it comes back |
|---|---|---|---|---|
| STL / `std::string` manipulation (`.substr`, `.find`, `<vector>`) as a **dedicated unit** | old manifest M06 | Deferred (alpha) | Not CCL-required; incidental `std::string` already woven into M3/M5, so basic string use is covered | Fold a focused slice into **M3** (the "pocketed" fold-in, ADR-011) |
| File I/O (reading/writing files) | old manifest M07 | Deferred (alpha) | Not CCL-required; no spine home; grading it as a Badge would grade untaught material | Add as an **M8 Badge**-tier extension (ADR-011) |

**Trigger to revisit:** genuine, observed student confusion attributable to one of these gaps (e.g.
surfaced in cohort QA). Absent that, they stay deferred. See
[[ADR-011-descope-stl-and-file-io]] for the ruling and the preserved fold-in option.
