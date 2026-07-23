---
name: exit-ticket-generator
description: "Create Practice-beat exit tickets for CSC-134: 5-8 low-stakes comprehension items (predict, classify, trace), completion-gated, no trick questions"
allowed-tools: "Read,Write,Bash,Glob,Grep"
---

# Exit Ticket Generator

Create the checkpoint quiz for CSC-134's **Practice** beat — the low-stakes comprehension gate between the reading (Learn) and the type-in tutorial (Apply). Exit tickets carry PRIMM's Run + Investigate stages: they verify a student can read and mentally execute code before being asked to modify or write any.

## When to Use This Skill

- Creating a module's exit ticket
- Writing extra practice/review item sets in exit-ticket style
- Converting quiz banks from other formats into course items
- When asked to "make an exit ticket / checkpoint quiz for X"

## Ground Rules (these define the genre)

1. **The gate is completion, not score.** Students must *finish* the ticket to proceed to Apply; a wrong answer costs nothing but triggers feedback. Write items and feedback accordingly — every wrong answer is a teaching moment, not a penalty.
2. **5–8 items.** Fewer is too thin to check comprehension; more turns low-stakes into homework. Target 10–15 minutes.
3. **No trick questions — stated program policy.** No "which compiles?" where two answers differ by an invisible character, no gotcha operator precedence beyond what the reading taught, no "all/none of the above." Items verify the module's MLOs, not stamina or lawyer-reading.
4. **Comprehension only.** Students read, predict, trace, and classify. They never write code on an exit ticket — that's Apply and Assess.
5. **10th-grade readability** on every stem. The thinking is in the code, not the sentence.
6. **All code in items must be real.** Snippets shown as working programs must compile clean under `g++ -std=c++17 -Wall -Wextra` and produce exactly the outputs claimed. Broken-on-purpose snippets (classify-the-error items) must contain **exactly one** flaw, and it must be the flaw the answer key names. Verify with Bash where a toolchain is available; otherwise mark the ticket "untested" for human verification.

## The Four Item Types

Use a mix; a good ticket for a code-bearing module (M3+) draws on at least three of the four.

### 1. Predict-the-output
Show a short complete program (or the ticket's shared program) and ask what prints.

```markdown
**Item 3.** What does this program print?

```cpp
#include <iostream>
using namespace std;

int main()
{
    int gold = 10;
    gold = gold + 5;
    cout << "Gold: " << gold << endl;
    return 0;
}
```

- A) `Gold: 10`
- B) `Gold: 15`   ← key
- C) `Gold: gold + 5`
- D) It does not compile
```

Rules: the program is complete and short (≤ 15 lines); the output options are exact strings including spacing; include "it does not compile" as an option only when the reading covered why it *does* compile.

### 2. Classify-the-error
Show a program with exactly one flaw; students name its class using the course's four-term taxonomy: **syntax** ("broke the grammar"), **static semantic** ("grammar fine, meaning impossible"), **runtime** ("ran, then fell over"), **logic** ("did what you said, not what you meant").

Rules: the four options are always the four taxonomy terms, in that order; the flaw must be unambiguous under the taxonomy as taught (if experts could argue, pick a different flaw); for runtime/logic items, state the input used.

### 3. Trace-the-branch / trace-the-loop
Give code plus a specific input (or starting state); ask which branch runs, how many times the body executes, or what a variable holds at a marked line. Provide a trace-table scaffold for loop items in M5+:

```markdown
**Item 5.** For the loop below, fill in the trace table, then answer:
how many lines print?

| pass | i before | condition (i < 3)? | prints |
|------|----------|--------------------|--------|
| 1    |          |                    |        |
```

Rules: one concrete input per item, stated in the stem; the trace table is offered, not graded — the answer is the final question.

### 4. Which-line-changes
Ask which single line must change to achieve a stated new behavior ("make it count to 10 instead of 5", "make the discount apply only over $50"). Number the lines in the listing.

Rules: exactly one line is the correct answer; the change required must be within the module's taught material; never require the student to write the new line — identifying it is the skill.

## Distractors: Use the Cohort's Real Wrong Answers

Distractors should be **the mistakes students actually make**, because a student who picks one gets feedback aimed at their actual misconception.

- **If a distractor bank is provided** (a file or doc of the cohort's real wrong answers, common misreads, past-ticket stats), pull distractors from it first and note the source in the answer key: `<!-- distractor B: 40% of Fall '25 cohort -->`.
- **If no bank exists**, derive distractors from the canonical misconception catalog: off-by-one (loop runs one time too many/few), integer division (`5 / 2` → `2.5`), assignment-vs-comparison intuitions, uninitialized reads, `endl` vs no newline, index-vs-value (`i` vs `array[i]`), start-at-0 vs start-at-1.
- Every distractor must be *arrivable-at* by a plausible wrong mental model. "Random wrong number" is a wasted option.
- 3–4 options per item. All options plausible in format (same units, same spacing style as the key).

**Accepting a distractor bank as input:** when invoked with a path/doc of prior wrong answers, read it before writing items, prefer its entries, and append any *new* predicted misconceptions to the ticket's answer key so the bank can grow.

## Output Format

Produce two artifacts per ticket:

### Student version — `mX-exit-ticket.md`

```markdown
---
title: "Module X Exit Ticket: [Topic]"
module: M0X
lpaa_beat: Practice
items: N
estimated_time: "10-15 minutes"
gate: completion   # finishing unlocks the Apply tutorial; score is feedback only
---

# Module X Exit Ticket: [Topic]

This is a checkpoint, not a test. Finish it and you move on — wrong answers
just tell us both what to review. No trick questions, ever.

[Items 1..N]
```

### Answer key — `mX-exit-ticket-key.md`

For each item: the key, **why the key is right in one sentence**, and **per-distractor feedback** naming the misconception ("If you chose A, you may have expected the loop to run while `i <= 3` — check the condition operator"). Tag each item with its type, the MLO it checks, and (for classify items) the error class.

## Sequencing Within a Ticket

- Order items easy → harder; open with a confidence builder tied directly to the reading's predict-the-output example (varied, not copied).
- One concept step per item. If an item needs two new ideas at once, split it.
- Reuse the module's running example program across 2–3 items where natural (same code, different questions) — less reading, more thinking.
- Stay strictly inside the Make gradient position: no function-reading before M6, no pointer items before M7.

## Quality Checklist

Before completing an exit ticket:

- [ ] 5–8 items; 10–15 minute estimate
- [ ] Gate stated as completion, not score, in the student-facing intro
- [ ] At least three of the four item types represented (M3+ modules)
- [ ] Every "working" snippet compiles clean under `g++ -std=c++17 -Wall -Wextra` and prints exactly the claimed output (Bash-verified or marked "untested")
- [ ] Every classify item has exactly one flaw, unambiguous under the four-term taxonomy
- [ ] Which-line-changes items have exactly one defensible answer
- [ ] Distractors come from the provided bank where one exists; sources annotated in the key
- [ ] Every distractor maps to a named misconception with feedback in the key
- [ ] No trick questions: no invisible-character differences, no untaught precedence, no "all/none of the above"
- [ ] Items check this module's MLOs only; nothing from future modules
- [ ] Stems at 10th-grade readability
- [ ] Answer key tags each item with type + MLO
- [ ] Student version and key are separate files

## Anti-Patterns to Avoid

**Score-gating language**: "You need 80% to continue" — wrong course. Completion gates; feedback teaches.
**Memory items**: "Which header provides `cout`?" checks recall, not comprehension. If it matters, it's on the cheat sheet.
**Double-flaw classify items**: a snippet with a missing semicolon *and* an infinite loop can't be classified — one flaw per item.
**Write-the-code items**: composition belongs to Apply/Assess. Tickets only read.
**Clever distractors**: an option only an expert would find tempting teaches nothing. Distractors impersonate novices, not lawyers.
