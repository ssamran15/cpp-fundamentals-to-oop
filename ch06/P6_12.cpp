// P6.12: Hot, pleasant or cold
#include <iostream>
using namespace std;

int main()
{
    double temp;
    cout << "Temperature: ";
    cin >> temp;

    if (temp > 35)
        cout << "Hot" << endl;
    else if (temp >= 25)
        cout << "Pleasant" << endl;
    else
        cout << "Cold" << endl;
    return 0;
}
