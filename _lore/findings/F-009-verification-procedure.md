---
name: F-009-verification-procedure
description: Copy-paste Codespaces procedure to confirm the F-009 compiler-warning findings on the real student toolchain. Written for a hand-off; no prior context needed.
---

# F-009 — verification procedure (Codespaces)

**For whoever runs this:** you do not need to know anything about the rest of this repo. This is a
20-minute job. You will compile four tiny C++ files and write down whether the compiler complained.

**What we are checking.** Some CSC-134 course material tells students that a deliberately broken
program will compile **with no warnings**. We think that is wrong in the environment students
actually work in. It has already been confirmed wrong on two compilers on a Mac. This step confirms
it on **Codespaces**, which is what students use — and Codespaces ships a different, older compiler,
so it genuinely could behave differently.

**You cannot get this wrong by running it.** Nothing here modifies the repo. If a result surprises
you, that is useful information, not a mistake — write down what you actually saw.

---

## Step 1 — open a Codespace

From the repo page on github.com: **Code → Codespaces → Create codespace on main**. Wait for the
terminal to appear.

## Step 2 — record the compiler version

```bash
g++ --version
```

**Write down the first line.** It will say something like `g++ (Ubuntu 12.3.0-...) 12.3.0`. The
version number matters — it is the whole reason we are re-running this.

## Step 3 — create the four test files

Paste this whole block in at once. It only writes files to `/tmp`; it does not touch the repo.

```bash
mkdir -p /tmp/f009 && cd /tmp/f009

cat > 1-fallthrough.cpp <<'EOF'
#include <iostream>
using namespace std;
int main()
{
    int characterClass = 0;
    cout << "Your class? (1 = Warrior, 2 = Mage, 3 = Rogue): ";
    cin >> characterClass;
    switch (characterClass)
    {
        case 1:
            cout << "\"A Warrior. Strong arms, I hope.\"\n";
            // break;   <-- deliberately removed
        case 2:
            cout << "\"A Mage. A sharp mind, I hope.\"\n";
            break;
        default:
            cout << "\"I do not know that class. Off you go.\"\n";
    }
    return 0;
}
EOF

cat > 2-dangling-else.cpp <<'EOF'
#include <iostream>
using namespace std;
int main()
{
    int strength = 0;
    cout << "Your strength score (0-100): ";
    cin >> strength;
    // TEMPORARY — braces removed on purpose
    if (strength >= 40)
        if (strength >= 70)
            cout << "The gate swings wide.\n";
    else
        cout << "Turned away.\n";
    cout << "The visit ends.\n";
    return 0;
}
EOF

cat > 3-unreachable-branch.cpp <<'EOF'
#include <iostream>
using namespace std;
int main()
{
    int strength = 0;
    cout << "Your strength score (0-100): ";
    cin >> strength;
    // BUG on purpose: bars are in the wrong order, so >= 70 can never run
    if (strength >= 40)
    {
        cout << "Borderline. A riddle.\n";
    }
    else if (strength >= 70)
    {
        cout << "The gate swings wide.\n";
    }
    else
    {
        cout << "Turned away.\n";
    }
    return 0;
}
EOF

cat > 4-off-by-one.cpp <<'EOF'
#include <iostream>
using namespace std;
int main()
{
    int strength = 0;
    cout << "Your strength score (0-100): ";
    cin >> strength;
    // BUG on purpose: > instead of >=, so exactly 70 falls to the wrong branch
    if (strength > 70)
    {
        cout << "The gate swings wide.\n";
    }
    else
    {
        cout << "Turned away.\n";
    }
    return 0;
}
EOF

ls
```

## Step 4 — compile each one and record what happens

These are the **exact flags the course uses**. Do not change them — they are the point.

```bash
for f in 1-fallthrough 2-dangling-else 3-unreachable-branch 4-off-by-one; do
  echo "================ $f ================"
  g++ -std=c++17 -Wall -Wextra "$f.cpp" -o "/tmp/f009/$f"
  echo "--- (nothing between the lines above and here means NO warnings) ---"
done
```

## Step 5 — fill in this table and report it

Copy this into a comment on **issue #25**, filled in:

```
g++ --version first line:  ____________________________________

| File                   | Warned? | Warning name (the [-Wsomething] part) |
|------------------------|---------|---------------------------------------|
| 1-fallthrough          | yes/no  |                                       |
| 2-dangling-else        | yes/no  |                                       |
| 3-unreachable-branch   | yes/no  |                                       |
| 4-off-by-one           | yes/no  |                                       |
```

**What we expect**, so you know whether something odd happened — but **report what you see, not
what this table predicts**:

| File | Expected | Why we care |
|---|---|---|
| 1-fallthrough | **warns** (`-Wimplicit-fallthrough`) | Course material claims it is silent. If it warns, the material is wrong. |
| 2-dangling-else | **warns** (`-Wdangling-else`) | Same — material claims "compiles clean". |
| 3-unreachable-branch | **silent** | Candidate replacement demo. Only useful to us if it really is silent. |
| 4-off-by-one | **silent** | Second candidate replacement. Same reasoning. |

**Files 3 and 4 are the important ones.** Files 1 and 2 confirm a problem we already believe in.
Files 3 and 4 tell us whether the proposed *fix* works — and a previous fix proposal was already
withdrawn for exactly this reason, because it was assumed silent and turned out not to be.

## Step 6 — one optional extra, if you have five more minutes

Run the two broken programs and confirm they misbehave the way the material says:

```bash
echo 1 | /tmp/f009/1-fallthrough        # expect BOTH the Warrior and Mage lines
echo 50 | /tmp/f009/2-dangling-else     # expect "Turned away." — wrong for a score of 50
```

Note whether the output matches those expectations.

---

## If something goes wrong

- **`g++: command not found`** — try `g++-12`, or `sudo apt-get install -y g++`. Note which you used.
- **A file fails to compile with an *error* rather than a warning** — that is a real result. Paste
  the full error into the issue; do not try to fix the file.
- **Anything else** — paste the whole terminal output into issue #25 and stop. An unexplained result
  is worth more to us than a tidy one.

## Context, if you want it

Full write-up: `_lore/findings/F-009-fallthrough-warning-claim-is-toolchain-dependent.md`.
Short version: `-Wall -Wextra` do not mean the same thing on GCC and on Apple's clang, and material
that promises *the compiler will stay quiet* only holds on the compiler it was written against.
