// learn-room-for.cpp — M5 Learn, the shape of a counting for-loop (twin).
// Excerpt source for the reading's first for-loop example (ADR-015). The loop
// sits at column 0 to mirror the fenced block byte-for-byte; it compiles clean.
#include <iostream>
using namespace std;

int main()
{
    {
for (int i = 0; i < 4; i++)
{
    cout << "Room " << i << "\n";
}
    }
    return 0;
}
