# Chapter 14: Dynamic Memory: new and delete

## More Exercises

These exercises continue the Exercises section of Chapter 14 in the book. The book has Q1 to Q8; the numbering continues here.

### Determine the output

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int *a = new int[4]{2, 4, 6, 8};
    cout << a[1] + *(a + 3) << " " << *a << endl;
    delete[] a;
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
int main()
{
    Point *p = new Point{3, 4};
    p->x *= 2;
    cout << p->x + p->y << endl;
    delete p;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int *p = nullptr;
    if (p)
        cout << "A";
    else
        cout << "B";
    p = new int(0);
    if (p)
        cout << "C";
    if (*p)
        cout << "D";
    cout << endl;
    delete p;
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char *s = new char[strlen("Multan") + 1];
    strcpy(s, "Multan");
    s[0] = 'm';
    cout << s << " " << strlen(s) << endl;
    delete[] s;
    return 0;
}
```

### Find the error

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int *p = &n;
    cout << *p << endl;
    delete p;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int *p = new int(10);
    p = new int(20);
    cout << *p << endl;
    delete p;
    return 0;
}
```

**Q15.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    double *d = new int;
    *d = 2.5;
    delete d;
    return 0;
}
```
