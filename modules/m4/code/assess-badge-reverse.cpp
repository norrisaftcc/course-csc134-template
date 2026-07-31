// assess-badge-reverse.cpp — M4 Assess lab, Badge item 1 (reverse recovery)
//
// The snippet the Badge asks students to read and turn back into a flowchart.
// Deliberately NOT the dungeon: recovering a diagram from code you have never
// seen is the skill, and a familiar gatekeeper would let a student answer from
// memory instead of from the code.
//
// Three outcomes, two decisions — so the recovered flowchart needs exactly two
// diamonds, which is what the Badge is checking.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o assess-badge-reverse assess-badge-reverse.cpp
#include <iostream>
using namespace std;

int main()
{
    int temp = 0;
    cin >> temp;
    if (temp >= 100)
        cout << "Boiling.\n";
    else if (temp <= 0)
        cout << "Freezing.\n";
    else
        cout << "Liquid.\n";

    return 0;
}
