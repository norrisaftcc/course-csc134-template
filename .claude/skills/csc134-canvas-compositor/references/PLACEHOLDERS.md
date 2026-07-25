# PLACEHOLDERS

Six artifacts emitted, spanning the dial from `M1 · learn` to `M7 · apply` and covering all
four LPAA beats. Wire the links in
the RCE, then delete the adjacent `[LINK PENDING]` marker span. Nothing else gets hand-edited
in the RCE — edit the Markdown source and re-emit.

| Fragment | Dial | Placeholder | Insert with |
|---|---|---|---|
| `m01-page-talk-to-computers.html` | `M1 · learn` | `#LINK-PENDING-m1-robot-sandwich` | Course Links → Assignments |
| `m02-page-draw-it-first.html` | `M2 · learn` | `#LINK-PENDING-m2-describe-lab` | Course Links → Assignments |
| `m04-page-apply-gatekeeper.html` | `M4 · apply` | `#LINK-PENDING-m4-gatekeeper-lab` | Course Links → Assignments |
| `m04-assignment-dungeon-gatekeeper.html` | `M4 · assess` | `#LINK-PENDING-style-guide-cpp` | Course Documents |
| `m07-page-apply-rooms-struct.html` | `M7 · apply` | `#LINK-PENDING-m7-lab1` | Course Links → Assignments |
| `m02-practice-exit-ticket.html` | `M2 · practice` | none | n/a — see below |

Marker counts equal placeholder-link counts on every page (1 each, and 0 on the quiz). ✔

## The exit ticket is not one fragment

`m02-practice-exit-ticket.html` holds **five** fragments — a quiz description and four question
stems — because each goes into a separate Canvas field. They share no wrapper and none of them
assumes one, so they cannot be pasted as a block. Copy them one at a time; the delimiters say
which field each belongs to.

Its answer key is `m02-practice-ANSWERS.md`. **Instructor only** — it is not a Canvas fragment
and must not be pasted anywhere students can reach.

Real external URL, correctly left as-is: GitHub basic writing and formatting syntax (M1).

## No images anywhere

No fragment carries an `<img>`, so there is no `manifest.txt` and no upload step in the whole
set. Diagrams ship as character diagrams (M2 flowchart, M7 array and record layouts), as
sequence gutters (M1 push/pull cycle), or as Mermaid source the student is meant to write
(M2, M4).

## Verified against a real toolchain

Every C++ listing, every block of machine text, and every numeric claim in a checklist was
compiled and run under `g++ -std=c++17 -Wall -Wextra` (GCC, Ubuntu):

- **M4 apply** — stages 1 and 2 build with zero warnings. The fallthrough warning is verbatim
  output at the line numbers students see in the stage-1 file.
- **M7 apply** — the listing builds clean *with the TODO unfilled* and prints `Reachable gold:
  0`, which is the page's teaching point. Filled correctly it prints `10`. Unlocking the Vault
  gives `260` and a fourth 40-gold room gives `50`, as the checklist claims. The
  `rooms.gold[i]` error text in the caution is verbatim.
- **Character diagrams** — all three checked programmatically for box-width consistency and
  column count: M2 flowchart 27 cols, M7 arrays 28, M7 record 16. Ceiling is 40.

Re-verify after editing any listing: the line numbers inside a compiler message are coupled to
the code above it, and the checklist numbers are coupled to the data in the listing.
