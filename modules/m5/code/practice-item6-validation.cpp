// practice-item6-validation.cpp — M5 exit ticket, Item 6 (the taught fix)
// The bulletproofed read from the M5 menu contract. BOTH calls are needed:
//   cin.clear()  turns the fail flag off so the stream can be read again;
//   cin.ignore(...) throws away the bad characters still sitting in the buffer.
// Remove either one and the loop spins forever. Item 6 asks the student to
// predict what removing cin.ignore(...) alone would do.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item6-validation practice-item6-validation.cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int choice = 0;
    cout << "Choose (1-3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a door. Choose 1, 2, or 3: ";
    }
    cout << "You chose door " << choice << ".\n";
    return 0;
}
