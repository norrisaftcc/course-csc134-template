# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a development repository for CSC134 (C++ Programming) course materials, designed with a focus on problem-based learning and experiential methods.

## Project Structure

The repository currently contains:
- `0_Introduction/` - Introductory module with Codespaces setup, GitHub workflow, and budget calculator example
- `1_Variables_and_IO/` - Complete module with 4 assignments (M1T1, M1T2, M1LAB, M1HW1)
- `materials/` - Course materials including style guides and planning documents
- `materials/legacy/` - Previous course materials for reference
- `csc134-outline.md` - 16-week course structure

## Development Guidelines

Since this is a course development repository focusing on problem-based learning:
- When creating C++ examples, prioritize real-world problems and practical applications
- Design exercises that encourage experiential learning through hands-on coding
- Structure content to build incrementally from fundamental concepts

## C++ Development Commands

When working with C++ code in this repository:
- To compile a single C++ file: `g++ -std=c++17 -Wall -Wextra filename.cpp -o filename`
- To run compiled programs: `./filename`
- For debugging builds: `g++ -std=c++17 -Wall -Wextra -g filename.cpp -o filename`

## Course Development Focus

This course emphasizes:
- Problem-based learning approach
- Experiential teaching methods
- Building C++ knowledge from first principles
- Compatibility with different learning styles (visual, aural, experiential)

## Development Workflow

**CRITICAL**: This repository models professional GitHub workflow for students. ALL development must follow these practices:

### Issue-Driven Development
1. **Create GitHub Issues FIRST** for any work to be done:
   - New module development
   - Assignment improvements
   - Bug fixes
   - Documentation updates
2. **Use descriptive issue titles** following pattern:
   - "Module X: [Brief description]"
   - "Fix: [What needs fixing]"
   - "Enhancement: [What to improve]"
3. **Include in issue body**:
   - Overview/context
   - Task checklist
   - Success criteria
   - Related issues/PRs

### Pull Request Workflow
1. **Create feature branches** for all work:
   - Branch naming: `feature/module-X-name` or `fix/issue-description`
   - Never commit directly to main
2. **Link PRs to Issues**:
   - Reference issue number in PR description
   - Use keywords: "Closes #X" or "Fixes #X"
3. **PR descriptions must include**:
   - What changes were made
   - Why changes were necessary
   - Testing performed
   - Screenshots if UI/output changes

### Commit Standards
- Use clear, descriptive commit messages
- Follow conventional commits when possible:
  - `feat: Add Module 2 selection statement assignments`
  - `fix: Correct calculation in coffee shop POS`
  - `docs: Update README with new module structure`
- Include co-authorship when working with AI tools

### Current Workflow Status
- ✅ Issues created retroactively for Modules 0-1 (Issues #3-#8)
- ✅ Module 1 completed with comprehensive assignments
- 🚧 Module 2 planning tracked in Issue #6
- 📋 All future work requires issues before implementation

This "eat our own dogfood" approach ensures students see and learn professional development practices through example.

## Student Environment

Students will work in GitHub Codespaces:
- Early exercises include environment customization (IDE themes, extensions) to engage personal preferences
- Codespaces configuration should be tested as part of course development
- Consider creating .devcontainer configurations for consistent environments

## Pedagogical Considerations

When developing content, ensure compatibility with multiple learning styles:
- **Visual learners**: Include diagrams, flowcharts, and visual debugging examples
- **Aural learners**: Consider adding video explanations or audio walkthroughs
- **Experiential learners**: Emphasize hands-on coding and immediate feedback loops

## Course Development Progress

### Completed Modules
- **Module 0: Introduction** - Codespaces setup, GitHub workflow practice, budget calculator problem
- **Module 1: Variables and Basic I/O** - Four comprehensive assignments with real-world problems:
  - M1T1: Development environment setup ("Your First Day as a Developer")
  - M1T2: Variables and formatting ("Digital Business Card")
  - M1LAB: Calculations and business logic ("Coffee Shop POS System")
  - M1HW1: User input and analysis ("Student Budget Analyzer")

### Module Pattern Established
Each module should include:
1. Problem-based main example (not abstract concepts)
2. GitHub workflow practice (issues, PRs)
3. Multiple learning style support
4. Hands-on exercises with modifications
5. Clear learning objectives and completion criteria

### Technical Standards
- All C++ examples must compile with: `g++ -std=c++17 -Wall -Wextra`
- Test all code in Codespaces environment
- Include both the problem and solution approaches