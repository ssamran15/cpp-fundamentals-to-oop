// P4.1: Total marks and percentage of five subjects
#include <iostream>
using namespace std;

int main()
{
    double m1, m2, m3, m4, m5;
    cout << "Enter marks of five subjects: ";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;

    double total = m1 + m2 + m3 + m4 + m5;
    double percentage = total / 500 * 100;

    cout << "Total marks: " << total << endl;
    cout << "Percentage : " << percentage << "%" << endl;
    return 0;
}
