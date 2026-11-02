// P5.5: Reversing a four-digit number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a four-digit number: ";
    cin >> n;

    int d1 = n / 1000;              // thousands digit
    int d2 = n / 100 % 10;          // hundreds digit
    int d3 = n / 10 % 10;           // tens digit
    int d4 = n % 10;                // units digit

    int reversed = d4 * 1000 + d3 * 100 + d2 * 10 + d1;
    cout << "Reversed: " << reversed << endl;
    return 0;
}
