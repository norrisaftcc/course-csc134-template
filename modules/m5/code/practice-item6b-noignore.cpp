// practice-item6b-noignore.cpp — verification helper for Item 6 (NOT shown to students)
// Same validation loop as practice-item6-validation.cpp but with cin.ignore(...)
// deleted, keeping only cin.clear(). Purpose: prove the answer-key claim that
// clear() alone is not enough — on non-numeric input the bad character stays in
// the buffer, is re-read immediately, and the loop spins forever (Runtime).
// Run under a timeout; it never terminates on bad input.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item6b-noignore practice-item6b-noignore.cpp
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
        // cin.ignore(...) deleted on purpose — the bad character is never dumped
        cout << "That is not a door. Choose 1, 2, or 3: ";
    }
    cout << "You chose door " << choice << ".\n";
    return 0;
}
