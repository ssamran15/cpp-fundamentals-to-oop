// P24.8: A Percentage class with conversions to and from double
#include <iostream>
using namespace std;

class Percentage
{
private:
    double value;                   // 0 to 100

public:
    Percentage(double v = 0)        // conversion constructor, clamps the value
    {
        if (v < 0)
            v = 0;
        if (v > 100)
            v = 100;
        value = v;
    }

    operator double() const        // the value as a fraction: 75% -> 0.75
    {
        return value / 100;
    }

    void show() const
    {
        cout << value << "%";
    }
};

int main()
{
    Percentage attendance = 75;     // double -> Percentage
    Percentage tooHigh = 130;       // clamped to 100
    Percentage negative = -20;      // clamped to 0

    attendance.show(); cout << " as a fraction: " << double(attendance) << endl;
    tooHigh.show(); cout << " as a fraction: " << double(tooHigh) << endl;
    negative.show(); cout << " as a fraction: " << double(negative) << endl;

    double fee = 48000;
    Percentage scholarship = 40;
    double waiver = fee * scholarship;      // scholarship becomes 0.40 here
    cout << "A "; scholarship.show();
    cout << " scholarship on Rs. " << fee << " is Rs. " << waiver << endl;
    return 0;
}
