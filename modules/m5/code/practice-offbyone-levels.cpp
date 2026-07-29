// practice-offbyone-levels.cpp — M5 Practice, the Level 1..10 off-by-one.
// A whole program shown in the exit ticket. It compiles clean but prints only
// Level 1..9: `level < 10` should be `level <= 10`. A Logic error, on purpose.
#include <iostream>
using namespace std;

int main()
{
    // Wants to print Level 1 through Level 10:
    for (int level = 1; level < 10; level++)
    {
        cout << "Level " << level << "\n";
    }
    return 0;
}
