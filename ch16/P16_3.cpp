// P16.3: Setting, clearing and toggling a bit
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Bit position (0 is the rightmost bit): ";
    cin >> k;

    cout << "Number         : " << bitset<16>(n) << " (" << n << ")" << endl;
    int set = n | (1 << k);
    int cleared = n & ~(1 << k);
    int toggled = n ^ (1 << k);
    cout << "After setting  : " << bitset<16>(set) << " (" << set << ")" << endl;
    cout << "After clearing : " << bitset<16>(cleared) << " (" << cleared << ")" << endl;
    cout << "After toggling : " << bitset<16>(toggled) << " (" << toggled << ")" << endl;
    return 0;
}
