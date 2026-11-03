// P23.1: A Complex class with overloaded operators
#include <iostream>
using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    Complex operator+(const Complex &c) const { return Complex(re + c.re, im + c.im); }
    Complex operator-(const Complex &c) const { return Complex(re - c.re, im - c.im); }

    Complex operator*(const Complex &c) const
    {
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    bool operator==(const Complex &c) const { return re == c.re && im == c.im; }

    Complex operator-() const { return Complex(-re, -im); }     // unary minus

    void show() const
    {
        cout << re << (im >= 0 ? " + " : " - ") << (im >= 0 ? im : -im) << "i" << endl;
    }
};

int main()
{
    Complex a(3, 2), b(1, -4);

    cout << "a     = "; a.show();
    cout << "b     = "; b.show();
    cout << "a + b = "; (a + b).show();
    cout << "a - b = "; (a - b).show();
    cout << "a * b = "; (a * b).show();
    cout << "-a    = "; (-a).show();

    Complex c(3, 2);
    cout << "a == c? " << (a == c ? "yes" : "no") << endl;
    cout << "a == b? " << (a == b ? "yes" : "no") << endl;
    return 0;
}
