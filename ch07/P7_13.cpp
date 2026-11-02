// P7.13: Tables of 2 to 9
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for (int t = 2; t <= 9; t++)
    {
        cout << "Table of " << t << endl;
        for (int i = 1; i <= 10; i++)
            cout << t << " x " << setw(2) << i << " = " << setw(2) << t * i << endl;
        cout << endl;
    }
    return 0;
}
