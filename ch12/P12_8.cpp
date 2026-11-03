// P12.8: Adding two Time values
#include <iostream>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

Time addTime(Time a, Time b);
Time inputTime();
void showTime(Time t);

int main()
{
    cout << "First time" << endl;
    Time t1 = inputTime();
    cout << "Second time" << endl;
    Time t2 = inputTime();

    Time total = addTime(t1, t2);
    showTime(t1);
    cout << " + ";
    showTime(t2);
    cout << " = ";
    showTime(total);
    cout << endl;
    return 0;
}

Time inputTime()
{
    Time t;
    cout << "Hours, minutes and seconds: ";
    cin >> t.hours >> t.minutes >> t.seconds;
    return t;
}

Time addTime(Time a, Time b)
{
    Time r;
    r.seconds = a.seconds + b.seconds;
    r.minutes = a.minutes + b.minutes + r.seconds / 60;   // carry seconds into minutes
    r.seconds %= 60;
    r.hours = a.hours + b.hours + r.minutes / 60;         // carry minutes into hours
    r.minutes %= 60;
    return r;
}

void showTime(Time t)
{
    cout << t.hours << "h " << t.minutes << "m " << t.seconds << "s";
}
