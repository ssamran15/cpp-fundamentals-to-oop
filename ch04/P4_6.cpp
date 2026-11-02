// P4.6: ASCII code of a character
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    int code = ch;                      // a char stored in an int gives its code
    cout << "ASCII code of " << ch << " is " << code << endl;
    return 0;
}
