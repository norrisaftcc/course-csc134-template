// practice-item5-cinfail.cpp — M5 exit ticket, Item 5 (classify the cin fail-state)
// This is the PLANNED, celebrated first encounter, not a gotcha: the read is
// unguarded, so non-numeric input (the word "six") puts cin in a fail state.
// roll never changes and the stream never recovers, so the loop spins forever.
// That is a Runtime failure ("ran, then fell over"). M5 teaches the fix.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item5-cinfail practice-item5-cinfail.cpp
#include <iostream>
using namespace std;

int main()
{
    int roll = 0;
    while (roll != 6)
    {
        cout << "Roll a 6 to escape (enter a number): ";
        cin >> roll;
    }
    cout << "You escaped!\n";
    return 0;
}
