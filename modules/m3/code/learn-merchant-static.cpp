// learn-merchant-static.cpp — M3 Learn, Stage A: variables, no input yet
//
// Everything is decided when the program is written. Run it a hundred times and
// it prints the same thing a hundred times — but the values now live in named
// boxes instead of being buried in the text.
//
// Pre-M6 form: everything in main, no functions.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string merchantName = "Bram";
    int torches = 12;
    double pricePerTorch = 2.50;

    cout << merchantName << " has " << torches << " torches.\n";
    cout << "Each one costs " << pricePerTorch << " gold.\n";

    return 0;
}
