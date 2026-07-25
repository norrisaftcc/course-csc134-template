---
name: csc134-canvas-compositor
description: Compose CSC 134 Canvas pages and assignment descriptions from Markdown source into sanitizer-safe, inline-styled HTML using the CSC 134 house style, and decide whether an artifact ships as a Canvas page, a PDF, or a standalone HTML file. Use whenever preparing CSC 134 content for Canvas — writing or restyling a page or assignment description, converting Markdown into something to paste into the Canvas HTML editor, adding callouts, checklists, code blocks, or flowcharts to course material, or working out how to get a Mermaid diagram into Canvas. Also use when the user mentions "the RCE," module pages, or says a Canvas page looks generic or boxy.
---

# CSC 134 Canvas Compositor

**Course-specific by design.** This is CSC-134's compositor; sibling courses get their own
forks (a capstone carries considerations an intro C++ course does not). The shared 80% —
sanitizer rules, tokens, placeholder discipline, the wrapper trick — is what every fork
inherits; the dial tables and the voice roster are what each fork replaces.

Forked from `canvas-page-compositor`. Same sanitizer knowledge, same emitter discipline,
different course. Three substantive changes:

1. **The dark terminal blocks are gone.** The parent skill serves a course with a machine
   narrator. This one doesn't. See *Voice*.
2. **A phase dial.** One declaration at the top of the source; the diagram routing and the
   scaffolding level follow from it. See *The dial*.
3. **Flowcharts are first-class from M2.** They are the earliest diagram in the course and
   they route to a character diagram, not an upload. See *Diagrams*.

The mental model is unchanged: **Markdown → Canvas page as document → InDesign.** The
source supplies content and structure; this skill supplies the typographic decisions. No
inventing a new visual device per page. If a page needs a device that isn't below, add it
here deliberately.

---

## The dial

Every source document opens with one comment naming where in the course it sits and which
LPAA beat it is:

```
<!-- compositor: M4 · assess -->
```

That is the whole dial. Two facts the author already knows; everything else is derived.

**Derived from the module number — which notation is in play:**

| Modules | Notation available | Diagram routing |
|---|---|---|
| **M0–M2** | Flowcharts, linear processes, message exchanges | Character diagram; native `<ol>`; sequence gutters |
| **M3–M6** | The above, plus trace tables and execution order | Character diagram; ASCII trace table |
| **M7–M8** | The above, plus indexing, memory layout, structs, classes | Character diagram (chains only); SVG figure for anything with a hub |

Do not use notation from a later row. An M3 page that draws a memory diagram is teaching
M7 content in the wrong module, and the compositor should refuse it and ask.

**Derived from the LPAA beat — how much scaffolding the devices carry:**

| Beat | Register | Device consequences |
|---|---|---|
| **Learn** | Exposition | Prose-heavy. Code blocks are read, not typed. Longest of the four. |
| **Practice** | Check | Very short. Usually no breakouts at all. |
| **Apply** | Instructor-led walkthrough | Numbered `<ol>` steps carry the page. Code blocks are complete and typed verbatim (M2–M4), or 80% complete with a marked gap (M5–M7), or absent (M8). |
| **Assess** | Contract | Terse. Task statement first. Numbered requirements. Pre-flight checklist mandatory. |

The Make gradient lives in the Apply row and nowhere else. Apply is the only beat whose
devices change across the semester; the other three look the same in M1 and M8.

**Why one dial and not two skills.** Two forks drift, and the drift lands on the shared 80%
— tokens, sanitizer rules, placeholder discipline — where divergence is pure cost. The
things that genuinely differ between an M1 page and an M7 page are the diagram row and the
Apply row, which is two tables, not two skills.

---

## Step 1: pick the delivery tier

| Student behavior | Tier | Constraints |
|---|---|---|
| Reads it once, in flow | **Canvas page or assignment** | Full sanitizer rules below |
| Answers a few questions for credit | **Canvas quiz** | Tier one rules, per-question, **no wrapper** — see below |
| Returns to it repeatedly | **PDF** | Print design: fixed page, print-safe color, deliberate breaks |
| Manipulates or tinkers with it | **Standalone HTML in Course Files** | None — see the rulings below |

Standalone HTML in Course Files is served from Canvas's sandboxed content domain, not
through the RCE sanitizer. It can carry `<style>`, web fonts, and JavaScript, so **Mermaid
renders there**. Reach for it when the behavior genuinely differs — a git simulator, an
interactive trace stepper — not to escape a constraint you found annoying. Most content is
tier one.

### Quiz question fields: tier one without the wrapper

Each question's content field is its own separately sanitized fragment. There is no shared
parent element, so **the wrapper trick does not work** and there is nothing to inherit from.
The consequences are all in the direction of doing less:

- **Emit one element per stem where possible** — a `<p>`, or a `<pre>`. Leave prose unstyled
  and let Canvas's quiz defaults render it. Restyling body text you cannot wrap means
  repeating a font stack on every paragraph, which is how quiz banks become unmaintainable.
- **`<pre>` is the exception** and must carry its full style inline, because Canvas's default
  for it is nothing.
- **No device vocabulary in a stem.** No gutters, no labels, no panels, no Haiku. A stem is a
  question, and a question that needs a callout is two questions.
- **Anything the student needs in order to answer goes in the quiz description**, not in a
  stem and not on a page they'd have to leave the quiz to reach. If the four error words are
  the answer options, their definitions are in the description. A student who has to remember
  a definition is being tested on recall you didn't intend to test — that's the no-trick-
  questions standard applied to layout rather than wording.

### Tier three: decided in advance

Provisional until the first toy exists, but locked now so nobody builds against a different
assumption:

1. **Light mode, matching the page.** A toy hangs off a page and the student returns to that
   page from it. A dark toy beside a light page reads as two artifacts by two authors. The
   dark terminal aesthetic belongs to the presentation decks, which are a projected
   performance surface — a different context with a different viewing distance.
2. **No disclosure widgets, even though tier three allows them.** This vocabulary has no
   spoiler device on tier one, and if toys have hover-to-reveal, students learn to expect it
   where it cannot exist.
3. **Never auto-tick a checkbox.** A toy obviously *can* tick the pre-flight list as the
   student completes each move. The drawn box is a contract whose whole point is that the
   student verifies their own work; auto-ticking converts it into a progress bar and teaches
   waiting for a machine to confirm you are done. Show state; let the student tick.
4. **The two-machines rule carries over unchanged.** A simulator reporting its own state is
   authoritative — it is a machine saying what happened, which is the compiler's job, so
   simulated `! [rejected] main -> main` gets the gray bar. Haiku keeps the green bar and
   stays advisory, pointing at what to look at rather than announcing what is wrong. A
   reactive Haiku that says "you forgot to commit" has done the verification the student was
   supposed to do, and has quietly inverted the course's stance on AI.
5. **Reuse the page's diagram, don't invent a second visual language.** The M1 git cycle is
   already a participants line and four numbered gutter blocks; that is the simulator's main
   screen with the state removed. The toy lights up the block you are in. Then the page is the
   static reference for the toy and the toy teaches the notation the page already taught.

**And a note on what a toy is for,** which shapes it more than any of the above: tier one can
only show a student an error message before they meet it. A simulator lets them *cause* it on
purpose and recover. So the spine of the git toy is **force the conflict, then fix it** — not
type the commands correctly.

---

## Canvas page and assignment rules

Canvas sanitizes on save. Violations are silently destroyed:

1. **Inline `style` attributes only.** No `<style>`, no `<link>`, no `@media`. This is the
   email-HTML problem.
2. **No `<script>`.** No client-rendered anything.
3. **System fonts only.** Font stacks must degrade.
4. **No inline `<svg>`.** Diagrams ship as `<img>`.
5. **Sections start at `<h2>`.** Canvas renders the title as the `<h1>` outside the content
   area, and nothing in the body repeats it.
6. **No fixed pixel widths.** The Canvas Student app renders in a ~375px webview. Use
   `max-width` and percentages; wrap tables in `<div style="overflow-x:auto">`.
7. **Never set `background-color` without also setting `color`,** or vice versa. Students on
   Canvas's high-contrast setting get half the declaration.
8. **No `<details>`/`<summary>`.** It does not survive the sanitizer in this instance.
   Grounded, not assumed. Nothing may be authored expecting a disclosure widget.

### Compose only what Canvas doesn't already render

Canvas draws chrome around the content. Restating it in the body creates two sources of
truth and the body copy is the one that goes stale.

**Never in the HTML:** due dates, points possible, availability windows, submission type,
next/previous navigation, the page or assignment title.

**Always in the HTML:** the task, the constraints, the worked reasoning, what is explicitly
out of scope, and the named common mistake.

---

## Placeholders

When a course is copied to a new term, Canvas relinks only references inserted through the
RCE, which stamps them with tracking attributes. A hand-written `src` or internal `href`
survives the copy still pointing at last term's course. So emit loud placeholders and wire
them in the RCE. Manual insertion is the correct method, not the fallback.

| Target | Placeholder | Insert with |
|---|---|---|
| Image | `src="UPLOAD-PENDING-figure-01.svg"` | RCE image tool |
| Course file (handout, style guide) | `href="#LINK-PENDING-slug"` | RCE **Course Documents** |
| Another Canvas page or assignment | `href="#LINK-PENDING-slug"` | RCE **Course Links** |
| External URL (GitHub docs, cppreference) | the real URL | type it |

Every placeholder link carries a visible marker:

```html
<a href="#LINK-PENDING-style-guide-cpp" style="color:#0374B5;">C++ style guide</a> <span style="font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;color:#9A6700;">[LINK PENDING]</span>
```

Delete the marker when the link is wired. Adjacent placeholder links may share one marker,
which must state the count: `[2 LINKS PENDING]`. The invariant: marker counts sum to the
number of placeholder links on the page. Every emitted fragment ships with `PLACEHOLDERS.md`.

---

## Design tokens

| Role | Value | Use |
|---|---|---|
| ink | `#16191D` | headings, code text |
| body | `#3C4149` | body text (set on wrapper) |
| muted | `#6B7280` | labels, captions, checkbox borders |
| rule | `#DFE3E8` | hairlines, table rows, default gutters |
| wash | `#F4F6F7` | code, diagram, and panel backgrounds |
| accent | `#1F6F5C` | kickers, sequence gutters, source-document gutters |
| caution | `#9A6700` | caution gutters and labels, placeholder markers |
| link | `#0374B5` | links only — Canvas blue, and it stays that way |

Mono stack: `ui-monospace,SFMono-Regular,Menlo,Consolas,monospace`

The accent is deliberately not Canvas blue (links own that) and deliberately not warm clay,
which is the current visual tell of AI-generated documents. **Accent no more than three
times per page**, counting distinct *roles*, not occurrences — a sequence of nine gutter
blocks is one accent use, because the repetition is what makes it legible as a set.

The parent skill's phosphor and amber tokens are removed along with the dark blocks. If a
future artifact needs a fifth color, it earns one here first.

## The wrapper trick

Put every inheritable property on one wrapper `<div>` and let it cascade. Children carry
only non-inheritable properties: background, border, padding, margin, display.

```html
<div style="max-width:52rem;font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Lato,Helvetica,Arial,sans-serif;color:#3C4149;font-size:1rem;line-height:1.65;">
  ...content...
</div>
```

Without this, inline CSS bloats past readability. With it, most elements need one short
`style` attribute or none.

---

## Voice

Voice is decided upstream by the course's own canon and arrives settled in the source. The
compositor's only job is to make voice shifts visible. CSC 134 has four voices and one open
question.

> **STATUS — the Haiku device is NOT CSC-134 canon yet (ADR-013 pending).**
>
> Haiku arrived with this skill from the parent course, where she descends from the
> project's original Gemini Flash assistant. Her *reasoning* holds — CLO8 covers "the
> responsible, cited use of AI assistance"
> (`_storming/CSC-134-learning-objectives.md:29`) — but a named assistant with a register,
> a glyph, and rationing rules is **content, not formatting**, and content enters this
> course by ADR, not on a compositor PR.
>
> **Until ADR-013 rules: do not emit Haiku check-ins.** Everything below is preserved as
> the design of record so the ruling has something concrete to rule on, and so the work
> is not redone from scratch. The self-check gates for check-ins stay live — they pass
> vacuously at zero check-ins and start biting the moment the first one is emitted.
>
> The ruling also carries an authorship task the compositor cannot do: students are not
> issued Claude accounts, but the course means to suggest that Haiku is the better use of
> a free account's token budget. That belongs in M1 Learn prose, hooked to the naming
> passage below, which already ends one sentence short of it.

| Voice | Device | Why |
|---|---|---|
| **Instructor teaching** (default) | Plain body copy, no device | It's the page's register. A box would imply it's optional. |
| **Instructor out of character** — support, policy, the human talking | Hairline gutter, muted mono label, **plain sans prose** | The frame drops and the design drops with it. Never decorated. |
| **Scenario flavor** — the Gatekeeper, the dungeon, the pizza shop | Plain body copy, usually under a *The situation* heading | Skin, not structure. It must strip cleanly, and a device welds it on. |
| **Machine output** — compiler warnings, `git` errors, program runs | Code device (left-rule `<pre>`) | See the monospace rule below. |
| **Haiku** — the AI assistant, checking in *(ADR-013 pending — do not emit)* | Accent gutter, mono label, **mono body**, no wash | She is a machine and her text really is machine text — but she is not the compiler, so she doesn't get the compiler's device. |

**The monospace rule, which is the whole reason the dark blocks are gone.** In this course
monospace means *a machine actually emitted this text*. Not "a character is speaking," not
"this is important." Students spend the term learning to read literal compiler output, and
every decorative use of monospace trains them to skim exactly the thing they must read
closely. So no fictional character speaks in monospace, there is no transmission device, and
the Gatekeeper does not get a terminal.

**Two machines, and the student must be able to tell them apart.** The compiler and the
student's own program are *authoritative* — they report what happened. Haiku is *advisory* —
she reports what is likely, and she is sometimes wrong. Both are real machine text, so both
are monospace. They take different devices, and the page says which is which the first time
both appear on it:

> Two kinds of computer text on this page. A **gray bar** means this is exactly what your
> machine printed — the compiler, or your own program running. A **green bar with a rose** is
> Haiku, an AI assistant. Haiku is usually right and never authoritative: the rose means the
> checking is yours to do.

That distinction is CLO8 arriving as a design decision rather than a lecture. Getting it
wrong — giving Haiku the compiler's device — teaches students that plausible text and true
text look the same, which is the opposite of the course's stance on AI.

**Sans, mono, and the shape they nearly share.** The instructor device and the Haiku device
started as the same shape — gutter, mono label, one paragraph — differing only in rule color
and body face: instructor hairline gray with a **sans** body, Haiku accent green with a
**mono** body. That near-identity was elegant, and the rose deliberately breaks it. Elegance
loses to legibility here: for a mixed cohort, three redundant signals (color, face, rose) beat
one subtle one, and the human voice on the page has to be findable by a student who is not
reading carefully because they are not in a state to read carefully. The instructor device
stays the plain undecorated gutter. Everything else on the page can afford to be marked.

**Two rules that outrank aesthetics:**

1. **The instructor device is never decorated.** This is the accessibility floor of the whole
   system: a student in trouble has to be able to find the real human on the page. Sans
   body, hairline rule, no color.
2. **Scenario flavor never gets a device.** *Skin ≠ structure* is a program-wide rule, and
   the test is that a re-skin touches only prose. A dungeon-themed callout box fails that
   test, because now the theme lives in the markup too.

### Instructor out of character

```html
<div style="border-left:2px solid #DFE3E8;padding-left:1rem;margin:0 0 1.4rem;">
  <p style="margin:0 0 .25rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;letter-spacing:.1em;text-transform:uppercase;color:#6B7280;">Instructor &middot; out of character</p>
  <p style="margin:0;">Plain prose. Real support. Real policy.</p>
</div>
```

The label is monospace because every gutter label on the page is monospace — that's the
label system, not a voice signal. The body is sans, and that's the signal.

### Haiku check-in

```html
<div style="border-left:2px solid #1F6F5C;padding-left:1rem;margin:0 0 1.4rem;">
  <p style="margin:0 0 .3rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;letter-spacing:.1em;text-transform:uppercase;color:#1F6F5C;"><span style="letter-spacing:normal;">--------{---(@</span> &nbsp;Haiku &middot; check-in</p>
  <p style="margin:0 0 .3rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.9rem;line-height:1.55;">Understated observation. Then a flat imperative check.</p>
  <p style="margin:0;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;color:#1F6F5C;">@)---}--------</p>
</div>
```

Reading flow, not a breakout — no wash, no enclosure, so it doesn't spend the breakout
budget. It does spend an accent role.

The rose sits in its own `<span>` with `letter-spacing:normal`, because the label system's
tracking would pull it apart into `- - - - { - - - ( @`. The closing rose is the mirror of the
opening one, so the pair reads as a frame rather than a repeat.

### The rose

**Haiku fences every check-in with an ASCII rose. Flowery language, literally.**

That is the whole device, and it does more work than the wry register it marks. The problem
with teaching *interesting* as a warning word is that it has to be inferred, and a course with
a genuinely mixed cohort cannot afford a convention that only lands for students who already
share the reference. The rose converts an inferred register into a **taught convention**:
stated once, then visible on every instance, decodable by anyone who read the introduction.

The decoding rule, and it is stated flatly:

> **A rose means: this is worth verifying, and you are the one who verifies it.**

That is the AI-literacy beat with nothing left implicit. Haiku produces plausible text.
Plausible is not true, and the rose is where the difference becomes the student's job.

**Introduced once, in M1, with the naming:**

> When Haiku hedges, she draws a rose.
>
> `--------{---(@`
>
> Flowery language, literally. The rose means she is telling you something she thinks is
> probably true, and that checking it is yours to do. She is a machine that produces
> plausible text — usually right, never authoritative. Look for the rose. It is the polite
> version of *something here is about to break.*

**Why ASCII and not an icon.** The decoration is made of characters, not styling, which is
the M1 thesis arriving as a design decision: plain text can carry structure, emphasis, and
now iconography, and it survives being pasted into a terminal, a commit message, or a plain
text email. An SVG rose would need an upload, a placeholder, and an RCE wiring step, and
would teach the opposite lesson.

**It also makes check-ins mechanically auditable** — but count the two roses separately,
because they are not the same string. The opening rose ends in `(@`; the mirrored closing rose
begins with `@)`. The gate is `count("(@") == count("@)") == number of check-ins`, which fails
loudly on an unclosed fence. Grepping for `(@` alone silently passes a check-in that was never
closed, which is how this rule was found to be wrong the first time it was written.

**The honest cost.** A screen reader announces `--------{---(@` as a run of punctuation, twice
per check-in. The text label `Haiku · check-in` sits on the same line as the opening rose and
carries the meaning, so nothing is lost — but noise is added. If `aria-hidden="true"` survives
the sanitizer in your instance, put it on both rose runs; **test that rather than assuming
it**, and if it's stripped the device still works, just more loudly. This is the same tradeoff
as box-drawing characters in the character diagrams: paid deliberately, not overlooked.

### Haiku's register

She does not say "sticking point." She says **interesting**, and she means it the way an
engineer means it in a code review:

> You may find the relationship between these two conditions interesting.

> There's something interesting about what happens when the player doesn't type a number.

> The exact numbers here are interesting.

> Interesting question: what does your program do at precisely 70?

The joke is that *interesting* is understatement, and it lands through repetition — by M4 a
student reads "you may find this interesting" as **something is about to break**. That is not
only a joke. Hedged criticism is how humans and LLMs both deliver bad news, and decoding it
is the human-facing half of the Communication spine: the compiler is a literal agent that
says exactly what it means, and almost nothing else the student will ever work with is.
Learning to hear *we may want to revisit this* as *this is wrong* is a professional literacy
the compiler cannot teach.

**The word has a lineage, which is the answer to "isn't this just cute?"** Code that was
tangled, over-clever, or dense with special cases used to be called **hairy** — the Jargon
File sense, still current in older codebases and code review. *Interesting* is the polite
descendant of *hairy*, and it means the same thing: complex, nuanced, more going on here than
the line count suggests. So Haiku is not inventing a euphemism for the course. She is using
the one the field already uses, which means a student who learns to read it here is reading
their eventual colleagues correctly.

Keep the stem list short. Four or five recognizable openers make a pattern; twenty make
noise, and the pattern is the whole mechanism.

**The label stays literal.** `Haiku · check-in`, never `Haiku · interesting`. The gutter label
is the scannable, information-carrying part of the device; the understatement lives in the
body where a reader has already committed to reading. Never both.

**Content rules, which matter more than the markup:**

1. **The observation is understated. The check never is.** Sentence one may hedge; the
   sentence that tells the student what to do is a flat imperative with a concrete outcome.
   "Run it with 85. If you get the riddle, the order is wrong" is a check. "You might want to
   look at your conditions" is a guess wearing a device. This rule is what makes the
   understatement safe: a student who reads *interesting* completely literally still performs
   the right action, because the next sentence is an instruction that works without the joke.
2. **Never an assertion the student can't verify.** She names what to run and what they'll
   see, not what's wrong.
3. **The check must be runnable in under a minute.** Type this input, look at this line, count
   the lines. If verifying takes longer than fixing, it isn't a check-in.
4. **Only for things the compiler won't catch.** If `-Wall -Wextra` reports it, it belongs in
   the code device as real compiler output, with prose explaining what the compiler means.
   Haiku exists for the silent failures: input that doesn't convert, conditions in the wrong
   order, off-by-one at a boundary, a plan file that no longer matches the program.
5. **Nothing load-bearing is ever understated.** This is the boundary that licenses the whole
   register. If a thing must not be skipped — a data-loss risk, a policy consequence, an
   academic-integrity line — it is a **caution** in the instructor's voice, blunt, with the
   word *Caution* on it. Haiku is only allowed to be wry because she never carries anything a
   student can't afford to miss. The two devices must never trade jobs.
6. **She never writes the student's code and never appears in an Assess beat.** Assess is a
   contract; a hint inside a contract is a hint everyone gets and nobody attributes. Haiku
   lives in Learn and Apply.

**Rationing.** One per stage in an Apply walkthrough, where the check-in is structurally part
of the stage. Two per page anywhere else. A page where Haiku talks more than the material does
has inverted its purpose.

**Named once, in M1**, and then never explained again:

> Her name is Haiku, and she is the small fast one. There are bigger models named after
> longer poems, which tells you the whole scheme once you notice it: a haiku is seventeen
> syllables, a sonnet is fourteen lines, an opus is however long it needs to be. Picking the
> smallest one that can do the job is a real skill, and it starts with knowing which is
> longer.

Legacy Module 02 material calls this assistant **Flash** (it was Gemini Flash). Rename to
Haiku on the editing pass, and rewrite the surrounding copy rather than swapping the noun —
the old material has her *answering* questions, and the device above only supports her
*prompting* them.

---

## Reading flow or breakout

Every block is one or the other, and that's always the design question.

**Reading flow.** The reader passes through without stopping: body copy, headings, lists,
steps, tables, asides, cautions, sequence gutters, the instructor device. These get **a left
rule plus a monospace label** — never an enclosing box. The gutter is load-bearing: the
label always carries information (a step number, the word *Caution*, the name of the voice).
If you can't write a truthful label, drop the device and use a plain paragraph.

**Breakout.** The reader stops, treats it as an object, and returns: code, diagrams,
checklists, worked examples. These get an enclosure, and the enclosure style says what kind
of object it is.

- **Three to five breakouts per page.** Past that the page is a stack of objects with prose
  in the cracks. (The parent skill's budget of four to six assumed two voice blocks per page;
  without them the ceiling comes down.)
- **In an Apply walkthrough the unit is the stage, not the block.** A staged build is
  code → output → code → output by nature, and counting each block separately puts a
  three-stage page over budget before it has said anything. So one **breakout group** per
  stage — the code to type, the output it should produce, and at most one check-in — counts
  as one, and the ceiling is five stages. The adjacency rule still holds inside the group:
  a real sentence sits between the code and its output, telling the student to compile and
  run. This is the same principle as repeating devices counting once.
- **Every breakout must be skippable.** If a reader who skipped it loses the thread, it isn't
  a breakout — it's reading flow wearing a box.
- **Never two breakouts in a row** without body copy between them. Adjacent breakouts read as
  one confused object. This binds hardest on a character diagram and its Mermaid source,
  which is the most common adjacency in this course; the prose statement of the diagram goes
  between them.
- **The enclosure style is the type signal.** Three styles, three meanings. Don't mix them.

### The three breakout styles

| Style | Means | Spec |
|---|---|---|
| Left rule, no radius, wash | **Code or machine output** — part of the argument, read left to right | `border-left:2px solid #DFE3E8` |
| Full border, radius 6, wash | **Diagram** — an object you look at | `border:1px solid #DFE3E8;border-radius:6px` |
| Full border, radius 4, wash | **Panel** — checklist, summary, worked example | `border:1px solid #DFE3E8;border-radius:4px` |

Radius 6 against radius 4 is a quiet distinction, and it is doing real work: both are
monospace-on-wash, and without it a diagram and a checklist read as the same object. Keeping
code out of the bordered family is what stops the page reading as an undifferentiated wall of
monospace.

---

## Component vocabulary

### Page header — kicker, lede, hairline

Pages only. **No `<h2>` title:** Canvas already renders the title as the `<h1>`, and the
parent skill's duplicate was a heading-hierarchy bug as well as a visual one. Section
headings on both pages and assignments are `<h2>`, so the document runs h1 (chrome) → h2 →
h3 with nothing skipped.

```html
<p style="margin:0 0 .5rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.72rem;letter-spacing:.14em;text-transform:uppercase;color:#1F6F5C;">Module 04 &middot; Reading</p>
<p style="margin:0 0 1.4rem;font-size:1.1rem;">One or two sentences on why this page exists and what the student will be able to do after it.</p>
<hr style="border:0;border-top:1px solid #DFE3E8;margin:0 0 1.6rem;">
```

### Assignment task statement

First thing on the page, imperative. Canvas often collapses the description on mobile, so
the first line must carry the actual work.

```html
<p style="margin:0 0 1.2rem;font-size:1.15rem;color:#16191D;">Write a program that does the thing, subject to the constraints below.</p>
```

### Headings

```html
<h2 style="margin:1.8rem 0 .6rem;font-size:1.2rem;line-height:1.3;color:#16191D;">Section</h2>
<h3 style="margin:1.4rem 0 .5rem;font-size:1.05rem;line-height:1.35;color:#16191D;">Subsection</h3>
```

`<h3>` is for pages long enough to need it — a Learn beat, generally. An assignment that
needs `<h3>` is probably two assignments.

### Aside — the default reading-flow device

```html
<div style="border-left:2px solid #DFE3E8;padding-left:1rem;margin:0 0 1.4rem;">
  <p style="margin:0 0 .25rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;letter-spacing:.1em;text-transform:uppercase;color:#6B7280;">Note</p>
  <p style="margin:0;">Body of the aside.</p>
</div>
```

### Caution — same shape, `#9A6700` on rule and label

Never signal by color alone; the word *Caution* does the work. **Label the common mistake as
common** — "Most students who lose points here lose them this way" does more work than any
amount of warning language. One caution per page; a second one means the first wasn't the
common mistake.

### Source document

For anything the student cannot do the work without. A bare inline link is not enough.

```html
<div style="border-left:2px solid #1F6F5C;padding-left:1rem;margin:0 0 1.4rem;">
  <p style="margin:0 0 .25rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;letter-spacing:.1em;text-transform:uppercase;color:#1F6F5C;">Source document</p>
  <p style="margin:0;"><a href="#LINK-PENDING-slug" style="color:#0374B5;">Document title</a> <span style="font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;color:#9A6700;">[LINK PENDING]</span> &mdash; what to do with it, in one sentence.</p>
</div>
```

### Table — reading flow, hairline rows, no enclosure

A table is scanned in flow, so it gets no border and no radius. Hairline row rules only,
first column carrying the label. Always wrapped.

```html
<div style="overflow-x:auto">
  <table style="width:100%;border-collapse:collapse;margin:0 0 1.2rem;font-size:.95rem;">
    <tbody>
      <tr>
        <td style="padding:.5rem .7rem .5rem 0;border-bottom:1px solid #DFE3E8;vertical-align:top;">Label</td>
        <td style="padding:.5rem 0;border-bottom:1px solid #DFE3E8;">Value</td>
      </tr>
    </tbody>
  </table>
</div>
```

Two columns is the ceiling on tier one. A three-column table at 375px is a horizontal
scroll bar with data in it; restructure it as gutter blocks or move it to a PDF. Drop
`border-bottom` on the last row. Use `<thead>` with `<th style="text-align:left;">` only
when the table genuinely has a header row — a label/value table does not.

### Code and machine output

```html
<pre style="margin:0 0 1.4rem;padding:.85rem 1rem;background-color:#F4F6F7;color:#16191D;border-left:2px solid #DFE3E8;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.85rem;line-height:1.5;overflow-x:auto;">code here</pre>
```

Escape `<` and `>` as `&lt;` `&gt;`. That means every `#include <iostream>` and every
`cout <<` in this course, which is most of them — check it programmatically, don't eyeball it.

**Show the error before they hit it.** An error message a student has been introduced to is
a debugging step; one they haven't is a dead end. Error text gets the code device, and the
sentence after it says what the compiler is actually complaining about.

### Steps

A real `<ol>`, restyled for spacing. Inline CSS can't reach `::marker`; don't fake numbered
badges to get around that. **Number requirements so feedback can cite them** — "see 4" is
worth more than a bullet.

### Checklists: bullets describe, checkboxes commit

**A bullet is prose. A checkbox is a contract.**

- **Bullets** — definitions, examples, reference lists, tier descriptions. Standard `<ul>`.
- **Checkboxes** — actions the student performs and can verify alone. Setup tasks, pre-flight
  checks, submission requirements.

Two constraints follow from calling it a contract:

1. **Every box must be checkable by the student without asking anyone.** If it depends on a
   grade or the instructor's judgment, it's reading flow. A box a student can't honestly tick
   is a broken promise in a device that promises completability.
2. **The boxes must survive printing.** Students print these and tick them with a pen. No
   `<input type="checkbox">` (the sanitizer may strip it, and it implies saved state that
   doesn't exist), and no Unicode `☐` (U+2610 tofus on some Android webviews, and a tofu in a
   contract is worse than no glyph). Draw the box with a border, which prints even with
   background graphics off.

```html
<ul style="margin:0;padding:0;list-style:none;">
  <li style="display:flex;margin:0 0 .55rem;">
    <span style="flex:0 0 auto;display:inline-block;width:.85em;height:.85em;border:1.5px solid #6B7280;border-radius:2px;margin:.3em .6em 0 0;"></span>
    <span>The thing the student does, phrased so they can tell whether they did it.</span>
  </li>
</ul>
```

The box is sized in `em` so it scales with the type — the one place a small fixed dimension
is correct. The span is empty, so assistive technology reads the item text and skips the box;
don't put a character inside it.

**Source notation:** GFM task list items — `- [ ] Do the thing`. One notation upstream, three
renderings: drawn box on tier one, drawn box in the PDF, native task list wherever GitHub
renders it. **Inside a `<pre>`, checkboxes stay as literal `[ ]`** — a drawn box breaks the
monospace column grid.

Checkbox lists almost always live inside a panel. The panel says *this is a steppable
object*; the boxes say *here is how you step it*.

### Panel

```html
<div style="background-color:#F4F6F7;color:#3C4149;border:1px solid #DFE3E8;border-radius:4px;padding:1rem 1.1rem;margin:0 0 1.4rem;">
  <p style="margin:0 0 .5rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;letter-spacing:.1em;text-transform:uppercase;color:#6B7280;">Before you submit</p>
  ...
</div>
```

Every Assess beat ends with one of these. No exceptions — the pre-flight checklist is where
the zero-warning standard and the file-naming convention actually get enforced.

---

## Diagrams

**Mermaid does not render in a Canvas page.** It's JavaScript. On tier one it is a *source*
format only. On tier three it renders normally.

### Who authors the notation decides the device

This is the routing question, asked before the shape question:

| The student… | Device | Because |
|---|---|---|
| **reads** the diagram | Character diagram in a rounded `<pre>`, or an SVG figure | They need to see the shape. |
| **writes** the notation | **Code block.** The source is the artifact, not an illustration of one. | Rendering it to a picture teaches the opposite of the lesson. |
| **both** — reads a model, then writes their own | Character diagram **and** its source, prose between them | The default from M2 onward. |

The third row is the common case in this course and it is the point: same diagram, two
representations, one of them is text. That lands the diagrams-as-code idea without a word of
explanation, and it lands it in M2 rather than waiting for a later module.

### Shape routing

| Diagram shape | Treatment |
|---|---|
| **Flowchart — decision chain with early exits** | Character diagram + Mermaid source |
| **Flowchart — merges or loop-backs** | SVG figure + text equivalent |
| Sequence / message exchange | Native HTML sequence gutters (below) |
| Linear process, timeline | Styled `<ol>` |
| Data layout, indexing, memory, execution trace | Character diagram (M7+ only per the dial) |
| Class or struct structure | Character diagram, three compartments (M7+) |
| Anything with a hub, anything genuinely two-dimensional | SVG figure + text equivalent |

**Flowcharts are the course's first diagram and they route to characters, not to an upload.**
A decision chain drawn in 28 columns is a diagram a student can reproduce — copy onto paper
in thirty seconds, redraw from memory, sketch on a whiteboard. Nobody reproduces an SVG.
When the goal is *learning a notation* rather than consuming a specific picture, the
reproducible form is the better teacher, and it means the thing on the Canvas page and the
thing the instructor draws on the board are the same object. It also removes the render,
upload, and RCE-wiring steps from the earliest and highest-friction pages in the course.

```
      ┌──────────────┐
      │ Player       │
      │ arrives      │
      └──────┬───────┘
      ┌──────┴───────┐
      │ strength     │
      │ >= 70 ?      │
      └──┬────────┬──┘
     yes │        │ no
  ┌──────┴─────┐  │
  │ Gate opens │  │
  └────────────┘  │
       ┌──────────┴───┐
       │ strength     │
       │ >= 40 ?      │
       └──┬────────┬──┘
      yes │        │ no
  ┌───────┴────┐   │
  │ Riddle     │   │
  └────────────┘   │
           ┌───────┴──────┐
           │ Turned away  │
           └──────────────┘
```

**Column budget: 24 to 28 comfortable, 40 the hard ceiling** from the 375px webview. Every
box row must be exactly the same width or the borders shear — check it programmatically.
Box-drawing characters are Unicode, not markup, and every system monospace font has them.

**The layout constraint is what decides it.** At 40 columns you cannot place two wide boxes
side by side, so a **relationship** diagram — flowchart, ERD, class structure — can only
express chains and shallow trees: the yes-exit hangs off to one side, the spine continues
straight down at a fixed indent so it never drifts right. A flowchart whose branches rejoin,
or that loops back to an earlier question, has nowhere to draw the return; split it into two
chained diagrams or escalate to SVG.

**Data-layout diagrams are a different family and the chain rule doesn't bind them.** Arrays,
index rows, and struct records are grids, not relationships, and narrow cells sit side by side
comfortably — three eight-column cells fit in half the budget. The 40-column ceiling still
applies; nothing else does.

**The honest tradeoff.** Box-drawing characters read to a screen reader as a stream of line
characters — worse than an SVG with good alt text. So a character diagram always ships with
**a short prose statement of the logic** next to it: three or four sentences, not optional.
This is a cost-and-robustness win with an accessibility cost paid down deliberately, not an
accessibility win.

### Native sequence — participants line, then one gutter block per message

```html
<p style="font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.78rem;color:#6B7280;margin:0 0 1rem;">Participants: You &middot; Your computer &middot; GitHub</p>
<div style="border-left:2px solid #1F6F5C;padding-left:1rem;margin:0 0 .9rem;">
  <p style="margin:0 0 .2rem;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.74rem;color:#1F6F5C;">01 &nbsp;GitHub &rarr; Your computer</p>
  <p style="margin:0;">What happens in this step, in plain language.</p>
</div>
```

A linearized sequence is often *better* than the picture: selectable, searchable, legible at
375px, and readable by a screen reader without a separate long description.

### SVG figure — the escalation path

**Images ship as SVG.** Grounded: this instance accepts `.svg` uploads and serves them to
`<img src>`. SVG stays crisp at 375px and on retina from one build step. PNG only for raster
content — screenshots, photos. Two constraints on SVG through `<img>`: it can't load external
fonts, so use `monospace` / `sans-serif` generics only; and it can't be styled from the page,
so bake the tokens into the file.

```html
<figure style="margin:0 0 1.4rem;">
  <img src="UPLOAD-PENDING-figure-01.svg" alt="Full description of what the diagram shows." style="display:block;max-width:100%;height:auto;border:1px solid #DFE3E8;">
  <figcaption style="margin:.5rem 0 0;font-size:.85rem;color:#6B7280;">Figure 1. Caption. &middot; <a href="#LINK-PENDING-fig01-source" style="color:#0374B5;">diagram source</a> <span style="font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;font-size:.7rem;color:#9A6700;">[LINK PENDING]</span></figcaption>
</figure>
```

One `.mmd` per figure, one build step, and the source ships downloadable alongside it — a
diagram whose source is readable teaches diagrams-as-code, which is real competency this
course is building. Never author the diagram twice.

**A load-bearing diagram's text equivalent goes on the page, in the open, as reading flow.**
Not collapsed (there is no disclosure device), not on a linked page, not in alt text alone.
Alt text serves someone who can't see the figure; the text equivalent serves everyone,
including the student on a phone who can't usefully pinch-zoom.

Vendor third-party JavaScript (Mermaid included) into Course Files rather than pulling from a
CDN on a tier-three page. Campus networks block CDNs, and a course asset that breaks on the
campus wifi is worse than a slightly larger file.

**What never becomes a character diagram, so the manual list is known in advance:**
wireframes and screen mockups, screenshots, state machines, architecture diagrams with
parallel tracks, and anything with a hub. Hand-built or escalated, every time.

---

## Workflow

1. Read the source. Note the dial declaration, the structure, and any voice shifts.
2. Pick the delivery tier.
3. Map each element to a component. **Flag anything with no mapping and ask** rather than
   improvising a device.
4. Route diagrams: authorship first, then shape. Build character diagrams inline; list any
   SVG figures in `manifest.txt`.
5. Emit one HTML fragment per page or assignment, wrapper div outermost.
6. Emit `PLACEHOLDERS.md`.
7. Author uploads images and wires links in the RCE, deleting the markers.

**The emitted HTML is build output.** Don't hand-edit in the RCE — the editor reformats
markup on save and the change is lost on the next build. Edit the Markdown and re-emit.
Wiring placeholders is the one sanctioned in-RCE edit, which is why the placeholders are
conspicuous.

---

## Self-check before emitting

**Sanitizer**
- Any `<style>`, `<script>`, `<link>`, `<svg>`, `<details>`, or `class` attribute? Remove.
- Any `<h1>`, or an `<h2>` repeating the Canvas title? Remove.
- Any fixed `px` width, or a table not wrapped in an overflow div? Any table over two columns?
- Any `background-color` without a matching `color`?
- Any unescaped `<` or `>` inside a `<pre>`?

**Voice**
- Any dark block, or any monospace prose that isn't a gutter label, a Haiku check-in, or real
  machine output?
- Is the instructor device plain — sans body, hairline rule, no color?
- Does any scenario flavor sit inside a device instead of plain prose?
- Does every Haiku check-in name a check the student can run in under a minute?
- Is every check-in's instruction a flat imperative with a concrete outcome, so it works for a
  reader who takes *interesting* literally?
- Is every check-in fenced top and bottom? Gate:
  `count("(@") == count("@)") == number of check-ins`.
- Any rose outside a Haiku check-in? Any rose inside a letter-spaced run?
- Any Haiku label reading anything other than `Haiku · check-in`?
- Anything load-bearing sitting in a check-in instead of a caution?
- Any check-in for something `-Wall -Wextra` would have caught? Move it to the code device.
- Any Haiku in an Assess beat? Remove.
- If both devices appear on the page, is the gray-bar/green-bar distinction stated once?

**Budget**
- More than five breakouts, two breakouts adjacent, or a breakout that isn't skippable?
- In an Apply beat: more than five stages, or a stage with more than one check-in?
- Accent used in more than three distinct roles?
- More than one caution?

**Content**
- Any due date, points value, or title that Canvas already renders?
- Any real image `src`, or real `href` to a course file or Canvas page?
- Does every placeholder link carry a marker, and appear in `PLACEHOLDERS.md`, with counts
  summing correctly?
- Every document the student must open has a Source document device, not a bare link?
- Every list of student actions a checkbox list; every list of definitions a plain bullet list?
- Any `<input>`, any Unicode `☐`, any checkbox the student can't verify alone?
- Every character diagram: equal row widths, under 40 columns, prose statement adjacent?
- Every character diagram the student must reproduce: is its Mermaid source on the page, with
  prose between the two?
- Does the diagram notation match the dial's module row?
- Does an Assess beat end with a pre-flight panel?

---

## Deferred

Two conflicts found while testing the parent skill, triaged out rather than resolved. They
are recorded so they aren't rediscovered from scratch.

1. **Spec list vs. checkbox list.** Numbered program requirements *are* student actions,
   which the checkbox rule would claim, but they need to be citable by number in feedback.
   Current practice: numbered `<ol>` for requirements, checkboxes for pre-flight verification.
   Not written as a rule.
2. **C/B/A tiers vs. "no rubric restatement."** Canvas rubrics are criterion × rating and
   can't express tiers, so the tiers have to live in the description. Current practice:
   describe them as scope under a *How far you take it* heading, in words rather than letter
   grades, so the description doesn't contradict the attached rubric. Not written as a rule.

*(The AI-assistant voice was deferred here in the first pass and is now resolved — see
**Haiku check-in** above.)*
