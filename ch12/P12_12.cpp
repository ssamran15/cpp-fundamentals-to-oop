// P12.12: Customers with a nested Address
#include <iostream>
#include <string>
using namespace std;

struct Address
{
    string house;
    string street;
    string city;
};

struct Customer
{
    string name;
    string phone;
    Address address;          // a structure inside a structure
};

void inputCustomer(Customer &c);
void showCustomer(const Customer &c);

int main()
{
    Customer c[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Customer " << i + 1 << endl;
        inputCustomer(c[i]);
    }

    cout << endl;
    for (int i = 0; i < 2; i++)
        showCustomer(c[i]);
    return 0;
}

void inputCustomer(Customer &c)
{
    cout << "Name: ";
    getline(cin, c.name);
    cout << "Phone: ";
    getline(cin, c.phone);
    cout << "House: ";
    getline(cin, c.address.house);
    cout << "Street: ";
    getline(cin, c.address.street);
    cout << "City: ";
    getline(cin, c.address.city);
}

void showCustomer(const Customer &c)
{
    cout << c.name << ", " << c.phone << endl;
    cout << "  House " << c.address.house << ", " << c.address.street
         << ", " << c.address.city << endl;
}
