// practice-item3-offbyone.cpp — M5 exit ticket, Item 3 (spot the off-by-one)
// The author wants all 10 levels (Level 1 through Level 10). This prints 1..9.
// One flaw: the condition should be level <= 10, not level < 10. (Logic error.)
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item3-offbyone practice-item3-offbyone.cpp
#include <iostream>
using namespace std;

int main()
{
    for (int level = 1; level < 10; level++)
    {
        cout << "Level " << level << "\n";
    }
    return 0;
}
