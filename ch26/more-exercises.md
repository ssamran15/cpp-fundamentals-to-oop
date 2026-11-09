# Chapter 26: Inheritance

## More Exercises

These exercises continue the Exercises section of Chapter 26 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Base
{
protected:
    int x = 10;
public:
    void f() const { cout << "Base " << x << endl; }
};
class Derived : public Base
{
public:
    void f() const { cout << "Derived " << x * 2 << endl; }
    void g() { x = 7; f(); Base::f(); }
};
int main()
{
    Derived d;
    d.f();
    d.g();
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Animal
{
public:
    void sound() const { cout << "..." << endl; }
};
class Cat : public Animal
{
public:
    void sound() const { cout << "Meow" << endl; }
};
void play(const Animal &a)
{
    a.sound();
}
int main()
{
    Cat c;
    c.sound();
    play(c);
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Fee
{
public:
    int amount() const { return 1000; }
    void print() const { cout << "Fee: " << amount() << endl; }
};
class HostelFee : public Fee
{
public:
    int amount() const { return 1000 + 4500; }
};
int main()
{
    HostelFee h;
    cout << h.amount() << endl;
    h.print();
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Point
{
protected:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    void show() const { cout << "(" << x << "," << y << ")" << endl; }
};
class Point3D : public Point
{
private:
    int z;
public:
    Point3D(int a, int b, int c) : Point(a, b), z(c) {}
    void show() const { cout << "(" << x << "," << y << "," << z << ")" << endl; }
};
int main()
{
    Point3D q(1, 2, 3);
    Point p = q;
    q.show();
    p.show();
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Employee
{
protected:
    double pay = 50000;
};
class Clerk : public Employee
{
public:
    void raise() { pay += 5000; }
};
int main()
{
    Clerk c;
    c.raise();
    cout << c.pay << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Printer
{
public:
    void print() const { cout << "Printing" << endl; }
};
class ColorPrinter : public Printer
{
public:
    void print(int copies) const { cout << "Printing " << copies << " copies" << endl; }
};
int main()
{
    ColorPrinter cp;
    cp.print(3);
    cp.print();
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Engine
{
public:
    void start() const { cout << "Engine started" << endl; }
};
class Car : private Engine
{
public:
    void drive() const { start(); cout << "Driving" << endl; }
};
int main()
{
    Car c;
    c.drive();
    c.start();
    return 0;
}
```
