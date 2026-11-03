// P18.8: An ElectricityBill class with slab rates
#include <iostream>
#include <iomanip>
using namespace std;

class ElectricityBill
{
private:
    int units;

public:
    bool setUnits(int u)
    {
        if (u < 0)
            return false;
        units = u;
        return true;
    }

    int getUnits() { return units; }

    double amount()
    {
        // example rates for practice, not an actual tariff
        if (units <= 100)
            return units * 10.0;
        else if (units <= 200)
            return 100 * 10.0 + (units - 100) * 15.0;
        else
            return 100 * 10.0 + 100 * 15.0 + (units - 200) * 20.0;
    }
};

int main()
{
    ElectricityBill bill;
    int u;
    cout << "Units consumed: ";
    cin >> u;
    if (!bill.setUnits(u))
    {
        cout << "Units cannot be negative" << endl;
        return 1;
    }
    cout << fixed << setprecision(2);
    cout << "Bill for " << bill.getUnits() << " units: Rs. " << bill.amount() << endl;
    return 0;
}
