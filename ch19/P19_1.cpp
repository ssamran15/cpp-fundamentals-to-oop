// P19.1: A Fraction class with constructors
#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

    int gcd(int a, int b)
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

public:
    Fraction()                          // default constructor: 0/1
    {
        num = 0;
        den = 1;
    }

    Fraction(int n, int d)
    {
        if (d == 0)
        {
            cout << "Zero denominator replaced with 1" << endl;
            d = 1;
        }
        if (d < 0)                      // keep the sign in the numerator
        {
            n = -n;
            d = -d;
        }
        int g = gcd(n, d);
        num = n / g;
        den = d / g;
    }

    void show()
    {
        cout << num << "/" << den << endl;
    }
};

int main()
{
    Fraction a;
    Fraction b(6, 8);
    Fraction c(-10, -25);
    Fraction d(4, 0);

    cout << "a = "; a.show();
    cout << "b = "; b.show();
    cout << "c = "; c.show();
    cout << "d = "; d.show();
    return 0;
}
