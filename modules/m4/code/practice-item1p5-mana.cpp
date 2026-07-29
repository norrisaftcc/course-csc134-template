// practice-item1p5-mana.cpp — M4 Practice, Item 1.5 (spell by mana).
// A two-branch if / else-if the reading shows in full. No trailing else, on
// purpose: below 20 mana, nothing prints. Compiles clean under -Wall -Wextra.
#include <iostream>
using namespace std;

int main()
{
    int mana = 30;

    if (mana >= 50)
        cout << "You cast the great spell.\n";
    else if (mana >= 20)
        cout << "You cast a minor spell.\n";

    return 0;
}
