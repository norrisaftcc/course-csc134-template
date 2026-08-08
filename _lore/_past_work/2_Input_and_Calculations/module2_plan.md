# Module 2: User Input and Advanced Calculations - Development Plan

## Module Overview
**Title:** Interactive Programs with User Input and Complex Calculations  
**Duration:** 2 weeks  
**Learning Objectives:**
- Master user input with `cin` for different data types
- Handle multi-word input with `getline()`
- Perform complex multi-step calculations
- Format output professionally with `iomanip`
- Build interactive programs that respond to user needs
- Debug common input-related issues

## Assignment Progression

### M2T1: Interactive Marketplace (Week 3, Day 1-2)
**Problem Context:** Transform the apple orchard into an interactive farmer's market stand
- User inputs their name, product, quantity, and price
- Calculate totals with user-provided values
- Handle basic input validation concepts
- **Skills:** Basic `cin`, variable input, dynamic calculations
- **Builds on:** M1LAB apple orchard concept

### M2T2: Restaurant Bill Calculator (Week 3, Day 3-4)
**Problem Context:** Create a tip calculator for restaurant bills
- User enters meal price
- Calculate tax (8%)
- User selects tip percentage
- Show breakdown and total
- **Skills:** Multiple inputs, percentage calculations, formatted output
- **New:** `fixed` and `setprecision` for currency

### M2LAB1: Custom Crate Manufacturing (Week 4, Day 1-2)
**Problem Context:** Help a crate company calculate costs and profits
- User inputs crate dimensions
- Calculate volume, material costs, labor
- Determine profit margins
- Professional cost analysis output
- **Skills:** Complex business calculations, multi-step problems
- **Based on:** Gaddis Chapter 3 case study

### M2HW1: Multi-Feature Banking System (Week 4, Day 3-5)
**Problem Context:** Create a comprehensive banking transaction system
- Multiple transaction types (deposit, withdrawal, transfer)
- Account management with user details
- Pizza party calculator (party planning feature)
- School spirit message generator
- **Skills:** String manipulation, complex I/O, multiple mini-programs
- **Culmination:** Combines all Module 2 concepts

## Pedagogical Approach

### Building on Module 1
- Students already understand variables and basic output
- Now making programs interactive and responsive
- Moving from hardcoded values to dynamic user input

### Common Input Challenges Addressed
- The "cin leaves newline" problem
- Handling spaces in names
- Input type mismatches
- Clear prompting techniques

### Progressive Complexity
- M2T1: Single inputs, simple calculations (25% difficulty)
- M2T2: Multiple inputs, formatted output (35% difficulty)
- M2LAB1: Business logic, complex formulas (55% difficulty)
- M2HW1: Multiple features, string manipulation (70% difficulty)

## Technical Focus

### New C++ Concepts
```cpp
// User input
cin >> variable;
getline(cin, stringVariable);

// Output formatting
#include <iomanip>
cout << fixed << setprecision(2);
cout << setw(10) << right;

// String operations
string fullName = firstName + " " + lastName;

// Input clearing (for mixed input types)
cin.ignore();
```

### Common Pitfalls to Address
1. **No prompt before input** - Always tell user what to enter
2. **Mixed cin and getline** - Teach about input buffer
3. **Uninitialized variables** - Emphasize initialization
4. **Integer division** - Ensure proper type casting

## Assessment Strategy

### Grading Tier System (Introduced in M2HW1)
- **Bronze (80%):** Complete core requirements
- **Silver (90%):** Add suggested improvements
- **Gold (100%):** Implement all features with polish
- **Bonus (+10%):** Creative enhancements

### Rubric Focus Areas
1. **Input Handling (30%)** - Proper prompts, input validation
2. **Calculations (30%)** - Correct formulas, appropriate types
3. **Output Formatting (20%)** - Professional presentation
4. **Code Quality (10%)** - Organization, comments
5. **User Experience (10%)** - Clear instructions, friendly interface

## Module Resources

### Required Readings
- Module slides on input/output streams
- Gaddis Chapter 3 (especially section 3.11)
- iomanip reference guide

### Support Materials
- Video: "Common cin Problems and Solutions"
- Reference: "Formatting Currency in C++"
- Debugging guide: "Input Buffer Issues"

## Learning Outcomes
By completing Module 2, students will:
- ✅ Create truly interactive programs
- ✅ Handle various input scenarios gracefully
- ✅ Format output professionally (especially currency)
- ✅ Solve multi-step business problems
- ✅ Debug common input-related issues
- ✅ Design user-friendly interfaces

## Module 2 to Module 3 Transition
Module 2 establishes interactive programming. Module 3 will add decision-making with if/else statements, allowing programs to respond differently based on user input conditions.