# Fixture — dedenting a nested fence must not make the gate blind

The companion to `indented/`. Stripping the fence's indentation is a whitespace
normalisation, and whitespace normalisation is exactly how a matcher quietly
stops matching. So: the same nesting, and one line of the listing changed.

The gate must still catch it. If this fixture ever passes, `dedent_to_fence` has
become a mute.

- [ ] **A checklist item with a drifted listing under it.** The threshold reads
      `>= 50` here; the source says `>= 70`:

      ```cpp excerpt=.github/scripts/selftest/markdown/code/clean.cpp
          if (strength >= 50)
          {
              cout << "The gate swings wide.\n";
          }
          else
          {
              cout << "Turned away.\n";
          }
      ```
