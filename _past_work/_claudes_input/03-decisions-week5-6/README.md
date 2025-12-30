# Module 03: Decision Structures - Your Code Learns to Think
## Weeks 5-6 | Badge: C++ Syntax and Control Structures

## 🎮 Choose Your Adventure

This module comes in TWO flavors - pick the one that matches your learning style!

### 📚 Option 1: [Canvas Assignment Version](module03-canvas-assignment.md)
**Best for:** Students who prefer formal, structured learning
- Professional academic format
- Clear learning objectives
- Traditional assignment structure
- Detailed rubrics and requirements

### 🎮 Option 2: [GameFAQs Guide Version](module03-gamefaqs-guide.md) 
**Best for:** Students who learn through gaming metaphors
- Retro ASCII art style
- Gaming terminology and references
- "Boss battle" framing for challenges
- Easter eggs and secrets section

Both versions teach the SAME concepts - just choose the style that motivates you more!

## 🎯 Module Overview

**Duration**: Weeks 5-6 (4 class sessions)  
**Project**: Choose Your Own Adventure Game  
**Badge Alignment**: C++ Syntax and Control Structures  
**AI Support**: Flash-Creative for story ideas, Flash-Debug for logic help

### This Module's Superpower
By the end of Week 6, your programs will make intelligent decisions! No more linear code - your programs will respond dynamically to user input and conditions.

## 📚 Learning Objectives

By the end of this module, you will be able to:
- [ ] Implement if, if-else, and if-else-if statements
- [ ] Use all six relational operators (>, <, >=, <=, ==, !=)
- [ ] Construct switch statements for multi-way selection
- [ ] Combine conditions using logical operators (&&, ||, !)
- [ ] Design programs with nested decision structures
- [ ] Validate user input to prevent errors
- [ ] Debug logic errors systematically
- [ ] Create a complete interactive program with branching logic

## 🎮 The Big Project: Your Text Adventure

You'll create a complete Choose Your Own Adventure game featuring:
- Multiple story paths
- Inventory system
- Combat or challenge mechanics
- At least 10 decision points
- Multiple endings

### Theme Freedom

Not into dungeons and dragons? No problem! Your adventure can be:
- **Sci-Fi**: Space station escape
- **Mystery**: Detective story
- **Survival**: Zombie apocalypse
- **Romance**: Dating sim
- **Educational**: Historical adventure
- **Comedy**: Absurdist journey
- **Business**: Startup simulator

Flash-Creative can help brainstorm unique themes!

## 📖 Module Contents

### Core Concepts (Both Versions Cover):
- **Chapter 5**: Decision Structures
  - Basic if statements
  - if-else chains
  - Nested decisions
  - Input validation

### Week 5 Focus
- Single and two-way decisions
- Relational operators
- Common logic patterns
- Debugging decision structures

### Week 6 Focus
- Multi-way decisions (else-if, switch)
- Logical operators (AND, OR, NOT)
- Complex conditions
- Project completion

## 🎮 Module Schedule

### Week 5, Monday
- Introduction to decision structures
- Basic if statements
- Start planning your adventure theme

### Week 5, Wednesday
- if-else statements
- Nested decisions
- Design your story flowchart

### Week 6, Monday
- Logical operators
- Complex conditions
- Implement core game mechanics

### Week 6, Wednesday
- Switch statements
- Input validation
- Polish and test your game

### Week 6, Friday
- **Project Due**: Complete Adventure Game
- Peer playtesting session
- Code reviews

## 🏆 Assessment

### Adventure Game Project (100 points)

| Component | Points | Requirements |
|-----------|--------|--------------|
| **Decision Variety** | 25 | Use if, else-if, switch, nested decisions |
| **Game Complexity** | 25 | 10+ decision points, multiple paths |
| **Input Validation** | 20 | Handle invalid input gracefully |
| **Story/Creativity** | 15 | Engaging narrative or concept |
| **Code Quality** | 10 | Clean, commented, organized |
| **Flash Log** | 5 | Document creative development |

## 🎮 Quick Start Examples

### Classic Fantasy Opening
```cpp
cout << "You stand at the entrance to a dark cave." << endl;
cout << "1. Enter the cave" << endl;
cout << "2. Walk around it" << endl;
cout << "3. Go back to town" << endl;

int choice;
cin >> choice;

if (choice == 1) {
    cout << "You bravely enter the darkness..." << endl;
    // Continue adventure
}
else if (choice == 2) {
    cout << "You discover a hidden path..." << endl;
    // Different branch
}
else if (choice == 3) {
    cout << "You return to safety. Game Over." << endl;
}
else {
    cout << "Invalid choice. The dragon eats you." << endl;
}
```

### Modern Setting Example
```cpp
cout << "Your phone buzzes with an unknown message." << endl;
cout << "Do you: (O)pen it, (I)gnore it, or (D)elete it? ";

char action;
cin >> action;

switch(toupper(action)) {
    case 'O':
        cout << "The message reads: 'They know. Run.'" << endl;
        hasWarning = true;
        break;
    case 'I':
        cout << "You pocket your phone and continue walking." << endl;
        break;
    case 'D':
        cout << "Message deleted. But was that wise?" << endl;
        missedClue = true;
        break;
    default:
        cout << "You fumble with your phone and drop it." << endl;
}
```

## 🦆 Working with Flash for This Module

### Flash-Creative (Story Development)
- Brainstorm unique storylines
- Generate character names and descriptions
- Create puzzle ideas
- Suggest plot twists

### Flash-Debug (Logic Help)
- Trace through decision paths
- Find logic errors in conditions
- Suggest test cases
- Help with flowchart design

### Flash-Organizer (Game Structure)
- Plan your scene functions
- Organize inventory systems
- Design state management
- Map out story branches

## 🐛 Common Week 5-6 Bugs

### Bug 1: Assignment vs. Comparison
```cpp
// ❌ WRONG - This assigns 5 to health!
if (health = 5)  

// ✅ RIGHT - This checks if health equals 5
if (health == 5)
```

### Bug 2: Missing Braces
```cpp
// ❌ WRONG - Only first line is conditional
if (score > 100)
    cout << "You win!" << endl;
    playerWins = true;  // This ALWAYS runs!

// ✅ RIGHT - Both lines are conditional
if (score > 100) {
    cout << "You win!" << endl;
    playerWins = true;
}
```

### Bug 3: Impossible Conditions
```cpp
// ❌ WRONG - Can never be true!
if (age < 18 && age > 65)

// ✅ RIGHT - Use OR for "either" condition
if (age < 18 || age > 65)
```

## 💡 Pro Tips from Previous Students

> "Draw your story as a flowchart FIRST. Coding is easy when you know the paths." - Sarah

> "Test every path! I had a whole branch players couldn't reach." - Mike

> "Add an inventory system - it makes the game feel more real." - Ashley

> "GameFAQs version made it click for me - the boss battle analogy for nested ifs was perfect!" - James

## 🚀 Looking Ahead

Next module (Weeks 7-8) you'll add LOOPS to create:
- Combat systems with multiple rounds
- Inventory management
- Save/load functionality
- Endless game modes

## Remember

**Choice is power.** Both in your code and in how you learn.

Pick the version that excites you more and dive in! Whether you prefer the formal Canvas approach or the playful GameFAQs style, you're learning the same crucial programming concepts.

**Module 3 Motto:**
### "Every decision in code is a fork in the road. Choose wisely!"

You're almost halfway through the course. Your code can now THINK! 🧠