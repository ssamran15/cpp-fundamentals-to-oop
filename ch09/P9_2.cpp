// P9.2: Smallest and largest through reference parameters
#include <iostream>
using namespace std;

void minMax(int a, int b, int c, int &smallest, int &largest);

int main()
{
    int a, b, c, small, large;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    minMax(a, b, c, small, large);
    cout << "Smallest = " << small << endl;
    cout << "Largest = " << large << endl;
    return 0;
}

void minMax(int a, int b, int c, int &smallest, int &largest)
{
    smallest = a;
    largest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
}
