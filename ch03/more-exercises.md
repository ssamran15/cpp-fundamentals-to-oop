# Chapter 3: Your First C++ Program

## More Exercises

These exercises continue the Exercises section of Chapter 3 in the book. The book has Q1 to Q6; the numbering continues here.

### Determine the output

**Q7.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    cout << "A\tB\nC\\D\n";
    cout << "\"Done\"";
    return 0;
}
```

**Q8.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    // cout << "Hidden";
    cout << "Shown"; /* cout << "Also hidden"; */
    cout << endl << "End";
    return 0;
}
```

### Find the error

**Q9.**

```cpp
#include <iostream>
using namespace std;
int main()
{
    cout << "Hello" << endl
    cout << "World << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
using namespace std;
int mian()
{
    cout << "Hello";
    return 0;
}
```
