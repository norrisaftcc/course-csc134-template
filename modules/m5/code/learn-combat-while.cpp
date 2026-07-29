// learn-combat-while.cpp — CSC-134 M5 (Loops) Learn beat
//
// A while loop: keep swinging until the monster drops. The condition is
// checked BEFORE every swing, and the body must move the loop toward its exit.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o learn-combat-while learn-combat-while.cpp

#include <iostream>
using namespace std;

int main()
{
    int monsterHp = 30;      // the monster starts at 30 HP
    int damage = 10;         // each hit takes 10 off

    while (monsterHp > 0)    // the condition: checked BEFORE every swing
    {
        cout << "You swing! The monster takes " << damage << " damage.\n";
        monsterHp = monsterHp - damage;   // the update: move toward the exit
        cout << "Monster HP is now " << monsterHp << ".\n";
    }

    cout << "The monster falls. Well fought.\n";
    return 0;
}
