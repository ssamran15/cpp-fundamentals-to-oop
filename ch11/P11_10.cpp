// P11.10: Initials of a name
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char name[60];
    cout << "Enter a name: ";
    cin.getline(name, 60);

    cout << "Initials: ";
    for (int i = 0; name[i] != '\0'; i++)
    {
        // a letter starts a word if it is first or comes after a space
        if (name[i] != ' ' && (i == 0 || name[i - 1] == ' '))
            cout << static_cast<char>(toupper(name[i])) << ". ";
    }
    cout << endl;
    return 0;
}
