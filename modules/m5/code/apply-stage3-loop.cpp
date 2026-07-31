// apply-stage3-loop.cpp — CSC-134 M5 (Loops) Apply, Part 1, STAGE 3
//
// Adds the counted for loop: ten levels, three stats each, one aligned row per level.
//
// A STAGE, not a draft: this compiles and runs on its own under the course
// flags. That is bar #9 — complexity accumulates visibly, and the student is
// never more than one stage away from a program that works.
//
// `// NEW` marks what this stage added to stage 2. Those markers are the
// tutorial's, and they are here so the printed listing and this file are the
// same text (ADR-015).
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o apply-stage3-loop apply-stage3-loop.cpp
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
