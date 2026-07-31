// apply-break-assignment.cpp — M4 Apply, Break It #1 (= vs ==)
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: the tutorial has the student change ONE character in their
// working gatekeeper — `==` to `=` — and read what the compiler says. On GCC:
//     warning: suggest parentheses around assignment used as truth value [-Wparentheses]
// It still builds and runs, and now every hero passes. Do not "fix" this file.
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
