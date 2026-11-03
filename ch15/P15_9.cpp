// P15.9: Changing a price in products.dat
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Product                  // the same structure as Program 15.7
{
    int code;
    char name[20];
    double price;
};

int main()
{
    fstream file("products.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "Cannot open products.dat (run Program 15.7 first)" << endl;
        return 1;
    }

    file.seekg(0, ios::end);
    int records = file.tellg() / sizeof(Product);

    int n;
    double newPrice;
    cout << "Record number (1 to " << records << "): ";
    cin >> n;
    if (n < 1 || n > records)
    {
        cout << "No such record" << endl;
        return 1;
    }
    cout << "New price: ";
    cin >> newPrice;

    Product p;
    file.seekg((n - 1) * sizeof(Product), ios::beg);
    file.read(reinterpret_cast<char*>(&p), sizeof(Product));
    cout << "Old: " << p.code << "  " << p.name << "  Rs. " << fixed << setprecision(2) << p.price << endl;

    p.price = newPrice;
    file.seekp((n - 1) * sizeof(Product), ios::beg);       // back to the same place
    file.write(reinterpret_cast<const char*>(&p), sizeof(Product));

    cout << endl << "All records now:" << endl;
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Product)))
        cout << p.code << "  " << left << setw(12) << p.name << right << "Rs. " << p.price << endl;
    file.close();
    return 0;
}
