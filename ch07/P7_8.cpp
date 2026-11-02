// P7.8: Sum of a series and sum of squares
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    long long sum = 0, sumSquares = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        sumSquares += i * i;
    }
    cout << "1 + 2 + ... + " << n << " = " << sum << endl;
    cout << "1^2 + 2^2 + ... + " << n << "^2 = " << sumSquares << endl;
    return 0;
}
