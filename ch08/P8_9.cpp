// P8.9: Income tax
#include <iostream>
#include <iomanip>
using namespace std;

double calculateTax(double salary);

int main()
{
    double salary;
    cout << "Enter monthly salary (Rs.): ";
    cin >> salary;
    cout << fixed << setprecision(2);
    cout << "Tax = Rs. " << calculateTax(salary) << endl;
    return 0;
}

double calculateTax(double salary)
{
    if (salary <= 50000)
        return 0;
    else if (salary <= 100000)
        return (salary - 50000) * 0.05;
    else
        return 50000 * 0.05 + (salary - 100000) * 0.10;
}
