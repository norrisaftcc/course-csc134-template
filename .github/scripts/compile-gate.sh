#!/usr/bin/env bash
#
# CSC-134 compile gate — mechanical quality bar #1.
#
#   "Every C++ block in every artifact builds under g++ -std=c++17 -Wall -Wextra
#    with zero warnings and zero errors. Not 'compiles with a note' — zero."
#                                                              — CLAUDE.md
#
# Runs in CI on ubuntu-latest, and locally with the same command:
#
#     bash .github/scripts/compile-gate.sh
#
# Why this exists: for most of the alpha the gate ran on whatever `g++` resolved
# to on a developer's machine. On macOS that is Apple clang, which does NOT enable
# -Wimplicit-fallthrough under -Wextra. GNU g++ does. So "gate green" meant "green
# on clang", and a warning shipped inside a module certified Ready. See
# _lore/findings/F-009-fallthrough-warning-claim-is-toolchain-dependent.md.
#
# ---------------------------------------------------------------------------
# THE DIALS — override any of these as environment variables.
# ---------------------------------------------------------------------------
#
#   CXX=g++-16 bash .github/scripts/compile-gate.sh     # pick the compiler
#   FAIL_ON_WARNING=0 bash ...                          # report, do not fail
#   SEARCH_PATHS="modules/m4" bash ...                  # gate one module
#   VERBOSE=1 bash ...                                  # print every diagnostic
#
CXX="${CXX:-g++}"                              # compiler binary
CXX_STD="${CXX_STD:-c++17}"                    # language standard (ADR: c++17)
WARN_FLAGS="${WARN_FLAGS:--Wall -Wextra}"      # the course's warning set
FAIL_ON_WARNING="${FAIL_ON_WARNING:-1}"        # 1 = a warning fails the build
SEARCH_PATHS="${SEARCH_PATHS:-_contracts modules}"
VERBOSE="${VERBOSE:-0}"

set -uo pipefail

BOLD=$'\033[1m'; RED=$'\033[31m'; GREEN=$'\033[32m'; YELLOW=$'\033[33m'; DIM=$'\033[2m'; OFF=$'\033[0m'
if [ ! -t 1 ] && [ -z "${GITHUB_ACTIONS:-}" ]; then BOLD=""; RED=""; GREEN=""; YELLOW=""; DIM=""; OFF=""; fi

command -v "$CXX" >/dev/null 2>&1 || { echo "${RED}FATAL${OFF}: compiler '$CXX' not found."; exit 2; }

echo "${BOLD}CSC-134 compile gate${OFF}"
echo "  compiler   : $($CXX --version | head -1)"
echo "  flags      : -std=$CXX_STD $WARN_FLAGS"
echo "  paths      : $SEARCH_PATHS"
echo "  warning is : $([ "$FAIL_ON_WARNING" = "1" ] && echo 'a FAILURE (zero-warning rule)' || echo 'reported only')"
echo

WORK="$(mktemp -d)"; trap 'rm -rf "$WORK"' EXIT

# Portable file collection. `mapfile` is bash 4+; macOS still ships bash 3.2, and
# this script is meant to run on an instructor's laptop as well as in CI.
FILES=()
while IFS= read -r line; do
  [ -n "$line" ] && FILES+=("$line")
done < <(find $SEARCH_PATHS -name '*.cpp' -type f 2>/dev/null | sort)

if [ "${#FILES[@]}" -eq 0 ]; then
  echo "${YELLOW}No .cpp files found under: $SEARCH_PATHS${OFF}"
  echo "Nothing to gate. This is a configuration problem, not a pass."
  exit 2
fi

clean=0; warned=0; errored=0; expected=0
warn_list=(); err_list=(); silent_list=()

for f in "${FILES[@]}"; do
  # Some teaching artifacts are BROKEN ON PURPOSE — an exit-ticket item whose whole
  # job is to demonstrate a warning. Holding them to the zero-warning bar would force
  # someone to "fix" the file and destroy the item it supports. They opt out by name:
  #
  #     // GATE: EXPECT-WARNING
  #
  # The opt-out is an ASSERTION, not a mute. A marked file that stops warning FAILS,
  # because the artifact has quietly stopped demonstrating what it claims to.
  expect_warn=0
  grep -q 'GATE: EXPECT-WARNING' "$f" && expect_warn=1

  out="$("$CXX" -std="$CXX_STD" $WARN_FLAGS "$f" -o "$WORK/$(basename "${f%.cpp}")" 2>&1)"
  rc=$?
  label="$f"

  if [ $rc -ne 0 ]; then
    printf '  %sERROR%s  %s\n' "$RED" "$OFF" "$label"
    err_list+=("$f"); errored=$((errored+1))
    echo "$out" | sed 's/^/           /'

  elif [ -n "$out" ]; then
    if [ "$expect_warn" = "1" ]; then
      printf '  %sexpect%s %s  %s(marked EXPECT-WARNING)%s\n' "$DIM" "$OFF" "$label" "$DIM" "$OFF"
      expected=$((expected+1))
      echo "$out" | grep -E 'warning:' | sed 's/^/           /'
    else
      printf '  %sWARN %s  %s\n' "$YELLOW" "$OFF" "$label"
      warn_list+=("$f"); warned=$((warned+1))
      # Always show the warning itself — a gate that hides its evidence is not a gate.
      echo "$out" | grep -E 'warning:' | sed 's/^/           /'
    fi
    [ "$VERBOSE" = "1" ] && echo "$out" | sed 's/^/           /'

  else
    if [ "$expect_warn" = "1" ]; then
      printf '  %sSILENT%s %s\n' "$RED" "$OFF" "$label"
      printf '         marked GATE: EXPECT-WARNING but compiled clean.\n'
      printf '         The artifact no longer demonstrates the warning it exists for.\n'
      silent_list+=("$f")
    else
      printf '  %sclean%s  %s\n' "$GREEN" "$OFF" "$label"
      clean=$((clean+1))
    fi
  fi
done

total="${#FILES[@]}"
echo
summary="$total file(s): $clean clean, $warned warned, $errored errored"
[ "$expected" -gt 0 ] && summary="$summary, $expected expected-warning"
[ "${#silent_list[@]}" -gt 0 ] && summary="$summary, ${#silent_list[@]} wrongly silent"
echo "${BOLD}${summary}${OFF}"

if [ -n "${GITHUB_STEP_SUMMARY:-}" ]; then
  {
    echo "## CSC-134 compile gate"
    echo
    echo "\`$($CXX --version | head -1)\`  ·  \`-std=$CXX_STD $WARN_FLAGS\`"
    echo
    echo "| | count |"
    echo "|---|---|"
    echo "| clean | $clean |"
    echo "| warned | $warned |"
    echo "| errored | $errored |"
    if [ "$warned" -gt 0 ]; then
      echo
      echo "### Warned"
      for f in "${warn_list[@]}"; do echo "- \`$f\`"; done
      echo
      echo "> A warning fails the Format column at any tier. This is a fix-and-resubmit"
      echo "> result, not a penalty one."
    fi
    if [ "$errored" -gt 0 ]; then
      echo
      echo "### Errored"
      for f in "${err_list[@]}"; do echo "- \`$f\`"; done
    fi
  } >> "$GITHUB_STEP_SUMMARY"
fi

if [ "$errored" -gt 0 ]; then
  echo "${RED}GATE FAILED${OFF} — compile errors."
  exit 1
fi
if [ "${#silent_list[@]}" -gt 0 ]; then
  echo "${RED}GATE FAILED${OFF} — a file marked EXPECT-WARNING compiled clean."
  echo "Either the compiler changed its mind, or someone 'fixed' a file that is"
  echo "broken on purpose. Check what the artifact is supposed to demonstrate"
  echo "before removing the marker."
  exit 1
fi
if [ "$warned" -gt 0 ] && [ "$FAIL_ON_WARNING" = "1" ]; then
  echo "${RED}GATE FAILED${OFF} — the course rule is zero warnings, not zero errors."
  exit 1
fi
if [ "$warned" -gt 0 ]; then
  echo "${YELLOW}Warnings present, not failing (FAIL_ON_WARNING=0).${OFF}"
fi
echo "${GREEN}GATE PASSED${OFF}"

# ---------------------------------------------------------------------------
# KNOWN LIMITATION, recorded rather than hidden.
#
# This gates complete .cpp files. Mechanical bar #1 says "every C++ block in
# every artifact", which includes fenced blocks inside Markdown. Many of those
# are deliberate fragments that cannot compile standalone, so extracting them
# needs a wrapping convention that does not exist yet. Until it does, a warning
# can hide in a Markdown listing that no .cpp file mirrors.
# ---------------------------------------------------------------------------
