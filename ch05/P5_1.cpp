// P5.1: Sum, difference, product, quotient and remainder
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;     // integer division
    cout << a << " % " << b << " = " << a % b << endl;     // remainder
    return 0;
}
