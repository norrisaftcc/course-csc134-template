# Fixture — a fence nested in a list item must MATCH

The hard case the convention nearly shipped without. A fenced block indented
inside a list item is rendered *un*indented by CommonMark, so the gate has to
read it the same way. If it does not, the block is unfixable: de-indenting to
satisfy the gate breaks the list nesting and changes the page.

`modules/m4/assess-lab.md:199` is exactly this shape and is one of the 23 blocks
awaiting migration (#30) — which is how this was found.

- [ ] **A checklist item with a listing under it.** Six spaces deep, the same
      depth M4 uses, quoting a run of lines from the fixture source:

      ```cpp excerpt=.github/scripts/selftest/markdown/code/clean.cpp
          if (strength >= 70)
          {
              cout << "The gate swings wide.\n";
          }
          else
          {
              cout << "Turned away.\n";
          }
      ```

- [ ] **A deeper nest, whole-file this time.** Only the fence's own indentation
      comes off — the code's internal indentation is structure and is still
      compared:

          ```cpp source=.github/scripts/selftest/markdown/code/clean.cpp
          // clean.cpp — fixture for the Markdown block gate self-test.
          // Not teaching material. This file exists so the gate can prove, on every run,
          // that it still matches what matches and still fails what should fail.
          #include <iostream>
          using namespace std;

          int main()
          {
              int strength = 0;
              cout << "Your strength score (0-100): ";
              cin >> strength;

              if (strength >= 70)
              {
                  cout << "The gate swings wide.\n";
              }
              else
              {
                  cout << "Turned away.\n";
              }

              return 0;
          }
          ```
