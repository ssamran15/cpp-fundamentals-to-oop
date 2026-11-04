// P25.2: Can the customer afford the product?
#include <iostream>
#include <string>
using namespace std;

class Customer;

class Product
{
private:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}
    friend void canAfford(const Customer &c, const Product &p);
};

class Customer
{
private:
    string name;
    double budget;

public:
    Customer(string n, double b) : name(n), budget(b) {}
    friend void canAfford(const Customer &c, const Product &p);
};

void canAfford(const Customer &c, const Product &p)
{
    cout << c.name << " and the " << p.name << " (Rs. " << p.price << "): ";
    if (c.budget >= p.price)
        cout << "can buy it, Rs. " << c.budget - p.price << " left" << endl;
    else
        cout << "cannot buy it, short by Rs. " << p.price - c.budget << endl;
}

int main()
{
    Product phone("mobile phone", 45000), bag("school bag", 2500);
    Customer ali("Ali", 30000), sana("Sana", 52000);

    canAfford(ali, phone);
    canAfford(ali, bag);
    canAfford(sana, phone);
    return 0;
}
