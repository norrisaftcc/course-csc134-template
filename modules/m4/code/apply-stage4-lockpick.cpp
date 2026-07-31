// apply-stage4-lockpick.cpp — CSC-134 M4 (Decisions) Apply, STAGE 4
//
// Adds the Rogue's lockpick and the compound condition (&&) that uses it.
//
// A STAGE, not a draft: this compiles and runs on its own under the course
// flags. That is bar #9 — complexity accumulates visibly, and the student is
// never more than one stage away from a program that works. The finished
// program is apply-gatekeeper.cpp.
//
// `// NEW` marks only what THIS stage added. Earlier stages' lines carry no
// marker, exactly as the tutorial prints them. The markers live here so the
// printed listing and this file are the same text (ADR-015).
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o apply-stage4-lockpick apply-stage4-lockpick.cpp
#include <iostream>
using namespace std;

int main()
{
    // ===== STAGE 1: the gatekeeper greets you =====
    cout << "A gatekeeper blocks the dungeon door. She looks you over.\n";

    // ===== STAGE 2: she asks your class (switch) =====
    int characterClass = 0;   // 1 = Warrior, 2 = Mage, 3 = Rogue
    cout << "Your class? (1 = Warrior, 2 = Mage, 3 = Rogue): ";
    cin >> characterClass;

    switch (characterClass)
    {
        case 1:
            cout << "\"A Warrior. Strong arms, I hope.\"\n";
            break;
        case 2:
            cout << "\"A Mage. Let us see if the mind is as sharp as the robes.\"\n";
            break;
        case 3:
            cout << "\"A Rogue. Keep your hands where I can see them.\"\n";
            break;
        default:
            cout << "\"I do not know that class. Off you go.\"\n";
            cout << "The gate stays shut. (Unknown class.)\n";
            return 0;   // single pass — one bad answer ends the visit
    }

    // ===== STAGE 3: she measures your strength (if / else-if / else) =====
    int strength = 0;         // a whole number, 0 to 100
    cout << "Your strength score (0-100): ";
    cin >> strength;

    // ===== STAGE 4: a Rogue may carry a lockpick (compound condition) =====   // NEW
    bool hasLockpick = false;                                                   // NEW
    if (characterClass == 3)                                                    // NEW
    {                                                                           // NEW
        int answer = 0;       // 1 = yes, anything else = no                    // NEW
        cout << "\"A Rogue, hm. Do you carry a lockpick? (1 = yes, 0 = no): \""; // NEW
        cin >> answer;                                                          // NEW
        hasLockpick = (answer == 1);                                            // NEW
    }                                                                           // NEW

    if (strength >= 70)
    {
        cout << "The gate swings wide. \"Strong enough. Go through.\"\n";
    }
    else if (strength >= 40 && hasLockpick)                                     // NEW
    {                                                                           // NEW
        cout << "\"Not strong — but those clever hands might do.\"\n";          // NEW
        cout << "She looks away. You pick the lock and slip inside.\n";         // NEW
    }                                                                           // NEW
    else if (strength >= 40)
    {
        cout << "\"Borderline. Answer me this and the gate is yours:\"\n";
        cout << "\"What must be broken before you can use it?\"\n";
        cout << "(Answer it in your head — the gate waits, half-open.)\n";
    }
    else
    {
        cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n";
    }

    cout << "The visit ends.\n";
    return 0;
}
