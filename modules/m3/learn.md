---
title: "Program Basics: When a Program Starts Remembering"
module: M3
lpaa_beat: Learn
estimated_time: "15 minutes"
prerequisites: ["M2 — How to Solve Problems"]
---

# Program Basics: When a Program Starts Remembering

## Learning Objectives

By the end of this reading, you will be able to:

- **Declare** a variable of the right type for the job — whole number, real number, or text (MLO 3.1).
- **Write** a program that reads input, works something out, and prints an answer (MLO 3.2).
- **Predict** the result of an arithmetic expression, including the one that catches everybody.
- **Read** a compiler message and a misbehaving run, and **name** each by the four course words (MLO 3.3).
- **Choose** variable names that tell the next reader what you meant.

## Why This Matters

Every program you have met so far printed the same thing every time you ran it. That was on purpose — M2 was about reading code and naming what goes wrong, and a program that never changes is the easiest kind to read.

It is also the least useful kind. **M3 is where a program starts remembering something.**

Back in M0 you described a program you had used in terms of its **inputs**, its **process**, and its **outputs**. That was a frame for describing *someone else's* program from the outside. This module is where you build one from the inside — and it turns out you only need two new ideas to do it: somewhere to keep a value, and a way to ask for one.

## The Core Concept

### A variable is a named box

A **variable** is a place to keep a value, with a name you choose and a type that says what kind of value it holds.

C++ makes you say the type up front. That is stricter than some languages and it is deliberate — the compiler can then catch you putting the wrong kind of thing in the wrong kind of box, before the program ever runs.

These four cover almost everything this term:

| Type | Holds | Example |
|---|---|---|
| `int` | whole numbers | `int torches = 12;` |
| `double` | numbers with a fractional part | `double price = 2.50;` |
| `string` | text | `string name = "Bram";` |
| `bool` | true or false | `bool hasKey = true;` |

Here is the smallest useful program that uses them. Nothing is asked for yet — every value is decided when the program is written — but the values now live in named boxes instead of being buried inside the printed text.

**Stage A** — `code/learn-merchant-static.cpp`

```cpp excerpt=modules/m3/code/learn-merchant-static.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string merchantName = "Bram";
    int torches = 12;
    double pricePerTorch = 2.50;

    cout << merchantName << " has " << torches << " torches.\n";
    cout << "Each one costs " << pricePerTorch << " gold.\n";

    return 0;
}
```

**Program Output:**

```
Bram has 12 torches.
Each one costs 2.5 gold.
```

Look closely at that second line. You wrote `2.50` and it printed **`2.5`**. Nothing is broken — `cout` prints the *number*, and trailing zeros are not part of a number. Making money look like money takes an extra tool, and it is coming; for now, notice that what you typed and what printed are not always identical.

> **💡 Pro Tip**: `#include <string>` is new. `<iostream>` gets you `cin` and `cout`; `<string>` gets you the `string` type. Ask for what you use.

### Predict first

**Here is the one that catches everybody. Read it and write down both printed numbers before you scroll.**

```cpp excerpt=modules/m3/code/learn-int-division.cpp
    int coins = 5;
    int heroes = 2;

    int eachInt = coins / heroes;                        // both int -> int result
    double eachReal = coins / (double)heroes;            // one is real -> real result
```

<details>
<summary>Reveal the output</summary>

```
Splitting 5 coins between 2 heroes.
Integer division says: 2
Real division says:    2.5
```

**`5 / 2` is `2`.** Not 2.5, and not 3.

When both sides of a `/` are `int`, C++ does *integer division*: it works out how many whole times one goes into the other and **throws the remainder away**. It does not round — `5 / 2` and `4 / 2` both give `2`.

The fix is to make at least one side a real number. `(double)heroes` says "treat this as a `double` for this calculation," and once one side is real, the answer is real.

**This compiles clean and runs fine.** No warning, no error. It is a **Logic** error in the four-word taxonomy — the program did exactly what you said, which was not what you meant. Nothing but a person reading the output will ever catch it.
</details>

### From fixed to asking

A program that only knows what you typed into it is a very expensive way to write a sentence. `cin` is the other half:

**Stage B** — `code/learn-merchant-interactive.cpp`

```cpp excerpt=modules/m3/code/learn-merchant-interactive.cpp
    int torches = 0;                       // INPUT
    cout << merchantName << ": How many torches do you want? ";
    cin >> torches;

    double total = torches * pricePerTorch;   // PROCESS

    cout << merchantName << ": That is " << total << " gold.\n";   // OUTPUT
```

**Program Output** (the user typed `4`):

```
Bram: How many torches do you want? Bram: That is 10 gold.
```

Three things worth naming:

**`cin >>` points the other way from `cout <<`.** The arrows show which way the data moves — out to the screen, in from the keyboard. If you ever type them backwards, that is what the compiler will complain about.

**The prompt and the answer are on the same line.** There is no `\n` at the end of the prompt, so the cursor stays put — which is what you want when someone is about to type. It looks odd in a transcript and correct in real life.

**Those three comments are the M0 frame, in code.** Input, process, output. Every program you write this term has this shape somewhere inside it.

### Names are a message to the next reader

`torches` and `pricePerTorch` could have been `t` and `p`. The program would run identically. **The compiler does not care and you should.**

The next person to read your code is most often you, three weeks later, with no memory of what you were thinking. Names are the cheapest documentation there is: `total` beats `x`, `pricePerTorch` beats `price2`. A comment explaining what `x` means is a comment you would not have needed.

> **🔗 Connection**: This is the same idea as M1's Robot Sandwich, pointed at a different reader. There you were being precise for a machine that cannot guess. Here you are being clear for a human who should not have to.

### Breaking it on purpose

Now the part this course does deliberately. **We are going to break a working program and read the complaint together.** Your first error is a planned event, not a failure — and there are two very different kinds waiting for you here.

#### Break one: the compiler stops you

```cpp excerpt=modules/m3/code/learn-break-undeclared.cpp
    int torches = 4;

    total = torches * 2;
    cout << "Total: " << total << '\n';
```

`total` is used but never declared. The grammar is perfect — semicolons, braces, all correct. It is a well-formed sentence about a thing that does not exist:

```
learn-break-undeclared.cpp:17:5: error: 'total' was not declared in this scope
   17 |     total = torches * 2;
      |     ^~~~~
```

That is a **Static semantic** error: grammar fine, meaning impossible. Caught at compile time, so **no program is produced**. This is the *friendly* kind — it stops you at the door, tells you the line, and points at the word.

#### Break two: the program lies to you

Here is the one M2 warned you about and could not show you, because it needs `cin`.

```cpp excerpt=modules/m3/code/learn-cin-fail.cpp
    int torches = 0;
    cout << "How many torches? ";
    cin >> torches;

    double total = torches * 2.50;
```

Run it and type `4`, and everything is fine:

```
How many torches? You asked for 4 torches.
That comes to 10 gold.
```

Now run it again and type **`lots`**:

```
How many torches? You asked for 0 torches.
That comes to 0 gold.
```

**No crash. No error message. Exit code 0.** As far as your terminal is concerned, that run succeeded.

What happened: `cin` was asked for an `int` and handed a word. It could not do the conversion, so it gave up and left `torches` exactly as it was — `0`. Every calculation after that was built on that zero, faithfully.

This is a **Runtime** error — it ran, then fell over. It just fell over *quietly*, which is the expensive way. In M2 you learned the name and the test (*did a program get built and start running?*); this is the first time you can watch one happen.

**Guarding against it — noticing the failure and asking again — needs a loop, which arrives in M5.** For now the honest lesson is smaller and more important: **a program that finishes is not a program that worked.**

## Putting It Together

The four words, now with M3's examples attached:

| Word | Example you have now seen | Caught by |
|---|---|---|
| **Syntax** | a missing semicolon (M2) | the compiler |
| **Static semantic** | using `total` before declaring it | the compiler |
| **Runtime** | typing `lots` where a number was expected | running it — sometimes |
| **Logic** | `5 / 2` giving `2` | a person, reading the output |

Notice the direction of travel. The errors at the top announce themselves loudly and cost you a minute. The ones at the bottom say nothing at all and can survive to a grade or a customer. **The skill this course is building is the one that catches the quiet ones.**

## Common Questions

**Why does `5 / 2` print `2`?**
Because both are `int`, so C++ does integer division and throws away the remainder. Make one side a `double` and you get `2.5`. This is the single most common surprise in this module.

**When do I use `int` and when `double`?**
Count things with `int` — people, torches, attempts. Measure things with `double` — money, weight, averages. If halving it would be meaningful, it is probably a `double`.

**Why do I have to say the type at all? Python doesn't.**
Python works it out at run time; C++ wants to know at compile time. The cost is more typing. The payoff is that a whole category of mistake becomes impossible before the program ever runs — and speed, which is why C++ is still used where speed matters.

**What if the user types something ridiculous?**
You saw exactly that above, and right now the answer is: the program believes a zero and carries on. Catching it properly needs a loop, which is M5. Knowing it can happen is this module's job.

**Can I ask an AI to write the calculation for me?**
Yes — and then read it, because integer division is exactly the kind of thing that looks right in a generated answer. It compiles, it runs, it prints a number. Only someone who knows the trap will notice the number is wrong.

## Check Yourself

**1.** `int a = 7; int b = 2;` — what does `a / b` give?

<details><summary>Answer</summary>

**`3`.** Integer division: 2 goes into 7 three whole times, remainder discarded. Not 3.5, and not rounded to 4.
</details>

**2.** A program compiles clean, runs, finishes normally, and prints a total of `0` when it should print `47.50`. Which of the four words?

<details><summary>Answer</summary>

Most likely **Runtime** — if the `0` came from a `cin` that failed on unexpected input, the way the torch program did. It could also be **Logic** if the arithmetic itself is wrong. The way to tell them apart is to feed it *good* input: if it is right then, the problem was the reading, not the maths.
</details>

**3.** Why is `double totalCostInGold` a better name than `double t`?

<details><summary>Answer</summary>

Because the program runs identically either way, so the name's entire job is telling the next reader what the value means — and the next reader is usually you, weeks later. A good name saves a comment. A bad one needs one.
</details>

## Next Steps

1. **Take the M3 exit ticket.** It is completion-gated — finish it to move on. Nothing on it is a trick.
2. **Bring this reading to class** for the Apply tutorial, where you will type an input → process → output program in yourself and get it building and running clean.
3. **Then the lab**, which asks you to build a small calculator from a spec — the first program you write from a description rather than a listing.

> **📋 Instructor note — not yet authored.** M3 is at **First pass**: this reading
> exists; the exit ticket, the Apply tutorial, and the lab **do not yet exist**
> (ADR-016). Steps 1–3 describe where this beat hands off, not files you can open
> today. Do not route students here expecting the rest of the module to be waiting
> for them.
