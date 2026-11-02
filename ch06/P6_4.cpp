// P6.4: Divisible by both 3 and 5
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n % 3 == 0 && n % 5 == 0)
        cout << n << " is divisible by both 3 and 5" << endl;
    else
        cout << n << " is not divisible by both 3 and 5" << endl;
    return 0;
}
