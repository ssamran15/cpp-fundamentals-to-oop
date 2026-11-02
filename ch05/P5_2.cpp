// P5.2: Total and percentage with two decimal places
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m1, m2, m3, m4, m5;
    cout << "Enter marks of five subjects: ";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;

    int total = m1 + m2 + m3 + m4 + m5;
    double percentage = static_cast<double>(total) / 500 * 100;

    cout << fixed << setprecision(2);
    cout << "Total      : " << total << " / 500" << endl;
    cout << "Percentage : " << percentage << "%" << endl;
    return 0;
}
