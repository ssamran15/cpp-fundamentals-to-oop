# Chapter 24: Operator Overloading II and Type Conversion

## More Exercises

These exercises continue the Exercises section of Chapter 24 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Add
{
private:
    int n;
public:
    Add(int k) : n(k) {}
    int operator()(int x) const { return x + n; }
};
int main()
{
    Add five(5), ten(10);
    cout << five(3) << " " << ten(five(1)) << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class P
{
private:
    int x;
public:
    P(int a) : x(a) {}
    operator int() const { return x * x; }
};
int main()
{
    P p(3);
    int n = p + 1;
    cout << n << " " << p * 2 << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
class Rupees
{
private:
    double r;
public:
    Rupees(double x) : r(x) {}
    double get() const { return r; }
};
class Dollars
{
private:
    double d;
public:
    Dollars(double x) : d(x) {}
    operator Rupees() const { return Rupees(d * 280); }
};
int main()
{
    Dollars fee(50);
    Rupees r = fee;
    cout << r.get() << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Ticket
{
private:
    int c = 0;
public:
    int operator()() { return ++c; }
};
int main()
{
    Ticket next;
    next();
    next();
    cout << next() * 10 << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Arr
{
private:
    int a[3] = {0, 0, 0};
public:
    int operator[](int i) { return a[i]; }
};
int main()
{
    Arr x;
    x[0] = 5;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Fahrenheit;
class Celsius
{
private:
    double deg;
public:
    Celsius(double d) : deg(d) {}
    double get() const { return deg; }
    operator Fahrenheit() const;
};
class Fahrenheit
{
private:
    double deg;
public:
    Fahrenheit(double d) : deg(d) {}
    Fahrenheit(const Celsius &c) : deg(c.get() * 9 / 5 + 32) {}
};
Celsius::operator Fahrenheit() const { return Fahrenheit(deg * 9 / 5 + 32); }
int main()
{
    Celsius c(30);
    Fahrenheit f = c;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
class SafeArray
{
private:
    int data[5] = {1, 2, 3, 4, 5};
public:
    int &operator[](int i) { return data[i]; }
};
void print(const SafeArray &a)
{
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}
int main()
{
    SafeArray s;
    print(s);
    return 0;
}
```
