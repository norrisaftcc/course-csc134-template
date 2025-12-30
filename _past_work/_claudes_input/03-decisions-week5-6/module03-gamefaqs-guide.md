```
==============================================================================
    ____ ____   ____   _ _____ _  _     ____  _____ ____ ___ ____ ___ ___  _   _ ____  
   / ___/ ___| / ___| / |___ /| || |   |  _ \| ____/ ___|_ _/ ___|_ _/ _ \| \ | / ___| 
  | |   \___ \| |     | | |_ \| || |_  | | | |  _|| |    | |\___ \| | | | |  \| \___ \ 
  | |___ ___) | |___  | |___) |__   _| | |_| | |__| |___ | | ___) | | |_| | |\  |___) |
   \____|____/ \____| |_|____/   |_|   |____/|_____\____|___|____/___\___/|_| \_|____/ 
                                                                                        
                        YOUR CODE LEARNS TO THINK (WEEKS 5-6)
                             v1.0 - Community College Edition
==============================================================================

Written by: Your Instructor
Platform: C++ (any compiler)
Updated: Week 5 Start
Contact: Office Hours or Discord #week5-decisions

==============================================================================
                              TABLE OF CONTENTS
==============================================================================

[1.0] INTRODUCTION & QUEST SETUP
[2.0] BASIC DECISIONS - THE IF STATEMENT
[3.0] FORK IN THE ROAD - IF-ELSE
[4.0] MULTIPLE PATHS - ELSE-IF CHAINS  
[5.0] THE SWITCH STATEMENT - MENU SYSTEMS
[6.0] BOSS BATTLE - LOGICAL OPERATORS
[7.0] LAB WALKTHROUGH - BUILD YOUR ADVENTURE
[8.0] COMMON BUGS & FIXES
[9.0] PROJECT 1 REQUIREMENTS
[10.0] SECRETS & EASTER EGGS

==============================================================================
[1.0] INTRODUCTION & QUEST SETUP
==============================================================================

Welcome to Week 5, adventurer! You're about to learn the most important 
skill in programming: making decisions.

IMPORTANT: Not into swords and wizards? No problem! Ask Flash to help you 
change the theme. Want to make a:
- Coffee shop simulator? 
- Stock trading game?
- Spanish flashcard drill?
- Dating sim?
- Zombie survival game?

It's YOUR adventure. The concepts work the same whether you're fighting 
dragons or serving lattes. (Yes, Flash can even help you make ASCII art 
for your cout statements!)

By Week 6's end, you'll submit Project 1: a complete text adventure with 
branching paths. Think "Choose Your Own Adventure" books, but YOU'RE the 
author.

==============================================================================
[2.0] BASIC DECISIONS - THE IF STATEMENT
==============================================================================

The simplest decision structure. "IF this is true, THEN do something."

------------------------------------------------------------------------------
SYNTAX:
------------------------------------------------------------------------------
if (condition)
{
    // Code runs ONLY if condition is true
}
// Program continues here either way

------------------------------------------------------------------------------
EXAMPLE - Health Potion:
------------------------------------------------------------------------------
int playerHealth = 75;
cout << "You find a glowing potion. Drink it? (1=yes, 2=no): ";
int choice;
cin >> choice;

if (choice == 1)
{
    playerHealth = playerHealth + 30;
    cout << "Refreshing! Health restored to " << playerHealth << endl;
}
cout << "You continue onward..." << endl;

------------------------------------------------------------------------------
THE GOLDEN RULE - DON'T MIX UP = AND ==
------------------------------------------------------------------------------
WRONG:  if (health = 100)   // ASSIGNS 100 to health!
RIGHT:  if (health == 100)  // CHECKS if health equals 100

Memory trick: "One equal gives, two equals asks!"

------------------------------------------------------------------------------
RELATIONAL OPERATORS QUICK REFERENCE:
------------------------------------------------------------------------------
>   Greater than       if (gold > 50)
<   Less than         if (health < 20)  
>=  Greater or equal  if (level >= 5)
<=  Less or equal     if (enemies <= 3)
==  Equal to          if (hasKey == true)
!=  Not equal         if (doorStatus != "locked")

==============================================================================
[3.0] FORK IN THE ROAD - IF-ELSE
==============================================================================

When you need to do one thing OR another (never both).

------------------------------------------------------------------------------
SYNTAX:
------------------------------------------------------------------------------
if (condition)
{
    // Path A - condition is true
}
else
{
    // Path B - condition is false
}

------------------------------------------------------------------------------
EXAMPLE - Shop Transaction:
------------------------------------------------------------------------------
const int SWORD_PRICE = 100;
int playerGold = 75;

if (playerGold >= SWORD_PRICE)
{
    cout << "You buy the sword! *ka-ching*" << endl;
    playerGold = playerGold - SWORD_PRICE;
}
else
{
    cout << "Not enough gold. The merchant scoffs." << endl;
}

==============================================================================
[4.0] MULTIPLE PATHS - ELSE-IF CHAINS
==============================================================================

For when you have more than two options.

------------------------------------------------------------------------------
PATTERN:
------------------------------------------------------------------------------
if (condition1)
{
    // First check
}
else if (condition2)
{
    // Second check (only if first was false)
}
else if (condition3)
{
    // Third check (only if first two were false)
}
else
{
    // Default - everything else failed
}

------------------------------------------------------------------------------
EXAMPLE - Grade Calculator:
------------------------------------------------------------------------------
if (score >= 90)
    grade = 'A';
else if (score >= 80)
    grade = 'B';
else if (score >= 70)
    grade = 'C';
else if (score >= 60)
    grade = 'D';
else
    grade = 'F';

==============================================================================
[5.0] THE SWITCH STATEMENT - MENU SYSTEMS
==============================================================================

Perfect for menus and multiple exact-value checks.

------------------------------------------------------------------------------
SYNTAX:
------------------------------------------------------------------------------
switch(variable)
{
    case value1:
        // Do something
        break;  // DON'T FORGET THIS!
        
    case value2:
        // Do something else
        break;
        
    default:
        // If nothing else matches
}

------------------------------------------------------------------------------
EXAMPLE - Door Selection:
------------------------------------------------------------------------------
cout << "Choose a door (1-4): ";
int door;
cin >> door;

switch(door)
{
    case 1:
        cout << "Treasure room! +100 gold!" << endl;
        playerGold += 100;
        break;
        
    case 2:
        cout << "Healing fountain! Full HP!" << endl;
        playerHealth = maxHealth;
        break;
        
    case 3:
        cout << "Armory! +1 sword!" << endl;
        hasSword = true;
        break;
        
    case 4:
        cout << "TRAP! -20 health!" << endl;
        playerHealth -= 20;
        break;
        
    default:
        cout << "You walk into a wall. -1 dignity." << endl;
}

WARNING: Forgetting 'break' causes fall-through to the next case!

==============================================================================
[6.0] BOSS BATTLE - LOGICAL OPERATORS
==============================================================================

Combine multiple conditions for complex decisions.

------------------------------------------------------------------------------
OPERATORS:
------------------------------------------------------------------------------
&&  AND  - Both must be true
||  OR   - At least one must be true  
!   NOT  - Reverses true/false

------------------------------------------------------------------------------
EXAMPLES:
------------------------------------------------------------------------------
// Need BOTH conditions
if (playerHealth > 50 && hasPotion == true)
{
    cout << "You're ready for battle!" << endl;
}

// Need AT LEAST ONE condition
if (playerClass == "warrior" || playerClass == "paladin")
{
    cout << "You can use heavy armor!" << endl;
}

// Reverse the condition
if (!isDead)  // Same as: if (isDead == false)
{
    cout << "Still alive!" << endl;
}

------------------------------------------------------------------------------
COMMON LOGIC PATTERNS:
------------------------------------------------------------------------------
// Range checking
if (level >= 5 && level <= 10)

// Multiple valid options
if (choice == 1 || choice == 2 || choice == 3)

// Complex battle conditions
if ((health > 30 || hasPotion) && weapon != "none")

==============================================================================
[7.0] LAB WALKTHROUGH - BUILD YOUR ADVENTURE
==============================================================================

Your Week 5-6 labs build toward Project 1.

------------------------------------------------------------------------------
LAB 5: BASIC ADVENTURE (potion_room.cpp)
------------------------------------------------------------------------------
Required elements:
1. At least 3 if statements
2. One if-else structure
3. Player stats (health, gold)
4. Meaningful choices that affect stats

Sample structure:
- Room description
- Present choices (1-4)
- Get input with validation
- Process choice with if/else
- Update game state
- Show results

------------------------------------------------------------------------------
LAB 6: ADVANCED SYSTEMS (combat_system.cpp)
------------------------------------------------------------------------------
Add these features:
1. Switch statement for menu
2. Nested decisions
3. Logical operators (&&, ||, !)
4. Input validation loop

Combat menu example:
1. Attack (normal damage)
2. Defend (reduce damage, heal 5)
3. Power Strike (2x damage, risky)
4. Use Item (if available)

------------------------------------------------------------------------------
ASCII ART TIP:
------------------------------------------------------------------------------
Flash CAN help you create ASCII art! Just add cout statements:

cout << "     /\\_/\\  " << endl;
cout << "    ( o.o ) " << endl;  
cout << "     > ^ <  " << endl;
cout << "    CAT BOSS" << endl;

==============================================================================
[8.0] COMMON BUGS & FIXES
==============================================================================

------------------------------------------------------------------------------
BUG #1: ASSIGNMENT IN CONDITION
------------------------------------------------------------------------------
WRONG:  if (score = 100)    // Always true!
FIX:    if (score == 100)   // Comparison

------------------------------------------------------------------------------
BUG #2: MISSING BRACES
------------------------------------------------------------------------------
WRONG:  
if (health <= 0)
    cout << "You died!" << endl;
    cout << "Game over!" << endl;  // ALWAYS prints!

FIX:
if (health <= 0)
{
    cout << "You died!" << endl;
    cout << "Game over!" << endl;
}

------------------------------------------------------------------------------
BUG #3: SWITCH FALL-THROUGH
------------------------------------------------------------------------------
WRONG:
case 1:
    cout << "Option 1" << endl;
    // Missing break!
case 2:
    cout << "Option 2" << endl;  // Runs for case 1 too!

FIX: Add 'break;' after each case

------------------------------------------------------------------------------
BUG #4: IMPOSSIBLE CONDITIONS
------------------------------------------------------------------------------
WRONG:  if (x > 10 && x < 5)   // Can't be both!
FIX:    if (x > 10 || x < 5)   // One or the other

==============================================================================
[9.0] PROJECT 1 REQUIREMENTS
==============================================================================

DUE: End of Week 6
NAME: "Your Adventure Title Here"
FILES: adventure.cpp, testing_log.txt, ai_chat.txt

------------------------------------------------------------------------------
MINIMUM REQUIREMENTS (C GRADE - 70%):
------------------------------------------------------------------------------
[ ] 3+ rooms/locations
[ ] Basic if-else decisions  
[ ] Track player health
[ ] One challenge/combat
[ ] 2 different endings
[ ] No crashes on bad input

------------------------------------------------------------------------------
B GRADE (85%):
------------------------------------------------------------------------------
[ ] 5+ rooms
[ ] Mix of if-else and switch
[ ] Track health, gold, inventory
[ ] Combat system with menu
[ ] 3 different endings
[ ] 3+ functions beyond main()

------------------------------------------------------------------------------
A GRADE (95%+):
------------------------------------------------------------------------------
[ ] 7+ rooms
[ ] Complex nested decisions
[ ] Full stat system
[ ] Strategic combat
[ ] Inventory with usable items
[ ] Save points or checkpoints
[ ] ASCII art or visual polish
[ ] Hidden secrets

------------------------------------------------------------------------------
TESTING CHECKLIST:
------------------------------------------------------------------------------
[ ] Test all paths to all endings
[ ] Enter invalid input everywhere
[ ] Try edge cases (0 health, negative gold)
[ ] Document 5+ test cases
[ ] Fix all crashes

==============================================================================
[10.0] SECRETS & EASTER EGGS
==============================================================================

Want to impress? Add these:

------------------------------------------------------------------------------
KONAMI CODE:
------------------------------------------------------------------------------
Track the last 10 inputs. If they match a pattern, unlock secret ending!

------------------------------------------------------------------------------
FOURTH WALL BREAKS:
------------------------------------------------------------------------------
if (playerName == "Neo")
{
    cout << "Wake up, " << playerName << "..." << endl;
    cout << "The Matrix has you..." << endl;
}

------------------------------------------------------------------------------
DEVELOPER ROOM:
------------------------------------------------------------------------------
Hidden room accessible only by specific choices:
Room 1: Choice 3
Room 2: Choice 1  
Room 3: Choice 4
Result: Secret developer commentary!

------------------------------------------------------------------------------
NEW GAME PLUS:
------------------------------------------------------------------------------
After winning, offer to restart with bonuses:
- Keep some items
- Start at higher level
- Unlock new dialogue options

==============================================================================
                              FINAL ADVICE
==============================================================================

Start small. Get 3 rooms working PERFECTLY before adding more.

Test everything. Then test it again.

Have fun with it! This is YOUR game. Make something you'd want to play.

Remember: Flash can help with theme changes and ASCII art, but the logic
is all you. You've got this!

==============================================================================
                          END OF DOCUMENT
                    GOOD LUCK, ADVENTURER!
==============================================================================
```