// learn-value-vs-reference.cpp — M6 Learn, the predict moment
//
// Two functions that look almost identical. One takes a copy, one takes the
// variable itself. Only the second one can change what the caller holds.
//
// The whole difference is a single & in the parameter list.
#include <iostream>
using namespace std;

void addTenByValue(int hp);        // takes a COPY
void addTenByReference(int &hp);   // takes the VARIABLE ITSELF

int main()
{
    int heroHp = 50;

    addTenByValue(heroHp);
    cout << "After addTenByValue:     " << heroHp << '\n';

    addTenByReference(heroHp);
    cout << "After addTenByReference: " << heroHp << '\n';

    return 0;
}

void addTenByValue(int hp)
{
    hp = hp + 10;   // changes the copy, which is thrown away on return
}

void addTenByReference(int &hp)
{
    hp = hp + 10;   // changes the caller's variable
}
