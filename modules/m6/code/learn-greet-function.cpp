// learn-greet-function.cpp — M6 Learn, the full single-file form
//
// The shape every program takes from M6 onward:
//   1. prototypes at the top   — the promises
//   2. main in the middle      — the story
//   3. definitions at the bottom — the details
//
// Before M6 everything lived in main. This is the completed convention.
#include <iostream>
#include <string>
using namespace std;

// ===== 1. PROTOTYPES — what exists, and what it needs =====
void greet(string name);
int doubled(int value);

int main()
{
    // ===== 2. MAIN — reads like a summary, not a transcript =====
    greet("Bram");

    int torches = 6;
    cout << "Twice " << torches << " is " << doubled(torches) << ".\n";

    return 0;
}

// ===== 3. DEFINITIONS — how each promise is kept =====
void greet(string name)
{
    cout << "Well met, " << name << ".\n";
}

int doubled(int value)
{
    return value * 2;
}
