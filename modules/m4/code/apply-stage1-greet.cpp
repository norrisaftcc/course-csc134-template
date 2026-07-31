// apply-stage1-greet.cpp — CSC-134 M4 (Decisions) Apply, STAGE 1
//
// She greets you. One line of output — the smallest thing that runs.
//
// A STAGE, not a draft: this compiles and runs on its own under the course
// flags. That is bar #9 — complexity accumulates visibly, and the student is
// never more than one stage away from a program that works. The finished
// program is apply-gatekeeper.cpp.
//
// Single-file, main-only (pre-M6 convention) — no functions yet.
// Build: g++ -std=c++17 -Wall -Wextra -o apply-stage1-greet apply-stage1-greet.cpp
#include <iostream>
using namespace std;

int main()
{
    // ===== STAGE 1: the gatekeeper greets you =====
    cout << "A gatekeeper blocks the dungeon door. She looks you over.\n";

    return 0;
}
