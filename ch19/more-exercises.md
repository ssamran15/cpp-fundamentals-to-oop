# Chapter 19: Constructors and Destructors

## More Exercises

These exercises continue the Exercises section of Chapter 19 in the book. The book has Q1 to Q8; the numbering continues here.

### Determine the output

**Q9.**

```cpp
#include <iostream>
using namespace std;
class P
{
private:
    int x, y;
public:
    P() { x = y = 0; }
    P(int a) { x = y = a; }
    P(int a, int b) { x = a; y = b; }
    int sum() { return x + y; }
};
int main()
{
    P p1, p2(4), p3(2, 7);
    cout << p1.sum() << " " << p2.sum() << " " << p3.sum() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class X
{
private:
    int a, b;
public:
    X(int v) : a(v), b(a * 2) {}
    void show() { cout << a << " " << b << endl; }
};
int main()
{
    X x(5);
    x.show();
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class K
{
public:
    K()  { cout << "*"; }
    ~K() { cout << "#"; }
};
int main()
{
    K arr[3];
    cout << endl;
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
using namespace std;
class S
{
private:
    int a = 5;
    int b = 7;
public:
    S() {}
    S(int x) : a(x) {}
    void show() { cout << a << " " << b << " "; }
};
int main()
{
    S s1, s2(9);
    s1.show();
    s2.show();
    cout << endl;
    return 0;
}
```

### Find the error

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Rect
{
private:
    int l, w;
public:
    Rect(int a, int b) { l = a; w = b; }
    int area() { return l * w; }
};
int main()
{
    Rect r;
    cout << r.area() << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class A
{
    int x;
    A() { x = 0; }
public:
    int get() { return x; }
};
int main()
{
    A a;
    cout << a.get() << endl;
    return 0;
}
```

**Q15.**

```cpp
#include <iostream>
using namespace std;
class Rect
{
private:
    int l, w;
public:
    Rect() { l = w = 1; }
    int area() { return l * w; }
};
int main()
{
    Rect r();
    cout << r.area() << endl;
    return 0;
}
```
