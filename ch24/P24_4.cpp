// P24.4: A Discount function object
#include <iostream>
#include <iomanip>
using namespace std;

class Discount
{
private:
    double percent;

public:
    Discount(double p) : percent(p >= 0 && p <= 100 ? p : 0) {}

    double operator()(double price) const
    {
        return price - price * percent / 100;
    }
};

int main()
{
    double prices[5] = {2500, 1800, 4200, 950, 6000};
    Discount eidSale(30);                   // 30% off

    cout << fixed << setprecision(2);
    cout << "Eid sale, 30% off" << endl;
    for (int i = 0; i < 5; i++)
        cout << "Rs. " << setw(8) << prices[i] << "  ->  Rs. " << setw(8) << eidSale(prices[i]) << endl;
    return 0;
}
