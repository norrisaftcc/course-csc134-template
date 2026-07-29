// practice-item1_5-mana.cpp — M4 Practice exit ticket, Item 1.5 (trace-the-branch)
// Single-file, main-only (pre-M6 convention). No functions, no prototypes.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item1_5-mana practice-item1_5-mana.cpp
//
// The bridge between Item 1 (one if / one else) and the fuller chains later in
// the ticket: a second check sits in the middle. With mana = 30 the first
// condition is false and the second is true, so exactly one line prints.
//
// Note there is no final `else`. If mana were below 20, nothing would print at
// all — which is a real outcome, not a bug, and worth noticing.
#include <iostream>
using namespace std;

int main()
{
    int mana = 30;

    if (mana >= 50)
        cout << "You cast the great spell.\n";
    else if (mana >= 20)
        cout << "You cast a minor spell.\n";

    return 0;
}
