---
title: "M5 Apply: Level Up Stats, then Bulletproof the Door"
module: M5
lpaa_beat: Apply
mode: "SPLIT — Part 1 FULL (type-in 100%), Part 2 EIGHTY (finish the 80%)"
estimated_time: "55 minutes (class session)"
prerequisites:
  reading: "Loops: Teaching Your Program to Repeat (modules/m5/learn.md)"
  exit_ticket: "Module 5 exit ticket (completion gate)"
program_file: "apply-levelup.cpp (Part 1), apply-menu-scaffold.cpp → m5_apply.cpp (Part 2)"
---

# M5 Apply: Level Up Stats, then Bulletproof the Door

## What We're Building

Two programs, in one session, and the order matters.

**Part 1 — Level Up Stats.** A counted `for` loop that prints ten levels of a
hero's growth as one aligned table. You type every character of this one
yourself. It is the last full type-in of the course.

**Part 2 — The Dungeon Door, bulletproofed.** You receive the M4 gatekeeper
wrapped in a working menu — about 80% of a finished program — with exactly one
piece missing: the input-validation loop. You write that piece.

Here is Part 2's finished target. Watch the first line of input: the player
types `x`, and the program *survives it*.

```
You stand before the dungeon door. A gatekeeper waits.

==== THE DUNGEON DOOR ====
1) Approach the gate
2) Hear the gatekeeper's rules
3) Leave
Choose (1-3): That is not a door. Choose 1, 2, or 3:
The gatekeeper looks you over.
Your class? (1 = Warrior, 2 = Mage, 3 = Rogue): "A Warrior. Strong arms, I hope."
Your strength score (0-100): The gate swings wide. "Strong enough. Go through."

==== THE DUNGEON DOOR ====
1) Approach the gate
2) Hear the gatekeeper's rules
3) Leave
Choose (1-3):
You step back from the door. The gatekeeper nods.

Until next time, traveler.
```

*(Player typed: `x`, `1`, `1`, `80`, `3`.)*

---

## Stage 1: The banner (~6 min)

The smallest thing that runs. Type it, build it, run it — that proves your
toolchain works before anything harder shows up.

```cpp excerpt=modules/m5/code/apply-stage1-banner.cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";
    return 0;
}
```

**Predict first:** what will this print? Say it out loud before you run it.

```bash
g++ -std=c++17 -Wall -Wextra -o apply-levelup apply-levelup.cpp
./apply-levelup
```

**Expected output:**

```
==== LEVEL UP STATS ====
```

If you got that, your compiler works and you are ready for the real material.

## Stage 2: The header row (~8 min)

Now the column headers. This stage introduces `setw(n)` from `<iomanip>`, which
sets the next thing printed to be `n` characters wide. That is what makes
numbers line up in a column instead of drifting.

Two new things: the `#include <iomanip>` line, and the header `cout`.

```cpp excerpt=modules/m5/code/apply-stage2-headers.cpp
#include <iostream>
#include <iomanip>                          // NEW — setw lives here
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";

    cout << setw(5) << "LVL"                // NEW
         << setw(6) << "STR"                // NEW
         << setw(6) << "DEX"                // NEW
         << setw(6) << "INT" << "\n";       // NEW

    return 0;
}
```

**Predict first:** the words are 3 letters each, but the widths are 5 and 6.
Where will the extra spaces go — before each word, or after?

```bash
g++ -std=c++17 -Wall -Wextra -o apply-levelup apply-levelup.cpp
./apply-levelup
```

**Expected output:**

```
==== LEVEL UP STATS ====
  LVL   STR   DEX   INT
```

The padding goes **before** each word — `setw` right-aligns by default. That is
exactly what you want for a table of numbers.

## Stage 3: The loop (~10 min)

Here is the module's whole idea in one block. Three stats, ten levels, one
counted loop.

```cpp excerpt=modules/m5/code/apply-stage3-loop.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";

    cout << setw(5) << "LVL"
         << setw(6) << "STR"
         << setw(6) << "DEX"
         << setw(6) << "INT" << "\n";

    // start at level 1, keep going while level <= 10, add one each pass  // NEW
    for (int level = 1; level <= 10; level++)                            // NEW
    {                                                                    // NEW
        int strength     = 10 + level * 2;                               // NEW
        int dexterity    =  8 + level * 3;                               // NEW
        int intelligence = 12 + level * 1;                               // NEW
                                                                         // NEW
        cout << setw(5) << level                                         // NEW
             << setw(6) << strength                                      // NEW
             << setw(6) << dexterity                                     // NEW
             << setw(6) << intelligence << "\n";                         // NEW
    }                                                                    // NEW

    return 0;
}
```

**Predict first — and this time, trace it.** Do not run it yet. Fill in the
first two rows by hand using the formulas, then check yourself:

| Pass | `level` | `level <= 10`? | STR = 10+2·lvl | DEX = 8+3·lvl | INT = 12+1·lvl |
|---|---|---|---|---|---|
| 1 | 1 |  |  |  |  |
| 2 | 2 |  |  |  |  |

Also predict: **how many rows print?** Commit to a number before you build.

```bash
g++ -std=c++17 -Wall -Wextra -o apply-levelup apply-levelup.cpp
./apply-levelup
```

**Expected output:**

```
==== LEVEL UP STATS ====
  LVL   STR   DEX   INT
    1    12    11    13
    2    14    14    14
    3    16    17    15
    4    18    20    16
    5    20    23    17
    6    22    26    18
    7    24    29    19
    8    26    32    20
    9    28    35    21
   10    30    38    22
```

Ten rows. Your traced rows should match the top two exactly. When your hand and
the machine agree, you understood the loop. When they disagree, the trace table
tells you *which pass* went wrong — that is the whole reason to keep one.

---

## The Deliberate Break (~5 min)

Everyone's program works. Now break it on purpose.

**Find this line:**

```cpp excerpt=modules/m5/code/apply-levelup.cpp
    for (int level = 1; level <= 10; level++)
```

**Change `<=` to `<`:**

```cpp excerpt=modules/m5/code/practice-item4-offbyone.cpp
    for (int level = 1; level < 10; level++)
```

**Predict:** will the compiler complain? Rebuild and see.

```bash
g++ -std=c++17 -Wall -Wextra -o apply-levelup apply-levelup.cpp
./apply-levelup
```

**Actual result — and this is the lesson:**

```
==== LEVEL UP STATS ====
  LVL   STR   DEX   INT
    1    12    11    13
    2    14    14    14
    3    16    17    15
    4    18    20    16
    5    20    23    17
    6    22    26    18
    7    24    29    19
    8    26    32    20
    9    28    35    21
```

**The compiler said nothing.** Zero errors, zero warnings, even with `-Wall
-Wextra`. The program ran perfectly and finished normally. It just printed
**nine** rows instead of ten.

Ask the room: which of the four error names is this?

- Not **Syntax** — nothing broke the grammar; it compiled.
- Not **Static semantic** — `level < 10` is a perfectly legal comparison.
- Not **Runtime** — it never fell over; it exited cleanly.
- **Logic.** It did exactly what you said. You just said the wrong thing.

This is the **off-by-one**, the most famous bug in loops, and it is the reason
you now own a trace table. No tool caught this. A person had to. Every time you
write a loop bound, pause for two seconds and ask the fence-post question:
*does the last value count, or not?*

**Now put it back** — change `<` to `<=`, rebuild, confirm ten rows. Part 2
needs a working brain, not a working program.

---

# PART 2 — Bulletproof the Door (EIGHTY: finish the 80%)

Everything changes here. You will not type this program. You will **receive**
it, read it, and finish the one piece that is missing.

Get the file from the course repo and make your working copy:

```bash
git pull
cp modules/m5/code/apply-menu-scaffold.cpp m5_apply.cpp
```

## Movement 1 — Investigate (~10 min)

**Read it before you write anything.** Open `m5_apply.cpp`. Do not scroll
straight to the TODO.

Notice what you are looking at: the block marked `the M4 gatekeeper core` is
**the program you wrote in M4**, dropped in as one menu action. Nothing about
the decision changed. What is new is the `do`/`while` wrapped around it. That is
the seam this whole module is about — **the loop wrapped the decision; it did
not replace it.**

Trace one path out loud as a class: the player types `2`. Which lines run, in
what order, and where does control go after the action finishes?

**One new word before you trace.** Down in the `default` case you will hit
`continue;`. It means *stop this pass here and go straight to the loop's
condition test* — skip whatever is left in the body. The catch is where that
test lives: in a `do`/`while` the condition is the `while (...)` line at the
**bottom**, not the top. So `continue` sends the player back to the menu for
another turn rather than out of the loop. That is the one keyword in this file
the reading has not shown you; everything else you have already written
yourself.

**Now build it and run it as-is.** It compiles clean — the file you were handed
always does.

```bash
g++ -std=c++17 -Wall -Wextra -o m5_apply m5_apply.cpp
./m5_apply
```

Choose `2`, then `3`. It works fine.

**Now run it again and type `banana` at the menu.**

**What actually happens:**

```
==== THE DUNGEON DOOR ====
1) Approach the gate
2) Hear the gatekeeper's rules
3) Leave
Choose (1-3):
You step back from the door. The gatekeeper nods.

==== THE DUNGEON DOOR ====
1) Approach the gate
2) Hear the gatekeeper's rules
3) Leave
Choose (1-3):
You step back from the door. The gatekeeper nods.

... and so on, forever.
```

Press `Ctrl+C` to stop it.

Read what happened. `cin >> choice` could not turn `banana` into a number, so it
gave up and entered its **fail state** — and `banana` is *still sitting in the
buffer*, waiting. Every trip through the loop tries to read it again, fails
again, and the menu spins. The program did not crash. It is still running right
now if you did not stop it. **Runtime** failure.

That spin is your job to fix.

## Movement 2 — Spec review (~4 min)

Scroll to the marked region. Read the comment block aloud — someone read it to
the room:

```cpp excerpt=modules/m5/code/apply-menu-scaffold.cpp
        // ============================================================
        // YOUR CODE: the input-validation loop
        //
        // Spec: keep asking until the player gives a real number, 1-3.
        //   - If they type letters, cin enters a fail state. You must
        //     cin.clear() to drop the fail flag, THEN
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n') to throw
        //     away the bad line still sitting in the buffer. Both calls,
        //     in that order — clear the flag, then clear the text.
        //   - If they type a number outside 1-3, re-prompt too.
        //   - Re-prompt text: "That is not a door. Choose 1, 2, or 3: "
        //
        // Right now the read is UNGUARDED (the one line below). Replace it
        // with the validation loop. See the acceptance check in the tutorial.
        // ============================================================
        cin >> choice;   // STUB: unguarded read — no validation yet
```

Restate it in your own words before you write anything. Two questions to answer
out loud:

1. **What are the two ways input can be wrong here?** (Letters — the read
   fails. And a number out of range — the read succeeds but the value is bad.
   Your condition must catch *both*.)
2. **Why two recovery calls instead of one?** (One resets the broken flag; the
   other throws away the bad text. Skip either and it spins. You predicted this
   on exit-ticket Item 6.)

## Movement 3 — Make (~12 min)

Replace the single stub line with your validation loop. `<limits>` is already
included for you.

You have seen this shape twice — in the reading, and on the exit ticket. Write
it from understanding, not memory. When you are stuck, reread your own answer to
question 1 above: **both** ways of being wrong, in **one** condition.

```bash
g++ -std=c++17 -Wall -Wextra -o m5_apply m5_apply.cpp
./m5_apply
```

### The acceptance check

Your program is finished when it survives all four of these. Run every one.

| # | Type this at the menu | Required behavior |
|---|---|---|
| 1 | `banana` | Re-prompts with `That is not a door. Choose 1, 2, or 3:` — does **not** spin |
| 2 | `9` | Re-prompts the same way — a number is not enough, it must be in range |
| 3 | `0` | Re-prompts the same way — the low end is guarded too |
| 4 | `2` | Prints the gatekeeper's rules and returns to the menu |

And the whole-program check: **you must always be able to reach `3` and exit
cleanly.** If any input can trap the player at the door forever, the program is
not done.

**Expected terminal session** once it works:

```
==== THE DUNGEON DOOR ====
1) Approach the gate
2) Hear the gatekeeper's rules
3) Leave
Choose (1-3): That is not a door. Choose 1, 2, or 3: That is not a door. Choose 1, 2, or 3:
"Strength 70 or more: you pass. 40 to 69: a riddle,
 or a lockpick if you have the hands for it. Below 40: away."
```

*(Player typed `banana`, then `9`, then `2`.)*

## Wrap-Up

You did two different things today, and the difference is the point.

In Part 1 you typed every character. In Part 2 you read someone else's working
program, found the one thing it was missing, and supplied it. **The second skill
is the one the rest of this course runs on** — and the rest of your career, for
that matter. Most code you will ever touch is code you did not write.

You also met both classic loop bugs face to face: the **off-by-one** (Logic — it
finished and lied) and the **`cin` fail-state spin** (Runtime — it never
finished at all). Neither was sprung on you. You now know their names and what
they look like from the outside.

**Next: the Assess lab.** You will build Project 2, the menu-driven game, on the
pattern you just finished. The C tier is precisely the piece you wrote today —
a menu loop with one fully-validated read — applied to a scene of your own. The
lab starter arrives about as complete as today's did, so you start no blanker
than you ended here. The A tier asks you to wrap an M4-style decision inside the
loop, which is the same seam you traced in Movement 1.

Bring your trace table.


---

## Instructor notes (not part of the student handout)

**Why this session is split.** M5 sits at the seam of the Make gradient. M2–M4
were type-in-100%; M5–M7 are finish-the-80%. Rather than flip the switch between
modules and hope it lands, M5 flips it **inside one class period**: students get
one more full type-in as a warm-up, then immediately meet the new shape while
the muscle memory is warm. Do not collapse Part 1 into a handout — the type-in
is the point of Part 1, and it is the last one they get.

**Timing.**

| Segment | Time | Mode |
|---|---|---|
| Part 1, Stage 1 — the banner | ~6 min | FULL type-in |
| Part 1, Stage 2 — the header row | ~8 min | FULL type-in |
| Part 1, Stage 3 — the loop | ~10 min | FULL type-in |
| **The Deliberate Break** | ~5 min | on just-typed code |
| Part 2, Investigate — read and run the 80% | ~10 min | EIGHTY |
| Part 2, Spec review — read the contract aloud | ~4 min | EIGHTY |
| Part 2, Make — write the validation loop | ~12 min | EIGHTY |
| **Total** | **~55 min** | |

Halfway mark is the Deliberate Break. If you are running long, Part 1 Stage 3
and the Break are the floor — Part 2's Make movement can become homework, but
only if students have at least *run* the unguarded scaffold and seen it spin.

**Where students stall.**

- **Stage 2, `setw`:** forgetting `#include <iomanip>`. The error names `setw`
  as undeclared — good, readable, and worth reading aloud.
- **Stage 3, the semicolons in the `for` header:** students write commas.
  `for (int level = 1, level <= 10, level++)` is a Syntax error with a long
  message; point out that the three parts are separated by `;`, not `,`.
- **Stage 3, brace placement:** typing the loop body before the opening `{`.
- **Part 2, Make:** the most common wrong answer is writing `&&` where `||`
  belongs. See "If a student writes `&&`" below — it compiles clean and looks
  right, so catch it by *testing*, not by reading.
- **Part 2, Make:** forgetting that `cin.clear()` and `cin.ignore(...)` are two
  separate calls in that order. The exit ticket rehearsed exactly this.

**A note on the two failure reps.** The skill calls for one scripted break per
tutorial; this session has one formal Break (Part 1, on code students just
typed) plus one *provided-code* failure they run in Part 2's Investigate
movement. That is deliberate, not drift: the Part 1 Break is the FULL-mode rep
(read the failure of code you wrote), and Part 2's Investigate is the
EIGHTY-mode rep (read the failure of code you were handed). Each part gets the
rep its mode calls for.

---

# PART 1 — Level Up Stats (FULL type-in)

You type this one. No copy-paste, no downloading. Typing is how the syntax gets
into your fingers, and reading your own typos is how you learn to read the
compiler.

Make a new file called `apply-levelup.cpp`.

### Instructor-only: the reference solution

The finished file is `modules/m5/code/apply-menu-complete.cpp`. Do not
distribute it before the Make movement ends. The validation loop reads:

```cpp excerpt=modules/m5/code/apply-menu-complete.cpp
        // ===== THE VALIDATION LOOP (the M5 bulletproofing) =====
        // Keep asking until the player gives a real number, 1 through 3.
        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cin.clear();  // drop the fail flag if they typed letters
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // dump the bad line
            cout << "That is not a door. Choose 1, 2, or 3: ";
        }
```

This is identical to the frozen contract's validation in
`_contracts/m5_menu.cpp`, on purpose — students are building the course's
canonical pattern, not a one-off.

### Instructor-only: if a student writes `&&`

This is the single most common wrong answer, and it is **invisible on
inspection**:

```cpp excerpt=modules/m5/code/apply-break-and-validation.cpp
    while (!(cin >> choice) && choice < 1 && choice > 3)   // WRONG — silently does nothing
```

It compiles clean under `-Wall -Wextra`. It looks reasonable. And it does
**nothing at all** — a number cannot be both less than 1 and greater than 3, so
the condition is never true and the loop body never runs. The program behaves
exactly like the unguarded stub they started with: type `banana` and it spins
forever, just as before.

Do not correct this by reading their screen. Send them to the acceptance check —
test 1 fails immediately. That is the habit worth building: **you find this
class of bug by running it, not by looking at it.** `||` is right because the
input is bad if it fails the read **or** it is under 1 **or** it is over 3 — any
one of those is enough to re-ask.

