// practice-item5-fallthrough.cpp — M4 Practice exit ticket, Item 5 (classify-the-error)
// BROKEN ON PURPOSE: exactly one flaw — a missing `break` after case 1, so case 1
// falls through into case 2. It compiles and runs; it just does the wrong thing.
// The compiler may print a helpful fall-through warning, but this is still a program
// that builds and runs, then produces output the author did not want (Logic error).
// Build (to see output): g++ -std=c++17 -o practice-item5-fallthrough practice-item5-fallthrough.cpp
#include <iostream>
using namespace std;

int main()
{
    int potion = 1;   // author wants ONLY the red-potion line to print

    switch (potion)
    {
        case 1:
            cout << "Red potion: +10 health.\n";
        case 2:
            cout << "Blue potion: +10 mana.\n";
            break;
        default:
            cout << "No potion.\n";
    }

    return 0;
}
