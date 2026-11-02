// P5.10: Lowercase to uppercase using the ASCII code
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a lowercase letter: ";
    cin >> ch;

    char upper = ch - 32;           // 'a' is 97 and 'A' is 65
    cout << "Uppercase: " << upper << endl;
    return 0;
}
