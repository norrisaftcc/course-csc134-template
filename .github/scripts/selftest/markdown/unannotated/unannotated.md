# Fixture — a bare cpp block, the pre-ADR-015 default

Not defective. Just unmigrated: the gate cannot tell whether it is right.

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Am I gated? Nobody knows.\n";
    return 0;
}
```
