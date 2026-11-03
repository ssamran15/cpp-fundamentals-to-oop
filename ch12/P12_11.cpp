// P12.11: Fractions
#include <iostream>
using namespace std;

struct Fraction
{
    int num;
    int den;
};

int gcd(int a, int b);
Fraction reduce(Fraction f);
Fraction add(Fraction a, Fraction b);
Fraction multiply(Fraction a, Fraction b);
void show(Fraction f);

int main()
{
    Fraction a, b;
    cout << "First fraction (numerator denominator): ";
    cin >> a.num >> a.den;
    cout << "Second fraction (numerator denominator): ";
    cin >> b.num >> b.den;

    show(a); cout << " + "; show(b); cout << " = "; show(add(a, b)); cout << endl;
    show(a); cout << " x "; show(b); cout << " = "; show(multiply(a, b)); cout << endl;
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

Fraction reduce(Fraction f)
{
    int g = gcd(f.num, f.den);
    if (g != 0)
    {
        f.num /= g;
        f.den /= g;
    }
    return f;
}

Fraction add(Fraction a, Fraction b)
{
    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    return reduce(r);
}

Fraction multiply(Fraction a, Fraction b)
{
    Fraction r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    return reduce(r);
}

void show(Fraction f)
{
    cout << f.num << "/" << f.den;
}
