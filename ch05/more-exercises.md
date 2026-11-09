# Chapter 5: Operators and Expressions

## More Exercises

These exercises continue the Exercises section of Chapter 5 in the book. The book has Q1 to Q6; the numbering continues here.

### Determine the output

**Q7.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int y = x++;
    int z = ++x;
    cout << x << " " << y << " " << z << endl;
    return 0;
}
```

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    cout << 2 + 3 * 4 - 8 / 2 % 3 << endl;
    cout << (2 + 3) * (4 - 8) / 2 << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    char c = 'a';
    c = c - 32;
    cout << c << endl;
    cout << -7 / 2 << " " << -7 % 2 << endl;
    return 0;
}
```

### Find the error

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 5, b;
    a + 1 = b;
    ++5;
    cout << a;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int total = 250, n = 0;
    cout << "Average = " << total / n << endl;
    return 0;
}
```
