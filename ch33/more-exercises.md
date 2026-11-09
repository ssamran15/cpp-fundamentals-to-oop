# Chapter 33: Exception Handling

## More Exercises

These exercises continue the Exercises section of Chapter 33 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
int check(int n)
{
    if (n % 2 != 0)
        throw n;
    return n / 2;
}
int main()
{
    int a[4] = { 8, 6, 5, 4 };
    for (int i = 0; i < 4; i++)
    {
        try
        {
            cout << check(a[i]) << " ";
        }
        catch (int n)
        {
            cout << "odd" << n << " ";
        }
    }
    cout << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    try
    {
        throw out_of_range("index 9");
    }
    catch (const logic_error &e)
    {
        cout << "logic_error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "exception: " << e.what() << endl;
    }
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <string>
using namespace std;
void g()
{
    try
    {
        throw string("low");
    }
    catch (const string &s)
    {
        cout << "g: " << s << endl;
        throw;
    }
}
int main()
{
    try
    {
        g();
    }
    catch (const string &s)
    {
        cout << "main: " << s << endl;
    }
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s[4] = { "12", "7x", "abc", "40" };
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        try
        {
            sum += stoi(s[i]);
        }
        catch (...)
        {
            cout << "skip " << s[i] << endl;
        }
    }
    cout << "sum = " << sum << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
int main()
{
    vector<int> v(3);
    try
    {
        v.at(8) = 1;
    }
    catch (const exception &e)
    {
        cout << "General error" << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Index problem: " << e.what() << endl;
    }
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    try
    {
        throw runtime_error("file marks.txt not found");
    }
    catch (exception e)
    {
        cout << "Error: " << e.what() << endl;
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
    int age = -3;
    try
    {
        if (age < 0)
            throw age;
    }
    cout << "Age: " << age << endl;
    return 0;
}
```
