// apply-break-and-validation.cpp — M5, the && validation trap
//
// BROKEN ON PURPOSE, and NOT marked EXPECT-WARNING — because there is nothing
// to warn about. This file compiles perfectly clean under -Wall -Wextra, and
// that is the entire lesson: `&&` where `||` belongs is invisible to the
// compiler, invisible on inspection, and only findable by running it.
//
// A number cannot be both less than 1 and greater than 3, so the condition is
// never true, the loop body never runs, and the program behaves exactly like
// the unguarded version. Type `banana` and it spins forever.
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
