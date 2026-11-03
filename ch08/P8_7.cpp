// P8.7: Power with a loop
#include <iostream>
using namespace std;

long long power(int base, int exp);

int main()
{
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << base << "^" << exp << " = " << power(base, exp) << endl;
    return 0;
}

long long power(int base, int exp)
{
    long long result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}
