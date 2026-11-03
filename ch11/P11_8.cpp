// P11.8: A string in reverse
#include <iostream>
using namespace std;

int main()
{
    char text[100];
    cout << "Enter a string: ";
    cin.getline(text, 100);

    int length = 0;
    while (text[length] != '\0')        // find the length ourselves
        length++;

    cout << "Reversed: ";
    for (int i = length - 1; i >= 0; i--)
        cout << text[i];
    cout << endl;
    return 0;
}
