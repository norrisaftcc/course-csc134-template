# Module 1: Foundations (Weeks 1-2)

## Welcome to Programming! 🚀

This module introduces the fundamental building blocks of C++ programming. By the end of Week 2, you'll have built your first interactive program - a Pizza Order Calculator that handles real customer orders!

## Learning Objectives

By completing this module, you will be able to:
- Write, compile, and run C++ programs
- Use variables to store different types of data
- Get input from users and display formatted output
- Perform calculations and handle currency
- Debug common syntax errors
- Build a complete, useful program

## Module Contents

### Week 1: Hello C++ World
- **Chapter 1**: Introduction to C++ Programming
  - Program structure and syntax
  - Your first "Hello World" program
  - Understanding compilation
  - Common beginner mistakes

### Week 2: Variables and Interaction
- **Chapter 2**: Input, Processing, and Output
  - Variables and data types
  - Getting user input
  - Calculations and operators
  - The Pizza Calculator Project

## Project: Pizza Order Calculator 🍕

You'll build this program in stages:

### Version 1 (Week 1 Practice)
- Display a welcome message
- Show menu with prices
- Basic output formatting

### Version 2 (Week 2 Lab)
- Get customer input (pizza size, toppings)
- Calculate subtotal
- Display formatted receipt

### Version 3 (Week 2 Project)
- Add tax calculation
- Handle multiple pizzas
- Input validation
- Professional receipt format

## Key Concepts Map

```
Program Structure
    ├── Headers (#include)
    ├── Namespace (using namespace std)
    └── Main Function
        ├── Variables (data storage)
        ├── Input (cin)
        ├── Processing (calculations)
        └── Output (cout)
```

## Common Challenges & Solutions

### Challenge 1: "My program closes immediately!"
**Solution**: Add `system("pause");` before `return 0;` (Windows) or run with Ctrl+F5

### Challenge 2: "cin only reads one word!"
**Solution**: Use `getline(cin, variable)` for strings with spaces

### Challenge 3: "My calculations are wrong!"
**Solution**: Check data types - integer division truncates (5/2 = 2, not 2.5)

### Challenge 4: "So many semicolon errors!"
**Solution**: Every statement needs a semicolon, but not after braces or #include

## Practice Exercises

### Exercise 1: Temperature Converter
- Input: Fahrenheit temperature
- Process: Convert to Celsius
- Output: Both temperatures

### Exercise 2: Tip Calculator
- Input: Meal cost, tip percentage
- Process: Calculate tip and total
- Output: Formatted bill

### Exercise 3: Movie Ticket Booth
- Input: Number of adult/child/senior tickets
- Process: Calculate total with tax
- Output: Receipt with breakdown

## Debugging Challenges

The `exercises/` folder contains intentionally broken programs. Your mission:
1. Find all bugs (count provided)
2. Fix them
3. Verify program works correctly
4. Document what each bug taught you

## Assessment Checklist

### Week 1 Complete When:
- [ ] Hello World runs successfully
- [ ] Can identify parts of program structure
- [ ] Understand compilation process
- [ ] Complete Chapter 1 exercises

### Week 2 Complete When:
- [ ] Pizza Calculator v2 works
- [ ] All three data types used correctly
- [ ] Input validation implemented
- [ ] Debugging exercises completed
- [ ] Can explain every line of your code

## Tips for Success

1. **Type everything** - Don't copy/paste while learning
2. **Compile often** - After every few lines
3. **Read errors carefully** - They tell you exactly what's wrong
4. **Experiment** - Change things and see what happens
5. **Comment your code** - Explain your thinking

## Getting Help

- **Syntax Reference**: See `resources/syntax-cheatsheet.md`
- **Common Errors**: See `resources/common-errors.md`
- **Discord Channel**: #week1-2-foundations
- **Office Hours**: See syllabus
- **Peer Support**: Find a study buddy!

## Motivational Note

Everyone struggles with their first programs. If you're frustrated, you're doing it right! The moment when your Pizza Calculator finally works will be magical - that's when you become a programmer.

Remember: **Professional programmers Google basic syntax daily. You're not behind - you're exactly where you should be.**

## Ready?

Start with Chapter 1 and write your first program. It might take an hour to get three lines working. That's normal. That's learning. That's programming.

Let's go! 🎮
