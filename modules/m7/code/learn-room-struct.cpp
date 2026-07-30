// learn-room-struct.cpp — M7 Learn, step 3: the parallel arrays collapse
//
// Same dungeon, same output. Three arrays became one, because a Room is one
// thing and now C++ knows it.
//
// Also step 4, in context: lightTorch takes Room& — a reference — so it can
// change the caller's room. Without the &, it would edit a copy and the
// dungeon would stay dark.
//
// Full single-file form (M6 onward): prototypes, main, definitions.
#include <iostream>
#include <string>
using namespace std;

struct Room
{
    string name;
    int hazards;
    bool lit;
};

void listRooms(const Room rooms[], int count);
void lightTorch(Room &room);

int main()
{
    const int ROOM_COUNT = 3;

    Room rooms[ROOM_COUNT] = {
        {"Entry Hall",    0, true},
        {"Flooded Vault", 2, false},
        {"Torch Room",    1, true}
    };

    listRooms(rooms, ROOM_COUNT);

    cout << "\nYou strike a torch in the vault.\n\n";
    lightTorch(rooms[1]);

    listRooms(rooms, ROOM_COUNT);
    return 0;
}

void listRooms(const Room rooms[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << rooms[i].name << ": " << rooms[i].hazards << " hazards, "
             << (rooms[i].lit ? "lit" : "dark") << ".\n";
    }
}

void lightTorch(Room &room)
{
    room.lit = true;
}
