# `_outputs/` — build output. Not ground truth.

Everything under this directory is **generated**. It is committed so formatting changes are
reviewable in a diff, and for no other reason.

## The rule

**Never hand-edit a file in here.** Edit the Markdown source and re-emit. A hand-edit is lost
the next time the page is composed, and — worse — it survives just long enough to be believed.

The single source of truth is always the module Markdown under `modules/`. If a Canvas page
and its source disagree, the source is right and the page is stale.

There is exactly one sanctioned edit to a composed page, and it happens in Canvas, not here:
**wiring placeholder links in the RCE.** That is why placeholders are emitted loud
(`[LINK PENDING]`). Canvas relinks only references inserted through the RCE, so a hand-written
`href` silently survives a term rollover still pointing at last term's course.

## Layout

```
_outputs/
  canvas-html/
    m4/          one file per Canvas page or assignment description
    ...
```

Each emitted file opens with two comments recording what made it:

```html
<!-- compositor: M4 · assess -->
<!-- SOURCE: modules/m4/assess-lab.md — build output, do not hand-edit. -->
```

The first is the compositor's dial. The second is the provenance line — if you are looking at
a page and wondering what to change, that line is the answer.

## Emitting and checking

Composed by the `csc134-canvas-compositor` skill. Verify with the gate before committing:

```bash
python3 .claude/skills/csc134-canvas-compositor/gate.py _outputs/canvas-html/m4
```

The gate enforces the Canvas sanitizer rules mechanically — forbidden tags, unescaped `<` and
`>` inside `<pre>`, tables over two columns or missing their scroll wrapper, character-diagram
column budgets, and placeholder-marker accounting. It is the same gate the imported reference
fragments were validated against.

## Why this is separate from `modules/`

Composed pages churn — every formatting tweak rewrites them wholesale. Keeping them out of the
module tree means a `git diff` on `modules/` is always a content change, never a re-render, and
nobody has to guess which of two files is authoritative.
