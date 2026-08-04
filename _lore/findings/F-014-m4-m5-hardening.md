---
name: F-014-m4-m5-hardening
description: M4 and M5 hardened for alpha — issue #30 markdown migration finished (45 blocks gated across both modules), the M4→M5 seam and EIGHTY-mode split verified against the frozen contract, and the new editorial gate applied with a green readability baseline (median grade 5.7).
---

# F-014 — M4/M5 hardening: migration complete, seam verified, editorial baseline

**Date:** 2026-07-29 · **Status:** Recorded · **Branch:** `copilot/ste-100-prioritize-backlog`
**Acts on:** [[ADR-015-markdown-blocks-mirror-gated-source]] §6 (the migration it tracked, issue #30) ·
**Enacts:** [[ADR-016-editorial-gate-ste100-derived]] (first application) ·
**Predecessor:** [[F-007-m5-deep-build]] (M5 Built), [[F-006-m4-fixes-and-ready]] (M4 Ready) ·
**Contract touched:** none — `_contracts/` unchanged

## Why this was done

The alpha's two deep modules, M4 and M5, each carried a hole. M4 was certified Ready but its
23 fenced C++ blocks were **unmigrated** — the markdown provenance gate (ADR-015) shipped red on
them by design, issue #30 the tracked debt. M5 had just been deep-built (F-007) and integrated
from PR #20, but its 22 blocks were unmigrated too. And bar #2 (readability) had no instrument at
all. This finding records closing all three at once, because they share one PR and one review.

## 1. Issue #30 — the markdown migration is finished

Both modules are fully gated. The per-file countdown ADR-015 §6 promised has reached zero.

| Module | Blocks | New gated twins written | Result |
|---|---|---|---|
| M4 | 23 | 16 | 23/23 match |
| M5 | 22 | 7 | 22/22 match |
| **Total** | **45** | **23** | **`markdown-gate.sh` green** |

The method followed ADR-015's own guidance exactly: **write the `.cpp` first, then quote it**.
Each block was classified against every candidate `.cpp` under three strategies — whole-file
`source=`, `excerpt=` as-is, and `excerpt=` after dropping N leading comment lines — and mapped to
the faithful source that shared its module and beat. Where no twin existed, one was authored to
compile standalone under `g++ -std=c++17 -Wall -Wextra`, then the block was annotated `excerpt=`.

Three details worth the wall:

- **Fragments get a `{ }` scope, not a bare wrapper.** A column-0 fragment whose one-statement body
  sits at 4-space indent collides with a wrapper's trailing `return 0;` under
  `-Wmisleading-indentation`. Wrapping the embedded fragment in a nested block puts a brace, not a
  statement, on the line after it. The fragment still matches `excerpt=` byte-for-byte; the warning
  goes away because the code is no longer misleading.
- **Staged builds get one file per stage** (ADR-015 §4). M4 Apply's Gatekeeper Stages 1–4 and M5
  Apply's Level-Up Stages 1–3 each have a standalone-compiling twin — bar #9 ("each stage compiles
  and runs standalone") is now enforced, not asserted. This also satisfies the directive's "gate
  the tutorial stages."
- **One pedagogical comment moved into the source, not out of the listing.** M5 Learn's do/while
  block carried a teaching note — `// <-- note the semicolon after do-while` — its `.cpp` twin
  lacked. Rather than strip the note from the student's page (losing the teaching) the note was
  added to `learn-menu-dowhile.cpp` (a true, harmless inline comment that improves the source too).
  The convention's "the `.cpp` is the one source of truth" is satisfied by making the file carry
  what the page shows, not by impoverishing the page.

Gate state after migration, course-wide: **compile 53 files (46 clean + 7 marked EXPECT-WARNING),
markdown 45/45 matched.**

### 1b. M4 Canvas re-emitted to track the migrated source

The migration edited M4's Learn source, so the four composed pages in
`_outputs/canvas-html/m4/` had drifted (ADR-012: the composed copy goes stale, and it is the one
that lies). Re-emitted the affected code blocks against the current Markdown: three self-naming
Stage headers (`// learn-gate-strength.cpp — Stage A`, `… class … Stage B`, `… full … Stage C`)
dropped so the `<pre>` matches the `excerpt=` slice byte-for-byte — the `.cpp` keeps its header, the
listing omits it (ADR-015 line 131) — and one bare `...` normalised to `// ...`. Nothing was
authored: the Stage-C fragment cue it carried already lives in the trailing prose ("The complete
runnable program is `modules/m4/code/learn-gate-full.cpp`"), and the `<h2>`/prose carry the concept
the headers named. Verified two ways: all four blocks now diff-clean against source, and the
compositor's own `gate.py` reports **0 failures across 4 fragments**. Apply/Practice remain
un-composed per F-008's rulings — unchanged.

## 2. The M4→M5 seam and EIGHTY-mode split are verified

The seam is the spine's load-bearing claim for these two modules: *M5 is the M4 gatekeeper grown a
loop.* Checked against the frozen contract `_contracts/m5_menu.cpp`, three ways:

- **The transformation is `return 0` → `continue`.** M4's gatekeeper ends the visit on a bad class
  (`return 0`, "single pass — one bad answer ends the visit"). The M5 contract drops that same
  switch in as one menu action and changes the default to `continue` ("no early exit now — the loop
  lets them try again"). The M5 material teaches exactly this: `learn-menu-dowhile.cpp` is headed
  "THE M4→M5 SEAM… the M4 gatekeeper decision, dropped in as ONE menu action."
- **The validation loop matches the contract byte-for-byte.** `learn-validate.cpp`'s
  `while (!(cin >> choice) || choice < 1 || choice > 3)` is the contract's guard exactly — the
  correct `||` form. The tempting-but-wrong `&&` form (a guard that is always false, so the loop
  never runs) is a clean-compiling **Logic** error, now captured as `apply-validate-wrong.cpp` and
  `assess-validate-wrong.cpp` — the twins behind M5 Apply's instructor note "if a student writes
  `&&`."
- **`apply-menu-complete.cpp` reaches the contract.** It is identical to `_contracts/m5_menu.cpp`
  except one comment word ("drop" vs "clear" the fail flag) — the student's Apply endpoint is the
  frozen program. The one-word variance is noted and accepted, not edited (the contract is frozen;
  the `.cpp` is the gated source its own block checks).

**EIGHTY mode (bar #8):** M5 Apply is a deliberate **SPLIT — Part 1 FULL type-in, Part 2 EIGHTY
finish-the-80%**. The student types the familiar M4-style decision material and *finishes* the one
genuinely new piece — the input-validation loop — behind a `// YOUR CODE:` marker with an
instructor-only reference. This is the correct reading of the Make gradient for the seam module: it
eases M4's 100%-type-in into M5's finish-the-80% by doing one of each in one class period, and the
missing 20% is precisely the new M5 machinery. Seam and gradient are coherent end to end.

## 3. The editorial gate is applied — M4/M5 read at grade level

ADR-016's gate was run across both modules. The result is a **green baseline**: warm register was
already at grade level, and now that is a number, not a vouch.

| | Files scored | Median grade | Highest | Over-30-word sentences |
|---|---|---|---|---|
| M4 + M5 (student-facing) | 10 | 5.7 | 7.5 (`practice-exit-ticket-key.md`) | ~31 (advisory) |

Every student-facing file scores **grade 4.4–7.5**, well under bar #2's target of 10. The
underscore-prefixed planning files score higher (10.8–12.0) and are correctly out of scope — they
are builder notes, not student prose.

The ~31 sentences over 30 words are **advisory rewrite candidates for Linx**, not defects: the
prose passes the bar, and rewriting certified, gated content to chase a proxy would risk
introducing an error for a cosmetic gain. Deferred to a future editorial pass (recorded as backlog,
not fixed here).

## What stays open

- **Editorial polish pass (deferred).** The advisory long-sentence list is a real, bounded backlog
  item for Linx — not alpha-blocking.
- **STE-100 as taught content (open question, ADR-016).** Whether the discipline becomes course
  material is a spine-owner call; no ADR number claimed.
- Neither blocks M4/M5's alpha readiness. With migration green, the seam verified, and readability
  instrumented, **M4 and M5 clear the mechanical bars for alpha.**
