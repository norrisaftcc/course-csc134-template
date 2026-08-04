// apply-gatekeeper-stage2.cpp — M4 Apply, Stage 2 (she asks your class: switch).
// The Stage 2 build, verbatim from the tutorial including its // NEW markers
// (inert comments) so the fenced block matches byte-for-byte (ADR-015).
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
