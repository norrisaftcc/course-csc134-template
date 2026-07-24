# M4 cohort round 1 — student feedback (verbatim)

Three approved personas took M4 (Decisions) end-to-end in isolated worktrees with the real `g++`
toolchain, kept an experience journal, and wrote direct feedback to the author. Their feedback is
reproduced verbatim below (lightly de-escaped). Findings distilled in
`_lore/findings/F-005-m4-cohort-round1.md`.

---

## Maria — the Literalist (community-garden skin, B tier)

> Straight talk: this was one of the smoothest modules I've been through in this course so far. Every
> single predicted output in Learn, Practice, and Apply matched what actually happened when I ran it —
> not close, exactly, character for character. That matters more than it sounds like it should when
> you're the kind of person who still isn't sure she trusts her own reasoning about code yet. When my
> prediction and the compiler agree ten times in a row, I start to believe I can actually read this stuff.
>
> The thing I want to call out as genuinely well done: naming the three traps "out loud" ahead of time
> in Learn, instead of springing them on me later, made the Deliberate Break in Apply feel like a
> planned lesson instead of a gotcha. And the line about switch fall-through producing "no warning at
> all" stuck with me — it's the first time this course told me flat out that a clean compile isn't
> proof of anything, and it made me want to actually test my program instead of just trusting that it built.
>
> My one real ask: give Trap 1 (= vs ==) and Trap 3 (dangling else) the same hands-on treatment Trap 2
> got. I read about both of them, and I believe you that they're real bugs, but reading about a bug and
> watching my own terminal do the wrong thing are different kinds of learning, and only fall-through got
> the "watch it happen to you personally" version. If it's worth 5 minutes for the switch, it feels
> worth 5 minutes for the other two.
>
> For Assess, thank you for the explicit permission to stop at a tier I'm sure about instead of
> stretching for one I'm not. I read the A-tier "genuinely nested" requirement twice and decided my
> trellis check didn't honestly qualify, and the lab's own language ("C is the objective met, not
> partial credit") made me feel fine writing that down instead of padding my plan file to sound more
> impressive than the code actually is.

**Also noted (journal):** the trace-table scratchpad in Practice Item 2 helped; wished Items 3 and 6
had one too. The `cin` glued-digit output looked like a typo on first read.

---

## Jaylen — the Skimmer (streamer-chat skin, B tier)

> Jaylen here. This module is *solid*. The three traps being named upfront stops gotchas cold — you
> know what to hunt for before you write. The flowchart-first design in ASSESS is genius; I drew it
> before coding and the program almost wrote itself.
>
> One thing: the switch fall-through being silent (no warning, just wrong output) is the scariest part,
> and the deliberate-break exercise nails it. But it's worth saying explicitly in Learn or the top of
> Apply: "A clean compile is not proof of a correct program." Students skim instructions, so that
> sentence standing alone would save a lot of debugging later. *(Note: already present twice in
> apply-tutorial.md — filtered as model-noise in F-005.)*
>
> The gatekeeper reskin opportunity in ASSESS is perfect — I ran a streamer chat tier system instead
> and the exact same decisions worked. That's how you know the logic is sound.
>
> The compound condition (&&) placement in ASSESS was the trickiest part for me — ordering the VIP
> Lurker branch before the plain >= 20 check to keep it reachable. That's probably where most B-tier
> attempts will stumble. Worth flagging in the spec or troubleshooting section.
>
> Predict-first blocks in Learn worked great for me (both right), but I'm a fast reader. Students who
> skim less carefully might need those reveals a bit more explicit so they don't accidentally read the
> answer while scanning. *(Note: reveals are already collapsed `<details>` gates — model-noise.)*
>
> Overall: good rhythm through the four beats, clear spec for ASSESS, traps named not sprung. Ship it.

---

## Dee — the Rules-Lawyer (tavern-keeper / bouncer skin, B tier)

> This module is solid. The progression from Learn to Practice to Apply to Assess is logical and
> scaffolded beautifully. Three things stand out as exemplary: (1) The three traps are named, not
> sprung — students know what to hunt for. (2) The Apply tutorial's "deliberate break" section is
> masterful — watching clean code produce wrong output teaches more than a lecture. (3) The
> flowchart-first design requirement in Assess is excellent pedagogy — it forces logic design before
> typing. The theme (dungeon gatekeeper) peels off cleanly; I reskinned as tavern keeper without
> breaking a decision. That's clean design.
>
> I found three minor ambiguities (all one-sentence fixes): Item 6's wording could focus on the
> threshold work instead of line location; the testing section could model reputation=0 as a boundary
> edge case; A-tier's "distinct endings" could specify "distinct outcome messages." These are friction
> points, not gotchas. After those tweaks, M4 is exemplary. The course honors its "no trick questions"
> promise.

**Also surfaced (via cohort-lead's toolchain recompile):** `learn.md` and `assess-lab.md` quote the
`=`/`==` compiler warning in two different wordings (clang paraphrase vs real GNU g++) — a real
cross-document inconsistency on the actual course toolchain. Sharpened to a should-fix in F-005.
