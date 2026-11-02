// P6.9: Type of character using ASCII ranges
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z')
        cout << "Uppercase letter" << endl;
    else if (ch >= 'a' && ch <= 'z')
        cout << "Lowercase letter" << endl;
    else if (ch >= '0' && ch <= '9')
        cout << "Digit" << endl;
    else
        cout << "Special character" << endl;
    return 0;
}
