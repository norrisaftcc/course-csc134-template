# Assay journal

Read-only findings. The floor test — Audience, Scope, Format, Path — pointed at documents
this repo already had, as they were encountered during work.

**Never a draft.** An assay that produced a rewrite would be the floor test run backwards:
compression in service of the upholstery. Where a finding implies a fix, the fix is a separate
piece of work with its own gate.

Entries are appended, newest last. Each names the document, the date, and what was being done
when it was read — an assay run for its own sake and an assay run in passing are different
evidence, and the difference should be visible.

---

## 001 — `.github/instructions/copilot.instructions.md`

**2026-08-06 · read while renaming it**

```
Residue:
# Read the invariants before you act

- Read _lore/invariants/ first. It holds world state.
- Prefer the simplest thing that could work. Then iterate.

Evaporated: "in general", "keep it light, keep it elegant"; function — tone-setting, and a
  hedge that softens the one instruction in the file.
Operative sentence: 1 of 3, main clause, imperative. Correctly placed.
Finding: above the floor · erosion direction none · one gap flagged.

This is a finding, not a draft.
```

**The gap.** The file says to *read* the invariants. It does not say what an invariant is or
how to treat one. `CLAUDE.md` does: *"Never paraphrase an invariant; it is a snapshot, not
prose."* A reader who only has this file will read the CCL catalog text and reasonably
summarize it — which is the single thing the tree exists to prevent.

Scope is the soft base: *"some world state"* does not say which state, or when it binds.

**Worth noting the shape.** Three lines, lowercase, no ceremony, and it clears the floor —
because the operative instruction is first, in the main clause, in the imperative. Length was
never the variable.

---

## 002 — `.github/scripts/README.md`

**2026-08-06 · read before reducing it**

```
Residue:
# Run the gates, and annotate every fenced C++ block

- Run: compile-gate.sh, markdown-gate.sh, lpaa-gate.sh, editorial-gate.sh.
- Annotate each cpp block: source=<path> for a whole file, excerpt=<path> for part of one.
- An un-annotated cpp block fails. There is no skip.
- Mark deliberately-broken files: // GATE: EXPECT-WARNING or EXPECT-ERROR. Both are
  assertions — a marked file that stops misbehaving fails.
- Do not trust a local run on macOS for the compile gate. g++ there is Apple clang.
- Dials are environment variables. Defaults gate _contracts and modules.

Evaporated: the rationale — why the markdown gate compiles nothing, why identity and not
  similarity, why line numbers were rejected, the migration history; function — these are the
  arguments that stop a future reader from "fixing" the design back to the thing that failed.
Operative sentence: distributed. No single sentence changes the world; the annotation rule is
  the closest, and it arrives on line 70 of 218, in a bulleted fragment.
Finding: above the floor · erosion direction none · structural note below.

This is a finding, not a draft.
```

**The structural note, and it cuts against reducing this file.** The evaporated material is
the most valuable text in it. *"Three quarters of the C++ blocks in this course are deliberate
fragments"* is why the markdown gate compiles nothing; delete it and the next maintainer
rebuilds the extract-and-compile design that does not survive contact with the corpus.

**So the assay's finding is: this document is not padded, it is layered.** A reference layer
that clears the floor, wrapped in a rationale layer that exists to prevent regressions. The
cut that would shorten it is a cut that removes specification — damage, by the rule.

**What is genuinely missing:** the LPAA gate has no section. It appears in the run block and
nowhere else — no dials table, no explanation of its six checks, no pointer to ADR-018. Three
gates are documented and four are shipped.

**Prediction, recorded before the work so it can be wrong:** the reduction pass on this file
will return `Cut: nothing.` and add the missing LPAA section instead. The document is below
the floor by *absence*, not above it by padding — and a vague ask comes back longer.

---

## 003 — the reduction pass, and how entry 002 scored

**2026-08-06 · written after the work**

**The prediction held.** `.github/scripts/README.md`: `Cut: nothing.` — and **+52 lines**,
being the LPAA gate's missing section, its five dials, and a note on the shared entry point.
The document was below its floor by absence. It came back longer, as a below-floor document
does.

The real reduction was somewhere the assay had not looked:

```
Residue (the three .sh wrappers, before):
- Find the repo root.
- Find python3 or python.
- Exec the matching .py with all arguments.
- Print a fatal message and exit 2 if there is no Python.

Evaporated: nothing. All three files carried the four steps above, byte-identical
  except for one filename and one label.
Operative sentence: line 12 of 12, in each of three files.
Finding: above the floor · erosion direction none · duplication flagged, 3x.

This is a finding, not a draft.
```

**What moved and what did not.** The mechanism went into `_run-python-gate.sh` — one copy,
twelve lines. Every wrapper kept its **full header comment**, because those comments are the
gate's specification: what it asks, which dials it takes, why it is shaped that way. Cutting
them would have been the named failure — a cut that removes specification is damage.

`head -30` on a wrapper is how people actually read a gate. Collapsing three headers into one
shared block would have saved thirty more lines and cost every gate the ability to explain
itself where it is invoked.

**Net: −30 lines of mechanism, +52 lines of specification.** That is the shape of an honest
compression pass, and it is the opposite of what "reduce complexity" sounds like it should
produce. Complexity went down; the file count went up by one and the line count went up by
twenty-two.

**For the moonshot pile — the generalizable bit.** Two documents, two different failures, and
the floor test told them apart before the work started:

| | Symptom | The cut |
|---|---|---|
| `README.md` | below floor by **absence** | add — `Cut: nothing.` |
| the three wrappers | above floor, **duplicated** | extract the mechanism, keep the spec |

Neither is "too long." Length was never the variable, in either direction.
