# ADR-015 — Fenced C++ blocks mirror a gated source file; they are never independent copies

**Date:** 2026-07-25 · **Status:** Accepted · **Deciders:** norrisa (rulings) + Cowork session B
**Relates to:** [[ADR-014-compile-gate-runs-on-gcc-in-ci]] (the limitation this closes),
[[ADR-008-two-tree-module-layout]] (why `assignments/` is out of scope),
[[F-013-markdown-blocks-are-unversioned-copies]], [[F-009]], [[F-010]]
**Numbering note:** ADR-012 is claimed by the Canvas compositor (PR #24) and ADR-013 is
reserved for the Haiku persona ruling (issue #23, pinned but unwritten). This takes 015 rather
than filling the gap, per the CLAUDE.md rule against grabbing a contested number.

## Context

Mechanical bar #1 says **"every C++ block in every artifact"** builds clean. ADR-014 built the
gate that enforces it — but only over complete `.cpp` files, and recorded the gap honestly:

> The gate compiles complete `.cpp` files. […] a warning can hide in a Markdown listing that no
> `.cpp` file mirrors, which is exactly where two of the three F-009 defects lived.

Every defect found in M4 this week ([[F-009]], [[F-010]]) lived in a fenced Markdown block. We
fixed the instances. The class stayed open.

### What the corpus actually looks like

Measured across `modules/` and `_contracts/` (72 `cpp` blocks repo-wide, 23 in scope):

- **19 complete programs, 53 fragments.** Three quarters of all blocks cannot compile standalone.
- Fragments come in four distinct shapes, not one: statements from inside `main` that reference
  variables declared in an *earlier* block; deliberately-broken one-liners; "add the marked
  lines" diff excerpts; and stub bodies in skill templates.

So "extract and compile every block" is not available. Something has to say what a block *is*.

### The root cause is not edit drift

The obvious story — someone fixed the `.cpp` and forgot the listing — is not what happened, and
the distinction changes the decision.

`modules/m4/learn.md` and `modules/m4/code/learn-gate-strength.cpp` were **born in the same
commit** (`cc6e630`), from one authoring pass with one intent. They came out **non-identical**,
and have stayed exactly as non-identical ever since. Nobody drifted them; they were never the
same.

But comparing *code only*, with comments stripped, **6 of 9 complete listings are byte-identical
to a gated file.** The program was reproduced faithfully. What varied was the prose around it —
the `.cpp` carries a three-line explanatory header, the listing trimmed it to one.

That is F-009's exact shape. F-009 was **four false claims in prose** sitting on top of correct
code. Regenerating an artifact reproduces the part a compiler checks and re-samples the part
nothing checks. **The explanation is the fragile half, and it is the half that ships to
students.**

Two consequences follow directly, and both are decisions below: a duplicate listing is not a
copy but an independent sample, so the convention must be *identity*, not similarity — and
comments are in scope, because a comment asserting "this compiles clean" is precisely the defect
class we are gating against.

## Decision

**A fenced C++ block is not source. It is a view of a gated source file, and it must prove it.**

### 1. Two annotations, declared on the info-string

| Form | Means | Gate does |
|---|---|---|
| ` ```cpp source=path/to/x.cpp ` | the block is that whole file | match; **any difference FAILS**, printing the diff |
| ` ```cpp excerpt=path/to/x.cpp ` | the block appears within that file | match contiguously; difference FAILS |

An un-annotated `cpp` block fails the gate. So does an unrecognised `gate=` verb — a gate that
silently tolerates annotations it does not understand is one you can switch off with a typo.

**On the info-string, not in frontmatter.** A per-file manifest keyed by block index divorces the
declaration from the block: insert a block and every index below it shifts, so the gate starts
checking the wrong things while staying green. The declaration rides on the thing it describes.

**No line numbers.** An earlier draft used `#L18-L44`. Same defect one level down — insert a line
above the slice and the anchor silently points elsewhere. `excerpt=` matches by *content*, so
unrelated edits to the source cannot break a match and edits to the quoted code always do.

**No skip, and no mute of any kind.** The only thing a block can do is name a source and be held
to it.

### 2. Broken-on-purpose blocks are excerpts of marked files — the gate compiles nothing

An earlier draft of this ADR had a third annotation, `gate=expect-error`. **It was wrong twice**,
and dropping it is why the design got smaller instead of larger.

First, it was the wrong primitive. M4's deliberately-broken blocks do not fail to compile — per
[[F-010]] they *warn*: `-Wparentheses`, `-Wdangling-else`, `-Wimplicit-fallthrough`. Second, it
could not be enforced: a bare one-liner like `if (hp = 0)` is not a translation unit, so "it did
not compile" would have been satisfied trivially by every fragment. That is a skip wearing an
assertion's clothes — exactly the failure this ADR is supposed to prevent.

**The composition already had the answer.** A broken block is an `excerpt=` of a `.cpp` carrying
`// GATE: EXPECT-WARNING`, and *that marker* — checked by `compile-gate.sh`, on GCC, in CI —
asserts the compiler behaviour. The Markdown gate proves the listing is a faithful view; the
compile gate proves the file behaves as claimed. Neither duplicates the other.

So **`markdown-gate.sh` compiles nothing at all.** Its result is identical on every platform,
which is a property worth having in a repo where a local macOS run is not evidence (ADR-014).

For symmetry, `compile-gate.sh` gains `// GATE: EXPECT-ERROR`: a file that must *not* build.
Like its sibling it is an **assertion, not a mute** — a marked file that quietly starts compiling
**fails**, because the artifact has stopped demonstrating the thing it exists for, and nothing
about that looks wrong from the outside. Both directions are covered by self-test fixtures.

### 3. Matching is exact text, comments included — with one elision rule

Two rules, deliberately no more:

1. Trailing whitespace is trimmed per line.
2. A line whose stripped form begins `// ...` is an **elision**: it matches zero or more source
   lines.

Before either rule, the block is read **the way a Markdown renderer reads it**: a fence nested
inside a list item has the fence's own indentation stripped, because CommonMark strips it before
display. This is not a third matching rule; it is the gate agreeing with the renderer about what
the block's text *is*. Without it the gate diffs text no student ever sees, and the drift is
unfixable — de-indenting to satisfy the gate would break the list nesting and change the page.
`assess-lab.md:199` is exactly this shape, six spaces deep inside a Badge checklist item, and it
is one of the 23 blocks awaiting migration. Only the fence's own indent comes off; indentation
*inside* the listing is code structure and stays in the comparison. Both directions are fixtured
(`indented/`, `indented-drift/`) because a whitespace normalisation is precisely how a matcher
quietly stops matching.

**Comments are in scope.** Exempting them would exempt exactly what broke: a comment claiming a
program "compiles clean" is a claim about compiler behaviour, and F-009 was four of those.

This raises a real tension, since 6 of 9 listings differ from their file *only* in the header
comment — the page trimmed a three-line explanatory header to one line for readability, which is
a legitimate editorial choice and Linx's call, not the gate's. **The convention already resolves
it: use `excerpt=` and omit the header from the listing entirely.** The block stays provably
faithful to every line it does show, and the page keeps its readability. Verified against real M4
material (`learn.md:56`) before this ADR was accepted. Requiring pages to carry file headers they
do not want would have been the gate dictating prose, which is out of its remit.

Rule 2 exists because M4's own author reached for that idiom unprompted
(`apply-tutorial.md:279` — `// ... Stage 2 switch ends with its closing brace above ...`). It is
visible in the rendered page, so a reader can see that something was left out. It is deliberately
loose: a block that is mostly elision technically matches a great deal. We accept that; the
alternative is that tail fragments cannot be expressed at all, and an inexpressible convention
gets abandoned.

The same looseness applies to very short excerpts — `excerpt=` of a single line like `return 0;`
matches almost any file, and so proves almost nothing. **Accepted, not fixed.** A minimum-content
rule would have to pick a threshold with nothing principled behind it, and the failure mode it
guards against is an author who is trying to defeat the gate rather than one who slipped. The
convention's job is catching the listing that drifted, not the one that lied.

**Annotation markers live in the source file.** `apply-tutorial.md`'s staged builds tag added
lines `// NEW`. Rather than teach the matcher to ignore them, the stage `.cpp` **carries the
markers** — comments compile free. The listing and the file become genuinely identical instead of
approximately so, which is the entire point.

### 4. Staged builds get one gated file per stage

A staged build's stage 2 is not a slice of its final program; it is a shorter whole program. So
`apply-gatekeeper-stage1.cpp`, `-stage2.cpp`, … each compile standalone. This is bar #9 ("each
stage compiles and runs standalone") enforced rather than asserted.

### 5. Scope is `_contracts modules` — the same tree the `.cpp` gate covers

`assignments/` is **excluded, and the reason is ADR-008**: that tree is frozen provenance, "never
edited, moved, or shipped." Migrating its 46 blocks would require editing frozen files. The
exclusion is recorded with a full block inventory in [[F-013]] rather than left silent.
`.claude/skills/*` is builder-facing template text, also out.

### 6. The gate ships enforcing, and `main` goes red

Per ADR-014's precedent — *"red CI telling the truth beats green CI that is lying"* — the gate
merges enforcing, before M4's 23 blocks are migrated. **The gate is the failing test; the
migration is the fix**, in that order.

A sustained red decays into background noise, so the red is built to describe itself:

- it runs as its **own CI job** beside the `.cpp` gate, so that signal stays independently
  readable;
- the failure says **unmigrated, not defective**, and prints a per-file countdown;
- it links the tracked migration issue (**#30**), so the debt has an owner rather than living in
  a red check nobody holds.

> **Status (2026-07-31): the red is closed.** Issue #30 is paid in full across four PRs
> (#37, #44, and the batch that closed it) — **71 blocks, 71 matched, 0 unmigrated.** The
> markdown job is green and is now a regression test: a new un-annotated block fails it on
> arrival. The decision text above stands as the record of why the gate shipped enforcing
> and red; the state it describes no longer holds. See [[F-016-m4-fence-migration-partial]].

### 7. The convention is proved on fixtures, not on M4

Because M4 stays unmigrated this PR, the hard cases are exercised by
`.github/scripts/selftest/markdown/` — **ten fixtures**, one per behaviour: exact `source=`,
`excerpt=`, an elided `source=`, drift, an excerpt that was never in the source, a nonexistent
source, a source outside the gated trees, an un-annotated block, an invented `gate=` verb, a
block that is nothing but an elision, a fence nested in a list item, and that same nesting with a
drifted line. `run.sh` asserts each passes or fails as it should.

The last two were added after review, and they are the argument for this section rather than an
addendum to it: the nesting case was a real defect that the other eight could not see, found by
probing the gate instead of trusting it. Its fix is a whitespace normalisation, so it arrived
with a must-fail twin — a normalisation that is not paired with a drift fixture is a mute waiting
to be discovered.

This matters more here than for the compile gate. M4 ships unmigrated, so on day one the
convention gets **no exercise from real material at all** — these fixtures are the only thing
standing between "the convention works" and "the convention has never been run against its hard
cases." ADR-014's rule applies unchanged: **a gate that cannot fail is not a gate**, and it must
prove it in the same run.

### 8. The two gates are separate CI jobs

`g++ …` and `markdown blocks (provenance)` run as sibling jobs, not steps in one. The markdown
job is expected red; folding it into the compile job would drag a working compiler signal down
with it and train everyone to ignore both.

## Consequences

- **Bar #1 becomes enforceable as written.** "Every C++ block in every artifact" stops being
  aspirational for the `modules/` tree.
- **`main` goes red on merge**, on 23 unmigrated M4 blocks. Expected and tracked.
- **Three genuinely ungated listings are now visible**, including a complete program in
  `practice-exit-ticket.md:60` that has no `.cpp` twin at all, inside a module certified Ready.
  M4's Ready certification stays provisional until the migration lands.
- **Authoring gains a step**: a new listing needs a `.cpp` first. This is the intended direction —
  CLAUDE.md's "port before authoring, derived not duplicated" now has teeth, and the deeper reason
  is recorded above: a regenerated duplicate is not a copy.
- **The M5 cohort round (session A) inherits the convention** as M5 material is authored, rather
  than migrating later.
- **Open question, not decided here:** whether the regeneration finding becomes *taught* content.
  The course has an AI prompt-pattern ladder, and "the code is reproduced, the explanation is
  re-wished" is a demonstrable misconception-breaker with evidence from the repo's own history.
  That is a spine-owner call about course scope, not a gate decision. Recorded in [[F-013]]; no
  ADR number claimed for it.
