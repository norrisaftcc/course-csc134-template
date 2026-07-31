// apply-stage2-headers.cpp — CSC-134 M5 (Loops) Apply, Part 1, STAGE 2
//
// Adds <iomanip> and the setw() column headers. Still no loop.
//
// A STAGE, not a draft: this compiles and runs on its own under the course
// flags. That is bar #9 — complexity accumulates visibly, and the student is
// never more than one stage away from a program that works.
//
// `// NEW` marks what this stage added to stage 1. Those markers are the
// tutorial's, and they are here so the printed listing and this file are the
// same text (ADR-015).
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o apply-stage2-headers apply-stage2-headers.cpp
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
