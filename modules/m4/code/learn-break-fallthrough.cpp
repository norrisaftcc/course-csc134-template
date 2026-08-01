// learn-break-fallthrough.cpp — M4 Learn, the missing `break`
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: exactly one flaw — no `break` after case 1, so a Warrior
// falls through and is announced as a Mage as well.
//
// This file is NOT held to the zero-warning bar, and the marker above tells the
// compile gate so. On GCC (what Codespaces runs) it emits:
//     warning: this statement may fall through [-Wimplicit-fallthrough=]
// Apple clang stays silent, because it does not enable that warning under
// -Wall -Wextra — which is exactly why CI on GCC is the authority (ADR-014).
//
// Do not add the `break;`. Do not add [[fallthrough]]. The M4 reading quotes
// this switch as the planned error; "fixing" it destroys the example.
//
// Build (to see output): g++ -std=c++17 -o learn-break-fallthrough learn-break-fallthrough.cpp
// (the course flags are omitted on purpose here; see the marker above)
#include <iostream>
using namespace std;

int main()
{
    int characterClass = 1;           // 1 = Warrior, 2 = Mage, 3 = Rogue

    switch (characterClass)
    {
        case 1:
            cout << "\"A Warrior.\"\n";
            // BUG: no break here!
        case 2:
            cout << "\"A Mage.\"\n";
            break;
        case 3:
            cout << "\"A Rogue.\"\n";
            break;
        default:
            cout << "\"Speak plainly. What are you?\"\n";
    }

    return 0;
}
