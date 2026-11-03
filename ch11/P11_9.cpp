// P11.9: Our own strlen and strcpy
#include <iostream>
using namespace std;

int myStrlen(const char s[]);
void myStrcpy(char dest[], const char src[]);

int main()
{
    char source[50];
    char copy[50];

    cout << "Enter a string: ";
    cin.getline(source, 50);

    myStrcpy(copy, source);
    cout << "Length: " << myStrlen(source) << endl;
    cout << "Copy: " << copy << endl;
    return 0;
}

int myStrlen(const char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void myStrcpy(char dest[], const char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';          // the copy needs its own terminator
}
