// P26.6: A SavingsAccount with withdrawal limits
#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string title;
    double balance;

public:
    Account(string t, double b) : title(t), balance(b) {}

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
            return false;
        balance -= amount;
        return true;
    }

    double getBalance() const { return balance; }
};

class SavingsAccount : public Account
{
private:
    int withdrawalsThisMonth;

public:
    SavingsAccount(string t, double b) : Account(t, b), withdrawalsThisMonth(0) {}

    bool withdraw(double amount)            // overrides Account::withdraw
    {
        if (withdrawalsThisMonth == 3)
        {
            cout << "  refused: 3 withdrawals already made this month" << endl;
            return false;
        }
        if (balance - amount < 1000)
        {
            cout << "  refused: balance would fall below Rs. 1000" << endl;
            return false;
        }
        if (!Account::withdraw(amount))     // the base class does the real work
            return false;
        withdrawalsThisMonth++;
        return true;
    }

    void newMonth() { withdrawalsThisMonth = 0; }
};

int main()
{
    SavingsAccount s("Sana Tariq", 20000);
    double requests[4] = {2000, 3000, 1500, 1000};

    cout << "This month:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Withdraw Rs. " << requests[i] << endl;
        if (s.withdraw(requests[i]))
            cout << "  done, balance Rs. " << s.getBalance() << endl;
    }

    s.newMonth();
    cout << "Next month:" << endl;
    cout << "Withdraw Rs. 13000" << endl;
    if (s.withdraw(13000))
        cout << "  done, balance Rs. " << s.getBalance() << endl;
    cout << "Withdraw Rs. 12000" << endl;
    if (s.withdraw(12000))
        cout << "  done, balance Rs. " << s.getBalance() << endl;
    return 0;
}
