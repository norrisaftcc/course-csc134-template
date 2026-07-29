// learn-combine-ops.cpp — M4 Learn, combining conditions (&&, ||, !).
// Excerpt source for the reading's three one-line condition examples (ADR-015).
// The condition lines sit at column 0 to mirror the fenced block; each gets a
// trivial body (the reading elides them with // ...) so the file compiles clean.
#include <iostream>
using namespace std;

int main()
{
    int strength = 50;
    int characterClass = 1;
    bool hasLockpick = true;
    bool isLocked = false;
    {
// Both must be true:
if (strength >= 40 && hasLockpick)
    cout << "x\n";
// At least one is enough:
if (characterClass == 1 || characterClass == 2)
    cout << "x\n";
// Flip it — true when NOT locked:
if (!isLocked)
    cout << "x\n";
    }
    return 0;
}
