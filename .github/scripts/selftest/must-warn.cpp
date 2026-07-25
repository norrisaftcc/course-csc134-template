// must-warn.cpp — a fixture for the compile gate's self-test. NOT course material.
//
// This file is SUPPOSED to warn under `g++ -std=c++17 -Wall -Wextra` on GCC.
// The workflow compiles it and asserts the gate exits non-zero. If this file
// ever compiles clean, the gate has stopped enforcing and every green run
// since is unverified.
//
// Do not "fix" this file. Do not add it to a module. Do not add `break;`.
//
// Why it looks like course material: it deliberately mirrors the switch
// fall-through shape from M4, so that if GCC ever changes its mind about this
// diagnostic, the self-test goes red at the same moment the real gate would
// silently go blind. A fixture testing a different warning would not tell us that.
//
// See _lore/decisions/ADR-014-compile-gate-runs-on-gcc-in-ci.md

#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    cout << "Pick a door (1, 2): ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "The first door.\n";
            // no break, on purpose — this is the point of the fixture
        case 2:
            cout << "The second door.\n";
            break;
        default:
            cout << "No such door.\n";
    }

    return 0;
}
