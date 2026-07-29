---
title: "Module 5 Exit Ticket — Answer Key (INSTRUCTOR-FACING)"
module: M5
lpaa_beat: Practice
items: 7
audience: instructor
gate: completion
---

# Module 5 Exit Ticket — Answer Key

**Instructor-facing. Do not hand to students.** Every snippet below was compiled
and run under `g++ -std=c++17 -Wall -Wextra` and produced exactly the output
claimed. Source files live in `modules/m5/code/`.

**Verification run (2026-07-25):** all eighteen M5 sources compiled with **zero
warnings, zero errors** (Apple clang 21.0.0). Outputs were captured by feeding
the stated inputs on stdin. Two programs are *supposed* to hang and were
confirmed hanging under a hard timeout. See the "Compile & run log" at the
bottom.

**Distractor source:** no cohort distractor bank exists for M5 yet. Distractors
are derived from the misconception catalog and the classic loop traps named in
the reading (off-by-one / fence-post, the `cin` fail-state, `while`-checks-first,
`do-while` runs-at-least-once, and the "one call is enough" recovery error). New
predicted misconceptions are recorded here so a bank can grow — harvest
wrong-answer rates after the first run and append.

---

## Item 1 — Warm-up: predict the output
- **Type:** Predict-the-output · **MLO:** 5.1 (`for`) · **Source:** `code/practice-item1-levelup.cpp`
- **Key: B** — three lines, `Level 1: ready` through `Level 3: ready`
- **Why:** `for (int level = 1; level <= 3; level++)` starts at 1 and uses `<=`,
  so 3 *is* included. Start 1, include 3 → three passes.
- **Per-distractor feedback:**
  - **A** — One line would be right if there were no loop at all, or if the
    condition were false after the first pass. `level <= 3` stays true through 3.
  - **C** — Four lines starting at `Level 0` assumes the counter starts at 0.
    This one starts at `1`. The start value is written in the loop header — read
    it, don't assume it. (Compare the reading's *Check Yourself* #1, which
    deliberately *does* start at 0.)
  - **D** — It compiles fine. Every line is legal C++.

## Item 2 — Trace a `while` loop
- **Type:** Trace-the-loop · **MLO:** 5.1 + 5.3 · **Source:** `code/practice-item2-hp.cpp`
- **Key: B** — 3 lines
- **Filled trace table:**

  | Pass | `hp` before the check | `hp > 0`? | `HP:` line prints? | `hp` after `hp = hp - 2` |
  |------|-----------------------|-----------|--------------------|--------------------------|
  | 1    | 5                     | true      | yes — `HP: 5`      | 3                        |
  | 2    | 3                     | true      | yes — `HP: 3`      | 1                        |
  | 3    | 1                     | true      | yes — `HP: 1`      | −1                       |
  | 4    | −1                    | **false** | no — loop exits    | (body never runs)        |

- **Why:** `hp` steps 5 → 3 → 1 → −1. It never lands exactly on 0; it *skips
  past* it. The fourth check is what ends the loop, and the body does not run on
  that pass. Three `HP:` lines, then `You collapse.`
- **Per-distractor feedback:**
  - **A (2)** — Likely counted only the passes where `hp` stayed positive
    *after* subtracting. The print happens **before** the subtraction, so the
    pass that drives `hp` to −1 still prints.
  - **C (5)** — This is `hp`'s starting value, not the number of passes. The loop
    steps by 2, not by 1, so it takes about half as many passes.
  - **D (never stops)** — There *is* an update (`hp = hp - 2`) and it moves
    toward the exit, so the loop terminates. Worth contrasting with Item 5, where
    the update genuinely never happens. **If a student picks D here and C on Item
    5, they have the concept and mixed up the instances — that is a much smaller
    gap than it looks.**

## Item 3 — Trace the menu loop (loops wrap decisions)
- **Type:** Trace-the-loop · **MLO:** 5.1 (`do-while`) + 5.4 · **Source:** `code/practice-item3-menu.cpp`, inputs `1`, `2`, `3`
- **Key: C** — 3 banners
- **Filled trace table:**

  | Pass | You type | Action that runs                       | `choice != 3`, so loop again? |
  |------|----------|----------------------------------------|-------------------------------|
  | 1    | 1        | `The gatekeeper looks you over.`       | yes (1 ≠ 3)                   |
  | 2    | 2        | `"Strength 70 or more and you pass."`  | yes (2 ≠ 3)                   |
  | 3    | 3        | `You step back from the door.`         | **no** (3 = 3) → exit          |

- **Why:** The banner is the first thing inside the loop body, so it prints once
  per pass. Three inputs → three passes → three banners. The pass where the
  player types `3` still shows the banner and still runs its action; the
  condition is only checked at the **bottom**, after the body.
- **Per-distractor feedback:**
  - **A (1)** — This treats the banner as if it were *outside* the loop, printed
    once before the menu starts. It is inside the body.
  - **B (2)** — This assumes the `3` pass exits *before* printing. A `do-while`
    checks its condition at the bottom — the whole body, banner included, has
    already run by then.
  - **D (4)** — This adds a fourth pass after `choice` becomes 3. Once
    `choice != 3` is false the loop is done; it does not display the menu one
    last time. (Students who picked D may be picturing a `while` loop that
    re-checks *and re-displays*.)

## Item 4 — Spot the off-by-one
- **Type:** Classify-the-error · **MLO:** 5.3 · **Error class: Logic** · **Source:** `code/practice-item4-offbyone.cpp`
- **Key: D — Logic** ("did what you said, not what you meant")
- **The one flaw:** `level < 10` should be `level <= 10`. The loop stops after
  printing `Level 9`. Confirmed by running it: exactly nine lines, `Level 1`
  through `Level 9`.
- **Why Logic:** It compiles with **no warning at all** and runs to completion
  with no crash. The program did exactly what the code said — the code just said
  the wrong thing. That is the definition of a Logic error.
- **Per-distractor feedback:**
  - **A (Syntax)** — Nothing broke the grammar; it compiles. Syntax errors stop
    the compile with a message like "expected `;`."
  - **B (Static semantic)** — The meaning is not impossible. `level < 10` is a
    perfectly legal, buildable comparison; it is just not the one wanted.
  - **C (Runtime)** — It never falls over. It finishes normally and exits 0. It
    simply prints one line fewer than intended.
  - *Fair-warning note:* the off-by-one is named and demonstrated in the reading
    ("write `level < 10` when you meant `<= 10` and the table prints 9 rows"), so
    this is a comprehension check, not a gotcha. **A student who picks C is
    likely conflating "wrong" with "broken" — worth a sentence in class: most
    real bugs run fine.**

## Item 5 — Classify the fail-state
- **Type:** Classify-the-error · **MLO:** 5.2 · **Error class: Runtime** · **Source:** `code/practice-item5-cinfail.cpp`
- **Key: C — Runtime** ("ran, then fell over")
- **The one flaw:** `cin >> roll` fails on the word `six`, `cin` enters its fail
  state and stops reading, `roll` keeps its old value, `roll != 6` stays true
  forever. Confirmed: the program printed the prompt continuously until a hard
  timeout killed it. It never exits on its own.
- **Why Runtime:** It compiled clean and it *ran* — then got stuck and never
  reached the end. "Ran, then fell over" covers hanging as well as crashing: the
  program is alive and never finishing is a failure at run time.
- **Per-distractor feedback:**
  - **A (Syntax)** — It compiles. Grammar is fine.
  - **B (Static semantic)** — Nothing here is impossible to build.
  - **D (Logic)** — This is the tempting one, and worth teaching against
    directly. A Logic error *finishes* and gives a wrong answer. This program
    never finishes at all, so there is no wrong answer to inspect — the failure
    is the hang itself. **Compare with Item 4: the off-by-one finished and lied;
    this one never finished. That contrast is the whole point of running these
    two items back to back.**
  - *Fair-warning note:* the reading names the infinite loop as one of the two
    classic loop traps and explicitly says `Ctrl+C` is the emergency stop. Not a
    surprise.

## Item 6 — Predict: the bulletproofed read
- **Type:** Predict-the-output · **MLO:** 5.2 · **Source:** `code/practice-item6-validation.cpp` (working) and `code/practice-item6b-noignore.cpp` (the friend's broken version)
- **Key: B** — it loops forever, printing `That is not a door.` again and again
- **Why:** `cin.clear()` turns the fail flag **off**, so `cin` is willing to read
  again — but the offending `x` is **still sitting in the buffer**. The next
  `cin >> choice` grabs that same `x`, fails again, sets the flag again, and the
  cycle repeats with nothing ever consumed. `cin.ignore(...)` is what throws the
  bad line away. One call fixes the flag; the other clears the mess. **Both, or
  it spins.** Confirmed by running both versions: the complete one recovers and
  prints `You chose door 2.`; the version with `cin.ignore(...)` deleted printed
  the re-prompt continuously until a hard timeout killed it.
- **Per-distractor feedback:**
  - **A (works the same)** — The most common misconception, and the exact reason
    this item exists. `clear()` alone un-breaks the *stream*, not the *buffer*.
    Nothing has removed the `x`.
  - **C (crashes)** — C++ input streams do not throw or crash on bad input by
    default; they set a fail flag and go quiet. Quiet failure is precisely what
    makes this bug hard to spot.
  - **D (skips and uses `choice = 0`)** — Since C++11 a failed `>>` does write 0
    into the variable, so this distractor is *half* right — which is what makes
    it useful. But `0` fails the `choice < 1` range check, so the loop re-prompts
    rather than proceeding. The read does not "skip"; it retries forever.
    **A student choosing D has usually understood value-initialization and missed
    the buffer. Credit the first half out loud.**

## Item 7 — Predict: search a sequence
- **Type:** Predict-the-output · **MLO:** 5.4 · **Source:** `code/practice-item7-search.cpp`
- **Key: A** — `Potion found in the bag.`
- **Why:** `target` is `8`, and `potions[2]` is `8`. On the third pass the
  comparison is true and `found` becomes `true`. The loop finishes all five
  passes (there is no `break`), then the `if (found)` after the loop prints the
  found message. Confirmed by running it.
- **Per-distractor feedback:**
  - **B (`No such potion.`)** — `found` would still be `false` only if no slot
    matched. Slot 2 holds 8. Students who picked B may have miscounted indices —
    worth walking the array aloud: index 0 is 2, index 1 is 5, index 2 is 8.
  - **C (both lines)** — `if`/`else` runs exactly one branch, never both. This is
    M4 knowledge being checked inside an M5 context, which is the point.
  - **D (does not compile)** — Comparing inside a loop is completely ordinary.
    It compiles clean with zero warnings.

---

## Deep-build decisions recorded (instructor-facing)

- **Trace tables land in Practice as scratchpads, not graded artifacts** (Items 2
  and 3). MLO 5.3 asks students to *predict output using a trace table*; the
  exit ticket is completion-gated, so the table is the tool and the multiple
  choice is the check. **Producing** a trace table for credit is deferred to the
  Assess beat's Badge tier, where it is graded as documentation. This resolves
  the open question `_mlos.md` left about where the trace-table artifact lives:
  **both, at different stakes.**
- **The two classic loop traps are taught-then-checked, never sprung.** Both the
  infinite loop (Item 5) and the off-by-one (Item 4) are named, demonstrated, and
  explained in the Learn reading before appearing here. The ticket's intro warns
  students outright that they are coming. This satisfies the no-trick-questions
  policy explicitly.
- **Items 4 and 5 are deliberately adjacent** to force the Logic-vs-Runtime
  contrast: one finished and lied, the other never finished. Grading them as a
  pair is more informative than grading either alone.
- **Item 6 resolves the `_assess-spec.STUB.md` "known trap."** The stub asked
  whether the *why* behind the two-call `cin` recovery gets forced in Practice or
  left to Assess. It is forced **here**, by making the student predict what
  happens when one of the two calls is removed — which cannot be answered by
  pattern-matching the idiom. Assess then requires writing it unprompted.
- **Item 7 uses a raw array, which M7 owns.** This is intentional and
  spine-sanctioned: the M5 Assess line names "array-search" explicitly. M5 uses a
  fixed-size array as a *sequence to iterate*, nothing more — no array
  manipulation, no `sizeof` idioms, no passing arrays anywhere (there are no
  functions until M6). The `_mlos.md` drift concern is answered: M5 borrows the
  array as a loop target; M7 still owns arrays as a data structure.
- **The dungeon skin stays strippable.** Every item is scene-flavored (levels,
  HP, the door, potions) but no item's *answer* depends on the flavor. A student
  who reskins to a coffee shop gets identical questions.

## Predicted-misconception bank (seed — grow after first cohort run)
- Item 1 / C: assuming a counted loop always starts at 0.
- Item 2 / A: counting passes by the value *after* the update, so the final
  printing pass gets missed.
- Item 3 / B: believing a `do-while` checks its condition before finishing the
  body — the "runs at least once" rule not yet internalized.
- Item 4 / C: "wrong output" read as Runtime; conflating *incorrect* with
  *broken*.
- Item 5 / D: hanging read as Logic; not recognizing that a program which never
  finishes has no output to be wrong.
- Item 6 / A: believing `cin.clear()` alone recovers the stream — the buffer is
  invisible, so it is easy to forget it holds anything.
- Item 6 / D: knowing a failed `>>` writes 0, but not tracing that 0 through the
  range check.
- Item 7 / B: off-by-one in *reading* array indices (thinking `potions[2]` is 5).

## Compile & run log (2026-07-25)
```
Toolchain: Apple clang version 21.0.0 (clang-2100.1.1.101)
g++ -std=c++17 -Wall -Wextra  → ZERO warnings, ZERO errors on all 18 files in
modules/m5/code/, and on all 13 whole-program blocks embedded in learn.md and
practice-exit-ticket.md (16 blocks checked incl. Mermaid; 0 failures).

Item 1  practice-item1-levelup   (no input)  → Level 1: ready / Level 2: ready /
                                               Level 3: ready                [3 lines → B]
Item 2  practice-item2-hp        (no input)  → HP: 5 / HP: 3 / HP: 1 /
                                               You collapse.                 [3 lines → B]
Item 3  practice-item3-menu      1, 2, 3     → banner printed 3 times        [→ C]
Item 4  practice-item4-offbyone  (no input)  → Level 1 .. Level 9            [9 lines → D/Logic]
Item 5  practice-item5-cinfail   six         → prompt repeats without end;
                                               killed by 3s alarm            [hangs → C/Runtime]
Item 6  practice-item6-validation x, 2       → "That is not a door. ..." then
                                               You chose door 2.             [recovers]
Item 6b practice-item6b-noignore  x          → re-prompt repeats without end;
                                               killed by 3s alarm            [spins → B]
Item 7  practice-item7-search    (no input)  → Potion found in the bag.      [→ A]

Mermaid: 3 blocks in learn.md rendered via mmdc (101 KB, 101 KB, 107 KB SVG).
```

### Instructor note: testing these programs from a script

Two gotchas bit the verification run and will bite anyone automating it:

1. **The taught validation pattern spins forever at EOF.** When stdin runs out,
   `cin >> choice` fails, `cin.clear()` clears the EOF flag, `cin.ignore(...)`
   immediately hits EOF again, and the loop re-prompts without end. A student at
   a terminal never sees this — they can always type more. A *piped* test run
   hits it every time. **Always run these under a hard timeout.** macOS has no
   `timeout`; `perl -e 'alarm 5; exec @ARGV' -- ./prog` works everywhere.
   This is not a defect in the taught pattern — bulletproofing against a human is
   the goal, and EOF is not a human. It is worth knowing before someone "fixes"
   it.
2. **Feed one input per line.** Piping `5 x 2` as a single line makes
   `cin.ignore(..., '\n')` discard `x 2` along with the rest of that line, which
   silently changes what is being tested. Use `printf '5\nx\n2\n'`.
