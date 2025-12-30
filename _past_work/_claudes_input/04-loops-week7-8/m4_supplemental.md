# m4 supplemental
## Document 3: Project 2 Rubric and Assessment

```markdown
# Project 2: "The Loop Master's Challenge" Assessment Rubric
## Menu-Driven Game System (Week 8)

### Project Overview
Create a complete menu-driven program demonstrating mastery of ALL fundamental concepts: variables, functions, decisions, and loops. This project marks your achievement of the course "C" grade!

**Learning Objectives Assessed:**
- Loop structures (while, do-while, for)
- Input validation
- Menu systems
- Function organization
- Decision structures
- Program state management
- Professional user interface

---

## Grading Components (100 points total)

### 1. Loop Implementation (35 points)

| Criteria | Excellent (10-12) | Proficient (7-9) | Developing (4-6) | Needs Work (0-3) |
|----------|------------------|------------------|------------------|------------------|
| **Loop Variety** (12 pts) | Uses all three loop types appropriately | Uses 2-3 types correctly | Some loops work | Limited loop usage |
| **Loop Control** (12 pts) | All loops terminate properly, no infinite loops | Most loops work correctly | Some infinite loop issues | Major loop problems |
| **Nested Loops** (11 pts) | Effective use of nested loops where appropriate | Some nested loops | Attempts at nesting | No nested loops |

### 2. Input Validation (20 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **Numeric Validation** | Handles all non-numeric input gracefully | Most validation works | Some validation | Crashes on bad input |
| **Range Validation** | All inputs checked for valid ranges | Most ranges validated | Some range checking | No range validation |

### 3. Menu System (20 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **Main Menu** | Professional menu with clear options | Good menu structure | Basic menu works | Minimal menu |
| **Navigation** | Smooth navigation, can always return | Good flow | Some navigation issues | Confusing navigation |

### 4. Program Features (15 points)

| Criteria | Excellent (5) | Proficient (4) | Developing (3) | Needs Work (1-2) |
|----------|--------------|----------------|----------------|------------------|
| **Core Gameplay** | Engaging, complete game loop | Good gameplay | Basic game works | Minimal gameplay |
| **State Management** | Tracks all game state correctly | Most state tracked | Some state tracking | Limited state |
| **User Experience** | Polished, professional feel | Good experience | Functional | Rough interface |

### 5. Code Quality (10 points)

| Criteria | Excellent (5) | Proficient (4) | Developing (3) | Needs Work (1-2) |
|----------|--------------|----------------|----------------|------------------|
| **Functions** | 5+ well-organized functions | 3-4 good functions | Some functions | Mostly in main() |
| **Documentation** | Clear comments, good names | Adequate comments | Some comments | Minimal comments |

---

## Project Requirements Checklist

### Minimum Requirements (C Grade - 70%)
- [ ] Menu-driven interface that loops until quit
- [ ] At least 2 different loop types used
- [ ] Basic input validation (no crashes)
- [ ] 3+ functions beyond main()
- [ ] One game/activity that works
- [ ] Tracks at least 2 state variables
- [ ] Clean exit option

### Target Requirements (B Grade - 85%)
- [ ] All 3 loop types used appropriately
- [ ] Complete input validation (handles all bad input)
- [ ] Professional menu system with submenus
- [ ] 5+ well-organized functions
- [ ] Multiple activities/games
- [ ] Comprehensive state tracking
- [ ] Statistics or score tracking
- [ ] Polished user interface

### Exceptional Requirements (A Grade - 95%+)
- [ ] Masterful use of nested loops
- [ ] Bulletproof validation (impossible to break)
- [ ] Multiple integrated systems
- [ ] 7+ functions with clear purposes
- [ ] Save/load functionality
- [ ] Difficulty levels or customization
- [ ] ASCII art or visual polish
- [ ] Easter eggs or hidden features
- [ ] Extensive replay value

---

## Project Structure Template

```cpp
// Recommended structure for your project

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void displayTitle();
void displayMainMenu();
int getValidChoice(int min, int max);
void playGame();
void showStatistics();
void saveProgress();
void loadProgress();

// Global constants (OK to use)
const int MAX_HEALTH = 100;
const int BASE_DAMAGE = 10;

// Global statistics (OK for this project)
int gamesPlayed = 0;
int gamesWon = 0;
int highScore = 0;

int main()
{
    // Initialize
    srand(time(0));
    displayTitle();
    
    // Main program loop
    bool running = true;
    while (running)
    {
        displayMainMenu();
        int choice = getValidChoice(1, 5);
        
        switch(choice)
        {
            case 1:
                playGame();
                break;
            case 2:
                showStatistics();
                break;
            case 3:
                saveProgress();
                break;
            case 4:
                loadProgress();
                break;
            case 5:
                running = false;
                break;
        }
    }
    
    // Cleanup
    cout << "Thanks for playing!" << endl;
    showStatistics();
    
    return 0;
}

// Function implementations...

-----
// must include...
int getValidChoice(int min, int max)
{
    int choice;
    bool valid = false;
    
    while (!valid)
    {
        cout << "Enter choice (" << min << "-" << max << "): ";
        cin >> choice;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number!" << endl;
        }
        else if (choice < min || choice > max)
        {
            cout << "Please enter a number between " 
                 << min << " and " << max << "!" << endl;
        }
        else
        {
            valid = true;
        }
    }
    
    return choice;
}
// 