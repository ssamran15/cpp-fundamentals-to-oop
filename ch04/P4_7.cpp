// P4.7: The next three letters of the alphabet
#include <iostream>
using namespace std;

int main()
{
    char letter;
    cout << "Enter an uppercase letter: ";
    cin >> letter;

    char next1 = letter + 1;
    char next2 = letter + 2;
    char next3 = letter + 3;
    cout << "Next three letters: " << next1 << " " << next2 << " " << next3 << endl;
    return 0;
}
