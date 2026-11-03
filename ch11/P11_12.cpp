// P11.12: Counting each vowel
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char text[200];
    cout << "Enter a sentence: ";
    cin.getline(text, 200);

    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for (int k = 0; text[k] != '\0'; k++)
    {
        switch (tolower(text[k]))
        {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }
    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
    return 0;
}
