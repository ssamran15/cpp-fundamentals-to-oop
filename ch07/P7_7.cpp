// P7.7: Unit converter menu
#include <iostream>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << endl << "1. Km to miles  2. Kg to pounds  3. Celsius to Fahrenheit  4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        double value;
        switch (choice)
        {
            case 1:
                cout << "Kilometres: ";
                cin >> value;
                cout << value << " km = " << value * 0.621371 << " miles" << endl;
                break;
            case 2:
                cout << "Kilograms: ";
                cin >> value;
                cout << value << " kg = " << value * 2.20462 << " pounds" << endl;
                break;
            case 3:
                cout << "Celsius: ";
                cin >> value;
                cout << value << " C = " << value * 9 / 5 + 32 << " F" << endl;
                break;
            case 4:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
