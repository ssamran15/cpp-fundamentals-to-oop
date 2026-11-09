# Chapter 18: Classes and Objects

## More Exercises

These exercises continue the Exercises section of Chapter 18 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Square
{
private:
    int side;
public:
    void set(int s);
    int area();
    int twiceArea();
};
void Square::set(int s) { side = s; }
int Square::area() { return side * side; }
int Square::twiceArea() { return 2 * area(); }
int main()
{
    Square sq;
    sq.set(5);
    cout << sq.area() << " " << sq.twiceArea() << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Rect
{
private:
    int l, w;
public:
    void set(int a, int b) { l = a; w = b; }
    int area() { return l * w; }
};
int main()
{
    Rect a;
    a.set(3, 4);
    Rect b = a;
    b.set(5, 5);
    cout << a.area() << " " << b.area() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Account
{
private:
    double bal;
public:
    void open(double b) { bal = b; }
    void addProfit(double rate) { bal += bal * rate / 100; }
    double get() { return bal; }
};
int main()
{
    Account a;
    a.open(10000);
    a.addProfit(10);
    a.addProfit(10);
    cout << a.get() << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string first, last;
public:
    void setName(string f, string l) { first = f; last = l; }
    string fullName() { return first + " " + last; }
    int nameLength() { return fullName().length(); }
};
int main()
{
    Person p;
    p.setName("Usman", "Tariq");
    cout << p.fullName() << " " << p.nameLength() << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Account
{
private:
    double balance;
    bool valid(double a) { return a > 0; }
public:
    void deposit(double a) { if (valid(a)) balance += a; }
};
int main()
{
    Account acc;
    if (acc.valid(500))
        acc.deposit(500);
    return 0;
}
```

**Q13.** (This program compiles, but cannot be built into an executable.)

```cpp
#include <iostream>
using namespace std;
class Box
{
private:
    int w;
public:
    void set(int x) { w = x; }
    int area();
};
int main()
{
    Box b;
    b.set(4);
    cout << b.area() << endl;
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
    void set(int x) { w = x; }
    int get() { return w; }
};
int main()
{
    Box b;
    b.set(4);
    cout << b->get() << endl;
    return 0;
}
```
