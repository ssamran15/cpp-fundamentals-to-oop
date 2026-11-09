# Chapter 20: Objects and Memory: this, Copy Constructor, Deep vs Shallow Copy

## More Exercises

These exercises continue the Exercises section of Chapter 20 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class C
{
private:
    int v = 0;
public:
    C &add(int x) { v += x; return *this; }
    int get() { return v; }
};
int main()
{
    C c;
    cout << c.add(2).add(3).add(5).get() << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Box
{
private:
    int *p;
public:
    Box(int v) { p = new int(v); }
    void set(int v) { *p = v; }
    int get() { return *p; }
};
int main()
{
    Box a(5);
    Box b = a;
    b.set(9);
    cout << a.get() << " " << b.get() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class T
{
public:
    T() { cout << "D"; }
    T(const T &) { cout << "C"; }
};
void f(T) {}
void g(T &) {}
int main()
{
    T a;
    T b(a);
    T c = b;
    f(c);
    g(c);
    cout << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Point
{
private:
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void move(int d) { x += d; y += d; }
    int sum() { return x + y; }
};
int main()
{
    Point p1(1, 2), p2;
    p2 = p1;
    p1.move(5);
    Point p3 = p1;
    p3.move(1);
    cout << p1.sum() << " " << p2.sum() << " " << p3.sum() << endl;
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
private:
    int roll;
public:
    void set(int roll) { this.roll = roll; }
};
int main()
{
    Student s;
    s.set(5);
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Order
{
private:
    double total = 0;
public:
    void add(double price) { total += price; }
    double get() { return total; }
};
int main()
{
    Order o;
    o.add(650).add(250);
    cout << o.get() << endl;
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
    int w = 3;
};
void show()
{
    cout << this->w << endl;
}
int main()
{
    show();
    return 0;
}
```
