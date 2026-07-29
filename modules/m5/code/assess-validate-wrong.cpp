// assess-validate-wrong.cpp — M5 Assess, the WRONG validation loop (twin).
// Compiles clean but the compound guard is never true, so the loop is skipped.
// A Logic error, shown so students can name why it silently does nothing.
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    {
while (!(cin >> choice) && choice < 1 && choice > 3)   // WRONG — silently does nothing
    {
    }
    }
    return 0;
}
