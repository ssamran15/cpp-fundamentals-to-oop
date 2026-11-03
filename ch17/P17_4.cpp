// P17.4: Stock value with a member function
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product
{
    string name;
    int quantity;
    double price;

    double stockValue()
    {
        return quantity * price;
    }
};

int main()
{
    Product items[5] = {
        {"Soap",      40, 120},
        {"Rice 1kg",  25, 380},
        {"Tea 250g",  18, 650},
        {"Sugar 1kg", 30, 160},
        {"Oil 1L",    12, 590}
    };

    double total = 0;
    cout << fixed << setprecision(2);
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(12) << items[i].name << right << setw(5) << items[i].quantity
             << " x " << setw(7) << items[i].price << " = " << setw(10) << items[i].stockValue() << endl;
        total += items[i].stockValue();
    }
    cout << "Total value of the stock: Rs. " << total << endl;
    return 0;
}
