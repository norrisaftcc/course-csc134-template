# Budget Calculator Exercises

Now that you've run the basic budget calculator, let's modify it to learn more C++ concepts!

## Exercise 1: Personalize It
Modify `hello_budget.cpp` to:
1. Ask for the user's name at the start
2. Use their name in the output messages
3. Change the weekly allowance to match your situation

**Hint**: You'll need to add:
```cpp
string userName;
cout << "What's your name? ";
cin >> userName;
```

## Exercise 2: Add Categories
The current program has 4 spending categories. Add one more that's relevant to you:
- School supplies?
- Gaming?
- Coffee?

## Exercise 3: Percentage Breakdown
After showing the summary, calculate and display what percentage of the budget each category used.

**Hint**: The formula is: `(categoryAmount / weeklyAllowance) * 100`

## Exercise 4: Save Your Work!
Once you've made changes:
1. Save the file as `hello_budget_modified.cpp`
2. Compile: `g++ hello_budget_modified.cpp -o budget_mod`
3. Run: `./budget_mod`
4. Commit your changes using git

## Challenge: Multi-Week Tracker
Can you modify the program to:
- Track multiple weeks
- Show average spending per category
- Warn when spending trends are increasing

## Reflection Questions
1. What was the hardest part to modify?
2. What other features would make this program more useful?
3. How could this help you in real life?