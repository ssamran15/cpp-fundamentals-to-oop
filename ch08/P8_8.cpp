// P8.8: Reverse and palindrome
#include <iostream>
using namespace std;

int reverse(int n);
bool isPalindrome(int n);

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Reverse: " << reverse(number) << endl;
    if (isPalindrome(number))
        cout << number << " is a palindrome" << endl;
    else
        cout << number << " is not a palindrome" << endl;
    return 0;
}

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n)
{
    return n == reverse(n);
}
