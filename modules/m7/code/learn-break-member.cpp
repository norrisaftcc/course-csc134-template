// learn-break-member.cpp — M7 Learn, the planned error: a member that is not there
//
// GATE: EXPECT-ERROR
//
// BROKEN ON PURPOSE: exactly one flaw — Room has no member called `torches`.
// The struct declares name, hazards, and lit. Asking for anything else is a
// well-formed sentence about something that does not exist.
//
// STATIC SEMANTIC error, caught at compile time. The compiler even lists the
// members it does know about, which is the fastest way to spot a typo.
//
// This file must FAIL to compile. The marker above is an assertion, not a mute.
#include <iostream>
#include <string>
using namespace std;

struct Room
{
    string name;
    int hazards;
    bool lit;
};

int main()
{
    Room entry = {"Entry Hall", 0, true};

    cout << entry.torches << '\n';

    return 0;
}
