// P4.12: Salary slip
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double basic;
    cout << "Basic salary: ";
    cin >> basic;

    double houseRent = basic * 45 / 100;
    double medical = basic * 10 / 100;
    double gross = basic + houseRent + medical;

    cout << fixed << setprecision(2);
    cout << endl << "        SALARY SLIP" << endl;
    cout << "Basic salary : " << setw(12) << basic << endl;
    cout << "House rent   : " << setw(12) << houseRent << endl;
    cout << "Medical      : " << setw(12) << medical << endl;
    cout << "Gross salary : " << setw(12) << gross << endl;
    return 0;
}
