// learn-trap2-fallthrough.cpp — M4 Learn Trap 2 (deliberately broken).
// GATE: EXPECT-WARNING
// case 1 has no break; and slides into case 2 -> -Wimplicit-fallthrough. The
// switch sits at column 0 to mirror the reading (ADR-015); the marker asserts it.
#include <iostream>
using namespace std;

int main()
{
    int characterClass = 1;
    {
switch (characterClass)
{
    case 1:
        cout << "\"A Warrior.\"\n";
        // BUG: no break here!
    case 2:
        cout << "\"A Mage.\"\n";
        break;
    default:
        cout << "\"Off you go.\"\n";
}
    }
    return 0;
}
