// P7.2: Sum of digits
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0)
        n = -n;

    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;      // last digit
        n /= 10;            // remove the last digit
    }
    cout << "Sum of digits = " << sum << endl;
    return 0;
}
