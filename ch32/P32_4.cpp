// P32.4: A shopping cart in a vector<Product>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Product
{
private:
    string name;
    int qty;
    double price;

public:
    Product(string n, int q, double p) : name(n), qty(q), price(p) {}
    string getName() const { return name; }
    double amount() const { return qty * price; }

    void show() const
    {
        cout << "  " << left << setw(10) << name << right << setw(4) << qty
             << " x " << setw(8) << price << " = " << setw(9) << amount() << endl;
    }
};

int main()
{
    vector<Product> cart;
    int choice;
    cout << fixed << setprecision(2);

    do
    {
        cout << endl << "1 Add  2 Remove  3 List  4 Empty cart  0 Exit: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int q;
            double p;
            cout << "Item, quantity and price: ";
            cin >> name >> q >> p;
            cart.push_back(Product(name, q, p));
        }
        else if (choice == 2)
        {
            string name;
            cout << "Item to remove: ";
            cin >> name;
            bool removed = false;
            for (int i = 0; i < static_cast<int>(cart.size()); i++)
            {
                if (cart[i].getName() == name)
                {
                    cart.erase(cart.begin() + i);
                    removed = true;
                    break;
                }
            }
            cout << (removed ? "  Removed" : "  Not in the cart") << endl;
        }
        else if (choice == 3)
        {
            double total = 0;
            for (const Product &p : cart)
            {
                p.show();
                total += p.amount();
            }
            cout << "  " << cart.size() << " item(s), total Rs. " << total << endl;
        }
        else if (choice == 4)
        {
            cart.clear();
            cout << "  The cart is empty" << endl;
        }
    } while (choice != 0);
    return 0;
}
