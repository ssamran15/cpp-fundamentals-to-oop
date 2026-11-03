// P8.13: GCD and LCM
#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    int a, b;
    cout << "Enter two positive numbers: ";
    cin >> a >> b;
    cout << "GCD = " << gcd(a, b) << endl;
    cout << "LCM = " << lcm(a, b) << endl;
    return 0;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
