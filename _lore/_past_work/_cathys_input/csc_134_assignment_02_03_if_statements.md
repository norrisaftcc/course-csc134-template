# Assignment 02 — If Only: Achievement Stamps

## Purpose (short)

Practice **independent **``** statements** (no `else`, no `else if`). You’ll trigger multiple messages based on one input. This sets up the need for `else if` in the next assignment.

## What students will do

1. Create a new **public** repo: `csc134-if-only-stamps`.
2. Write `main.cpp` using the starter below.
3. Ask for a single integer **score** (0–100).
4. Use **≥5 independent **``** statements** to print achievement messages when conditions are true.
5. Commit, test different inputs, **commit again** with improvements.

---

## Requirements

- File: `main.cpp` with a **comment header** (name, course, assignment, date, description).
- Read one `int score`.
- Use **only **``** statements** (no `else`, no `else if`).
- Include at least one check each for:
  - **Range** (e.g., `score >= 90`)
  - **Lower bound** (e.g., `score < 60`)
  - **Even/odd or divisibility** (e.g., `score % 2 == 0`, `score % 10 == 0`)
- Print **one line per condition** that was true; multiple lines may print for one score.
- Clear, readable output (use `cout` + `endl`).

> **Reminder:** `<foo>` is your chosen favorite thing (category + item). You don’t have to use `<foo>` here, but you may add a fun message like `If score is even → print a line that references your favorite <foo>`.

---

## Starter code (copy/paste)

```cpp
/*
  Name: <Your Name>
  Course: CSC 134
  Assignment: 02 — If Only: Achievement Stamps
  Date: <YYYY-MM-DD>
  Description: Practice independent if statements.
*/
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter score (0-100): ";
    cin >> score;

    // Independent ifs — several may fire for one score
    if (score >= 90) {
        cout << "Stamp: High Achiever (>=90)" << endl;
    }
    if (score >= 80) {
        cout << "Stamp: Solid Performance (>=80)" << endl;
    }
    if (score % 2 == 0) {
        cout << "Stamp: Even Number Bonus" << endl;
    }
    if (score % 10 == 0) {
        cout << "Stamp: Round Number Bonus" << endl;
    }
    if (score < 60) {
        cout << "Stamp: Practice Reminder (<60)" << endl;
    }

    return 0;
}
```

---

## Try these inputs

- `95` → Expect several messages (>=90, >=80, even?, round?).
- `83` → Should trigger >=80 only.
- `50` → Practice Reminder? Even? Round Number?
- `59` → Practice Reminder only.

---

## Choose your workflow (pick one)

- **Web editor → Codespaces** (simple start): add file, commit, then **Code ▾ → Create codespace on main** and run in Terminal:\
  `g++ main.cpp -o stamps && ./stamps`
- **Codespaces only**: create codespace first, add file there, run in Terminal.
- **Local VS Code**: clone, add file, build/run in terminal.

## GitHub workflow

1. Create repo `csc134-if-only-stamps` (Public).
2. Add `main.cpp` → **Commit** (`feat: initial stamps program`).
3. Test inputs, tweak messages/conditions.
4. **Commit again** (`feat: add round-number stamp`, `style: clarify output`, etc.).

## Deliverables

- **URL** to `csc134-if-only-stamps` with a compiling/running `main.cpp`.

## Rubric (20 pts)

- (4) Compiles and runs; clean output.
- (6) Uses ≥5 **independent** `if` statements (no `else` / `else if`).
- (4) Covers range, lower bound, and divisibility checks.
- (3) Sensible commit messages and at least 2 commits.
- (3) Readable code and comment header.

## Common issues

- Using `else if` by habit — don’t; keep them **independent**.
- Forgetting `%` rules (modulo gives the remainder).
- Overlapping messages are **expected** in this assignment.

---

# Assignment 03 — One Choice Only: Grade Reporter

## Purpose (short)

Introduce ``** chains** to make a **single, mutually-exclusive** decision. You’ll convert a numeric score into one letter grade.

## What students will do

1. Create a new repo: `csc134-grade-reporter`.
2. Read an integer `score` (0–100).
3. Use an `if / else if / else` chain to output **one** letter grade (A, B, C, D, F).
4. Add simple **input validation**: if `score` is outside 0–100, print an error message instead of a grade.
5. Commit, test edge cases, commit improvements.

---

## Requirements

- File: `main.cpp` with a comment header.
- Use an `if / else if / else` **chain** (not multiple separate `if`s).
- Grade boundaries (you may adopt these common thresholds):
  - A: `score >= 90`
  - B: `score >= 80`
  - C: `score >= 70`
  - D: `score >= 60`
  - Else: F
- Input validation: if `score < 0 || score > 100` → print `Invalid score` and skip the grade.

> **Optional twist:** After printing the letter, print a short encouragement line that references your  (e.g., “Channel your  energy for the next quiz!”).

---

## Starter code (copy/paste)

```cpp
/*
  Name: <Your Name>
  Course: CSC 134
  Assignment: 03 — One Choice Only: Grade Reporter
  Date: <YYYY-MM-DD>
  Description: Use if/else-if/else to choose exactly one outcome.
*/
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter score (0-100): ";
    cin >> score;

    if (score < 0 || score > 100) {
        cout << "Invalid score" << endl;
    } else if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 80) {
        cout << "Grade: B" << endl;
    } else if (score >= 70) {
        cout << "Grade: C" << endl;
    } else if (score >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    return 0;
}
```

---

## Test cases (edge-aware)

- `-5` → `Invalid score`
- `0` → `Grade: F`
- `59` vs `60`
- `69` vs `70`
- `79` vs `80`
- `89` vs `90`
- `100` → `Grade: A`

---

## Choose your workflow (pick one)

- **Web editor → Codespaces** → run: `g++ main.cpp -o grader && ./grader`
- **Codespaces only**
- **Local VS Code**

## GitHub workflow

1. Create repo `csc134-grade-reporter` (Public).
2. Add `main.cpp` → **Commit** (`feat: initial grade reporter`).
3. Test edge cases, refine messages.
4. **Commit again** (`fix: validation`, `style: clarify boundaries`).

## Deliverables

- **URL** to `csc134-grade-reporter` with a compiling/running `main.cpp`.

## Rubric (20 pts)

- (5) Compiles and runs; clear output.
- (7) Correct `if / else if / else` chain produces exactly **one** grade.
- (4) Proper handling of invalid input.
- (2) At least 2 commits with sensible messages.
- (2) Readable code and comment header.

## Common issues

- Putting the highest threshold **after** a lower one (order matters).
- Accidentally using independent `if`s and printing multiple grades.
- Missing validation → negative or >100 scores should be rejected.

---

## Instructor Notes (quick)

- Show Assignment 02 first and deliberately input `95` to demonstrate **multiple** messages firing; segue to the need for **else-if**.
- In Assignment 03, emphasize **ordering** (high-to-low).
- Encourage tight, verb-first commit messages (`feat:`, `fix:`, `style:`).
- Invite students to share a screenshot or short codespace link preview if available.

