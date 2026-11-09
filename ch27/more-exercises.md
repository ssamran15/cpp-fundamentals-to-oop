# Chapter 27: Polymorphism and Abstract Classes

## More Exercises

These exercises continue the Exercises section of Chapter 27 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class A
{
public:
    virtual void f() const { cout << "A::f "; }
    void g() const { cout << "A::g "; }
};
class B : public A
{
public:
    void f() const { cout << "B::f "; }
    void g() const { cout << "B::g "; }
};
int main()
{
    B b;
    A *p = &b;
    p->f();
    p->g();
    b.g();
    cout << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Bill
{
public:
    virtual double rate() const { return 10; }
    double total(int units) const { return units * rate(); }
};
class CommercialBill : public Bill
{
public:
    double rate() const { return 25; }
};
int main()
{
    Bill h;
    CommercialBill c;
    cout << h.total(100) << " " << c.total(100) << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Shape
{
public:
    virtual ~Shape() {}
    virtual int sides() const = 0;
    void describe() const { cout << sides() << " sides" << endl; }
};
class Triangle : public Shape
{
public:
    int sides() const override { return 3; }
};
class Hexagon : public Shape
{
public:
    int sides() const override { return 6; }
};
int main()
{
    Triangle t;
    Hexagon h;
    Shape &s1 = t, &s2 = h;
    s1.describe();
    s2.describe();
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Account
{
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual ~Account() {}
    virtual double profit() const { return 0; }
    double get() const { return balance; }
};
class Savings : public Account
{
public:
    Savings(double b) : Account(b) {}
    double profit() const override { return balance * 0.1; }
};
int main()
{
    Account *a[3] = { new Account(5000), new Savings(20000), new Savings(1000) };
    double sum = 0;
    for (int i = 0; i < 3; i++)
        sum += a[i]->get() + a[i]->profit();
    cout << sum << endl;
    for (int i = 0; i < 3; i++)
        delete a[i];
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Shape
{
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
};
int main()
{
    Shape s;
    cout << s.area() << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Record
{
public:
    virtual Record() { cout << "Record" << endl; }
    virtual ~Record() {}
};
int main()
{
    Record r;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Phone
{
public:
    virtual ~Phone() {}
    virtual void call() const { cout << "Calling" << endl; }
};
class SmartPhone final : public Phone
{
public:
    void call() const override { cout << "Video calling" << endl; }
};
class FoldPhone : public SmartPhone
{
};
int main()
{
    FoldPhone f;
    f.call();
    return 0;
}
```
