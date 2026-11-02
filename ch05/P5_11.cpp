// P5.11: Compound profit
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double principal, rate;
    int years;
    cout << "Principal amount: Rs. ";
    cin >> principal;
    cout << "Profit rate (% per year): ";
    cin >> rate;
    cout << "Number of years: ";
    cin >> years;

    double amount = principal * pow(1 + rate / 100, years);
    cout << fixed << setprecision(2);
    cout << "Amount after " << years << " years: Rs. " << amount << endl;
    return 0;
}
