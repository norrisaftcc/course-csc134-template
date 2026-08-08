# Pizza Calculator Project Rubric (Week 2)
## AI-Supported Learning Assessment

### Project Overview
Create a pizza ordering system that calculates costs based on size, toppings, and applicable taxes/discounts.

**Learning Objectives Assessed:**
- Variable declaration and initialization
- User input with `cin`
- Mathematical calculations
- Formatted output with `cout`
- Problem decomposition with AI support

---

## Grading Components (100 points total)

### 1. Functional Requirements (40 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **User Input** | Handles all inputs gracefully, including name with spaces | Gets all required inputs | Gets most inputs, minor issues | Significant input problems |
| **Calculations** | All calculations correct with proper order of operations | Minor calculation errors | Some calculations work | Major calculation errors |
| **Output Display** | Professional receipt format with clear labels and alignment | Clear output, minor formatting issues | Output works but messy | Output unclear or missing |
| **Edge Cases** | Handles 0 toppings, maximum sizes, etc. | Handles most cases | Some edge cases cause issues | Crashes on edge cases |

### 2. Code Quality (30 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **Variable Names** | Descriptive names like `toppingCount`, `taxRate` | Mostly clear names | Some unclear names like `x`, `temp` | Confusing or misleading names |
| **Code Organization** | Logical flow with clear sections (input→calculation→output) | Generally well organized | Some organization present | Chaotic structure |
| **Constants Used** | All fixed values (tax rate, prices) declared as `const` | Most constants declared | Some constants used | Magic numbers throughout |

### 3. AI Partnership Documentation (20 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **Debugging Log** | Shows multiple AI conversations with clear problem-solving progression | Shows AI interaction with some debugging | Minimal AI interaction logged | No evidence of AI use or clear violation |
| **Reflection Quality** | Explains what AI helped understand vs. what student figured out independently | Basic reflection on AI use | Minimal reflection | No reflection or copy-pasted |

### 4. Understanding Demonstration (10 points)

| Criteria | Excellent (10) | Proficient (8) | Developing (6) | Needs Work (4) |
|----------|---------------|----------------|----------------|----------------|
| **Code Comments** | Every section has comments explaining WHY, not just what | Most sections commented | Some comments present | No meaningful comments |

---

## Sample Debugging Log (What We Want to See)

### GOOD Example ✅
```
Me: My total isn't calculating right
AI: What's the value of each variable when you calculate the total?
Me: pizzaPrice is 12.99, toppings is 3, toppingPrice is 1.50
AI: How are you calculating the total from these values?
Me: total = pizzaPrice + toppings
AI: What about the price per topping?
Me: OH! I need to multiply toppings by toppingPrice first!
AI: What's your plan to fix that?
Me: total = pizzaPrice + (toppings * toppingPrice)
```

**Why this is good:** Shows thinking process, AI guided but didn't provide solution

### BAD Example ❌
```
Me: Write the calculation for pizza total with toppings
AI: That's your job! But let's think about what components make up the total...
Me: Just show me the formula
AI: I can't write code, but what prices need to be added together?
[Conversation ends]
```

**Why this is bad:** Student trying to get AI to write code, gave up when it wouldn't

---

## Code Expectations

### Minimum Viable Product (C Grade - 70%)
```cpp
// Gets basic input
cout << "Enter pizza size (1, 2, or 3): ";
cin >> size;

// Simple calculation
if (size == 1)
    price = 9.99;
// etc.

// Basic output
cout << "Total: $" << total << endl;
```

### Target Product (B Grade - 85%)
```cpp
// Clear prompts
cout << "=== Pizza Order System ===" << endl;
cout << "Sizes: 1-Small($9.99) 2-Medium($12.99) 3-Large($15.99)" << endl;
cout << "Enter your choice: ";
cin >> pizzaSize;

// Organized calculations
const double TAX_RATE = 0.08;
double subtotal = pizzaPrice + (toppingCount * TOPPING_PRICE);
double tax = subtotal * TAX_RATE;
double total = subtotal + tax;

// Formatted output
cout << "\n--- Your Receipt ---" << endl;
cout << "Pizza:    $" << pizzaPrice << endl;
cout << "Toppings: $" << toppingTotal << endl;
cout << "Subtotal: $" << subtotal << endl;
cout << "Tax:      $" << tax << endl;
cout << "Total:    $" << total << endl;
```

### Exceptional Product (A Grade - 95%+)
- Handles customer name with spaces (using `getline`)
- Validates input (size must be 1-3)
- Offers discount for 5+ toppings
- Calculates delivery fee based on distance
- Provides estimated wait time
- Professional receipt with borders/formatting

---

## AI Policy Compliance Check

### Automatic Failure Conditions:
- [ ] Submitted code appears in AI conversation log
- [ ] No AI debugging log submitted
- [ ] Evidence of using non-approved AI tools
- [ ] Code complexity beyond Week 2 concepts (obvious external help)

### Expected AI Usage Pattern:
- [ ] 3-5 debugging conversations
- [ ] Questions about errors, not requests for code
- [ ] AI helps student think, not write
- [ ] Reflection shows learning process

---

## Common Week 2 Issues (Debugging Focus)

### Issue 1: Integer Division
**Student Code:**
```cpp
double discount = 10 / 100;  // Results in 0, not 0.10!
```

**Good AI Interaction:**
- AI: "What type is 10? What type is 100? What happens when you divide two integers?"

### Issue 2: Missing getline after cin
**Student Code:**
```cpp
cin >> size;
getline(cin, customerName);  // Skips input!
```

**Good AI Interaction:**
- AI: "What's left in the input buffer after cin >>? How might that affect getline?"

### Issue 3: Uninitialized Variables
**Student Code:**
```cpp
double total;
total = total + pizzaPrice;  // total contained garbage!
```

**Good AI Interaction:**
- AI: "What value does total have before you add to it? Where was it initialized?"

---

## Submission Requirements

1. **pizzaCalc.cpp** - Your source code
2. **output.txt** - Screenshot/copy of program running with sample data
3. **ai_log.txt** - Your debugging conversations with AI
4. **reflection.md** - 100-word reflection answering:
   - What was the hardest part?
   - How did the AI help without writing code for you?
   - What did you learn about debugging?

---

## Grading Timeline
- **Submitted on time**: Full credit possible
- **1 day late**: Maximum 90%
- **2 days late**: Maximum 80%
- **3+ days late**: Maximum 70%
- **Missing AI log**: Maximum 50% (shows likely policy violation)

---

## Excellence Indicators (What makes an A+ project)

1. **Clean Code**: Anyone could read and understand immediately
2. **Robust**: Handles weird input gracefully
3. **Creative**: Adds personality while meeting requirements
4. **Well-Documented**: Comments explain thinking
5. **Learning Visible**: AI log shows genuine problem-solving journey

---

## Support Resources

- **Sample Solution Video**: [Canvas link] (Watch AFTER attempting)
- **Common Errors Guide**: [Canvas link]
- **Discord**: #week2-pizza-help
- **Office Hours**: Bring your AI log!

---

### Remember
**The goal isn't a perfect pizza calculator. The goal is learning to think like a programmer.** 

Your AI partner is there to help you think, not think for you. Every error you debug yourself makes you stronger! 🍕💪