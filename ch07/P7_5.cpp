// P7.5: Armstrong number (three digits)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a three-digit number: ";
    cin >> n;

    int temp = n, sum = 0;
    while (temp > 0)
    {
        int d = temp % 10;
        sum += d * d * d;
        temp /= 10;
    }

    if (sum == n)
        cout << n << " is an Armstrong number" << endl;
    else
        cout << n << " is not an Armstrong number" << endl;
    return 0;
}
