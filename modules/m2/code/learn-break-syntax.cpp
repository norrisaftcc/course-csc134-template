// learn-break-syntax.cpp — M2 Learn, the Syntax error demo
//
// GATE: EXPECT-ERROR
//
// BROKEN ON PURPOSE: exactly one flaw — the semicolon after the first cout is
// missing. This is a SYNTAX error: it broke the grammar, so the compiler cannot
// even finish reading the file. Nothing runs. There is no program to run.
//
// This file must FAIL to compile. The marker above is an assertion, not a mute:
// if it ever starts building, it has stopped demonstrating a Syntax error and
// the gate fails.
#include <iostream>
using namespace std;

int main()
{
    cout << "You are standing at the dungeon door.\n"
    cout << "You push it open.\n";
    return 0;
}
