// P6.17: Vowel or consonant using switch
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a letter: ";
    cin >> ch;

    switch (ch)
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            cout << ch << " is a vowel" << endl;
            break;
        default:
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                cout << ch << " is a consonant" << endl;
            else
                cout << ch << " is not a letter" << endl;
    }
    return 0;
}
