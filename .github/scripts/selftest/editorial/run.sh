#!/usr/bin/env bash
#
# Self-test for the Editorial gate.
#
#     bash .github/scripts/selftest/editorial/run.sh
#
# A gate that cannot fail is not a gate (ADR-014). The editorial gate ships in
# advisory mode (ADR-016), so its failure paths only exist behind FAIL_ON_GRADE
# and FAIL_ON_LONG_SENTENCE. This proves each of them fires when it should and
# stays quiet when it should not -- one fixture per behaviour, including the one
# that matters most: prose-only scoring must ignore code, or the whole measure is
# the readability analog of "diffing text no student ever sees" (ADR-015).

set -uo pipefail
cd "$(git rev-parse --show-toplevel)" || exit 2

BASE=".github/scripts/selftest/editorial"
GATE="python3 .github/scripts/editorial-gate.py"

BOLD=$'\033[1m'; RED=$'\033[31m'; GREEN=$'\033[32m'; DIM=$'\033[2m'; OFF=$'\033[0m'
if [ ! -t 1 ] && [ -z "${GITHUB_ACTIONS:-}" ]; then BOLD=""; RED=""; GREEN=""; DIM=""; OFF=""; fi

fails=0

# expect <must-pass|must-fail> <dir> <extra-env> <what it proves>
expect() {
  local want="$1" dir="$2" env="$3" what="$4" out rc
  out="$(env SEARCH_PATHS="$BASE/$dir" $env $GATE 2>&1)"; rc=$?

  if [ "$want" = "must-pass" ] && [ "$rc" -ne 0 ]; then
    printf '  %sBROKEN%s  %-16s expected PASS, got exit %d — %s\n' "$RED" "$OFF" "$dir" "$rc" "$what"
    echo "$out" | sed 's/^/           /'; fails=$((fails+1)); return
  fi
  if [ "$want" = "must-fail" ] && [ "$rc" -eq 0 ]; then
    printf '  %sBROKEN%s  %-16s expected FAIL, gate PASSED it — %s\n' "$RED" "$OFF" "$dir" "$what"
    echo "$out" | sed 's/^/           /'; fails=$((fails+1)); return
  fi
  printf '  %sok%s      %-16s %s\n' "$GREEN" "$OFF" "$dir" "$what"
}

printf '%sEditorial gate self-test%s\n' "$BOLD" "$OFF"

expect must-pass pass         "FAIL_ON_GRADE=1 FAIL_ON_LONG_SENTENCE=1" \
  "warm short-sentence prose clears the bar even enforcing"
expect must-fail high-grade   "FAIL_ON_GRADE=1" \
  "dense academic prose trips FAIL_ON_GRADE"
expect must-fail long-sentence "FAIL_ON_LONG_SENTENCE=1" \
  "one 40-word run-on trips FAIL_ON_LONG_SENTENCE"
expect must-pass long-sentence "FAIL_ON_GRADE=1" \
  "...and does NOT trip grade alone (the two checks are independent)"
expect must-pass code-ignored "FAIL_ON_GRADE=1 FAIL_ON_LONG_SENTENCE=1" \
  "dense code + inline span are stripped; the easy prose passes"

echo
if [ "$fails" -eq 0 ]; then
  printf '%sAll editorial self-tests passed.%s\n' "$GREEN" "$OFF"; exit 0
else
  printf '%s%d editorial self-test(s) BROKEN.%s\n' "$RED" "$fails" "$OFF"; exit 1
fi
