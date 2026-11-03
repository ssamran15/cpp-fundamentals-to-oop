// P18.2: A Date class that rejects invalid dates
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

    bool isLeap(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    int daysInMonth(int m, int y)
    {
        switch (m)
        {
            case 2:  return isLeap(y) ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

public:
    bool setDate(int d, int m, int y)
    {
        if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y))
            return false;
        day = d;
        month = m;
        year = y;
        return true;
    }

    void show()
    {
        if (day < 10) cout << '0';
        cout << day << '/';
        if (month < 10) cout << '0';
        cout << month << '/' << year << endl;
    }
};

int main()
{
    Date date;
    date.setDate(1, 1, 2026);           // a valid starting date

    int d, m, y;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Enter day month year: ";
        cin >> d >> m >> y;
        if (date.setDate(d, m, y))
        {
            cout << "Date set: ";
            date.show();
        }
        else
            cout << "Invalid date, not accepted" << endl;
    }
    return 0;
}
