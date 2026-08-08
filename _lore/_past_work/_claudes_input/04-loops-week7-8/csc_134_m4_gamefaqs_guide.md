# m4 gamefaqs guide.md
==============================================================================
     ____ ____   ____   _ _____ _  _     _     ___   ___  ____  ____  
    / ___/ ___| / ___| / |___ /| || |   | |   / _ \ / _ \|  _ \/ ___| 
   | |   \___ \| |     | | |_ \| || |_  | |  | | | | | | | |_) \___ \ 
   | |___ ___) | |___  | |___) |__   _| | |__| |_| | |_| |  __/ ___) |
    \____|____/ \____| |_|____/   |_|   |_____\___/ \___/|_|   |____/ 
                                                                       
                    THE END BOSS OF BASIC PROGRAMMING (WEEKS 7-8)
                        v1.0 - Achievement Unlocked Edition
                            >>> WEEK 8 = C GRADE! <<<
==============================================================================

Written by: Your Instructor
Platform: C++ (any compiler)
Updated: Week 7 Start
Contact: Office Hours or Discord #week7-loops

==============================================================================
                              TABLE OF CONTENTS
==============================================================================

PART I: CORE CONTENT
[1.0] INTRODUCTION - THE FINAL FUNDAMENTAL
[2.0] THE WHILE LOOP - KEEP GOING UNTIL
[3.0] THE DO-WHILE LOOP - ACT FIRST, THINK LATER
[4.0] THE FOR LOOP - COUNTING CHAMPION
[5.0] INPUT VALIDATION - BULLETPROOF YOUR CODE
[6.0] NESTED LOOPS - LOOPS WITHIN LOOPS
[7.0] THE ULTIMATE MENU PATTERN

PART II: LABORATORY MISSIONS
[8.0] LAB 7 - LOOP FUNDAMENTALS
[9.0] LAB 8 - PROFESSIONAL MENU SYSTEM

PART III: THE BOSS BATTLE
[10.0] PROJECT 2 REQUIREMENTS
[11.0] GRADING RUBRIC
[12.0] COMMON BUGS & FIXES
[13.0] TESTING CHECKLIST

PART IV: VICTORY LAP
[14.0] WEEK 8 ACHIEVEMENT GUIDE
[15.0] SECRETS & EASTER EGGS

==============================================================================
[1.0] INTRODUCTION - THE FINAL FUNDAMENTAL
==============================================================================

Welcome to the END BOSS of introductory programming: LOOPS!

By Week 8's end, you'll have ALL four fundamental tools:
1. Variables & I/O (Weeks 1-2) [COMPLETE]
2. Functions (Weeks 3-4) [COMPLETE]
3. Decisions (Weeks 5-6) [COMPLETE]  
4. Loops (Weeks 7-8) [LOADING...]

------------------------------------------------------------------------------
QUEST OBJECTIVES:
------------------------------------------------------------------------------
- Master three types of loops (while, do-while, for)
- Build bulletproof input validation
- Create professional menu systems
- Submit Project 2: Menu-Driven Game
- UNLOCK C GRADE ACHIEVEMENT!

------------------------------------------------------------------------------
THEME FLEXIBILITY:
------------------------------------------------------------------------------
Not into combat loops? Flash can help you reskin to:
- Coffee shop order system
- Language learning drills
- Fitness tracker
- Stock market simulator
- Dating sim dialogue trees
- Whatever loops make sense for YOU!

==============================================================================
[2.0] THE WHILE LOOP - KEEP GOING UNTIL
==============================================================================

The while loop checks BEFORE it runs. "While this is true, keep doing that."

------------------------------------------------------------------------------
SYNTAX:
------------------------------------------------------------------------------
while (condition)
{
    // Runs as long as condition is true
    // Don't forget to progress toward false!
}

------------------------------------------------------------------------------
EXAMPLE - COMBAT LOOP:
------------------------------------------------------------------------------
int enemyHealth = 100;
int playerDamage = 15;

while (enemyHealth > 0)
{
    cout << "You attack for " << playerDamage << " damage!" << endl;
    enemyHealth = enemyHealth - playerDamage;
    
    if (enemyHealth > 0)
        cout << "Enemy health: " << enemyHealth << endl;
}
cout << "Enemy defeated!" << endl;

------------------------------------------------------------------------------
THE INFINITE LOOP TRAP:
------------------------------------------------------------------------------
WRONG:
while (x > 0)
{
    cout << "Stuck forever!" << endl;
    // x never changes - infinite loop!
}

RIGHT:
while (x > 0)
{
    cout << x << endl;
    x--;  // Progress toward exit!
}

Remember: Ctrl+C is your emergency exit!

==============================================================================
[3.0] THE DO-WHILE LOOP - ACT FIRST, THINK LATER
==============================================================================

Runs at least once, THEN checks condition.

------------------------------------------------------------------------------
SYNTAX:
------------------------------------------------------------------------------
do
{
    // This runs at least once
} while (condition);  // <-- Don't forget semicolon!

------------------------------------------------------------------------------
PERFECT FOR MENUS:
------------------------------------------------------------------------------
int choice;
do
{
    cout << "1. Play" << endl;
    cout << "2. Quit" << endl;
    cout << "Choice: ";
    cin >> choice;
    
    if (choice == 1)
        playGame();
        
} while (choice != 2);

------------------------------------------------------------------------------
WHILE vs DO-WHILE:
------------------------------------------------------------------------------
// WHILE: Might never run
while (password != 1234)  
{
    cout << "Enter password: ";
    cin >> password;
}

// DO-WHILE: Always runs at least once
do
{
    cout << "Enter password: ";
    cin >> password;
} while (password != 1234);

==============================================================================
[4.0] THE FOR LOOP - COUNTING CHAMPION
==============================================================================

When you know exactly how many times to repeat.

------------------------------------------------------------------------------
ANATOMY:
------------------------------------------------------------------------------
for (start; condition; update)
{
    // Loop body
}

for (int i = 0; i < 10; i++)
{
    cout << i << " ";  // Prints: 0 1 2 3 4 5 6 7 8 9
}

------------------------------------------------------------------------------
COMMON PATTERNS:
------------------------------------------------------------------------------
// Count from 1 to 10
for (int i = 1; i <= 10; i++)

// Count backwards
for (int i = 10; i >= 0; i--)

// Count by 2s
for (int i = 0; i <= 20; i += 2)

// Count by 5s
for (int level = 5; level <= 50; level += 5)

------------------------------------------------------------------------------
OFF-BY-ONE ERRORS:
------------------------------------------------------------------------------
WRONG: for (int i = 1; i < 10; i++)   // Only 9 times!
RIGHT: for (int i = 1; i <= 10; i++)  // 10 times
  -OR- for (int i = 0; i < 10; i++)   // Also 10 times (0-9)

==============================================================================
[5.0] INPUT VALIDATION - BULLETPROOF YOUR CODE
==============================================================================

The #1 skill that separates noobs from pros!

------------------------------------------------------------------------------
THE BULLETPROOF PATTERN:
------------------------------------------------------------------------------
int getValidInput(int min, int max)
{
    int input;
    bool valid = false;
    
    while (!valid)
    {
        cout << "Enter (" << min << "-" << max << "): ";
        cin >> input;
        
        if (cin.fail())  // User entered text!
        {
            cin.clear();  // Clear error flag
            cin.ignore(10000, '\n');  // Dump bad input
            cout << "Numbers only!" << endl;
        }
        else if (input < min || input > max)
        {
            cout << "Must be " << min << "-" << max << "!" << endl;
        }
        else
        {
            valid = true;  // Success!
        }
    }
    
    return input;
}

------------------------------------------------------------------------------
WHY THIS WORKS:
------------------------------------------------------------------------------
1. cin.fail() detects when text is entered for a number
2. cin.clear() resets cin to working state
3. cin.ignore() throws away the bad input
4. Loop continues until valid input received
5. IMPOSSIBLE TO CRASH!

==============================================================================
[6.0] NESTED LOOPS - LOOPS WITHIN LOOPS
==============================================================================

For 2D patterns, grids, and tables.

------------------------------------------------------------------------------
BASIC PATTERN:
------------------------------------------------------------------------------
for (int row = 0; row < 5; row++)
{
    for (int col = 0; col < 5; col++)
    {
        cout << "* ";
    }
    cout << endl;  // New line after each row
}

Output:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *

------------------------------------------------------------------------------
TREASURE MAP EXAMPLE:
------------------------------------------------------------------------------
for (int row = 0; row < 5; row++)
{
    for (int col = 0; col < 5; col++)
    {
        if (row == 2 && col == 2)
            cout << "X ";  // Treasure here!
        else
            cout << "- ";
    }
    cout << endl;
}

Output:
- - - - -
- - - - -
- - X - -
- - - - -
- - - - -

==============================================================================
[7.0] THE ULTIMATE MENU PATTERN
==============================================================================

This pattern will serve you for YEARS!

------------------------------------------------------------------------------
THE PROFESSIONAL MENU LOOP:
------------------------------------------------------------------------------
bool quit = false;

do
{
    // Display menu
    cout << "\n=== MAIN MENU ===" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. View Scores" << endl;
    cout << "3. Options" << endl;
    cout << "4. Quit" << endl;
    
    // Get validated input
    int choice = getValidInput(1, 4);
    
    // Process choice
    switch(choice)
    {
        case 1:
            playGame();
            break;
        case 2:
            viewScores();
            break;
        case 3:
            showOptions();
            break;
        case 4:
            quit = true;
            cout << "Thanks for playing!" << endl;
            break;
    }
    
} while (!quit);

==============================================================================
[8.0] LAB 7 - LOOP FUNDAMENTALS
==============================================================================

Three exercises to master loops.

------------------------------------------------------------------------------
EXERCISE A: COMBAT DUMMY (combat_loop.cpp)
------------------------------------------------------------------------------
Create a training dummy with 100 HP.
Your attacks do 15 damage.
20% chance of critical hit (double damage).

Requirements:
- Use while loop for combat
- Count total attacks needed
- Track critical hits
- Display statistics after victory

Sample Output:
Attack #1: Hit for 15! (HP: 85)
Attack #2: CRITICAL for 30! (HP: 55)
[...]
Victory in 5 attacks! (1 critical)

------------------------------------------------------------------------------
EXERCISE B: NUMBER GUESS (guess_game.cpp)
------------------------------------------------------------------------------
Computer picks random 1-100.
Player gets 7 attempts.

Requirements:
- Use do-while for game loop
- Give "higher/lower" hints
- Track attempts
- Offer replay option

------------------------------------------------------------------------------
EXERCISE C: PATTERN MAKER (patterns.cpp)
------------------------------------------------------------------------------
Create three patterns using nested loops:

Pattern 1: Right Triangle
*
**
***
****
*****

Pattern 2: Number Pyramid  
1
12
123
1234
12345

Pattern 3: Hollow Square
*****
*   *
*   *
*   *
*****

==============================================================================
[9.0] LAB 8 - PROFESSIONAL MENU SYSTEM
==============================================================================

Your masterpiece lab!

------------------------------------------------------------------------------
THE ULTIMATE MENU (ultimate_menu.cpp)
------------------------------------------------------------------------------
Requirements:
1. Main menu with 4+ options
2. At least one submenu
3. Statistics tracking
4. Complete input validation
5. Clean exit with summary

Structure:
MAIN MENU
├── Play Games
│   ├── Dice Game
│   └── Number Guess
├── View Statistics
├── Reset Statistics
└── Quit

------------------------------------------------------------------------------
GRADING CHECKLIST:
------------------------------------------------------------------------------
[ ] Loops until user quits
[ ] All input validated
[ ] No possible crashes
[ ] Statistics update correctly
[ ] Professional appearance
[ ] Uses functions effectively

==============================================================================
[10.0] PROJECT 2 REQUIREMENTS
==============================================================================

"The Loop Master's Challenge" - Due End of Week 8

------------------------------------------------------------------------------
MINIMUM REQUIREMENTS (70% - C GRADE):
------------------------------------------------------------------------------
[ ] Menu-driven interface
[ ] 2+ different loop types
[ ] Basic input validation
[ ] 3+ functions
[ ] One working game/activity
[ ] Tracks 2+ variables
[ ] Clean exit

------------------------------------------------------------------------------
B GRADE (85%):
------------------------------------------------------------------------------
[ ] All 3 loop types
[ ] Complete validation (no crashes!)
[ ] Professional menus
[ ] 5+ functions
[ ] Multiple activities
[ ] Statistics tracking
[ ] Polished interface

------------------------------------------------------------------------------
A GRADE (95%+):
------------------------------------------------------------------------------
[ ] Nested loops mastery
[ ] Impossible to break
[ ] Multiple systems
[ ] 7+ functions
[ ] Save/load feature
[ ] Difficulty levels
[ ] ASCII art
[ ] Hidden features

------------------------------------------------------------------------------
PROJECT IDEAS:
------------------------------------------------------------------------------
1. Arena Fighter - Battle waves of enemies
2. Shop Simulator - Buy/sell with customers
3. Quiz Master - Educational with categories
4. Dungeon Crawler - Room exploration
5. Your Own Idea - Get approval first!

==============================================================================
[11.0] GRADING RUBRIC
==============================================================================

COMPONENT                    WEIGHT   POINTS
-------------------------------------------- 
Loop Implementation            35%      35
- Variety (12)
- Control (12)
- Nesting (11)

Input Validation              20%      20
- Numeric (10)
- Range (10)

Menu System                   20%      20
- Main Menu (10)
- Navigation (10)

Program Features              15%      15
- Gameplay (5)
- State (5)
- UX (5)

Code Quality                  10%      10
- Functions (5)
- Comments (5)
--------------------------------------------
TOTAL                        100%     100

==============================================================================
[12.0] COMMON BUGS & FIXES
==============================================================================

------------------------------------------------------------------------------
BUG #1: INFINITE LOOP
------------------------------------------------------------------------------
SYMPTOM: Program hangs, never stops
CAUSE:   Loop condition never becomes false

WRONG:
while (x > 0)
{
    cout << x << endl;
    x++;  // Going wrong direction!
}

FIX:
while (x > 0)
{
    cout << x << endl;
    x--;  // Toward exit condition
}

------------------------------------------------------------------------------
BUG #2: SEMICOLON AFTER LOOP
------------------------------------------------------------------------------
SYMPTOM: Loop body never runs or runs once

WRONG:
while (x < 10);  // <-- This semicolon!
{
    cout << x << endl;
    x++;
}

FIX: Remove semicolon after while/for

------------------------------------------------------------------------------
BUG #3: CIN FAIL STATE
------------------------------------------------------------------------------
SYMPTOM: Input validation loops forever

WRONG:
while (choice < 1 || choice > 3)
{
    cin >> choice;  // If cin failed, stuck forever!
}

FIX: Check cin.fail() and clear/ignore

------------------------------------------------------------------------------
BUG #4: OFF-BY-ONE
------------------------------------------------------------------------------
SYMPTOM: Loop runs wrong number of times

WRONG:  for(int i = 1; i < 10; i++)   // 9 times
FIX:    for(int i = 1; i <= 10; i++)  // 10 times

==============================================================================
[13.0] TESTING CHECKLIST
==============================================================================

Your testing_log.txt must include:

------------------------------------------------------------------------------
TEST 1: MENU NAVIGATION
------------------------------------------------------------------------------
[ ] Test all menu options
[ ] Verify return to main
[ ] Test quit function
[ ] Check submenus

------------------------------------------------------------------------------
TEST 2: INPUT VALIDATION
------------------------------------------------------------------------------
[ ] Enter letters for numbers
[ ] Enter negative numbers  
[ ] Enter huge numbers
[ ] Enter nothing (just Enter)
[ ] Rapid random input

------------------------------------------------------------------------------
TEST 3: GAME FEATURES
------------------------------------------------------------------------------
[ ] Play through completely
[ ] Test win conditions
[ ] Test lose conditions
[ ] Check score tracking

------------------------------------------------------------------------------
TEST 4: EDGE CASES
------------------------------------------------------------------------------
[ ] Maximum values
[ ] Minimum values
[ ] Empty states
[ ] Boundary conditions

------------------------------------------------------------------------------
TEST 5: STRESS TEST
------------------------------------------------------------------------------
[ ] Play 10+ rounds
[ ] Check for memory issues
[ ] Verify statistics accuracy
[ ] No performance degradation

==============================================================================
[14.0] WEEK 8 ACHIEVEMENT GUIDE
==============================================================================

                    ********************************
                    *                              *
                    *   ACHIEVEMENT UNLOCKED!      *
                    *                              *
                    *      C GRADE EARNED          *
                    *                              *
                    *   You've mastered all four   *
                    *   fundamental concepts!      *
                    *                              *
                    ********************************

------------------------------------------------------------------------------
YOUR TOOLKIT IS COMPLETE:
------------------------------------------------------------------------------
[✓] Variables & I/O     - You can store and display data
[✓] Functions          - You can organize code
[✓] Decisions          - Your programs can think
[✓] Loops              - Your programs persist

------------------------------------------------------------------------------
WHAT THIS MEANS:
------------------------------------------------------------------------------
- You can build ANY basic program
- You understand programming logic
- You can debug systematically
- You ARE a programmer!

------------------------------------------------------------------------------
WEEK 9 UNLOCK:
------------------------------------------------------------------------------
Starting Week 9, Flash can generate code!
But you proved you don't need it.
That's what makes you REAL.

==============================================================================
[15.0] SECRETS & EASTER EGGS
==============================================================================

Want to go beyond? Add these to Project 2!

------------------------------------------------------------------------------
KONAMI CODE:
------------------------------------------------------------------------------
Track last 10 menu choices.
If they match: 1,1,2,2,3,4,3,4,1,2
Unlock secret "Developer Mode"!

------------------------------------------------------------------------------
BOSS RUSH MODE:
------------------------------------------------------------------------------
After beating game normally:
- All enemies at max difficulty
- No healing between fights
- Special victory message

------------------------------------------------------------------------------
STATISTICS ACHIEVEMENTS:
------------------------------------------------------------------------------
Track everything:
- Total keystrokes
- Time played
- Perfect runs
- Easter eggs found

Display achievements:
"Speed Demon" - Win in under 2 minutes
"Perfectionist" - Win without taking damage
"Explorer" - Find all secrets

------------------------------------------------------------------------------
ASCII ART GALLERY:
------------------------------------------------------------------------------
Flash can help you make ASCII art!
Just ask for help with cout statements.

   /\_/\  
  ( o.o ) 
   > ^ <  
  CAT BOSS

     ___
    [o o]
     \-/
    ROBOT

------------------------------------------------------------------------------
SAVE SYSTEM:
------------------------------------------------------------------------------
Simple version:
- Display a "save code" (encoded stats)
- Player writes it down
- Can enter code to restore

Example: "HERO-100-050-003"
(name-health-gold-level)

==============================================================================
                          FINAL WISDOM
==============================================================================

THREE LAWS OF LOOPS:
1. Every loop must have an exit
2. Validate everything  
3. Test the boundaries

DEBUGGING MANTRAS:
- "Is my condition ever becoming false?"
- "What is cin's state right now?"
- "Have I tested with garbage input?"

YOU'VE GOT THIS:
Week 8 is YOUR week. You're submitting Project 2 and earning that C.
You've climbed the mountain. The view is amazing.

Flash is here to help you debug, not write code (until Week 9).
Your struggles make you stronger.
Your bugs make you wiser.
Your loops make you POWERFUL.

==============================================================================
                    END OF DOCUMENT
            GOOD LUCK, LOOP MASTER!
==============================================================================