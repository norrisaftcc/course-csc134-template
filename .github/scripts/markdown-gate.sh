#!/usr/bin/env bash
#
# CSC-134 Markdown block gate — entry point.
#
#     bash .github/scripts/markdown-gate.sh
#
# Deliberately shaped like compile-gate.sh: same invocation, same dial-as-env-var
# style, same "runs identically in CI and on a laptop" promise (ADR-014 §4). An
# instructor should never have to push a commit to find out whether a listing is
# still faithful to the file it claims to show.
#
# THE DIALS — override any of these as environment variables.
#
#   SEARCH_PATHS="modules" bash ...          # which trees to walk
#   GATED_PATHS="_contracts modules" bash ...# trees the compile gate covers
#   FAIL_ON_UNANNOTATED=0 bash ...           # report un-annotated blocks, don't fail
#   VERBOSE=1 bash ...                       # print every diff in full
#
# The engine is Python because this is text matching, not compilation, and doing
# it in bash would mean lying about how carefully it was done. Python 3 ships on
# ubuntu-latest, on macOS, and in Codespaces; no packages are required.

set -uo pipefail

. "$(dirname "$0")/_run-python-gate.sh"
run_python_gate markdown-gate.py "Markdown" "$@"
