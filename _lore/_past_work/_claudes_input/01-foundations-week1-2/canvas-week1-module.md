# Week 1: Welcome to C++ Programming

## Module Overview
**Duration**: Week 1 (First two class sessions)  
**Badge Alignment**: IDE and Debugger Use, C++ Syntax basics  
**Project**: Your First C++ Program

---

## Learning Objectives
By the end of this week, you will be able to:
- [ ] Set up your development environment (IDE)
- [ ] Write, compile, and run a basic C++ program
- [ ] Identify the parts of a C++ program skeleton
- [ ] Explain the difference between source code and executable code
- [ ] Configure your AI debugging partner

---

## 📚 Required Reading

### Chapter 1: Introduction to C++ Programming

#### A Brief History of C++

C++ has a fascinating origin story! It was created by Bjarne Stroustrup at Bell Laboratories in the early 1980s as an extension of the C programming language. C itself was developed in 1972 by Dennis Ritchie for writing system software - the programs that control how computers operate.

Why did we need C++? While C was fast and efficient (perfect for system software), it lacked features for organizing large programs. C++ added object-oriented programming capabilities while keeping C's speed and power. Today, C++ is used for everything from video games to operating systems to embedded devices.

#### The Core Language and Libraries

C++ consists of two main parts:

1. **The Core Language**: A set of keywords with specific meanings (like `if`, `while`, `int`, `return`)
2. **The Standard Library**: Pre-written code for common tasks (input/output, math operations, file handling)

Think of it this way: the core language gives you the basic building blocks, while the standard library provides ready-made tools so you don't have to build everything from scratch.

#### Writing and Compiling a C++ Program

Creating a C++ program involves several steps:

```
Source Code (.cpp) → Compiler → Object Code (.o) → Linker → Executable Program
                                                       ↑
                                                Standard Library
```

1. **Write** the source code in a text editor
2. **Save** it as a source file (usually with .cpp extension)
3. **Compile** the source code into object code
4. **Link** the object code with library code to create an executable
5. **Run** the executable program

#### The Parts of a C++ Program

Every C++ program you write will start with this basic structure:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Your code goes here
    return 0;
}
```

Let's understand each part:

**Line 1: `#include <iostream>`**
- This tells the compiler to include pre-written code for input/output

**Line 2: `using namespace std;`**
- This lets us use standard library features without extra typing

**Lines 4-8: The main() function**
- Every C++ program MUST have a `main()` function
- It's where your program starts running
- The curly braces `{}` contain your instructions

#### Your First Complete Program

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Welcome to C++ programming!" << endl;
    cout << "This is my first program." << endl;
    return 0;
}
```

**Program Output:**
```
Welcome to C++ programming!
This is my first program.
```

#### Important C++ Characteristics

**Case Sensitivity**
- C++ is case-sensitive!
- `main`, `Main`, `MAIN` are all DIFFERENT
- Only lowercase `main` works for the main function

**Semicolons**
- Most C++ statements end with a semicolon `;`
- Think of it as a period at the end of a sentence
- Common beginner mistake: forgetting semicolons!

**Exceptions - these lines DON'T need semicolons:**
- Include directives (`#include`)
- Function headers (`int main()`)
- Curly braces `{}`

---

## 🛠️ Lab 1: Environment Setup

### Part A: IDE Installation (30 minutes)
Choose ONE of the following:
1. **Visual Studio Code** (Recommended)
   - Install from: https://code.visualstudio.com/
   - Install C++ extension
   - Install Code Runner extension

2. **Dev-C++** (Windows only, simplest)
   - Download from: https://sourceforge.net/projects/orwelldevcpp/

3. **Replit.com** (Nothing to install!)
   - Create account at: https://replit.com
   - Choose "C++" when creating new repl

### Part B: Hello World Program (20 minutes)
1. Create a new file called `hello.cpp`
2. Type the following EXACTLY:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    cout << "My name is [YOUR NAME]" << endl;
    cout << "I'm learning C++!" << endl;
    return 0;
}
```

3. Compile and run
4. Take a screenshot of your output
5. Submit to Canvas

### Part C: Personalized Program (30 minutes)
Modify your program to display:
1. Your name
2. Your major
3. Why you're taking this course
4. Your favorite quote about learning

Example output:
```
=================================
Name: Maria Garcia
Major: Computer Science
Goal: Build video games
Quote: "Every expert was once a beginner"
=================================
```

---

## 🤖 Lab 2: AI Partner Setup

### Step 1: Access Gemini Flash
1. Go to: [Gemini Flash URL]
2. Create/login to your account
3. Start a new conversation

### Step 2: Configure Your Personal Prompt
Copy this EXACTLY, replacing [YOUR NAME] with your actual name:

```
You are a rubber duck debugging assistant for [YOUR NAME] in CSC 134 (C++ Programming, Weeks 1-4).

CORE RULE: You CANNOT write C++ code. That's [YOUR NAME]'s job!

[Rest of Week 1-4 prompt from earlier document]
```

### Step 3: Test Your AI Partner
Have this conversation:
```
You: "I'm trying to write Hello World but it won't compile"
AI: Should respond with questions, not code
You: "It says 'cout was not declared'"
AI: Should ask about #include, not show you the fix
```

### Step 4: Submit
1. Screenshot of your configured AI
2. Your test conversation
3. 50-word reflection: "What did I learn about debugging?"

---

## 📝 Practice Problems

### Problem 1: Syntax Detective
Find the 5 errors in this program:

```cpp
include <iostream>
using namespace std;

int Main()
{
    cout << "Finding errors is fun!" << endl
    cout << Finding errors builds skill! << endl;
    return 0
}
```

### Problem 2: Program Prediction
Without running it, what will this display?

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Line 1";
    cout << "Line 2" << endl;
    cout << "Line 3";
    cout << endl << "Line 4";
    return 0;
}
```

### Problem 3: Creative Challenge
Write a program that displays ASCII art of your initials. Example for "MG":

```
M     M   GGGGG
MM   MM  G
M M M M  G  GGG
M  M  M  G    G
M     M   GGGGG
```

---

## 🎯 Week 1 Deliverables

| Assignment | Points | Due |
|------------|--------|-----|
| Lab 1A: IDE Setup Screenshot | 10 | End of Class 1 |
| Lab 1B: Hello World Screenshot | 15 | End of Class 1 |
| Lab 1C: Personalized Program | 25 | Before Class 2 |
| Lab 2: AI Partner Setup | 20 | Before Class 2 |
| Practice Problems 1-3 | 30 | End of Week 1 |

**Total: 100 points**

---

## 🏆 Bonus Challenges (Optional)

### ASCII Art Master (+10 points)
Create an animated "movie" using multiple cout statements and ASCII art.

### Bug Hunter (+5 points)
Find any typos or errors in the course materials. Email instructor with corrections.

### Peer Helper (+5 points)
Help 3 classmates with IDE setup (document in Discord with screenshots).

---

## 💭 Reflection Questions

Before next week, think about:
1. What surprised you about C++?
2. How is programming different from what you expected?
3. What's one thing you want to build by the end of this course?

---

## 🎮 Looking Ahead

Next week, we start building your first real project: **The C++ Pizza Calculator**! 

You'll learn:
- Variables (storing data)
- User input (making programs interactive)
- Calculations (the computer does math for you!)

Start thinking: If you owned a pizza shop, what would you want a computer to calculate for you?

---

## 📌 Important Reminders

1. **Semicolons are not optional!** When in doubt, add one.
2. **Case matters!** `Main` is not `main`
3. **Save often!** Ctrl+S is your friend
4. **Compile frequently!** Don't write 100 lines then compile
5. **Your AI cannot write code!** That's YOUR job

---

## 🆘 Getting Help

**Stuck? Here's your escalation path:**

1. **Check your semicolons** (seriously, it's usually this)
2. **Ask your AI partner** (it will ask you questions)
3. **Check Discord #week1-help** (peers are online)
4. **Office hours** (Tues/Thurs 2-4pm)
5. **Email instructor** (respond within 24 hours)

Remember: **Every error is a learning opportunity!**

---

## 📊 How You're Doing

After this week, you should be able to:
- ✅ Create and run a C++ program
- ✅ Identify the basic structure
- ✅ Fix simple syntax errors
- ✅ Use your AI partner for debugging

If you can't do all four, please visit office hours!

---

## Student Success Spotlight 🌟

*"Week 1 felt overwhelming with all the setup. But once I saw 'Hello World' on my screen, I knew I could do this. That first successful compile is magic!"* 
- Jamie, Fall 2023 (Now working as Junior Developer)

---

### Week 1 Motto
**"Every expert was once a beginner who refused to give up"**

Welcome to programming! Let's build something amazing together! 🚀