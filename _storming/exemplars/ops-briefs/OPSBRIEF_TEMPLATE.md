# Module Ops Brief — Template

*Front page for every module. One page. A student who reads nothing else knows what to do, what to build, and what will try to stop them. Replace every ⟨slot⟩; delete nothing else without an ADR.*

---

```text
UNCLASSIFIED // COURSE USE ONLY // READABILITY: 10TH GRADE
```

# OPERATION ⟨CODENAME⟩
### Module ⟨N⟩: ⟨Plain Title⟩ · Weeks ⟨X–Y⟩

> **BLUF:** ⟨2–3 sentences, max. What you will be able to DO when this module ends,
> what you must DELIVER, and what gates you forward. No throat-clearing.⟩

> **New here? "BLUF" means Bottom Line Up Front** — say the conclusion first, details after.
> It comes from military and intelligence writing, where nobody has time to hunt for the point,
> and it's used the same way in engineering and business today. Every module in this course
> opens with one. Steal the habit: your emails, your bug reports, and your prompts to an AI
> all get better when the first sentence is the point. *(This box appears in M0–M2, then retires.)*

## SITUATION
⟨2–4 sentences: where we are on the SDLC arc, what the student already holds from prior
modules, and why this module exists. Reference the arc drawn on day one.⟩

## MISSION
By end of module, you can:
- ⟨MLO N.1, plain language⟩
- ⟨MLO N.2⟩
- ⟨MLO N.3⟩

## EXECUTION (the four beats)
| Phase | What | Deliverable | Gate |
|---|---|---|---|
| **Learn** | ⟨reading/video + predict-the-output⟩ | — | — |
| **Practice** | ⟨exit ticket⟩ | completed ticket | **completion-gated: no ticket, no Apply** |
| **Apply** | ⟨tutorial; FULL or EIGHTY mode per the Make gradient⟩ | working program from the walkthrough | compiles clean |
| **Assess** | ⟨lab/homework name⟩ | ⟨files⟩ | tier attempted: C / B / A / Badge |

## KNOWN THREATS (intel from students before you)
- ⟨Error classes you WILL meet this module, named by the four-word taxonomy⟩
- ⟨Top 2–4 harvested common mistakes — from the findings ledger once cohorts/semesters run⟩
- ⟨The planted trap, if this module has one, stated honestly — no trick questions is policy⟩

## LOGISTICS
- Toolchain: Codespaces or local VSCode + g++ · build: `g++ -std=c++17 -Wall -Wextra -o ⟨name⟩ ⟨name⟩.cpp` · zero warnings
- Files live in: ⟨repo path⟩ · submit: pull → commit → push

## COMMS
- Stuck ⟨X⟩ minutes? ⟨help channel / office hours⟩. Bring the exact error text — quote it, don't describe it.
- AI assistance this module: ⟨status per the AI ladder⟩. Log anything you use in `prompts.md`.

```text
END OF BRIEF // GOOD HUNTING
```

---

## Authoring notes (delete from student copy)

1. **The BLUF is the module.** If you can't write it in 3 sentences, the module isn't scoped yet — that's a spine problem, not a writing problem.
2. **KNOWN THREATS is the harvest's home.** Cohort findings (and later, real-semester findings) feed this section. It gets *truer every run.* First run, seed it from the error taxonomy and the instructor guide's predictions.
3. **The teach-box retires after M2** because by then BLUF is vocabulary. It comes back once, in the M8 brief, as: "Your design document opens with a BLUF. You knew that."
4. Military flavor is a skin. The structure (conclusion first, mission, execution, threats, logistics) must survive re-skinning like everything else. Keep it UNCLASSIFIED and self-aware; we are a taqueria-and-dungeons operation, not an actual SCIF.
5. One page. If it scrolls twice, cut SITUATION first, then LOGISTICS boilerplate (link out instead).
