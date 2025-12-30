
# Layout

claude-code-customization-kit/
├── README.md                    # Quick start
├── CLAUDE.md                    # Root context (generic)
├── .claude/
│   ├── CLAUDE.md               # CSC-113 exemplar domain context
│   ├── settings.json           # Hook wiring
│   └── skills/
│       ├── _template/          # Copy this for new skills
│       ├── course-content-writer/    # Voice & philosophy
│       ├── reading-generator/        # Chapter readings
│       ├── lab-creator/              # Hands-on labs  
│       └── rubric-converter/         # Assessment → rubrics
├── hooks/
│   ├── validate-content-structure.sh  # PreToolUse gate
│   ├── lint-and-format.sh            # PostToolUse cleanup
│   └── completion-report.sh          # Stop status report
└── templates/
    ├── reading-template.md
    ├── lab-template.md
    └── rubric-template.md

# Workflow

You: "Create M01 Reading 1: What is AI?"
  ↓
Claude: Creates branch → activates reading-generator skill → writes content
  ↓  
PreToolUse hook: Validates structure (blocks if missing frontmatter)
PostToolUse hook: Lints and logs
Stop hook: Reports readiness status
  ↓
You: Review, comment, approve PR

# To Use

Unzip to your project directory
Run chmod +x hooks/*.sh
Adapt .claude/CLAUDE.md to your domain
Copy _template skill and customize for your content types
Run claude in the directory
