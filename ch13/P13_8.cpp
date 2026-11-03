// P13.8: Palindrome word with two char pointers
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[50];
    cout << "Enter a word: ";
    cin >> word;

    char *front = word;
    char *back = word + strlen(word) - 1;
    bool palindrome = true;
    while (front < back)
    {
        if (*front != *back)
        {
            palindrome = false;
            break;
        }
        front++;
        back--;
    }

    if (palindrome)
        cout << word << " is a palindrome" << endl;
    else
        cout << word << " is not a palindrome" << endl;
    return 0;
}
