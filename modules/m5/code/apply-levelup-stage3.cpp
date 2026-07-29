// apply-levelup-stage3.cpp — M5 Apply, Stage 3 (the for-loop stat table).
// The Stage 3 build, verbatim from the tutorial including its // NEW markers
// (inert comments) so the fenced block matches byte-for-byte (ADR-015).
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";

    cout << setw(5) << "LVL"
         << setw(6) << "STR"
         << setw(6) << "DEX"
         << setw(6) << "INT" << "\n";

    // start at level 1, keep going while level <= 10, add one each pass  // NEW
    for (int level = 1; level <= 10; level++)                            // NEW
    {                                                                    // NEW
        int strength     = 10 + level * 2;                               // NEW
        int dexterity    =  8 + level * 3;                               // NEW
        int intelligence = 12 + level * 1;                               // NEW
                                                                         // NEW
        cout << setw(5) << level                                         // NEW
             << setw(6) << strength                                      // NEW
             << setw(6) << dexterity                                     // NEW
             << setw(6) << intelligence << "\n";                         // NEW
    }                                                                    // NEW

    return 0;
}
