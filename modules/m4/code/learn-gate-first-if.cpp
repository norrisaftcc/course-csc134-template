// learn-gate-first-if.cpp — M4 Learn, the first decision
// Two branches and nothing else: the smallest complete if/else in the course.
// The M4 reading quotes the if/else itself as its opening example.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-gate-first-if learn-gate-first-if.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 0;                 // a whole number, 0 to 100
    cout << "Your strength score (0-100): ";
    cin >> strength;

    if (strength >= 70)
    {
        cout << "The gate swings wide.\n";
    }
    else
    {
        cout << "Turned away.\n";
    }

    return 0;
}
