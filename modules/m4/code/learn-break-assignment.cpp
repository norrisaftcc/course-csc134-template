// learn-break-assignment.cpp — M4 Learn, the = vs == trap
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: exactly one flaw — `if (strength = 70)` ASSIGNS 70 to
// strength and then tests 70, which is always true. One character away from
// `==`, and the gate opens for everybody.
//
// This file is NOT held to the zero-warning bar, and the marker above tells the
// compile gate so. On GCC (what Codespaces runs) it emits:
//     warning: suggest parentheses around assignment used as truth value [-Wparentheses]
// The program still BUILDS and RUNS. That is the point: a warning does not stop
// a build, so the wrong program ships unless somebody reads the warning.
//
// Do not "fix" this file. The M4 reading quotes it as the planned error.
//
// Build (to see the warning): g++ -std=c++17 -Wall -Wextra -o learn-break-assignment learn-break-assignment.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 10;                // far too weak to pass

    if (strength = 70)   // BUG: this ASSIGNS 70 to strength, then the if is "true"
    {
        cout << "The gate swings wide.\n";
    }

    return 0;
}
