# Chapter 15: Files and the Preprocessor

## More Exercises

These exercises continue the Exercises section of Chapter 15 in the book. The book has Q1 to Q8; the numbering continues here.

### Determine the output

**Q9.**

```cpp
#include <iostream>
using namespace std;
#define MUL(a, b) a * b
int main()
{
    cout << MUL(2 + 3, 4) << " " << MUL(4, 2 + 3) << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream f("t.txt");
    f << "Pakistan\nZindabad";
    f.close();
    ifstream g("t.txt");
    string w;
    g >> w;
    cout << w.length() << " ";
    getline(g, w);
    cout << "[" << w << "]" << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
#define LEVEL 2
int main()
{
#if LEVEL > 1
    cout << "High";
#else
    cout << "Low";
#endif
#ifndef TEST
    cout << " NoTest";
#endif
    cout << endl;
    return 0;
}
```

**Q12.**

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream f("t.txt");
    f << "a b\nc";
    f.close();
    ifstream g("t.txt");
    char ch;
    int n1 = 0, n2 = 0;
    while (g.get(ch))
        n1++;
    g.close();
    g.open("t.txt");
    while (g >> ch)
        n2++;
    cout << n1 << " " << n2 << endl;
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
    ofstream out("a.txt");
    out << "Okara";
    out.close();
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
using namespace std;
#define MAX 100
int main()
{
    MAX = 200;
    cout << MAX << endl;
    return 0;
}
```

**Q15.**

```cpp
#include <iostream>
using namespace std;
#define SQUARE (x) ((x) * (x))
int main()
{
    cout << SQUARE(4) << endl;
    return 0;
}
```
