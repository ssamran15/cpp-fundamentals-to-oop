// P26.8: A grocery bill with perishable products
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}

    double finalPrice() const { return price; }

    void show() const
    {
        cout << left << setw(18) << name << right << setw(10) << finalPrice() << endl;
    }
};

class PerishableProduct : public Product
{
private:
    int daysToExpiry;

public:
    PerishableProduct(string n, double p, int d) : Product(n, p), daysToExpiry(d) {}

    double finalPrice() const
    {
        if (daysToExpiry < 3)
            return price * 0.70;            // 30% off
        return price;
    }

    void show() const
    {
        cout << left << setw(18) << name << right << setw(10) << finalPrice();
        if (daysToExpiry < 3)
            cout << "  (30% off, " << daysToExpiry << " day(s) left)";
        cout << endl;
    }
};

int main()
{
    Product rice("Rice 5kg", 1850), soap("Soap", 120);
    PerishableProduct milk("Milk 1L", 220, 2), bread("Bread", 150, 5), yogurt("Yogurt 1kg", 300, 1);

    cout << fixed << setprecision(2);
    rice.show();
    soap.show();
    milk.show();
    bread.show();
    yogurt.show();

    double total = rice.finalPrice() + soap.finalPrice() + milk.finalPrice()
                 + bread.finalPrice() + yogurt.finalPrice();
    cout << "----------------------------" << endl;
    cout << left << setw(18) << "Total" << right << setw(10) << total << endl;
    return 0;
}
