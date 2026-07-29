// learn-trap1-assign.cpp — M4 Learn Trap 1 (deliberately broken).
// GATE: EXPECT-WARNING
// '=' assigns instead of comparing -> -Wparentheses. The single shown line
// sits at column 0 to mirror the reading (ADR-015); the marker asserts the warning.
#include <iostream>
using namespace std;

int main()
{
    int strength = 0;
    {
if (strength = 70)   // BUG: this ASSIGNS 70 to strength, then the if is "true"
        cout << "forced in\n";
    }
    return 0;
}
