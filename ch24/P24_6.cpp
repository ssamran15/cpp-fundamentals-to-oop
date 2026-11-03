// P24.6: Converting between Kilogram and Pound
#include <iostream>
using namespace std;

class Kilogram
{
private:
    double kg;

public:
    Kilogram(double k = 0) : kg(k) {}
    double value() const { return kg; }
};

class Pound
{
private:
    double lb;

public:
    Pound(double l = 0) : lb(l) {}

    Pound(const Kilogram &k) : lb(k.value() * 2.20462) {}  // Kilogram -> Pound: a constructor

    operator Kilogram() const                               // Pound -> Kilogram: a conversion operator
    {
        return Kilogram(lb / 2.20462);
    }

    double value() const { return lb; }
};

int main()
{
    Kilogram rice(5);
    Pound p = rice;                 // uses Pound(const Kilogram &)
    cout << rice.value() << " kg = " << p.value() << " lb" << endl;

    Pound flour(22);
    Kilogram k = flour;             // uses Pound::operator Kilogram()
    cout << flour.value() << " lb = " << k.value() << " kg" << endl;
    return 0;
}
