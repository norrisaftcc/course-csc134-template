# M3LAB2 Taco Receipt — Instructor Guide

**Position:** M3 Assess, second data point alongside the Pizza Calculator. Where Pizza teaches *input → process → output works*, Taco teaches *the output was never the value*. Together they're the N-shot pair for M3-tier assignments: one straight application, one with a conceptual payload.

**The payload:** representation ≠ display. First planted here, cashed in three more times: M5 (trace tables predict *values*, not printouts), M7 (int cents vs double dollars is a representation *choice*), and the AI ladder (an LLM's confident prose is also a display — you verify the value underneath).

## Verified facts (all from real runs, g++ -std=c++17 -Wall -Wextra, zero warnings)

| Fact | Value |
|---|---|
| C-tier sample (3,2,1,2) | subtotal 25.50, tax 1.79, total 27.29 — adds up cleanly |
| Penny Mystery order (5,0,1,2) | subtotal **24.50**, tax displays **1.72**, total line math is off by 1¢ without tip: 24.50 + 1.72 = 26.22 vs total 26.21 |
| Tax raw value | `1.71500000000000008` → displays 1.72 (rounds up) |
| Tip raw value (15% of 24.50) | `3.67499999999999982` → displays **3.67** (rounds DOWN — schoolbook says 3.68) |
| Reference solutions | `m3lab2_taco_c.cpp` (C tier), `m3lab2_taco_a.cpp` (A tier), both compile clean |

The tip is the star exhibit: students *know* .675 rounds to .68. The machine disagrees, and the machine is right about what it's holding — 3.674999… rounds to 3.67. Nobody is lying; they're describing different numbers.

## The talk track (10 minutes, three beats)

1. **The zero that never was.** `double price = 3.50; cout << price;` prints `3.5`. Ask: where did the zero go? Let them sit in it. Answer: it was never there. The variable holds a *value* (three and a half); "3.50" was just how they wrote it down. Digits in, value stored, digits out — and the out-digits are a choice.
2. **Display is paint.** `fixed << setprecision(2)` doesn't change the variable; it changes the picture. Print the same variable twice with different manipulators — one variable, two displays. This is the entire `<iomanip>` unit in one demo.
3. **The Penny Mystery.** Run the 5-0-1-2 order live. The receipt disagrees with itself by a penny and the X-ray shows why: most decimal prices can't be stored exactly in binary, so every stored price is the *nearest representable value* — a hair high or a hair low — and rounding the pictures line-by-line doesn't always match rounding the sum. Close with: "real registers do money in integer cents. You'll be able to build that by M7."

## Tier calibration

- **C shortfall patterns:** literals repeated instead of constants (Format); `setprecision(2)` without `fixed` (the "$27" bug — worth a public autopsy, it's the lesson in bug form); name prompt after numeric input (skipped `getline`).
- **B:** the honest work is `setw` fiddling. Accept any alignment that is *actually aligned*; don't grade column widths. Watch for tip computed on post-tax total — spec says subtotal, and the spec wins (that's a Correctness miss, not a style choice).
- **A:** the comment answer must say, in some form, (a) the X-ray is closer to the stored value, and (b) the receipt is a rounded display of it. Bonus language like "nearest binary fraction" is above the bar, not the bar. An answer that says "the computer made a rounding error" is a miss — the display rounded, the computer did exactly what it was told.
- **Badge:** the PENNY_REPORT should reach "integer cents" or "don't store money in floating point" by any wording. A student who finds a real receipt that *doesn't* add up gets folklore status.

## Predicted cohort findings (pre-registered)

Filed before any cohort run, so the cohort audits our guesses too:
1. Jaylen skims past `fixed`, gets `$27`, burns his two fixes on the wrong lines.
2. Maria completes cleanly *if* prompt order is followed; if any draft moves `getline` after `cin >>`, she stops exactly there. (Which is the point of the spec note.)
3. Dee tests "tip on subtotal, before tax" — we pinned it — and probed negative quantities. **Ruled (ADR-002):** the spec pins quantities to zero-or-more; negative input is out of spec and ungraded at M3, *and the lab says so out loud* ("The Negative Taco Problem" section) rather than hiding the hole. No trick questions includes no silent holes.

**The class moment (don't waste it):** if a student asks the negative-taco question live, that's the best question of the week — say so, then deliver the ruling in the house voice: *"No — the register will not pay you for the privilege of giving you negative three tacos. The exit code of that request is not zero."* Then cash the joke: point at the `return 0;` they've been typing since M0, explain zero-means-success / nonzero-means-refused, and promise them that in M4 they personally get to install the bouncer. The gag is a load-bearing forward reference: same receipt, M4, first `if` statement is `if (qtyPastor < 0)`.

## Re-skin check

Theme strips clean: four products, a tax rate, a gratuity — works as bookstore, potion shop (dungeon canon), or coffee cart by editing nouns and prices only. If a re-skin changes any requirement, that's a defect in the lab, not the skin. Note: prices must stay non-representable decimals (avoid .00/.25/.50 across the board) or the X-ray goes boring — flag this in any re-skin PR.

## Forward seams

- **M5:** the `cin` fail-state test case ("type `three`") is planted here unresolved on purpose; M5's validation unit pays it off.
- **M6:** this program is a designated refactor candidate (four near-identical line-item blocks are *begging* for a function).
- **M7:** the menu is four parallel somethings — it becomes the `MenuItem` struct-array example, and integer-cents lands as the representation-choice payoff.
