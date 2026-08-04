// apply-levelup-stage2.cpp — M5 Apply, Stage 2 (aligned columns with setw).
// The Stage 2 build, verbatim from the tutorial including its // NEW markers
// (inert comments) so the fenced block matches byte-for-byte (ADR-015).
#include <iostream>
#include <iomanip>                          // NEW — setw lives here
using namespace std;

int main()
{
    cout << "==== LEVEL UP STATS ====\n";

    cout << setw(5) << "LVL"                // NEW
         << setw(6) << "STR"                // NEW
         << setw(6) << "DEX"                // NEW
         << setw(6) << "INT" << "\n";       // NEW

    return 0;
}
