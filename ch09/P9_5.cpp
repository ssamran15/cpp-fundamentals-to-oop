// P9.5: Profit with default arguments
#include <iostream>
using namespace std;

double simpleProfit(double amount, double rate = 12.5, int years = 1);

int main()
{
    cout << "One argument:    " << simpleProfit(100000) << endl;
    cout << "Two arguments:   " << simpleProfit(100000, 15) << endl;
    cout << "Three arguments: " << simpleProfit(100000, 15, 3) << endl;
    return 0;
}

double simpleProfit(double amount, double rate, int years)
{
    return amount * rate / 100 * years;
}
