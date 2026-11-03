// P8.6: Counting even numbers
#include <iostream>
using namespace std;

bool isEven(int n);

int main()
{
    int number, count = 0;
    cout << "Enter 10 numbers: ";
    for (int i = 1; i <= 10; i++)
    {
        cin >> number;
        if (isEven(number))
            count++;
    }
    cout << "Even numbers entered: " << count << endl;
    return 0;
}

bool isEven(int n)
{
    return n % 2 == 0;
}
