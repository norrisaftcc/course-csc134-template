
"Check the workforce skill mappings of 
the things we're teaching so far, please"
----
Love this question. Here’s a crisp, defensible mapping from Assignments 00–03 to widely used workforce frameworks (NACE Career Readiness, SFIA, ABET) plus O\*NET “what people do at work.” I kept it practical so you can paste the bullets into your syllabus or program review.

# Workforce skill mappings (Assignments 00–03)

## Assignment 00 — GitHub Setup & Personal Repo

**What students do:** Make an account, create a public repo, author a README, make multiple commits.
**Workforce skills demonstrated**

* Version control fundamentals (init, edit, commit, history) → aligns to **SFIA: Programming/Software development (PROG), L2** (designs/codes/tests simple components; applies basic standards) and **SFIA: Configuration management (CFMG)** (tracking configuration items like source and docs). ([SFIA][1])
* Professional communication (concise commit messages, README writing) → **NACE: Communication**; **Professionalism**. ([Default][2])
* Technology fluency with industry tools (GitHub recognized as a “Hot Technology” across developer roles) → **O\*NET Tools & Technology**. ([O\*NET OnLine][3])

**ABET touchpoints** (early evidence)

* Outcome (3) communicate effectively (README/commit messages).
* Outcome (7) acquire/apply new knowledge (self-setup, docs). ([Bucknell University][4], [UNH Engineering and Physical Sciences][5])

**O\*NET job activities connected**

* “Write computer programming code” / maintain code artifacts; manage version control in typical dev roles. ([O\*NET OnLine][6])

---

## Assignment 01 — Hello, Profile! (I/O, `main`, compile/run)

**What students do:** Write/compile a simple C++ program; run locally or in Codespaces; commit improvements.
**Workforce skills demonstrated**

* Build/run workflow (local VS Code or **GitHub Codespaces**, a common cloud IDE path in industry/edu). ([GitHub Docs][7])
* Basic software construction & testing of simple programs → **SFIA PROG L2**. ([SFIA][1])
* Version control hygiene (incremental commits) → **SFIA CFMG**. ([SFIA][8])
* Clear console prompts/output → **NACE: Communication**, **Technology**. ([Default][2])
* Why we teach Git early: version control is a standard professional practice. ([Atlassian][9])

**ABET touchpoints**

* (1) identify/solve problems (debug simple build/run issues).
* (3) communicate effectively (user prompts, output).
* (7) acquire/apply new knowledge (install toolchain or adopt Codespaces). ([Bucknell University][4], [UNH Engineering and Physical Sciences][5])

**O\*NET job activities connected**

* Using industry platforms (GitHub “Hot Technology”). ([O\*NET OnLine][3])

---

## Assignment 02 — If Only: Achievement Stamps (independent `if`)

**What students do:** Translate pseudocode to C++ with multiple independent `if` checks; test inputs.
**Workforce skills demonstrated**

* Control-flow reasoning & basic logic → **SFIA PROG L2** (designs/codes/tests simple programs and reviews own work). ([SFIA][1])
* Test mindset: try representative & edge inputs (behavioral testing). **NACE: Critical Thinking**; **Technology**. ([Default][2])

**ABET touchpoints**

* (1) problem solving via conditional logic;
* (3) communication via clear, unambiguous output messages (user feedback);
* (7) learn by iteration as students refine conditions. ([Bucknell University][4], [UNH Engineering and Physical Sciences][5])

**O\*NET job activities connected**

* Implement and test small features; analyze program behavior vs. requirements. ([O\*NET OnLine][6])

---

## Assignment 03 — One Choice Only: Grade Reporter (`if/else if/else`, validation)

**What students do:** Translate pseudocode into a mutually exclusive decision chain; add input validation; run edge-case tests.
**Workforce skills demonstrated**

* Defensive programming & input validation → core of software quality; **SFIA PROG L2** and **TEST** adjacent behaviors (verifies/tests). ([SFIA][1])
* Communicating outcomes cleanly (exactly one grade; error messages) → **NACE: Communication**, **Professionalism**. ([Default][2])

**ABET touchpoints**

* (1) solve clearly specified problems (boundary logic);
* (3) communicate effectively (single, correct result and errors);
* (7) apply new knowledge (validation patterns). ([Bucknell University][4], [UNH Engineering and Physical Sciences][5])

**O\*NET job activities connected**

* Implement spec-driven logic; handle invalid inputs; verify behavior with test cases. ([O\*NET OnLine][6])

---

# Crosswalk cheat sheet (quick tags)

* **NACE (2024)**: Career & Self-Development, Communication, Critical Thinking, Equity & Inclusion, Leadership, Professionalism, Teamwork, Technology. (We’re primarily hitting **Technology, Communication, Critical Thinking, Professionalism** in 00–03.) ([Default][2])
* **SFIA (v9/v8)**: **PROG** (Programming/software development) L2; **CFMG** (Configuration management) for version control habits; introduction to **TEST** behaviors via simple verification. ([SFIA][1])
* **ABET outcomes (1)–(7)**: 00–03 give early evidence for **(1)** problem solving, **(3)** communication, and **(7)** learning new tools; teamwork/design-heavy outcomes come later. ([Bucknell University][4], [UNH Engineering and Physical Sciences][5])

---

## Gaps to close next (suggested adds)

* **Branching/merging basics** (short lab): brings in collaboration realism; strengthens SFIA CFMG + NACE Teamwork. ([Atlassian][9])
* **Structured testing** (table of test cases, expected vs. actual): clearer line to ABET (3) communication and to testing behaviors under SFIA PROG/TEST. ([SFIA][1])
* **Issue tracking/readme polish** (screenshots, run instructions): professional artifacts tied to NACE Communication/Professionalism. ([Default][2])
* **Codespaces ergonomics** (devcontainer tweaks later): reinforces cloud dev literacy noted in GitHub Education guidance. ([GitHub Docs][7])

---

## Evidence you can collect (portfolio-friendly)

* Links to GitHub repos showing commit history (Assignment 00–03).
* Screenshots of passing runs + a tiny test table (inputs/outputs).
* One-paragraph reflection: “what I fixed and how I tested it” (maps to NACE Critical Thinking & ABET (7)). ([Default][2], [UNH Engineering and Physical Sciences][5])

If you want, I can drop this into a one-page “Workforce Mapping” handout (with the framework logos and inline citations) and attach it to the Assignment 00–03 doc set.

[1]: https://sfia-online.org/en/sfia-9/skills/programming-software-development?utm_source=chatgpt.com "Programming/software development PROG - Skills"
[2]: https://www.naceweb.org/career-readiness/competencies/career-readiness-defined?utm_source=chatgpt.com "What is Career Readiness?"
[3]: https://www.onetonline.org/search/hot_tech/example?e=GitHub&utm_source=chatgpt.com "Hot Technology: GitHub"
[4]: https://www.bucknell.edu/academics/college-engineering/abet-accreditation?utm_source=chatgpt.com "Engineering ABET Accreditation"
[5]: https://ceps.unh.edu/academics/abet-accreditation?utm_source=chatgpt.com "ABET Accreditation - unh.ceps - University of New Hampshire"
[6]: https://www.onetonline.org/link/summary/15-1252.00?utm_source=chatgpt.com "15-1252.00 - Software Developers"
[7]: https://docs.github.com/en/education/manage-coursework-with-github-classroom/integrate-github-classroom-with-an-ide/using-github-codespaces-with-github-classroom?utm_source=chatgpt.com "Using GitHub Codespaces with GitHub Classroom"
[8]: https://sfia-online.org/en/sfia-9/all-skills-a-z?utm_source=chatgpt.com "SFIA 9 skills directory A–Z"
[9]: https://www.atlassian.com/git/tutorials/what-is-version-control?utm_source=chatgpt.com "What is version control | Atlassian Git Tutorial"
