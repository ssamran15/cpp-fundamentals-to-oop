// P16.6: Days in a month with an enum
#include <iostream>
using namespace std;

enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main()
{
    int m;
    cout << "Enter a month number (1 to 12): ";
    cin >> m;

    switch (static_cast<Month>(m))
    {
        case JAN: case MAR: case MAY: case JUL: case AUG: case OCT: case DEC:
            cout << "31 days" << endl;
            break;
        case APR: case JUN: case SEP: case NOV:
            cout << "30 days" << endl;
            break;
        case FEB:
            cout << "28 days (29 in a leap year)" << endl;
            break;
        default:
            cout << "Invalid month" << endl;
    }
    return 0;
}
