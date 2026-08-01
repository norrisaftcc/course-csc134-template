// M8 Learn — staged build, STAGE 2: three rooms in an array, and a total.
// Stage 1's behaviour is still here. This one also compiles and runs on its own.
#include <iostream>
#include <string>
using namespace std;

struct Room
{
    string name;
    int hazards;
};

void describeRoom(Room room);

int main()
{
    Room dungeon[3] = {
        {"The Damp Corridor", 2},
        {"The Collapsed Stair", 1},
        {"The Gatekeeper's Hall", 4}
    };

    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        describeRoom(dungeon[i]);
        total += dungeon[i].hazards;
    }

    cout << "Hazards in the whole dungeon: " << total << "\n";
    return 0;
}

void describeRoom(Room room)
{
    cout << "== " << room.name << " ==\n";
    cout << "Hazards here: " << room.hazards << "\n";
}
