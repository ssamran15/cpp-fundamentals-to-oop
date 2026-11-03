// P16.4: Swapping with XOR
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Before: a = " << a << ", b = " << b << endl;

    a = a ^ b;
    b = a ^ b;          // (a ^ b) ^ b gives the old a
    a = a ^ b;          // (a ^ b) ^ old a gives the old b

    cout << "After:  a = " << a << ", b = " << b << endl;
    return 0;
}
