# ADR-019 — the-algorithm-lite is provisional house style

**Date:** 2026-08-06 · **Status:** Accepted, **PROVISIONAL** — this ADR expires (see below)

## Context

`algocratic/the-algorithm-lite` hosts the `release/alpha` of a skill package offered as the
option for **small models expected to operate under appropriate constraints**. The build fleet
wants it as a **stand-in for house style while the problem is worked** — explicitly a
placeholder, not a settled convention.

The full form, `the-algorithm` v2, exists as a user-level skill: 2,898 words, 18,567 bytes,
loading whenever it triggers. The ask was a selector so the lighter form is the default.

**The premise arrived unmeasured.** "It is token lighter" is a quantity claim, and
[[F-022-split-picture-rail-calibration]] had just finished measuring what those cost: "~2,200
words" produced three defensible counts spanning 2,056–2,620, and one spec demanded deleting
650 words from a passing reading to satisfy a number the repo's own tool disagreed with. **A
quantity requirement without a named instrument is uncheckable however checkable it looks.**

Upstream could not be fetched. `raw.githubusercontent.com` is denied by this session's egress
policy — 403 on CONNECT, recorded by the proxy — and per its README a policy denial is reported,
not routed around. The repository was not attached. So the choice was: vendor a file we could
not read and repeat its size claim, or compress the form we *do* have and measure that.

## Decision

**Compress it ourselves, measure the result, and mark the whole thing provisional.**

1. **`.claude/skills/the-algorithm-lite/SKILL.md`** is *our* compression of the v2 prose form,
   applying that document's own Self-hosting clause — it is explicitly subject to its own floor
   test. **Invariants are carried verbatim**, per v2's rule that no edit may paraphrase them;
   the gate-integrity block is byte-identical. Everything cut was exposition, never
   specification.

2. **The selector is progressive disclosure plus description routing**, because Claude Code has
   no model-conditional skill loading. The lite body is the only thing that loads;
   `reference/v2-full.md` loads only on escalation. A `## Which form to use` table makes the
   choice visible to a human, not only to a router.

3. **A distinct name**, not a same-name override of the user-level `the-algorithm`. Same-name
   routing resolves by "most specific wins," which is implicit and fragile.

4. **`NOTICE` records what came from where**, including what could not be verified. No upstream
   commit SHA is written, because none was read.

### The measurement

Instrument: `wc -lwc`, both files, same method. Re-runnable.

| Form | Lines | Words | Bytes |
|---|---|---|---|
| `reference/v2-full.md` | 308 | 2,898 | 18,567 |
| `SKILL.md` (lite) | 226 | 1,791 | 11,040 |

**40.5% fewer bytes, 38.2% fewer words.** The gate set beforehand was ≥30% — it passes on a
number that existed before the result did.

## Consequences

**Good.** The default form is measurably lighter and the claim now travels with its instrument.
Invariants survive verbatim, so drift against v2 is a plain `diff`. The full form stays one
escalation away rather than being deleted.

**The cost, stated plainly.** This is *not* upstream's file. It is our compression of a related
document, reached by a different route, and it must never be diffed against upstream
`SKILL-mini.md` as though it were a copy. Two forms of the same discipline now exist in two
places, which is a drift surface — that is the price of not being able to read upstream.

**A real asymmetry, recorded because it breaks the obvious mental model.** The clearance ladder
(🟥 RED default, no right to the Customer seat) exists in upstream's mini and **not** in v2.
The lite form is therefore not a subset of the full one: escalating from lite to full would
*lose* the safety property that matters most for small models. Anyone reconciling these must
not assume full ⊇ lite.

**`running-the-bases` stays separate** as the teaching form, cross-referenced both ways. It is
course-facing prose built on the same four nouns; folding it in would lose the
pseudocode/interview seam F-022 calibrated.

## Expiry

**This ADR is provisional and must be revisited when any of the following is true:**

1. **Upstream becomes readable** — the repo is attached, or the egress policy allows the host.
   Then: diff, record the SHA, and decide whether ours or theirs is canon. The value of that
   diff is finding rules *we dropped*, not making the files match.
2. **The stand-in is used in anger** — a builder runs a real deliverable through it and the
   result is reviewed. Until then no one knows whether the compression cut something
   load-bearing.
3. **90 days pass** (by 2026-11-04) with neither of the above.

**On expiry the outcome is one of:** promoted to real house style with the Voice section of
`CLAUDE.md` rewritten around it, replaced by upstream's file, or dropped. **Provisional is not
a resting state** — this exists so that "we are still working the problem" stays a true
statement rather than becoming the permanent condition it describes.

Until then `CLAUDE.md`'s Voice and conventions sections remain canon, and this package is
registered in the Skill guild with the word *provisional* in its row.
