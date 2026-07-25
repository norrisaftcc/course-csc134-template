// assess-game-starter.cpp — CSC-134 M5 (Loops) ASSESS starter scaffold
//
// STUDENT-FACING. This is the ~80% you finish for Project 2 (Part 2 of the M5
// lab). The menu loop and one working action are already here. Your job starts
// at the TODO markers. Full instructions: modules/m5/assess-lab.md.
//
// Rename your finished file to m5lab-game.cpp before you submit.
//
// Everything lives in main — no functions, no prototypes (those arrive in M6).
//
// Build: g++ -std=c++17 -Wall -Wextra -o m5lab-game assess-game-starter.cpp

#include <iostream>
#include <iomanip>
#include <limits>       // you will need this for the validation loop (C tier)
using namespace std;

int main()
{
    cout << "You duck into the Adventurer's Rest. The room is warm.\n";

    int choice = 0;

    // ===== The do/while menu loop (given) =====
    do
    {
        cout << "\n==== THE ADVENTURER'S REST ====\n";
        cout << "1) Read the bounty board\n";
        cout << "2) Talk to the barkeep\n";
        cout << "3) Leave\n";
        cout << "Choose (1-3): ";

        // TODO(C tier): this naive read is NOT bulletproof. Type a letter here
        // and cin drops into a fail state (a Runtime failure) — this menu then
        // spins forever, never reaching "Leave." Type 9 and nothing catches it.
        // Replace this one line with a validation loop that re-prompts until
        // choice is 1-3, using the cin.clear() + cin.ignore(...) pattern from
        // the Apply tutorial. That validation loop IS your C-tier deliverable.
        cin >> choice;

        if (choice == 1)
        {
            // The bounty board — a for-loop table. Given, so you start no
            // blanker than the Apply tutorial left you (this is the Level Up
            // Stats table, re-skinned as daily bounties).
            cout << "\n DAY   REWARD\n";
            for (int day = 1; day <= 10; day++)
            {
                int reward = 10 + day * 5;
                cout << setw(4) << day << setw(9) << reward << "\n";
            }
        }
        else if (choice == 2)
        {
            // TODO(B tier): the barkeep asks you a number (how much gold you
            // slide across the bar, say). Add a SECOND validated numeric read
            // here — the same bulletproof pattern you wrote for the menu.
            //
            // TODO(A tier): wrap an M4-style decision around that number so the
            // barkeep gives one of several replies (a generous tip, a fair tip,
            // an insult). That is the M5 seam: a loop wrapping a decision. Make
            // one broken answer `continue` back to the menu so the loop grants a
            // second try.
            cout << "\nThe barkeep nods. \"Nothing for you yet.\"\n";
        }
        else if (choice == 3)
        {
            cout << "\nYou step back into the night.\n";
        }

    } while (choice != 3);

    cout << "\nThe door swings shut behind you.\n";
    return 0;
}
