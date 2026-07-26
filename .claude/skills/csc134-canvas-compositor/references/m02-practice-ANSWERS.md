# M2 Practice — Error Taxonomy Exit Ticket · Answer Key

**Instructor only.** Do not paste into Canvas.

Every specimen below was compiled and run under `g++ -std=c++17 -Wall -Wextra` (GCC, Ubuntu).
The messages and outputs in the stems are verbatim, not paraphrased.

---

## Q1 — **Syntax**

Missing semicolon after `int score = 88` on line 6.

**Why not static semantic:** the compiler never got as far as meaning. It could not parse the
token stream, which is what "broke the grammar" describes.

**Worth mentioning in review:** the error is reported on **line 7**, not line 6 where the
semicolon is missing. The compiler reports where it *noticed*, not where you erred. This is
the single most useful thing a beginner can learn about reading compiler output, and it is why
the escalation path says *read the first error carefully* rather than *go to the line number*.
If you only debrief one item, debrief this one.

## Q2 — **Static semantic**

`int score = "eighty-eight";` — assigning a string literal to an `int`.

**Why not syntax:** the line is grammatically perfect. Declaration, name, assignment,
expression, semicolon. The compiler parsed it completely and then refused it, because there is
no meaning to be had: `const char*` does not convert to `int`. Grammar fine, meaning
impossible.

**Anticipated student objection, and it's a fair one:** "both Q1 and Q2 are compiler errors, so
how is this two categories?" Correct answer: because the fix is a different kind of thinking.
Q1 you fix by looking at punctuation. Q2 you fix by reconsidering what you meant. The
taxonomy sorts errors by *what you have to do about them*, not by when they surface.

## Q3 — **Runtime**

Integer division by zero. Built clean, started, printed both prompts, then died on
`total / players` with `players` at 0.

**Why not logic:** it did not produce a wrong answer. It produced no answer. The process was
terminated (`SIGFPE`, exit code 136).

**Why the compiler couldn't help:** the divisor arrives from `cin` at runtime, so there is
nothing to check at compile time. Had the code said `total / 0` literally, `-Wall` would have
warned — which is a good five-second aside if someone asks.

**This is the input-validation hook.** The program is correct for every input except one, and
nothing in the language protects it. Point forward to it.

## Q4 — **Logic**

Operator precedence: `first + second / 2` divides before it adds, giving 10 + 10 = 20 instead
of (10 + 20) / 2 = 15. Fix is `(first + second) / 2`.

**Why not static semantic:** every type is correct and every operation is meaningful. The
program does exactly what it says. What it says is not what was wanted.

**Why this one is the whole point of the taxonomy:** zero warnings, clean exit, plausible-
looking number. No tool on earth flags this. The only thing that catches it is a human who
knew what the answer should have been — which is the argument for testing against expected
values, and later the argument for why AI-generated code has to be verified rather than
trusted.

---

## Notes on fairness

Each specimen sits unambiguously in one category, and the description fragment supplies the
four definitions plus the sorting question (*did it build? did it finish? was the answer
right?*), so nothing here tests recall of a definition the student had to memorize.

The one place a student could reasonably hesitate is Q1 vs Q2, and that hesitation is the
learning objective rather than a flaw — see the objection under Q2. If more than a third of the
cohort misses Q2 specifically, the fix is a clearer beat in the reading, not an easier
question.
