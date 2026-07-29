// practice-item1-levelup.cpp — M5 exit ticket, Item 1 (predict for-loop output)
// Build: g++ -std=c++17 -Wall -Wextra -o practice-item1-levelup practice-item1-levelup.cpp
#include <iostream>
using namespace std;

int main()
{
    for (int level = 1; level <= 3; level++)
    {
        cout << "Level " << level << ": ready\n";
    }
    return 0;
}
