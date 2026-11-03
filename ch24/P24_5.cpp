// P24.5: Time with an explicit constructor from int and a conversion to int
#include <iostream>
using namespace std;

class Time
{
private:
    int h, m, s;

public:
    explicit Time(int seconds)
    {
        if (seconds < 0)
            seconds = 0;
        h = seconds / 3600;
        m = seconds % 3600 / 60;
        s = seconds % 60;
    }

    Time(int hours, int minutes, int seconds) : h(hours), m(minutes), s(seconds) {}

    operator int() const                // total seconds
    {
        return h * 3600 + m * 60 + s;
    }

    void show() const
    {
        cout << h << "h " << m << "m " << s << "s";
    }
};

int main()
{
    Time start(8, 45, 20), finish(11, 10, 5);

    int difference = finish - start;    // both are converted to int
    Time gap(difference);               // an explicit conversion back to Time
    // Time wrong = 5000;               // error: the constructor is explicit

    cout << "From "; start.show();
    cout << " to "; finish.show();
    cout << endl << "Difference: " << difference << " seconds = "; gap.show();
    cout << endl;
    return 0;
}
