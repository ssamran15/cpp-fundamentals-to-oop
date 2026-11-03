// P23.5: A Date class with prefix and postfix ++
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

    bool isLeap() const
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int daysInMonth() const
    {
        switch (month)
        {
            case 2: return isLeap() ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date &operator++()              // prefix: ++d
    {
        day++;
        if (day > daysInMonth())
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int)            // postfix: d++ (the int only marks the postfix form)
    {
        Date old = *this;
        ++(*this);
        return old;                 // the value before the change
    }

    void show() const
    {
        cout << day << "/" << month << "/" << year;
    }
};

int main()
{
    Date d1(28, 2, 2024);
    ++d1;
    cout << "Day after 28/2/2024: "; d1.show(); cout << endl;
    ++d1;
    cout << "Next day: "; d1.show(); cout << endl;

    Date d2(31, 12, 2025);
    Date before = d2++;
    cout << "d2++ gave "; before.show(); cout << ", d2 is now "; d2.show(); cout << endl;

    Date d3(28, 2, 2026);
    ++d3;
    cout << "Day after 28/2/2026: "; d3.show(); cout << endl;
    return 0;
}
