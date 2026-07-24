---
> **NOT YET AUTHORED — STUB**
> This is a skeleton of what the M5 Assess-beat artifact *will be*, not the lab
> itself. No student-facing prose below is final; no acceptance criteria here
> are complete. Deep-build (via the `lab-creator` skill) replaces this file's
> content with the real lab — do not hand this stub to students.
---

# M5 Assess Spec — STUB

**Spine anchor:** "loop fundamentals (`while` / `for` / array-search) +
Project 2, the menu-driven game (tiered C/B/A)" — `_storming/CSC-134-course-
spine.md`, M5 Assess line. **Measured by** (learning-objectives doc):
"loop fundamentals (`while`/`for`/array-search) + Project 2 (menu-driven
game)."

**MLOs this artifact must exercise:** MLO 5.1 (`while`/`do-while`/`for`),
MLO 5.2 (input validation, `cin` fail-state, infinite-loop prevention),
MLO 5.3 (trace-table prediction), MLO 5.4 (loop + selection combined to
filter/search a sequence). See `_mlos.md`.

**Contract this artifact grows from:** `_contracts/m5_menu.cpp` — the
canonical M5 menu program (M4 gatekeeper wrapped in a validated `do/while`
menu loop). The Assess artifact is the *student-built* sibling of this
frozen reference. Do not fork the contract file itself.

---

## Two components (per the spine's own Assess line — do not merge into one artifact)

The spine names two distinct pieces. Deep-build decides whether these are two
files, or a two-part single lab — this stub does not make that call.

1. **Loop fundamentals exercise(s):** `while`, `for`, and array-search,
   likely smaller/earlier and closer to the exit-ticket end of the
   difficulty range.
2. **Project 2 — the menu-driven game:** the larger, tiered (C/B/A)
   artifact; the one the acceptance-criteria skeleton below is written
   against, since it's the artifact the rubric ladder actually measures.

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete values, menu text, and messages at deep-build time.

```
program() -> runs until the player chooses "leave" -> no return value (exit code 0)

  PRECONDITIONS (what the C-tier program may assume):
    - the menu has a fixed, known set of numbered choices (spine anchor:
      the `_contracts/m5_menu.cpp` three-choice shape — approach the gate /
      hear the rules / leave)
    - the player interacts via cin, one line at a time

  POSTCONDITIONS (what "correct" means):
    - the menu redisplays after every choice except "leave" (do/while, not
      a one-shot if)
    - every numeric menu read is guarded: non-numeric input and
      out-of-range numeric input both re-prompt without crashing or
      silently misbehaving
    - the program terminates cleanly only when the player chooses "leave"
      (no other path exits early)

  FAILURE CASES (must be named, not just handled silently):
    - letters typed where cin expects a menu number
        -> unguarded: RUNTIME failure class (cin enters a fail state; the
           stream is unusable until cleared) — this is the textbook case
           MLO 5.2 targets
        -> guarded (the taught pattern): cin.clear() +
           cin.ignore(numeric_limits<streamsize>::max(), '\n') converts
           this into a handled re-prompt, not a crash
    - a menu number that is numeric but out of the valid range (e.g., "7"
      when choices are 1-3)
        -> this is a LOGIC-adjacent validation gap if unguarded (the
           program "does what you typed," not what was meant, i.e. it
           may fall through a switch/if chain with no matching case) —
           C tier must guard the range, not just the type
    - a loop that never reaches its exit condition (e.g., the update
      step is missing, or the condition can never become false)
        -> RUNTIME failure class: the program runs, then hangs — never
           reaches the "print and finish" step. This is the infinite-loop
           case MLO 5.2 names explicitly; the C tier must be demonstrably
           free of it (a tester can always reach "leave")
    - an off-by-one in a counted (`for`) loop (e.g., a 10-level stat
      table that prints 9 or 11 rows)
        -> LOGIC failure class: no crash, wrong output. This is the exact
           case the Practice-beat exit ticket rehearses ("spot the
           off-by-one") — the Assess artifact is where a student must
           avoid it unprompted, not just spot it in a given snippet
    - an array-search that never finds a value present in the array (or
      claims to find one that isn't there)
        -> LOGIC failure class if the loop bounds or comparison are wrong;
           C tier must state what "not found" output looks like as a
           real, checked case — not an unstated assumption
```

**Known trap to resolve at deep-build, not left implicit:** the `cin`
fail-state recovery idiom (`cin.clear()` + `cin.ignore(...)`) is easy to
copy without understanding *why* both calls are needed. Deep-build should
decide whether the trace-table / predict-then-run verification step (MLO
5.3) is used here to force the "why," or whether that's left entirely to
the Practice beat.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template; right column is skeleton-only,
**not yet filled with this lab's real requirements.**

| Tier | Fixed meaning (course-wide) | M5 slot (TBD at deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] Candidate: a working menu loop (do/while) with one fully-validated numeric read (type + range), proving MLO 5.1/5.2 end to end. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: nested loops, or a second validated input, or the array-search half of the "loop fundamentals" component folded in. |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: the full menu-driven game (Project 2) with multiple menu paths, each independently validated, echoing the M4→M5 seam (`_contracts/m5_menu.cpp`) at full scale. |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: a hand-completed trace table (MLO 5.3) for one non-trivial loop in the submission, plus `prompts.md` if AI was used. |

## Four-column scoring table (inherits `_contracts/rubric-template.md`)

Columns, order, and point weights are fixed course-wide; "what we're looking
for" cells are **unfilled placeholders**, not this lab's real rubric text.

| Criterion | Points | What we're looking for (TBD — deep-build fills per this lab) |
|---|---|---|
| **Correctness** | 8 | [ ] |
| **Completeness** | 6 | [ ] |
| **Format** | 3 | [ ] — must include: compiles clean under `g++ -std=c++17 -Wall -Wextra`, zero warnings. |
| **Submission** | 3 | [ ] — correct file/folder/repo, committed and pushed (no branches — ADR-004), `prompts.md` if AI was used. |
| **Total** | **20** | |

"No hidden criteria" applies once this stub is instantiated: what's on the
lab page will be the whole rubric.

---

## Standing invariants (apply to every M5 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors. Run it; never claim a clean compile that wasn't executed.
- **Single-file form, pre-M6 shape.** Everything lives in `main` — no
  functions, no prototypes. Functions are not taught until M6; do not use
  them in M5 code (this includes the menu-driven game — it stays one
  `main`, however long, until M6's refactor lab revisits it).
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories. Use these exact words when naming the
  failure cases above (infinite loop and unguarded `cin` fail-state are
  Runtime; off-by-one and bad search bounds are Logic).
- **Mermaid flowcharts**, where a flowchart is called for — renders
  natively, verified before hand-off.
- **Make-gradient position: top of the M5–M7 band, finish-the-80%** — but
  only for the menu/validation half of the module (see `_overview.md`). The
  Level Up Stats warm-up is still type-in, carried over from the M2–M4
  shape. The Assess artifact's starting scaffold — how much of the menu
  skeleton is pre-built vs. student-authored — is a deep-build decision. It
  must stay consistent with whatever the Apply beat hands out: do not let
  Assess start from a blanker page than Apply already earned.
- **No trick questions.** Failure cases above must be named and taught, not
  sprung on the student as a gotcha. This is explicitly true of the
  `cin` fail-state and infinite-loop cases — both are *planned, celebrated*
  first encounters per the course's debugging philosophy, not ambushes.
- **Staged builds.** If Project 2 (the menu-driven game) is delivered as a
  multi-stage build (menu skeleton -> one validated action -> full game),
  each stage must compile and run standalone before the next stage is
  added, per the course-wide staged-build convention.
