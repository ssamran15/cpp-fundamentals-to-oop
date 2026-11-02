// P7.3: Palindrome number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int original = n, reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (original == reversed)
        cout << original << " is a palindrome" << endl;
    else
        cout << original << " is not a palindrome" << endl;
    return 0;
}
