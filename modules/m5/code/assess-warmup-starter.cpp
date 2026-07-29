// assess-warmup-starter.cpp — CSC-134 M5 (Loops) ASSESS starter, Part 1
//
// STUDENT-FACING. Three loop-fundamentals exercises: a `while` loop, a `for`
// loop, and an array search. Each one is marked with a TODO. Everything you
// need is already declared — your job is the loop itself.
//
// This file compiles and runs AS-IS. It just gives wrong answers until you
// finish it, which is exactly what you are fixing. Full instructions:
// modules/m5/assess-lab.md.
//
// Rename your finished file to m5lab-warmup.cpp before you submit.
//
// Everything lives in main — no functions, no prototypes (those arrive in M6).
//
// Build: g++ -std=c++17 -Wall -Wextra -o m5lab-warmup assess-warmup-starter.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // ================= EXERCISE 1: a `while` loop =================
    // The hero rests. Health regenerates 7 points per hour of rest, and the
    // hero stops resting the moment health reaches 100 or more.
    //
    // TODO(Exercise 1): write a `while` loop that repeats until health
    // reaches 100 or more. Each pass must:
    //   - add 7 to health
    //   - add 1 to hoursRested
    //   - print one line: "Hour <hoursRested>: health is <health>"
    //
    // Remember the update. A `while` loop whose body never changes what the
    // condition tests is the infinite loop you met in the reading (Runtime).

    int health = 58;
    int hoursRested = 0;

    cout << "==== EXERCISE 1: THE LONG REST ====\n";
    cout << "Health starts at " << health << ".\n";

    // <-- your while loop goes here

    cout << "Rested " << hoursRested << " hours. Final health: " << health << ".\n";

    // ================= EXERCISE 2: a `for` loop =================
    // A counted table. Print the gold a hero earns on each of days 1 through 12,
    // where the reward for a day is: 20 + day * 4.
    //
    // TODO(Exercise 2): write a `for` loop that counts `day` from 1 through 12
    // (all twelve days — mind the fence-post) and prints one row per day using
    // the setw widths already used in the header below.

    cout << "\n==== EXERCISE 2: TWELVE DAYS OF PAY ====\n";
    cout << setw(5) << "DAY" << setw(8) << "GOLD" << "\n";

    // <-- your for loop goes here

    // ================= EXERCISE 3: an array search =================
    // Search a fixed sequence for a value. The array and the target are given.
    //
    // TODO(Exercise 3): write a `for` loop that walks all 8 slots of `runes`
    // and checks each one against `target`. If a slot matches, set `found` to
    // true and set `foundAt` to that slot's index.
    //
    // Then the printing below will report the right answer on its own. Do not
    // change the printing — change only the search.

    int runes[8] = {3, 14, 7, 22, 9, 41, 16, 5};
    int target = 22;
    bool found = false;
    int foundAt = -1;

    cout << "\n==== EXERCISE 3: SEARCH THE RUNE BAG ====\n";

    // GIVEN: this loop WALKS the bag and prints every rune. Read it — your
    // search loop below walks the bag exactly the same way. The only thing
    // you add is a decision inside the body.
    cout << "The bag holds:";
    for (int i = 0; i < 8; i++)
    {
        cout << " " << runes[i];
    }
    cout << "\n";

    cout << "Looking for rune " << target << ".\n";

    // <-- your search loop goes here

    if (found)
    {
        cout << "Found rune " << target << " in slot " << foundAt << ".\n";
    }
    else
    {
        cout << "No rune " << target << " in the bag.\n";
    }

    return 0;
}
