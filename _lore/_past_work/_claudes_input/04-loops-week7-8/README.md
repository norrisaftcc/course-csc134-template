# Module 04: Loops - The Boss Battle Against Repetition
## Weeks 7-8 | Badge: Advanced Control Structures

## 🎮 Module Overview

**Duration**: Weeks 7-8 (4 class sessions)  
**Project**: Professional Game Menu System  
**Badge Alignment**: Advanced Control Structures, Input Validation  
**AI Support**: Flash-Debug for infinite loop help, Flash-Organizer for menu structure

### This Module's Superpower
By the end of Week 8, you'll defeat repetition forever! Your programs will handle any amount of data, validate all input, and run until the user decides to stop.

## 📚 Learning Objectives

By the end of this module, you will be able to:
- [ ] Implement while loops for conditional repetition
- [ ] Use for loops for counted iteration
- [ ] Create do-while loops for guaranteed execution
- [ ] Build input validation loops
- [ ] Design menu-driven programs
- [ ] Detect and prevent infinite loops
- [ ] Combine loops with previous concepts (functions, decisions)
- [ ] Create professional, polished programs

## 🎮 Available Materials

### GameFAQs Guides
- [Main GameFAQs Guide](module04-loops-gamefaqs.md) - Primary loop tutorial
- [CSC 134 M4 Guide](csc_134_m4_gamefaqs_guide.md) - Alternative version
- [M4 FAQ](m4_faq.md) - Frequently asked questions
- [M4 Supplemental](m4_supplemental.md) - Additional resources
- [Test Log](m4_test_log.txt) - Sample testing outputs

## 🎮 The Big Project: Professional Menu System

Transform your Module 3 adventure game into a polished application with:
- Main menu with multiple options
- Input validation on ALL user input
- Ability to play multiple times
- Statistics tracking
- Save/load functionality (basic)
- Clean exit option

### The Menu Loop Pattern
```cpp
int choice;
do {
    displayMenu();
    cin >> choice;
    
    switch(choice) {
        case 1:
            playGame();
            break;
        case 2:
            viewStats();
            break;
        case 3:
            showHelp();
            break;
        case 4:
            cout << "Thanks for playing!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
    }
} while (choice != 4);
```

## 📖 Module Contents

### Week 7: Loop Fundamentals
- **while loops**: When you don't know how many times
- **for loops**: When you know the count
- **Loop control**: break and continue
- **Common patterns**: Counters, accumulators, sentinels

### Week 8: Advanced Loops
- **do-while loops**: Always run at least once
- **Nested loops**: Loops inside loops
- **Input validation**: Bulletproof user input
- **Menu systems**: Professional program flow

## 🎮 Module Schedule

### Week 7, Monday
- Introduction to while loops
- Input validation patterns
- Start menu system design

### Week 7, Wednesday  
- for loops and counting
- Loop debugging strategies
- Implement core menu

### Week 8, Monday
- do-while loops
- Nested loop patterns
- Add game statistics

### Week 8, Wednesday
- Polish and testing
- Infinite loop prevention
- Project completion

### Week 8, Friday
- **Project Due**: Complete Menu System
- Code review session
- Midterm preparation

## 🏆 Assessment

### Menu System Project (100 points)

| Component | Points | Requirements |
|-----------|--------|--------------|
| **Loop Variety** | 25 | Use while, for, and do-while appropriately |
| **Input Validation** | 25 | No crashes on bad input anywhere |
| **Menu Functionality** | 20 | All options work, clean navigation |
| **Code Integration** | 15 | Incorporates functions and decisions well |
| **Polish** | 10 | Professional output, good UX |
| **Flash Log** | 5 | Shows debugging process |

## 🐛 Common Loop Bugs

### Bug 1: Infinite Loop
```cpp
// ❌ WRONG - Infinite loop!
int count = 1;
while (count <= 10) {
    cout << count << endl;
    // Forgot to increment count!
}

// ✅ RIGHT
int count = 1;
while (count <= 10) {
    cout << count << endl;
    count++;  // Don't forget this!
}
```

### Bug 2: Off-by-One Error
```cpp
// ❌ WRONG - Runs 11 times, not 10
for (int i = 0; i <= 10; i++)

// ✅ RIGHT - Runs exactly 10 times
for (int i = 0; i < 10; i++)
```

### Bug 3: Input Validation Fail
```cpp
// ❌ WRONG - Infinite loop on bad input
int choice;
while (choice < 1 || choice > 3) {
    cin >> choice;  // What if they enter a letter?
}

// ✅ RIGHT - Handles all input
int choice;
while (true) {
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a number: ";
    }
    else if (choice >= 1 && choice <= 3) {
        break;
    }
    else {
        cout << "Please enter 1-3: ";
    }
}
```

## 💡 Loop Mastery Tips

### The Three Questions
Before writing any loop, ask:
1. **What's the condition?** (When should it run?)
2. **What changes?** (What prevents infinite loop?)
3. **What's the body?** (What happens each time?)

### Input Validation Recipe
```cpp
// Universal input validation pattern
int getValidInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again: ";
        }
        else if (input < min || input > max) {
            cout << "Please enter " << min << "-" << max << ": ";
        }
        else {
            return input;
        }
    }
}
```

## 🦆 Flash Strategies for Loops

### Flash-Debug
- "Where should I add cout to see loop progress?"
- "What would cause this to run forever?"
- "How can I test if my loop runs the right number of times?"

### Flash-Organizer
- "What loops does a menu system need?"
- "How should I structure nested game rounds?"
- "What's the best loop type for this situation?"

## 🚀 Looking Ahead

After Week 8, you're HALFWAY DONE and ready for the big transition:
- **Week 9**: Meet Thinker (AI that can write code!)
- **Weeks 10-12**: Arrays and file I/O
- **Weeks 13-15**: Object-oriented programming
- **Week 16**: Portfolio project

## Loop Wisdom

> "Every professional programmer has written an infinite loop. The difference? We hit Ctrl+C faster!" - Instructor

> "Loops are like superpowers - they make impossible tasks trivial." - Former student

> "Once loops clicked, everything else in programming made sense." - Another survivor

## Module 4 Motto
### "Why do something twice when a loop can do it a thousand times?"

After this module, you'll have ALL the fundamental control structures. You can make programs that think (decisions) and programs that persist (loops). Combined with functions, you're now a REAL programmer! 🎯