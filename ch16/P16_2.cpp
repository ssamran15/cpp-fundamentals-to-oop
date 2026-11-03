// P16.2: Power of 2 test
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // a power of 2 has exactly one 1 bit; n - 1 turns that bit off and
    // all the bits below it on, so n & (n - 1) is 0
    if (n > 0 && (n & (n - 1)) == 0)
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " is not a power of 2" << endl;
    return 0;
}
