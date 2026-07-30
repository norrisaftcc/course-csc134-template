// learn-read-choice.cpp — M6 Learn, the refactor payoff
//
// The validation loop from _contracts/m5_menu.cpp, lifted out of main and given
// a name. Same machinery — but main no longer has to show it, and any other
// prompt can reuse it.
//
// Note what extraction forced: M5's retry line said "That is not a door." That
// was fine inside a door menu and wrong the moment this became reusable, so the
// message had to lose the door. Pulling code out often reveals which parts of it
// were really about the caller.
//
// This is MLO 6.3 in miniature: refactor without changing behaviour.
#include <iostream>
#include <limits>
using namespace std;

int readChoice(int low, int high);

int main()
{
    cout << "==== THE DUNGEON DOOR ====\n";
    cout << "1) Approach the gate\n";
    cout << "2) Hear the rules\n";
    cout << "3) Leave\n";

    int choice = readChoice(1, 3);

    cout << "You chose " << choice << ".\n";
    return 0;
}

// Keep asking until the answer is a real number in range.
// Lifted verbatim in spirit from the M5 contract's validation loop.
int readChoice(int low, int high)
{
    int value = 0;
    cout << "Choose (" << low << "-" << high << "): ";

    while (!(cin >> value) || value < low || value > high)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Not one of the choices. Choose " << low << "-" << high << ": ";
    }

    return value;
}
