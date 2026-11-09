# Chapter 32: The Standard Library vector

## More Exercises

These exercises continue the Exercises section of Chapter 32 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3 };
    for (int x : v)
        x = x * 10;
    for (int x : v)
        cout << x << " ";
    for (int &x : v)
        x = x * 10;
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool bigger(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> v = { 40, 15, 75, 15, 60 };
    sort(v.begin(), v.end(), bigger);
    cout << v[0] << " " << v[1] << " " << count(v.begin(), v.end(), 15) << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> g(2, vector<int>(3, 1));
    g[1].push_back(4);
    int sum = 0;
    for (const auto &row : g)
        for (int x : row)
            sum += x;
    cout << g.size() << " " << g[0].size() << " " << g[1].size() << " " << sum << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> names = { "Ali", "Sana", "Hamza", "Ayesha" };
    auto it = find(names.begin(), names.end(), "Hamza");
    cout << it - names.begin() << " ";
    it = find(names.begin(), names.end(), "Usman");
    cout << (it == names.end()) << " " << names.end() - names.begin() << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back("ten");
    cout << v.size() << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> marks = { 72, 85, 64 };
    for (int i = 0; i < marks.length(); i++)
        cout << marks[i] << " ";
    cout << endl;
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
#include <vector>
using namespace std;
double average(const vector<double> &v)
{
    double total = 0;
    for (double x : v)
        total += x;
    return total / v.size();
}
int main()
{
    vector<int> marks = { 72, 85, 64 };
    cout << average(marks) << endl;
    return 0;
}
```
