// P12.14: A union with three members
#include <iostream>
using namespace std;

union Value
{
    int i;
    float f;
    char c;
};

int main()
{
    Value v;

    v.i = 2026;
    cout << "As int:   " << v.i << endl;

    v.f = 3.75f;                 // overwrites the int
    cout << "As float: " << v.f << endl;

    v.c = 'Z';                   // overwrites part of the float
    cout << "As char:  " << v.c << endl;

    cout << "Size of the union: " << sizeof(Value) << " bytes" << endl;
    return 0;
}
