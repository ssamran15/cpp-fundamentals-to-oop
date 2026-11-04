// P25.1: A friend function of two distance classes
#include <iostream>
using namespace std;

class DistanceBritish;          // declared early, so DistanceMetric can mention it

class DistanceMetric
{
private:
    int metres, cm;

public:
    DistanceMetric(int m, int c) : metres(m), cm(c) {}
    friend void addAndShow(const DistanceMetric &a, const DistanceBritish &b);
};

class DistanceBritish
{
private:
    int feet, inches;

public:
    DistanceBritish(int f, int i) : feet(f), inches(i) {}
    friend void addAndShow(const DistanceMetric &a, const DistanceBritish &b);
};

void addAndShow(const DistanceMetric &a, const DistanceBritish &b)
{
    double fromMetric = a.metres * 100 + a.cm;                          // in cm
    double fromBritish = (b.feet + b.inches / 12.0) * 0.3048 * 100;     // in cm
    int total = static_cast<int>(fromMetric + fromBritish + 0.5);       // rounded

    cout << a.metres << " m " << a.cm << " cm + " << b.feet << " ft " << b.inches
         << " in = " << total / 100 << " m " << total % 100 << " cm" << endl;
}

int main()
{
    DistanceMetric d1(3, 40);
    DistanceBritish d2(5, 6);
    addAndShow(d1, d2);

    DistanceMetric d3(0, 75);
    DistanceBritish d4(10, 0);
    addAndShow(d3, d4);
    return 0;
}
