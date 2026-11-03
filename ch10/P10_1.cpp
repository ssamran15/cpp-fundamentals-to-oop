// P10.1: Sum of even and odd numbers
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int num[SIZE];
    int evenSum = 0, oddSum = 0;

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> num[i];

    for (int i = 0; i < SIZE; i++)
    {
        if (num[i] % 2 == 0)
            evenSum += num[i];
        else
            oddSum += num[i];
    }
    cout << "Sum of even numbers = " << evenSum << endl;
    cout << "Sum of odd numbers = " << oddSum << endl;
    return 0;
}
