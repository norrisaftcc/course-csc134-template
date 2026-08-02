// apply-break-c.cpp — M4 Apply, Optional Break C (deliberately broken).
// GATE: EXPECT-WARNING
// The removed break; lets case 1 fall into case 2 -> -Wimplicit-fallthrough.
// Verbatim view of the tutorial edit (ADR-015).
#include <iostream>
using namespace std;

int main()
{
    int characterClass = 1;
    switch (characterClass)
    {
    {
        case 1:
            cout << "\"A Warrior. Strong arms, I hope.\"\n";
            // break;   <-- deliberately removed
        case 2:
            cout << "\"A Mage.\"\n";
            break;
    }
    }
    return 0;
}
