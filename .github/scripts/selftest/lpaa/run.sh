#!/usr/bin/env bash
#
# Self-test for the LPAA content gate.
#
#     bash .github/scripts/selftest/lpaa/run.sh
#
# A gate that cannot fail is not a gate (ADR-014). That principle bites harder
# here than for either sibling gate, for a specific reason:
#
#   THE LPAA GATE IS GREEN AGAINST THE REAL TREE ON THE DAY IT SHIPS.
#
# The compile gate has a must-warn fixture; the markdown gate shipped red with 23
# real violations to chew through. This one found nothing enforcing on its first
# run, so real material proves nothing about it either way. These fixtures are
# the ONLY evidence that a green run means anything at all.
#
# Each case is a tiny fake module tree — its own MODULES.md and its own modules/
# — so a fixture can claim a status the real repo would never claim.
#
# Run with STRICT=1: the gate ships reporting-only against real content, but a
# self-test that cannot go nonzero would test nothing.

set -uo pipefail
cd "$(git rev-parse --show-toplevel)" || exit 2

BASE=".github/scripts/selftest/lpaa"
GATE="bash .github/scripts/lpaa-gate.sh"

BOLD=$'\033[1m'; RED=$'\033[31m'; GREEN=$'\033[32m'; DIM=$'\033[2m'; OFF=$'\033[0m'
if [ ! -t 1 ] && [ -z "${GITHUB_ACTIONS:-}" ]; then BOLD=""; RED=""; GREEN=""; DIM=""; OFF=""; fi

fails=0

# expect <must-pass|must-fail> <dir> <what it proves>
expect() {
  local want="$1" dir="$2" what="$3" out rc
  out="$(STRICT=1 MODULES_INDEX="$BASE/$dir/MODULES.md" MODULES_ROOT="$BASE/$dir/modules" \
         $GATE 2>&1)"; rc=$?

  if [ "$want" = "must-pass" ] && [ "$rc" -ne 0 ]; then
    printf '  %sBROKEN%s  %-20s expected PASS, got exit %d — %s\n' "$RED" "$OFF" "$dir" "$rc" "$what"
    echo "$out" | sed 's/^/           /'
    fails=$((fails+1)); return
  fi
  if [ "$want" = "must-fail" ] && [ "$rc" -eq 0 ]; then
    printf '  %sBROKEN%s  %-20s expected FAIL, gate PASSED it — %s\n' "$RED" "$OFF" "$dir" "$what"
    echo "$out" | sed 's/^/           /'
    fails=$((fails+1)); return
  fi
  printf '  %sok%s      %-20s %s%s%s\n' "$GREEN" "$OFF" "$dir" "$DIM" "$what" "$OFF"
}

echo "${BOLD}LPAA content gate self-test${OFF}"
echo

expect must-pass pass               "a clean First pass + Built tree passes every check"
expect must-fail status-missing     "Built with no assess-lab.md is caught"
expect must-fail status-stale       "First pass holding a lab is caught — the STATUS is what went stale"
expect must-fail frontmatter-module "learn.md declaring the wrong module is caught"
expect must-fail frontmatter-beat   "learn.md declaring the wrong lpaa_beat is caught"
expect must-fail stale-stub         "NOT YET AUTHORED inside a Ready module is caught (F-014 §5)"
expect must-fail key-leak           "a student beat linking its own answer key is caught"
expect must-fail boundary-missing   "instructor content with no declared boundary is caught (F-018)"
expect must-fail boundary-above     "an instructor block above the boundary is caught"
expect must-pass boundary-ok        "the boundary heading does not flag itself — must-pass twin"

echo
if [ "$fails" -gt 0 ]; then
  echo "${RED}SELF-TEST FAILED${OFF} — $fails case(s) wrong."
  echo "The gate is not behaving as #54 describes. Treat every green run as unverified."
  exit 1
fi
echo "${GREEN}Self-test OK${OFF} — the gate passes what it should and fails what it should."
