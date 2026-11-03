// P12.13: Billing with typedef Rupees
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

typedef double Rupees;

int main()
{
    const int ITEMS = 3;
    string name;
    Rupees price, lineTotal, grandTotal = 0;
    int qty;

    cout << fixed << setprecision(2);
    for (int i = 1; i <= ITEMS; i++)
    {
        cout << "Item " << i << " (name price quantity): ";
        cin >> name >> price >> qty;
        lineTotal = price * qty;
        grandTotal += lineTotal;
        cout << "  " << name << ": " << qty << " x Rs. " << price
             << " = Rs. " << lineTotal << endl;
    }
    cout << "Grand total: Rs. " << grandTotal << endl;
    return 0;
}
