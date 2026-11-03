// P13.11: Deposit and withdraw through a pointer to a structure
#include <iostream>
#include <string>
using namespace std;

struct Account
{
    string title;
    double balance;
};

void deposit(Account *acc, double amount);
bool withdraw(Account *acc, double amount);

int main()
{
    Account a = {"Hamza Ali", 25000};
    cout << "Account: " << a.title << ", balance Rs. " << a.balance << endl;

    deposit(&a, 7500);
    cout << "After depositing 7500: Rs. " << a.balance << endl;

    if (withdraw(&a, 40000))
        cout << "Withdrew 40000" << endl;
    else
        cout << "Withdrawal of 40000 refused: not enough balance" << endl;

    if (withdraw(&a, 12000))
        cout << "Withdrew 12000, balance now Rs. " << a.balance << endl;
    return 0;
}

void deposit(Account *acc, double amount)
{
    acc->balance += amount;
}

bool withdraw(Account *acc, double amount)
{
    if (amount > acc->balance)
        return false;               // refused; the balance is not changed
    acc->balance -= amount;
    return true;
}
