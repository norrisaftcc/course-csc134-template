# Loops — The Two-Skin Exemplar (Phase D)

*Proof-of-concept. One concept, written once, worn as two skins. If this reads clean in both languages, the whole procedural core (selection → iteration → decomposition) is validated for shared authoring.*

**Seed:** CSC 134 `M5LAB_A` Exercise 2 ("Level Up Stats"), refactored into the shared format. Sibling on the Python side: CTI 110 M5 (loops). This is a refactor of material you already have, not a new invention.

---

## The concept (language-independent)

**Counted iteration:** *do a known number of reps; each rep, compute something from the count.* The count-based loop is the sharpest place to show two skins, because the surface differs the most while the idea stays identical — and because the difference traces to real design decisions, not arbitrary rules.

Student-facing one-liner (10th-grade target): **"A `for` loop does something a set number of times, and it knows which rep it's on."**

---

## Delivery: PRIMM, both courses

The same five beats run in both languages. The first three (Predict → Run → Investigate) work in Runestone C++ ActiveCode *and* any Python sandbox, because this program takes no input — which is exactly why it's the right seed given Runestone's no-`cin` limitation. Interactive work waits for the Make beat in Codespaces.

| Beat | What the student does |
|---|---|
| **Learn** | See iteration before reading it — the turtle square (below) |
| **Predict** | Read the working program, predict the first two table rows *before* running |
| **Run** | Run it as-is; check the prediction |
| **Investigate** | Change the count to 5, predict, run; change a formula, predict, run |
| **Modify** | Add a stat column; extend the range; reskin the theme |
| **Make** | The tiered assignment (C / B / A / Badge) |

---

## Beat 1 — Learn: the turtle (identical in both courses)

Iteration seen before it's written. A square is four identical moves; watching the turtle repeat *shows* the loop before any syntax.

```python
import turtle
t = turtle.Turtle()
for side in range(4):      # four reps
    t.forward(100)         # the body: what repeats
    t.right(90)            # the body
```

Name the two parts here and they pay off in every loop, any language: the **body** (what repeats) and the **count** (how many reps). We borrow Python's instant visual feedback to teach the *idea* — then implement it where the machine detail shows. In CSC 134 this is a demo/bridge; in CTI 110 it's home turf.

---

## Beat 2 — Read: the same program, two skins

Level 1 through 10; each level, compute three stats from the level number; print an aligned table. Same output, both skins.

**Python skin (CTI 110 home / CSC 134 bridge):**
```python
print("LVL   STR   DEX   INT")
for level in range(1, 11):
    strength     = 10 + level * 2
    dexterity    =  8 + level * 3
    intelligence = 12 + level * 1
    print(f"{level:>3}{strength:>6}{dexterity:>6}{intelligence:>6}")
```

**C++ skin (CSC 134 home / CTI 110 glance):**
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "LVL   STR   DEX   INT\n";
    for (int level = 1; level <= 10; level++) {
        int strength     = 10 + level * 2;
        int dexterity    =  8 + level * 3;
        int intelligence = 12 + level * 1;
        cout << setw(3) << level
             << setw(6) << strength
             << setw(6) << dexterity
             << setw(6) << intelligence << "\n";
    }
    return 0;
}
```

### How they differ — and why (the marquee annotations)

**1. The loop header.** Python's `range(1, 11)` hides the machinery; C++'s `for (int level = 1; level <= 10; level++)` states it out loud — start, condition, update.

| | Python | C++ |
|---|---|---|
| where the count starts | inside `range` | `int level = 1` |
| the keep-going test | inside `range` | `level <= 10` |
| how it advances | inside `range` | `level++` |

Neither is wrong. C++ makes you name the three moving parts because it wants you close to what the machine does; Python folds them into `range` because it wants you close to what you *mean*. That's the whole comparative lesson in one sentence.

> **Name once, use forever:** `range(1, 11)` yields 1…10 — the stop value is *excluded* (half-open). This is a deliberate, widely-shared convention, not a quirk, and its arithmetic advantages show up all term. The C++ mirror is the `<= 10` vs `< 11` choice — same fencepost, stated differently.

**2. Blocks: indentation vs. braces.** Python's indentation *is* the loop body; C++'s `{ }` is, and its indentation is decoration the compiler ignores. This isn't aesthetics — it's lineage. C++ inherited braces through C (BCPL → B → C), and C compatibility was a hard, non-negotiable design constraint when C++ was built, so the braces stayed. Python's designer treated re-encoding structure in *both* indentation and braces as redundant (they can disagree, which is a bug source), and made the whitespace itself the syntax, drawing on the older ABC language and the "off-side rule." *(Full version lives in the Iteration Bridge doc; a one-paragraph callout is enough here.)*

**3. Formatting the table.** C++ needs `<iomanip>` and `setw(n)`; Python uses an f-string with `:>6`. Both are "make this column *n* wide," different ergonomics. Worth showing side by side so students see that "print a neat table" is a solved problem in both, reached by different tools.

> **The typed-skin bonus (optional aside):** every stat here is an `int` in both. The moment you divide — say, an *average* stat — the skins teach something: C++ `int / int` truncates (a silent **logic** error), while Python `/` promotes to float. The compiled, typed skin surfaces the question earlier and louder. A good place to preview the error taxonomy.

---

## Beat 3–4 — Investigate & Modify (predict-then-run)

Small, fast changes; predict the output *before* each run (this is the verification muscle):

- Change `10` / `<= 10` to `5`. How many rows now?
- Change a formula (`level * 3` → `level * 4`). Which column moves?
- **Modify:** add a `luck = 5 + level` column; extend to level 20; reskin (sci-fi ranks, fitness weeks, coffee-shop day counter — theme is free, the loop is fixed).

---

## Beat 5 — Make: the tiered assignment

Student-facing, 10th-grade target. RPG theme by default; reskin allowed. AI use allowed with prompts saved to `prompts.md`.

**Scenario.** Show how a character's stats grow as they level up. Print a clean table.

| Tier | What it takes |
|---|---|
| **C — core** | A `for` loop, levels 1→10, three stats computed from the level, printed as an aligned table, plus a "total growth" line at the end. |
| **B — depth** | Add a second concept: ask the player for their *start* and *end* level, and **validate the input** (reject non-numbers and bad ranges) before looping. *(This is the beat that needs real input — Codespaces, not Runestone.)* |
| **A — synthesis** | Nested loops: print the growth table for **two** character classes side by side (or loop the level-up until a stat crosses a target, mixing `for` with `while`). |
| **Badge — above & beyond** | `prompts.md` with your AI prompts, **plus** a short reflection: where did you use `for` vs `while`, and why? Or hand-trace one column in a trace table and include the photo. |

### Shared rubric (from the Robot Sandwich template)

The four columns are the same ones the Robot Sandwich established, adapted from prose to code — one rubric shape across the whole program.

| Criterion | Points | What we're looking for |
|---|---|---|
| **Correctness** | 8 | The loop runs the right number of times; stats compute correctly; no off-by-one |
| **Completeness** | 6 | Every required part present for the tier attempted; edge cases handled (B: bad input; A: both loops) |
| **Format** | 3 | Table aligns; code is readable and commented. **C++: compiles clean under `-Wall -Wextra`** |
| **Submission** | 3 | Right file name, folder, repo, committed; `prompts.md` present if AI was used |

No hidden criteria; what's on the page is the whole rubric. (Matches the Robot Sandwich promise and the program's "no trick questions" standard.)

---

## The compiler/interpreter beat, made concrete here

Same off-by-one — `range(1, 10)` or `< 10` when you meant ten reps — is a **logic error** in *both* skins: it runs fine and quietly prints nine rows. But a slip like forgetting `<iomanip>`, or a stray type mistake, is caught at **C++ build time** (the program never runs), while its Python cousin often waits until the line *executes*. Same taxonomy, different phase — the one deliberate Practice-spine divergence, landing on a loop the student already understands.

---

## For the instructor — how this maps

- **CSC 134:** this is `M5LAB_A` Exercise 2 refactored — same formulas (`STR = 10 + 2·lvl`, `DEX = 8 + 3·lvl`, `INT = 12 + 1·lvl`), same RPG theme, now carrying the PRIMM beats and the two-skin annotations. Exercises 1 (while / health regen) and 3 (array search) refactor the same way.
- **CTI 110:** slots into M5 (loops) as the home-language version; the C++ skin becomes a two-minute "look how the other track writes the same idea" glance, not a second language to learn.
- **Delivery standards applied:** 10th-grade prompt copy, no hidden rubric, clean-compile bar for the C++ tier, exit-ticket-able (the Predict/Run/Investigate beats are natural low-stakes checks).

---

## What this validates / open items

If this reads clean in both languages — and it should — then the two-skin authoring model is proven for the entire Phase-D procedural core, and only the back-third divergences (Phase E data/OOP, Phase F synthesis) remain as genuinely course-specific work.

Two small things to confirm on review:
1. **How literal is the C++ "glance" in CTI 110?** A shown-and-explained snippet, or just named in passing? (Ties to open decision #6 on how many cross-language bridges we build.)
2. **Whether the turtle Learn beat is required or optional in CSC 134.** It's a genuine time cost in a compiled course; worth deciding on purpose rather than by default.
