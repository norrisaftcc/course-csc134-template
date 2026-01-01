# CSC 134 Content Inventory

**Generated:** 2026-01-01
**Purpose:** Map all existing content in `_past_work/` to manifest deliverables

---

## Inventory Legend

| Symbol | Meaning |
|--------|---------|
| ✅ | Content exists and is production-ready |
| 📝 | Content exists in draft form |
| 🔗 | Content exists but needs mapping to manifest |
| ❌ | Content does not exist |
| ⚠️ | Needs attention or verification |

---

## Module 00: Introduction & Environment Setup

**Source:** `_past_work/0_Introduction/`
**Manifest Ref:** M01

### Content Inventory

```
_past_work/0_Introduction/
├── README.md                          🔗 Meta file (not a deliverable)
├── 01_workspace_setup.md              ✅ Tutorial - IDE/Environment Setup
└── examples/
    ├── 02_first_pull_request.md       ✅ Tutorial - GitHub Workflow
    ├── budget_exercises.md            ✅ Exercise - Practice Problems
    └── hello_budget.cpp               ✅ Code Sample - First Program
```

### Manifest Mapping

| Manifest Deliverable | File in _past_work | Status |
|---------------------|-------------------|--------|
| Chapter 1: Introduction to C++ Programming | ❌ Not found | **MISSING** |
| IDE Installation and Setup | `01_workspace_setup.md` | ✅ EXISTS |
| Environment Verification Lab | ❌ Not found | **MISSING** |
| C++ Language Companion (Ch 1) | External resource | ✅ REFERENCE |

### Unmapped Content (exists but not in manifest)
- `02_first_pull_request.md` - **Recommend adding as Lab**
- `budget_exercises.md` - **Recommend adding as Supplementary**
- `hello_budget.cpp` - **Recommend adding as Code Sample**

---

## Module 01: Variables and Basic I/O

**Source:** `_past_work/1_Variables_and_IO/`
**Manifest Ref:** M02

### Content Inventory

```
_past_work/1_Variables_and_IO/
├── README.md                          🔗 Module overview (instructor-facing)
├── module1_plan.md                    🔗 Planning document (internal)
├── M1T1_HelloWorld.md                 ✅ Tutorial - First Program
├── M1T2_DigitalBusinessCard.md        ✅ Tutorial - Variables & Formatting
├── M1LAB_CoffeeShopPOS.md             ✅ Lab - Point of Sale System
└── M1HW1_StudentBudgetAnalyzer.md     ✅ Homework - Full Application
```

### Manifest Mapping

| Manifest Deliverable | File in _past_work | Status |
|---------------------|-------------------|--------|
| Chapter 2: Input, Processing, Output | ❌ Not found | **MISSING** |
| Variables and Data Types Tutorial | `M1T1_HelloWorld.md` + `M1T2_DigitalBusinessCard.md` | ✅ EXISTS |
| Input with cin and getline Tutorial | (covered in M1T2) | ✅ PARTIAL |
| Pizza Calculator Lab | `M1LAB_CoffeeShopPOS.md` (different theme) | ⚠️ THEME MISMATCH |
| Pizza Calculator Rubric | Embedded in M1LAB_CoffeeShopPOS.md | ✅ EXISTS |
| C++ Language Companion (Ch 2) | External resource | ✅ REFERENCE |

### Unmapped Content (exists but not in manifest)
- `M1HW1_StudentBudgetAnalyzer.md` - **MAJOR GAP: Not tracked in manifest**
- `module1_plan.md` - Internal planning (appropriate to exclude)
- `README.md` - Module overview (appropriate to exclude)

### Content Quality Notes

**M1T1_HelloWorld.md:**
- Title: "Your First Day as a Developer"
- Covers: Environment setup, compilation, Git workflow
- Includes: Starter code, step-by-step instructions, rubric
- Size: 6.3 KB

**M1T2_DigitalBusinessCard.md:**
- Title: "Digital Business Card"
- Covers: Variable declaration, data types, output formatting
- Includes: Example output, code templates, rubric
- Size: 10.6 KB

**M1LAB_CoffeeShopPOS.md:**
- Title: "Coffee Shop POS System"
- Covers: Arithmetic operations, business logic, receipt formatting
- Includes: Detailed requirements, sample output, rubric
- Size: 11.3 KB

**M1HW1_StudentBudgetAnalyzer.md:**
- Title: "Student Budget Analyzer"
- Covers: User input, complex calculations, data analysis, recommendations
- Includes: Full rubric, bonus challenges
- Size: 16.2 KB
- **Note:** This is the capstone assignment for the module

---

## Module 02: User Input and Advanced Calculations

**Source:** `_past_work/2_Input_and_Calculations/`
**Manifest Ref:** M03 (Functions) - **MISMATCH**

### Content Inventory

```
_past_work/2_Input_and_Calculations/
├── README.md                          🔗 Module overview (instructor-facing)
├── module2_plan.md                    🔗 Planning document (internal)
├── M2T1_InteractiveMarketplace.md     ✅ Tutorial - User Input Basics
├── M2T2_RestaurantCalculator.md       ✅ Tutorial - Calculations & Formatting
├── M2LAB1_CrateManufacturing.md       ✅ Lab - Business Calculations
└── M2HW1_MultiProgramChallenge.md     ✅ Homework - Tiered Challenge
```

### Manifest Mapping Issue

⚠️ **MAJOR ISSUE:** Module 2 content in `_past_work/` covers **Input and Calculations**, but manifest M03 covers **Functions**. These are different topics.

**Actual M02 content covers:**
- User input (cin, getline)
- Buffer management
- Percentage calculations
- iomanip formatting
- Business logic

**Manifest M03 expects:**
- Function definition
- Parameters and return values
- Scope
- Prototypes

### Manifest Mapping (if treated as separate module)

| Actual Deliverable | Proposed Manifest Entry | Status |
|-------------------|------------------------|--------|
| M2T1_InteractiveMarketplace.md | Tutorial: User Input Basics | ✅ NEW |
| M2T2_RestaurantCalculator.md | Tutorial: Calculations & Formatting | ✅ NEW |
| M2LAB1_CrateManufacturing.md | Lab: Business Calculations | ✅ NEW |
| M2HW1_MultiProgramChallenge.md | Homework: Multi-Program Challenge | ✅ NEW |

### Content Quality Notes

**M2T1_InteractiveMarketplace.md:**
- Title: "Interactive Farmer's Market"
- Covers: Basic cin, input prompts, buffer management
- Unique Feature: Transforms hardcoded values to user input
- Size: 9.4 KB

**M2T2_RestaurantCalculator.md:**
- Title: "Restaurant Bill Calculator"
- Covers: Percentage calculations, iomanip formatting, tip calculations
- Unique Feature: Professional receipt output
- Size: 13.8 KB

**M2LAB1_CrateManufacturing.md:**
- Title: "Crate Manufacturing Case Study"
- Covers: Multi-step problem solving, business logic, 3D geometry
- Based On: Gaddis Chapter 3, Section 3.11
- Size: 13.5 KB

**M2HW1_MultiProgramChallenge.md:**
- Title: "Multi-Program Challenge"
- Covers: Multiple programs with tiered grading
- Unique Feature: Bronze/Silver/Gold/Diamond tier system
- Programs: Banking system, crates update, pizza calculator, spirit generator
- Size: 10.1 KB

---

## Supplementary Content Inventory

### Materials Directory

```
_past_work/materials/
├── legacy/                            Historical course content
│   ├── m1/, m2/, m3/                 Previous module iterations
├── claude_hints/                      AI assistant guidance
│   ├── csc134-16week-outline.md
│   ├── csc134-claude-instructions.md
│   ├── semester2-integration-plan.md
│   └── software-engineering-integration.md
├── canvas/                            LMS integration resources
├── unsorted_samples/                  Example assignments
└── rag_food/                          Research materials
```

### Cathy's Input

```
_past_work/_cathys_input/
├── csc134_assignments0-3.md                              Assignment bundle
├── csc_134_assignment_00_01_git_hub_setup_first_c_program.md
├── csc_134_assignment_02_03_if_statements.md
├── csc_134_assignment_02_03_pseudocode.md
├── csc_134_assignments_00_03_student_first_path_resume_alert_final.md
└── workplace_skill_mappings_0-3.md
```

### Claude's Input (Proposed Structure)

```
_past_work/_claudes_input/
├── 00-course-setup/                   Course foundation materials
├── 01-foundations-week1-2/            Variables and I/O
├── 02-functions-week3-4/              Functions
├── 03-decisions-week5-6/              Decision structures
├── 04-loops-week7-8/                  Loops
├── 05-rpg-integration-week8/          RPG consolidation
├── 06-ai-transition-week9/            AI tools introduction
├── 07-arrays-files-week10-12/         Arrays and File I/O
├── 08-oop-week13-15/                  Object-Oriented Programming
├── 09-portfolio-week16/               Capstone portfolio
├── debugging-bootcamp/                Debugging curriculum
├── resources/                         Shared materials
├── assessments/                       Grading materials
└── instructor-notes/                  Teaching guidance
```

---

## Summary Statistics

### Content by Type

| Type | Count | Total Size | Status |
|------|-------|------------|--------|
| Tutorials | 5 | ~40 KB | All complete |
| Labs | 3 | ~27 KB | All complete |
| Homework | 2 | ~26 KB | All complete |
| READMEs | 3 | ~10 KB | All complete |
| Planning Docs | 2 | ~5 KB | Internal use |
| **Total** | **15** | **~108 KB** | **Production-ready** |

### Manifest Coverage

| Manifest Module | Deliverables Declared | Deliverables Found | Coverage |
|-----------------|----------------------|-------------------|----------|
| M01 (Intro) | 4 | 2 | 50% |
| M02 (Input) | 6 | 4+ | 67%+ |
| M03 (Functions) | 6 | 0* | 0%* |
| M04 (Decisions) | 6 | 0 | 0% |
| M05 (Loops) | 8 | 0 | 0% |
| M06 (Arrays) | 6 | 0 | 0% |
| M07 (Files) | 6 | 0 | 0% |
| M08 (OOP) | 8 | 0 | 0% |

*Note: M02 content in _past_work is about Input/Calculations, not Functions (manifest M03)

---

## Recommended Actions

### Priority 1: Manifest Alignment
1. Revise manifest to include Input/Calculations as separate module
2. Add all M1HW1 and M2 deliverables to manifest
3. Update status of existing deliverables to reflect actual completion

### Priority 2: Content Organization
1. Decide on final folder structure
2. Move content from `_past_work/` to production locations
3. Standardize file naming conventions

### Priority 3: Gap Filling
1. Create missing Chapter readings (or link to textbook)
2. Verify external resources (C++ Language Companion)
3. Complete labs for M00 (Environment Verification)

---

## Change Log

| Date | Change | Author |
|------|--------|--------|
| 2026-01-01 | Initial inventory created | Claude |
