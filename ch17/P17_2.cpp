// P17.2: Adding fractions passed by const reference
#include <iostream>
using namespace std;

struct Fraction
{
    int num;
    int den;
};

int gcd(int a, int b);
Fraction add(const Fraction &a, const Fraction &b);

int main()
{
    Fraction a, b;
    cout << "First fraction (numerator denominator): ";
    cin >> a.num >> a.den;
    cout << "Second fraction (numerator denominator): ";
    cin >> b.num >> b.den;

    Fraction sum = add(a, b);
    cout << a.num << "/" << a.den << " + " << b.num << "/" << b.den
         << " = " << sum.num << "/" << sum.den << endl;
    return 0;
}

int gcd(int a, int b)
{
    if (a < 0) a = -a;
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Fraction add(const Fraction &a, const Fraction &b)
{
    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    int g = gcd(r.num, r.den);          // reduce to lowest terms
    if (g != 0)
    {
        r.num /= g;
        r.den /= g;
    }
    return r;
}
