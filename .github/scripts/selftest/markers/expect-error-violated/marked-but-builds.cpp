// GATE: EXPECT-ERROR
//
// Fixture for the INVERSE assertion. Not teaching material.
// This file claims it must fail to compile, and then compiles perfectly.
// The gate must FAIL on it.
//
// This is the case that matters. An artifact marked broken-on-purpose that has
// quietly started working has stopped demonstrating the thing it exists for, and
// nothing about the output looks wrong — success and "never checked" are the same
// colour. That is the F-009 shape, and it is why the marker is an assertion
// rather than a mute.
#include <iostream>
using namespace std;

int main()
{
    cout << "I build cleanly, and I should not.\n";
    return 0;
}
