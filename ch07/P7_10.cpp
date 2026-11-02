// P7.10: x to the power n without pow
#include <iostream>
using namespace std;

int main()
{
    double x;
    int n;
    cout << "Enter x and n: ";
    cin >> x >> n;

    double result = 1;
    for (int i = 1; i <= n; i++)
        result *= x;

    cout << x << "^" << n << " = " << result << endl;
    return 0;
}
