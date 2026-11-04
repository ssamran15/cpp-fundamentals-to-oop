// P33.3: A Date constructor that throws
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y)
    {
        if (m < 1 || m > 12)
            throw invalid_argument("month " + to_string(m) + " is not from 1 to 12");
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };   // leap years ignored
        if (d < 1 || d > days[m - 1])
            throw invalid_argument("day " + to_string(d) + " is not valid for month " + to_string(m));
    }

    void show() const { cout << day << "/" << month << "/" << year; }
};

void tryDate(int d, int m, int y)
{
    try
    {
        Date date(d, m, y);             // if this throws, date never exists
        cout << "Created ";
        date.show();
        cout << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Rejected " << d << "/" << m << "/" << y << ": " << e.what() << endl;
    }
}

int main()
{
    tryDate(14, 8, 2026);
    tryDate(31, 4, 2026);
    tryDate(25, 12, 2026);
    tryDate(10, 13, 2026);
    return 0;
}
