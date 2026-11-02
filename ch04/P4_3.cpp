// P4.3: Fahrenheit to Celsius
#include <iostream>
using namespace std;

int main()
{
    double f;
    cout << "Temperature in Fahrenheit: ";
    cin >> f;

    double c = (f - 32) * 5 / 9;
    cout << "Temperature in Celsius   : " << c << endl;
    return 0;
}
