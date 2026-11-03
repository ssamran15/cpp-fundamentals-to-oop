// P21.6: A class of static conversion functions
#include <iostream>
using namespace std;

class Converter
{
public:
    static double celsiusToFahrenheit(double c) { return c * 9 / 5 + 32; }
    static double fahrenheitToCelsius(double f) { return (f - 32) * 5 / 9; }
    static double kmToMiles(double km) { return km * 0.621371; }
    static double milesToKm(double miles) { return miles / 0.621371; }
};

int main()
{
    // no Converter object is created; the class name is used instead
    cout << "37 C = " << Converter::celsiusToFahrenheit(37) << " F" << endl;
    cout << "212 F = " << Converter::fahrenheitToCelsius(212) << " C" << endl;
    cout << "130 km = " << Converter::kmToMiles(130) << " miles" << endl;
    cout << "26.2 miles = " << Converter::milesToKm(26.2) << " km" << endl;
    return 0;
}
