// P12.1: Capital letter at the start of every word
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string name;
    cout << "Enter a full name: ";
    getline(cin, name);

    for (int i = 0; i < static_cast<int>(name.length()); i++)
    {
        if (i == 0 || name[i - 1] == ' ')
            name[i] = toupper(name[i]);      // first letter of a word
        else
            name[i] = tolower(name[i]);      // every other letter
    }
    cout << "Proper form: " << name << endl;
    return 0;
}
