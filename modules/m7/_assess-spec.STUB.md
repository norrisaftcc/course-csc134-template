---
> **NOT YET AUTHORED — STUB**
> This is a skeleton of what the M7 Assess-beat artifact *will be*, not the
> lab itself. No student-facing prose below is final; no acceptance criteria
> here are complete. Deep-build (via the `lab-creator` skill) replaces this
> file's content with the real lab — do not hand this stub to students.
---

# M7 Assess Spec — STUB

**Spine anchor:** "the tiered `M7LAB1` — C: refactor parallel arrays into a
`Room` struct array; B: add a `Hero` struct to teach pass-by-value vs.
pass-by-reference; A: add a `Monster` struct with auto-resolve combat; then a
class refactor." — `_storming/CSC-134-course-spine.md`, M7 Assess line.
**Measured by** (learning-objectives doc): "the tiered `M7LAB1` (Room struct
→ Hero → Monster → class refactor)."

**MLOs this artifact must exercise:** MLO 7.1 (array declare/traverse), MLO
7.2 (struct definition + member access), MLO 7.3 (pointer/reference use, in
context), MLO 7.4 (class design — encapsulation + methods). See `_mlos.md`.

---

## Acceptance-criteria skeleton (type-signature style)

Written as input → expected-behavior contracts, not prose requirements. Fill
in concrete field names, member lists, and messages at deep-build time. The
four tiers below are **cumulative** — each includes everything the tier below
it requires (per the rubric-template's tier-ladder semantics), so the
signatures build on one another rather than restart.

```
[C tier]
refactor(parallel_arrays: {room_name[], room_desc[], room_has_monster[]})
  -> Room[]: array of struct Room { name, desc, has_monster, ... }

  PRECONDITIONS (what the C-tier program may assume):
    - the starting parallel-array version is given/ported in, not authored
      from scratch (the refactor is the point, not a blank-page struct design)
    - array size is fixed and known at compile time (no dynamic resize yet)

  POSTCONDITIONS (what "correct" means):
    - every parallel-array field becomes a member of one `Room` struct
    - a single `Room rooms[N]` array replaces all prior same-indexed arrays
    - traversal (e.g., printing every room) still produces identical output
      to the pre-refactor version — a refactor changes structure, not behavior
    - at least one function call demonstrates member access via dot notation

  FAILURE CASES (must be named, not just handled silently):
    - index used to access one array but a different array's matching field
      is forgotten (e.g., updating room_name[i] but not room_has_monster[i])
        -> classify per the four-word taxonomy: this is the exact class of
           LOGIC error the struct refactor is designed to make structurally
           impossible going forward — name it explicitly as "the bug this
           tier's struct design prevents," not just a mistake to avoid
    - off-by-one on array bounds during traversal
        -> RUNTIME (out-of-bounds access) or LOGIC (wrong loop bound but no
           crash), depending on what actually happens — TBD at deep-build
           which case(s) the C tier is required to demonstrate/discuss

[B tier — adds]
Hero: struct { name, hp, attack, ... }
takeDamage(h: Hero, amount: int) -> void            [pass-by-value version]
takeDamageRef(h: Hero&, amount: int) -> void         [pass-by-reference version]

  POSTCONDITIONS:
    - calling the pass-by-value version leaves the caller's Hero unchanged
      after the call returns (a copy was modified, not the original)
    - calling the pass-by-reference version DOES change the caller's Hero
    - the lab requires the student to demonstrate and explain this
      difference, not just implement one version

  FAILURE CASES:
    - student expects pass-by-value to persist a change (classic
      misconception) -> this is the exact SEMANTIC/LOGIC gap MLO 7.3 exists
      to close; the B tier's job is to make the student *observe* the
      surprise, not just be told about it in prose
    - forgetting `&` and silently getting pass-by-value when
      pass-by-reference was intended -> SYNTAX is fine (it compiles), but the
      resulting behavior gap is a LOGIC error the student must be able to
      diagnose, not just avoid by memorized incantation

[A tier — adds]
Monster: struct { name, hp, attack, ... }
resolveCombat(h: Hero&, m: Monster&) -> outcome: {winner, rounds, final_hp}

  POSTCONDITIONS:
    - combat auto-resolves (no per-round manual input) using hero/monster
      stats already established by MLO 7.4-adjacent struct design
    - both structs are modified by reference during resolution (hp decreases
      as combat proceeds) — ties directly back to the B-tier reference lesson
    - TBD at deep-build: exact combat formula, what "auto-resolve" bounds
      look like (a bounded loop, not an unbounded one — ties to M5's
      loop-safety MLOs as a prerequisite skill, not new content here)

  FAILURE CASES:
    - an unbounded resolution loop (e.g., neither combatant's hp ever drops
      below zero due to a comparison bug) -> RUNTIME (never terminates) or
      LOGIC (terminates on the wrong condition) depending on symptom; TBD
      which the A tier is expected to name

[A tier, class refactor — adds]
class Hero { private: fields; public: methods (e.g., takeDamage as a member) }

  POSTCONDITIONS:
    - at least one prior free function becomes a member method
    - fields are private; access happens only through methods (encapsulation,
      MLO 7.4's actual target, not just "a struct renamed class")
    - "a class is a struct that also has behavior" (spine's own framing) is
      demonstrable: point at the specific method(s) added as the "behavior"

  FAILURE CASES:
    - a class with all-public fields and no methods -> not a failure to
      compile, but a failure to meet the tier's actual intent (encapsulation
      absent); deep-build must state this as an explicit non-negotiable
      Completeness-column criterion, not an implicit expectation
```

**Known trap to resolve at deep-build, not left implicit:** the spine names
pointers as "introduced in context... not a standalone unit." The stub above
folds pointer/reference use into the B-tier `Hero&` signature rather than
giving pointers their own tier or their own acceptance-criteria block.
Deep-build must confirm this placement is where the *spec* wants the concept
taught. Or it must decide whether reference-passing (used above) and raw
pointer syntax (`Hero*`, `->`) are different enough that the lab needs to
show both explicitly, not just the reference form.

---

## Tier ladder (inherits `_contracts/rubric-template.md`)

Fixed left-column meaning per the template; right column is skeleton-only,
**not yet filled with this lab's real requirements.**

| Tier | Fixed meaning (course-wide) | M7 slot (TBD at deep-build) |
|---|---|---|
| **C — core** | The core competency, demonstrated end to end; a complete, passing submission. | [ ] Refactor a given parallel-array program into one array of `Room` structs; identical output, MLO 7.1/7.2 proven. |
| **B — depth** | One added concept from the module, or a harder case of the first. | [ ] TBD — candidate: add a `Hero` struct and demonstrate pass-by-value vs. pass-by-reference on it (MLO 7.3). |
| **A — synthesis** | Concepts combined, or the taught case pushed further. | [ ] TBD — candidate: add a `Monster` struct with auto-resolve combat (structs + references + bounded loop combined), then refactor `Hero` into a class (MLO 7.4). |
| **Badge — above & beyond** | Documentation/reflection beyond the code. | [ ] TBD — candidate: `prompts.md` + a short written comparison of the parallel-array version vs. the struct version, naming the specific bug class the refactor prevents. |

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

## Standing invariants (apply to every M7 C++ artifact, not just Assess)

- **Clean compile.** `g++ -std=c++17 -Wall -Wextra` — zero warnings, zero
  errors. Run it; never claim a clean compile that wasn't executed.
- **Single-file form, post-M6 shape.** From M6 on, the full form applies:
  prototypes at top, `main` in the middle, definitions at the bottom. M7's
  struct/class definitions slot into this same single-file convention — no
  multi-file projects, no header/implementation split.
- **Four-word error taxonomy.** Syntax / Static semantic / Runtime / Logic —
  no synonyms, no new categories. See the acceptance-criteria skeleton above
  for where each tier's likely failure modes land in this taxonomy (several
  are marked TBD — deep-build must pick, not leave ambiguous).
- **Mermaid flowcharts**, where a flowchart is called for (e.g., the
  auto-resolve combat loop in the A tier) — renders natively, verified before
  hand-off.
- **Make-gradient position: M5–M7 band, finish-the-80%.** The Assess
  artifact's *starting scaffold* is a mostly-built program with a defined gap
  to complete. This is independent of the Apply beat's own 80%-tutorial, but
  both beats sit at the same gradient position. Do not hand M7 an M3-style
  full type-in-100% scaffold, and do not hand it an M8-style spec-only brief.
- **No trick questions.** Failure cases above must be named and taught, not
  sprung on the student as a gotcha — including the classic pass-by-value
  misconception in the B tier, which is a *documented teaching moment*, not a
  trap.
- **Dungeon theme, instructor-facing only.** `Room`/`Hero`/`Monster` naming
  above matches the spine's own asset names and is fine to carry into
  student-facing material — the spine names it as the module's running
  example. But any build-org canon notes, contract provenance, or answer-key
  reasoning about *why* these names were chosen must stay out of what
  students see.
