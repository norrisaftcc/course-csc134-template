// apply-menu-scaffold.cpp — CSC-134 M5 (Loops) Apply, Part 2 (the 80% starter)
//
// THE SEAM. This is the M4 Dungeon Gatekeeper that grew a loop. The decision
// logic in the "M4 gatekeeper core" block below is the same program you built
// in M4 — dropped in here as ONE action inside a menu the player can return to.
// The do/while menu loop is the new M5 machinery; the loop wraps the decision,
// it does not replace it.
//
// This file compiles clean and runs AS-IS. But one piece is missing on purpose:
// the menu read is unguarded. Your job is to add the input-validation loop where
// the TODO says so. Everything else is done for you.
//
// Single-file, main-only (the pre-M6 convention) — no functions yet.
//
// Build: g++ -std=c++17 -Wall -Wextra -o apply-menu-scaffold apply-menu-scaffold.cpp

#include <iostream>
#include <limits>   // needed by the validation loop you will add (numeric_limits)
using namespace std;

int main()
{
    cout << "You stand before the dungeon door. A gatekeeper waits.\n";

    int choice = 0;

    // ===== THE MENU LOOP: repeat until the player leaves (choice 3) =====
    do
    {
        cout << "\n==== THE DUNGEON DOOR ====\n";
        cout << "1) Approach the gate\n";
        cout << "2) Hear the gatekeeper's rules\n";
        cout << "3) Leave\n";
        cout << "Choose (1-3): ";

        // ============================================================
        // YOUR CODE: the input-validation loop
        //
        // Spec: keep asking until the player gives a real number, 1-3.
        //   - If they type letters, cin enters a fail state. You must
        //     cin.clear() to drop the fail flag, THEN
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n') to throw
        //     away the bad line still sitting in the buffer. Both calls,
        //     in that order — clear the flag, then clear the text.
        //   - If they type a number outside 1-3, re-prompt too.
        //   - Re-prompt text: "That is not a door. Choose 1, 2, or 3: "
        //
        // Right now the read is UNGUARDED (the one line below). Replace it
        // with the validation loop. See the acceptance check in the tutorial.
        // ============================================================
        cin >> choice;   // STUB: unguarded read — no validation yet

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
