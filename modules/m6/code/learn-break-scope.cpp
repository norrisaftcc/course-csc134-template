// learn-break-scope.cpp — M6 Learn, the planned error: scope
//
// GATE: EXPECT-ERROR
//
// BROKEN ON PURPOSE: exactly one flaw — announce() reaches for `torches`, which
// is a local variable of main. Functions cannot see each other's locals. The
// grammar is fine; the meaning is impossible.
//
// STATIC SEMANTIC error, caught at compile time. The fix is to pass the value
// in as a parameter — which is the entire reason parameters exist.
//
// This file must FAIL to compile. The marker above is an assertion, not a mute.
#include <iostream>
using namespace std;

void announce();

int main()
{
    int torches = 6;
    announce();
    return 0;
}

void announce()
{
    cout << "You are carrying " << torches << " torches.\n";
}
