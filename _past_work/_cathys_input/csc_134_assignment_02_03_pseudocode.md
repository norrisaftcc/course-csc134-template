# Assignment 02 — If Only: Achievement Stamps (Pseudocode Starter)

## Purpose (short)

Practice **independent **``** statements** (no `else`, no `else if`). You’ll trigger multiple messages for one input. This intentionally sets up the need for `else if` in Assignment 03.

## What students will do

1. Create a new **public** repo: `csc134-if-only-stamps`.
2. Implement `main.cpp` by **translating pseudocode comments into C++**.
3. Ask for a single integer **score** (0–100).
4. Use **≥5 independent **``** statements** to print achievement messages when conditions are true.
5. Commit, test different inputs, **commit again** with improvements.

---

## Requirements

- **Translate from pseudocode:** Implement the comment pseudocode as real C++ `if` statements (**no** `else`, **no** `else if`).
- File: `main.cpp` with a **comment header** (name, course, assignment, date, description).
- Read one `int score`.
- Include at least one check each for:
  - **Range** (e.g., `score >= 90`)
  - **Lower bound** (e.g., `score < 60`)
  - **Divisibility/evenness** (e.g., `score % 2 == 0`, `score % 10 == 0`)
- Print **one line per condition** that was true; multiple lines may print for one score.

> **Reminder of **``** / **``**:** `<foo>` is your chosen favorite thing (category + item). You may reference it in one of your messages for fun.

---

## Starter code (copy/paste)

```cpp
/*
  Name: <Your Name>
  Course: CSC 134
  Assignment: 02 — If Only: Achievement Stamps
  Date: <YYYY-MM-DD>
  Description: Practice independent if statements (no else / else if).
*/
#include <iostream>
using namespace std;

int main() {
    int score;

    // 1) Prompt the user for a score in 0..100 and read it into `score`.
    //    Example prompt: "Enter score (0-100): "

    // 2) Implement the following as independent checks (no else/else if).
    //    Each true condition should print exactly one line (a "stamp"):
    //    a) If score >= 90      -> print: Stamp: High Achiever (>=90)
    //    b) If score >= 80      -> print: Stamp: Solid Performance (>=80)
    //    c) If score % 2 == 0   -> print: Stamp: Even Number Bonus
    //    d) If score % 10 == 0  -> print: Stamp: Round Number Bonus
    //    e) If score < 60       -> print: Stamp: Practice Reminder (<60)

    // 3) Multiple messages may print for a single score.

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

**A. GitHub Web Editor → Codespaces (simple start)**

1. Add `main.cpp` in the **web editor** and commit.
2. **Code ▾ → Create codespace on main**.
3. In Codespaces Terminal: `g++ main.cpp -o stamps && ./stamps`
4. Edit in Codespaces and **commit** from Source Control.

**B. GitHub Codespaces (cloud IDE only)**

1. Create codespace first.
2. Add `main.cpp`, run in Terminal as above.
3. Commit via Source Control.

**C. Local machine (VS Code + Git)**

1. Clone the repo to VS Code.
2. Ensure a C++ compiler (Xcode CLT / MinGW‑w64 / GCC).
3. Build/run:
   - macOS/Linux: `g++ main.cpp -o stamps && ./stamps`
   - Windows (MinGW): `g++ main.cpp -o stamps && stamps.exe`
4. Commit and **push**.

## GitHub workflow

1. Create repo `csc134-if-only-stamps` (Public).
2. Add `main.cpp` → **Commit** (`feat: initial stamps program`).
3. Test inputs, tweak messages/conditions.
4. **Commit again** (`feat: add round-number stamp`, `style: clarify output`).

## Deliverables

- **URL** to `csc134-if-only-stamps` with a compiling/running `main.cpp`.

## Rubric (20 pts)

- (4) Compiles and runs; clean output.
- (6) Uses ≥5 **independent** `if` statements (no `else` / `else if`).
- (4) Covers range, lower bound, and divisibility checks.
- (3) Sensible commit messages and at least 2 commits.
- (3) Readable code and comment header.

## Common issues

- Using `else if` by habit — keep them **independent**.
- Forgetting `%` rules (modulo gives the remainder).
- Overlapping messages are **expected** in this assignment.

---

# Assignment 03 — One Choice Only: Grade Reporter (Pseudocode Starter)

## Purpose (short)

Introduce ``** chains** to make a **single, mutually exclusive** decision. Convert a numeric score into one letter grade.

## What students will do

1. Create a new repo: `csc134-grade-reporter`.
2. Implement `main.cpp` by **translating pseudocode comments into C++**.
3. Read an integer `score` (0–100).
4. Use an `if / else if / else` chain to output **one** letter grade (A, B, C, D, F).
5. Add simple **input validation**: if `score` is outside 0–100, print an error message instead of a grade.
6. Commit, test edge cases, commit improvements.

---

## Requirements

- **Translate from pseudocode:** Implement the comment pseudocode as a single `if / else if / else` chain (not multiple separate `if`s).
- File: `main.cpp` with a comment header.
- Grade boundaries (common thresholds):
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

    // 1) Prompt the user for a score (0-100) and read it into `score`.

    // 2) Implement exactly one of the following outcomes using a single
    //    if / else if / else chain (mutually exclusive):
    //    - If score < 0 or score > 100 -> print: Invalid score
    //    - Else if score >= 90         -> print: Grade: A
    //    - Else if score >= 80         -> print: Grade: B
    //    - Else if score >= 70         -> print: Grade: C
    //    - Else if score >= 60         -> print: Grade: D
    //    - Else                        -> print: Grade: F

    // 3) (Optional) After the grade, print a short encouragement line
    //    that references your <foo>.

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

**A. Web Editor → Codespaces** → run: `g++ main.cpp -o grader && ./grader`\
**B. Codespaces only**\
**C. Local VS Code**

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

- In Assignment 02, enter `95` to show **multiple** messages firing; segue to why **else-if** is needed for a single choice.
- In Assignment 03, emphasize **ordering** (high-to-low).
- Keep commit messages verb-first (`feat:`, `fix:`, `style:`).
- Encourage students to paste repo URLs for peer feedback.

