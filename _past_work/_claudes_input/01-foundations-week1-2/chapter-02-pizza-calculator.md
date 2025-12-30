# Chapter 2: Input, Processing, and Output - Your First Interactive Program

## Welcome to the World of Interactive Programming!

Remember when you first used a calculator? You pressed buttons (input), it did math (processing), and showed you the answer (output). That's exactly what we're learning today - how to make C++ programs that actually interact with users!

## Chapter Project: Building a Pizza Order Calculator 🍕

Throughout this chapter, we'll build a real program that calculates the cost of a pizza order. By the end, you'll have a working calculator that handles toppings, sizes, and even calculates tips!

## Part 1: Displaying Output with `cout`

Let's start with the basics - making your program talk to the user.

### Your First Output Statement

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Welcome to C++ Pizza Palace!";
    return 0;
}
```

**Program Output:**
```
Welcome to C++ Pizza Palace!
```

Wait... why is the cursor sitting right after the exclamation mark? Let's fix that!

### The Magic of `endl` (End Line)

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Welcome to C++ Pizza Palace!" << endl;
    cout << "Home of the Binary Byte Pizza!" << endl;
    return 0;
}
```

**Program Output:**
```
Welcome to C++ Pizza Palace!
Home of the Binary Byte Pizza!
```

Much better! `endl` moves to a new line AND flushes the output buffer (ensures text appears immediately).

### Chaining Output with `<<`

The `<<` operator (called "stream insertion operator") can be chained like train cars:

```cpp
cout << "Today's " << "special " << "is " << "pepperoni!" << endl;
```

Think of `<<` as an arrow pointing data toward the screen!

## Part 2: Variables - Your Program's Memory

### What Are Variables?

Imagine your desk has labeled drawers:
```
┌─────────────┐  ┌─────────────┐  ┌─────────────┐
│   age: 21   │  │ price: 15.99│  │ name: "Alex"│
└─────────────┘  └─────────────┘  └─────────────┘
     int              double           string
```

Each drawer (variable) has:
- A **label** (variable name)
- A **type** (what kind of data it holds)
- A **value** (what's currently stored)

### C++ Data Types You'll Actually Use

| Type | What It Stores | Example | When to Use |
|------|---------------|---------|-------------|
| `int` | Whole numbers | 42, -17, 0 | Counting, ages, quantities |
| `double` | Decimals | 3.14, 19.99 | Money, measurements, calculations |
| `string` | Text | "Hello", "Pizza" | Names, messages, addresses |
| `char` | Single character | 'A', '7', '!' | Menu choices, grades |
| `bool` | true/false | true, false | Yes/no decisions |

### Declaring Variables

```cpp
#include <iostream>
#include <string>  // Needed for string variables!
using namespace std;

int main()
{
    // Declare variables (create the drawers)
    int pizzaCount;
    double pizzaPrice;
    string customerName;
    
    // Initialize variables (put values in drawers)
    pizzaCount = 2;
    pizzaPrice = 12.99;
    customerName = "Sarah";
    
    // Or declare AND initialize in one line!
    int drinkCount = 3;
    double drinkPrice = 2.50;
    
    return 0;
}
```

### Variable Naming Rules (The Law of the Land)

✅ **ALLOWED:**
- Start with letter or underscore: `total`, `_count`
- Use letters, numbers, underscores: `player1Score`
- Be descriptive: `studentAge` (not just `a`)

❌ **NOT ALLOWED:**
- Start with number: ~~`2fast2furious`~~
- Use spaces: ~~`my variable`~~
- Use keywords: ~~`int int = 5;`~~
- Use special characters: ~~`total$`~~

**Pro Tip**: Use camelCase for multi-word names: `totalPizzaCost` not `totalpizzacost`

### Displaying Variables

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string restaurant = "C++ Pizza Palace";
    int yearEstablished = 2020;
    double avgRating = 4.8;
    
    cout << "Welcome to " << restaurant << endl;
    cout << "Serving you since " << yearEstablished << endl;
    cout << "Average rating: " << avgRating << " stars" << endl;
    
    return 0;
}
```

**Program Output:**
```
Welcome to C++ Pizza Palace
Serving you since 2020
Average rating: 4.8 stars
```

## Part 3: Getting Input with `cin`

Now for the fun part - making your program listen!

### Basic Input

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age;
    
    cout << "Welcome! What's your name? ";
    cin >> name;
    
    cout << "Hi " << name << "! How old are you? ";
    cin >> age;
    
    cout << "Great! " << name << ", age " << age 
         << ", you're ready to order!" << endl;
    
    return 0;
}
```

**Program Interaction:**
```
Welcome! What's your name? Maria
Hi Maria! How old are you? 22
Great! Maria, age 22, you're ready to order!
```

### The Space Problem 😱

Here's where students often get frustrated:

```cpp
string fullName;
cout << "Enter your full name: ";
cin >> fullName;  // This only reads until the first space!
cout << "Hello, " << fullName << endl;
```

**Problem Output:**
```
Enter your full name: Maria Garcia
Hello, Maria
```

Where did "Garcia" go?! 😭

### The Solution: `getline()`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    
    cout << "Enter your full name: ";
    getline(cin, fullName);  // Reads the ENTIRE line!
    
    cout << "Hello, " << fullName << "!" << endl;
    
    return 0;
}
```

**Fixed Output:**
```
Enter your full name: Maria Garcia
Hello, Maria Garcia!
```

## Part 4: Processing - Let's Do Math!

### C++ Arithmetic Operators

| Operator | What it Does | Example | Result |
|----------|-------------|---------|--------|
| `+` | Addition | `10 + 3` | 13 |
| `-` | Subtraction | `10 - 3` | 7 |
| `*` | Multiplication | `10 * 3` | 30 |
| `/` | Division | `10 / 3` | 3 (integer division!) |
| `%` | Modulus (remainder) | `10 % 3` | 1 |

### Our Pizza Calculator Begins!

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Pizza prices
    const double SMALL_PRICE = 8.99;
    const double MEDIUM_PRICE = 12.99;
    const double LARGE_PRICE = 16.99;
    const double TOPPING_PRICE = 1.50;
    const double TAX_RATE = 0.08;  // 8% tax
    
    // Get order details
    int pizzaSize;
    int toppingCount;
    
    cout << "=== C++ Pizza Palace Order System ===" << endl;
    cout << "Pizza Sizes:" << endl;
    cout << "1. Small ($8.99)" << endl;
    cout << "2. Medium ($12.99)" << endl;
    cout << "3. Large ($16.99)" << endl;
    cout << "\nEnter size (1-3): ";
    cin >> pizzaSize;
    
    cout << "How many toppings? ";
    cin >> toppingCount;
    
    // Calculate base price
    double basePrice;
    if (pizzaSize == 1)
        basePrice = SMALL_PRICE;
    else if (pizzaSize == 2)
        basePrice = MEDIUM_PRICE;
    else
        basePrice = LARGE_PRICE;
    
    // Calculate totals
    double toppingCost = toppingCount * TOPPING_PRICE;
    double subtotal = basePrice + toppingCost;
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;
    
    // Display receipt
    cout << "\n--- Your Receipt ---" << endl;
    cout << "Pizza: $" << basePrice << endl;
    cout << "Toppings (" << toppingCount << "): $" << toppingCost << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;
    
    return 0;
}
```

### Constants: Values That Never Change

Notice we used `const`? These are like variables wearing a "DO NOT CHANGE" sign:

```cpp
const double PI = 3.14159;        // Mathematical constant
const int VOTING_AGE = 18;        // Legal constant
const double SPEED_OF_LIGHT = 299792458;  // Physical constant
```

**Why use constants?**
1. Prevents accidental changes
2. Makes code clearer
3. Easy to update (change in one place)

## Part 5: Comments - Notes to Your Future Self

```cpp
// This is a single-line comment
// Use for quick notes

/*
   This is a multi-line comment.
   Perfect for longer explanations
   or temporarily disabling code.
*/

int main()
{
    // Calculate area of circle
    double radius = 5.0;
    double area = 3.14159 * radius * radius;  // PI * r²
    
    /* TODO: Add error checking
       Make sure radius is positive */
    
    return 0;
}
```

## Practice Projects

### Project 1: Temperature Converter
Create a program that:
1. Asks for temperature in Fahrenheit
2. Converts to Celsius: C = (F - 32) × 5/9
3. Displays both temperatures

### Project 2: Tip Calculator
Create a program that:
1. Asks for meal cost
2. Asks for tip percentage
3. Calculates tip amount and total

### Project 3: Movie Ticket Booth
Create a program that:
1. Shows ticket prices (Adult: $12, Child: $8, Senior: $10)
2. Asks how many of each type
3. Calculates total cost with 6% sales tax

## Common Beginner Mistakes (We All Make Them!)

### 1. Forgetting to Include Libraries
```cpp
// ❌ WRONG - Will error with 'string not defined'
int main() {
    string name;  // Error!
}

// ✅ RIGHT
#include <string>
int main() {
    string name;  // Works!
}
```

### 2. Integer Division Surprise
```cpp
// ❌ Unexpected Result
int a = 5, b = 2;
double result = a / b;  // Result is 2.0, not 2.5!

// ✅ Fixed
double result = static_cast<double>(a) / b;  // Result is 2.5
```

### 3. Uninitialized Variables
```cpp
// ❌ Dangerous
int count;
count = count + 1;  // What was count before? Random garbage!

// ✅ Safe
int count = 0;
count = count + 1;  // Now it's 1
```

## Your Learning Journey Checklist

- [ ] I can display text with `cout`
- [ ] I understand the difference between `int`, `double`, and `string`
- [ ] I can get input with `cin`
- [ ] I know when to use `getline()` for strings with spaces
- [ ] I can perform calculations and store results
- [ ] I understand why constants are useful
- [ ] I've completed at least one practice project

## Words of Encouragement

If you're feeling overwhelmed, remember:
- **Every expert was once a beginner**
- **Errors are teachers in disguise**
- **Small progress is still progress**

The syntax might feel weird now, but soon you'll be writing C++ as naturally as texting a friend. Keep experimenting, keep breaking things (in your code, not your computer!), and keep learning.

## What's Next?

Chapter 3 will introduce functions - reusable chunks of code that make your programs more organized and powerful. We'll transform our pizza calculator into a full restaurant management system!

Remember: The best way to learn programming is by programming. Open your IDE and start coding! 🚀
