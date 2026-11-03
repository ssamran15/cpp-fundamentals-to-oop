// P24.2: A Polynomial with [] for coefficients and () for evaluation
#include <iostream>
using namespace std;

class Polynomial
{
private:
    double coeff[10];               // coeff[i] is the coefficient of x^i
    double dummy;

public:
    Polynomial() : dummy(0)
    {
        for (int i = 0; i < 10; i++)
            coeff[i] = 0;
    }

    double &operator[](int i)
    {
        if (i < 0 || i >= 10)
        {
            cout << "[power " << i << " not allowed]" << endl;
            dummy = 0;
            return dummy;
        }
        return coeff[i];
    }

    double operator()(double x) const      // Horner's method
    {
        double result = 0;
        for (int i = 9; i >= 0; i--)
            result = result * x + coeff[i];
        return result;
    }

    void show() const
    {
        bool first = true;
        for (int i = 9; i >= 0; i--)
        {
            if (coeff[i] == 0)
                continue;
            if (!first)
                cout << " + ";
            cout << coeff[i];
            if (i >= 1) cout << "x";
            if (i >= 2) cout << "^" << i;
            first = false;
        }
        if (first)
            cout << 0;
        cout << endl;
    }
};

int main()
{
    Polynomial p;
    p[2] = 3;                       // 3x^2
    p[1] = 2;                       // + 2x
    p[0] = 5;                       // + 5
    p[12] = 1;                      // refused

    cout << "p(x) = ";
    p.show();
    cout << "Coefficient of x: " << p[1] << endl;
    for (int x = 0; x <= 3; x++)
        cout << "p(" << x << ") = " << p(x) << endl;
    return 0;
}
