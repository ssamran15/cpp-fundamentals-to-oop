// P4.11: A neat grocery bill with setw
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sugar, rice, tea;
    cout << "Price of sugar: ";
    cin >> sugar;
    cout << "Price of rice : ";
    cin >> rice;
    cout << "Price of tea  : ";
    cin >> tea;

    double total = sugar + rice + tea;

    cout << fixed << setprecision(2);
    cout << endl << left << setw(12) << "Item" << right << setw(10) << "Price" << endl;
    cout << left << setw(12) << "Sugar" << right << setw(10) << sugar << endl;
    cout << left << setw(12) << "Rice" << right << setw(10) << rice << endl;
    cout << left << setw(12) << "Tea" << right << setw(10) << tea << endl;
    cout << left << setw(12) << "Total" << right << setw(10) << total << endl;
    return 0;
}
