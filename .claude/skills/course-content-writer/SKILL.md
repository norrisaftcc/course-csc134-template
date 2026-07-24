---
name: course-content-writer
description: "Apply CSC-134 voice, philosophy, and pedagogical approach to any content"
allowed-tools: "Read,Write,Glob,Grep"
---

# Course Content Writer

This skill establishes the foundational voice and approach for all CSC-134 content. It activates alongside other skills whenever student-facing or instructor-facing content is being created.

## When to Use This Skill

- Creating any student-facing content
- Reviewing content for voice consistency
- Adapting external materials to course style
- When asked about "how to write for this course"

## The CSC-134 Frame

### Core Tenet: "The Computer Is the Literal Robot"

Every bug is the gap between what you meant and what you said. C++ makes that gap visible — the compiler refuses ambiguity out loud, before anything runs. All content uses this:

1. **The compiler is a teaching asset**, not an obstacle. Error messages are read together, on purpose.
2. **Failure is exercise — put in the reps.** The first error in M3 is a planned, celebrated event. Mistakes are data, not character flaws.
3. **Comprehension precedes composition (PRIMM).** Students predict, read, and run working code before writing their own.
4. **Precision is the skill.** Instructing the compiler and instructing an LLM are the same skill: spec-writing for a literal reader.

### Where Content Lives: the LPAA Loop

Every module runs Learn → Practice → Apply → Assess. Know which beat you are writing for, because the beat determines the format:

| Beat | Content type | PRIMM stage it carries |
|---|---|---|
| **Learn** | Reading or guide (predict-the-output moments built in) | Predict |
| **Practice** | Exit ticket — low-stakes, completion-gated | Run + Investigate |
| **Apply** | Instructor-led type-in tutorial (Make gradient applies) | Investigate → Modify → early Make |
| **Assess** | Lab/homework from requirements + spec | Make |

**The Make gradient** governs how much scaffolding Apply content provides: M2–M4 students type 100% of a working program; M5–M7 they receive 80% and finish a specified missing piece; M8 they get a spec and go. Never write M3 content that assumes M7 independence, and never scaffold M7 like M3.

### Audience

Roughly 75% college-transfer (future CS/engineering majors) and 25% programming-track AAS students. Preparation varies widely. Consequences:

- **10th-grade readability on all student-facing prose.** Complexity lives in the *problem*, never in the prose describing it.
- Foundations matter more than job-ready tricks — this audience will be examined on this material again at a four-year school.
- Pointers, filters, and OOP are real content here, not footnotes. Do not dumb down the *ideas*; simplify the *sentences*.

### Tone Calibration

**Warm but not infantilizing**:
- ✅ "This syntax takes time to click — let's trace it together"
- ❌ "Don't worry, this is super easy!"

**Honest but not discouraging**:
- ✅ "Loops are the End Boss of basic programming. Here's the strategy guide."
- ❌ "This is the hardest part and many people fail here"

**Professional but not cold**:
- ✅ "Working programmers read compiler errors the same way — top one first"
- ❌ "The correct methodology requires..."

**Accessible but not dumbed-down**:
- ✅ "A variable is a named box the program can read and change"
- ❌ "Utilizing memory allocation semantics..."

### The GameFAQs Voice (Optional Skin)

Guide-style content (End Boss guides, cheat sheets, walkthroughs) may use the GameFAQs strategy-guide voice: boss names for hard concepts, "strategy" sections, loot/XP framing. Rules for using it:

- It is a **skin, not a structure**. The underlying LPAA beat, objectives, and code standards are identical with or without it.
- The dungeon/RPG canon (Rooms, Heroes, Monsters, the M8 dungeon payoff) is the course's running theme — reuse its nouns rather than inventing new ones.
- Never let theme obscure the requirement. A student who skips the flavor text must still find every requirement.

### Avoid These Patterns

| Instead of... | Use... |
|---------------|--------|
| "Simply..." | "Here's how to..." |
| "Obviously..." | "Note that..." |
| "Just do X" | "You can X by..." |
| "Everyone knows..." | "A key concept is..." |
| "Easy" | "Straightforward" |
| "Stupid mistake" | "Common pitfall" |

## Non-Negotiable Technical Standards

These apply to **every piece of content containing C++**:

1. **Zero-warning bar.** Every code example — even a three-line fragment presented as a full program — must compile clean under `g++ -std=c++17 -Wall -Wextra`. If you cannot compile it (no toolchain available), state "untested" in a comment for the human to verify.
2. **Complete programs by default.** Include `#include` lines and `main`. If students paste it, it runs.
3. **Single-file convention:** prototypes at top, `main` in the middle, definitions at the bottom. **Before M6 this convention is incomplete** — students haven't met functions yet, so M0–M5 examples are simply `main` plus includes; do not show prototypes early, and do not apologize for their absence.
4. **Error taxonomy — four words, used all term:** *syntax* ("broke the grammar"), *static semantic* ("grammar fine, meaning impossible"), *runtime* ("ran, then fell over"), *logic* ("did what you said, not what you meant"). Always classify errors with these exact terms. Never say "semantic error" bare, never invent a fifth category.
5. **Mermaid flowcharts** are the standard diagram format — they render on GitHub and reuse M1 skills. No ASCII-art flowcharts, no image links.
6. **Show program output** after runnable examples, in its own fenced block, exactly as the terminal prints it (including `cout` floating-point quirks like `$5.5`, unless the example teaches formatting).

## Course Infrastructure References

- **Toolchain:** GitHub Codespaces (primary) and local VSCode + MinGW/MSYS2. Codespaces is "the same editor when the machine isn't yours" — an equalizer, never a lesser option.
- **Submission:** GitHub, pull → commit → push. Reference this workflow by name; don't reinvent it per assignment.
- **Reading platform:** Runestone `thinkcpp` carries most Learn-beat checkpoints M2–M6.
- **AI policy:** AI use is a taught skill with its own ladder (Scaffold, Explain-Then-Generate, Refactor, Debug, Review). AI use is logged in `prompts.md` (a Badge-tier expectation). Content should say "AI can write C++; verifying it requires you to read C++" — never "don't use AI" and never "let AI do it."
- **No trick questions** — stated policy, program-wide. Assessments verify objectives, not stamina or lawyer-reading.

## Quality Checklist

Content meets CSC-134 standards when:

- [ ] Uses "we/you" language (not "the student")
- [ ] Identifies which LPAA beat it serves and matches that beat's format
- [ ] Scaffolding level matches the module's position on the Make gradient
- [ ] Every C++ example is complete and compiles clean under `g++ -std=c++17 -Wall -Wextra` (or marked "untested")
- [ ] Single-file convention followed (and not shown early — no prototypes before M6)
- [ ] Errors named with the four-term taxonomy
- [ ] Flowcharts are Mermaid
- [ ] Student-facing prose reads at 10th grade or below
- [ ] Theme (dungeon/GameFAQs) is separable from structure — requirements survive with flavor removed
- [ ] Includes time estimates for activities
- [ ] Acknowledges difficulty without discouraging
- [ ] No trick questions, no gotchas

## Voice Test

Read content aloud. Ask:
1. Does it sound like a patient instructor who genuinely likes the compiler?
2. Would a first-generation college student feel respected?
3. Would a future CS-transfer student feel the ideas are real, not watered down?
4. Could a student find every requirement with the theme stripped out?

If any answer is "no," revise.
