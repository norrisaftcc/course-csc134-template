# Claude Code Customization Kit: Architecture & Usage Guide

## What This Is

A **reusable framework for building domain-specific Claude Code environments**. Clone it, adapt the skills and hooks to your domain, and get a customized AI development assistant with quality gates and specialized knowledge.

The included example implements a **course content development system** for CSC-113 AI Fundamentals, demonstrating all patterns with production-ready components.

---

## Core Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                     CLAUDE CODE SESSION                         │
├─────────────────────────────────────────────────────────────────┤
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐         │
│  │  CLAUDE.md  │    │   Skills    │    │    Hooks    │         │
│  │  (Context)  │    │ (Knowledge) │    │  (Control)  │         │
│  └──────┬──────┘    └──────┬──────┘    └──────┬──────┘         │
│         │                  │                  │                 │
│         ▼                  ▼                  ▼                 │
│  ┌─────────────────────────────────────────────────────────────┤
│  │              System Prompt + Tool Access                    │
│  └─────────────────────────────────────────────────────────────┤
│                              │                                  │
│                              ▼                                  │
│                    ┌─────────────────┐                         │
│                    │   User Prompt   │                         │
│                    └────────┬────────┘                         │
│                             │                                   │
│         ┌───────────────────┼───────────────────┐              │
│         ▼                   ▼                   ▼              │
│  ┌────────────┐      ┌────────────┐      ┌────────────┐       │
│  │ PreToolUse │      │  Execute   │      │PostToolUse │       │
│  │   Hooks    │ ───▶ │   Tool     │ ───▶ │   Hooks    │       │
│  └────────────┘      └────────────┘      └────────────┘       │
│         │                                       │               │
│         │ exit 2 = BLOCK                       │               │
│         ▼                                       ▼               │
│  ┌─────────────────────────────────────────────────────────────┤
│  │                    Stop Hook                                │
│  │            (Completion validation)                          │
│  └─────────────────────────────────────────────────────────────┤
└─────────────────────────────────────────────────────────────────┘
```

---

## The Three Extension Layers

### Layer 1: CLAUDE.md Files (Always-On Context)

**Purpose**: Project identity, preferences, and constraints that apply to EVERY interaction.

**Loading Hierarchy** (all merged, later overrides earlier):
1. `~/.claude/CLAUDE.md` — User-level defaults
2. `./CLAUDE.md` — Project root context
3. `./.claude/CLAUDE.md` — Project-specific details

**Best Practices**:
- Keep under 2,000 words total across all files
- Front-load the most critical information
- Use for WHO (identity), WHAT (project), HOW (style)
- Don't use for task-specific procedures (that's what skills are for)

**Example Structure**:
```markdown
# Project Identity
[What this project is, who it's for]

# Working Agreements  
[Git workflow, review process, quality standards]

# Voice & Style
[Tone, terminology, audience assumptions]

# Critical Constraints
[Things that must never happen, hard requirements]
```

---

### Layer 2: Skills (On-Demand Knowledge)

**Purpose**: Domain expertise injected only when relevant to the current task.

**Architecture**:
```
.claude/skills/
└── skill-name/
    ├── SKILL.md          # Required: frontmatter + instructions
    ├── scripts/          # Optional: automation scripts
    └── references/       # Optional: extended documentation
```

**SKILL.md Anatomy**:
```yaml
---
name: skill-name
description: "One-line description for LLM matching"
allowed-tools: "Read,Write,Bash,Glob,Grep"  # Tool whitelist
model: "claude-sonnet-4"                     # Optional model override
---

# Skill Name

## When to Use This Skill
[Activation criteria - helps Claude decide when to load]

## Core Instructions
[The actual procedures and knowledge]

## Output Format
[Expected deliverable structure]

## Quality Checklist
[Definition of done]
```

**Progressive Disclosure**:
- **Level 1** (always in context): Only `name` and `description` (~50 tokens each)
- **Level 2** (on activation): Full SKILL.md content loaded
- **Level 3** (on demand): Reference files loaded when skill requests them

This design allows **unlimited skill content** without bloating base context.

**Matching Heuristics**:
Claude decides to activate a skill when:
1. User explicitly mentions the skill name
2. Task description matches skill's `description` field
3. "When to Use" criteria in SKILL.md align with current context

---

### Layer 3: Hooks (Deterministic Control)

**Purpose**: Shell-based gates and automation that execute at specific lifecycle events.

**The 10 Hook Events**:

| Event | Timing | Common Use |
|-------|--------|------------|
| `PreToolUse` | Before any tool executes | Validation, security gates |
| `PostToolUse` | After tool completes | Linting, formatting, logging |
| `Stop` | When Claude finishes responding | Completion validation |
| `SubagentStop` | When subagent returns | Output validation |
| `PreCompact` | Before context compaction | Preserve critical info |
| `UserPromptSubmit` | Before prompt processing | Input enrichment |
| `PermissionRequest` | On permission dialogs | Auto-approve/deny patterns |
| `SessionStart` | Session begins | Initialization |
| `SessionEnd` | Session ends | Cleanup |
| `Notification` | On system notifications | Custom handling |

**Exit Code Semantics**:
- `exit 0` — Success, continue (stdout shown in verbose mode)
- `exit 2` — **BLOCK action**, feed stderr back to Claude
- Any other code — Non-blocking error, log and continue

**Hook Input** (via environment variables):
```bash
$CLAUDE_TOOL_NAME     # e.g., "Write", "Bash", "Read"
$CLAUDE_TOOL_INPUT    # JSON of tool parameters
$CLAUDE_FILE_PATH     # For file operations
$CLAUDE_CONTENT       # For write operations
```

**Hook Output** (JSON to stdout for advanced control):
```json
{
  "permissionDecision": "allow" | "deny" | "ask",
  "updatedInput": { "modified": "parameters" },
  "message": "Feedback to Claude"
}
```

---

## Configuration: settings.json

Location options (checked in order, first found wins):
1. `.claude/settings.local.json` — Personal overrides (gitignored)
2. `.claude/settings.json` — Project settings (committed)
3. `~/.claude/settings.json` — User defaults

**Full Schema**:
```json
{
  "hooks": {
    "PreToolUse": [
      {
        "matcher": "Write",
        "command": "./hooks/validate-before-write.sh"
      },
      {
        "matcher": "Bash\\(npm|yarn\\)",
        "command": "./hooks/log-package-commands.sh"
      }
    ],
    "PostToolUse": [
      {
        "matcher": "Write.*\\.(md|txt)$",
        "command": "./hooks/lint-markdown.sh"
      }
    ],
    "Stop": [
      {
        "matcher": ".*",
        "command": "./hooks/completion-checklist.sh"
      }
    ]
  },
  "permissions": {
    "allow": [
      "Read(**)",
      "Write(content/**)",
      "Bash(npm test)"
    ],
    "deny": [
      "Bash(rm -rf *)",
      "Write(/etc/**)"
    ]
  }
}
```

**Matcher Patterns**:
- Simple string: `"Write"` matches the Write tool
- With arguments: `"Write(*.md)"` matches markdown writes
- Regex: `"Bash\\(git\\s+push\\)"` matches git push commands

---

## Workflow: PR-Based Human Review

This framework assumes **human review at natural completion points** (PRs), not autonomous loops.

```
┌─────────────────────────────────────────────────────────────────┐
│                    SPRINT WORKFLOW                              │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  1. HUMAN: Defines sprint goal                                  │
│     "Write M01 Reading 1: What is AI?"                         │
│                          │                                      │
│                          ▼                                      │
│  2. CLAUDE: Creates feature branch                              │
│     git checkout -b content/m01-reading-1                       │
│                          │                                      │
│                          ▼                                      │
│  3. CLAUDE: Activates relevant skill                            │
│     [reading-generator skill loaded]                            │
│                          │                                      │
│                          ▼                                      │
│  4. CLAUDE: Creates content (hooks validate)                    │
│     PreToolUse → validates structure                            │
│     Write → creates file                                        │
│     PostToolUse → lints markdown                                │
│                          │                                      │
│                          ▼                                      │
│  5. CLAUDE: Commits with conventional message                   │
│     git commit -m "feat(m01): add reading 1 - what is AI"      │
│                          │                                      │
│                          ▼                                      │
│  6. STOP HOOK: Reports completion status                        │
│     ✓ File created                                              │
│     ✓ Frontmatter valid                                         │
│     ✓ Word count: 1,847                                         │
│     ⚠ No learning objectives section                            │
│                          │                                      │
│                          ▼                                      │
│  7. CLAUDE: Opens PR or reports ready for review                │
│                          │                                      │
│                          ▼                                      │
│  8. HUMAN: Reviews PR, provides feedback                        │
│     - Approve → merge                                           │
│     - Request changes → back to step 4                          │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## Adapting to Your Domain

### Step 1: Define Your Project Context

Edit `CLAUDE.md` and `.claude/CLAUDE.md`:
- What is this project?
- Who is the audience?
- What are the quality standards?
- What should never happen?

### Step 2: Identify Knowledge Domains

List the distinct types of work Claude will do:
- CSC-113 example: readings, labs, rubrics, tutorials
- Your domain: ???

Each distinct type becomes a skill.

### Step 3: Create Skills

For each knowledge domain:
1. Create `.claude/skills/your-skill/SKILL.md`
2. Define when it activates
3. Document the procedures
4. Specify output format
5. List quality criteria

### Step 4: Define Quality Gates

Identify validation that should happen automatically:
- What structure must files have?
- What content is required?
- What patterns are forbidden?

Each gate becomes a hook.

### Step 5: Wire It Together

Configure `settings.json` to connect hooks to events.

### Step 6: Test the Workflow

Run Claude Code in the directory:
```bash
cd your-customized-project
claude
```

Give it a representative task and observe:
- Does the right skill activate?
- Do hooks fire correctly?
- Is the output quality acceptable?

Iterate on skills and hooks based on results.

---

## Debugging & Troubleshooting

### Hook Not Firing
1. Check matcher pattern in settings.json
2. Verify script is executable: `chmod +x hooks/*.sh`
3. Run Claude with `--verbose` to see hook execution
4. Test hook directly: `./hooks/your-hook.sh`

### Wrong Skill Activating
1. Check `description` field—is it too generic?
2. Review "When to Use" section—is it specific enough?
3. Try explicit skill invocation: "Use the reading-generator skill to..."

### Content Quality Issues
1. Add more specific instructions to skill
2. Add validation to PreToolUse hook
3. Tighten output format specification
4. Add examples of good vs. bad output

### Hook Blocking Unexpectedly
1. Check exit codes (only `exit 2` blocks)
2. Review stderr output (that's what Claude sees)
3. Add debug logging: `echo "DEBUG: $CLAUDE_FILE_PATH" >> /tmp/hook.log`

---

## File Manifest

```
claude-code-customization-kit/
├── README.md                           # Quick start
├── CLAUDE.md                           # Root context (generic template)
│
├── .claude/
│   ├── CLAUDE.md                       # Project context (your domain)
│   ├── settings.json                   # Hook wiring
│   │
│   └── skills/
│       ├── _template/                  # Skill template to copy
│       │   └── SKILL.md
│       │
│       ├── course-content-writer/      # Example: domain voice
│       │   └── SKILL.md
│       ├── reading-generator/          # Example: specific content type
│       │   └── SKILL.md
│       ├── lab-creator/                # Example: hands-on work
│       │   └── SKILL.md
│       └── rubric-converter/           # Example: structured transformation
│           └── SKILL.md
│
├── hooks/
│   ├── validate-content-structure.sh   # PreToolUse gate
│   ├── lint-and-format.sh              # PostToolUse cleanup
│   └── completion-report.sh            # Stop hook
│
└── templates/
    ├── reading-template.md             # Content scaffolds
    ├── lab-template.md
    └── rubric-template.md
```

---

## Next Steps After Setup

1. **First sprint**: Pick one small deliverable to test the full workflow
2. **Iterate skills**: Refine based on output quality
3. **Tune hooks**: Adjust validation strictness
4. **Document patterns**: Add to CLAUDE.md what works
5. **Share the kit**: Others can clone and adapt

---

## Appendix: Quick Reference

### Skill Frontmatter Fields
| Field | Required | Description |
|-------|----------|-------------|
| `name` | Yes | Identifier (lowercase, hyphenated) |
| `description` | Yes | One-line for LLM matching |
| `allowed-tools` | No | Comma-separated tool whitelist |
| `model` | No | Override model for this skill |

### Hook Exit Codes
| Code | Effect |
|------|--------|
| 0 | Success, continue |
| 2 | Block action, return stderr to Claude |
| Other | Log error, continue |

### Environment Variables in Hooks
| Variable | Available In | Content |
|----------|--------------|---------|
| `CLAUDE_TOOL_NAME` | All | Tool being called |
| `CLAUDE_TOOL_INPUT` | All | JSON parameters |
| `CLAUDE_FILE_PATH` | File ops | Target file path |
| `CLAUDE_CONTENT` | Write ops | Content being written |

### Matcher Pattern Examples
| Pattern | Matches |
|---------|---------|
| `"Write"` | Any Write call |
| `"Write(*.md)"` | Markdown writes |
| `"Bash(git *)"` | Git commands |
| `"Bash\\(npm\\|yarn\\)"` | Package manager commands |
| `".*"` | Everything |
