#!/usr/bin/env bash
#
# Shared entry-point mechanism for the three Python gates.
#
#     source .github/scripts/_run-python-gate.sh
#     run_python_gate markdown-gate.py "Markdown" "$@"
#
# WHY THIS EXISTS. markdown-gate.sh, lpaa-gate.sh, and editorial-gate.sh had
# byte-identical bodies — find the repo root, find a Python, exec, fail loudly if
# there is none. Three copies of twelve lines is three places for a fix to land in
# two of them.
#
# WHAT DELIBERATELY DID NOT MOVE. Each wrapper keeps its full header comment: the
# dials it accepts, what the gate asks, and why it is shaped the way it is. That
# text is the gate's specification, and `bash .github/scripts/lpaa-gate.sh` is not
# the only way people read it — `head -30` on the wrapper is. Collapsing the three
# headers into one shared block would save lines and cost every gate the ability
# to explain itself where it is invoked.
#
# The mechanism is shared. The specification is not.
#
# Python 3 ships on ubuntu-latest, on macOS, and in Codespaces; no packages are
# required, which is what lets a laptop run and a CI run give the same number
# (ADR-014 §4).

run_python_gate() {
  local script="$1" label="$2"
  shift 2

  cd "$(git rev-parse --show-toplevel 2>/dev/null || echo .)" || exit 2

  # The `python` fallback must be version-checked. Every gate .py is python3-shebanged
  # and lpaa-gate.py uses f-strings, so running one under Python 2 dies with a
  # SyntaxError instead of the message below — the script would break its own promise
  # at exactly the moment the promise matters.
  local py
  for py in python3 python; do
    if command -v "$py" >/dev/null 2>&1 &&
       "$py" -c 'import sys; sys.exit(0 if sys.version_info[0] >= 3 else 1)' 2>/dev/null; then
      exec "$py" ".github/scripts/$script" "$@"
    fi
  done

  echo "FATAL: python3 not found. The $label gate needs Python 3 (no packages)." >&2
  exit 2
}
