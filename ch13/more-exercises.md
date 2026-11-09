# Chapter 13: Pointers

## More Exercises

These exercises continue the Exercises section of Chapter 13 in the book. The book has Q1 to Q8; the numbering continues here.

### Determine the output

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {3, 6, 9, 12, 15};
    int *p = a + 1;
    cout << *p << " " << *(p + 2) << " " << p[1] << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
void change(int *n)
{
    *n = *n * 2;
    n = nullptr;
}
int main()
{
    int v = 7;
    change(&v);
    cout << v << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    char s[] = "Okara";
    char *p = s + 2;
    cout << p << " " << *p << " " << *(s + 4) << endl;
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    int sum = 0;
    while (p < a + 5)
    {
        if (*p % 20 == 0)
            sum += *p;
        p++;
    }
    cout << sum << endl;
    return 0;
}
```

### Find the error

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    double price = 99.5;
    int *p = &price;
    cout << *p << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 4;
    const int *p = &x;
    *p = 8;
    cout << x << endl;
    return 0;
}
```

**Q15.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int *p;
    *p = 25;
    cout << *p << endl;
    return 0;
}
```
