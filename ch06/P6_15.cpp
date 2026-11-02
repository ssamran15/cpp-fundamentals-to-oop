// P6.15: Toll plaza
#include <iostream>
using namespace std;

int main()
{
    char type;
    cout << "C. Car   B. Bus   T. Truck" << endl;
    cout << "Vehicle type: ";
    cin >> type;

    switch (type)
    {
        case 'C':
        case 'c':
            cout << "Toll: Rs. 150" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Toll: Rs. 300" << endl;
            break;
        case 'T':
        case 't':
            cout << "Toll: Rs. 500" << endl;
            break;
        default:
            cout << "Invalid vehicle type" << endl;
    }
    return 0;
}
