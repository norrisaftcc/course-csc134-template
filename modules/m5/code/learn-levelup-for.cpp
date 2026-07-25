// learn-levelup-for.cpp — CSC-134 M5 (Loops) Learn beat
//
// The Level Up Stats table. A for loop runs levels 1 through 10; each level,
// it computes three stats from the level number and prints an aligned row.
// setw(n) from <iomanip> makes each column n characters wide.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-levelup-for learn-levelup-for.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(5) << "LVL" << setw(6) << "STR"
         << setw(6) << "DEX" << setw(6) << "INT" << "\n";

    for (int level = 1; level <= 10; level++)
    {
        int strength     = 10 + level * 2;   // grows by 2 each level
        int dexterity    =  8 + level * 3;   // grows by 3 each level
        int intelligence = 12 + level * 1;   // grows by 1 each level

        cout << setw(5) << level << setw(6) << strength
             << setw(6) << dexterity << setw(6) << intelligence << "\n";
    }

    return 0;
}
