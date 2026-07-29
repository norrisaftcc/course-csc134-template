// practice-item7-search.cpp — M5 exit ticket, Item 7 (loop + selection over a sequence)
// A simple fixed-size search: walk the bag once, and if any slot matches the
// target, set a found flag. This is MLO 5.4 — combine a loop with a decision to
// process a sequence — kept to a plain fixed-size scan, not data-structure work.
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item7-search practice-item7-search.cpp
#include <iostream>
using namespace std;

int main()
{
    int potions[5] = {2, 5, 8, 11, 14};
    int target = 8;
    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (potions[i] == target)
        {
            found = true;
        }
    }

    if (found)
        cout << "Potion found in the bag.\n";
    else
        cout << "No such potion.\n";

    return 0;
}
