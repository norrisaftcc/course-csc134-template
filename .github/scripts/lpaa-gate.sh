#!/usr/bin/env bash
#
# CSC-134 LPAA content gate — entry point.
#
#     bash .github/scripts/lpaa-gate.sh
#
# Shaped like compile-gate.sh and markdown-gate.sh on purpose: same invocation,
# same dials-as-env-vars, same "runs identically in CI and on a laptop" promise
# (ADR-014 §4). Three gates that each want to be driven differently is three
# gates nobody runs locally.
#
# The other two ask whether the code is right. This one asks whether the repo's
# claims about itself are true — the class of defect that produced six false
# status claims in one week, none of which any gate could see (#54).
#
# THE DIALS
#
#   STRICT=1 bash ...                         # fail on violations (default: report)
#   ONLY=boundary,stale-stub bash ...         # run a subset of checks
#   MODULES_INDEX=modules/MODULES.md bash ... # where the status table lives
#   MODULES_ROOT=modules bash ...             # which tree to walk
#
# Python because this is text and path reasoning, not compilation. Python 3 ships
# on ubuntu-latest, on macOS, and in Codespaces; no packages are required.

set -uo pipefail

. "$(dirname "$0")/_run-python-gate.sh"
run_python_gate lpaa-gate.py "LPAA" "$@"
