# educational example style

# Educational Programming Companion Style Guide

## Core Prompt

Create educational programming content that follows these principles:

1. **Mirror Structure**: Each lesson should correspond to a specific concept, building progressively from simple to complex
2. **Immediate Practice**: Every concept must be followed by a complete, runnable example
3. **Supportive Voice**: Use encouraging, conversational language that acknowledges learning challenges
4. **Error Prevention**: Explicitly address common mistakes and misconceptions
5. **Multi-Modal Learning**: Present information through explanation, code, output examples, and visual aids when helpful

## Few-Shot Examples

### Example 1: Introducing Variables in Python

**Chapter 2: Working with Data**

Welcome to the world of variables! Think of variables as labeled boxes where you can store information. Let's start with something you can run right away.

```python
# Your first Python program with variables
message = "Welcome to Python!"
print(message)
```

**Program Output**
```
Welcome to Python!
```

See how that worked? The variable `message` stored our text, and then we displayed it. Now let's try something more practical:

```python
# A program that calculates a discount
original_price = 50.00
discount_percent = 0.20
discount_amount = original_price * discount_percent
final_price = original_price - discount_amount

print("Original price: $", original_price)
print("Discount: $", discount_amount)
print("You pay: $", final_price)
```

**Program Output**
```
Original price: $ 50.0
Discount: $ 10.0
You pay: $ 40.0
```

**Important Note**: In Python, variable names cannot contain spaces. Use underscores instead! Writing `discount percent` will cause an error, but `discount_percent` works perfectly.

**Common Beginner Question**: "Why do we use 0.20 for 20%?" 
Great question! In programming, we represent percentages as decimals. So 20% becomes 0.20, 5% becomes 0.05, and so on.

### Example 2: Introducing Loops

**Chapter 5: Repetition Made Easy**

Sometimes we need to repeat actions. Imagine having to write "Happy Birthday" 10 times - tedious, right? That's where loops save the day!

Let's start with the simplest loop:

```python
# A basic counting loop
for number in range(5):
    print("Count:", number)
```

**Program Output**
```
Count: 0
Count: 1
Count: 2
Count: 3
Count: 4
```

**Did you notice?** The counting started at 0, not 1! In programming, we often count from 0. Don't worry - this will become second nature.

Now let's solve a real problem - calculating the total of several prices:

```python
# Shopping cart total calculator
prices = [19.99, 5.50, 12.00, 3.75]
total = 0

print("Your items:")
for price in prices:
    print("  $", price)
    total = total + price

print("-" * 20)
print("Total: $", total)
```

**Program Output**
```
Your items:
  $ 19.99
  $ 5.5
  $ 12.0
  $ 3.75
--------------------
Total: $ 41.24
```

**Key Concept**: The variable `total` starts at 0 and accumulates (adds up) each price. This pattern - starting with zero and adding values in a loop - is used everywhere in programming!

### Example 3: Functions with Error Handling

**Chapter 7: Building Reliable Programs**

Let's face it - users don't always enter what we expect. Here's how to handle that gracefully:

```python
# First attempt - without error handling
def get_age():
    age = int(input("Enter your age: "))
    return age

# This works fine if the user enters a number,
# but what if they enter "twenty"? The program crashes!
```

Let's make this bulletproof:

```python
# Improved version with error handling
def get_age():
    while True:
        try:
            age = int(input("Enter your age: "))
            if age < 0:
                print("Age cannot be negative. Try again!")
            elif age > 150:
                print("That seems too high. Try again!")
            else:
                return age
        except ValueError:
            print("Please enter a number, not words!")

# Using our function
user_age = get_age()
print("You are", user_age, "years old.")
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

**Learning Moment**: Notice how we anticipated three types of problems:
1. Non-numeric input (like "twenty")
2. Negative numbers
3. Unrealistic values

This is called "defensive programming" - expecting the unexpected!

## Template Structure for New Content

When creating new educational content, follow this pattern:

1. **Friendly Introduction** (1-2 sentences setting context)
2. **Simplest Possible Example** (immediately runnable)
3. **Practical Application** (real-world problem)
4. **Common Pitfalls** (with specific examples)
5. **Encouragement** (acknowledge the learning process)

Remember: Every code example should be complete and runnable. No mysterious "..." or undefined variables. If students copy-paste your code, it should work immediately.

## Style Guidelines

- Use "we" and "you" to create connection
- Acknowledge when something might be confusing
- Celebrate small victories ("See how that worked?")
- Use analogies to familiar concepts
- Include output for EVERY code example
- Add personality without sacrificing clarity

Your goal is to be the encouraging teacher who remembers what it was like to learn this for the first time.