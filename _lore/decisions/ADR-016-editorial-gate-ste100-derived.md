# ADR-016 — An STE-100-derived editorial gate gives bar #2 an instrument

**Date:** 2026-07-29 · **Status:** Accepted · **Deciders:** build fleet (Cadence Master),
enacting CLAUDE.md bar #2 under norrisa's backlog directive; ratifiable at this PR's review
**Relates to:** [[ADR-014-compile-gate-runs-on-gcc-in-ci]] (the gate-in-CI precedent),
[[ADR-015-markdown-blocks-mirror-gated-source]] (a gate's remit stops at prose the reader
sees), [[F-009-fallthrough-warning-claim-is-toolchain-dependent]] (the vouch-only failure),
[[F-014-m4-m5-hardening]] (the first application)
**Numbering note:** ADR-012 is the Canvas compositor and ADR-013 is reserved for the Haiku
persona ruling (issue #23, unwritten). This takes 016 — the next free number after 015 —
rather than filling the gap, per the CLAUDE.md rule against grabbing a contested number.

## Context

Mechanical quality bar #2 says student-facing prose reads at a 10th-grade level, "complexity
in the problem, never in the sentence." Bar #1 — "clean compile" — has two gates and a CI job.
Bar #2 had a human who read it and vouched.

That is exactly the state bar #1 was in before [[F-009]]: four false claims about compiler
behaviour shipped inside a module certified Ready, because "I read it and it was fine" is not
re-runnable and not a diff. Readability is softer than compiler output, but the failure mode is
identical — a pass nobody else can reproduce. The backlog directive names an **STE-100-derived
editorial gate** as the fix, applied to M4 and M5.

### Why STE-100, and why *derived*

[ASD-STE100](https://www.asd-ste100.org/) (Simplified Technical English) is the mature
controlled-language standard for making technical prose comprehensible to a non-native or
novice reader. It is the right well to draw from. But it cannot be adopted whole here, and the
reason is a *different bar*: CLAUDE.md's voice section requires a "GameFAQs register, not a
textbook" — warm, second person, a little playful. STE-100's article mandates, its ban on
`-ing` where a simpler form exists, and its one-approved-word-per-meaning dictionary would sand
exactly that off. A gate enforcing them would be one bar fighting another.

So the split is the whole design decision: **take the parts of STE-100 that serve a 10th-grade
reader — short sentences, a bounded reading grade — and leave the parts that have a voice.**

## Decision

**Ship `editorial-gate.py` (+ `.sh` entry point): a dependency-free instrument that measures
reading grade and sentence length on student-facing prose, and defaults to advisory.**

### 1. It measures grade and length, never word choice

Three numbers, on prose only:

| Measure | Source | Target |
|---|---|---|
| Flesch–Kincaid grade level | the bar's own "10th grade" | ≤ 10.0 (flag above 12.0) |
| Flesch reading ease | a second view (higher = easier) | reported |
| Over-long sentences | STE-100's sentence-length rule | > 30 words = named |

It never inspects grammar or diction. Those are Linx's editorial calls and carry the voice; a
gate touching them would be dictating prose — which [[ADR-015]] already put out of a gate's
remit ("requiring pages to carry file headers they do not want would have been the gate
dictating prose"). Grade and length are structural: you can shorten a sentence without changing
its register.

### 2. It scores prose only — code, Mermaid, tables, headings stripped first

Counting a `for` loop or a Mermaid node as a sentence measures the wrong thing, and it is the
readability analog of ADR-015's rule against "diffing text no student ever sees." Before
scoring, the gate removes YAML frontmatter, fenced code and Mermaid blocks, inline `code`
spans, HTML, Markdown tables, and headings (navigation, not prose), and reduces links to their
text. `_`-prefixed planning files (`_overview.md`, `_mlos.md`, …) are skipped by default: they
are builder notes, and bar #2 governs *student-facing* prose. The stripping is proved by a
self-test fixture whose only dense, long content lives inside a code fence and which therefore
must pass even enforcing.

### 3. It defaults to ADVISORY — and that asymmetry with the markdown gate is deliberate

The markdown gate ships **enforcing** because provenance is exact: a listing either is or is not
the same text as its `.cpp`. Reading grade is a **proxy**. A syllable heuristic that failed a
build over a warm, correct sentence scoring grade 10.2 would be worse than no gate — it would
train authors to fight the measure. So by default the gate **reports**: it prints a grade per
file and names the longest sentences, and the human keeps the call.

CI makes it enforcing on **one** thing: the grade, at the loose `target + 2.0` band (12.0 — two
full grades of slack over the bar). Student warm prose scores grade 5–8 (see F-014), so this
catches a genuine breakdown, not an editorial nuance. The sentence-length lint stays advisory
even in CI: it has honest false positives (multiple-choice options, answer-key metadata) and
its job is to point Linx at candidates, not to block a merge. Both are dials
(`FAIL_ON_GRADE`, `FAIL_ON_LONG_SENTENCE`).

### 4. It is its own CI workflow, not a step in the compile gate

Bar #1 is compiler behaviour; bar #2 is prose. They fail for unrelated reasons and are owned by
different people. Folding readability into "Compile gate" would blur two signals — the same
argument ADR-015 §8 made for keeping the compile and markdown *jobs* separate, one level up. A
new `editorial-gate.yml` keeps the signal independently readable.

### 5. It proves it can fail, on every run

Per ADR-014's rule that a gate which cannot fail is not a gate: five fixtures (`pass`,
`high-grade`, `long-sentence`, the independence of those two, and `code-ignored`) assert the gate
goes red when it should and stays green when it should. Because the gate ships advisory, these
failure paths only exist behind the dials — so the self-test is the *only* thing that exercises
them until someone turns CI enforcing, which is exactly when they must already work.

### 6. Scope is `modules/` — the student-facing tree

`_contracts/` is frozen reference, `assignments/` is frozen provenance (ADR-008), `_past_work/`
is legacy, and `.claude/skills/*` is builder-facing. None is student prose. The gate defaults to
`SEARCH_PATHS=modules`.

## Consequences

- **Bar #2 becomes re-runnable.** "I read it and it was fine" gains a number anyone can
  reproduce on a laptop or in CI, the same way ADR-014/015 did for bar #1.
- **M4 and M5 pass comfortably today** (median grade 5.7, all student files ≤ 8.1), so the gate
  ships green — the opposite of the markdown gate, which shipped red. That is the honest result:
  the warm register was already at grade level; the gate proves it and guards it. Baseline in
  [[F-014]].
- **The voice is protected by omission.** Nothing the gate measures can be satisfied by making
  prose colder, because it does not measure tone. This was the load-bearing reason to derive from
  STE-100 rather than adopt it.
- **The long-sentence list is advisory backlog, not a defect list.** The ~31 sentences over 30
  words in M4/M5 are rewrite *candidates* for a future editorial pass (Linx), recorded in F-014,
  not failures to fix in this PR — rewriting certified, gated prose to chase a proxy would trade a
  real risk (introducing an error) for a cosmetic gain.
- **Open question, not decided here:** whether STE-100 itself becomes *taught* content — the
  course has an AI-prompt-pattern ladder and "write it so a novice can read it" is a teachable
  discipline. That is a spine-owner call about course scope, not a tooling decision, and no ADR
  number is claimed for it (parallel to ADR-015's open question on the regeneration finding).
