// P18.3: A BankAccount class
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int number;
    string title;
    double balance;
    int transactions;

public:
    void open(int n, string t, double initial)   // sets the number once
    {
        number = n;
        title = t;
        balance = (initial >= 0) ? initial : 0;
        transactions = 0;
    }

    int getNumber() { return number; }           // a getter but no setter

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            transactions++;
        }
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
            return false;
        balance -= amount;
        transactions++;
        return true;
    }

    void show()
    {
        cout << "Account " << number << " (" << title << "): Rs. " << balance
             << ", " << transactions << " transaction(s)" << endl;
    }
};

int main()
{
    BankAccount acc;
    acc.open(50231, "Bilal Ahmed", 20000);
    acc.show();

    acc.deposit(5000);
    acc.withdraw(3000);
    if (!acc.withdraw(50000))
        cout << "Withdrawal of 50000 refused" << endl;
    acc.deposit(1500);
    acc.show();

    cout << "Account number from the getter: " << acc.getNumber() << endl;
    // acc.number = 99999;      // error: 'number' is private
    return 0;
}
