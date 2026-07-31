// apply-break-swapped.cpp — M4 Apply, Break It #4 (branches out of order)
//
// BROKEN ON PURPOSE, and NOT marked EXPECT-WARNING — because there is nothing
// to warn about. This compiles perfectly clean under -Wall -Wextra, and that is
// the entire lesson: order is meaning in an if/else-if ladder, and the compiler
// has no opinion about it.
//
// The >= 40 test now comes first, so it catches every hero at 40 or above. The
// >= 70 branch below it can never run. A strength-90 hero is told they are
// "borderline". The program is wrong and nothing but running it will say so —
// a Logic error, the fourth of the course's four words.
//
// Do not reorder these branches. The tutorial asks the student to find this by
// testing, not by reading.
//
// Build: g++ -std=c++17 -Wall -Wextra -o apply-break-swapped apply-break-swapped.cpp
#include <iostream>
using namespace std;

int main()
{
    int strength = 90;   // clearly strong enough — watch what she says

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
    else
    {
        cout << "\"Too weak, and no trick to make up for it. Turned away.\"\n";
    }

    return 0;
}
