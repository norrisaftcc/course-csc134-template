// learn-logic.cpp — M2 Learn, the Logic error demo
//
// NOT broken from the compiler's point of view: this file compiles clean with
// zero warnings and runs to completion. It is still wrong.
//
// The flaw is the ORDER. The door swings shut before you push it open, which is
// not the story anyone meant to tell. That is a LOGIC error: the program did what
// you said, not what you meant. No tool catches this one. Only a reader does.
#include <iostream>
using namespace std;

int main()
{
    cout << "You are standing at the dungeon door.\n";
    cout << "The door swings shut behind you.\n";
    cout << "You push it open.\n";
    return 0;
}
