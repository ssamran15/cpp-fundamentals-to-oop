// P27.8: Utility bills through an interface
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class UtilityBill                       // an interface: only pure virtual functions
{
public:
    virtual ~UtilityBill() {}
    virtual string company() const = 0;
    virtual double amount(int units) const = 0;
};

// Practice rates only, not real tariffs.
class ElectricityBill : public UtilityBill
{
public:
    string company() const override { return "City Electric Co."; }
    double amount(int units) const override
    {
        if (units <= 100) return units * 12.0;
        if (units <= 300) return 100 * 12.0 + (units - 100) * 18.0;
        return 100 * 12.0 + 200 * 18.0 + (units - 300) * 25.0;
    }
};

class GasBill : public UtilityBill
{
public:
    string company() const override { return "City Gas Co."; }
    double amount(int units) const override
    {
        if (units <= 50) return units * 20.0;
        return 50 * 20.0 + (units - 50) * 35.0;
    }
};

class WaterBill : public UtilityBill
{
public:
    string company() const override { return "City Water Board"; }
    double amount(int units) const override
    {
        return 300 + units * 2.0;       // fixed charge plus a rate per unit
    }
};

int main()
{
    ElectricityBill e;
    GasBill g;
    WaterBill w;
    UtilityBill *bills[3] = { &e, &g, &w };

    double total = 0;
    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++)
    {
        int units;
        cout << "Units used for " << bills[i]->company() << ": ";
        cin >> units;
        double a = bills[i]->amount(units);
        cout << "  Bill: Rs. " << a << endl;
        total += a;
    }
    cout << "Total of the three bills: Rs. " << total << endl;
    return 0;
}
