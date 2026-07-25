// practice-menu.cpp — M5 exit ticket, Item 4 (trace the do/while menu)
// THE M4->M5 SEAM, shrunk for reading: a decision (which action to run) now
// lives INSIDE a do/while loop that keeps bringing the player back to the door.
// The loop did not replace the decision — it wrapped it.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-menu practice-menu.cpp
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    do
    {
        cout << "==== THE DUNGEON DOOR ====\n";
        cout << "1) Approach the gate\n";
        cout << "2) Hear the rules\n";
        cout << "3) Leave\n";
        cout << "Choose (1-3): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "The gatekeeper looks you over.\n";
        }
        else if (choice == 2)
        {
            cout << "\"Strength 70 or more and you pass.\"\n";
        }
        else if (choice == 3)
        {
            cout << "You step back from the door.\n";
        }
    } while (choice != 3);

    cout << "Until next time, traveler.\n";
    return 0;
}
