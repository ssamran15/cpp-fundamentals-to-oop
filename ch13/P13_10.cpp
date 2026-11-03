// P13.10: Month names in an array of const char *
#include <iostream>
using namespace std;

int main()
{
    const char *months[12] = {"January", "February", "March", "April",
                              "May", "June", "July", "August",
                              "September", "October", "November", "December"};
    int m;
    cout << "Enter a month number: ";
    cin >> m;

    if (m < 1 || m > 12)
        cout << "Error: the month number must be from 1 to 12" << endl;
    else
        cout << "Month " << m << " is " << months[m - 1] << endl;
    return 0;
}
