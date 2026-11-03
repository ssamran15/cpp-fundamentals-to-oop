// P9.8: Recursive sum 1 + 2 + ... + n
#include <iostream>
using namespace std;

int sum(int n);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "1 + 2 + ... + " << n << " = " << sum(n) << endl;
    return 0;
}

int sum(int n)
{
    if (n <= 0)            // base case
        return 0;
    return n + sum(n - 1);
}
