# Chapter 11: Two-Dimensional Arrays and C-strings

## More Exercises

These exercises continue the Exercises section of Chapter 11 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    for (int i = 0; i < 3; i++)
        cout << a[i][2 - i] << " ";
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[] = "Okara";
    cout << sizeof(s) << " " << strlen(s);
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[20] = "Pak", b[] = "istan";
    strcat(a, b);
    cout << a << " " << strlen(a);
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    char s[] = "ABCDE";
    for (int i = 4; i >= 0; i -= 2)
        cout << s[i];
    cout << " " << s[1] + 1;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
void show(int m[][], int rows)
{
    cout << m[0][0];
}
int main()
{
    int a[2][2] = { {1, 2}, {3, 4} };
    show(a, 2);
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    char country[5] = "Pakistan";
    cout << country;
    return 0;
}
```
