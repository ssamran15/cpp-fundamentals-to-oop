# Chapter 8: Functions I

## More Exercises

These exercises continue the Exercises section of Chapter 8 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int f(int n)
{
    return n * n + 1;
}
int main()
{
    cout << f(3) + f(f(1));
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
void line(int n)
{
    for (int i = 1; i <= n; i++)
        cout << '*';
    cout << endl;
}
int main()
{
    line(3);
    line(1);
    line(0);
    line(2);
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int counter(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}
int main()
{
    cout << counter(50273) << " " << counter(9) << " " << counter(0);
    return 0;
}
```

### Find the error

**Q11.**

```cpp
#include <iostream>
using namespace std;
void message()
{
    cout << "Hello";
    return 5;
}
int main()
{
    message();
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
using namespace std;
int sum(int a, b)
{
    return a + b;
}
int main()
{
    cout << sum(2, 3);
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int half(int n)
    {
        return n / 2;
    }
    cout << half(10);
    return 0;
}
```
