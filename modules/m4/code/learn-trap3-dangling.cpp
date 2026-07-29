// learn-trap3-dangling.cpp — M4 Learn Trap 3 (deliberately broken).
// GATE: EXPECT-WARNING
// The else looks outer but binds to the inner if -> -Wdangling-else. The block
// sits at column 0 to mirror the reading (ADR-015); the marker asserts the warning.
#include <iostream>
using namespace std;

int main()
{
    int strength = 50;
    bool hasLockpick = false;
    {
if (strength >= 40)
    if (hasLockpick)
        cout << "Clever hands.\n";
else                              // looks like it pairs with the OUTER if...
    cout << "Turned away.\n";     // ...but it actually pairs with the INNER if
    }
    return 0;
}
