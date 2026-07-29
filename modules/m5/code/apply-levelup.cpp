// apply-levelup.cpp — CSC-134 M5 (Loops) Apply, Part 1
//
// The Level Up Stats table: a counted `for` loop that prints ten levels of a
// hero's growth as one aligned table. This is the last type-in-100% warm-up —
// you type every character yourself, one compiling stage at a time.
//
// Single-file, main-only (the pre-M6 convention) — no functions yet.
//
// Build: g++ -std=c++17 -Wall -Wextra -o apply-levelup apply-levelup.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";

    // Column headers, spaced to the same widths as the rows below.
    cout << setw(5) << "LVL"
         << setw(6) << "STR"
         << setw(6) << "DEX"
         << setw(6) << "INT" << "\n";

    // The counted loop: start at level 1, keep going while level <= 10,
    // add one each pass. The body runs once per level — ten times total.
    for (int level = 1; level <= 10; level++)
    {
        int strength     = 10 + level * 2;
        int dexterity    =  8 + level * 3;
        int intelligence = 12 + level * 1;

        cout << setw(5) << level
             << setw(6) << strength
             << setw(6) << dexterity
             << setw(6) << intelligence << "\n";
    }

    cout << "Your hero grew from level 1 to level 10.\n";
    return 0;
}
