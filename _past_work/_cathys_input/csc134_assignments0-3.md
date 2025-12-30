# CSC 134 — Assignments 00–03 (Student‑First Path + “Resume Alert!”)

*This packet puts all four early assignments in one place and tags the workforce skills you can honestly list as “one‑day experience” on your resume or LinkedIn.*

---

## Course Ground Rules (Weeks 1–8)

* **AI assistants (e.g., Gemini Flash) allowed** for: planning, pseudocode, test tables, README/docs, diagramming, and rubber‑duck debugging of concepts.
* **Not allowed** before Week 9: generating C++ source code or pasting AI‑written code.
* Primary workflows: **GitHub Web → Codespaces** (simple start), **Codespaces only** (cloud IDE), or **Local VS Code + Git**.

---

# Assignment 00 — GitHub Setup & Personal Repo

**Purpose:** Learn the repeatable GitHub workflow: *create → edit/upload → write commit message → commit*.

### What you’ll do

1. Create a GitHub account (or sign in).
2. Create a **public** repo named **`<your-github-username>`** (example: `anorris`).
3. Add and personalize `README.md` (**include your favorite `<foo>`**: a category + item you choose).
4. Create `interests.md` and update it later. Aim for **4+ commits** total.

### Deliverable

* URL to your public repo named exactly `your-github-username`.

### “Resume Alert!” — you now have *one‑day experience* with:

* **Version control basics (GitHub):** create repo, edit files, write concise commit messages.
* **Professional communication:** author a clear README (purpose, summary bullets).
* **Tool fluency:** GitHub Web UI; optional CLI basics.

**Resume line template:** *“Set up GitHub profile repo; authored README; practiced incremental commits and history hygiene (1‑day experience).”*

---

# Assignment 01 — Hello, Profile! (C++)

**Purpose:** Write a tiny C++ program that uses `main()`, `cin`, and `cout`; practice committing code to a new repo.

### What you’ll do

1. Create **`csc134-hello-profile`** (Public).
2. Add `main.cpp` with a comment header; prompt for **first name** and **age**; print two lines of output.
3. Build & run (Codespaces **or** local); improve output; **commit again**.

### Starter (skeleton)

```cpp
#include <iostream>
using namespace std;
int main() {
    string firstName; int age;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Hello, " << firstName << "!" << endl;
    cout << "You are " << age << " years old." << endl;
    return 0;
}
```

### Deliverable

* Repo URL to `csc134-hello-profile` containing `main.cpp` that compiles and runs.

### “Resume Alert!” — you now have *one‑day experience* with:

* **C++ console I/O:** `cin`/`cout`, line formatting.
* **Build/run workflow:** compile in Codespaces or local VS Code; troubleshoot basic errors.
* **Incremental change management:** make and explain small improvements via commits.
* **AI‑assisted planning (non‑code):** use an assistant for requirement restatements, pseudocode, and test inputs.

**Resume line template:** *“Built and ran a C++ console app (I/O, `main`, compile/run); improved output formatting; documented changes in Git (1‑day experience).”*

---

# Assignment 02 — If Only: Achievement Stamps

**Purpose:** Practice **independent** `if` statements (no `else` / `else if`). Multiple messages may print for one input.

### What you’ll do

1. Create **`csc134-if-only-stamps`**.
2. Read an integer **score** (0–100).
3. Implement **≥ 5 independent** `if` checks (e.g., `>=90`, `>=80`, `%2==0`, `%10==0`, `<60`).
4. Print one line for each true condition; test a variety of inputs; commit improvements.

### Pseudocode‑first starter (you translate to code)

```cpp
// prompt for score (0..100) and read into `score`
// if score >= 90      -> print High Achiever
// if score >= 80      -> print Solid Performance
// if score % 2 == 0   -> print Even Number Bonus
// if score % 10 == 0  -> print Round Number Bonus
// if score < 60       -> print Practice Reminder
```

### Deliverable

* Repo URL to `csc134-if-only-stamps` with a compiling `main.cpp`.

### “Resume Alert!” — you now have *one‑day experience* with:

* **Control‑flow logic (independent conditions):** designing overlapping checks with clear outputs.
* **Modulo arithmetic for branching:** `%2`, `%10` patterns.
* **Edge‑aware testing:** try representative and boundary values; observe multi‑message behavior.
* **Requirements → code:** translate pseudocode comments into working C++.

**Resume line template:** *“Implemented multi‑criteria condition checks in C++ (independent `if`s), including divisibility logic and boundary tests; documented results in Git (1‑day experience).”*

---

# Assignment 03 — One Choice Only: Grade Reporter

**Purpose:** Use an `if / else if / else` **chain** to produce **exactly one** outcome and add **input validation**.

### What you’ll do

1. Create **`csc134-grade-reporter`**.
2. Read `score` (0–100). If out of range, print `Invalid score`. Otherwise, output letter grade **A/B/C/D/F** via a single chain.
3. Test edge cases (`59/60`, `69/70`, `79/80`, `89/90`, `100`, negatives); commit improvements.

### Pseudocode‑first starter

```cpp
// read score (0..100)
// if score < 0 or score > 100 -> print Invalid score
// else if score >= 90 -> A
// else if score >= 80 -> B
// else if score >= 70 -> C
// else if score >= 60 -> D
// else -> F
```

### Deliverable

* Repo URL to `csc134-grade-reporter` with a compiling `main.cpp`.

### “Resume Alert!” — you now have *one‑day experience* with:

* **Decision chains (mutually exclusive):** correct ordering to ensure a single result.
* **Defensive programming:** input validation and friendly error messaging.
* **Test table design:** systematic edge comparisons and expected outcomes.
* **Clean UX in console apps:** concise, unambiguous output lines.

**Resume line template:** *“Built grade classification with validated input and mutually exclusive decision chain; designed and ran edge‑case tests; versioned changes in Git (1‑day experience).”*

---

## Quick Submission Checklist (all assignments)

* [ ] Repo is **public** and named correctly.
* [ ] `main.cpp` (where applicable) compiles and runs.
* [ ] At least **2 commits** with clear, verb‑first messages.
* [ ] README includes a short description and run instructions.
* [ ] Test inputs tried are noted (in README or a `tests.md`).

## Optional “Polish” Extras (earn shout‑outs)

* Add a tiny **test table** (Input → Expected → Actual).
* Add a **screenshot** of a successful run.
* Use the assistant to draft a concise **Problem → Approach → Result** summary (no code generation).

---

## FAQ

**What’s `<foo>` again?** A placeholder for a *favorite thing you pick* (category + item). Example: category = “anime character”; item = “Tanjiro.”
**Do I have to use Codespaces?** No. Codespaces is the simplest path to run C++ in a browser. Local VS Code works too.
**Can I ask an AI to fix my code?** Before Week 9: you can ask conceptual questions, plan tests, or restate compiler errors—but **don’t** paste AI‑written C++ into your work.

