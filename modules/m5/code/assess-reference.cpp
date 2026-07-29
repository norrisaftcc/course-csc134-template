// assess-reference.cpp — CSC-134 M5 (Loops) ASSESS-beat reference solution
//
// ============================================================================
// INSTRUCTOR-FACING. NOT part of the student handout. Do NOT distribute this
// file to students. It is the grader's A-tier exemplar for assess-lab.md.
// ============================================================================
//
// This shows the full structure a finished A-tier game (Project 2) should
// reach: a do/while menu loop, a fully-validated menu read (type + range), a
// for-loop table, an array-search (loop + selection over a fixed sequence), a
// second validated read inside an action, and the M4->M5 SEAM made visible —
// an M4-style accept/counter/refuse decision wrapped INSIDE the menu loop, with
// `continue` sending the player back to try again (the loop did not replace the
// decision; it wrapped it). Gold persists across the whole menu loop.
//
// It is a RE-SKIN of the frozen _contracts/m5_menu.cpp shape (a wandering
// merchant instead of the dungeon gatekeeper's door) to prove the theme strips
// cleanly without touching the loop/validation structure. It deliberately does
// NOT reuse the gatekeeper scene or the Adventurer's Rest starter students work
// from — grading against a copy of either would teach nothing.
//
// M5 machinery ONLY: while / do-while / for, the cin fail-state validation
// idiom, a fixed-size array search. No functions or prototypes — everything
// lives in main (the pre-M6 single-file convention), however long.
//
// Built in stages; each stage compiles and runs on its own.
//
// Build: g++ -std=c++17 -Wall -Wextra -o assess-reference assess-reference.cpp

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    cout << "A merchant's cart creaks to a stop at the crossroads.\n";

    int gold = 40;          // persistent state — carried across every menu turn
    int choice = 0;

    // ===== STAGE 1: the do/while menu loop — repeat until the player leaves =====
    do
    {
        cout << "\n==== THE WANDERING MERCHANT ====\n";
        cout << "You carry " << gold << " gold.\n";
        cout << "1) Browse the price list\n";
        cout << "2) Haggle for a blade\n";
        cout << "3) Search your satchel\n";
        cout << "4) Leave\n";
        cout << "Choose (1-4): ";

        // ===== STAGE 2: the validation loop (type + range) =====
        // Keep asking until the player gives a real number, 1 through 4.
        while (!(cin >> choice) || choice < 1 || choice > 4)
        {
            cin.clear();  // drop the fail flag if they typed letters
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // dump the bad line
            cout << "That is not on the cart. Choose 1-4: ";
        }

        if (choice == 1)
        {
            // ===== STAGE 3: a for-loop table (counted iteration) =====
            cout << "\n LVL   PRICE\n";
            for (int lvl = 1; lvl <= 10; lvl++)
            {
                int price = 5 + lvl * 3;
                cout << setw(4) << lvl << setw(8) << price << "\n";
            }
        }
        else if (choice == 2)
        {
            // ===== STAGE 4: the SEAM — an M4 decision wrapped in the loop =====
            // A second validated read, then an accept/counter/refuse decision.
            // On a broken offer, `continue` returns to the menu — the loop is
            // what lets the player try again (where M4 would have just ended).
            int offer = 0;
            cout << "The blade is marked 30 gold. Your offer? (0-100): ";
            while (!(cin >> offer) || offer < 0 || offer > 100)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name an honest number (0-100): ";
            }

            if (offer > gold)
            {
                cout << "\"You cannot pay what you do not have.\"\n";
                continue;   // back to the menu — the loop grants a second try
            }

            if (offer >= 30)
            {
                cout << "\"Sold! A fine blade for a fair price.\"\n";
                gold -= offer;
            }
            else if (offer >= 20)
            {
                cout << "\"Ah, a haggler. Meet me at 25 and it is yours.\"\n";
            }
            else
            {
                cout << "\"An insult! Come back with real coin.\"\n";
            }
        }
        else if (choice == 3)
        {
            // ===== STAGE 5: array-search (loop + selection over a sequence) =====
            // A fixed-size, known sequence. A single pass looks for a match.
            int satchel[5] = {2, 9, 4, 7, 1};
            int target = 0;
            cout << "Which coin are you hunting for? (a number): ";
            while (!(cin >> target))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "A number, please: ";
            }

            bool found = false;
            int foundAt = -1;
            for (int i = 0; i < 5; i++)
            {
                if (satchel[i] == target)
                {
                    found = true;
                    foundAt = i;
                    break;   // stop at the first match
                }
            }

            if (found)
                cout << "Found it! A " << target << " coin sits in slot " << foundAt << ".\n";
            else
                cout << "You rummage, but no " << target << " coin is here.\n";
        }
        else  // choice == 4
        {
            cout << "\nThe merchant waves. \"Safe roads, traveler.\"\n";
        }

    } while (choice != 4);

    cout << "\nYou leave the crossroads with " << gold << " gold.\n";
    return 0;
}
