// learn-firstfork.cpp — M4 Learn, the one-fork if / else (illustration twin).
// Excerpt source for the reading's first if/else example (ADR-015). The shown
// lines sit at column 0 to mirror the fenced block byte-for-byte; C++ ignores
// the indentation and this file compiles clean under -Wall -Wextra.
#include <iostream>
using namespace std;

int main()
{
    int strength = 0;
    cout << "Your strength score (0-100): ";
    cin >> strength;
    {
if (strength >= 70)
{
    cout << "The gate swings wide.\n";
}
else
{
    cout << "Turned away.\n";
}
    }
    return 0;
}
