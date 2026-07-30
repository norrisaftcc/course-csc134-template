// learn-break-undeclared.cpp — M3 Learn, the planned first error
//
// GATE: EXPECT-ERROR
//
// BROKEN ON PURPOSE: exactly one flaw — `total` is used but never declared.
// The grammar is perfect; the meaning is impossible. That is a STATIC SEMANTIC
// error, caught at compile time. No program is produced.
//
// This file must FAIL to compile. The marker above is an assertion, not a mute.
#include <iostream>
using namespace std;

int main()
{
    int torches = 4;

    total = torches * 2;
    cout << "Total: " << total << '\n';

    return 0;
}
