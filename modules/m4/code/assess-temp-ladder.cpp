// assess-temp-ladder.cpp — M4 Assess, the if / else-if / else worked example.
// Excerpt source for the Badge-checklist listing (ADR-015). The block sits at
// column 0 to mirror the fenced code (which the renderer de-indents from the list).
#include <iostream>
using namespace std;

int main()
{
    {
int temp = 0;
cin >> temp;
if (temp >= 100)
    cout << "Boiling.\n";
else if (temp <= 0)
    cout << "Freezing.\n";
else
    cout << "Liquid.\n";
    }
    return 0;
}
