# M5 cohort round 1 — run plan

**Issue:** #21 · **Branch:** `cohort/m5-round1` · **Opened:** 2026-07-31
**Precedent:** [[F-005-m4-cohort-round1]] (how M4 ran) · [[F-006-m4-fixes-and-ready]] (what it cost to close)
**Status:** plan frozen, run not yet executed

M5 (Loops) is `Built`, not `Ready`. Its ledger (F-007) is a **build record, not a field
record** — no student, synthetic or otherwise, has taken it. This round is the depth gate
ADR-016 deferred, and it is the last thing standing between M5 and `Ready`.

---

## 0. The constraint this plan bends, stated plainly

Issue #21 says, in its own words:

> This round should be run **semi-interactively**, with a human in the loop watching the
> personas work rather than a fire-and-forget fan-out.

**A workflow fan-out is the thing that sentence rules out.** This plan runs one anyway,
under an explicit authorisation to use up to four agents, and moves the human checkpoint
rather than deleting it:

| | Issue #21's shape | This round |
|---|---|---|
| Before the run | — | **This plan, in a draft PR, read before anything executes** |
| During the run | Human watches personas work | Personas run unattended in isolated worktrees |
| After transcripts | — | **Hard stop.** Verbatim transcripts + synthesis land in the PR. No issues filed, no fixes, no `Ready`. |
| Fix PR + `Ready` | Human review | Unchanged — human review, separate PR |

What the original constraint was protecting is **M5 not being certified `Ready` on an
agent's say-so**, and that is fully preserved: this round cannot certify anything. What is
genuinely lost is the chance to catch a persona going off-script *mid-run* and correct it.
The mitigation is that the transcripts are verbatim and the synthesizer's job includes
flagging any persona that broke character — but a reader who wanted the live version should
say so, and this plan should be re-run interactively instead.

**This is a deviation from a written instruction, made deliberately, and it is the first
thing a reviewer should agree or disagree with.**

---

## 1. Roster — four agents, and why exactly these

The issue asks for the M4 roster reused *"so findings are comparable across modules."*
Three students plus one synthesizer is four, which is the authorised ceiling and also the
right number — there is no fifth persona approved for cohort runs ([[F-003]]).

| Agent | Persona | Skin | Model | Why this tier |
|---|---|---|---|---|
| 1 | **Maria** — the Literalist | community garden | **sonnet** | F-005's operational lesson: Maria **failed** the structured-output cap at haiku after 54 tool calls. Not a material defect — the schema burden on top of heavy tool use is where haiku drops out. |
| 2 | **Dee** — the Rules-Lawyer | dungeon canon, literal | **sonnet** | F-005's rule is *"escalate the literalist **and any deep-audit persona**."* Dee reads everything and cross-examines the rubric against the spec. She is a deep-audit persona; M4 ran her at haiku by accident of ordering, not by decision. |
| 3 | **Jaylen** — the Skimmer | streamer / esports | **haiku** | Genuinely light: skims headings and code, takes the shortest path the text permits, stops after two pattern-match fixes. Haiku is the honest tier and matches M4. |
| 4 | **cohort-lead** — synthesizer | — | inherit | Consolidates, filters model-noise, answers the watch-list, re-verifies every claim against the text. |

**Worktree isolation is required, not optional.** All three students write `m5lab-warmup.cpp`
and `m5lab-game.cpp` and compile them. Without isolation they overwrite each other and every
transcript is garbage.

---

## 2. What each student does

All four beats, in order, as a student would meet them:

`learn.md` → `practice-exit-ticket.md` → `apply-tutorial.md` → `assess-lab.md`

Non-negotiables carried from F-005:

- **Real `g++ -std=c++17 -Wall -Wextra`.** Compile every program. Paste verbatim output —
  never describe it.
- **Verbatim confusion.** The M4 round's value was in the transcripts, not the pass/fail.
  Quote the exact instruction that failed you.
- **Answer the exit ticket cold**, before looking at `practice-exit-ticket-key.md`. Record
  your answers, then diff against the key. A persona that peeks produces no signal.
- **Stay in character.** Maria does not infer missing steps. Jaylen does not read the prose
  on the first pass. Dee argues only from the record.
- **Students never fix material.** They report. Evaluation is the synthesizer's job.

---

## 3. The watch-list — six questions this round exists to answer

Straight from #21. The synthesizer must answer **each one explicitly**, including
"no evidence either way," which is a real answer.

1. **Does the SPLIT Apply session land?** M5 is the only module where the Make gradient
   shifts mid-class — Part 1 FULL type-in → Part 2 EIGHTY gap. Do students arrive at Part 2
   still waiting to be told what to type?
2. **Is A tier overloaded?** Open review question from #20. A demands three distinct ideas
   on top of B: carry a value across turns, an M4 decision chain inside the loop, and
   `continue` for a second chance. **Settle it with evidence, not argument.**
3. **Does anyone actually write `&&` for `||`?** Predicted as the highest-yield error —
   compiles clean, reads plausibly, silently disables all validation. **If no persona
   produces it, the prediction in `assess-lab.md`'s troubleshooting is unearned and should
   be reported as such.** A prediction that never fires is a finding about the prediction.
4. **Is the ~90-minute C-tier estimate right?** Part 1 is three separate small programs. If
   the estimate is wrong it is probably wrong low.
5. **Do exit-ticket Items 4 and 5 land as a pair?** Logic vs Runtime — "finished and lied"
   vs "never finished," placed adjacent on purpose. Does the contrast land, or do students
   miss both?
6. **Does anyone fill in the trace tables?** They are ungraded scratchpads by design. If
   nobody uses them, that design needs revisiting **before Badge tier depends on one** —
   and Badge already does.

---

## 4. The synthesizer's job, and the trap it must avoid

**Filter model-noise.** F-005 caught two persona "findings" that asked for something the
material already said — one asked for a sentence that appears **twice** in the very file
being reviewed. A synthetic student praising or requesting a thing that is already there is
an artifact of the model, not a signal about the material.

**So: every promoted finding gets re-verified against the actual file before it is
written down.** Quote the text, or drop the finding. A finding that survives is one where
the synthesizer went and looked.

Also required:

- **Convergence vs divergence.** Where all three personas hit the same wall, that is the
  strongest signal available. Where one did and two did not, say which and why.
- **Break-character check.** Flag any persona that stepped outside its sheet — Maria
  inferring a missing step, Jaylen reading prose he would have skimmed. Their findings are
  suspect and must be marked.
- **Severity split**, exactly as M4: `should-fix` vs `nit`.
- **A verdict**, in M4's vocabulary: `ready-with-fixes` / `needs-work` / `blocked`.

---

## 5. Deliverables — and what is deliberately *not* here

**In this PR:**

- `_tracking/cohort/m5-round1/PLAN.md` — this file, frozen before the run
- `_tracking/cohort/m5-round1/feedback.md` — verbatim persona feedback, M4's shape
- `_lore/findings/F-017-m5-cohort-round1.md` — the finding (satisfies the merge gate)
- Draft issue text for each `should-fix`, in the PR body, ready to file

**Explicitly NOT in this PR, and not by oversight:**

- **Issues are not filed.** #21's definition of done asks for them, and they will be filed —
  *after* a human reads the synthesis. Auto-filing a batch of issues off an unreviewed
  agent run is the fire-and-forget behaviour #21 objected to.
- **No fixes.** Findings are recorded, not repaired. A round that fixes what it finds cannot
  be checked against what it found.
- **M5 is not certified `Ready`, and `MODULES.md` is not touched.** That is the follow-on
  PR, after every `should-fix` is closed. #21 is explicit: *"Do not certify M5 Ready before
  this runs"* — and running it is necessary, not sufficient.

---

## 6. How to check this round was honest

- Every compiler claim in the findings has verbatim output behind it.
- Every promoted finding quotes the text it is about.
- All six watch-list questions answered, including the unglamorous "no evidence."
- Both gates still green: `compile-gate.sh` and `markdown-gate.sh` — this round adds
  Markdown and student artifacts, and **must not add an un-annotated ` ```cpp ` fence**
  (ADR-015; the gate went green at 71/71 in #45 and stays that way).

**The failure mode to watch for:** three synthetic students agreeing that a module is good.
M4's round produced that shape and it was *mostly* right — but the finding that mattered
most (two files quoting the same compiler warning differently) came from the synthesizer
re-compiling the claim himself, not from any student's praise. **Convergent approval is the
weakest evidence in this process.** If this round returns nothing but agreement, the honest
conclusion is that the round was too easy, not that M5 is flawless.
