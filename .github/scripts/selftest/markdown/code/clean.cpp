// clean.cpp — fixture for the Markdown block gate self-test.
// Not teaching material. This file exists so the gate can prove, on every run,
// that it still matches what matches and still fails what should fail.
#include <iostream>
using namespace std;

int main()
{
    int strength = 0;
    cout << "Your strength score (0-100): ";
    cin >> strength;

    if (strength >= 70)
    {
        cout << "The gate swings wide.\n";
    }
    else
    {
        cout << "Turned away.\n";
    }

    return 0;
}
