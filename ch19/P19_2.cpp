// P19.2: A Complex class with overloaded constructors
#include <iostream>
using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex()                 { re = 0; im = 0; }
    Complex(double r)         { re = r; im = 0; }
    Complex(double r, double i) { re = r; im = i; }

    Complex add(Complex c)
    {
        return Complex(re + c.re, im + c.im);
    }

    void show()
    {
        cout << re;
        if (im >= 0)
            cout << " + " << im << "i" << endl;
        else
            cout << " - " << -im << "i" << endl;
    }
};

int main()
{
    Complex a;                  // 0 + 0i
    Complex b(4.5);             // 4.5 + 0i
    Complex c(3, -2);           // 3 - 2i

    cout << "a = "; a.show();
    cout << "b = "; b.show();
    cout << "c = "; c.show();

    Complex sum = b.add(c);
    cout << "b + c = "; sum.show();
    return 0;
}
