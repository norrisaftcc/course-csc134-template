# Phase 0 Open-Question Brief — for human ruling before the M4 deep build

**Author:** spine-owner · **Date:** 2026-07-24 · **Status:** Decision brief. Nothing ruled, nothing moved. Options + recommendations only.

**Purpose.** Four open questions block clean downstream work. Each is framed as options + a recommendation so the human can rule, not decide cold. The two-tree model (ADR-008) is already ratified and excluded. Two-tree layout is assumed throughout: `modules/mN/` is the canonical delivered tree; `assignments/` is frozen provenance that is never edited, moved, or shipped.

**Grounding:** `_storming/CSC-134-course-spine.md`; `_tracking/numbering-reconciliation-map.md` (F-001, OQ1–7); `_lore/decisions/ADR-004/006/007/008`; the on-disk legacy files in `assignments/m0,m1,m2/`.

---

## Q1 — The M1/M2 → M3 remap (the big one)

**Statement.** Legacy `assignments/m1` + `assignments/m2` hold Program-Basics content (variables, I/O, arithmetic) that maps to spine **M3**; spine M1/M2 are new modules. When M3 is built, do all ten legacy files port into `modules/m3/` as M3 artifacts, or are some trimmed, reassigned, or backlogged?

**The ten legacy files** (8 deliverables + 2 module READMEs):

| File | Content | Natural spine home |
|---|---|---|
| `m1/README.md` | Module overview (points-based rubric, IPO framing) | Superseded by M3 build |
| `m1/M1T1_HelloWorld.md` | Env setup + Hello World | **M0** (env setup + hello world is M0's Apply, not M3) |
| `m1/M1T2_DigitalBusinessCard.md` | Variables, formatted output | M3 core |
| `m1/M1LAB_CoffeeShopPOS.md` | Arithmetic, business logic, receipt | M3 core |
| `m1/M1HW1_StudentBudgetAnalyzer.md` | User input, multi-step calc | M3 (heavy) |
| `m2/README.md` | Module overview (Bronze/Silver/Gold rubric) | Superseded by M3 build |
| `m2/M2T1_InteractiveMarketplace.md` | Basic `cin`, input prompts | M3 core |
| `m2/M2T2_RestaurantCalculator.md` | Percentages, `iomanip` formatting | M3 core |
| `m2/M2LAB1_CrateManufacturing.md` | Complex business calc | M3 (heavy) |
| `m2/M2HW1_MultiProgramChallenge.md` | Multi-program, tiered, `std::string` | M3 (heavy) + **rework** — uses Bronze/Silver/Gold/Diamond (conflicts with canonical C/B/A/Badge) and string manipulation (ties to Q2) |

Two structural mismatches make wholesale porting wrong: (a) eight full programs vastly exceed the spine's M3 LPAA, which calls for **one** Apply type-in + **one** Assess-from-spec (Pizza Calculator, spine line 175); (b) these are full spec-driven labs/homework, but M3 sits at the **type-in-100%** end of the Make gradient (spine lines 74–77) — full-spec labs belong to the M5+ finish-the-80% region.

**Options**

- **A — Wholesale port.** All 8 deliverables become M3 artifacts. *Trade-off:* preserves every asset, but overloads M3 with 8 programs, imports the legacy points/Bronze-Silver-Gold rubric that conflicts with C/B/A/Badge, duplicates M0 env-setup (M1T1), and breaks the Make gradient by dropping full labs into a type-in module.
- **B — Curated port + reassign + backlog.** Select a small canonical M3 set aligned to LPAA and the gradient; reassign M1T1 to M0; hold the rest as ranked M3-extension backlog (shelved, not retired). *Trade-off:* matches spine scope and gradient, keeps rubric canon clean; some polished material sits unbuilt; requires per-file curation judgment. **(Recommended.)**
- **C — Rebuild fresh, mine legacy as a quarry.** M3 authored new per spine (Pizza Calculator as canonical Assess); legacy files stay frozen as raw material, nothing ports as-is. *Trade-off:* cleanest fit to spine + ADR-008; but discards the framing that this is a "port," and existing assignments never reach students unless re-authored.

**Recommendation — Option B.** Concretely, a defensible default M3 shape:
- **Apply (type-in):** `M2T1 Interactive Marketplace` or `M1T2 Digital Business Card` (variables + `cin`/`cout` type-in).
- **Assess (from spec):** the spine's named **Pizza Calculator** as the canonical Assess; `M1LAB Coffee Shop POS` or `M2T2 Restaurant Calculator` as the arithmetic alternate.
- **Reassign:** `M1T1 Hello World` → **M0** (env setup + first compile).
- **Backlog (ranked, not retired):** `M1HW1 Budget Analyzer`, `M2LAB1 Crate`, `M2HW1 Multi-Program` (M2HW1 additionally needs rubric-scheme rework and depends on the Q2 `std::string` ruling).

**Where I want a steer:** the *exact* count M3 should carry (a lean 1 Apply + 1 Assess, or a slightly richer set) is a module-weight call that turns on your intent for M3's density. I can execute any target once you name it; the default above is the lean reading of the spine.

**needsADR:** **Yes.** ADR-008 explicitly deferred *what* ports into `modules/m3/` to a "per-module owning ruling." This is that ruling, and it sets the precedent pattern for every future legacy→module port — worth recording as an ADR (or a ruling appendix to F-001).

---

## Q2 — STL / `std::string` + File I/O scope

**Statement.** Legacy manifest M06 (Arrays and Strings — STL, `std::string`) and M07 (File I/O) carry content the current spine has no home for. Descope for alpha, defer to a spine addendum, or fold into an existing module?

**Key facts.** The CCL crosswalk (spine line 340) requires: I/O, iteration, arithmetic, arrays, pointers, filters, OOP. **Neither File I/O nor STL-algorithms is CCL-required** — so there is no compliance risk in dropping them. Spine M7 covers raw/parallel arrays, structs, pointers, classes, but no STL-algorithms and no string-as-a-focused-topic. Important distinction: **incidental `std::string`** (getline, concatenation) is unavoidable and *already present* — legacy M2 uses it, and any menu program uses it — so basic string usage already lives in M3/M5 with no dedicated slot needed. Only the *focused* STL/string topic and File I/O are genuinely homeless.

**Options**

- **A — Descope for alpha entirely.** *Trade-off:* zero compliance risk; keeps the nine-module shape clean; but a silent drop violates "announce, never mutate silently," and loses skills (persistence, string methods) transfer students may value.
- **B — Defer to a spine addendum (post-alpha backlog).** *Trade-off:* records them honestly as "known future," not "cut"; preserves intent without spending alpha effort; costs one addendum stub so nothing is lost.
- **C — Fold into existing modules.** `std::string` light-touch into M3; File I/O into M8 as an optional save/load Badge extension. *Trade-off:* gives them a real home without a new module; but risks bloating M3/M8, and File-I/O-at-M8 would be graded-without-being-taught unless a Learn beat is added — colliding with the spine's own open-question #3 (teach before you grade).

**Recommendation — A executed through B.** Descope both from **alpha build scope**, and record them in a spine addendum as ranked post-alpha backlog, with an explicit note that incidental `std::string` already lives in M3 and needs no dedicated slot. File I/O is not CCL-required, has no taught home, and should be deferred cleanly rather than wedged into M8. This holds the alpha line (M4/M5 depth only) while honoring "version and announce."

**needsADR:** **Yes.** F-001 OQ2 already calls this "a scope ruling, likely its own ADR." Descoping CCL-adjacent content is exactly what the Program Advisor would need on record when defending scope outward.

---

## Q3 — `M6LAB2` landing shape

**Statement.** Does `M6LAB2` (parallel arrays → `Room` struct) land as a standalone file under M7, or get absorbed as `M7LAB1`'s C-tier?

**Key facts.** Neither `M6LAB2` nor `M7LAB1` is a physical file yet (F-001 rows 2–3 confirm no on-disk hit) — this is a design decision, not a migration. The spine describes M7LAB1's **C-tier as exactly** "refactor parallel arrays into a `Room` struct array" (line 248) — i.e. M6LAB2's job — while the Assets table (lines 252, 368) lists the two as separate assets. This touches the **Room/Hero progression** — one of the three Phase 0 interface contracts I own — so the packaging must not fracture the arc.

**Options**

- **A — Absorb `M6LAB2` as `M7LAB1`'s C-tier.** *Trade-off:* most literal reading of the spine, fewest artifacts, one coherent tiered lab tells Room→Hero→Monster→class in one file; but compresses the deliberate "parallel arrays as a felt-pain stepping stone" pedagogy (spine line 240) into a rubric tier rather than its own guided moment.
- **B — Standalone `M7LAB0`, feeding `M7LAB1`.** *Trade-off:* preserves parallel-arrays-as-stepping-stone as a visible artifact; but risks redundancy with M7LAB1's C-tier unless carefully differentiated, and adds an artifact.
- **C — `M6LAB2` becomes M7's Apply-beat exemplar (not a peer lab).** The spine already names an M7 Apply moment: "instructor-led — build a `Room` struct array" (line 247). Repurpose M6LAB2 as that Apply rehearsal; `M7LAB1` stays the sole tiered Assess whose C-tier grades the same refactor. *Trade-off:* cleanest role separation (Apply teaches the move, Assess grades it), no duplication, contract stays singular; requires framing M6LAB2 as Apply content rather than porting it as a lab.

**Recommendation — Option C, with A as the low-effort fallback.** C resolves the apparent two-assets/one-job tension honestly: they are not two labs but the **Apply rehearsal and the Assess performance of the same contract move**. The Room/Hero arc stays intact and singular. If you prefer minimum artifacts, A is fully spine-faithful.

**needsADR:** **No — lightweight call.** This is builder-level packaging *within* an already-ratified contract; the arc itself is unchanged. Record the chosen shape in `modules/m7/_assets.md` per ADR-008; no new ADR needed.

---

## Q4 — `assignments/m0/02_first_pull_request.md`

**Statement.** The live M0 lab teaches the full `Fork → Clone → Branch → Commit → Push → Pull Request → Review → Merge` cycle to Module-0 students (file lines 9–11, 29–37, 87–128), contradicting ADR-004's student flow (commit+push directly, no branches, no PRs before capstone). Rewrite to Mail-Run scope, or grandfather?

**Key facts.** ADR-004 is explicit: student flow = commit+push, no branches/PRs; branching is M8/capstone territory. ADR-006 names the submission loop **the Mail Run** (pull = check the mailbox; commit = box it up **and write the label**; push = hand to the carrier, then check tracking). ADR-007 adds the **Postmark Rule** (commit timestamp = postmark). The M0 file teaches every step ADR-004 rules out, and its own line 122 promises this is "the EXACT workflow you'll use for every assignment" — now false under the Mail Run.

**Framing correction worth surfacing.** The task says "rewrite it," but under **ADR-008 `assignments/` is frozen** — never edited, moved, or shipped by build work. So the mechanism is not "edit the frozen file." It is: **author a fresh Mail-Run-scoped M0 lab in `modules/m0/`** (the delivered tree), and leave the legacy file resting frozen as provenance. Grandfathering-in-place is moot: the frozen file is not what ships. The only real risk is if the frozen file is still being handed to students — it must not be.

**Options**

- **A — Author a Mail-Run M0 lab in `modules/m0/`.** Teaches pull→commit→push, the Postmark Rule line, no fork/branch/PR. Legacy file stays frozen. *Trade-off:* fully aligns delivered M0 with ADR-004/006/007; polished PR walkthrough preserved (frozen) for reuse. **(Recommended.)**
- **B — Grandfather the existing file as-is.** *Trade-off:* contradicts ADR-004 head-on for live students, teaches a capstone skill at M0, and its "exact workflow" promise is now false. Only defensible if you actually want PRs taught early — which would instead require *amending ADR-004*, not grandfathering. Not recommended.
- **C — Reassign the PR content to M8.** ADR-004 places branching at the capstone; the fork/branch/PR walkthrough is genuinely good M8 material. *Trade-off:* preserves the work in its correct home and gives M8 a real workflow lesson. Complements A (A fixes M0; C rehomes the content).

**Recommendation — A + C.** Build the Mail-Run M0 lab in `modules/m0/`; leave `assignments/m0/02_first_pull_request.md` frozen per ADR-008; earmark its fork/branch/PR content as an M8 asset for when branching is actually taught. Do **not** edit the frozen file, and do **not** grandfather it into delivery.

**needsADR:** **No — lightweight call.** The governing decisions already exist (ADR-004/006/007/008); this only applies them. Record in `modules/m0/_assets.md` that `02_first_pull_request.md` does **not** port (reassigned to M8 backlog).

---

## Summary table

| # | Question | Recommendation | needsADR |
|---|---|---|---|
| Q1 | M1/M2 → M3 remap | Curated port (B): lean M3 set, M1T1→M0, rest to ranked backlog | **Yes** (precedent-setting) |
| Q2 | STL/string + File I/O | Descope for alpha, record in addendum (A via B) | **Yes** |
| Q3 | M6LAB2 landing shape | Apply-beat exemplar (C); A as fallback | No (lightweight) |
| Q4 | M0 PR lab | Author Mail-Run M0 in `modules/m0/` (A); rehome PR content to M8 (C) | No (lightweight) |

**One flag for the human:** Q1 is the only question where a per-file curation steer would sharpen the recommendation (how dense should M3 be). Q2–Q4 are ready to rule as framed.
