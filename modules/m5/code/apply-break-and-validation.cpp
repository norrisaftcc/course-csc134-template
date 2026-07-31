// apply-break-and-validation.cpp — M5, the && validation trap
//
// BROKEN ON PURPOSE, and NOT marked EXPECT-WARNING — because there is nothing
// to warn about. This file compiles perfectly clean under -Wall -Wextra, and
// that is the entire lesson: `&&` where `||` belongs is invisible to the
// compiler, invisible on inspection, and only findable by running it.
//
// A number cannot be both less than 1 and greater than 3, so the condition is
// never true and the loop body never runs — the guard is decorative.
//
// WHAT THIS FILE DOES, exactly: feed it `banana` and it prints
//     Choose (1-3): You chose 0.
// and exits. The read fails, `choice` is left 0, the dead loop is skipped, and
// the program marches on with garbage. It does NOT spin here, because there is
// no outer loop to spin in.
//
// WHAT THE STUDENT SEES is worse, and is the reason this matters: in the Apply
// tutorial the same guard sits inside the menu's do/while. There, the failed
// read is never cleared, so every later read fails too and the menu redisplays
// forever. Same bug, same clean compile, louder symptom.
//
// The correct condition is in learn-validate.cpp and in the frozen contract
// (_contracts/m5_menu.cpp): `||`, because bad input is a failed read OR too
// small OR too big — any one is enough.
//
// Do not "fix" this file. The Apply tutorial's instructor note and the Assess
// lab's debugging guide both quote it as the single most common wrong answer.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o apply-break-and-validation apply-break-and-validation.cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int choice = 0;
    cout << "Choose (1-3): ";

    while (!(cin >> choice) && choice < 1 && choice > 3)   // WRONG — silently does nothing
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not one of the choices. Choose 1-3: ";
    }

    cout << "You chose " << choice << ".\n";
    return 0;
}
