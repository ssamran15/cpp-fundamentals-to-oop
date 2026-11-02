// P4.10: GST amount and final price
#include <iostream>
using namespace std;

int main()
{
    const double GST_RATE = 18;         // percent
    double price;
    cout << "Price of the product: Rs. ";
    cin >> price;

    double gst = price * GST_RATE / 100;
    double finalPrice = price + gst;
    cout << "GST (18%)  : Rs. " << gst << endl;
    cout << "Final price: Rs. " << finalPrice << endl;
    return 0;
}
