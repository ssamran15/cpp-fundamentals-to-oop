// P26.7: ClockTime overrides show() to print 12-hour time
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
protected:
    int hours, minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    void show() const
    {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << setfill(' ');
    }
};

class ClockTime : public Time
{
public:
    ClockTime(int h, int m) : Time(h, m) {}

    void show() const
    {
        int h = hours % 12;
        if (h == 0)
            h = 12;                     // 0:xx is 12 AM and 12:xx is 12 PM
        cout << h << ":" << setfill('0') << setw(2) << minutes << setfill(' ')
             << (hours < 12 ? " AM" : " PM");
    }
};

int main()
{
    int times[5][2] = { {14, 5}, {0, 30}, {9, 45}, {12, 0}, {23, 59} };
    for (int i = 0; i < 5; i++)
    {
        Time t(times[i][0], times[i][1]);
        ClockTime c(times[i][0], times[i][1]);
        t.show();
        cout << "  ->  ";
        c.show();
        cout << endl;
    }
    return 0;
}
