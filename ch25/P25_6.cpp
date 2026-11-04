// P25.6: Reading dd/mm/yyyy and printing "15 Mar 2026"
#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    friend istream &operator>>(istream &in, Date &d);
    friend ostream &operator<<(ostream &out, const Date &d);
    friend bool operator==(const Date &a, const Date &b);
    friend bool operator<(const Date &a, const Date &b);
};

istream &operator>>(istream &in, Date &d)
{
    int dd, mm, yy;
    char s1, s2;
    in >> dd >> s1 >> mm >> s2 >> yy;
    if (s1 != '/' || s2 != '/' || mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy < 1)
        in.setstate(ios::failbit);              // mark the input as failed
    else
    {
        d.day = dd;
        d.month = mm;
        d.year = yy;
    }
    return in;
}

ostream &operator<<(ostream &out, const Date &d)
{
    const char *names[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    out << d.day << " " << names[d.month - 1] << " " << d.year;
    return out;
}

bool operator==(const Date &a, const Date &b)
{
    return a.day == b.day && a.month == b.month && a.year == b.year;
}

bool operator<(const Date &a, const Date &b)
{
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main()
{
    Date first, second;
    cout << "Enter two dates (dd/mm/yyyy dd/mm/yyyy): ";
    cin >> first >> second;
    if (!cin)
    {
        cout << "Invalid date entered." << endl;
        return 1;
    }

    if (first == second)
        cout << "Both dates are " << first << endl;
    else if (first < second)
        cout << "The earlier date is " << first << endl;
    else
        cout << "The earlier date is " << second << endl;
    return 0;
}
