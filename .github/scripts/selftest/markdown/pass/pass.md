# Fixture — everything here must MATCH

Three shapes the convention has to support. If this file ever fails, the gate has
become stricter than the convention and authors will start fighting it.

## 1. `source=` — the whole file, byte for byte

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

## 2. `excerpt=` — a run of lines from inside the file

No line numbers. This is found by content, so inserting a line above it in the
`.cpp` cannot break the match.

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

## 3. `source=` with an elision — the M4 tail-fragment shape

`apply-tutorial.md` Stage 3 is written this way by hand. The `// ...` line stands
in for lines the page deliberately does not repeat, and the reader can see that
something was left out.

```cpp source=.github/scripts/selftest/markdown/code/clean.cpp
// clean.cpp — fixture for the Markdown block gate self-test.
// Not teaching material. This file exists so the gate can prove, on every run,
// that it still matches what matches and still fails what should fail.
#include <iostream>
using namespace std;

int main()
{
    // ... the strength prompt is read above ...

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
