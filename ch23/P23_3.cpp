// P23.3: A Time class with +, += and <
#include <iostream>
using namespace std;

class Time
{
private:
    int h, m, s;

    void normalise()
    {
        int total = h * 3600 + m * 60 + s;
        h = total / 3600;
        m = total % 3600 / 60;
        s = total % 60;
    }

public:
    Time(int hours = 0, int minutes = 0, int seconds = 0) : h(hours), m(minutes), s(seconds)
    {
        normalise();
    }

    Time operator+(const Time &t) const
    {
        return Time(h + t.h, m + t.m, s + t.s);
    }

    Time &operator+=(int seconds)
    {
        s += seconds;
        normalise();
        return *this;
    }

    bool operator<(const Time &t) const
    {
        return h * 3600 + m * 60 + s < t.h * 3600 + t.m * 60 + t.s;
    }

    void show() const
    {
        cout << h << ":" << (m < 10 ? "0" : "") << m << ":" << (s < 10 ? "0" : "") << s;
    }
};

int main()
{
    Time a(1, 45, 30), b(0, 20, 45);
    a.show(); cout << " + "; b.show(); cout << " = "; (a + b).show(); cout << endl;

    b += 90;
    cout << "After b += 90: "; b.show(); cout << endl;

    Time times[5] = { Time(9, 15, 0), Time(8, 50, 30), Time(13, 5, 0), Time(8, 50, 10), Time(10, 0, 0) };
    int earliest = 0;
    for (int i = 1; i < 5; i++)
        if (times[i] < times[earliest])
            earliest = i;
    cout << "Earliest of the five: "; times[earliest].show(); cout << endl;
    return 0;
}
