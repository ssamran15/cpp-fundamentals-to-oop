// P27.4: Month-end processing of different accounts
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account
{
protected:
    string title;
    double balance;

public:
    Account(string t, double b) : title(t), balance(b) {}
    virtual ~Account() {}

    virtual void monthEnd() {}              // nothing by default
    virtual string type() const = 0;

    void show() const
    {
        cout << left << setw(14) << title << setw(10) << type() << right
             << "Rs. " << setw(10) << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    double ratePerYear;                     // percent

public:
    SavingsAccount(string t, double b, double r) : Account(t, b), ratePerYear(r) {}
    void monthEnd() override { balance += balance * ratePerYear / 100 / 12; }
    string type() const override { return "Savings"; }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(string t, double b) : Account(t, b) {}
    void monthEnd() override { balance -= 150; }       // fixed service charge
    string type() const override { return "Current"; }
};

class StudentAccount : public Account
{
public:
    StudentAccount(string t, double b) : Account(t, b) {}
    string type() const override { return "Student"; }  // keeps the default monthEnd()
};

int main()
{
    SavingsAccount a("Hina Tariq", 120000, 12);
    CurrentAccount b("Okara Traders", 85000);
    StudentAccount c("Usman Ali", 4500);
    Account *accounts[3] = { &a, &b, &c };

    cout << fixed << setprecision(2);
    cout << "Before month end:" << endl;
    for (int i = 0; i < 3; i++)
        accounts[i]->show();

    for (int i = 0; i < 3; i++)
        accounts[i]->monthEnd();

    cout << "After month end:" << endl;
    for (int i = 0; i < 3; i++)
        accounts[i]->show();
    return 0;
}
