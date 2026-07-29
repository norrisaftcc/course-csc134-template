---
title: "Module 5 Exit Ticket: Loops — How Many Times, and When Does It Stop?"
module: M5
lpaa_beat: Practice
items: 7
estimated_time: "13-16 minutes"
gate: completion   # finishing unlocks the Apply tutorial; score is feedback only
---

# Module 5 Exit Ticket: Loops — How Many Times, and When Does It Stop?

This is a checkpoint, not a test. Finish it and you move on to the Apply
tutorial. Wrong answers cost you nothing — they just tell us both what to
review before you write loop code yourself. **No trick questions, ever.**

You'll read loops and predict what they do: how many times a body runs, what
prints, and where a loop goes wrong. You won't write any code here. That comes
next, in Apply.

Two of these items hand you a **trace table** — a little scratchpad for walking
a loop one pass at a time. Filling it in is not graded; it's the tool that gets
you to the right answer. This is the "trace before you run" habit M5 is built
around.

A heads-up on two items: you'll meet a loop that **never stops** and a program
that **spins forever** when someone types the wrong thing. Those aren't
gotchas — they're the two famous loop bugs, and naming them is exactly what
this module teaches. Spotting them here is the whole point.

---

## Item 1 — Warm-up: predict the output

A `for` loop counts `level` from 1 up to and including 3. What does this
program print?

``` cpp excerpt=modules/m5/code/practice-item1-levelup.cpp
#include <iostream>
using namespace std;

int main()
{
    for (int level = 1; level <= 3; level++)
    {
        cout << "Level " << level << ": ready\n";
    }
    return 0;
}
```

- A) `Level 1: ready` (just once)
- B) Three lines: `Level 1: ready`, `Level 2: ready`, `Level 3: ready`
- C) Four lines: `Level 0: ready` through `Level 3: ready`
- D) It does not compile.

---

## Item 2 — Trace a `while` loop

This loop drops your `hp` by 2 each pass until you run out. Walk it one pass at
a time using the trace table, then answer the question.

``` cpp excerpt=modules/m5/code/practice-item2-hp.cpp
#include <iostream>
using namespace std;

int main()
{
    int hp = 5;
    while (hp > 0)
    {
        cout << "HP: " << hp << "\n";
        hp = hp - 2;
    }
    cout << "You collapse.\n";
    return 0;
}
```

Filling in this trace table may help you decide (it's a scratchpad, not graded —
the question below is what counts):

| Pass | `hp` before the check | `hp > 0`? | `HP:` line prints? | `hp` after `hp = hp - 2` |
|------|-----------------------|-----------|--------------------|--------------------------|
| 1    | 5                     |           |                    |                          |
| 2    |                       |           |                    |                          |
| 3    |                       |           |                    |                          |
| 4    |                       |           |                    |                          |

**How many `HP:` lines print before `You collapse.`?**

- A) 2
- B) 3
- C) 5
- D) The loop never stops.

---

## Item 3 — Trace the menu loop (loops wrap decisions)

Here's a smaller version of the menu you'll finish in Apply. Read it once. This
is the **M4 → M5 seam** up close: the decision about *which action to run* is
the same kind of branching you wrote in M4 — but now it lives **inside** a
`do`/`while` loop that keeps bringing the player back to the door. The loop
didn't replace the decision; it wrapped it.

``` cpp excerpt=modules/m5/code/practice-item3-menu.cpp
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    do
    {
        cout << "==== THE DUNGEON DOOR ====\n";
        cout << "1) Approach the gate\n";
        cout << "2) Hear the rules\n";
        cout << "3) Leave\n";
        cout << "Choose (1-3): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "The gatekeeper looks you over.\n";
        }
        else if (choice == 2)
        {
            cout << "\"Strength 70 or more and you pass.\"\n";
        }
        else if (choice == 3)
        {
            cout << "You step back from the door.\n";
        }
    } while (choice != 3);

    cout << "Until next time, traveler.\n";
    return 0;
}
```

A player types, in order: `1`, then `2`, then `3`.

Filling in this trace table may help you count (scratchpad, not graded):

| Pass | You type | Action that runs | `choice != 3`, so loop again? |
|------|----------|------------------|-------------------------------|
| 1    | 1        |                  |                               |
| 2    | 2        |                  |                               |
| 3    | 3        |                  |                               |

**How many times does the `==== THE DUNGEON DOOR ====` banner appear?**

- A) 1
- B) 2
- C) 3
- D) 4

---

## Item 4 — Spot the off-by-one

The author wanted this loop to print **all ten levels** — `Level 1` through
`Level 10`. It compiles with no errors, it runs with no crash, but it prints
only **nine** lines (`Level 1` through `Level 9`).

``` cpp excerpt=modules/m5/code/practice-offbyone-levels.cpp
#include <iostream>
using namespace std;

int main()
{
    // Wants to print Level 1 through Level 10:
    for (int level = 1; level < 10; level++)
    {
        cout << "Level " << level << "\n";
    }
    return 0;
}
```

Using the course's four error names, this off-by-one is a:

- A) **Syntax** error (broke the grammar)
- B) **Static semantic** error (grammar fine, meaning impossible)
- C) **Runtime** error (ran, then fell over)
- D) **Logic** error (did what you said, not what you meant)

---

## Item 5 — Classify the fail-state

This is one of the two famous loop bugs — and it's *supposed* to show up here,
so you can name it. The program asks for a number and loops until you roll a 6.
A player types the **word** `six` instead of the digit. The program then prints
the prompt again, and again, and again, forever — it never stops and never
crashes on its own.

``` cpp excerpt=modules/m5/code/practice-item5-cinfail.cpp
#include <iostream>
using namespace std;

int main()
{
    int roll = 0;
    while (roll != 6)
    {
        cout << "Roll a 6 to escape (enter a number): ";
        cin >> roll;
    }
    cout << "You escaped!\n";
    return 0;
}
```

When the input is the word `six`, `cin` can't read a number, so it stops
reading and `roll` keeps its old value. Using the course's four error names,
the endless spinning is a:

- A) **Syntax** error (broke the grammar)
- B) **Static semantic** error (grammar fine, meaning impossible)
- C) **Runtime** error (ran, then fell over)
- D) **Logic** error (did what you said, not what you meant)

---

## Item 6 — Predict: the bulletproofed read

Here is the fix for Item 5's bug — the validation loop you'll finish in Apply.
It keeps asking until it gets a real number from 1 to 3. If you type a letter,
it recovers and re-prompts. Two clean-up lines make that recovery work:
`cin.clear()` and `cin.ignore(...)`.

``` cpp excerpt=modules/m5/code/practice-item6-validation.cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int choice = 0;
    cout << "Choose (1-3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a door. Choose 1, 2, or 3: ";
    }
    cout << "You chose door " << choice << ".\n";
    return 0;
}
```

Your friend decides `cin.clear()` is enough and **deletes the
`cin.ignore(...)` line**, keeping everything else. They run their version and
type the letter `x`.

**What happens?**

- A) It works exactly the same — `cin.clear()` alone is enough.
- B) It loops forever, printing `That is not a door.` again and again.
- C) It crashes with an error message and stops.
- D) It skips the input and uses `choice = 0`.

---

## Item 7 — Predict: search a sequence

This program walks a bag of five potion values once, and checks each slot
against the one it's looking for. What does it print?

``` cpp excerpt=modules/m5/code/practice-item7-search.cpp
#include <iostream>
using namespace std;

int main()
{
    int potions[5] = {2, 5, 8, 11, 14};
    int target = 8;
    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (potions[i] == target)
        {
            found = true;
        }
    }

    if (found)
        cout << "Potion found in the bag.\n";
    else
        cout << "No such potion.\n";

    return 0;
}
```

- A) `Potion found in the bag.`
- B) `No such potion.`
- C) Both lines print, one after the other.
- D) It does not compile, because you can't compare inside a loop.

---

*That's the whole ticket. Once you've worked through every item, you're cleared
for the Apply tutorial, where you'll type in the Level Up Stats loop and then
finish the menu's validation loop yourself.*
