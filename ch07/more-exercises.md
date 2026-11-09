# Chapter 7: Loops

## More Exercises

These exercises continue the Exercises section of Chapter 7 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i = 10; i > 0; i -= 3)
        cout << i << " ";
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int s = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (i == 3)
            continue;
        s += i;
    }
    cout << "s = " << s;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 2; j++)
            x++;
    cout << "x = " << x;
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
    int n = 5;
    do
    {
        cout << n;
        n--;
    } while (n > 0)
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 5; i++)
        cout << i << " ";
    cout << "Last value: " << i;
    return 0;
}
```

**Q14.** This program should print the sum of 1 to 10 but prints 45. Why?

```cpp
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    for (int i = 1; i < 10; i++)
        sum += i;
    cout << "Sum of 1 to 10 = " << sum;
    return 0;
}
```
