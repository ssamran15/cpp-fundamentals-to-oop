// P9.1: Sorting three numbers with sortTwo
#include <iostream>
using namespace std;

void sortTwo(int &a, int &b);

int main()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    sortTwo(x, y);      // smaller of x, y is now in x
    sortTwo(x, z);      // smallest of all three is now in x
    sortTwo(y, z);      // the larger of the other two is now in z

    cout << "In ascending order: " << x << " " << y << " " << z << endl;
    return 0;
}

void sortTwo(int &a, int &b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
