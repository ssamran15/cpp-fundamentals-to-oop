// P9.11: Binary form, recursively
#include <iostream>
using namespace std;

void printBinary(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << n << " in binary is ";
    printBinary(n);
    cout << endl;
    return 0;
}

void printBinary(int n)
{
    if (n >= 2)
        printBinary(n / 2);     // print the higher bits first
    cout << n % 2;
}
