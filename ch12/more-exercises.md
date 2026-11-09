# Chapter 12: Strings, Structures, typedef and Unions

## More Exercises

These exercises continue the Exercises section of Chapter 12 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "Programming";
    cout << s.substr(3, 4) << " " << s.find('g') << " " << s.find("ram");
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x = "apple", y = "Apple";
    cout << (x == y) << " " << (x > y) << " " << (x.length() == y.length());
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
void f(Point p)  { p.x = 99; }
void g(Point &p) { p.y = 99; }
int main()
{
    Point a = {1, 2};
    f(a);
    g(a);
    cout << a.x << " " << a.y;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <string>
using namespace std;
struct Item
{
    string name;
    int price;
};
int main()
{
    Item items[3] = { {"Pen", 20}, {"Book", 350}, {"Bag", 1200} };
    int total = 0;
    for (int i = 0; i < 3; i++)
        total += items[i].price;
    cout << total << " " << items[1].name[0] << items[2].name.length();
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
struct Student
{
    int roll;
    double cgpa;
};
int main()
{
    Student s = {1, 3.5};
    cout << s;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string grade = 'A';
    cout << grade;
    return 0;
}
```
