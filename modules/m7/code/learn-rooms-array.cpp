// learn-rooms-array.cpp — M7 Learn, step 1: raw arrays
//
// One name, many values. The index is the position, not the value — the single
// most common confusion in this module.
//
// Full single-file form (M6 onward): prototypes, main, definitions.
#include <iostream>
using namespace std;

void describeDungeon(const int hazards[], int count);

int main()
{
    const int ROOM_COUNT = 3;
    int hazards[ROOM_COUNT] = {0, 2, 1};   // hazards in each room

    describeDungeon(hazards, ROOM_COUNT);
    return 0;
}

void describeDungeon(const int hazards[], int count)
{
    for (int i = 0; i < count; i++)
    {
        // i is WHERE we are. hazards[i] is WHAT is there.
        cout << "Room " << i << " holds " << hazards[i] << " hazards.\n";
    }
}
