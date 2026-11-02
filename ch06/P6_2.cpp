// P6.2: Eligible to vote
#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter age: ";
    cin >> age;

    if (age >= 18)
        cout << "Eligible to vote" << endl;
    else
        cout << "Not eligible to vote yet; " << 18 - age << " more year(s) to go" << endl;
    return 0;
}
