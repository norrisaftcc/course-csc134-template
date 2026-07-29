// learn-menu-dowhile.cpp — CSC-134 M5 (Loops) Learn beat
//
// THE M4->M5 SEAM. This is the M4 gatekeeper decision, dropped in as ONE menu
// action. The do/while loop runs the menu at least once, then keeps redisplaying
// it until the player leaves. The loop did not replace the decision — it wrapped
// it. (Trusting input here on purpose: type a letter and watch it misbehave.
// The next reading section, learn-validate.cpp, bulletproofs exactly this.)
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-menu-dowhile learn-menu-dowhile.cpp

#include <iostream>
using namespace std;

int main()
{
    int choice = 0;

    do
    {
        cout << "\n==== THE DUNGEON DOOR ====\n";
        cout << "1) Approach the gate\n";
        cout << "2) Leave\n";
        cout << "Choose (1-2): ";
        cin >> choice;

        if (choice == 1)
        {
            // ===== the M4 decision core, as one menu action =====
            int strength = 0;
            cout << "Your strength (0-100): ";
            cin >> strength;

            if (strength >= 70)
            {
                cout << "The gate swings wide. Go through.\n";
            }
            else
            {
                cout << "Turned away. Try again from the menu.\n";
            }
        }

    } while (choice != 2);   // <-- note the semicolon after do-while

    cout << "Until next time, traveler.\n";
    return 0;
}
