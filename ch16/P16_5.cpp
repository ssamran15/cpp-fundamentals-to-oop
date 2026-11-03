// P16.5: Attendance of 8 days in one byte
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    unsigned char attendance = 0;       // all 8 bits start as 0 (absent)

    for (int day = 1; day <= 8; day++)
    {
        int present;
        cout << "Day " << day << " (1 present, 0 absent): ";
        cin >> present;
        if (present == 1)
            attendance |= (1 << (day - 1));     // day 1 is bit 0
    }

    cout << endl << "Stored byte: " << bitset<8>(attendance) << endl;
    cout << "Present on days:";
    int total = 0;
    for (int day = 1; day <= 8; day++)
    {
        if ((attendance >> (day - 1)) & 1)
        {
            cout << " " << day;
            total++;
        }
    }
    cout << endl << "Total days present: " << total << " out of 8" << endl;
    return 0;
}
