// P9.7: Overloaded display functions
#include <iostream>
#include <iomanip>
using namespace std;

void display(int n);
void display(double d);
void display(char ch, int n);

int main()
{
    display(250);
    display(3.14159);
    display('*', 20);
    return 0;
}

void display(int n)
{
    cout << "int: " << n << endl;
}

void display(double d)
{
    cout << fixed << setprecision(2);
    cout << "double: " << d << endl;
}

void display(char ch, int n)
{
    for (int i = 1; i <= n; i++)
        cout << ch;
    cout << endl;
}
