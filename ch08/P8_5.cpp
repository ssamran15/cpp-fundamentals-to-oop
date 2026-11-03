// P8.5: Sum of digits with a function
#include <iostream>
using namespace std;

int sumOfDigits(int n);

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Sum of digits = " << sumOfDigits(number) << endl;
    return 0;
}

int sumOfDigits(int n)
{
    if (n < 0)
        n = -n;
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
