# Chapter 4: Variables, Data Types and Input/Output

## More Exercises

These exercises continue the Exercises section of Chapter 4 in the book. The book has Q1 to Q6; the numbering continues here.

### Determine the output

**Q7.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    char c = 'A';
    c = c + 2;
    cout << c << " " << int(c) << endl;
    return 0;
}
```

**Q8.**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << setw(5) << 42 << "|" << endl;
    cout << fixed << setprecision(1) << 3.86 << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int total = 7.9;
    cout << total << endl;
    return 0;
}
```

### Find the error

**Q10.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin << x;
    cout << y;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    int class = 5;
    char grade = "A";
    cout << class << grade;
    return 0;
}
```
