#!/usr/bin/env bash
#
# Self-test for the Markdown block gate.
#
#     bash .github/scripts/selftest/markdown/run.sh
#
# A gate that cannot fail is not a gate (ADR-014). The .cpp gate proves this on
# every run with a fixture that must warn; this is the same idea, one fixture per
# way the Markdown gate is supposed to go red.
#
# It matters more here than there. M4 stays UNMIGRATED in the PR that ships this
# gate, so the convention gets no exercise from real material on day one. These
# fixtures are the only thing standing between "the convention works" and "the
# convention has never been run against its hard cases."

set -uo pipefail
cd "$(git rev-parse --show-toplevel)" || exit 2

BASE=".github/scripts/selftest/markdown"
GATE="bash .github/scripts/markdown-gate.sh"
export GATED_PATHS="$BASE"

BOLD=$'\033[1m'; RED=$'\033[31m'; GREEN=$'\033[32m'; DIM=$'\033[2m'; OFF=$'\033[0m'
if [ ! -t 1 ] && [ -z "${GITHUB_ACTIONS:-}" ]; then BOLD=""; RED=""; GREEN=""; DIM=""; OFF=""; fi

fails=0

# expect <must-pass|must-fail> <dir> <what it proves>
expect() {
  local want="$1" dir="$2" what="$3" out rc
  out="$(SEARCH_PATHS="$BASE/$dir" $GATE 2>&1)"; rc=$?

  if [ "$want" = "must-pass" ] && [ "$rc" -ne 0 ]; then
    printf '  %sBROKEN%s  %-18s expected PASS, got exit %d — %s\n' "$RED" "$OFF" "$dir" "$rc" "$what"
    echo "$out" | sed 's/^/           /'
    fails=$((fails+1)); return
  fi
  if [ "$want" = "must-fail" ] && [ "$rc" -eq 0 ]; then
    printf '  %sBROKEN%s  %-18s expected FAIL, gate PASSED it — %s\n' "$RED" "$OFF" "$dir" "$what"
    echo "$out" | sed 's/^/           /'
    fails=$((fails+1)); return
  fi
  printf '  %sok%s      %-18s %s%s%s\n' "$GREEN" "$OFF" "$dir" "$DIM" "$what" "$OFF"
}

echo "${BOLD}Markdown gate self-test${OFF}"
echo

expect must-pass pass             "exact source=, excerpt=, and an elided source= all match"
expect must-fail drift            "one changed line in a listing is caught (the F-009 class)"
expect must-fail excerpt-missing  "an excerpt that was never in the source is caught"
expect must-fail no-such-source   "source= naming a nonexistent file fails"
expect must-fail unannotated      "a bare cpp block fails — there is no silent default"
expect must-fail gate-verb        "an invented gate= verb is rejected, not tolerated"
expect must-fail ungated          "source= outside the compile gate's trees fails"
expect must-fail elision-only     "a block that is only an elision matches nothing"

echo
if [ "$fails" -gt 0 ]; then
  echo "${RED}SELF-TEST FAILED${OFF} — $fails case(s) wrong."
  echo "The gate is not behaving as ADR-015 describes. Treat every green run as unverified."
  exit 1
fi
echo "${GREEN}Self-test OK${OFF} — the gate passes what it should and fails what it should."
