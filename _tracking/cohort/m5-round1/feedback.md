# M5 cohort round 1 — student feedback (verbatim)

Three approved personas took M5 (Loops) end-to-end in isolated worktrees with the real `g++`
toolchain, kept an experience journal, and wrote direct feedback to the author. Their feedback is
reproduced verbatim below. Findings distilled in `_lore/findings/F-017-m5-cohort-round1.md`;
the run plan, frozen before execution, is in `PLAN.md`.

**Read the feedback against F-017's break-character section.** Two of the three stepped outside
their persona sheets, one of them silently — praise from those runs carries less weight than it
appears to.

---


## Maria — the Literalist (community-garden skin, sonnet)

**Tier reached:** Badge (content complete: C, B, A, and Badge deliverables all done and verified; Submission step blocked by a git push/upstream-tracking failure I did not work around)

> I made it all the way through Learn, Practice, Apply, and up through the Badge tier of Assess, and every single C++ program I typed compiled clean under -Wall -Wextra and matched the documented output on the first try. That's a genuine compliment to how tightly the four beats reinforce each other: the validation-loop pattern gets shown in Learn, rehearsed as a prediction in Practice, typed by me in Apply, and then I write it unprompted in Assess -- by the fourth exposure it's not memorization, it's just understanding, exactly like the reading's Common Questions section promises it will be.
>
> Two things tripped up my literalism, and both are process, not content. First, every git pull and the final git push failed with the exact same root cause: this worktree branch has no upstream tracking configured. I hit it at the start of Apply Part 2, at the start of Assess ('Getting Started'), and again at Submission step 4 -- three separate places in the student-facing material that assume git pull/push just work. As a literalist I don't invent the --set-upstream fix on my own, so if I were a real cohort student hitting this on my very first push of the semester, I'd be stuck at the finish line with a complete, correct, tested submission that never reaches GitHub. Worth checking whether the worktree provisioning script sets tracking branches for real cohort spawns, because the material gives no fallback instruction for this error.
>
> Second, the apply-menu-scaffold.cpp file that Part 2's Investigate movement hands me and says 'read it before you write anything' contains a bare `continue;` on line 75, inside the switch's default case -- and nothing in learn.md or apply-tutorial.md ever names or explains `continue`. It's explained later, but only in assess-lab.md's A-tier spec, which I hadn't read yet. I traced around it fine by inference, but a student told to 'trace one path out loud as a class' on code containing an unexplained keyword is going to stall exactly where the instructions assume confidence.
>
> Neither of these broke anything I built -- Part 1, Part 2 C/B/A tier, and the Badge trace table + prompts.md are all done and verified. I just couldn't get the final `git push` to land.

**Self-reported timing:** Learn: ~30 min (reading + typing/compiling all 5 examples + hand-tracing). Practice: ~15 min (7 cold answers + key diff). Apply: ~55-60 min (Part 1 three staged type-ins + Deliberate Break, Part 2 investigate/spec-review/make + acceptance checks). Assess: ~2.5 hours (Part 1 three exercises, Part 2 C+B+A tiers, Badge trace table + prompts.md, submission attempt). Total: roughly 4-4.5 hours end to end.

**Break-character (self-reported):** Two small ones, both procedural rather than content: (1) I used `sed`/shell scripting to quickly generate the two extra Exercise-3 test variants (target=41, target=99) instead of manually editing and rebuilding the file twice by hand the way a Chromebook/Codespaces student would click through. (2) The 'Chromebook only, Codespaces is my only path' framing in my persona sheet doesn't actually bind in this sandboxed tool environment -- I have direct terminal access already, so I never hit any of the friction a real Chromebook-bound student would (browser tab-switching, Codespaces cold-start, copy-paste between panes). I did not fabricate that friction; I just note it wasn't tested.

**Exit ticket, cold:** `1B 2B 3C 4D 5C 6B 7A` → **7/7**


---

## Dee — the Rules-Lawyer (dungeon canon, sonnet)

**Tier reached:** Badge

> Dear M5 author,
>
> I read every word before I touched a compiler, the way I always do, and I want to say up front: this module is unusually tight. I went in looking for a place to plant a defensible-but-unintended flag and mostly came up empty, which is rare enough to be worth saying plainly rather than manufacturing a complaint to fill the letter.
>
> Two places where the contract actually has a gap, not a gotcha:
>
> First, B tier's second validated read: "It gets the same bulletproofing the menu read got: bad type re-prompts, bad range re-prompts." Nowhere -- not the requirement text, not the sample run, not the Testing table -- is the valid range for the barkeep's gold offer ever stated. The menu's range (1-3) is pinned by the menu itself having three options; the gold offer has nothing pinning it. I picked 0-100 because I had to pick something. Worse, the published Testing table's only B-tier row sends `banana` at the barkeep's prompt -- it never tests an out-of-range number there. A submission that validated type only, with no range check at all, would pass every row a student is told to run while failing the requirement sentence a grader is presumably checking against. Publish a number, add a row to the Testing table, or drop "bad range re-prompts" from B tier and let A tier's `offer > gold` check own that story.
>
> Second, the Submission rubric row says prompts.md is required "if AI was used," but the Badge tier says to submit it unconditionally, with explicit instructions for the no-AI case. Taken literally, a no-AI Badge submission could skip prompts.md at zero Submission-column cost -- which contradicts the Badge tier's own "submit both" language two sections earlier.
>
> Everything else held up under a genuinely adversarial read. My cold exit-ticket answers matched the key 7/7. Every staged type-in in Apply matched its documented output byte for byte, including the off-by-one Break. Both lab acceptance grids passed clean on the first honest attempt at C, B, and A. I did trip myself twice -- feeding a validation loop too few lines of piped input and watching it spin at EOF -- but that is exactly the gotcha your own answer key already documents and warns future test-writers about. That tells me the material anticipated its own reader better than I anticipated it.
>
> — Dee

**Self-reported timing:** Learn: ~20 min (full read + 6 programs typed, compiled, and run). Practice: ~15 min (cold-answer all 7 first, then type/compile/run all 8 programs including the two intentionally-hanging ones under timeout, then diff against the key). Apply: ~50 min (Part 1's three staged type-ins plus the Deliberate Break, all verified byte-for-byte; Part 2's read-the-scaffold, run-the-hang, then write-and-verify the validation loop against all four acceptance rows) -- close to the tutorial's own 55-minute estimate. Assess: roughly 150 min total (Part 1's three exercises correct on first compile, ~20 min; Part 2 C tier's validation loop and four-row acceptance check, ~30 min including the EOF-spin self-inflicted bug; B tier's second validated read, ~15 min; A tier's carried-gold/decision/continue seam plus multi-turn verification, ~35 min; Badge's trace table and prompts.md, ~20 min) -- roughly in line with the lab's own 90+20+35-minute C+B+A estimate, plus Badge time on top.

**Break-character (self-reported):** To plan this run I read learn.md, apply-tutorial.md, and assess-lab.md in full before writing any code, which means I saw the Learn reading's <details>/<summary> reveal answers, the Apply tutorial's 'Expected output' blocks, and the lab's sample runs before the material's own predict-then-reveal ritual intended me to. I did keep the one genuinely load-bearing prediction honest -- the 7-item exit ticket cold answers were written down before opening the key, exactly as instructed, and that diff is real signal. But the beat-internal 'predict this line, then scroll' moments inside Learn and Apply were compromised by having already read ahead; a first-time student reading top-to-bottom would not have this problem. Also: prompts.md says 'I used no AI,' which is the honest in-character answer for the persona but is structurally funny coming from an AI agent typing the whole lab -- noted here per the instruction to flag it rather than quietly launder it.

**Bugs written:**

- *m5-student-work/ -- manual acceptance test 4 for m5_apply.cpp (Apply Part 2)* — Piped only 'banana\n9\n2\n' (3 lines) expecting the program to recover and finish, but the program still needed a 4th line (the '3' to leave). With no more input, cin hit EOF, cin.clear() cleared the EOF flag, cin.ignore() immediately hit EOF again, and the validation loop spun forever -- not a defect in my validation code, a defect in my test harness. (found: The spin exactly matched the 'Instructor note: testing these programs from a script' section of practice-exit-ticket-key.md, which names this precise EOF-spin gotcha and prescribes a hard timeout plus one-input-per-line piping. Re-ran with 'banana\n9\n2\n3\n' and it passed cleanly.)
- *m5-student-work/m5lab-game.cpp -- manual test of the barkeep's out-of-range offer (999)* — Piped '2\n999\n3\n' intending the final 3 to quit the menu. Since 999 failed the offer<=100 range check, the validation loop consumed the '3' as the retried offer instead (3 is in range, gets the 'insult' reply), leaving no input for the next menu prompt -- which then spun at EOF exactly as in the bug above. (found: Same EOF-spin signature as the first bug. Re-ran with '2\n999\n40\n3\n' (an extra line) and got the correct behavior: re-prompt on 999, accept 40, generous reply, clean exit on 3.)

**Exit ticket, cold:** `1B 2B 3C 4D 5C 6B 7A` → **7/7**


---

## Jaylen — the Skimmer (streamer/esports skin, haiku)

**Tier reached:** B (Assess: C tier fully complete for both Part 1 and Part 2, plus B tier for Part 2 barkeep validation)

> I crushed Module 5. Took 90 minutes end-to-end, got 7/7 on the exit ticket without peeking, typed out the Level Up Stats program all the way through (the last full type-in!), and hit B tier on the lab (C tier core plus a second validation loop). I skimmed the reading hard but caught the key concepts — three loop types, trace tables, off-by-one is Logic not Runtime, and the cin validation pattern. The Apply tutorial was the perfect confidence-builder; I did Part 1 type-in-100% to warm up, then moved straight into the finish-the-80% Part 2 and got all four acceptance tests passing. By the time I hit the lab, I was rolling — Part 1 exercises were straightforward (while for health, for for days, for for search), and Part 2 validation was a copy of what I'd just written in Apply. I got through B tier (second validation in the barkeep action) but didn't push to A tier (would've needed to refactor to track gold across turns with a decision inside the loop). That's a fair stop point — C is the core competency, B proves I can use the pattern twice, A would be another 35 minutes and I'd already hit the 90-minute mark. The loop-wrap-decides seam is the whole point of M5, and I feel it now. In M4 a decision ended the program; in M5 it just returns to the menu. No trick questions, just clean work.

**Self-reported timing:** 90 minutes total: Learn 5 min, Practice exit ticket 15 min, Apply Part 1 type-in 15 min, Apply Part 2 finish-80% 15 min, Assess warmup 15 min, Assess game C tier 10 min, Assess game B tier 5 min

**Break-character (self-reported):** none

**Bugs written:**

- *None found* — All code compiles clean with zero warnings. All tests pass. All output matches expected. (found: Compiled with g++ -std=c++17 -Wall -Wextra and ran test cases.)

**Exit ticket, cold:** `1B 2B 3C 4D 5C 6B 7A` → **7/7 (100%)**


---
