# Your AI Team: A Student Guide

## Welcome to a Different Way of Learning Programming! 🦆🤖

You'll have AI assistants throughout this course. But here's the twist: for the first 8 weeks, your AI **literally cannot write code for you**. We've programmed it that way. Think of it as the world's smartest rubber duck that asks questions but never gives answers.

Then at Week 9, things get interesting. You get a second AI that CAN write code. But here's what actually happens: you're now managing yourself plus two AI agents, and you'll quickly discover that's its own skill.

## Why This Weird System?

Because in 6 months, you'll be interviewing for jobs where they'll ask you to code on a whiteboard. No AI. No Google. Just you and your knowledge. 

But also because in the real world, you WILL have AI tools. The trick is knowing when they're helping vs. when they're creating technical debt you can't pay back.

## Your AI Team Evolution 🎮

### Weeks 1-4: Just You and Flash (Basic Rubber Duck)
Your AI "Flash" is basically a curious 5-year-old:
- "What does that line do?"
- "Tell me about that error"
- "What happens next?"

**You're learning**: Variables, input/output, basic functions

**Example conversation**:
```
You: "My program crashed!"
Flash: "What does the error message say? Read it to me."
You: "It says 'undefined reference to main'"
Flash: "Hmm, what function must every C++ program have?"
You: "Oh! main()! I spelled it 'mian'!"
Flash: "Interesting! What will you try now?"
```

### Weeks 5-8: Flash Gets Smarter (Debugging Partner)
Flash becomes a thinking buddy:
- Helps trace through logic
- Explains error messages
- Suggests debugging strategies (but not fixes!)

**You're learning**: Decisions, loops, complex functions

**Example conversation**:
```
You: "My loop runs forever!"
Flash: "Let's trace it. What makes the loop stop?"
You: "When health reaches 0"
Flash: "What changes health inside your loop?"
You: "...nothing. OH NO."
Flash: "What's your plan to fix that?"
```

### Weeks 9-16: You Get a Second AI! 🎉
**LEVEL UP!** You now manage TWO AIs:

**Flash** (your original partner) becomes a senior reviewer:
- Discusses design patterns
- Reviews structure (still won't write code!)
- Helps with Git/GitHub
- Asks architectural questions

**Thinker** (your new bot) CAN write code:
- Might be GPT, Claude, Kevin, or The Algorithm (different sections use different ones - they all have quirks!)
- Will happily write entire functions
- Sometimes writes bugs
- Often overcomplicates simple things

**The Reality Check**: Now you're managing three entities - yourself, Flash, and Thinker. Congrats, you're now a technical lead!

**Example Week 12 workflow**:
```
You: "I need a function to sort my inventory"
Thinker: "Here's a complete sort function using std::sort with a lambda comparator..."
You: "Wait, that seems complex"
Flash: "What are you actually sorting by? Do you need that complexity?"
You: "Just... alphabetically?"
Flash: "What's the simplest approach for that?"
Thinker: [Waiting to overcomplicate things]
You: "I'll just use basic sort() with strings!"
```

**The Trap**: If you just copy Thinker's code without understanding it, here's what happens:
- Week 10: "Wow, Thinker solved everything!"
- Week 11: "Why doesn't my program work?"
- Week 12: "I have no idea what any of this code does"
- Week 13: "...I need to start over"

**The Strategy**: Use Thinker for boilerplate, Flash for thinking, and YOUR BRAIN for decisions.

## The Two-Agent System (It's Actually Pretty Cool)

### Your Agents and Their Personalities

**Flash** (Weeks 1-16):
- Your rubber duck debugger
- Asks questions, never answers
- Gets smarter over time but NEVER writes code
- Honestly, Flash COULD write code after Week 9, but that's not what it's good at
- Flash is best at making YOU think

**Thinker** (Weeks 9-16):
- Your code generator
- Different sections get different versions:
  - **GPT**: Writes verbose code with lots of comments
  - **Claude**: Tends to overengineer everything  
  - **Kevin**: Surprisingly good at game logic
  - **The Algorithm**: Mysterious, writes cryptic but efficient code
- Will confidently write bugs
- Never admits when it doesn't know something

### How to Use Your AI Team Effectively

#### Weeks 1-8: Solo with Flash
Focus on learning fundamentals. Flash is annoying on purpose - it makes you stronger.

#### Weeks 9-16: Managing Your Team

**The Right Way**:
1. Think about what you need
2. Ask Flash to help you plan
3. Ask Thinker to write boilerplate
4. Read Thinker's code carefully
5. Ask Flash if it seems reasonable
6. Modify to actually work for YOUR program
7. Test and debug yourself

**The Tempting (But Doomed) Way**:
1. Ask Thinker to do everything
2. Copy-paste without reading
3. Hope it works
4. Week 11: "Why is everything broken?"
5. Can't fix it because you don't understand any of it
6. Start over from scratch
7. Repeat until you drop the class

### Real Student Experiences

> "I thought getting Thinker in Week 9 would make everything easier. Instead, I spent three hours debugging code I didn't write for a problem that would've taken me 20 minutes to solve myself." - Alex, Spring 2024

> "The Algorithm wrote me a sorting function using bit manipulation. It worked but I still don't know why. I rewrote it with basic sort()." - Jamie, Fall 2023

> "Once I learned to use Flash for planning and Thinker for boring stuff like file I/O templates, I actually got faster. But you have to stay in control." - Maria, Spring 2024

## How to Use Your AI Team Effectively

### ✅ GOOD Uses (Weeks 1-8 with just Flash)

1. **Explain Your Code To It**
   ```
   "I wrote a function that calculates tax. Let me walk you through it..."
   ```

2. **Debug Together**
   ```
   "Line 15 gives an error. I think it's because..."
   ```

3. **Discuss Approaches**
   ```
   "I need to store multiple characters. What should I consider?"
   ```

### ✅ GOOD Uses (Weeks 9+ with Flash AND Thinker)

1. **Strategic Planning with Flash**
   ```
   You: "I need to implement save game functionality"
   Flash: "What data needs to be saved? What format makes sense?"
   ```

2. **Boilerplate from Thinker**
   ```
   You: "Thinker, show me basic file I/O structure in C++"
   Thinker: *Provides template*
   You: *Adapts it to your specific needs*
   ```

3. **Code Review Triangle**
   ```
   You: *Write solution*
   Thinker: *Provides alternative approach*
   Flash: "What are the trade-offs between these approaches?"
   You: *Make informed decision*
   ```

### ❌ BAD Uses (That Lead to Disaster)

1. **The Copy-Paste Disaster**
   ```
   You: "Thinker, write my entire RPG battle system"
   Thinker: *500 lines of code*
   You: *Pastes without reading*
   Week 11: "Nothing works and I don't know why"
   ```

2. **The Infinite Loop of Confusion**
   ```
   You: "Fix this bug"
   Thinker: *Rewrites everything*
   You: "Now there's a different bug"
   Thinker: *Rewrites everything again*
   You: "I have no idea what my code does anymore"
   ```

3. **Ignoring Flash for Thinker**
   ```
   You: *Only talks to Thinker after Week 9*
   Flash: *Sad rubber duck noises*
   You: *Loses ability to think through problems*
   Final exam: *No AI allowed*
   You: 😱
   ```

## Weekly Requirements

### AI Conversation Logs (All Weeks)
Submit your debugging conversations weekly. We want to see:
- Your problem-solving process
- How you explained issues
- What you learned

### Reflection Questions

**Weeks 1-8** (50 words):
- What did Flash help you understand?
- What did you figure out alone?
- How did explaining help your learning?

**Weeks 9-16** (100 words):
- How did you use Flash vs Thinker?
- What code did you keep/reject from Thinker?
- How did managing two AIs change your workflow?
- What would you do differently?

## The Week 9 Transformation 🎊

### What Happens in Week 9

**Monday**: "The Great Unlocking"
- Morning: Submit your best Flash conversation showing mastery
- Afternoon: Receive your Thinker bot assignment (GPT/Claude/Kevin/The Algorithm)
- Evening: First three-way conversation

**Wednesday**: "Reality Check Day"
- Try to get Thinker to do your homework
- Discover it writes bugs
- Realize you need Flash more than ever
- Submit reflection: "My first 48 hours with code generation"

**Friday**: "Finding Balance"
- Learn the workflow: Plan with Flash → Generate with Thinker → Fix yourself
- Share horror stories in Discord
- Veterans from last semester give advice

### The Three-Way Conversation (Required Week 9)

You'll orchestrate a conversation between yourself, Flash, and Thinker:

```
You: "I need to implement a function that sorts inventory items"
Flash: "What are you sorting by? What's the data structure?"
You: "Vector of Item objects, sorting by name alphabetically"
Thinker: "Here's a complete implementation using std::sort with a custom comparator..."
Flash: "That seems complex. Do you need a custom comparator for alphabetical sorting?"
You: "Wait, can't I just use the default sort?"
Thinker: "Well yes, if Item has operator< defined..."
Flash: "Does it need operator<? What about just sorting by the name field?"
You: "This is getting confusing. Let me think about what I actually need..."
```

This conversation shows the reality: More AIs ≠ Easier. More AIs = More to manage.

## Meet the Thinker Bots (Week 9+ Personalities)

Different sections get different Thinker bots. They all have... quirks.

### GPT - "The Overexplainer"
```cpp
// You asked for: "increment x"
// GPT writes:
// First, we declare our intention to increment the variable
// We use the increment operator (++) which adds 1 to the value
// This is equivalent to x = x + 1 but more efficient
x++; // Incrementing x by 1
```
**Survival tip**: Great for learning, terrible for clean code. Delete 80% of comments.

### Claude - "The Architecture Astronaut"
```cpp
// You asked for: "function to add two numbers"
// Claude writes:
template<typename T>
class ArithmeticOperationHandler {
    public:
        T performAddition(const T& operand1, const T& operand2) const noexcept {
            return operand1 + operand2;
        }
};
```
**Survival tip**: Always ask "Could this be 3 lines instead of 30?"

### Kevin - "The Game Dev Bro"
```cpp
// You asked for: "player health system"
// Kevin writes:
int playerHP = 100; // full health lets gooo
int maxHP = 100; // cap it at 100 cuz balance
bool isDead = false; // not dead yet lol
// TODO: add epic death animation
// TODO: maybe regeneration??
// TODO: damage types would be sick
```
**Survival tip**: Actually pretty good at game logic. Terrible at professional standards.

### The Algorithm - "The Enigma"
```cpp
// You asked for: "check if number is even"
// The Algorithm writes:
return !(n&1);
```
**Survival tip**: Usually correct, never readable. Great for learning bitwise operations, terrible for maintainable code.

### Which Thinker Will You Get?

Your section assignment determines your Thinker. You can't switch, but you can laugh about it in Discord:

- **Section 01 (MWF 9am)**: GPT - Hope you like comments
- **Section 02 (MWF 11am)**: Claude - Bring your UML diagrams  
- **Section 03 (TTh 2pm)**: Kevin - Game on, bro
- **Section 04 (Online)**: The Algorithm - Good luck

By Week 12, you'll have Stockholm Syndrome with your Thinker. By Week 16, you'll miss its quirks.

> "At first I hated that Flash wouldn't just tell me the answer. By Week 8, I realized I didn't need it to." - Maria, Fall 2023

> "Getting Thinker in Week 9 felt like Christmas. By Week 10, I realized it was more like getting a puppy - exciting but requires training." - James, Spring 2024

> "The Algorithm wrote me a recursive solution to FizzBuzz. I'm still not sure if it was trolling me." - Ashley, Fall 2023

> "Kevin (my Thinker) writes code like a caffeinated squirrel. It works, but you HAVE to clean it up." - David, Spring 2024

## The Secret Benefit 🤫

By Week 16, you'll understand the difference between:
- Code that works today (what Thinker writes)
- Code that you can maintain tomorrow (what you write with Flash's guidance)

Professional programming isn't about getting AI to write everything. It's about knowing when to use AI, when to write it yourself, and when to completely ignore both AIs and just think.

## Managing Two AIs: A Survival Guide

### The Weekly Workflow Evolution

**Weeks 1-8**: You → Flash → You (learn by struggling)

**Week 9**: You → Thinker → "Wait, what did it write?" → Start over

**Week 10**: You → Flash (plan) → Thinker (boilerplate) → You (fix) → Flash (review)

**Week 11+**: You know when to use which tool

### Common Week 9+ Scenarios

**Scenario 1: The Overengineering Trap**
```
You: "I need to read a file"
Thinker: *Writes enterprise-grade file system with error handling for 17 edge cases*
You: "I... just needed three lines"
Flash: "What's the simplest solution that could work?"
```

**Scenario 2: The Mysterious Bug**
```
Thinker: *Writes complex algorithm*
You: "It doesn't work"
Thinker: *Rewrites everything differently*
You: "Still broken"
Flash: "Can you explain what the original code was trying to do?"
You: "...no"
Flash: "There's your problem"
```

**Scenario 3: The Perfect Balance**
```
You: "I need file I/O structure"
Flash: "What operations do you need?"
You: "Read, write, append"
Thinker: *Provides template*
You: *Adapts template to your specific needs*
Flash: "How would you test this?"
You: *Writes tests yourself*
```

## Your First Assignment (Updated for Two-Agent System)

1. Set up Flash with your Week 1-4 personalized prompt
2. Have a 5-minute conversation about why you're learning programming
3. Submit the log with a reflection: "What did I learn about myself?"
4. (Week 9) Set up your Thinker bot
5. (Week 9) Have both AIs "meet each other" in a three-way conversation
6. (Week 9) Reflection: "How do I plan to use two AIs without losing my mind?"

## Quick Reference Card

| Week | Flash Can Do | Thinker Status | Your Job |
|------|-------------|----------------|----------|
| 1-4 | Ask basic questions | Not available | Write everything |
| 5-8 | Trace logic, explain errors | Not available | Debug and implement |
| 9-12 | Review architecture, discuss design | Writes code (badly) | Manage both AIs, fix Thinker's code |
| 13-16 | Senior dev review | Writes code (still badly) | Architect solutions using both as tools |

## Remember

Every professional programmer uses AI tools now. The difference between a good programmer and someone who just copies AI code? 

**The good programmer knows why the code works, can fix it when it breaks, and can explain it in an interview.**

You're learning to be the good programmer.

Welcome to CSC 134. Let's build something amazing! 🚀