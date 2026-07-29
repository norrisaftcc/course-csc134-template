// assess-warmup-reference.cpp — CSC-134 M5 (Loops) ASSESS Part 1 reference
//
// ============================================================================
// INSTRUCTOR-FACING. NOT part of the student handout. Do NOT distribute.
// This is assess-warmup-starter.cpp with all three TODOs completed — the
// grader's exemplar for Part 1 (loop fundamentals) of assess-lab.md.
// ============================================================================
//
// Exercise 1 exercises `while` (condition unknown in advance).
// Exercise 2 exercises `for`  (count known in advance).
// Exercise 3 exercises loop + selection over a fixed sequence (array search).
//
// Everything lives in main — no functions, no prototypes (pre-M6 convention).
//
// Build: g++ -std=c++17 -Wall -Wextra -o assess-warmup-reference assess-warmup-reference.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // ================= EXERCISE 1: a `while` loop =================
    int health = 58;
    int hoursRested = 0;

    cout << "==== EXERCISE 1: THE LONG REST ====\n";
    cout << "Health starts at " << health << ".\n";

    while (health < 100)
    {
        health = health + 7;
        hoursRested = hoursRested + 1;
        cout << "Hour " << hoursRested << ": health is " << health << "\n";
    }

    cout << "Rested " << hoursRested << " hours. Final health: " << health << ".\n";

    // ================= EXERCISE 2: a `for` loop =================
    cout << "\n==== EXERCISE 2: TWELVE DAYS OF PAY ====\n";
    cout << setw(5) << "DAY" << setw(8) << "GOLD" << "\n";

    // <= 12, not < 12 — all twelve days count.
    for (int day = 1; day <= 12; day++)
    {
        int gold = 20 + day * 4;
        cout << setw(5) << day << setw(8) << gold << "\n";
    }

    // ================= EXERCISE 3: an array search =================
    int runes[8] = {3, 14, 7, 22, 9, 41, 16, 5};
    int target = 22;
    bool found = false;
    int foundAt = -1;

    cout << "\n==== EXERCISE 3: SEARCH THE RUNE BAG ====\n";

    cout << "The bag holds:";
    for (int i = 0; i < 8; i++)
    {
        cout << " " << runes[i];
    }
    cout << "\n";

    cout << "Looking for rune " << target << ".\n";

    // The search: walk every slot, and decide at each one.
    for (int i = 0; i < 8; i++)
    {
        if (runes[i] == target)
        {
            found = true;
            foundAt = i;
        }
    }

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
