// P13.6: Counting characters with a char pointer
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char text[200];
    cout << "Enter a line of text: ";
    cin.getline(text, 200);

    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    for (char *p = text; *p != '\0'; p++)
    {
        char ch = tolower(*p);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else if (isalpha(ch))
            consonants++;
        else if (isdigit(ch))
            digits++;
        else if (ch == ' ')
            spaces++;
    }
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    return 0;
}
