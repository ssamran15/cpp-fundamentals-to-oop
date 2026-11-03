// P23.6: A six-digit Odometer with ++
#include <iostream>
#include <iomanip>
using namespace std;

class Odometer
{
private:
    int reading;

public:
    Odometer(int r = 0) : reading(r >= 0 && r <= 999999 ? r : 0) {}

    Odometer &operator++()          // prefix
    {
        reading = (reading + 1) % 1000000;      // 999999 goes back to 0
        return *this;
    }

    Odometer operator++(int)        // postfix
    {
        Odometer old = *this;
        ++(*this);
        return old;
    }

    void show() const
    {
        cout << setfill('0') << setw(6) << reading << setfill(' ');
    }
};

int main()
{
    Odometer car(999997);
    for (int i = 1; i <= 4; i++)
    {
        Odometer before = car++;
        before.show();
        cout << " -> ";
        car.show();
        cout << endl;
    }

    ++car;
    cout << "After ++car: ";
    car.show();
    cout << endl;
    return 0;
}
