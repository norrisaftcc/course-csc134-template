# Assignment 00 — GitHub Setup & Personal Repo

## Purpose (short)

Learn a repeatable GitHub workflow: **create → edit/upload → write commit message → commit**. Practice it multiple times.

## What students will do

1. Create a GitHub account (or sign in).
2. Create a **public** repository named `` (example: if your username is `anorris`, repo name is `anorris`).
3. Add a `README.md` that introduces you (**include your favorite **).
4. Make at least **two separate commits** by editing or uploading updated content.
5. Add a second file and practice updating it.

---

## Step-by-step (web workflow)

1. Go to **github.com** → **Sign up** or **Sign in**. Confirm your email.
2. Click your profile picture → **Your repositories** → **New**.
3. **Repository name:** `your-exact-username`\
   **Visibility:** Public\
   ✅ Check **Add a README file** → **Create repository**.
4. Open `README.md` → **Edit**. Add your info using the template below.\
   **Commit changes**: Write a short message (e.g., `docs: personalize README`) → **Commit changes**.
5. Edit again or upload a new version.\
   **Commit changes** with a different message (e.g., `docs: add course + goals`).
6. Click **Add file** → **Create new file**. Name it `interests.md`. Add 3–5 bullets.\
   **Commit changes** (e.g., `docs: add interests list`).
7. Open `interests.md` again → modify one bullet or add another section.\
   **Commit changes** (e.g., `docs: revise interests with details`).

> **Goal:** You’ve practiced the cycle at least **4 commits** across `README.md` and `interests.md`.

---

### Quick reminder: What are 'foo' and 'bar'?

- In programming examples, **foo** and **bar** are placeholder names.
- For this course,  means “a favorite thing of your choosing (category + item),” e.g., anime character, musician, video game, or race car driver.
- **bar** is just a second placeholder we might use later.

## README.md template (copy/paste)

```
# Hello, I’m <Your Name>

- Major / Program: <Your major>
- Interests: <short list>
- Favorite <foo>: <your chosen category and item>  
  _(example: Category = "anime character", Item = "Tanjiro" — choose any category you like)_
- Tools I’m comfortable with: <VS Code, Replit, etc.>
- This semester I’m learning: C++ in CSC 134
```

---

## Deliverable

- **URL** to your public repository named exactly `your-github-username`.

## Rubric (10 pts)

- (2) Account created and email confirmed.
- (3) Public repository exists and is correctly named.
- (3) `README.md` personalized and updated with a second commit.
- (2) `interests.md` added and later modified (separate commit).

## Troubleshooting

- **Save ≠ Commit**: In GitHub, every change should have a **commit message** before it’s saved to history.
- If a filename looks wrong, rename it in the repo (three-dots menu) and commit the change.
- If you can’t find your repo, go to **Your repositories** from your profile.

---

## Optional (CLI workflow, for the curious)

```
# one-time setup per machine
# git config --global user.name "Your Name"
# git config --global user.email "you@example.com"

mkdir my-profile && cd my-profile
echo "# Hello, I’m <Your Name>" > README.md

git init
git add README.md
git commit -m "docs: initial README"

git branch -M main
# create an empty repo named <username> on GitHub first, then:
git remote add origin https://github.com/<username>/<username>.git
git push -u origin main
```

---

# Assignment 01 — Hello, Profile! (C++)

## Purpose (short)

Write a tiny C++ program that uses `main()`, **input** with `cin`, and **output** with `cout`. Practice committing code to a **new GitHub repo**.

## What students will do

1. Create a new **public** repo named ``.
2. Write `main.cpp` (starter below).
3. Compile and run it.
4. Commit your code, then make one improvement and **commit again**.

## Choose your workflow (pick one)

**A. GitHub Web Editor → Codespaces (simple start)**

1. In your new repo, add `main.cpp` in the **web editor** and commit.
2. When you're ready to run code, click **Code ▾ → Create codespace on main**.
3. In Codespaces (VS Code in the browser), open the built‑in **Terminal** and run:
   - `g++ main.cpp -o hello && ./hello`
4. Edit in Codespaces and **commit** changes from the Source Control panel.

**B. GitHub Codespaces (cloud IDE only)**

1. Create the repo, then **Create codespace on main** immediately.
2. Add `main.cpp` in Codespaces, run it in the Terminal as above.
3. Commit via the Source Control panel.

**C. Local machine (VS Code + Git)**

1. Clone your repo (**Code ▾ → HTTPS**), open in VS Code.
2. Ensure a C++ compiler is installed (e.g., Xcode CLT on macOS, MinGW‑w64 on Windows, GCC on Linux).
3. Build/run in VS Code terminal:
   - macOS/Linux: `g++ main.cpp -o hello && ./hello`
   - Windows (MinGW): `g++ main.cpp -o hello && hello.exe`
4. Commit in VS Code or GitHub Desktop, then **push**.

---

## Requirements

**Quick reminder on **``** / **``**:** `<foo>` is a placeholder for “a favorite thing you pick (category + item).” `bar` is a second placeholder we might use later.

- File: `main.cpp` with a **comment header** at the top (name, course, assignment, date, brief description).
- Ask for **first name** (one word) and **age** (integer).
- Output at least **two lines** that use this info (e.g., greeting and age line).
- Use `cout` and `endl`.
- Use `cin` for input.
- Program must compile and run without errors.

> **Stretch (optional):** Ask for a third input: your favorite  (you decide what  means—category + item). Or try `getline` to accept a full name on one line.

---

## Starter code (copy/paste)

```cpp
/*
  Name: <Your Name>
  Course: CSC 134
  Assignment: 01 — Hello, Profile!
  Date: <YYYY-MM-DD>
  Description: Simple C++ IO practice using cin/cout.
*/
#include <iostream>
using namespace std;

int main() {
    string firstName; // one word
    int age;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << firstName << "!" << endl;
    cout << "You are " << age << " years old." << endl;

    return 0;
}
```

---

## Build & run

Use your chosen workflow above.

- **Codespaces (recommended once you're ready to run):** Open **Terminal** → `g++ main.cpp -o hello && ./hello`
- **VS Code / local IDE:** Use the Run/Build button or VS Code terminal commands listed above.
- **Windows note:** If using MinGW, run `hello.exe`; on macOS/Linux (and Codespaces), run `./hello`.

---

## GitHub workflow (web start → Codespaces run)

1. Create repo `` (Public).
2. **Web editor:** Add `main.cpp` → paste starter → **Commit changes** (`feat: initial program`).
3. **Run in Codespaces:** Click **Code ▾ → Create codespace on main** → open **Terminal** → run `g++ main.cpp -o hello && ./hello` (Linux environment).
   - Prefer local? You can compile locally instead (see **Build & run** above).
4. Improve the output formatting or add one more line.
5. Commit again from Codespaces Source Control (or the web editor): `feat: add extra line` or `style: tidy output`.

> **Goal:** At least **2 commits** for this assignment.

---

## Deliverables

- **URL** to your `csc134-hello-profile` repository with `main.cpp` that compiles and runs.

## Rubric (20 pts)

- (4) Compiles and runs without errors.
- (4) Correct C++ skeleton (`#include <iostream>`, `int main()`, `return 0;`).
- (4) Prompts and reads input using `cin`.
- (4) Prints multi-line output using `cout` and `endl`.
- (4) GitHub repo present; at least two commits with sensible messages.

## Common issues

- Missing `#include <iostream>` → `cout`/`cin` won’t compile.
- Forgetting `return 0;` at the end of `main()`.
- Accidentally typing input answers on the same line as prompts in some IDEs—watch the terminal cursor.
- If your name has spaces, `cin >>` stops at the first space. (Use `getline` in a later assignment.)

---

## Instructor Notes (quick)

- Demo the web-only GitHub workflow live: **Edit → message → Commit**. Repeat twice.
- Call out commit message style: small, **verb-first** (e.g., `docs: add interests`, `feat: initial program`).
- Run the C++ program once with typical input, once with edge-ish input (e.g., age `0`) to show behavior.
- Encourage students to paste their repo URLs into a class discussion thread for peer viewing and light feedback.

---

## Instructor One‑Slide Demo Checklist (Day 1)

*(Paste these onto one slide; use during live demo. Emoji = visual anchors.)*

### A) 🌐 Web Editor → ☁️ Codespaces (simple start)

1. 🌐 **New repo:** `csc134-hello-profile` (Public).
2. 📝 **Add file:** `main.cpp` → paste starter.
3. 💬 **Commit:** `feat: initial program`.
4. ☁️ **Open Codespace:** **Code ▾ → Create codespace on main**.
5. ⌨️ **Run:** `g++ main.cpp -o hello && ./hello`.
6. ✏️ **Edit** one output line.
7. 💬 **Commit** again (Source Control) → 🔄 **Sync/Push** if prompted.
8. 🔗 **Copy repo URL** (show where students submit).

### B) ☁️ Codespaces only (cloud IDE)

1. 🌐 **New repo** → ☁️ **Create codespace on main**.
2. 📝 **Create **`` in Codespaces.
3. ⌨️ **Run** in Terminal.
4. 💬 **Commit** (Source Control) → 🔄 **Sync/Push**.
5. 🔗 **Repo URL** for submission.

### C) 🖥️ Local VS Code + Git

1. 🧰 **Compiler installed:** Xcode CLT / MinGW‑w64 / GCC.
2. ⬇️ **Clone** repo in VS Code (or GitHub Desktop).
3. 📝 **Add **``, save.
4. ⌨️ **Build/Run:** `g++ main.cpp -o hello && ./hello` (Win: `hello.exe`).
5. 💬 **Commit → Push**.
6. 🔗 **Repo URL** for submission.

### Pitfalls to call out (90s-style lightning round)

- ❌ *Save ≠ Commit*: every change needs a commit message.
- 🧩 Missing `#include <iostream>` or forgotten `return 0;`.
- ⏎ `cin` stops at spaces (full names need `getline` in later labs).
- 🔄 In Codespaces, **Sync/Push** after committing.

### Suggested pacing (5–6 minutes total)

- A) Web→Codespaces: **\~2 min**
- B) Codespaces only: **\~2 min**
- C) Local VS Code: **\~1–2 min**

