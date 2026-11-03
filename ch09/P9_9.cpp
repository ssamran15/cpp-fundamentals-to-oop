// P9.9: Recursive GCD
#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
    int a, b;
    cout << "Enter two positive numbers: ";
    cin >> a >> b;
    cout << "GCD = " << gcd(a, b) << endl;
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)            // base case: gcd(a, 0) = a
        return a;
    return gcd(b, a % b);
}
