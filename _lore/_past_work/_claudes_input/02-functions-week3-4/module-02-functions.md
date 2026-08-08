# Module 02: Functions - Breaking Down Problems Like a Pro Chef
## Weeks 3-4 | Badge: Program Design and Implementation

## 🎨 Flash-Powered Creative Development

### Monday: Concept Development
```
You: "Everyone's doing boring pizza places"
Flash: "What food do YOU love? What's missing in your college town? What would make classmates laugh?"
You: "There's no good Korean food, and everyone loves boba..."
Flash: "Could you combine them? What would that look like?"
Result: K-Pop Fusion Burger is born!
```

### Wednesday: Menu Engineering
```
You: "I need 5 items for my menu"
Flash: "What's your restaurant's story? Are you authentic? Fusion? Playful? What would each type serve?"
You: "Playful fusion!"
Flash: "So maybe item names that are puns? 'Seoul Food'? 'Kimchi Get It'? 'Boba Fett's Bounty'?"
```

### Friday: Polish & Personality
```
You: "My welcome message is boring"
Flash: "What music plays in K-Pop restaurants? What's the vibe? Energetic? How would staff greet you there?"
You: "Oh! 'Annyeonghaseyo! Welcome to Seoul Food!'"
Flash: "How could ASCII art support that theme?"
```

---

## 🎯 Module Overview

**Duration**: Weeks 3-4 (4 class sessions)  
**Project**: Restaurant Management System  
**Badge Alignment**: Program Design, Software Development Practices  
**AI Support**: Flash can help you communicate blockers (but not write code!)

### This Module's Superpower
By the end of Week 4, you'll transform from writing 100-line chaos to organized, reusable code. Functions are THE fundamental skill that separates beginners from programmers.

---

## 📚 Learning Objectives

By the end of this module, you will be able to:
- [ ] Create and call void functions
- [ ] Pass arguments to functions
- [ ] Understand scope (what happens in functions, stays in functions)
- [ ] Use function prototypes to organize code
- [ ] Pass by value vs. pass by reference
- [ ] Debug function-related errors systematically
- [ ] Write a complete multi-function program

---

## 🧑‍🍳 The Kitchen Metaphor That Makes Everything Click

Imagine you're a chef in a busy restaurant. You don't make an entire meal in one chaotic process. Instead, you have:

```
┌─────────────────────────────────────────────┐
│              RESTAURANT KITCHEN              │
├──────────────┬──────────────┬───────────────┤
│ PREP STATION │ GRILL STATION│ SAUCE STATION │
│   chopVeggies│   cookMeat   │  makeSauce    │
│      ()      │      ()      │      ()       │
└──────────────┴──────────────┴───────────────┘
                      ↓
              ┌──────────────┐
              │ PLATING TEAM │
              │ assembleDish │
              │      ()      │
              └──────────────┘
```

Functions in programming work the same way - they break big problems into manageable, specialized tasks!

---

## 📖 Chapter Content: Functions Fundamentals

### Part 1: Your First Function

```cpp
#include <iostream>
using namespace std;

// Function definition - like writing a recipe
void greetCustomer()
{
    cout << "🍕 Welcome to C++ Pizza Palace!" << endl;
    cout << "🎉 Where every byte is delicious!" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}

int main()
{
    // Function call - like saying "follow that recipe!"
    greetCustomer();
    
    cout << "What would you like to order?" << endl;
    
    return 0;
}
```

**Output:**
```
🍕 Welcome to C++ Pizza Palace!
🎉 Where every byte is delicious!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
What would you like to order?
```

### The Anatomy of a Function

```cpp
return_type function_name(parameters)
{
    // Function body
    // Do stuff here
}
```

Think of it like a job description:
- **return_type**: What the function gives back (`void` = nothing)
- **function_name**: The function's job title
- **parameters**: What the function needs to do its job
- **body**: The actual work being done

### Part 2: The Flow of Control

When you call a function, your program takes a detour:

```
main() starts
    │
    ▼
Line 1 of main
    │
    ▼
greetCustomer(); ──────┐
    │                  │
    │                  ▼
    │          ┌─────────────────┐
    │          │ greetCustomer() │
    │          │ - Print welcome │
    │          │ - Print slogan  │
    │          │ - Print line    │
    │          └────────┬────────┘
    │                   │
    ◄───────────────────┘
    │
    ▼
Continue main()
```

### Part 3: Function Prototypes - The Movie Trailer

```cpp
#include <iostream>
using namespace std;

// Function prototypes - declare now, define later!
void showMenu();
void takeOrder();
void processPayment();

int main()
{
    showMenu();      // We can call these even though
    takeOrder();     // they're defined below main!
    processPayment();
    
    return 0;
}

// Function definitions come after main
void showMenu()
{
    cout << "=== TODAY'S MENU ===" << endl;
    cout << "1. Pizza  ($12.99)" << endl;
    cout << "2. Burger ($8.99)" << endl;
    cout << "3. Salad  ($6.99)" << endl;
}

void takeOrder()
{
    cout << "Taking your order..." << endl;
}

void processPayment()
{
    cout << "Processing payment..." << endl;
}
```

---

## 🔬 Lab 3: Building Your Restaurant System

### Part A: Basic Functions (30 minutes)

**First, brainstorm with Flash:**
```
You: "Flash, what makes a restaurant welcoming?"
Flash: "Think about your favorite restaurant. What's the first thing you see? Hear? How do they greet you?"
You: "Oh! A catchy name, warm greeting, maybe hours or specials?"
Flash: "Perfect! How would you organize those into separate display functions?"
```

Create `restaurant_v1.cpp`:

```cpp
#include <iostream>
#include <string>
using namespace std;

// TODO: Create these function prototypes
// displayWelcome() - Shows restaurant name and greeting
// displayMenu() - Shows food options with prices
// displayGoodbye() - Thanks customer

int main()
{
    displayWelcome();
    displayMenu();
    
    // For now, just get one menu choice
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    cout << "You ordered item #" << choice << endl;
    
    displayGoodbye();
    
    return 0;
}

// TODO: Write function definitions below
```

**Expected Output:**
```
=================================
   WELCOME TO [YOUR NAME]'S CAFE   
=================================

--- MENU ---
1. Pizza  ($12.99)
2. Burger ($8.99)
3. Salad  ($6.99)

Enter your choice (1-3): 2
You ordered item #2

Thank you for visiting!
Come back soon!
```

### Part B: Functions with Parameters (45 minutes)

Extend your program with functions that accept parameters:

```cpp
// New function prototypes
void processOrder(int itemNumber);
void calculatePrice(int itemNumber, int quantity);
void printReceipt(double total);

// Example function with parameters
void processOrder(int itemNumber)
{
    cout << "Processing order for item #" << itemNumber << endl;
    
    switch(itemNumber)
    {
        case 1:
            cout << "One pizza coming up!" << endl;
            break;
        case 2:
            cout << "Burger on the grill!" << endl;
            break;
        case 3:
            cout << "Fresh salad being prepared!" << endl;
            break;
        default:
            cout << "Invalid item number!" << endl;
    }
}
```

### Part C: The Scope Challenge (30 minutes)

**Bug Hunt!** This code has scope issues. Fix them:

```cpp
#include <iostream>
using namespace std;

void function1()
{
    int secretNumber = 42;
    cout << "Function 1 secret: " << secretNumber << endl;
}

void function2()
{
    cout << "Function 2 trying to access: " << secretNumber << endl; // ERROR!
}

int main()
{
    function1();
    function2();
    cout << "Main trying to access: " << secretNumber << endl; // ERROR!
    
    return 0;
}
```

**Your task**: Understand WHY this fails, then fix it using parameters.

---

## 🎮 Lab 4: Pass by Reference - The Magic Portal

### Understanding the Problem

```cpp
// This DOESN'T work as expected
void tryToAddTax(double price)
{
    price = price * 1.08;  // Adds 8% tax
    cout << "Inside function: $" << price << endl;
}

int main()
{
    double itemPrice = 10.00;
    tryToAddTax(itemPrice);
    cout << "In main: $" << itemPrice << endl; // Still $10!
    
    return 0;
}
```

**Output:**
```
Inside function: $10.80
In main: $10.00
```

### The Solution: Reference Parameters

```cpp
// This WORKS with the & symbol
void actuallyAddTax(double &price)  // Note the &
{
    price = price * 1.08;  // Changes the original!
    cout << "Inside function: $" << price << endl;
}

int main()
{
    double itemPrice = 10.00;
    actuallyAddTax(itemPrice);
    cout << "In main: $" << itemPrice << endl; // Now $10.80!
    
    return 0;
}
```

### Visual Explanation

**Regular Parameter (Copy):**
```
main: itemPrice[10.00] ──copy──> function: price[10.00]
                                  (changes don't affect original)
```

**Reference Parameter (Portal):**
```
main: itemPrice ←──portal──→ function: &price
      (same variable, two names!)
```

---

## 🏆 Project: Complete Restaurant Management System

Build a professional restaurant ordering system using everything you've learned:

### Step 1: Design Your Restaurant Concept (with Flash!)

```
You: "Flash, I want my restaurant to stand out. Help me brainstorm!"
Flash: "What cuisine interests you? What's popular with college students? What matches your personality?"
You: "I love K-Pop and burgers..."
Flash: "K-Pop Fusion Burger! What would that menu look like? Special sauces? Korean-style fries? Boba drinks?"
You: "YES! The 'Seoul Food' combo with kimchi fries and taro boba!"
Flash: "How would you organize that in your menu display function? What categories make sense?"
```

### Step 2: Implementation Structure

```cpp
#include <iostream>
#include <string>
using namespace std;

// Constants (Flash helped brainstorm these!)
// "What's competitive but profitable pricing for fusion food?"
const double BULGOGI_BURGER_PRICE = 14.99;  // Premium item
const double KIMCHI_FRIES_PRICE = 6.99;     // Unique side
const double TARO_BOBA_PRICE = 5.99;        // Trendy drink
const double COMBO_DISCOUNT = 0.15;         // 15% off combos
const double STUDENT_DISCOUNT = 0.10;       // Flash: "College town needs student deals!"
const double TAX_RATE = 0.08;

// Function prototypes
void displayWelcome();
void displayMenu();
int getValidChoice(int min, int max);
void processOrder(int choice, double &subtotal);
void applyDiscounts(double &subtotal);
void calculateTotals(double subtotal, double &tax, double &total);
void displayReceipt(double subtotal, double tax, double total);

int main()
{
    double runningSubtotal = 0.0;
    double tax = 0.0;
    double finalTotal = 0.0;
    char orderMore = 'y';
    
    displayWelcome();
    
    // Order loop
    while (orderMore == 'y' || orderMore == 'Y')
    {
        displayMenu();
        int choice = getValidChoice(1, 3);
        processOrder(choice, runningSubtotal);
        
        cout << "Current subtotal: $" << runningSubtotal << endl;
        cout << "Order more? (y/n): ";
        cin >> orderMore;
    }
    
    // Calculate final amounts
    applyDiscounts(runningSubtotal);
    calculateTotals(runningSubtotal, tax, finalTotal);
    
    // Show receipt
    displayReceipt(runningSubtotal, tax, finalTotal);
    
    return 0;
}

// YOUR TASK: Implement all the functions!
// Each should do ONE clear job
// Use parameters to pass data between them
// Make it match YOUR restaurant theme!
```

---

## 🦆 Flash: Your Sous Chef (Weeks 3-4)

Flash can't write code (can't run the grill), but a good sous chef does SO much more than cook!

### Flash as Your Creative Partner:

**1. Restaurant Concept Development**
```
You: "I want to make my restaurant unique - thinking K-Pop fusion?"
Flash: "Interesting! What food combinations could work? What would you call a kimchi burger? What about drinks?"
You: "Ooh, we could have a 'Seoul Food' section!"
Flash: "How would you price premium fusion items versus classics? What categories make sense?"
```

**2. Menu Design & Pricing**
```
You: "Help me brainstorm menu items for K-Pop Fusion Burger"
Flash: "What are signature K-Pop flavors? How about:
- Gochujang Glaze Burger?
- Kimchi Fries?
- Bulgogi Beef Burger?
- What boba flavors match burgers?"
You: "Perfect! Taro boba with savory food could work!"
```

**3. Writing a Good Help Email**
```
You: "I'm stuck and need to email the instructor"
Flash: "What specific error are you seeing? What have you tried? Let's organize your thoughts..."

Result: "Hi Instructor, I'm getting 'segmentation fault' in my processOrder function when choice is 4. I've tried checking my array bounds and adding debug statements. Could we review this in office hours?"
```

**4. Test Case Planning**
```
You: "What should I test in my restaurant system?"
Flash: "What happens if someone orders item 99? Orders negative quantities? What's your most expensive possible order? Cheapest?"
```

**5. User Experience Design**
```
You: "My menu display is boring"
Flash: "What would make it exciting? ASCII art? Borders? How would a real K-Pop restaurant menu look? Colorful? Energetic?"
```

**6. Debugging Strategy (Not Solutions!)**
```
You: "My function isn't changing the value"
Flash: "Are you passing by value or reference? How can you check what the value is inside the function? Where would you put a cout to see?"
```

### Flash CANNOT:
- Write your functions (can't cook the food)
- Show you the syntax (won't give you the recipe)
- Fix your code (won't flip your burger for you)
- Tell you exactly what's wrong (but will ask questions to help you find it!)

### But Flash CAN:
- Brainstorm creative ideas (menu concepts!)
- Help organize your thoughts (what to test)
- Improve your communication (emails, issues)
- Be your rubber duck (explain your logic)
- Plan your approach (what functions do you need?)
- Make your project fun (K-Pop Burger with boba? Yes!)

---

## 🎯 Practice Challenges

### Challenge 1: Temperature Converter Station
Create a program with these functions:
- `displayTempMenu()` - Shows conversion options
- `getTemperature()` - Gets input with validation
- `celsiusToFahrenheit(double celsius)` 
- `fahrenheitToCelsius(double fahrenheit)`
- `kelvinToCelsius(double kelvin)`

### Challenge 2: Grade Calculator Suite
Build a grade management system:
- `getTestScore(int testNumber)` - Gets one test score
- `calculateAverage(double t1, double t2, double t3)`
- `determineLetterGrade(double average)`
- `shouldGetExtraCredit(double average)` - Returns true if avg > 95
- `displayReport(string name, double avg, char grade)`

### Challenge 3: ATM Simulator
Create an ATM with:
- `displayATMMenu()`
- `validatePIN(int pin)` - Returns true/false
- `checkBalance(double balance)` - Display only
- `deposit(double &balance)` - Modifies balance
- `withdraw(double &balance)` - Checks for sufficient funds
- `quickCash(double &balance, int amount)` - $20, $40, $60 options

---

## 🐛 Common Week 3-4 Bugs

### Bug 1: Function Used Before Declaration
```cpp
// ❌ ERROR
int main()
{
    greet();  // Error: 'greet' was not declared
    return 0;
}

void greet()
{
    cout << "Hello!" << endl;
}

// ✅ FIX: Add prototype or move function above main
```

### Bug 2: Forgetting Parentheses in Function Call
```cpp
// ❌ ERROR
int main()
{
    displayMenu;  // This doesn't call the function!
    return 0;
}

// ✅ FIX
int main()
{
    displayMenu();  // Need parentheses to call
    return 0;
}
```

### Bug 3: Misunderstanding Scope
```cpp
// ❌ ERROR
void calculateTax()
{
    double tax = price * 0.08;  // What's price??
}

// ✅ FIX: Pass as parameter
void calculateTax(double price)
{
    double tax = price * 0.08;
}
```

### Bug 4: Pass by Value When You Need Reference
```cpp
// ❌ Doesn't modify original
void addTip(double bill)
{
    bill = bill * 1.20;
}

// ✅ FIX: Use reference
void addTip(double &bill)
{
    bill = bill * 1.20;
}
```

---

## 📊 Assessment Rubric

### Restaurant System Project (100 points)

| Component | Points | Requirements |
|-----------|--------|--------------|
| **Function Organization** | 25 | At least 6 meaningful functions, each doing ONE job |
| **Parameter Usage** | 25 | Correct use of parameters, including at least 2 reference parameters |
| **Code Runs** | 20 | Compiles and executes without crashes |
| **User Experience** | 15 | Clear prompts, formatted output, handles basic invalid input |
| **Code Quality** | 10 | Good names, comments explaining purpose, consistent indentation |
| **Flash Debugging Log** | 5 | Shows using Flash to work through at least one problem |

### What Makes an 'A' Project:
- Clean separation of concerns (each function has ONE job)
- Creative, cohesive restaurant theme (K-Pop Fusion? Cyberpunk Cafe? Viking Feast Hall?)
- Professional-looking output with formatting that matches your theme
- Unique menu items with thoughtful pricing (Flash helped brainstorm!)
- Input validation (doesn't crash on bad input)
- Special features (student discount? happy hour? combo deals?)
- Clear debugging process in Flash logs showing creative development

---

## 🎬 Week 4 Culmination

### The "Function Mastery" Checklist
Before moving to Week 5, you should be able to:

- [ ] Write a void function that displays information
- [ ] Create a function that accepts parameters
- [ ] Use a function prototype
- [ ] Explain why variables in one function can't be seen by another
- [ ] Pass by reference when you need to modify a value
- [ ] Debug "undefined reference" errors
- [ ] Break a 100+ line program into organized functions

### The Mini-Boss Battle
**Friday Week 4**: Live coding challenge!
- 20 minutes
- Given a messy 50-line program
- Refactor it into clean functions
- Must compile and run
- Explain your design choices

---

## 💡 Pro Tips from Previous Students

> "Draw boxes for each function and arrows for data flow. It really helps visualize what goes where." - Maria, now at GameDev Studios

> "Name your functions like verbs: calculateTax(), displayMenu(), validateInput(). Makes everything clearer." - James, Systems Analyst

> "When Flash asks 'What does this function need to know?', that's your parameter list!" - Ashley, Junior Developer

> "I spent 30 minutes with Flash designing 'Raccoon's Trash Panda Tacos' theme. Best decision ever. The instructor loved the creativity!" - David, Spring 2024

> "Flash helped me realize my 'Space Station Sushi' needed different categories: 'Earth Classics' vs 'Alien Delicacies'. Made my menu function so much better!" - Kim, Fall 2023

---

## 🆘 Getting Help

### Your Escalation Path:
1. **Try to compile** - Read the FIRST error carefully
2. **Add cout statements** - See what values actually are
3. **Ask Flash** - "How do I debug an undefined reference error?"
4. **Check Discord #week3-functions** - Someone else hit the same bug
5. **Office Hours** - Bring your Flash conversation log
6. **Email Instructor** - Flash can help you write a clear technical email!

### Sample Tech Support Email (Flash-Assisted):
```
Subject: Week 3 Lab - Undefined Reference Error in Restaurant Project

Hi Instructor,

Error: undefined reference to 'processOrder(int)'
Location: Line 24 in main()
What I've tried:
- Checked spelling (matches exactly)
- Verified prototype exists
- Function is defined after main

Could you help me understand what I'm missing?

Attached: restaurant.cpp and Flash debugging log

Thanks,
[Your name]
```

---

## 🚀 Looking Ahead to Week 5

Next week you'll add DECISION MAKING to your functions:
- if/else statements
- switch cases  
- Boolean logic
- Your restaurant will get smart about orders!

**Week 5 Preview**: "Do you qualify for the senior discount? Is it happy hour? Did you order the daily special?"

---

## 📌 Remember

**Functions are just named chunks of code that do specific jobs.**

You already think in functions:
- brushTeeth()
- driveToWork()  
- makeCoffe()
- checkEmail()

Programming is just teaching the computer to follow your functions!

---

## Module 2 Motto
### "A function should do one thing, do it well, and do it only"
*- Unix Philosophy (and good life advice)*

You're 25% through the course. You can now write organized, reusable code. That's huge! 🎉