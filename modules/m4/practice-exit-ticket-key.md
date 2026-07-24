---
title: "Module 4 Exit Ticket — Answer Key (INSTRUCTOR-FACING)"
module: M4
lpaa_beat: Practice
items: 7
audience: instructor
gate: completion
---

# Module 4 Exit Ticket — Answer Key

**Instructor-facing. Do not hand to students.** Every "working" snippet was
compiled and run under `g++ -std=c++17 -Wall -Wextra` and produced exactly the
output claimed below. Source files live in `modules/m4/code/`.

**Verification run (2026-07-24):** all four working programs
(`practice-item1-vault.cpp`, `practice-gatekeeper.cpp`,
`practice-item4-doors.cpp`, `practice-item7-status.cpp`) compiled with **zero
warnings, zero errors**. Outputs were captured by feeding the stated inputs on
stdin. See the "Compile & run log" at the bottom.

**Distractor source:** no cohort distractor bank exists for M4 yet (first
offering under this spine). Distractors are derived from the canonical
misconception catalog and the classic M4 traps named in the reading
(`= vs ==`, dangling `else`, `switch` fall-through, threshold off-by-one,
else-if ordering). New predicted misconceptions are recorded here so a bank can
grow — harvest wrong-answer rates after the first run and append.

---

## Item 1 — Warm-up predict-the-output
- **Type:** Predict-the-output · **MLO:** 4.1 (`if`/`else`) · **Source:** `code/practice-item1-vault.cpp`
- **Key: B** — `Not enough gold. Come back richer.`
- **Why:** `gold` is `45`. `45 >= 50` is false, so the `else` branch runs. Exactly
  one of the two branches runs — never both.
- **Per-distractor feedback:**
  - **A** — You may have read `>=` as "less than or equal," or assumed the first
    branch always runs. Check the comparison: `45 >= 50` is false.
  - **C** — In an `if`/`else`, exactly one branch runs, never both. If you expected
    both, review how `else` blocks the second path once the `if` is false.
  - **D** — It compiles fine. Every line is legal C++. "Does not compile" is only
    the answer when there is a real Syntax or Static semantic error.

## Item 2 — Trace the branch (else-if chain, no lockpick)
- **Type:** Trace-the-branch · **MLO:** 4.1 + 4.2 · **Source:** `code/practice-gatekeeper.cpp`, inputs `1`, `55`
- **Key: C** — `Borderline. Answer the riddle to pass.`
- **Filled trace table:**

  | Check, in order                 | With Warrior, strength 55 |
  |---------------------------------|---------------------------|
  | `strength >= 70`                | false (55 is not ≥ 70)    |
  | `strength >= 40 && hasLockpick` | false (`hasLockpick` is false — not a Rogue) |
  | `strength >= 40`                | **true → this branch runs** |

- **Why:** The chain is tested top to bottom and stops at the first true branch.
  55 fails the first two checks and passes the third.
- **Per-distractor feedback:**
  - **A** — That branch needs `strength >= 70`. 55 is below 70.
  - **B** — This branch needs `hasLockpick` to be true, but a Warrior never gets
    asked about a lockpick, so it stays `false`. `55 >= 40 && false` is false.
    This is the whole point of `&&`: **both** sides must be true.
  - **D** — `Too weak` is the final `else`, reached only when `strength < 40`. 55
    is not below 40.

## Item 3 — Trace the branch with `&&` (Rogue with lockpick)
- **Type:** Trace-the-branch · **MLO:** 4.2 (logical `&&`) · **Source:** `code/practice-gatekeeper.cpp`, inputs `3`, `50`, `1`
- **Key: B** — `Clever hands will do. You slip inside.`
- **Why:** Rogue, so the program asks about the lockpick and `hasLockpick`
  becomes true. `50 >= 70` is false; then `50 >= 40 && true` is **true**, so the
  second branch runs before the plain `strength >= 40` branch is ever reached.
- **Per-distractor feedback:**
  - **A** — Needs `strength >= 70`. 50 is below 70.
  - **C** — Order matters. `strength >= 40 && hasLockpick` is checked **before**
    the plain `strength >= 40`. Since the `&&` branch is true here, the chain
    stops there and never reaches C.
  - **D** — `Too weak` needs `strength < 40`. 50 is not below 40.

## Item 4 — Predict the output (`switch` default)
- **Type:** Predict-the-output · **MLO:** 4.1 (`switch`) · **Source:** `code/practice-item4-doors.cpp`
- **Key: C** — `You walk into a wall.`
- **Why:** `door` is `3`. There is no `case 3`, so control goes to `default`.
  That is exactly what `default` is for.
- **Per-distractor feedback:**
  - **A / B** — Those are `case 1` and `case 2`. `door` is 3, so neither matches.
  - **D** — A `switch` with no matching `case` does **not** print nothing — it
    runs `default`. If there were no `default` and no match, *then* nothing would
    print. Here there is a `default`.

## Item 5 — Classify the error (`switch` fall-through)
- **Type:** Classify-the-error · **MLO:** 4.1 (`switch`, taught trap) · **Error class: Logic** · **Source:** `code/practice-item5-fallthrough.cpp`
- **Key: D — Logic** ("did what you said, not what you meant")
- **The one flaw:** `case 1` has no `break`, so after printing the red line,
  control **falls through** into `case 2` and prints the blue line too. This trap
  is named in the reading — it is not a surprise.
- **Why Logic:** The program compiles and runs with no complaint (on our
  toolchain it produced **no** warning at all), and it does precisely what the
  code literally says — it just is not what the author *meant*. Code that builds,
  runs, and quietly does the wrong thing is the definition of a Logic error.
- **Per-distractor feedback:**
  - **A (Syntax)** — Nothing broke the grammar; it compiles. Syntax errors stop
    the compile with a message like "expected `;`."
  - **B (Static semantic)** — The meaning is not impossible; every statement is
    legal and buildable. Static semantic errors (like using an undeclared
    variable or adding a number to a string) stop the compile.
  - **C (Runtime)** — It never crashes or falls over while running; it finishes
    normally. It just prints an extra line.
  - *Fair-warning note for the instructor:* fall-through is taught by name in the
    Learn reading, so this is a comprehension check, not a gotcha. If a student
    picks A or B because "the compiler should have caught it," that is the exact
    misconception to correct — the compiler did **not** catch it here.

## Item 6 — Which line must change?
- **Type:** Which-line-changes · **MLO:** 4.1 + 4.3 · **Source:** `code/practice-gatekeeper.cpp` (outcome block)
- **Key: A — Line 1** (`if (strength >= 70)`)
- **Why:** To let strength `65` reach `The gate swings wide`, the first
  condition's threshold (`>= 70`) is what blocks it. Lowering that threshold to
  `65` (or lower) is the single change. No other line's condition controls that
  top outcome. *(Confirmed by running the program: Warrior, strength 65 currently
  prints "Borderline"; only line 1 gates the "gate swings wide" outcome.)*
- **Per-distractor feedback:**
  - **B (Line 5)** — This is the Rogue-lockpick branch. Changing it will not send
    a strength-65 Warrior to the top outcome; a Warrior has no lockpick.
  - **C (Line 9)** — This is the `Borderline` branch — the one a 65 currently
    lands in. Changing it changes what "borderline" means, not who fully passes.
  - **D (Line 13)** — This is the final `else` for the weakest players. It has no
    condition to change and does not affect strong players.

## Item 7 — Match the code to its flowchart (code → flowchart, MLO 4.3 reverse)
- **Type:** Which-flowchart-matches (code → flowchart recovery) · **MLO:** 4.3 (recover a flowchart from code) · **Source:** `code/practice-item7-status.cpp`
- **Key: A**
- **Why:** The code checks `hp >= 50` **first**; only if that is false does it
  check `hp >= 20`; otherwise `Critical`. Flowchart A tests them in that order,
  and each path leads to exactly one printed status. That mirrors an
  `if / else if / else` chain exactly.
- **Per-distractor feedback:**
  - **B** — This flowchart checks `hp >= 20` first, then `hp >= 50`. That is the
    wrong order. Under B, an hp of 80 would hit `hp >= 20` first and print
    `Wounded` — the code prints `Healthy`. **Order matters** in an else-if chain.
  - **C** — Here, after printing `Healthy`, the flow still drops into the
    `hp >= 20` check, so a high hp could print **two** lines. That is what
    *separate* `if` statements would do — not an `if / else if` chain. The `else`
    is exactly what stops the second check once the first was true.

---

## Deep-build decisions recorded (instructor-facing)

- **MLO 4.3 reverse direction (code → flowchart) lands here in Practice, as a
  recognition item (Item 7), not a production item.** Students *match* code to
  the correct flowchart rather than *draw* one — drawing is a write task and
  belongs to Assess, where producing a flowchart-first design is graded. Practice
  stays read-only per the exit-ticket genre, but still exercises the reverse
  direction the spine requires "at least once."
- **Dungeon Gatekeeper is the taught/worked skin** across the ticket, matching
  the canonical `_contracts/m4_gatekeeper.cpp` shape (switch on class, else-if on
  a threshold, one `&&` compound condition). The intro explicitly offers reskins
  (bouncer / gate agent / loan officer) so the theme stays strippable.
- **Compound conditions (`&&`) are traced in Practice** (Item 3), because the
  canonical contract uses `strength >= 40 && hasLockpick` and the reading teaches
  it. Practice does not *introduce* `&&`; it checks comprehension of it.
- **The classic traps are taught-then-checked, never sprung.** Fall-through
  (Item 5) is named in the reading and framed here as "this compiles and runs" —
  no gotcha. `= vs ==` and the dangling `else` are named in the reading and
  reinforced in Item 7's distractor C (missing `else` = separate ifs); neither is
  sprung as a hidden trap.

## Predicted-misconception bank (seed — grow after first cohort run)
- Item 2 / B: `&&` read as "either side" instead of "both sides."
- Item 3 / C: else-if order assumed not to matter.
- Item 4 / D: belief that a `switch` with no matching case prints nothing even
  when a `default` exists.
- Item 5 / A,B: belief that the compiler always catches a missing `break`.
- Item 6 / C: confusing "the branch a value currently lands in" with "the branch
  that gates the target outcome."
- Item 7 / C: treating `if / else if` as interchangeable with separate `if`s.

## Compile & run log (2026-07-24)
```
g++ -std=c++17 -Wall -Wextra  → zero warnings on:
  practice-item1-vault.cpp, practice-gatekeeper.cpp,
  practice-item4-doors.cpp, practice-item7-status.cpp

Item 1  (no input)                         → Not enough gold. Come back richer.
Item 4  (no input)                         → You walk into a wall.
Item 5  (no input)                         → Red potion: +10 health.
                                             Blue potion: +10 mana.   (fall-through; no warning emitted)
Item 2  gatekeeper 1,55                    → A Warrior steps up. / Borderline. Answer the riddle to pass.
Item 3  gatekeeper 3,50,1                  → A Rogue steps up. / Clever hands will do. You slip inside.
Item 6  gatekeeper 1,65 (setup check)      → A Warrior steps up. / Borderline. Answer the riddle to pass.
Item 7  status hp=35                        → Wounded
```
```
