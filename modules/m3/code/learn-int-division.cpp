// learn-int-division.cpp — M3 Learn, the integer-division trap
//
// Compiles clean, runs fine, prints an answer that is wrong by any human
// reckoning. Dividing an int by an int gives an int: the fraction is thrown
// away, not rounded. A LOGIC error the compiler cannot see.
//
// Pre-M6 form: everything in main, no functions.
#include <iostream>
using namespace std;

int main()
{
    int coins = 5;
    int heroes = 2;

    int eachInt = coins / heroes;                        // both int -> int result
    double eachReal = coins / (double)heroes;            // one is real -> real result

    cout << "Splitting " << coins << " coins between " << heroes << " heroes.\n";
    cout << "Integer division says: " << eachInt << '\n';
    cout << "Real division says:    " << eachReal << '\n';

    return 0;
}
