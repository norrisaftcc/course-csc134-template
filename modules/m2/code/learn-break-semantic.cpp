// learn-break-semantic.cpp — M2 Learn, the Static semantic error demo
//
// GATE: EXPECT-ERROR
//
// BROKEN ON PURPOSE: exactly one flaw — `cuot` is not a name C++ knows. Every
// semicolon and brace is in the right place, so the grammar is fine; the meaning
// is impossible. That is a STATIC SEMANTIC error, and it is caught at compile
// time, not run time.
//
// This file must FAIL to compile. The marker above is an assertion, not a mute.
#include <iostream>
using namespace std;

int main()
{
    cuot << "You are standing at the dungeon door.\n";
    return 0;
}
