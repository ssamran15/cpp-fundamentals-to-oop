// P25.5: Complex with friend operators and stream operators
#include <iostream>
using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    friend Complex operator+(const Complex &a, const Complex &b);
    friend Complex operator-(const Complex &a, const Complex &b);
    friend Complex operator*(const Complex &a, const Complex &b);
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
};

Complex operator+(const Complex &a, const Complex &b) { return Complex(a.re + b.re, a.im + b.im); }
Complex operator-(const Complex &a, const Complex &b) { return Complex(a.re - b.re, a.im - b.im); }

Complex operator*(const Complex &a, const Complex &b)
{
    return Complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.re << (c.im >= 0 ? " + " : " - ") << (c.im >= 0 ? c.im : -c.im) << "i";
    return out;
}

istream &operator>>(istream &in, Complex &c)
{
    in >> c.re >> c.im;             // real and imaginary parts, separated by a space
    return in;
}

int main()
{
    Complex a, b;
    cout << "First complex number (real imaginary): ";
    cin >> a;
    cout << "Second complex number (real imaginary): ";
    cin >> b;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a + 5 = " << a + 5 << endl;        // 5 becomes Complex(5, 0)
    cout << "5 + a = " << 5 + a << endl;        // works because + is not a member
    return 0;
}
