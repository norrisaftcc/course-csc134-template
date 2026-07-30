// learn-check-rooms.cpp — CSC-134 M5 (Loops) Learn beat, Check Yourself #1
//
// Predict-the-output fragment: how many times does the body run, and what
// does it print? Counting from 0 with a < test is the shape students meet
// everywhere, and it is where the off-by-one lives.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-check-rooms learn-check-rooms.cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Room " << i << "\n";
    }
    return 0;
}
