// P19.3: A Date class with default arguments and validation
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

    bool valid(int d, int m, int y)
    {
        if (y < 1 || m < 1 || m > 12 || d < 1)
            return false;
        int days = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11)
            days = 30;
        else if (m == 2)
        {
            bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
            days = leap ? 29 : 28;
        }
        return d <= days;
    }

public:
    Date(int d = 1, int m = 1, int y = 2000)
    {
        if (valid(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    void show()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date d1;                    // all defaults
    Date d2(14);                // 14/1/2000
    Date d3(14, 8);             // 14/8/2000
    Date d4(29, 2, 2024);       // leap year: valid
    Date d5(29, 2, 2026);       // not a leap year: invalid

    cout << "d1: "; d1.show();
    cout << "d2: "; d2.show();
    cout << "d3: "; d3.show();
    cout << "d4: "; d4.show();
    cout << "d5: "; d5.show();
    return 0;
}
