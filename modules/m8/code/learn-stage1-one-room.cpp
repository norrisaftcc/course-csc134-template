// M8 Learn — staged build, STAGE 1: one room, printed.
// Compiles and runs on its own. Nothing here is placeholder.
#include <iostream>
#include <string>
using namespace std;

void describeRoom(string name, int hazards);

int main()
{
    describeRoom("The Damp Corridor", 2);
    return 0;
}

void describeRoom(string name, int hazards)
{
    cout << "== " << name << " ==\n";
    cout << "Hazards here: " << hazards << "\n";
}
