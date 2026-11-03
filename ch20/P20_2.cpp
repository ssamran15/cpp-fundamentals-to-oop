// P20.2: A Calculator with cascaded calls
#include <iostream>
using namespace std;

class Calculator
{
private:
    double value;

public:
    Calculator() : value(0) {}

    Calculator &set(double x)      { value = x;  return *this; }
    Calculator &add(double x)      { value += x; return *this; }
    Calculator &subtract(double x) { value -= x; return *this; }
    Calculator &multiply(double x) { value *= x; return *this; }

    Calculator &divide(double x)
    {
        if (x == 0)
            cout << "(division by zero ignored) ";
        else
            value /= x;
        return *this;
    }

    void show()
    {
        cout << "Result = " << value << endl;
    }
};

int main()
{
    Calculator c;
    c.set(10).add(5).multiply(3).subtract(2).show();      // ((10 + 5) * 3) - 2
    c.set(100).divide(8).add(0.5).show();
    c.set(7).divide(0).multiply(2).show();
    return 0;
}
