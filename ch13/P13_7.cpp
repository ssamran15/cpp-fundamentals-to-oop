// P13.7: Converting a C-string to capitals in place
#include <iostream>
#include <cctype>
using namespace std;

void toUpper(char *s);

int main()
{
    char text[100];
    cout << "Enter some text: ";
    cin.getline(text, 100);

    toUpper(text);
    cout << "In capitals: " << text << endl;
    return 0;
}

void toUpper(char *s)
{
    while (*s != '\0')
    {
        *s = toupper(*s);
        s++;
    }
}
