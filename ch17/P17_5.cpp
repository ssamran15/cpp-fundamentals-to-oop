// P17.5: A Thermometer class
#include <iostream>
using namespace std;

class Thermometer
{
private:
    double celsius;

public:
    bool set(double c)
    {
        if (c < -273.15)                // colder than absolute zero is impossible
            return false;
        celsius = c;
        return true;
    }

    double getCelsius()
    {
        return celsius;
    }

    double getFahrenheit()
    {
        return celsius * 9 / 5 + 32;
    }
};

int main()
{
    Thermometer t;
    t.set(0);                           // a starting value

    double c;
    cout << "Enter a temperature in Celsius: ";
    cin >> c;
    if (!t.set(c))
        cout << "Refused: below absolute zero. Keeping " << t.getCelsius() << " C" << endl;

    cout << t.getCelsius() << " C = " << t.getFahrenheit() << " F" << endl;
    return 0;
}
