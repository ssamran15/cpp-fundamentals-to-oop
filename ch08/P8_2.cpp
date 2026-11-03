// P8.2: Multiplication tables of 2, 5 and 9
#include <iostream>
using namespace std;

void printTable(int n);

int main()
{
    printTable(2);
    printTable(5);
    printTable(9);
    return 0;
}

void printTable(int n)
{
    cout << "Table of " << n << endl;
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n * i << endl;
    cout << endl;
}
