// P6.7: Income tax on a monthly salary
#include <iostream>
using namespace std;

int main()
{
    double salary;
    cout << "Monthly salary: Rs. ";
    cin >> salary;

    double tax;
    if (salary <= 50000)
        tax = 0;
    else if (salary <= 100000)
        tax = (salary - 50000) * 5 / 100;
    else
        tax = 50000 * 5 / 100 + (salary - 100000) * 10 / 100;

    cout << "Income tax: Rs. " << tax << endl;
    return 0;
}
