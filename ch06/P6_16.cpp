// P6.16: Area menu
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14159;
    int choice;
    cout << "1. Area of circle" << endl;
    cout << "2. Area of rectangle" << endl;
    cout << "3. Area of triangle" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            double r;
            cout << "Radius: ";
            cin >> r;
            cout << "Area = " << PI * r * r << endl;
            break;
        }
        case 2:
        {
            double length, width;
            cout << "Length and width: ";
            cin >> length >> width;
            cout << "Area = " << length * width << endl;
            break;
        }
        case 3:
        {
            double base, height;
            cout << "Base and height: ";
            cin >> base >> height;
            cout << "Area = " << 0.5 * base * height << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }
    return 0;
}
