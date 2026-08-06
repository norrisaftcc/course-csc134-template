# Worked — one deliverable, both routes

The deliverable is real and shipped: the `lore-numbers` check in
`.github/scripts/lpaa-gate.py`. It is small enough to hold in your head and it has the one
property that makes it worth teaching — **the two routes produce different programs, and
one of them is wrong.**

## The ask

> a duplicate-lore-number check in `lpaa-gate.sh` would have caught all three at creation

That is the whole ask. Read it again before continuing; everything below was latent in it.

---

## Route A — pseudocode first

Write the steps down. This is the route that feels like progress, because it produces
something runnable fast.

```
for each file in _lore/decisions/ and _lore/findings/:
    parse the number out of the filename        # ADR-016-slug.md -> ADR-016
    group the files by number
for each number with more than one file:
    report a violation
exit nonzero if any violations
```

**Predict first.** Before reading on: run that against this repo. What happens?

It reports **three violations** — `ADR-016`, `F-009`, `F-014` — and fails the build. On
`main`. On every branch. Forever, or until someone renames six files.

The pseudocode is not wrong. Every line does what it says. It is a **Logic** error in the
course's own four words: it did what you said, not what you meant. And it is the kind that
compiles, runs, and looks finished.

Run the bases against Route A's output:

| Base | Route A |
|---|---|
| Audience | ✅ inferable — builders, in CI |
| Scope | ❌ **"all duplicates" — the boundary was never asked about** |
| Format | ✅ a gate check, like its five siblings |
| Path | ✅ `.github/scripts/lpaa-gate.py` |

**Stranded on Scope.** Pseudocode gave the algorithm perfectly and never once asked
*which duplicates count*, because pseudocode has no question in it. It is a description of
a mechanism, and a mechanism cannot notice that the world already contains three
counterexamples.

---

## Route B — interview first

Same ask. Ask the customer instead.

> **Builder:** Who runs this, what counts as a duplicate, and where does it go?
>
> **Customer:** Builders, in CI, with the other gates. A duplicate is one number naming two
> files.
>
> **Builder:** There are three of those already. Do they fail?
>
> **Customer:** No — those stand. Cite them by slug from now on. It is new ones I want
> caught.

Four exchanges. The third question is the one that matters, and notice what prompted it:
**not the algorithm — looking at the repo.**

Run the bases against Route B:

| Base | Route B |
|---|---|
| Audience | ✅ builders, in CI |
| Scope | ✅ **new collisions fail; three named ones do not** |
| Format | ✅ a gate check |
| Path | ⚠️ "with the other gates" — a directory, not a file |

**Stranded on Path, and on the mechanism.** Route B knows exactly what the check must
*mean* and has not said how to parse a filename, where to walk, or what the message says.
Hand this to a builder and you get a check; hand it to a compiler and you get nothing.

---

## The merge

Neither route reached the floor alone. Route A had the mechanism and the wrong boundary.
Route B had the boundary and no mechanism. Put together:

```
# Fail any lore number that names two files

- Walk _lore/decisions/ and _lore/findings/.
- Parse the number from each filename: ADR-NNN-slug.md, F-NNN-slug.md.
- Group by number. Report any number naming two or more files.
- Exempt exactly three: ADR-016, F-009, F-014. They stand as history.
- The exemption list must never grow. Say so where a reader will find it.
- Path: .github/scripts/lpaa-gate.py, as check 7 in the existing CHECKS list.
```

Cut: "would have caught all three at creation" was the *reason*, not a requirement —
dropped from the spec, kept in the ADR. The reason belongs where reasons are kept.

Assume: it follows the existing check signature `(index, found)` and appends `Finding`
objects like its five siblings, rather than printing directly.

**Freeze this and build it, or keep working the ask?**

---

## What actually happened

The gate opened. A human typed the ruling — *"Right now disambiguate by slug"* — and the
check was built exactly as frozen, with two fixtures: one collision that must fail, one
must-pass twin proving the three exempt numbers stay quiet.

**The honest part, and the reason this example was chosen.** No agent could have produced
Route B's third exchange from RED clearance. *Do the existing three fail?* is a question;
*they stand as history* is a **decision**, and deciding it is sitting in the customer seat.
An agent that answered its own question there would have invented the requirement it then
satisfied — and it would have looked exactly like good work.

That is what the clearance rule is for, and it is why the gate has a human on it.

## What each route drops — the seam, in one table

| | Pseudocode gives you | The interview gives you |
|---|---|---|
| **Order** | ✅ every step, in sequence | ❌ "and then validate it somehow" |
| **Edge cases** | ✅ forces the wrong-input branch | ❌ rarely surfaces until build |
| **Audience** | ❌ never asks | ✅ first question |
| **Scope** | ❌ describes a mechanism, not a boundary | ✅ the boundary *is* the conversation |
| **Existing world** | ❌ blind to what already stands | ✅ "there are three of those already" |

**Teach both. Grade the spec.**
