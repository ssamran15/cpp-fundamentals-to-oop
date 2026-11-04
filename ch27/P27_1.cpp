// P27.1: Fares through an array of Vehicle pointers
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehicle
{
public:
    virtual ~Vehicle() {}
    virtual string name() const { return "Vehicle"; }
    virtual double fare(double) const { return 0; }
};

class Rickshaw : public Vehicle
{
public:
    string name() const override { return "Rickshaw"; }
    double fare(double km) const override { return 50 + 30 * km; }
};

class Taxi : public Vehicle
{
public:
    string name() const override { return "Taxi"; }
    double fare(double km) const override { return 150 + 55 * km; }
};

class Bus : public Vehicle
{
public:
    string name() const override { return "Bus"; }
    double fare(double km) const override
    {
        if (km <= 10)
            return 40;
        return 40 + 3 * (km - 10);
    }
};

int main()
{
    Rickshaw r;
    Taxi t;
    Bus b;
    Vehicle *list[3] = { &r, &t, &b };

    double km;
    cout << "Distance in km: ";
    cin >> km;

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++)             // the right fare() is chosen at run time
        cout << left << setw(10) << list[i]->name() << "Rs. " << list[i]->fare(km) << endl;
    return 0;
}
