// P15.10: Macros with correct brackets
#include <iostream>
using namespace std;

#define CUBE(x) ((x) * (x) * (x))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define IS_EVEN(n) ((n) % 2 == 0)

int main()
{
    cout << "CUBE(3)          = " << CUBE(3) << endl;
    cout << "CUBE(1 + 2)      = " << CUBE(1 + 2) << endl;
    cout << "100 / CUBE(2)    = " << 100 / CUBE(2) << endl;
    cout << "MIN(17, 42)      = " << MIN(17, 42) << endl;
    cout << "MIN(10 - 8, 1)   = " << MIN(10 - 8, 1) << endl;
    cout << "2 * MIN(3, 5)    = " << 2 * MIN(3, 5) << endl;
    cout << "IS_EVEN(14)      = " << IS_EVEN(14) << endl;
    cout << "IS_EVEN(7 + 2)   = " << IS_EVEN(7 + 2) << endl;
    return 0;
}
