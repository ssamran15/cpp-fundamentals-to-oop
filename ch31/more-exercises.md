# Chapter 31: Templates

## More Exercises

These exercises continue the Exercises section of Chapter 31 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
template <typename T>
T half(T x)
{
    return x / 2;
}
int main()
{
    cout << half(9) << " " << half(9.0) << " " << half<double>(9) << " " << half<int>(9.8) << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
template <typename T>
void describe(T x)
{
    cout << "general " << x << endl;
}
template <>
void describe<bool>(bool x)
{
    cout << "bool " << (x ? "yes" : "no") << endl;
}
int main()
{
    describe(10);
    describe(true);
    describe(2.5);
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <string>
using namespace std;
template <typename T>
void exchange(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x = 5, y = 9;
    string s = "Okara", t = "Lahore";
    exchange(x, y);
    exchange(s, t);
    cout << x << " " << y << " " << s << " " << t << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Stack
{
private:
    T items[10];
    int count = 0;
public:
    void push(T x) { items[count++] = x; }
    T pop() { return items[--count]; }
    bool isEmpty() const { return count == 0; }
};
int main()
{
    Stack<char> s;
    string word = "OKARA";
    for (int i = 0; i < 5; i++)
        s.push(word[i]);
    while (!s.isEmpty())
        cout << s.pop();
    cout << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    cout << maximum(10, 12.5) << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
template <typename T>
class Counter
{
private:
    T value;
public:
    Counter(T v);
    T get() const { return value; }
};
Counter<T>::Counter(T v) : value(v) {}
int main()
{
    Counter<int> c(5);
    cout << c.get() << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
template <T>
T square(T x)
{
    return x * x;
}
int main()
{
    cout << square(4) << endl;
    return 0;
}
```
