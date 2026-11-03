// P21.4: A static tax rate shared by all products
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    string name;
    double price;
    static double taxRate;              // percent, the same for every product

public:
    Product(string n, double p) : name(n), price(p) {}

    static void setTaxRate(double rate)
    {
        if (rate >= 0)
            taxRate = rate;
    }

    static double getTaxRate() { return taxRate; }

    double priceWithTax() const
    {
        return price + price * taxRate / 100;
    }

    void show() const
    {
        cout << left << setw(12) << name << right << "Rs. " << setw(8) << price
             << "  with tax Rs. " << setw(8) << priceWithTax() << endl;
    }
};

double Product::taxRate = 17;

int main()
{
    Product items[3] = { Product("Soap", 120), Product("Tea 250g", 650), Product("Oil 1L", 590) };

    cout << fixed << setprecision(2);
    cout << "Tax rate " << Product::getTaxRate() << "%" << endl;
    for (int i = 0; i < 3; i++)
        items[i].show();

    Product::setTaxRate(18);            // one change affects every product
    cout << endl << "Tax rate " << Product::getTaxRate() << "%" << endl;
    for (int i = 0; i < 3; i++)
        items[i].show();
    return 0;
}
