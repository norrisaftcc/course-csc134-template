// apply-validate-wrong.cpp — M5 Apply, the tempting-but-WRONG validation loop.
// Compiles clean: `choice < 1 && choice > 3` can never both hold, so the guard
// is always false and the loop never runs. A Logic error the compiler cannot see.
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    {
        while (!(cin >> choice) && choice < 1 && choice > 3)   // WRONG
        {
        }
    }
    return 0;
}
