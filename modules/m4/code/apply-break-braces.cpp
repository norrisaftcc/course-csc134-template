// apply-break-braces.cpp — M4 Apply, Break It #2 (braces removed)
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: the tutorial has the student delete the braces from a
// working if/else and see what the `else` attaches to. The indentation says the
// OUTER if; C++ says the INNER one. On GCC:
//     warning: suggest explicit braces to avoid ambiguous 'else' [-Wdangling-else]
// It builds and runs, and a weak hero is told nothing at all.
//
// Do not add the braces back. Braces are the fix the tutorial asks the student
// to supply; adding them here deletes the exercise.
//
// Build (to see the warning): g++ -std=c++17 -Wall -Wextra -o apply-break-braces apply-break-braces.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 20;

    // TEMPORARY — braces removed on purpose
    if (strength >= 40)
        if (strength >= 70)
            cout << "The gate swings wide. \"Strong enough. Go through.\"\n";
    else
        cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n";

    return 0;
}
