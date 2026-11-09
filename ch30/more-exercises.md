# Chapter 30: Streams and Object File I/O

## More Exercises

These exercises continue the Exercises section of Chapter 30 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    istringstream in("12abc 7");
    int a = 0, b = 0;
    in >> a;
    in >> b;
    cout << a << " " << b << " " << in.fail() << in.eof() << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
#include <fstream>
using namespace std;
class Point
{
private:
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    friend ostream &operator<<(ostream &out, const Point &p) { return out << p.x << " " << p.y; }
    friend istream &operator>>(istream &in, Point &p) { return in >> p.x >> p.y; }
    int sum() const { return x + y; }
};
int main()
{
    ofstream out("points.txt");
    out << Point(1, 2) << endl << Point(3, 4) << endl << Point(5, 6) << endl;
    out.close();
    ifstream in("points.txt");
    Point p;
    int total = 0;
    while (in >> p)
        total += p.sum();
    cout << total << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    ofstream out("nums.dat", ios::binary);
    out.write(reinterpret_cast<const char *>(a), sizeof(a));
    out.close();
    ifstream in("nums.dat", ios::binary);
    int x;
    in.seekg(2 * sizeof(int), ios::beg);
    in.read(reinterpret_cast<char *>(&x), sizeof(int));
    cout << x << " ";
    in.seekg(-static_cast<int>(sizeof(int)), ios::end);
    in.read(reinterpret_cast<char *>(&x), sizeof(int));
    cout << x << endl;
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    istringstream in("10 abc 20");
    int a = 0, b = 0, c = 0;
    string s;
    in >> a >> b;
    cout << a << " " << b << " " << in.good() << endl;
    in.clear();
    in >> s >> c;
    cout << s << " " << c << " " << in.good() << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
#include <fstream>
using namespace std;
struct Product
{
    int code;
    double price;
};
int main()
{
    Product p = { 101, 120 };
    ofstream out("p.dat", ios::binary);
    out.write(&p, sizeof(p));
    out.close();
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("marks.txt");
    in << "Ali 78" << endl;
    in.close();
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    istringstream in("10 20 30");
    int x, sum = 0;
    while (in >> x)
        sum += x;
    cout << sum << endl;
    return 0;
}
```
