# Chapter 16: Bitwise Operators, enums and Command-line Arguments

## More Exercises

These exercises continue the Exercises section of Chapter 16 in the book. The book has Q1 to Q8; the numbering continues here.

### Determine the output

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 1;
    x <<= 3;
    cout << x << " " << (x >> 1) << " " << (40 >> 3) << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    unsigned char f = 0;
    f |= 1 << 2;
    f |= 1 << 0;
    f &= ~(1 << 2);
    cout << int(f) << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 7, b = 12;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << a << " " << b << endl;
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 6, b = 1;
    cout << (a && b) << " " << (a & b) << " "
         << (a || 0) << " " << (a | 0) << endl;
    return 0;
}
```

### Find the error

**Q13.**

```cpp
#include <iostream>
using namespace std;
enum class Light { RED, GREEN };
int main()
{
    int x = Light::GREEN;
    cout << x << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
enum Fruit { APPLE, ORANGE };
enum Color { RED, ORANGE };
int main()
{
    cout << APPLE << endl;
    return 0;
}
```

**Q15.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    double d = 5.5;
    cout << (d << 1) << endl;
    return 0;
}
```
