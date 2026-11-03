// P8.12: Calculator menu with functions
#include <iostream>
using namespace std;

void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main()
{
    int choice;
    double a, b;
    do
    {
        showMenu();
        cin >> choice;
        if (choice >= 1 && choice <= 4)
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }
        switch (choice)
        {
            case 1:
                cout << "Result = " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result = " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result = " << multiply(a, b) << endl;
                break;
            case 4:
                if (b == 0)
                    cout << "Cannot divide by zero" << endl;
                else
                    cout << "Result = " << divide(a, b) << endl;
                break;
            case 5:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}

void showMenu()
{
    cout << endl << "1. Add  2. Subtract  3. Multiply  4. Divide  5. Exit" << endl;
    cout << "Choice: ";
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}
