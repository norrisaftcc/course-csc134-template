---
name: F-019-lpaa-content-gate
description: The third gate — checks that the repo's structural claims about itself are true. Ships green and reporting-only, which makes its ten fixtures the only evidence it works.
---

# F-019 — The LPAA content gate

**Date:** 2026-07-31 · **Status:** Recorded · **Issue:** #54 · **Branch:** `phase0/lpaa-content-gate`

Two gates existed. Neither could see the most common defect in this repo.

| Gate | Question |
|---|---|
| `compile-gate.sh` (ADR-014) | Does the C++ build? |
| `markdown-gate.sh` (ADR-015) | Is this listing the real file? |
| **`lpaa-gate.sh`** (this) | **Is what the repo SAYS about itself true?** |

## Why: six false claims in one week, none mechanically visible

Every one was checkable. None was caught by a gate, because neither existing gate knows what an
LPAA beat is:

- `m4/_assess-spec.STUB.md` — "NOT YET AUTHORED" inside a module certified `Ready`
- `m5/_assess-spec.STUB.md` — the same
- `m7/learn.md` — claimed MLO 7.4 while three sibling files disclaimed it
- `m8/_overview.md` — "structure-only skeleton pass" after the Learn beat landed
- `ADR-015 §6` and `compile-gate.yml` — "EXPECTED RED until M4's 23 blocks are migrated," after
  they were migrated
- `breadth-pass-ledger.md` — its own status line, M5's row, and two done-but-unticked boxes

**The pattern, stated once: finishing a piece of work is what makes the surrounding status text
false.** Nobody writes a stale claim on purpose. They write a true one, and then make it false
somewhere else.

## The checks

Five enforcing, one reporting-only.

| Check | Asserts | Born from |
|---|---|---|
| `status-files` | `MODULES.md`'s status implies a file set; assert it both ways | the six above |
| `frontmatter` | `module:` and `lpaa_beat:` agree with the path | copy-paste drift |
| `stale-stub` | no "NOT YET AUTHORED" inside a `Built`/`Ready` module | F-014 §5, shipped twice |
| `key-leak` | a student-facing beat never links its own answer key | — |
| `boundary` | instructor content sits behind a declared boundary | F-018 |
| `open-questions` | **reports** unticked `- [ ]` items for review | M7's item that outlived its ruling by six days |

Two design notes worth keeping:

**`status-files` fails in both directions, and the reverse case is the interesting one.** A
`First pass` module holding an `assess-lab.md` is not a filing mistake — it is a *status* that went
stale when somebody authored past it. The message says so: *"the file exists, so the STATUS is what
is stale."* A gate that only checked for missing files would have missed every one of the six.

**`open-questions` never fails.** Whether a ruling in `_lore/decisions/` closes an item is a
judgement, and a gate that guesses would either nag or lie. It refuses to let the list stay
invisible and stops there — **22 unticked items** across six modules on the first run, against 16
decision files.

**The vocabulary is read from `MODULES.md`, not hard-coded.** A gate keeping its own copy of the
status list would become the next stale claim in this very finding.

## The gate found a bug in itself on its first real run

The `boundary` check flagged all three files that *correctly* declare a boundary — including the one
`assess-lab.md` that established the convention.

Cause: the boundary phrase lives *inside* the heading `## Instructor notes (not part of the student
handout)`, and that heading also matches the instructor-marker pattern. Comparing the marker's start
against the *phrase* offset made every boundary heading start before itself.

Fixed by comparing against the start of the boundary's **line**. **The fix arrived with a must-pass
twin** — `boundary-ok` — because a check that was just repaired and is not pinned by a fixture is a
mute waiting to be rediscovered. That rule comes from ADR-015 §7, which learned it the same way.

## Ships GREEN and reporting-only, and that combination is the risk

Five enforcing checks, **zero violations** against the real tree on day one.

ADR-015 §6 shipped the markdown gate *enforcing and red*, and that was right — but it was right
because the debt was already measured at 23 blocks. Here the debt was unmeasured until the first
run. **A gate that goes red before anyone knows how red is a gate people learn to ignore.**

As it happens the first run was clean, so `STRICT=1` is now a one-line change (`vars.LPAA_GATE_STRICT`)
and a judgement about how much churn a red should cause mid-authoring. Left off until somebody
decides that on purpose rather than inheriting it.

**The green is also the problem.** The compile gate has a must-warn fixture; the markdown gate had 23
real violations to chew through. This gate found nothing, so real material proves nothing about it
either way — **the ten fixtures are the only evidence a green run means anything.** Each is a tiny
fake module tree with its own `MODULES.md`, so a fixture can claim a status the real repo never would.

## What it does not do

**It cannot tell whether content is any good.** That needs a cohort round (#21, F-017) and cannot be
automated. This gate checks a much cheaper and much more boring property: that the repo's claims
about itself are true.

Worth saying plainly, because the two are easy to conflate. F-017's round found four real content
gaps that no gate will ever catch — an untaught keyword, an unpublished range, syntax arriving cold.
F-018's defect *is* gateable and shipped anyway for months. **Different failures, different
instruments; neither substitutes for the other.**

## Immediately closed by building it

`compile-gate.yml`'s own header said **"TWO JOBS, ON PURPOSE"** and repeated the migrated-away
"EXPECTED RED" claim. Adding the third job made the first false and re-exposed the second — fixed in
the same commit. **The sixth stale claim was found by the work of building the thing that finds
stale claims**, which is either reassuring or funny depending on the hour.

---

## First harvest: 8 of the 22 reported items closed (2026-08-01)

The `open-questions` reporter's first real use. **22 → 14**, and the triage is worth recording
because the counts were not what the raw list looked like.

### Twelve of the 22 were the same two items, repeated

Six modules each carried *"Per-MLO behavioral statement"* and *"Mapping each MLO to the artifact"* —
boilerplate inherited from the skeleton template. So the list looked like 22 distinct questions and
was really **ten module-specific questions plus one template repeated twelve times.** A reporter that
prints line-by-line hides that; whoever reads it next should group before estimating.

### Five carried a false claim inside the item

Every "Mapping" item said *"Learn/Practice/Apply are not yet built."* **Learn was built in all five
modules**, and M4 and M5 had all four beats and were cohort-tested. The items were written true and
the work of building the course made them false — the same pattern this gate exists to catch, sitting
*inside the checklist items the gate surfaced.* All five corrected.

### What actually closed, and what it cost

Eight items, all closed from evidence already in the repo — no new decisions:

- **M4 (4/4).** Behavioral statements and the full MLO→artifact table, both writable because M4 is
  `Ready`. MLO 4.3's *"recover a flowchart from existing code"* half resolved to **Badge item 1**,
  which has done exactly that since the lab shipped. The 4.2/4.1 tier boundary resolved by reading
  the tiers: **4.1 first required at C, 4.2 at B** — taught in Learn, typed in Apply Stage 4,
  required one tier above baseline, which is the no-trick-questions rule satisfied.
- **M5 (3/4).** Same two, plus MLO 5.3's trace-table question — **all three homes**, ungraded
  scratchpads in Practice and Apply and a graded four-pass minimum at Badge, with F-017's watch-list
  Q6 confirming the design holds.
- **M6 (1/4).** The reference-vs-pointer boundary, **closed by grep**: `m6/learn.md` contains the
  word "pointer" zero times, so the conflation it guards against cannot happen from that reading.

**Nothing was closed by asserting it.** Each answer quotes the artifact that settles it.

### The honest caveat found while closing M6's

The item framed the boundary as a handoff to M7. **M7's Learn beat does not say "pointer" either** —
it walks arrays → parallel arrays → structs → by-reference and names classes without teaching them.
So the boundary holds on M6's side and the pickup on M7's side is not built. Recorded in M6's file
rather than quietly claiming the handoff works.

### And closing them made two more banners stale

`m4/_mlos.md` and `m5/_mlos.md` opened with *"skeleton slots only — not authored objectives"* — false
the moment the slots were authored. Both now read **AUTHORED**, with the slot record kept as the
derivation and an explicit precedence rule: **where the record and the authored beats differ, the
beats win.**

That is the seventh instance of the pattern, and it arrived *while fixing the sixth*. The reporter
cannot see it — a status banner is not a `- [ ]`. **Worth considering as a future enforcing check:
a file whose pending section is empty should not describe itself as pending.**
