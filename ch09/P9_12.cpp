// P9.12: Palindrome check with recursion
#include <iostream>
using namespace std;

int reverseNumber(int n, int reversed = 0);
bool isPalindrome(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPalindrome(n))
        cout << n << " is a palindrome" << endl;
    else
        cout << n << " is not a palindrome" << endl;
    return 0;
}

// moves the last digit of n to the end of reversed, one digit per call
int reverseNumber(int n, int reversed)
{
    if (n == 0)
        return reversed;
    return reverseNumber(n / 10, reversed * 10 + n % 10);
}

bool isPalindrome(int n)
{
    return n == reverseNumber(n);
}
