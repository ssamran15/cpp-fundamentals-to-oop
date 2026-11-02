// P7.12: Prime numbers from 1 to 100
#include <iostream>
using namespace std;

int main()
{
    for (int n = 2; n <= 100; n++)
    {
        bool prime = true;
        for (int d = 2; d * d <= n; d++)
        {
            if (n % d == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
            cout << n << " ";
    }
    cout << endl;
    return 0;
}
