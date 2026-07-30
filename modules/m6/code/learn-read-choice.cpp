// learn-read-choice.cpp — M6 Learn, the refactor payoff
//
// The validation loop from _contracts/m5_menu.cpp, lifted out of main and given
// a name. Same behaviour, same machinery — but main no longer has to show it,
// and any other prompt in the program can reuse it.
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
        cout << "That is not a door. Choose " << low << "-" << high << ": ";
    }

    return value;
}
