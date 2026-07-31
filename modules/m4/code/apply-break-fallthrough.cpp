// apply-break-fallthrough.cpp — M4 Apply, Break It #3 (missing break)
//
// GATE: EXPECT-WARNING
//
// BROKEN ON PURPOSE: the tutorial has the student comment out one `break;` and
// run it. A Warrior is now announced as a Mage as well. On GCC:
//     warning: this statement may fall through [-Wimplicit-fallthrough=]
// Apple clang stays silent — it does not enable that warning under -Wall
// -Wextra — which is exactly why CI on GCC is the authority (ADR-014).
//
// Do not restore the `break;`. Do not add [[fallthrough]].
//
// Build (to see output): g++ -std=c++17 -o apply-break-fallthrough apply-break-fallthrough.cpp
// (the course flags are omitted on purpose here; see the marker above)
#include <iostream>
using namespace std;

int main()
{
    int characterClass = 1;

    switch (characterClass)
    {
        case 1:
            cout << "\"A Warrior. Strong arms, I hope.\"\n";
            // break;   <-- deliberately removed
        case 2:
            cout << "\"A Mage. Let us see if the mind is as sharp as the robes.\"\n";
            break;
        default:
            cout << "\"I do not know that class.\"\n";
    }

    return 0;
}
