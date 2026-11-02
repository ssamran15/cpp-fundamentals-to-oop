// P7.16: Add numbers until the total goes over 1000
#include <iostream>
using namespace std;

int main()
{
    int total = 0, count = 0;
    while (true)
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        total += n;
        count++;
        if (total > 1000)
            break;
    }
    cout << "Total = " << total << " after " << count << " numbers" << endl;
    return 0;
}
