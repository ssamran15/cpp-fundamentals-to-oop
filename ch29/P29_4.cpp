// P29.4: An Invoice that implements two interfaces
#include <iostream>
#include <string>
using namespace std;

class Printable
{
public:
    virtual ~Printable() {}
    virtual void print() const = 0;
};

class Savable
{
public:
    virtual ~Savable() {}
    virtual void save() const = 0;
};

class Invoice : public Printable, public Savable
{
private:
    int number;
    string customer;
    double amount;

public:
    Invoice(int n, string c, double a) : number(n), customer(c), amount(a) {}

    void print() const override
    {
        cout << "Invoice " << number << ": " << customer << ", Rs. " << amount << endl;
    }

    void save() const override
    {
        cout << "Saving invoice " << number << " to invoice_" << number << ".txt" << endl;
    }
};

int main()
{
    Invoice a(101, "Okara Traders", 18500), b(102, "City Bookshop", 7250);

    Printable *toPrint[2] = { &a, &b };
    Savable *toSave[2] = { &a, &b };    // the same two objects

    cout << "Printing:" << endl;
    for (int i = 0; i < 2; i++)
        toPrint[i]->print();

    cout << "Saving:" << endl;
    for (int i = 0; i < 2; i++)
        toSave[i]->save();
    return 0;
}
