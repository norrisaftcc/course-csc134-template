// learn-square.cpp — CSC-134 M5 (Loops) Learn beat
//
// The turtle's square, now in C++. Four identical moves: the body is what
// repeats, the count says how many times. This is exactly what a for loop is
// for — a known number of reps that knows which rep it's on.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-square learn-square.cpp

#include <iostream>
using namespace std;

int main()
{
    // start at side 1, keep going while side <= 4, add 1 each time
    for (int side = 1; side <= 4; side++)
    {
        cout << "Side " << side << ": walk forward, then turn right.\n";
    }

    cout << "Back where you started. The square is closed.\n";
    return 0;
}
