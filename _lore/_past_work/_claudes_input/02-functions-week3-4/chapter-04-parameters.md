# Chapter 4: Parameters and Scope
## Making Functions Smart and Powerful

## Functions with Parameters

So far, our functions have been like robots that do the same thing every time. But what if we want them to be smarter? That's where parameters come in!

### Sending Information to Functions

Parameters let you send information TO a function:

```cpp
// Function with one parameter
void greetByName(string name)
{
    cout << "Welcome, " << name << "!" << endl;
}

int main()
{
    greetByName("Alice");  // Output: Welcome, Alice!
    greetByName("Bob");    // Output: Welcome, Bob!
    
    return 0;
}
```

### Multiple Parameters

Functions can accept multiple parameters:

```cpp
void processOrder(int itemNumber, int quantity)
{
    cout << "Processing " << quantity << " of item #" << itemNumber << endl;
    
    double price = 0.0;
    switch(itemNumber)
    {
        case 1:
            price = 12.99;
            cout << "Pizza selected" << endl;
            break;
        case 2:
            price = 8.99;
            cout << "Burger selected" << endl;
            break;
        case 3:
            price = 6.99;
            cout << "Salad selected" << endl;
            break;
        default:
            cout << "Invalid item!" << endl;
            return;
    }
    
    double total = price * quantity;
    cout << "Subtotal: $" << total << endl;
}

int main()
{
    processOrder(1, 2);  // 2 pizzas
    processOrder(2, 1);  // 1 burger
    
    return 0;
}
```

## Understanding Scope

### What Happens in Functions, Stays in Functions!

Variables created inside a function only exist inside that function. This is called "scope."

```cpp
void function1()
{
    int secretNumber = 42;  // This variable only exists here
    cout << "Function 1 secret: " << secretNumber << endl;
}

void function2()
{
    // cout << secretNumber;  // ERROR! secretNumber doesn't exist here
    int secretNumber = 99;     // This is a DIFFERENT variable
    cout << "Function 2 secret: " << secretNumber << endl;
}

int main()
{
    function1();  // Prints: Function 1 secret: 42
    function2();  // Prints: Function 2 secret: 99
    
    // cout << secretNumber;  // ERROR! Doesn't exist in main either
    
    return 0;
}
```

### Visual Explanation of Scope

Think of each function as a separate room:

```
┌──────────────┐ ┌──────────────┐ ┌──────────────┐
│   main()     │ │  function1() │ │  function2() │
│              │ │              │ │              │
│  No access   │ │secretNumber  │ │secretNumber  │
│  to other    │ │    = 42      │ │    = 99      │
│  rooms!      │ │              │ │              │
└──────────────┘ └──────────────┘ └──────────────┘
     Room 1          Room 2          Room 3
```

Each room (function) has its own variables that can't be seen from other rooms!

## Pass by Value vs. Pass by Reference

### The Problem: Pass by Value

By default, C++ makes a COPY of values you pass to functions:

```cpp
// This DOESN'T work as expected
void tryToAddTax(double price)
{
    price = price * 1.08;  // Adds 8% tax to the COPY
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

### The Solution: Pass by Reference

Add an `&` to create a "portal" to the original variable:

```cpp
// This WORKS with the & symbol
void actuallyAddTax(double &price)  // Note the &
{
    price = price * 1.08;  // Changes the ORIGINAL!
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

**Output:**
```
Inside function: $10.80
In main: $10.80
```

### Visual Explanation

**Pass by Value (Copy):**
```
main: itemPrice[10.00] ──copy──> function: price[10.00]
                                  (changes don't affect original)
```

**Pass by Reference (Portal):**
```
main: itemPrice ←──portal──→ function: &price
      (same variable, two names!)
```

## When to Use Each

### Use Pass by Value When:
- You don't want the function to change the original
- Working with small data types (int, double, char)
- You need the function to work with its own copy

### Use Pass by Reference When:
- You WANT the function to modify the original
- Working with large objects (to avoid copying)
- The function needs to return multiple values

## Practical Example: Shopping Cart

Let's see both concepts in action:

```cpp
#include <iostream>
using namespace std;

// Pass by value - doesn't change original
void displayPrice(double price)
{
    cout << "Item costs: $" << price << endl;
    // price = 0;  // This wouldn't affect the original
}

// Pass by reference - DOES change original
void applyDiscount(double &price, double discountPercent)
{
    double discount = price * (discountPercent / 100);
    price = price - discount;
    cout << "Applied " << discountPercent << "% discount" << endl;
}

// Pass by reference - modifies multiple values
void calculateTotals(double subtotal, double &tax, double &total)
{
    tax = subtotal * 0.08;  // 8% tax
    total = subtotal + tax;
}

int main()
{
    double itemPrice = 50.00;
    double taxAmount = 0.0;
    double finalTotal = 0.0;
    
    displayPrice(itemPrice);        // Shows $50, doesn't change itemPrice
    applyDiscount(itemPrice, 20);   // Changes itemPrice to $40
    displayPrice(itemPrice);        // Shows $40
    
    calculateTotals(itemPrice, taxAmount, finalTotal);
    
    cout << "Subtotal: $" << itemPrice << endl;
    cout << "Tax: $" << taxAmount << endl;
    cout << "Total: $" << finalTotal << endl;
    
    return 0;
}
```

## Common Bugs and How to Fix Them

### Bug 1: Forgetting the & for Reference
```cpp
// ❌ WRONG - Won't modify original
void addTip(double bill)
{
    bill = bill * 1.20;
}

// ✅ RIGHT - Will modify original
void addTip(double &bill)
{
    bill = bill * 1.20;
}
```

### Bug 2: Trying to Access Out-of-Scope Variables
```cpp
// ❌ WRONG
void calculateTax()
{
    double tax = price * 0.08;  // What's price??
}

// ✅ RIGHT - Pass as parameter
void calculateTax(double price)
{
    double tax = price * 0.08;
}
```

### Bug 3: Misunderstanding Scope
```cpp
// ❌ WRONG - These are THREE different variables!
int x = 10;  // Global x

void func1()
{
    int x = 20;  // Local x in func1
}

void func2()
{
    int x = 30;  // Local x in func2
}

// ✅ RIGHT - Use parameters to share values
void func1(int &sharedValue)
{
    sharedValue = 20;
}

void func2(int &sharedValue)
{
    sharedValue = sharedValue + 10;
}
```

## Practice Challenges

### Challenge 1: Temperature Converter
Create functions that:
- Accept a temperature value as a parameter
- Convert between Celsius and Fahrenheit
- Use pass by reference to return the converted value

### Challenge 2: Grade Calculator
Build functions that:
- Accept test scores as parameters
- Calculate the average (pass by value)
- Determine letter grade and modify a grade variable (pass by reference)

### Challenge 3: Banking System
Create functions for:
- Checking balance (pass by value - just display)
- Making deposits (pass by reference - modify balance)
- Making withdrawals (pass by reference with validation)

## Key Takeaways

1. **Parameters** let you send information TO functions
2. **Scope** means variables in one function can't be seen by others
3. **Pass by value** makes a copy (original unchanged)
4. **Pass by reference** (&) creates a portal to the original
5. Use reference parameters when you need to modify the original value

## What's Next?

Now that you understand functions with parameters and scope, you're ready to build complex programs! In Module 3, we'll add decision-making (if/else statements) to make your functions even smarter.

Remember: Functions + Parameters + Decisions = Professional Programs! 🎯