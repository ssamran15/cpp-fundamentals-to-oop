// P8.4: Celsius to Fahrenheit table
#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double c);

int main()
{
    cout << setw(10) << "Celsius" << setw(14) << "Fahrenheit" << endl;
    for (int c = 0; c <= 100; c += 10)
        cout << setw(10) << c << setw(14) << celsiusToFahrenheit(c) << endl;
    return 0;
}

double celsiusToFahrenheit(double c)
{
    return c * 9 / 5 + 32;
}
