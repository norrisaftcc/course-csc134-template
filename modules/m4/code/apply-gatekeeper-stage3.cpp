// apply-gatekeeper-stage3.cpp — M4 Apply, Stage 3 (strength ladder).
// The Stage 3 build (Stages 1-2 above, then the if/else-if/else ladder).
// The ladder tail is a verbatim view of the tutorial block (ADR-015).
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

    // ===== STAGE 3: she measures your strength (if / else-if / else) =====   // NEW
    int strength = 0;         // a whole number, 0 to 100                       // NEW
    cout << "Your strength score (0-100): ";                                    // NEW
    cin >> strength;                                                            // NEW
                                                                                // NEW
    if (strength >= 70)                                                         // NEW
    {                                                                           // NEW
        cout << "The gate swings wide. \"Strong enough. Go through.\"\n";       // NEW
    }                                                                           // NEW
    else if (strength >= 40)                                                    // NEW
    {                                                                           // NEW
        cout << "\"Borderline. Answer me this and the gate is yours:\"\n";      // NEW
        cout << "\"What must be broken before you can use it?\"\n";             // NEW
        cout << "(Answer it in your head — the gate waits, half-open.)\n";      // NEW
    }                                                                           // NEW
    else                                                                        // NEW
    {                                                                           // NEW
        cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n"; // NEW
    }                                                                           // NEW
                                                                                // NEW
    cout << "The visit ends.\n";                                                // NEW
    return 0;
}
