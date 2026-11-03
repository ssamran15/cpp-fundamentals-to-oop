// P21.3: A const Date object with const member functions
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isLeapYear() const
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int daysInMonth() const
    {
        switch (month)
        {
            case 2: return isLeapYear() ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

    void show() const
    {
        cout << day << "/" << month << "/" << year;
    }
};

int main()
{
    const Date independenceDay(14, 8, 1947);

    cout << "Independence Day: ";
    independenceDay.show();
    cout << endl;
    cout << "Days in that month: " << independenceDay.daysInMonth() << endl;
    cout << "Leap year? " << (independenceDay.isLeapYear() ? "yes" : "no") << endl;
    return 0;
}
