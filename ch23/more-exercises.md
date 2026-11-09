# Chapter 23: Operator Overloading I

## More Exercises

These exercises continue the Exercises section of Chapter 23 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Counter
{
private:
    int v;
public:
    Counter(int x = 0) : v(x) {}
    Counter &operator++() { ++v; return *this; }
    Counter operator++(int) { Counter old = *this; ++v; return old; }
    int get() const { return v; }
};
int main()
{
    Counter k(10);
    Counter a = k++;
    Counter b = ++k;
    cout << a.get() << " " << b.get() << " " << k.get() << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Money
{
private:
    int r;
public:
    Money(int x = 0) : r(x) {}
    Money &operator+=(const Money &m) { r += m.r; return *this; }
    int get() const { return r; }
};
int main()
{
    Money m(100);
    (m += Money(50)) += Money(25);
    Money n = m;
    n += n;
    cout << m.get() << " " << n.get() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class A
{
private:
    int v;
public:
    A(int x = 0) : v(x) {}
    A(const A &o) : v(o.v) { cout << "C"; }
    A &operator=(const A &o) { cout << "="; v = o.v; return *this; }
};
int main()
{
    A a(1), b(2);
    A c = a;
    c = b;
    A d(c);
    d = a = b;
    cout << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Mark
{
private:
    int m;
public:
    Mark(int x = 0) : m(x) {}
    bool operator<(const Mark &o) const { return m < o.m; }
    int get() const { return m; }
};
int main()
{
    Mark list[4] = { Mark(72), Mark(45), Mark(88), Mark(60) };
    Mark best = list[0];
    for (int i = 1; i < 4; i++)
        if (best < list[i])
            best = list[i];
    Mark worst = list[0];
    for (int i = 1; i < 4; i++)
        if (list[i] < worst)
            worst = list[i];
    cout << best.get() << " " << worst.get() << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Counter
{
private:
    int v = 0;
public:
    Counter &operator++() { ++v; return *this; }
    Counter operator++() { Counter old = *this; ++v; return old; }
};
int main()
{
    Counter c;
    c++;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int operator+(int a, int b)
{
    return a - b;
}
int main()
{
    cout << 2 + 3 << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Box
{
private:
    int w;
public:
    Box(int x = 0) : w(x) {}
    void operator=(const Box &b) { w = b.w; }
};
int main()
{
    Box a(1), b(2), c(3);
    a = b = c;
    return 0;
}
```
