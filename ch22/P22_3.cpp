// P22.3: A Flight composed of two Time objects
#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int hours, minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    int totalMinutes() const { return hours * 60 + minutes; }

    void show() const
    {
        if (hours < 10) cout << '0';
        cout << hours << ':';
        if (minutes < 10) cout << '0';
        cout << minutes;
    }
};

class Flight
{
private:
    string number;
    Time departure;
    Time arrival;

public:
    Flight(string n, int dh, int dm, int ah, int am)
        : number(n), departure(dh, dm), arrival(ah, am) {}

    int duration() const
    {
        int d = arrival.totalMinutes() - departure.totalMinutes();
        if (d < 0)
            d += 24 * 60;           // the flight lands after midnight
        return d;
    }

    void show() const
    {
        cout << "Flight " << number << ": ";
        departure.show();
        cout << " to ";
        arrival.show();
        cout << ", " << duration() << " minutes" << endl;
    }
};

int main()
{
    Flight f1("FL-301", 9, 45, 11, 20);
    Flight f2("FL-785", 22, 30, 1, 15);
    f1.show();
    f2.show();
    return 0;
}
