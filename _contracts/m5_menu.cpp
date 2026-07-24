// m5_menu.cpp — CSC-134 M5 (Loops) canonical program
//
// CONTRACT (frozen). This is the professional menu pattern for CSC-134. M6
// refactors it into functions; M7 extends it. Do not edit without the
// spine-owner's sign-off and an ADR (see _contracts/README.md).
//
// THE M4->M5 SEAM. This program is the M4 gatekeeper that grew a loop. Same
// scenario, same gatekeeper, same decision logic — but now the door is a menu
// the player can return to, and every menu choice is bulletproofed against bad
// input. Read this next to m4_gatekeeper.cpp: the block marked "the M4
// gatekeeper core" is that program, dropped in as one menu action. The loop
// and the validation are the new M5 machinery.
//
// M5-level machinery: the do/while menu loop and the cin fail-state validation
// loop. Still single-file, main-only (pre-M6 convention) — no functions yet.
//
// Build: g++ -std=c++17 -Wall -Wextra -o m5_menu m5_menu.cpp

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "You stand before the dungeon door. A gatekeeper waits.\n";

    int choice = 0;

    // ===== STAGE 1: the menu loop — repeat until the player leaves =====
    do
    {
        cout << "\n==== THE DUNGEON DOOR ====\n";
        cout << "1) Approach the gate\n";
        cout << "2) Hear the gatekeeper's rules\n";
        cout << "3) Leave\n";
        cout << "Choose (1-3): ";

        // ===== STAGE 2: the validation loop (the M5 bulletproofing) =====
        // Keep asking until the player gives a real number, 1 through 3.
        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cin.clear();  // clear the fail flag if they typed letters
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // dump the bad line
            cout << "That is not a door. Choose 1, 2, or 3: ";
        }

        if (choice == 1)
        {
            // ===== the M4 gatekeeper core (from m4_gatekeeper.cpp) =====
            cout << "\nThe gatekeeper looks you over.\n";

            int characterClass = 0;   // 1 = Warrior, 2 = Mage, 3 = Rogue
            cout << "Your class? (1 = Warrior, 2 = Mage, 3 = Rogue): ";
            cin >> characterClass;

            switch (characterClass)
            {
                case 1:
                    cout << "\"A Warrior. Strong arms, I hope.\"\n";
                    break;
                case 2:
                    cout << "\"A Mage. Sharp mind, sharp robes.\"\n";
                    break;
                case 3:
                    cout << "\"A Rogue. Hands where I can see them.\"\n";
                    break;
                default:
                    cout << "\"I do not know that class. Come back when you do.\"\n";
                    continue;   // no early exit now — the loop lets them try again
            }

            int strength = 0;         // a whole number, 0 to 100
            cout << "Your strength score (0-100): ";
            cin >> strength;

            bool hasLockpick = false;
            if (characterClass == 3)
            {
                int answer = 0;       // 1 = yes, anything else = no
                cout << "\"Do you carry a lockpick? (1 = yes, 0 = no): \"";
                cin >> answer;
                hasLockpick = (answer == 1);
            }

            if (strength >= 70)
            {
                cout << "The gate swings wide. \"Strong enough. Go through.\"\n";
            }
            else if (strength >= 40 && hasLockpick)
            {
                cout << "\"Not strong — but those clever hands might do.\"\n";
                cout << "You pick the lock and slip inside.\n";
            }
            else if (strength >= 40)
            {
                cout << "\"Borderline. Answer my riddle and you may pass.\"\n";
            }
            else
            {
                cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n";
            }
            // ===== end M4 gatekeeper core =====
        }
        else if (choice == 2)
        {
            cout << "\n\"Strength 70 or more: you pass. 40 to 69: a riddle,\n";
            cout << " or a lockpick if you have the hands for it. Below 40: away.\"\n";
        }
        else  // choice == 3
        {
            cout << "\nYou step back from the door. The gatekeeper nods.\n";
        }

    } while (choice != 3);

    cout << "\nUntil next time, traveler.\n";
    return 0;
}
