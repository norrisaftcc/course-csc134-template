// apply-break-a.cpp — M4 Apply, Optional Break A (deliberately broken).
// GATE: EXPECT-WARNING
// '=' instead of '==' -> -Wparentheses. Verbatim view of the tutorial edit (ADR-015).
#include <iostream>
using namespace std;

int main()
{
    int strength = 0;
    {
    if (strength = 70)     // one character changed on purpose
        cout << "forced in\n";
    }
    return 0;
}
