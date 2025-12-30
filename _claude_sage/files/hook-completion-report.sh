#!/bin/bash
# hooks/completion-report.sh
# Stop hook - runs when Claude finishes responding
# Reports completion status and readiness for review
#
# This hook provides a summary rather than blocking.
# It helps ensure nothing is forgotten before moving to PR.
#
# Exit codes:
#   0 = Report generated (informational, never blocks)

# ============================================
# GATHER COMPLETION DATA
# ============================================

REPORT=()
CHECKS_PASSED=0
CHECKS_FAILED=0
CHECKS_WARNED=0

# Helper function to add check results
check_pass() {
    REPORT+=("  ✅ $1")
    ((CHECKS_PASSED++))
}

check_fail() {
    REPORT+=("  ❌ $1")
    ((CHECKS_FAILED++))
}

check_warn() {
    REPORT+=("  ⚠️  $1")
    ((CHECKS_WARNED++))
}

# ============================================
# GIT STATUS CHECKS
# ============================================

REPORT+=("")
REPORT+=("📋 GIT STATUS")

# Check if we're in a git repo
if git rev-parse --is-inside-work-tree &>/dev/null; then
    
    # Check current branch
    CURRENT_BRANCH=$(git branch --show-current 2>/dev/null)
    if [ -n "$CURRENT_BRANCH" ]; then
        if [ "$CURRENT_BRANCH" = "main" ] || [ "$CURRENT_BRANCH" = "master" ]; then
            check_warn "On protected branch: $CURRENT_BRANCH (should use feature branch)"
        else
            check_pass "On feature branch: $CURRENT_BRANCH"
        fi
    fi
    
    # Check for uncommitted changes
    UNCOMMITTED=$(git status --porcelain 2>/dev/null | wc -l)
    if [ "$UNCOMMITTED" -gt 0 ]; then
        check_warn "$UNCOMMITTED uncommitted changes (commit before PR)"
        
        # List changed files
        CHANGED_FILES=$(git status --porcelain 2>/dev/null | head -5)
        while IFS= read -r line; do
            REPORT+=("      $line")
        done <<< "$CHANGED_FILES"
        if [ "$UNCOMMITTED" -gt 5 ]; then
            REPORT+=("      ... and $((UNCOMMITTED - 5)) more")
        fi
    else
        check_pass "All changes committed"
    fi
    
    # Check for unpushed commits
    UNPUSHED=$(git log @{u}.. --oneline 2>/dev/null | wc -l)
    if [ "$UNPUSHED" -gt 0 ]; then
        check_warn "$UNPUSHED unpushed commits"
    else
        # Check if upstream exists
        if git rev-parse --abbrev-ref @{u} &>/dev/null; then
            check_pass "All commits pushed"
        else
            check_warn "No upstream branch set"
        fi
    fi
    
    # Recent commits summary
    RECENT_COMMITS=$(git log --oneline -3 2>/dev/null)
    if [ -n "$RECENT_COMMITS" ]; then
        REPORT+=("")
        REPORT+=("  Recent commits:")
        while IFS= read -r line; do
            REPORT+=("    $line")
        done <<< "$RECENT_COMMITS"
    fi
    
else
    check_warn "Not in a git repository"
fi

# ============================================
# CONTENT CHECKS
# ============================================

REPORT+=("")
REPORT+=("📝 CONTENT STATUS")

# Check for recently modified content files
CONTENT_FILES=$(find . -name "*.md" -newer .git/index 2>/dev/null | grep -E '(content|readings|labs|tutorials)' | head -10)
if [ -n "$CONTENT_FILES" ]; then
    check_pass "Modified content files:"
    while IFS= read -r file; do
        # Get word count
        WC=$(wc -w < "$file" 2>/dev/null || echo "?")
        REPORT+=("    $file ($WC words)")
    done <<< "$CONTENT_FILES"
else
    check_warn "No recently modified content files found"
fi

# Check for any TODO markers in modified files
if [ -n "$CONTENT_FILES" ]; then
    TODO_FILES=$(echo "$CONTENT_FILES" | xargs grep -l 'TODO\|FIXME\|XXX' 2>/dev/null || true)
    if [ -n "$TODO_FILES" ]; then
        check_warn "Files with TODO markers:"
        while IFS= read -r file; do
            TODO_COUNT=$(grep -c 'TODO\|FIXME\|XXX' "$file" 2>/dev/null || echo "0")
            REPORT+=("    $file ($TODO_COUNT TODOs)")
        done <<< "$TODO_FILES"
    fi
fi

# ============================================
# VALIDATION STATUS
# ============================================

REPORT+=("")
REPORT+=("🔍 VALIDATION")

# Check if validation log exists
LOG_FILE=".claude/logs/write-log.csv"
if [ -f "$LOG_FILE" ]; then
    # Get today's entries
    TODAY=$(date +%Y-%m-%d)
    TODAY_WRITES=$(grep "^$TODAY" "$LOG_FILE" 2>/dev/null | wc -l)
    TODAY_WARNINGS=$(grep "^$TODAY" "$LOG_FILE" 2>/dev/null | awk -F, '{sum+=$NF} END {print sum+0}')
    
    if [ "$TODAY_WRITES" -gt 0 ]; then
        check_pass "$TODAY_WRITES files written today"
        if [ "$TODAY_WARNINGS" -gt 0 ]; then
            check_warn "$TODAY_WARNINGS total warnings generated"
        fi
    fi
else
    REPORT+=("  ℹ️  No validation log found (first run?)")
fi

# ============================================
# PR READINESS ASSESSMENT
# ============================================

REPORT+=("")
REPORT+=("🚀 PR READINESS")

if [ "$CHECKS_FAILED" -eq 0 ] && [ "$UNCOMMITTED" -eq 0 ] && [ "$CURRENT_BRANCH" != "main" ] && [ "$CURRENT_BRANCH" != "master" ]; then
    check_pass "Ready for Pull Request!"
    REPORT+=("")
    REPORT+=("  Suggested PR title:")
    
    # Try to generate title from branch name
    if [ -n "$CURRENT_BRANCH" ]; then
        PR_TITLE=$(echo "$CURRENT_BRANCH" | sed 's/-/ /g' | sed 's/content\///g' | sed 's/fix\///g')
        REPORT+=("    $PR_TITLE")
    fi
else
    check_warn "Address issues above before PR"
fi

# ============================================
# OUTPUT REPORT
# ============================================

echo ""
echo "╔════════════════════════════════════════════════════════════════╗"
echo "║              COMPLETION REPORT                                 ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo ""

for line in "${REPORT[@]}"; do
    echo "$line"
done

echo ""
echo "────────────────────────────────────────────────────────────────"
echo " Summary: $CHECKS_PASSED passed | $CHECKS_WARNED warnings | $CHECKS_FAILED issues"
echo "────────────────────────────────────────────────────────────────"
echo ""

# ============================================
# NEXT STEPS SUGGESTION
# ============================================

if [ "$CHECKS_FAILED" -gt 0 ]; then
    echo "📌 Next: Address failed checks above"
elif [ "$CHECKS_WARNED" -gt 0 ]; then
    echo "📌 Next: Review warnings, then 'git push' and open PR"
else
    echo "📌 Next: 'git push' and open PR for review"
fi

echo ""

exit 0
