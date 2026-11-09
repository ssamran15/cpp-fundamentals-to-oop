# Chapter 9: Functions II

## More Exercises

These exercises continue the Exercises section of Chapter 9 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int calc(int a, int b = 2, int c = 3)
{
    return a * b + c;
}
int main()
{
    cout << calc(1) << " " << calc(1, 4) << " " << calc(1, 4, 5);
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int x = 10;
int main()
{
    int x = 20;
    {
        int x = 30;
        cout << x << " ";
    }
    cout << x << " " << ::x;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int f(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + f(n / 10);
}
int main()
{
    cout << f(1234);
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int g(int n)
{
    if (n <= 1)
        return 1;
    return n * g(n - 2);
}
int main()
{
    cout << g(7) << " " << g(6);
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
void print(int a = 1, int b)
{
    cout << a << b;
}
int main()
{
    print(5);
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        int total = i * 10;
    }
    cout << total;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
double interest(double p, double rate = 10);
int main()
{
    cout << interest(5000);
    return 0;
}
double interest(double p, double rate = 10)
{
    return p * rate / 100;
}
```
