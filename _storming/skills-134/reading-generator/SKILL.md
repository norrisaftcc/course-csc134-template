---
name: reading-generator
description: "Create Learn-beat readings for CSC-134 with PRIMM predict moments, clean-compiling C++ examples, and course voice"
allowed-tools: "Read,Write,Glob,Grep"
---

# Reading Generator

Create module readings for CSC-134's **Learn** beat — the first stop in the LPAA loop. A reading's job is comprehension before composition: students predict, read, and mentally run code here before they touch a keyboard in Practice and Apply.

## When to Use This Skill

- Creating new module readings or chapter content
- Adapting external content (textbook chapters, Runestone gaps) into course readings
- Writing GameFAQs-style guides (End Boss guides, cheat sheets)
- Reviewing/revising existing readings
- When asked to "write a reading about X"

## Reading Specifications

### Length & Scope
- **Target**: 1,500–2,500 words (guides/cheat sheets may run shorter)
- **Reading time**: 10–15 minutes
- **Scope**: One major concept or 2–3 tightly related ideas
- **Readability**: 10th grade on all prose. The complexity lives in the code and the problem, not the sentences.
- **Role**: Carries PRIMM's **Predict** stage. Every reading must contain at least one predict-the-output moment (below).

### Required Sections

```markdown
---
title: "Reading Title"
module: M0X
lpaa_beat: Learn
estimated_time: "XX minutes"
prerequisites: ["previous-reading"] or "None"
---

# [Title]

## Learning Objectives
[3-5 specific, measurable objectives tied to the module's MLOs]

## Why This Matters
[1-2 paragraphs connecting to the spine, the dungeon project, or transfer goals]

## The Core Concept
[Main content — multiple subsections; predict-the-output moments live here]

## Putting It Together
[Synthesis and connections]

## Common Questions
[FAQ format, 3-5 questions students actually ask]

## Check Yourself
[2-3 quick self-test items — same style as the exit ticket, answers included]

## Next Steps
[Points at this module's exit ticket (Practice) and Apply tutorial]
```

## Section-by-Section Guidance

### Learning Objectives
Use observable Bloom verbs, matched to the module's MLOs (see `CSC-134-learning-objectives.md`): trace, predict, classify, implement, refactor.

**Good**: "By the end of this reading, you'll be able to predict a `for` loop's output using a trace table."
**Bad**: "Understand loops."

### Why This Matters
Connect to:
- The problem-solving spine (decompose → represent → implement → verify)
- The running dungeon/RPG project the concept will feed (Rooms, Heroes, menus)
- Transfer relevance — "you will meet this again in your four-year program"
- The AI-fluency goal: "you can't supervise code you can't read"

### The Core Concept

Structure for learning:
1. **Hook**: a concrete, relatable example (dungeon canon welcome, not required)
2. **Predict**: show a short complete program, ask the reader to predict the output *before* revealing it
3. **Reveal + explain**: show the actual output, then explain why — especially where prediction commonly goes wrong
4. **Expand**: build complexity gradually, one new element per example
5. **Connect**: link to prior modules and forward to the Apply tutorial

**The predict-the-output block** is this course's signature move:

````markdown
**Predict first.** Read this program. What prints? Write your guess down before scrolling.

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << "Room " << i << endl;
    }
    return 0;
}
```

<details>
<summary>Reveal the output</summary>

```
Room 1
Room 2
Room 3
```

If you guessed `Room 0` first — good instinct, loops often start at 0.
This one starts `i` at 1. The start value is a choice, not a rule.
</details>
````

### Code Example Rules (non-negotiable)

- Every example is a **complete program** (`#include`s + `main`) that compiles clean under `g++ -std=c++17 -Wall -Wextra`. Zero warnings.
- Single-file convention: prototypes top, `main` middle, definitions bottom — **only from M6 onward**. M0–M5 readings show `main`-only programs.
- Show **Program Output** in its own fenced block after each runnable example, exactly as printed.
- Keep examples under ~25 lines; comment the non-obvious lines.
- When a reading discusses errors, classify them with the four-term taxonomy: **syntax / static semantic / runtime / logic**. Use the plain-language names on first use ("broke the grammar", "grammar fine, meaning impossible", "ran, then fell over", "did what you said, not what you meant").
- Flowcharts are **Mermaid**, in fenced ` ```mermaid ` blocks.

### The GameFAQs Voice Option

Guide-style readings (loops = the End Boss, cheat sheets, walkthroughs) may adopt strategy-guide framing: boss stats, STRATEGY sections, "common wipe causes." Constraints:

- The skin must be **separable**: strip the flavor and every objective, example, and requirement survives intact.
- Reuse the established dungeon canon (Rooms, Hero, Monster, Level Up Stats) — don't invent parallel lore.
- Keep the prose at 10th grade even in-character.

### Common Questions
Answer questions students actually ask:
- "But what if the user types a word instead of a number?"
- "Why does `5 / 2` print `2`?"
- "Do I need to memorize this syntax?"
- "Can I just ask AI?" (Answer honestly, per the course's AI ladder: yes for explanation, and you still must be able to read the answer.)

### Check Yourself
2–3 short items in exit-ticket style — predict-the-output or classify-the-error — **with answers and one-line explanations included**. This primes the completion-gated exit ticket without pre-testing it. No trick questions.

### Next Steps
Specific and LPAA-shaped:
- "Take the Module X exit ticket" (the Practice gate)
- "Then bring this reading to class for the type-in tutorial" (Apply)
- Optional deeper dives (Runestone `thinkcpp` sections, cppreference pages)

## Formatting Guidelines

### Headers
One `#` title; `##` for major sections; `###` for subsections.

### Emphasis
- **Bold** for key terms on first use
- `Code formatting` for keywords, file names, commands, flags
- Callouts:

```markdown
> **💡 Pro Tip**: [Helpful insight]

> **⚠️ Common Pitfall**: [What to avoid — name the error class it causes]

> **🔗 Connection**: [Link to other module or the dungeon project]
```

## Quality Checklist

Before completing a reading:

- [ ] Frontmatter complete (title, module, LPAA beat, time estimate, prereqs)
- [ ] 3–5 objectives aligned to the module's MLOs
- [ ] At least one predict-the-output moment before any output reveal
- [ ] All C++ examples complete, and compile with zero warnings under `g++ -std=c++17 -Wall -Wextra` (verified with Bash where available, else marked "untested")
- [ ] Program output shown after runnable examples
- [ ] No prototypes/function definitions shown before M6
- [ ] Errors named with the four-term taxonomy
- [ ] Any flowchart is Mermaid
- [ ] Prose reads at 10th grade or below
- [ ] Theme/skin separable from structure
- [ ] Check Yourself items have answers; no trick questions
- [ ] Next Steps route to this module's exit ticket and Apply tutorial
- [ ] Word count 1,500–2,500
- [ ] Voice consistent with course-content-writer skill

## Anti-Patterns to Avoid

**Output before prediction**: Never show a program and its output in the same breath the first time — that skips the Predict beat.
**Fragment code**: `cout << x;` floating alone teaches copy-paste failure. Wrap it in a minimal `main`.
**Premature machinery**: No pointers before M7, no prototypes before M6, no `class` before the struct→class arc.
**Wall of text**: Break up every 3–4 paragraphs with a header, example, or diagram.
**Theme lock-in**: If removing the dungeon flavor breaks a sentence's meaning, restructure.
**Ending abruptly**: Always route to the exit ticket and Apply tutorial.
