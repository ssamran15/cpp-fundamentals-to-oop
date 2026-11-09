# Chapter 28: Virtual Tables and Run-Time Type Information

## More Exercises

These exercises continue the Exercises section of Chapter 28 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;
class Fruit
{
public:
    virtual ~Fruit() {}
};
class Mango : public Fruit { };
int main()
{
    Mango m;
    Fruit *f = &m;
    cout << (typeid(f) == typeid(Fruit *)) << " ";
    cout << (typeid(*f) == typeid(Fruit)) << " ";
    cout << (typeid(*f) == typeid(Mango)) << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base() {}
    virtual void f() const { cout << "Base::f "; }
    void g() const { cout << "Base::g "; }
};
class Derived : public Base
{
public:
    void f() const override { cout << "Derived::f "; }
    void g() const { cout << "Derived::g "; }
};
int main()
{
    Derived d;
    Base *bp = &d;
    Derived *dp = static_cast<Derived *>(bp);
    bp->f();
    bp->g();
    dp->f();
    dp->g();
    cout << endl;
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
};
class Circle : public Shape { };
class Square : public Shape { };
int main()
{
    Circle c;
    Shape *s = &c;
    Square *sq = dynamic_cast<Square *>(s);
    Circle *ci = dynamic_cast<Circle *>(s);
    Shape *back = ci;
    cout << (sq == nullptr) << (ci == nullptr) << (back == s) << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <string>
using namespace std;
class Staff
{
public:
    virtual ~Staff() {}
    virtual string role() const { return "Staff"; }
};
class Teacher : public Staff
{
public:
    string role() const override { return "Teacher"; }
    int lectures() const { return 18; }
};
int main()
{
    Teacher t;
    Staff s;
    Staff *list[3] = { &t, nullptr, &s };
    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        Teacher *tp = dynamic_cast<Teacher *>(list[i]);
        if (tp)
            total += tp->lectures();
        else
            total += 1;
    }
    cout << total << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Person
{
public:
    virtual ~Person() {}
};
class Student : public Person
{
public:
    int roll = 12;
};
int main()
{
    Student s;
    Person *p = &s;
    Student *sp = p;
    cout << sp->roll << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Vehicle
{
public:
    virtual ~Vehicle() {}
};
class Truck : public Vehicle
{
public:
    double load() const { return 18.5; }
};
int main()
{
    Truck t;
    Vehicle *v = &t;
    cout << v->load() << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Vehicle
{
public:
    virtual ~Vehicle() {}
};
class Truck : public Vehicle
{
public:
    double load = 18.5;
};
int main()
{
    Truck t;
    Vehicle &v = t;
    Truck tr = dynamic_cast<Truck>(v);
    cout << tr.load << endl;
    return 0;
}
```
