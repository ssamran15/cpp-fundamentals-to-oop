// P5.6: Days to years, weeks and days
#include <iostream>
using namespace std;

int main()
{
    int days;
    cout << "Number of days: ";
    cin >> days;

    int years = days / 365;
    int rest = days % 365;
    int weeks = rest / 7;
    int remaining = rest % 7;

    cout << days << " days = " << years << " years, " << weeks
         << " weeks and " << remaining << " days" << endl;
    return 0;
}
