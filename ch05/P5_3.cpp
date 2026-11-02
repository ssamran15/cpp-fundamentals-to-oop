// P5.3: Metres to kilometres and metres
#include <iostream>
using namespace std;

int main()
{
    int metres;
    cout << "Distance in metres: ";
    cin >> metres;

    int km = metres / 1000;
    int m = metres % 1000;
    cout << metres << " m = " << km << " km " << m << " m" << endl;
    return 0;
}
