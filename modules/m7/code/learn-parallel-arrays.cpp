// learn-parallel-arrays.cpp — M7 Learn, step 2: parallel arrays
//
// DELIBERATE STEPPING STONE. This works, and it is not where we stop.
// Three arrays describe one thing. Room 2's name, hazard count, and lit-ness
// live in three separate places, held together only by everyone agreeing to
// use the same index.
//
// FUTURE REFACTOR: these three collapse into one array of structs in
// learn-room-struct.cpp. Read them side by side.
//
// Full single-file form (M6 onward): prototypes, main, definitions.
#include <iostream>
#include <string>
using namespace std;

void listRooms(const string names[], const int hazards[], const bool lit[], int count);

int main()
{
    const int ROOM_COUNT = 3;

    string names[ROOM_COUNT]  = {"Entry Hall", "Flooded Vault", "Torch Room"};
    int    hazards[ROOM_COUNT] = {0, 2, 1};
    bool   lit[ROOM_COUNT]     = {true, false, true};

    listRooms(names, hazards, lit, ROOM_COUNT);
    return 0;
}

void listRooms(const string names[], const int hazards[], const bool lit[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << names[i] << ": " << hazards[i] << " hazards, "
             << (lit[i] ? "lit" : "dark") << ".\n";
    }
}
