// practice-item7-hp.cpp — M4 Practice, Item 7 (hp status ladder).
// Excerpt source for the flowchart-match if / else-if / else chain (ADR-015).
// The chain sits at column 0 to mirror the fenced block byte-for-byte.
#include <iostream>
using namespace std;

int main()
{
    int hp = 0;
    cin >> hp;
    {
if (hp >= 50)
    cout << "Healthy\n";
else if (hp >= 20)
    cout << "Wounded\n";
else
    cout << "Critical\n";
    }
    return 0;
}
