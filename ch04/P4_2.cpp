// P4.2: Total bill
#include <iostream>
using namespace std;

int main()
{
    double price;
    int quantity;
    cout << "Price of one item: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> quantity;

    double bill = price * quantity;
    cout << "Total bill: Rs. " << bill << endl;
    return 0;
}
