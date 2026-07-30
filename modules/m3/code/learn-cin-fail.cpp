// learn-cin-fail.cpp — M3 Learn, the Runtime error M2 promised
//
// Compiles clean and runs to completion. If the user types a WORD where a number
// was expected, cin fails, `torches` is left at 0, and every later calculation is
// quietly built on that 0. The program does not crash. It lies.
//
// This is the RUNTIME case M2's reading named but could not demonstrate: it needs
// cin, which M3 is the first module to have. Guarding it (cin.clear() + ignore) is
// M5's job — here we only look at the failure honestly.
//
// Pre-M6 form: everything in main, no functions.
#include <iostream>
using namespace std;

int main()
{
    int torches = 0;
    cout << "How many torches? ";
    cin >> torches;

    double total = torches * 2.50;

    cout << "You asked for " << torches << " torches.\n";
    cout << "That comes to " << total << " gold.\n";

    return 0;
}
