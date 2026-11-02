// P6.11: Pass only with at least 40 in every subject
#include <iostream>
using namespace std;

int main()
{
    int m1, m2, m3;
    cout << "Enter marks of three subjects: ";
    cin >> m1 >> m2 >> m3;

    if (m1 >= 40 && m2 >= 40 && m3 >= 40)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
    return 0;
}
