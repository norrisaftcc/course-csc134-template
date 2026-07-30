// learn-merchant-interactive.cpp — M3 Learn, Stage B: input -> process -> output
//
// The same program, now asking. This is the shape M0 named: inputs come in,
// something is worked out, an answer goes back out.
//
// Pre-M6 form: everything in main, no functions.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string merchantName = "Bram";
    double pricePerTorch = 2.50;

    int torches = 0;                       // INPUT
    cout << merchantName << ": How many torches do you want? ";
    cin >> torches;

    double total = torches * pricePerTorch;   // PROCESS

    cout << merchantName << ": That is " << total << " gold.\n";   // OUTPUT

    return 0;
}
