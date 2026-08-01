// learn-logic-operators.cpp — M4 Learn, the three logic operators
// && (both must be true), || (either will do), ! (flip it) — one worked
// example of each, in one program, so the reading can quote all three.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-logic-operators learn-logic-operators.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 45;
    int characterClass = 2;           // 1 = Warrior, 2 = Mage, 3 = Rogue
    bool hasLockpick = true;
    bool isLocked = false;

    // Both must be true:
    if (strength >= 40 && hasLockpick)
    {
        cout << "Not strong, but those clever hands might do.\n";
    }

    // At least one is enough:
    if (characterClass == 1 || characterClass == 2)
    {
        cout << "Warrior or Mage — either way, she has heard of you.\n";
    }

    // Flip it — true when NOT locked:
    if (!isLocked)
    {
        cout << "The door gives when you push it.\n";
    }

    return 0;
}
