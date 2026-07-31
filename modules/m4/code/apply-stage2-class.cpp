// apply-stage2-class.cpp — CSC-134 M4 (Decisions) Apply, STAGE 2
//
// Adds the switch on character class, with a default that ends the visit.
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
// Build: g++ -std=c++17 -Wall -Wextra -o apply-stage2-class apply-stage2-class.cpp
#include <iostream>
using namespace std;

int main()
{
    // ===== STAGE 1: the gatekeeper greets you =====
    cout << "A gatekeeper blocks the dungeon door. She looks you over.\n";

    // ===== STAGE 2: she asks your class (switch) =====        // NEW
    int characterClass = 0;   // 1 = Warrior, 2 = Mage, 3 = Rogue   // NEW
    cout << "Your class? (1 = Warrior, 2 = Mage, 3 = Rogue): ";   // NEW
    cin >> characterClass;                                        // NEW
                                                                  // NEW
    switch (characterClass)                                       // NEW
    {                                                             // NEW
        case 1:                                                   // NEW
            cout << "\"A Warrior. Strong arms, I hope.\"\n";      // NEW
            break;                                                // NEW
        case 2:                                                   // NEW
            cout << "\"A Mage. Let us see if the mind is as sharp as the robes.\"\n";  // NEW
            break;                                                // NEW
        case 3:                                                   // NEW
            cout << "\"A Rogue. Keep your hands where I can see them.\"\n";  // NEW
            break;                                                // NEW
        default:                                                  // NEW
            cout << "\"I do not know that class. Off you go.\"\n"; // NEW
            cout << "The gate stays shut. (Unknown class.)\n";    // NEW
            return 0;   // single pass — one bad answer ends the visit  // NEW
    }                                                             // NEW

    return 0;
}
