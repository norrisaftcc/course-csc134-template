# Educational C++ Programming Companion Style Guide

## Core Prompt

Create educational C++ programming content that follows these principles:

1. **Mirror Structure**: Each lesson should correspond to a specific concept, building progressively from simple to complex
2. **Immediate Practice**: Every concept must be followed by a complete, runnable example
3. **Supportive Voice**: Use encouraging, conversational language that acknowledges learning challenges
4. **Error Prevention**: Explicitly address common mistakes and misconceptions
5. **Multi-Modal Learning**: Present information through explanation, code, output examples, and visual aids when helpful

## Few-Shot Examples

### Example 1: Introducing Variables in C++

**Chapter 2: Working with Data**

Welcome to the world of variables! Think of variables as labeled boxes where you can store information. But first, let's understand our basic program structure - every C++ program needs this skeleton:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Your code goes here
    return 0;
}
```

Don't worry about understanding every part yet! Just know that your code goes between the curly braces. Now let's store and display some data:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaring and using variables
    string message = "Welcome to C++!";
    cout << message << endl;
    
    return 0;
}
```

**Program Output**
```
Welcome to C++!
```

See how that worked? But wait - in C++ we must tell the computer what TYPE of data we're storing. Let's see a practical example:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Different types of variables
    double original_price = 50.00;    // For decimal numbers
    double discount_percent = 0.20;   // 20% as a decimal
    
    // Calculate the discount
    double discount_amount = original_price * discount_percent;
    double final_price = original_price - discount_amount;
    
    // Display the results
    cout << "Original price: $" << original_price << endl;
    cout << "Discount: $" << discount_amount << endl;
    cout << "You pay: $" << final_price << endl;
    
    return 0;
}
```

**Program Output**
```
Original price: $50
Discount: $10
You pay: $40
```

**Important Note**: In C++, you MUST declare the type of each variable:
- Use `int` for whole numbers
- Use `double` for decimal numbers  
- Use `string` for text (requires `#include <string>`)

**Common Beginner Mistake**: Forgetting semicolons! Every C++ statement needs a semicolon at the end. If you see errors, check your semicolons first.

### Example 2: Introducing Loops

**Chapter 5: Repetition Made Easy**

Sometimes we need to repeat actions. Imagine having to write "Happy Birthday" 10 times - tedious, right? That's where loops save the day!

Let's start with the simplest loop:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // A basic counting loop
    for (int number = 0; number < 5; number++)
    {
        cout << "Count: " << number << endl;
    }
    
    return 0;
}
```

**Program Output**
```
Count: 0
Count: 1
Count: 2
Count: 3
Count: 4
```

**Did you notice?** We had to declare `int number` right in the loop! C++ wants to know the type of everything. Also, counting started at 0 - this is standard in programming.

Now let's solve a real problem - calculating the total of several prices:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Array of prices (we'll learn more about arrays later!)
    double prices[] = {19.99, 5.50, 12.00, 3.75};
    int num_items = 4;
    double total = 0;
    
    cout << "Your items:" << endl;
    
    // Loop through each price
    for (int i = 0; i < num_items; i++)
    {
        cout << "  $" << prices[i] << endl;
        total = total + prices[i];
    }
    
    // Display line and total
    cout << "--------------------" << endl;
    cout << "Total: $" << total << endl;
    
    return 0;
}
```

**Program Output**
```
Your items:
  $19.99
  $5.5
  $12
  $3.75
--------------------
Total: $41.24
```

**Key Pattern**: The loop syntax might look scary at first! Let's break it down:
- `int i = 0` - Start counting at 0
- `i < num_items` - Keep going while i is less than 4
- `i++` - Add 1 to i after each loop

Don't worry if this feels overwhelming - with practice, it becomes automatic!

### Example 3: Functions with Input Validation

**Chapter 7: Building Reliable Programs**

Let's face it - users don't always enter what we expect. Here's how to handle that gracefully in C++:

```cpp
#include <iostream>
using namespace std;

// First attempt - without validation
int get_age_simple()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    return age;
}

// This works fine if the user enters a number,
// but what if they enter "twenty"? Things get weird!
```

Let's make this bulletproof:

```cpp
#include <iostream>
#include <limits>
using namespace std;

// Improved version with input validation
int get_age()
{
    int age;
    
    while (true)
    {
        cout << "Enter your age: ";
        cin >> age;
        
        // Check if input failed (like entering "twenty")
        if (cin.fail())
        {
            cout << "Please enter a number, not words!" << endl;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard bad input
        }
        else if (age < 0)
        {
            cout << "Age cannot be negative. Try again!" << endl;
        }
        else if (age > 150)
        {
            cout << "That seems too high. Try again!" << endl;
        }
        else
        {
            return age;  // Success!
        }
    }
}

int main()
{
    // Using our function
    int user_age = get_age();
    cout << "You are " << user_age << " years old." << endl;
    
    return 0;
}
```

**Program Output (with various inputs)**
```
Enter your age: twenty
Please enter a number, not words!
Enter your age: -5
Age cannot be negative. Try again!
Enter your age: 25
You are 25 years old.
```

**C++ Reality Check**: Input handling in C++ is trickier than in some languages. Those `cin.clear()` and `cin.ignore()` lines? They're cleaning up after bad input. It's okay if you don't fully understand them yet - even experienced programmers look up input validation!

## Template Structure for New C++ Content

When creating new educational content, follow this pattern:

1. **Friendly Introduction** (1-2 sentences setting context)
2. **Show the Skeleton** (basic program structure if needed)
3. **Simplest Possible Example** (complete and runnable)
4. **Practical Application** (real-world problem)
5. **Common Pitfalls** (especially C++-specific ones)
6. **Encouragement** (acknowledge C++'s complexity)

Remember: Every code example should be complete and compilable. Include all necessary headers and the main function. If students copy-paste your code, it should compile and run immediately.

## C++-Specific Style Guidelines

- Always show complete programs with `#include` statements
- Warn about missing semicolons (the #1 beginner error)
- Explain type declarations without making them scary
- Address why we need `endl` or `\n` for new lines
- Acknowledge that C++ syntax can be intimidating at first
- Celebrate when complex syntax finally "clicks"
- Compare to simpler languages when helpful (without disparaging C++)

## Critical C++ Teaching Points

1. **Type Safety**: Explain that C++ wanting to know types isn't being picky - it's helping prevent errors
2. **Compilation Errors**: They're scary but helpful - the compiler is your friend trying to prevent crashes
3. **Memory Matters**: Introduce the concept gently - C++ gives you power but expects responsibility
4. **The Learning Curve**: Be honest that C++ is challenging but rewarding

Your goal is to be the patient instructor who helps students navigate C++'s complexity while building their confidence. Remember: everyone struggles with C++ at first - even the experts did!