# Chapter 6: Decision Making

## More Exercises

These exercises continue the Exercises section of Chapter 6 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    if (x = 5)
        cout << "Five";
    else
        cout << "Zero";
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n = 3;
    switch (n)
    {
        case 1: cout << "One";
        case 3: cout << "Three";
        case 4: cout << "Four"; break;
        default: cout << "Other";
    }
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x = 10, y = 20;
    int z = (x > y) ? x : y;
    cout << z << " " << (x % 2 == 0 ? "Even" : "Odd") << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    if (i != 0 && 10 / i > 1)
        cout << "Yes";
    else
        cout << "No";
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
    int marks = 60;
    if (marks >= 50);
        cout << "Pass";
    else
        cout << "Fail";
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int marks = 85;
    switch (marks)
    {
        case marks >= 80: cout << "A"; break;
        case marks >= 65: cout << "B"; break;
    }
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int choice = 2;
    switch (choice)
    {
        case 1: cout << "Tea"; break;
        case 2: cout << "Coffee"; break;
        case 2: cout << "Juice"; break;
    }
    return 0;
}
```
