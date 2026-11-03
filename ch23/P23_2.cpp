// P23.2: A Fraction class with arithmetic and comparison operators
#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

    static int gcd(int a, int b)
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void reduce()
    {
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d == 0 ? 1 : d)
    {
        reduce();
    }

    Fraction operator+(const Fraction &f) const { return Fraction(num * f.den + f.num * den, den * f.den); }
    Fraction operator-(const Fraction &f) const { return Fraction(num * f.den - f.num * den, den * f.den); }
    Fraction operator*(const Fraction &f) const { return Fraction(num * f.num, den * f.den); }
    Fraction operator/(const Fraction &f) const { return Fraction(num * f.den, den * f.num); }

    bool operator==(const Fraction &f) const { return num == f.num && den == f.den; }   // both reduced
    bool operator<(const Fraction &f) const { return num * f.den < f.num * den; }      // dens are positive

    void show() const
    {
        cout << num;
        if (den != 1)
            cout << "/" << den;
    }
};

int main()
{
    Fraction a(1, 2), b(3, 4);

    a.show(); cout << " + "; b.show(); cout << " = "; (a + b).show(); cout << endl;
    a.show(); cout << " - "; b.show(); cout << " = "; (a - b).show(); cout << endl;
    a.show(); cout << " * "; b.show(); cout << " = "; (a * b).show(); cout << endl;
    a.show(); cout << " / "; b.show(); cout << " = "; (a / b).show(); cout << endl;

    Fraction c(2, 4);
    cout << "1/2 == 2/4? " << (a == c ? "yes" : "no") << endl;
    cout << "1/2 < 3/4? " << (a < b ? "yes" : "no") << endl;
    cout << "3/4 < 1/2? " << (b < a ? "yes" : "no") << endl;
    return 0;
}
