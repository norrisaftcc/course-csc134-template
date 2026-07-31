// learn-break-dangling-else.cpp — M4 Learn, the else that pairs with the wrong if
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: exactly one flaw — the indentation says the `else` belongs
// to the OUTER `if`, and C++ pairs it with the INNER one. Nothing here is a
// grammar mistake; the program means something other than it looks like.
//
// This file is NOT held to the zero-warning bar, and the marker above tells the
// compile gate so. On GCC (what Codespaces runs) it emits:
//     warning: suggest explicit braces to avoid ambiguous 'else' [-Wdangling-else]
// The program BUILDS and RUNS. A weak hero with no lockpick is told nothing at
// all — which is the Logic error the M4 reading is pointing at.
//
// Do not add the braces. Braces are the fix the reading asks the student to
// supply; adding them here deletes the example.
//
// Build (to see the warning): g++ -std=c++17 -Wall -Wextra -o learn-break-dangling-else learn-break-dangling-else.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 20;                // weak
    bool hasLockpick = false;         // and empty-handed

    if (strength >= 40)
        if (hasLockpick)
            cout << "Clever hands.\n";
    else                              // looks like it pairs with the OUTER if...
        cout << "Turned away.\n";     // ...but it actually pairs with the INNER if

    return 0;
}
