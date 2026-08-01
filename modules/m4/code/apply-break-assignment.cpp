// apply-break-assignment.cpp — M4 Apply, Break It #1 (= vs ==)
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: Break A has the student find their strength check
// `if (strength >= 70)` and delete the `>` — one character — so it reads
// `if (strength = 70)`. That assigns 70 and tests 70, which is always true.
//
// On GCC:
//     warning: suggest parentheses around assignment used as truth value [-Wparentheses]
// g++ still emits a binary, but the course's zero-warning rule treats a warning
// as a failed build, so the tutorial is right to say "it won't build." Both
// facts matter: the compiler saw it, and only the rule made anyone stop.
//
// Do not "fix" this file.
//
// Build (to see the warning): g++ -std=c++17 -Wall -Wextra -o apply-break-assignment apply-break-assignment.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 10;

    if (strength = 70)     // one character changed on purpose
    {
        cout << "The gate swings wide.\n";
    }

    return 0;
}
