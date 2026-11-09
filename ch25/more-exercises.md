# Chapter 25: Friend Functions and Stream Operators

## More Exercises

These exercises continue the Exercises section of Chapter 25 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Box
{
private:
    int w = 2, h = 3;
    friend class Painter;
};
class Painter
{
public:
    int area(const Box &b) const { return b.w * b.h; }
    void grow(Box &b) const { b.w++; b.h++; }
};
int main()
{
    Box b;
    Painter p;
    cout << p.area(b) << " ";
    p.grow(b);
    cout << p.area(b) << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Num
{
private:
    int v;
public:
    Num(int x) : v(x) {}
    int operator-(int k) const { return v - k; }
    friend int operator-(int k, const Num &n) { return k - n.v * 2; }
};
int main()
{
    Num a(10);
    cout << a - 4 << " " << 4 - a << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Item
{
private:
    int code;
public:
    Item(int c) : code(c) {}
    void show() const { cout << "M" << code << " "; }
    friend void show(const Item &i);
};
void show(const Item &i)
{
    cout << "F" << i.code + 1 << " ";
}
int main()
{
    Item x(7);
    x.show();
    show(x);
    cout << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Temp
{
private:
    int c;
public:
    Temp(int x) : c(x) {}
    friend ostream &operator<<(ostream &out, const Temp &t)
    {
        out << t.c << "C";
        return out;
    }
    friend Temp operator+(const Temp &a, const Temp &b) { return Temp(a.c + b.c); }
};
int main()
{
    Temp morning(18), rise(9);
    cout << morning << " + " << rise << " = " << morning + rise << endl;
    cout << 1 + morning << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Plot
{
private:
    double length, width;
public:
    Plot(double l, double w) : length(l), width(w) {}
    friend double area(const Plot &p);
};
double area(const Plot &p)
{
    return p.length * p.width;
}
int main()
{
    Plot p(30, 60);
    cout << p.area() << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Date
{
private:
    int d, m, y;
public:
    Date(int a, int b, int c) : d(a), m(b), y(c) {}
    ostream &operator<<(ostream &out) const
    {
        out << d << "/" << m << "/" << y;
        return out;
    }
};
int main()
{
    Date today(30, 10, 2026);
    cout << today << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Time
{
private:
    int h, m;
public:
    Time() : h(0), m(0) {}
    friend istream &operator>>(istream &in, const Time &t);
};
istream &operator>>(istream &in, const Time &t)
{
    char colon;
    in >> t.h >> colon >> t.m;
    return in;
}
int main()
{
    Time t;
    cin >> t;
    return 0;
}
```
