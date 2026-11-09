# Chapter 17: From Procedural to Object-Oriented Programming

## More Exercises

These exercises continue the Exercises section of Chapter 17 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
struct S
{
    int a;
};
S make(int n)
{
    S s;
    s.a = n * n;
    return s;
}
int main()
{
    cout << make(4).a + make(3).a << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
struct Counter
{
    int c;
    void up() { c++; }
};
int main()
{
    Counter a = {3};
    Counter b = a;
    b.up();
    cout << a.c << " " << b.c << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
struct Point
{
    int x, y;
};
int main()
{
    Point p = {1, 2};
    Point &r = p;
    Point *q = &p;
    r.x = 5;
    q->y = 8;
    cout << p.x << " " << p.y << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Lamp
{
private:
    bool on;
public:
    void reset() { on = false; }
    void press() { on = !on; }
    void show() { cout << (on ? "ON" : "OFF") << " "; }
};
int main()
{
    Lamp a, b;
    a.reset();
    b.reset();
    a.press();
    b.press();
    b.press();
    a.show();
    b.show();
    cout << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Student
{
    int roll;
};
int main()
{
    Student s;
    s.roll = 5;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
struct Counter
{
    int c;
    void show() { cout << c << endl; }
};
int main()
{
    Counter k = {4};
    Counter *p = &k;
    p.show();
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Box
{
public:
    int w;
    void set(int x) { w = x; }
};
int main()
{
    Box.set(3);
    return 0;
}
```
