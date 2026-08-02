// apply-break-b.cpp — M4 Apply, Optional Break B (deliberately broken).
// GATE: EXPECT-WARNING
// Braces removed -> the else binds to the inner if -> -Wdangling-else.
// Verbatim view of the tutorial edit (ADR-015).
#include <iostream>
using namespace std;

int main()
{
    int strength = 50;
    {
    // TEMPORARY — braces removed on purpose
    if (strength >= 40)
        if (strength >= 70)
            cout << "The gate swings wide. \"Strong enough. Go through.\"\n";
    else
        cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n";
    }
    return 0;
}
