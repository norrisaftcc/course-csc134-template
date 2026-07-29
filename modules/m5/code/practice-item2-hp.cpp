// practice-item2-hp.cpp — M5 exit ticket, Item 2 (trace a while loop)
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item2-hp practice-item2-hp.cpp
#include <iostream>
using namespace std;

int main()
{
    int hp = 5;
    while (hp > 0)
    {
        cout << "HP: " << hp << "\n";
        hp = hp - 2;
    }
    cout << "You collapse.\n";
    return 0;
}
