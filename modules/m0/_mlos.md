# M0 — Module Learning Objectives (MLOs)

> **PARTLY INSTANTIATED.** These are objective *slots* — the shape an MLO takes
> and what it must feed.
>
> **`learn.md` now states finished objective sentences for MLO-0.1 and MLO-0.4.**
> Where that file and this one differ in phrasing, the Learn beat is the authored
> version. **MLO-0.2** (toolchain + one clean compile) belongs to Apply/Assess and
> is untouched — the reading names both toolchain paths and why they exist, but
> does not walk the setup. **MLO-0.3** (inputs / process / outputs) is an Assess
> objective, so the reading **supplies the vocabulary and rehearses it once in a
> predict moment**, without running the exercise. Do not read the four slots below
> as all covered.
>
> ---
>
> **⚠️ OPEN QUESTION FOR A HUMAN RULING — the M0 MLO numbering disagrees with
> itself, and the Learn beat could not resolve it.**
>
> This file lists **four** slots, `MLO-0.1`–`MLO-0.4`.
> `_storming/CSC-134-learning-objectives.md` lists **three**, `MLO 0.1`–`0.3`.
> They are not a subset of one another:
>
> - The **AI-collaboration objective** is `MLO-0.4` here and `MLO 0.3` there.
>   A citation of "MLO 0.3" is therefore ambiguous across the two files.
> - This file's `MLO-0.3` (inputs / process / outputs) **has no counterpart** in
>   the objectives doc.
> - This file's `MLO-0.1` **drops the systems clause** the spine and the
>   objectives doc both require — *"how software operates within a system of
>   people, processes, and technology"*. `learn.md` teaches the fuller version,
>   because the spine's big idea keeps it.
>
> `learn.md` cites **this file's** numbering, since it is the module's own. The
> reconciliation is a spine-owner call, not a module-builder one — it decides
> which document is authoritative for MLO numbering course-wide. **No ADR number
> has been taken for it.** Recorded in `_lore/findings/F-015-breadth-pass-recipe.md`
> under the M0 entry.

---

## MLO slots

Each slot below feeds a course-level learning objective (CLO). It's scoped to
what the spine's M0 section actually promises: environment and orientation,
not code fluency yet.

| # | MLO slot (skeleton) | Feeds CLO # | LPAA beat it's demonstrated in |
|---|---|---|---|
| MLO-0.1 | Student can state, in their own words, what a "program" is and identify one in an everyday system. | *(CLO ref — fill in deep-build pass)* | Learn, Practice |
| MLO-0.2 | Student can set up a working C++ toolchain (Codespaces **or** local VSCode + MinGW/MSYS2) and produce one clean compile. | *(CLO ref)* | Apply, Assess |
| MLO-0.3 | Student can describe, for a program they used that day, its inputs / process / outputs. | *(CLO ref)* | Assess |
| MLO-0.4 | Student can state the course's AI-collaboration stance in their own words (AI can write C++; you must be able to read it to verify and collaborate). | *(CLO ref)* | Learn |

*(Slots only — number, wording, and CLO mapping are finalized when the module
is authored, not in this skeleton pass.)*

---

## CCL-crosswalk touch

Per the spine's CCL crosswalk table (`_storming/CSC-134-course-spine.md`,
"## CCL crosswalk (compliance anchor)", lines 338–351), **M0 has no listed CCL
element.** The crosswalk's first tracked element (input/output operations)
begins at M3. M0 is orientation and toolchain setup — it precedes the CCL's
technical content entirely.

| CCL element | Where it lives | M0 touch |
|---|---|---|
| Input/output operations | M3 (core) | none — precedes |
| Iteration | M5 | none — precedes |
| Arithmetic operations | M3 | none — precedes |
| Arrays | M7 | none — precedes |
| Pointers | M7 | none — precedes |
| Filters | M4 → M5/M7 | none — precedes |
| Object-oriented | M7 + M8 | none — precedes |
| Design, code, test, debug | Whole spine; M8 summative | **orientation only** — M0 sets up the toolchain the whole-spine "design, code, test, debug" thread runs on, but does not itself teach any step of it. |

**Skeleton note:** this is a genuine "N/A, and here's why" slot, not an
oversight. It's recorded so a later pass doesn't mistake the blank cells above
for missing work.
