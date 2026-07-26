// GATE: EXPECT-ERROR
//
// Fixture for the compile gate's EXPECT-ERROR marker. Not teaching material.
// This file must FAIL to compile. `case 1;` uses a semicolon where C++ demands a
// colon — a Syntax error, in the course's four-word taxonomy.
//
// The gate should report this as `expect`, not as a failure.
#include <iostream>
using namespace std;

int main()
{
    int choice = 1;
    switch (choice)
    {
        case 1;
            cout << "unreachable\n";
    }
    return 0;
}
