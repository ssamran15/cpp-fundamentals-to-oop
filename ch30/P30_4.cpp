// P30.4: Holidays in a chosen month
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
    int getMonth() const { return month; }

    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);
};

ostream &operator<<(ostream &out, const Date &d)
{
    out << setfill('0') << setw(2) << d.day << "/" << setw(2) << d.month << "/" << d.year << setfill(' ');
    return out;
}

istream &operator>>(istream &in, Date &d)
{
    char s1, s2;
    in >> d.day >> s1 >> d.month >> s2 >> d.year;
    if (in && (s1 != '/' || s2 != '/'))
        in.setstate(ios::failbit);
    return in;
}

int main()
{
    ifstream in("holidays.txt");
    if (!in)
    {
        cout << "Cannot open holidays.txt" << endl;
        return 1;
    }

    int month;
    cout << "Month (1 to 12): ";
    cin >> month;

    Date d;
    string name;
    int found = 0;
    while (in >> d && getline(in, name))        // the rest of the line is the name
    {
        if (!name.empty() && name[0] == ' ')
            name.erase(0, 1);                   // drop the space after the date
        if (d.getMonth() == month)
        {
            cout << d << " " << name << endl;
            found++;
        }
    }
    in.close();
    if (found == 0)
        cout << "No holidays in that month" << endl;
    return 0;
}
