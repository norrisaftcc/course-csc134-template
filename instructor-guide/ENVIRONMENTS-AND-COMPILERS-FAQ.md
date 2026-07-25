```
   ____ ____   ____       _ _____  _  _
  / ___/ ___| / ___|     / |___ / | || |
 | |   \___ \| |   _____ | | |_ \ | || |_
 | |___ ___) | |__|_____|| |___) ||__   _|
  \____|____/ \____|     |_|____/    |_|

  E N V I R O N M E N T S   &   C O M P I L E R S
  ~ The Behind-the-Screen FAQ ~

  Platform : Ubuntu / Codespaces / macOS / GitHub Actions / Canvas
  For      : Instructors and developers. NOT student-facing.
  Version  : 1.0
  Updated  : 2026-07-25
```

```
===============================================================================
  0. BEFORE YOU START
===============================================================================
```

This is the doc for **you**, not the students. It explains which compiler runs
where, why that turned out to matter enormously, and which knobs you can turn
without asking anyone.

Everything here is already written down somewhere in `_lore/`. This just puts it
in one place, in an order that makes sense if you are trying to get productive
rather than trying to audit a decision.

**Use Ctrl+F with the bracket codes.** That is what they are for.

```
===============================================================================
  TABLE OF CONTENTS
===============================================================================

  [1.0] .... THE ONE THING TO KNOW
  [2.0] .... THE COMPILER PROBLEM
          [2.1] .. What actually happened
          [2.2] .. Why gcc and clang disagree
          [2.3] .. The damage
  [3.0] .... THE FOUR ENVIRONMENTS
          [3.1] .. Your Mac
          [3.2] .. Codespaces
          [3.3] .. GitHub Actions (CI)
          [3.4] .. Canvas
  [4.0] .... THE DIALS
          [4.1] .. Compile gate dials
          [4.2] .. Canvas compositor dials
  [5.0] .... HOW DO I ... (walkthroughs)
  [6.0] .... KNOWN BUGS / CURRENT STATUS
  [7.0] .... FREQUENTLY ASKED
  [8.0] .... GLOSSARY OF OUR OWN JARGON
  [9.0] .... VERSION HISTORY
```

```
===============================================================================
  [1.0] THE ONE THING TO KNOW
===============================================================================
```

> **On your Mac, `g++` is not GCC. It is Apple clang wearing a `g++` costume.**
>
> Your students use GCC. The two do not agree about what `-Wextra` means.

If you remember nothing else, remember that. It cost us a bug inside a module
we had already certified as Ready.

The fix is already in place — CI compiles on Ubuntu now — so you do not have to
think about it day to day. But when you are about to write the words *"this
compiles clean"* in something a student will read, that is the moment to stop
and check where you ran it.

```
===============================================================================
  [2.0] THE COMPILER PROBLEM
===============================================================================
```

--------------------------------------------------------------------------
  [2.1] What actually happened
--------------------------------------------------------------------------

M4's material tells students to break a program on purpose — delete a `break;`
from a `switch` — and promises the program will **compile with zero warnings**
and misbehave silently. The whole lesson is *a clean compile is not proof of a
correct program.*

Someone went to verify that claim before publishing it to Canvas. On a Mac, it
held. On GCC, it did not:

```
warning: this statement may fall through [-Wimplicit-fallthrough=]
```

Then a second, worse one turned up. The dangling-`else` demo also claims to
compile clean. **That one warns on both compilers** — it was wrong even on the
machine it was written on.

--------------------------------------------------------------------------
  [2.2] Why gcc and clang disagree
--------------------------------------------------------------------------

Both accept `-Wall -Wextra`. They do not mean the same thing by it.

```
  FLAG                          GCC         Apple clang
  ---------------------------------------------------------------
  -Wall alone                   silent      silent
  -Wextra alone                 WARNS       silent
  -Wall -Wextra (ours)          WARNS       silent
  with "// falls through"       silent      silent
```

GCC has bundled `-Wimplicit-fallthrough` into `-Wextra` since **version 7**.
Clang has the warning but does not switch it on under either flag; you have to
ask for it by name.

That is the entire story. One flag, two opinions, and our material was written
against the quieter opinion.

Confirmed on three compilers, including a live Codespace:

```
  Apple clang 21.0.0        fall-through: silent     dangling else: WARNS
  GNU g++ 16.1.0 (brew)     fall-through: WARNS      dangling else: WARNS
  Ubuntu g++ 13.3.0 (CS)    fall-through: WARNS      dangling else: WARNS
```

No version quirk — GCC behaves the same from 13 through 16.

--------------------------------------------------------------------------
  [2.3] The damage
--------------------------------------------------------------------------

```
  * modules/m4/learn.md ............... Trap 2 says "no warning at all"
  * modules/m4/apply-tutorial.md ...... Deliberate Break says "zero warnings"
  * modules/m4/apply-tutorial.md ...... Break B says "It compiles clean"
  * modules/m4/code/practice-item5-fallthrough.cpp .... SHIPPED CODE, warns
```

That last one is not prose. It is a real file behind an exit-ticket item, and a
student compiling it in Codespaces gets a warning — which, under our own
zero-warning rule, means **their build failed**.

Why it matters more than a typo: the zero-warning rule says a warning *is* a
failed build. So on GCC the demo stops teaching *"clean compile, wrong
behaviour"* and starts teaching *"your build failed"* — the exact opposite
lesson, in the one course moment where we promised the compiler would stay quiet.

Tracked in issue **#25**. Full write-up: `_lore/findings/F-009-*.md`.

```
===============================================================================
  [3.0] THE FOUR ENVIRONMENTS
===============================================================================
```

--------------------------------------------------------------------------
  [3.1] Your Mac — authoring
--------------------------------------------------------------------------

```
  Compiler   : Apple clang (pretending to be g++)
  Trust it   : for "does this compile at all?"
  Do NOT     : claim compiler SILENCE from a result here
```

Quoting a warning you saw is safe. Promising there wasn't one is not.

Want a truthful local check? Install real GCC once:

```
  brew install gcc
  CXX=g++-16 bash .github/scripts/compile-gate.sh
```

It installs *alongside* clang. Your default `g++` does not change. Undo with
`brew uninstall gcc`.

--------------------------------------------------------------------------
  [3.2] Codespaces — where students live
--------------------------------------------------------------------------

```
  Compiler   : GNU g++ 13.3.0 (Ubuntu 24.04)
  Trust it   : completely. This IS the student experience.
```

The most honest place to test anything. If you only ever check one environment,
check this one. It is also the answer to "works on my machine" — it is nobody's
machine, which is the point.

--------------------------------------------------------------------------
  [3.3] GitHub Actions — the referee
--------------------------------------------------------------------------

```
  Compiler   : GNU g++ on ubuntu-latest
  Runs on    : every push to main, every PR, on demand
  Authority  : THIS ONE. CI is the ruling, not your laptop.
```

Deliberately **not** a build matrix. No macOS lane, no clang lane. A green clang
lane sitting next to a red GCC lane invites *"well, it passes somewhere"* — and
the course has exactly one target environment.

The gate **self-tests before it runs**. It first compiles a file guaranteed to
warn and confirms it fails. If that check ever passes, the build stops and tells
you every green run since is unverified.

That step exists because the very first version of this workflow **passed while
printing the bug**. A GitHub expression quirk (`null == false` is *true*) meant
enforcement was off on exactly the events that mattered. A gate that cannot fail
is not a gate — so now it proves it can, every single run.

Decision record: `_lore/decisions/ADR-014-*.md`.

--------------------------------------------------------------------------
  [3.4] Canvas — the delivery surface
--------------------------------------------------------------------------

```
  Renders    : sanitized HTML fragments, inline styles only
  Forbidden  : <style> <script> <svg> <details> class= fixed px widths
  Mermaid    : DOES NOT RENDER. It is JavaScript.
```

Canvas silently destroys what it does not like. Not an error — *silently*. So
composed pages go through their own gate before they are pasted anywhere.

Consequences you will actually notice:

```
  * Flowcharts become box-drawing characters, or an uploaded SVG.
  * Tables are capped at TWO columns (a 3-col table at 375px is a scrollbar
    with data in it).
  * No spoiler widget exists, so predict/reveal is prose plus a hairline rule.
  * Links are emitted as loud [LINK PENDING] placeholders and wired by hand in
    Canvas — because Canvas only relinks references inserted through its own
    editor when a course is copied to a new term.
```

Composed pages live in `_outputs/`. **They are build output.** Never hand-edit
one; edit the Markdown and re-emit. A hand-edit survives just long enough to be
believed, then vanishes on the next build.

```
===============================================================================
  [4.0] THE DIALS
===============================================================================
```

Everything below is designed to be turned. Nothing here requires editing a
workflow file.

--------------------------------------------------------------------------
  [4.1] Compile gate dials
--------------------------------------------------------------------------

Locally, as environment variables:

```
  bash .github/scripts/compile-gate.sh          # just run it

  CXX=g++-16 bash ...                # which compiler
  CXX_STD=c++17 bash ...             # language standard
  WARN_FLAGS="-Wall -Wextra" bash ...# the warning set
  FAIL_ON_WARNING=0 bash ...         # report but do not fail
  SEARCH_PATHS="modules/m4" bash ... # gate one module only
  VERBOSE=1 bash ...                 # print every diagnostic line
```

In CI: **Actions → Compile gate → Run workflow**. Three of them are exposed as
form fields (compiler, search paths, fail-on-warning).

```
  ,-----------------------------------------------------------.
  | WHEN YOU WOULD ACTUALLY TURN ONE                          |
  |-----------------------------------------------------------|
  | FAIL_ON_WARNING=0 | Surveying damage across many files.   |
  |                   | You want the whole list, not the      |
  |                   | first failure. Never the default.     |
  |-----------------------------------------------------------|
  | SEARCH_PATHS      | Working on one module and tired of    |
  |                   | waiting for all of them.              |
  |-----------------------------------------------------------|
  | CXX               | Reproducing a student's report, or    |
  |                   | checking whether a warning is         |
  |                   | compiler-specific.                    |
  `-----------------------------------------------------------'
```

--------------------------------------------------------------------------
  [4.2] Canvas compositor dials
--------------------------------------------------------------------------

The compositor is a skill, not a script — you drive it in conversation. Its two
mechanical settings:

```
  The dial     : one comment at the top of the source, e.g.
                 <!-- compositor: M4 · assess -->
                 Module number picks which diagram notation is allowed.
                 LPAA beat picks how much scaffolding devices carry.

  The gate     : python3 .claude/skills/csc134-canvas-compositor/gate.py \
                     _outputs/canvas-html
                 Add --reference for imported material that predates our
                 provenance and freeze rules.
```

The gate checks sanitizer rules, unescaped `<` and `>` inside `<pre>`, table
column ceilings, character-diagram box-width shear, placeholder accounting,
breakout budgets, the one-caution rule, and provenance headers.

```
===============================================================================
  [5.0] HOW DO I ...
===============================================================================
```

**... check whether the course code compiles, for real?**

```
  bash .github/scripts/compile-gate.sh
```

On a Mac that runs clang, so it answers "does it build" but not "is it clean for
students." For the real answer, push and read CI, or `CXX=g++-16` with brew GCC.

**... test a claim about compiler behaviour before I publish it?**

Open a Codespace and run it there. That is the student environment; anything
else is an approximation. There is a copy-paste runbook at
`_lore/findings/F-009-verification-procedure.md` — written so it can be handed
to someone with no context on the repo.

**... check a composed Canvas page before pasting it?**

```
  python3 .claude/skills/csc134-canvas-compositor/gate.py _outputs/canvas-html
```

**... regenerate a Canvas page after editing the source?**

Ask for it to be re-composed from the Markdown. Do not edit the HTML. The file
says so in its own header comment, twice, because this is the mistake everyone
makes once.

**... find out why something is the way it is?**

```
  _lore/decisions/   ADRs — decisions and their reasoning
  _lore/findings/    Findings — what broke, what was measured
  CLAUDE.md          The invariants, in brief
```

ADRs record *pocketed options* too — ideas considered and deliberately not
taken, with why. If you are about to propose something, check whether it is
already sitting in a pocket with a reason attached.

```
===============================================================================
  [6.0] KNOWN BUGS / CURRENT STATUS
===============================================================================
```

```
  ISSUE  WHAT                                             STATE
  -----------------------------------------------------------------------
  #25    M4 "compiles clean" claims are false             OPEN, fix chosen
         + practice-item5-fallthrough.cpp warns on GCC
  #23    Haiku AI persona — canon or not?                 OPEN, awaiting
                                                          ADR-013 ruling
  #19    Mini-textbook / course pack                      PINNED, unscoped
```

**The recommended #25 fix**, already tested on all three compilers: swap the
deliberate break for a **mis-ordered `if` chain** — put the `>= 40` test above
the `>= 70` test so the top branch can never run. It is silent on every compiler
tested, it genuinely misbehaves (strength 85 prints the *Borderline* riddle), it
is a Logic error by our own four-word taxonomy, and M4 already teaches "highest
bar first" — so it reinforces the module instead of adding an idea.

**Expect `main` to be red** once the CI PR merges, until #25 lands. That is
correct. Red CI telling the truth beats green CI that is lying, and an allowlist
would have encoded the bug as acceptable on the day we found it.

```
===============================================================================
  [7.0] FREQUENTLY ASKED
===============================================================================
```

**Q: Do I need to install GCC on my Mac?**

No. CI covers it. Install it if you want fast truthful local checks and dislike
waiting on a push — `brew install gcc`, then `CXX=g++-16`. It sits alongside
clang and changes nothing else.

**Q: Why are we so strict about warnings? Students hate that.**

Because a warning is where the compiler tries to save you and most beginners
learn to scroll past it. One warning fails the Format column at any tier — but
it is explicitly a fix-and-resubmit conversation, not a penalty one. The point is
the habit, not the points.

And the strictness paid off in an unexpected direction: it is exactly *why* the
fall-through demo broke. Our flags are good enough that they caught the bug we
were relying on them to miss.

**Q: Why does Mermaid work on GitHub but not Canvas?**

GitHub renders Mermaid natively. Canvas strips `<script>`, and Mermaid is
JavaScript. So on Canvas a flowchart becomes box-drawing characters (which
students can redraw on paper — a real upside) or an uploaded SVG.

**Q: Can I just fix the HTML in Canvas? It's one word.**

It will be gone on the next build, and Canvas reformats markup on save anyway.
The one sanctioned in-Canvas edit is wiring `[LINK PENDING]` placeholders, which
is why those are made deliberately loud.

**Q: Something says "green" and I do not believe it.**

Correct instinct. Check *what* was green: which compiler, which paths, and
whether enforcement was on. The gate prints all three at the top of every run
precisely so that question is answerable without asking anyone. This is not
paranoia — the first CI run here was green while printing a real bug.

**Q: Where do composed Canvas pages go?**

`_outputs/`. Build output, committed so formatting churn shows in diffs, never
ground truth. The Markdown in `modules/` is always the source of truth.

**Q: What is an ADR and do I have to write one?**

Architecture Decision Record — a numbered note saying what was decided and why.
No PR merges without a lore entry: an ADR, a finding, or a glossary change. If
you are making a call someone will later wonder about, write the ADR. If the
call is not yours to make, record it as an open question — but **do not claim a
number** when numbering is contested.

```
===============================================================================
  [8.0] GLOSSARY OF OUR OWN JARGON
===============================================================================
```

```
  LPAA ............. Learn, Practice, Apply, Assess. The four beats every
                     module has.
  The Make gradient  How much scaffolding an Apply beat gives:
                     M2-M4 type it all in, M5-M7 finish the last 20%,
                     M8 spec only.
  Four-word taxonomy The only names for errors: Syntax, Static semantic,
                     Runtime, Logic. No synonyms.
  Four columns ..... Correctness / Completeness / Format / Submission.
                     Every rubric. No new columns, no hidden criteria.
  C / B / A / Badge  Tiers of ambition. C is the objective met, NOT
                     partial credit. Badge is documentation, never more code.
  The dial ......... The compositor comment naming module + beat.
  Breakout ......... A boxed thing on a Canvas page. Three to five per page.
  Skin vs structure  The dungeon theme must peel off without breaking the
                     exercise. If it does not, that is a bug.
  Pocketed option .. An idea considered and deliberately not taken, kept in
                     the ADR with reasons so nobody re-derives it.
  The lore gate .... No PR merges without a decision, finding, or glossary
                     entry.
```

```
===============================================================================
  [9.0] VERSION HISTORY
===============================================================================

  1.0  2026-07-25  First version. Written after the GCC/clang divergence
                   (F-009) turned a one-line fact-check into a compile gate,
                   a CI pipeline, and two bug tickets.

===============================================================================
  Sources, all in-repo:
    _lore/findings/F-009-fallthrough-warning-claim-is-toolchain-dependent.md
    _lore/findings/F-009-verification-procedure.md
    _lore/findings/F-008-canvas-compositor-import.md
    _lore/decisions/ADR-012-canvas-compositor-enters-alpha-scope.md
    _lore/decisions/ADR-014-compile-gate-runs-on-gcc-in-ci.md
    CLAUDE.md
===============================================================================
```
