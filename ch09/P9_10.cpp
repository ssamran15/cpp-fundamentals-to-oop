// P9.10: Digits in reverse order, recursively
#include <iostream>
using namespace std;

void printReverse(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reversed: ";
    printReverse(n);
    cout << endl;
    return 0;
}

void printReverse(int n)
{
    cout << n % 10;        // last digit first
    if (n >= 10)
        printReverse(n / 10);
}
