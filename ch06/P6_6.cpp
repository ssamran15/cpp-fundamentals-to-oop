// P6.6: Electricity bill with three slabs
#include <iostream>
using namespace std;

int main()
{
    int units;
    cout << "Units consumed: ";
    cin >> units;

    double bill;
    if (units <= 100)
        bill = units * 20;
    else if (units <= 200)
        bill = 100 * 20 + (units - 100) * 25;
    else
        bill = 100 * 20 + 100 * 25 + (units - 200) * 30;

    cout << "Bill: Rs. " << bill << endl;
    return 0;
}
