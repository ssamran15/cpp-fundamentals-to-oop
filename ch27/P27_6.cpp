// P27.6: Payment methods behind an abstract class
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Payment
{
public:
    virtual ~Payment() {}
    virtual string method() const = 0;
    virtual double charges(double amount) const = 0;

    double total(double amount) const       // the same for every method
    {
        return amount + charges(amount);
    }
};

class CashPayment : public Payment
{
public:
    string method() const override { return "Cash"; }
    double charges(double) const override { return 0; }
};

class CardPayment : public Payment
{
public:
    string method() const override { return "Card"; }
    double charges(double amount) const override { return amount * 0.02; }
};

class WalletPayment : public Payment
{
public:
    string method() const override { return "Mobile wallet"; }
    double charges(double) const override { return 10; }
};

int main()
{
    CashPayment cash;
    CardPayment card;
    WalletPayment wallet;
    Payment *methods[3] = { &cash, &card, &wallet };

    double bill;
    cout << "Bill amount: Rs. ";
    cin >> bill;

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++)
        cout << left << setw(15) << methods[i]->method() << right
             << "charges Rs. " << setw(7) << methods[i]->charges(bill)
             << "   total Rs. " << setw(9) << methods[i]->total(bill) << endl;
    return 0;
}
