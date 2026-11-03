// P16.7: Area menu with enum class Shape
#include <iostream>
#include <cmath>
using namespace std;

enum class Shape { CIRCLE, RECTANGLE, TRIANGLE };

double area(Shape s);

int main()
{
    int choice;
    do
    {
        cout << endl << "1. Circle  2. Rectangle  3. Triangle  0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            Shape s = static_cast<Shape>(choice - 1);   // 1 -> CIRCLE, 2 -> RECTANGLE, ...
            double result = area(s);                    // inputs the dimensions first
            cout << "Area = " << result << endl;
        }
        else if (choice != 0)
            cout << "Invalid choice" << endl;
    } while (choice != 0);
    return 0;
}

double area(Shape s)
{
    const double PI = 3.14159;
    double a, b, c;
    switch (s)
    {
        case Shape::CIRCLE:
            cout << "Radius: ";
            cin >> a;
            return PI * a * a;
        case Shape::RECTANGLE:
            cout << "Length and width: ";
            cin >> a >> b;
            return a * b;
        case Shape::TRIANGLE:
            cout << "Base and height: ";
            cin >> a >> c;
            return 0.5 * a * c;
    }
    return 0;
}
