// learn-validate.cpp — CSC-134 M5 (Loops) Learn beat
//
// The loop-and-validate pattern: keep asking until the input is really a number
// in range. This is the exact validation loop from the frozen contract
// (_contracts/m5_menu.cpp) — the piece the Apply tutorial hands you 80% built
// and asks you to finish.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-validate learn-validate.cpp

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int choice = 0;
    cout << "Choose a door (1-3): ";

    // Keep asking while EITHER the read fails OR the number is out of range.
    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cin.clear();  // step 1: turn OFF the fail flag so cin can read again
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // step 2: dump the bad line
        cout << "That is not a door. Choose 1, 2, or 3: ";
    }

    cout << "You chose door " << choice << ".\n";
    return 0;
}
