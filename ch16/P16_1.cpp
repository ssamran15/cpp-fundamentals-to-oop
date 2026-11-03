// P16.1: Binary, octal and hexadecimal
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Binary      : " << bitset<16>(n) << endl;
    cout << "Octal       : " << oct << n << endl;
    cout << "Hexadecimal : " << hex << n << endl;
    cout << dec;                    // back to decimal for any later output
    return 0;
}
