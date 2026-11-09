# Chapter 10: Arrays

## More Exercises

These exercises continue the Exercises section of Chapter 10 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2};
    for (int i = 0; i < 5; i++)
        cout << a[i];
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i += 2)
        cout << a[i] + a[i + 1] << " ";
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        a[i] = i * i;
    cout << a[a[2]] << " " << a[4 - a[1]];
    return 0;
}
```

**Q11.** This is one pass of bubble sort.

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {5, 1, 4, 2, 8};
    for (int i = 0; i < 4; i++)
        if (a[i] > a[i + 1])
        {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[5];
    a = {1, 2, 3, 4, 5};
    cout << a[0];
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    float x[2.5];
    cout << x[0];
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
void show(int arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i];
}
int main()
{
    int a[3] = {1, 2, 3};
    show(a, 3);
    return 0;
}
```
