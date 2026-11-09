# Chapter 21: const and static Members

## More Exercises

These exercises continue the Exercises section of Chapter 21 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class S
{
private:
    static int x;
    int y = 0;
public:
    void inc() { x++; y++; }
    void show() const { cout << x << y << " "; }
};
int S::x = 0;
int main()
{
    S a, b;
    a.inc();
    b.inc();
    b.inc();
    a.show();
    b.show();
    cout << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class A
{
private:
    int x;
    static int y;
public:
    A(int v) : x(v) { y += v; }
    int sum() const { return x + y; }
};
int A::y = 0;
int main()
{
    A p(2), q(5);
    cout << p.sum() << " " << q.sum() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Meter
{
private:
    int reading;
    mutable int checks = 0;
public:
    Meter(int r) : reading(r) {}
    int get() const { checks++; return reading; }
    int getChecks() const { return checks; }
};
int main()
{
    const Meter m(450);
    int total = m.get() + m.get();
    cout << total << " " << m.getChecks() << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Club
{
public:
    static int members;
    Club() { members++; }
};
int Club::members = 100;
int main()
{
    Club a;
    Club b;
    a.members = 200;
    Club c;
    cout << Club::members << " " << b.members << endl;
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
    int n = 0;
public:
    int next() const
    {
        n++;
        return n;
    }
};
int main()
{
    Counter c;
    cout << c.next() << endl;
    return 0;
}
```

**Q13.** (This program compiles, but cannot be built into an executable.)

```cpp
#include <iostream>
using namespace std;
class Box
{
public:
    static int count;
    Box() { count++; }
};
int main()
{
    Box a, b;
    cout << Box::count << endl;
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
    int w = 5;
    static int count;
public:
    static int getW() { return w; }
};
int Box::count = 0;
int main()
{
    cout << Box::getW() << endl;
    return 0;
}
```
