// apply-deliberate-break.cpp — M4 Apply, The Deliberate Break.
// Compiles with ZERO warnings on purpose: a mis-ordered ladder is a Logic error
// the compiler cannot see. Verbatim view of the tutorial edit (ADR-015).
#include <iostream>
using namespace std;

int main()
{
    int strength = 50;
    {
    // TEMPORARY — branches swapped on purpose
    if (strength >= 40)
    {
        cout << "\"Borderline. Answer me this and the gate is yours:\"\n";
        cout << "\"What must be broken before you can use it?\"\n";
        cout << "(Answer it in your head — the gate waits, half-open.)\n";
    }
    else if (strength >= 70)
    {
        cout << "The gate swings wide. \"Strong enough. Go through.\"\n";
    }
    }
    return 0;
}
