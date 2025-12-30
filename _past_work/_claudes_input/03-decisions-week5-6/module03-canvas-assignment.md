# Module 03: Decision Structures in C++ Programming
## CSC 134 - Weeks 5-6

---

### Module Information
- **Duration:** 2 weeks (Week 5-6)
- **Points:** 100 points (Project 1)
- **Due Date:** End of Week 6, 11:59 PM
- **Submission:** Via Canvas
- **Badge Alignment:** C++ Syntax and Control Structures

---

## Learning Objectives

Upon successful completion of this module, students will be able to:

1. **Implement** basic decision structures using if, if-else, and if-else-if statements
2. **Apply** all six relational operators (>, <, >=, <=, ==, !=) correctly in conditional expressions
3. **Construct** multi-way selection structures using switch statements
4. **Combine** multiple conditions using logical operators (&&, ||, !)
5. **Design** programs with nested decision structures
6. **Validate** user input to prevent runtime errors
7. **Debug** logic errors systematically using trace statements
8. **Create** a complete interactive program with branching logic

---

## Module Overview

This module introduces decision-making structures in C++ programming, enabling you to create programs that respond intelligently to user input and changing conditions. You will develop a text-based interactive game that demonstrates mastery of conditional logic and program flow control.

**Note on Theme Selection:** While examples use a fantasy adventure theme, students are encouraged to choose any interactive scenario that interests them (e.g., business simulation, educational quiz system, interactive story, resource management game). The AI assistant Flash can help adapt examples to your chosen theme and even assist with ASCII art for display elements.

---

## Required Reading

### Week 5 Materials
- Chapter 4: Decision Structures (Sections 4.1-4.6)
- Supplemental: Relational Operators Reference Guide
- Video Lecture: "Understanding Program Flow" (23 minutes)

### Week 6 Materials
- Chapter 4: Decision Structures (Sections 4.7-4.10)
- Supplemental: Input Validation Techniques
- Video Lecture: "Debugging Logic Errors" (18 minutes)

---

## Content Outline

### Week 5: Fundamental Decision Structures

#### Topic 1: The if Statement
The if statement executes a block of code when a condition evaluates to true.

**Syntax:**
```cpp
if (condition)
{
    // Statements executed when condition is true
}
```

**Key Concept:** Distinguish between assignment (=) and comparison (==) operators. This is a critical distinction that causes frequent errors.

#### Topic 2: The if-else Statement
Provides two alternative paths of execution based on a condition.

**Syntax:**
```cpp
if (condition)
{
    // Executed when condition is true
}
else
{
    // Executed when condition is false
}
```

#### Topic 3: Nested if Statements and else-if Chains
Multiple conditions can be checked in sequence or nested within each other.

**Example Structure:**
```cpp
if (condition1)
{
    // First condition true
}
else if (condition2)
{
    // First false, second true
}
else if (condition3)
{
    // First two false, third true
}
else
{
    // All conditions false
}
```

#### Topic 4: Relational Operators
- Greater than (>)
- Less than (<)
- Greater than or equal (>=)
- Less than or equal (<=)
- Equal to (==)
- Not equal to (!=)

### Week 6: Advanced Decision Structures

#### Topic 5: The switch Statement
Efficient multi-way selection based on the value of an expression.

**Syntax:**
```cpp
switch(expression)
{
    case value1:
        // Statements
        break;
    case value2:
        // Statements
        break;
    default:
        // Default statements
}
```

**Important:** Include break statements to prevent fall-through behavior.

#### Topic 6: Logical Operators
- AND (&&): Both operands must be true
- OR (||): At least one operand must be true
- NOT (!): Negates the boolean value

**Application Examples:**
- Range validation: `if (value >= min && value <= max)`
- Multiple valid options: `if (choice == 1 || choice == 2 || choice == 3)`
- Negation: `if (!isGameOver)`

#### Topic 7: Input Validation
Implementing robust input validation to prevent program crashes.

**Standard Pattern:**
```cpp
int choice;
bool validInput = false;

while (!validInput)
{
    cout << "Enter choice (1-3): ";
    cin >> choice;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
    }
    else if (choice < 1 || choice > 3)
    {
        cout << "Please enter a value between 1 and 3." << endl;
    }
    else
    {
        validInput = true;
    }
}
```

---

## Laboratory Exercises

### Lab 5: Introduction to Decision Structures (Week 5)
**Objective:** Create a simple interactive program demonstrating basic decision structures.

**Requirements:**
1. Implement at least three if statements
2. Include one if-else structure
3. Track and modify program state variables
4. Provide meaningful user feedback

**Deliverable:** `lab5_decisions.cpp`

### Lab 6: Advanced Decision Making (Week 6)
**Objective:** Extend your program with complex decision structures.

**Requirements:**
1. Implement a switch statement for menu selection
2. Use logical operators to combine conditions
3. Include nested decision structures
4. Implement comprehensive input validation

**Deliverable:** `lab6_advanced.cpp`

---

## Project 1: Interactive Decision-Based Program

### Project Description
Design and implement a text-based interactive program that demonstrates comprehensive understanding of decision structures. The program should present users with choices that affect the program's state and lead to different outcomes.

### Technical Requirements

#### Minimum Requirements (70% - C Grade)
- Minimum of 3 distinct scenes or decision points
- Implementation of if-else structures
- State tracking (e.g., score, health, resources)
- At least one challenge or puzzle element
- Two different program endings
- Basic input validation

#### Standard Requirements (85% - B Grade)
- Minimum of 5 distinct scenes
- Combination of if-else and switch statements
- Multiple state variables tracked throughout
- Interactive menu system using switch
- Three different program endings
- Three or more functions beyond main()
- Comprehensive input validation

#### Advanced Requirements (95%+ - A Grade)
- Seven or more distinct scenes
- Complex nested decision structures
- Sophisticated state management system
- Strategic decision-making elements
- Inventory or resource management system
- Save/checkpoint functionality
- Visual enhancements (ASCII art, formatting)
- Hidden features or alternate paths

### Grading Rubric

| Component | Weight | Criteria |
|-----------|--------|----------|
| **Technical Implementation** | 40% | Correct use of decision structures, proper syntax, appropriate operator usage |
| **Program Design** | 25% | Logical flow, meaningful choices, coherent structure |
| **Code Quality** | 20% | Organization, readability, comments, function usage |
| **Testing & Validation** | 15% | Input validation, error handling, documented testing |

### Required Documentation

1. **Source Code** (`project1.cpp`)
   - Well-commented code explaining logic
   - Proper formatting and indentation
   - Meaningful variable and function names

2. **Testing Log** (`testing_log.txt`)
   - Document at least 5 test cases
   - Include edge cases and invalid input testing
   - Note any bugs found and how they were resolved

3. **AI Interaction Log** (`ai_conversation.txt`)
   - Document any assistance received from AI tools
   - Focus on debugging and conceptual understanding
   - Note: Direct code generation is not permitted

4. **Design Document** (`design.txt`)
   - Program flow diagram or outline
   - Description of major decision points
   - Explanation of state variables used

---

## Assignment Policies

### Acceptable AI Tool Usage
Students may use AI assistants (like Flash) for:
- Understanding error messages
- Discussing debugging strategies
- Clarifying conceptual questions
- Adapting themes and creating ASCII art
- Formatting and organizing ideas

AI tools may NOT be used to:
- Generate complete code solutions
- Write entire functions or decision structures
- Complete the assignment for you

### Late Submission Policy
- On time: 100% credit available
- 1 day late: Maximum 90%
- 2 days late: Maximum 80%
- 3+ days late: Maximum 70%

### Academic Integrity
All submitted code must be your own work. While collaboration on concepts is encouraged, direct code sharing is prohibited. Any use of external resources must be properly cited.

---

## Resources and Support

### Getting Help
1. **Office Hours:** Tuesday/Thursday 2:00-3:30 PM
2. **Discord Channel:** #module03-decisions
3. **Peer Tutoring:** Available in Learning Center
4. **Canvas Discussion Board:** "Module 3 Q&A"

### Supplemental Materials
- Decision Structure Flowchart Templates
- Common Logic Patterns Reference Sheet
- Debugging Checklist for Logic Errors
- Example Programs (view after attempting labs)

### Tips for Success
1. Start early and test incrementally
2. Draw flowcharts before coding complex logic
3. Use descriptive variable names
4. Test all possible paths through your program
5. Add cout statements to trace program flow during debugging

---

## Module Schedule

| Week | Day | Topic | Assignment |
|------|-----|-------|------------|
| 5 | Monday | if statements, relational operators | Read Ch. 4.1-4.3 |
| 5 | Wednesday | if-else, nested decisions | Lab 5 due |
| 5 | Friday | else-if chains, complex conditions | Practice problems |
| 6 | Monday | switch statements | Read Ch. 4.7-4.8 |
| 6 | Wednesday | Logical operators, validation | Lab 6 due |
| 6 | Friday | Integration and testing | Project 1 due |

---

## Success Criteria

By the end of this module, you should be able to confidently answer:
- Can I write conditional statements with correct syntax?
- Do I understand the difference between = and ==?
- Can I combine multiple conditions logically?
- Can I choose the appropriate decision structure for a given problem?
- Can I validate input to prevent program crashes?
- Can I trace through complex decision logic?
- Can I design and implement a complete interactive program?

---

## Questions?

Please post questions to the Canvas discussion board or visit office hours. Remember that struggling with logic is normal - debugging is a crucial programming skill that improves with practice.

---

*This module document was last updated at the beginning of Week 5. Check Canvas announcements for any updates or clarifications.*