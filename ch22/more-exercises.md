# Chapter 22: Composition, Aggregation and Arrays of Objects

## More Exercises

These exercises continue the Exercises section of Chapter 22 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Engine
{
private:
    int hp;
public:
    Engine(int h) : hp(h) {}
    int get() const { return hp; }
};
class Car
{
private:
    Engine e;
    int seats;
public:
    Car(int h, int s) : e(h), seats(s) {}
    int score() const { return e.get() / seats; }
};
int main()
{
    Car c(1200, 4), d(660, 2);
    cout << c.score() << " " << d.score() << endl;
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
    int s;
public:
    Box(int n) : s(n) {}
    int volume() const { return s * s * s; }
};
int main()
{
    cout << Box(3).volume() + Box(2).volume() << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Point
{
private:
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    int sum() const { return x + y; }
};
int main()
{
    Point pts[3] = { Point(1, 2), Point(3) };
    for (int i = 0; i < 3; i++)
        cout << pts[i].sum() << " ";
    cout << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Counter
{
private:
    int n = 0;
public:
    void inc() { n++; }
    int get() const { return n; }
};
int main()
{
    Counter a, b;
    Counter *arr[3] = { &a, &b, &a };
    for (int i = 0; i < 3; i++)
        arr[i]->inc();
    cout << a.get() << " " << b.get() << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Point
{
private:
    int x;
public:
    Point(int a) : x(a) {}
};
int main()
{
    Point arr[3];
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
    int year;
public:
    Date(int y) : year(y) {}
};
class Employee
{
private:
    Date birth;
public:
    Employee(int y) : birth(y) {}
    int birthYear() const { return birth.year; }
};
int main()
{
    Employee e(1995);
    cout << e.birthYear() << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class Book
{
public:
    void show() const { cout << "Book" << endl; }
};
int main()
{
    Book *picks[2];
    picks[0] = new Book;
    picks[1] = new Book;
    for (int i = 0; i < 2; i++)
        picks[i].show();
    return 0;
}
```
