# M0 — Assess-Beat Spec STUB

> ## ⚠️ NOT YET AUTHORED — STUB
> This is an acceptance-criteria **skeleton** for the M0 Assess artifact, not
> the lab itself. No student-facing prose lives here yet. The deep-build pass
> (via the `lab-creator` skill) writes the real lab against this stub.

---

## What the assessed artifact WILL be

Per the spine: **a short reflection** (a program the student used that day:
its inputs, its process, its outputs) **+ proof the toolchain runs** (a
compiling, running `hello world`).

Two parts, both required for a C-tier pass:

1. A short written reflection (prose, not code).
2. One `.cpp` file that compiles clean and runs, proving the student's
   toolchain (Codespaces or local) actually works.

---

## Acceptance criteria (type-signature style — skeleton)

```
reflection(program_used: string) -> {
    inputs: string[],       // what went in
    process: string,        // what happened to it
    outputs: string[]       // what came out
}
  precondition:  program_used names a real, specific program the student
                 actually used (not a hypothetical).
  postcondition: all three fields present and specific enough that a reader
                 who has never used that program could follow the trace.
  failure cases:
    - missing any of the three fields                    -> INCOMPLETE
    - inputs/outputs described so vaguely they could describe
      any program ("stuff goes in, stuff comes out")      -> INCOMPLETE
    - program_used is invented/hypothetical, not a program
      the student actually used                           -> INCOMPLETE

toolchain_proof(file: "hello_world.cpp") -> {
    compiles: bool,   // g++ -std=c++17 -Wall -Wextra, zero warnings/errors
    runs: bool,       // executes without crashing
    output: string    // what printed
}
  precondition:  file exists, is single-file, is the student's own submission.
  postcondition: compiles == true AND runs == true.
  failure cases:
    - does not compile                                    -> syntax error
      (four-word taxonomy; this is the ONLY failure class expected at M0 —
      static-semantic / runtime / logic errors are out of scope for a
      hello-world-scale program and should not appear in grading language)
    - compiles with warnings under -Wall -Wextra            -> FORMAT deduction,
      not a pass/fail gate (see Format column below)
    - compiles and runs, but is not single-file              -> SUBMISSION issue
```

*(This is a skeleton shape for the deep-build author to fill in with real
student-facing wording — not the final rubric prose.)*

---

## Tier ladder — inherits `_contracts/rubric-template.md`

**Skeleton only.** Right-column language below is a placeholder for the
deep-build pass, not the finished lab text. Each tier includes the tier below.

| Tier | Fixed meaning (course-wide, from the contract) | M0 slot (fill in deep-build pass) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; complete and passing. | *(TODO: reflection + one clean-compiling hello world)* |
| **B — depth** | Added depth: a second concept, or a harder case of the first. | *(TODO — candidate: reflection covers a program with a less obvious process step, e.g. a search engine or a game, not just a calculator)* |
| **A — synthesis** | Synthesis/extension: concepts combined, or pushed past the taught case. | *(TODO — candidate: student explains where "prompt and hope" would fail for their example program, tying to the AI-collaboration stance)* |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | *(TODO — candidate: a short `prompts.md` if AI was used to help debug the toolchain setup)* |

---

## Four-column scoring table — inherits `_contracts/rubric-template.md`

**Skeleton only** — columns, order, and weights are fixed by the contract and
copied verbatim. The "what we're looking for" language is a placeholder.

| Criterion | Points | M0 slot (fill in deep-build pass) |
|---|---|---|
| **Correctness** | 8 | *(TODO — reflection accurately describes the chosen program's real inputs/process/outputs; hello world produces correct output)* |
| **Completeness** | 6 | *(TODO — all three reflection fields present; toolchain proof included)* |
| **Format** | 3 | *(TODO — readable reflection; hello world compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings)* |
| **Submission** | 3 | *(TODO — correct file names/folder/repo, committed and pushed per the student flow: commit + push, no branches, ADR-004; `prompts.md` if AI used)* |
| **Total** | **20** | |

> No hidden criteria — what is on this page (once authored) will be the whole
> rubric. This stub does not promise anything beyond its own placeholders.

---

## Standing invariants (this module)

- **Clean compile.** The hello-world proof must build under
  `g++ -std=c++17 -Wall -Wextra` with zero warnings and zero errors.
- **Single-file form.** M0 is pre-M6 — no functions, no prototypes; everything
  the student writes lives in `main`.
- **Four-word error taxonomy.** Only **syntax / static semantic / runtime /
  logic** — at M0 scale, expect only *syntax* to realistically appear.
- **Mermaid.** Not required for M0's Assess artifact (no flowchart-worthy
  logic yet) — flag as N/A rather than omit silently if the deep-build author
  finds otherwise.
- **Make-gradient position.** Pre-gradient (see `_overview.md`) — Apply beat
  is instructor-led setup, not a type-in/finish-it/spec-only code exercise.

---

## Contract touch

Inherits `_contracts/rubric-template.md` (four columns, four tiers). Does not
touch `m4_gatekeeper.cpp` or `m5_menu.cpp`.
