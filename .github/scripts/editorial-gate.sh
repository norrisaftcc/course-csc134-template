#!/usr/bin/env bash
#
# CSC-134 Editorial gate — entry point.
#
#     bash .github/scripts/editorial-gate.sh
#
# Shaped like compile-gate.sh and markdown-gate.sh: same invocation, same
# dial-as-env-var style, same "runs identically in CI and on a laptop" promise
# (ADR-014 §4). An instructor should never have to push a commit to find out
# whether a page still reads at grade level.
#
# This is bar #2's instrument, not bar #1's. It DEFAULTS TO ADVISORY (ADR-016):
# readability is a proxy, so the gate reports a grade and names the longest
# sentences, and Linx keeps the editorial call. Turn it enforcing only where a
# genuine regression should stop a merge:
#
#   SEARCH_PATHS="modules" bash ...          # which trees/files to walk
#   TARGET_GRADE=10.0 bash ...               # the bar; flag above target+band
#   MAX_SENTENCE_WORDS=30 bash ...           # STE-100-derived sentence cap
#   SKIP_META=0 bash ...                     # also score _-prefixed planning files
#   FAIL_ON_GRADE=1 bash ...                 # make an over-band file fail
#   FAIL_ON_LONG_SENTENCE=1 bash ...         # make an over-cap sentence fail
#   VERBOSE=1 bash ...                       # list every over-long sentence
#
# Python because this is text measurement, not compilation. Python 3 ships on
# ubuntu-latest, macOS, and Codespaces; no packages are required.

set -uo pipefail

cd "$(git rev-parse --show-toplevel 2>/dev/null || echo .)" || exit 2

for py in python3 python; do
  if command -v "$py" >/dev/null 2>&1; then
    exec "$py" .github/scripts/editorial-gate.py "$@"
  fi
done

echo "FATAL: python3 not found. The editorial gate needs Python 3 (no packages)." >&2
exit 2
