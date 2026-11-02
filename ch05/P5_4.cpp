// P5.4: Breaking an amount into currency notes
#include <iostream>
using namespace std;

int main()
{
    int amount;
    cout << "Amount in rupees: ";
    cin >> amount;

    int rest = amount;
    int n5000 = rest / 5000;  rest = rest % 5000;
    int n1000 = rest / 1000;  rest = rest % 1000;
    int n500 = rest / 500;    rest = rest % 500;
    int n100 = rest / 100;    rest = rest % 100;
    int n50 = rest / 50;      rest = rest % 50;

    cout << "Rs. 5000 notes: " << n5000 << endl;
    cout << "Rs. 1000 notes: " << n1000 << endl;
    cout << "Rs. 500 notes : " << n500 << endl;
    cout << "Rs. 100 notes : " << n100 << endl;
    cout << "Rs. 50 notes  : " << n50 << endl;
    cout << "Remaining     : Rs. " << rest << endl;
    return 0;
}
