// P6.5: Profit or loss
#include <iostream>
using namespace std;

int main()
{
    double cost, sale;
    cout << "Cost price: Rs. ";
    cin >> cost;
    cout << "Sale price: Rs. ";
    cin >> sale;

    if (sale > cost)
        cout << "Profit of Rs. " << sale - cost << endl;
    else if (cost > sale)
        cout << "Loss of Rs. " << cost - sale << endl;
    else
        cout << "No profit, no loss" << endl;
    return 0;
}
