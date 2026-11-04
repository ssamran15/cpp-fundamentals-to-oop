// P33.8: Program 33.11 with a Transfer option
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class BankError : public runtime_error
{
public:
    BankError(const string &msg) : runtime_error(msg) { }
};

class InsufficientFunds : public BankError
{
private:
    double shortAmount;
public:
    InsufficientFunds(double s) : BankError("insufficient funds"), shortAmount(s) { }
    double shortBy() const { return shortAmount; }
};

class AccountNotFound : public BankError
{
public:
    AccountNotFound(int n) : BankError("no account has number " + to_string(n)) { }
};

class Account
{
private:
    int number;
    string title;
    double balance;
public:
    Account(int n, const string &t, double b) : number(n), title(t), balance(b)
    {
        if (t == "")
            throw invalid_argument("title cannot be empty");
        if (b < 500)
            throw invalid_argument("opening balance must be at least Rs. 500");
    }
    int getNumber() const { return number; }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw invalid_argument("amount must be positive");
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw invalid_argument("amount must be positive");
        if (amount > balance)
            throw InsufficientFunds(amount - balance);
        balance -= amount;
    }

    void show() const
    {
        cout << setw(6) << number << "  " << left << setw(10) << title << right
             << setw(10) << balance << endl;
    }
};

class Bank
{
private:
    vector<Account> accounts;
    int nextNumber = 1001;
public:
    int open(const string &title, double amount)
    {
        Account a(nextNumber, title, amount);   // may throw: then nothing is added
        accounts.push_back(a);
        return nextNumber++;
    }

    Account &find(int number)
    {
        for (auto &a : accounts)
            if (a.getNumber() == number)
                return a;
        throw AccountNotFound(number);
    }

    void transfer(int fromNo, int toNo, double amount)     // the new function
    {
        Account &from = find(fromNo);
        from.withdraw(amount);              // may throw: then nothing has changed
        try
        {
            Account &to = find(toNo);
            to.deposit(amount);
        }
        catch (...)
        {
            from.deposit(amount);           // put the money back first
            throw;                          // then report the same error
        }
    }

    void showAll() const
    {
        if (accounts.empty())
            cout << "No accounts yet." << endl;
        for (const auto &a : accounts)
            a.show();
    }
};

int readInt(const string &prompt)
{
    string line;
    cout << prompt;
    if (!getline(cin, line))                    // input has ended: treat as Exit
        return 0;
    try
    {
        return stoi(line);
    }
    catch (const exception &)                   // invalid_argument or out_of_range
    {
        throw invalid_argument("\"" + line + "\" is not a valid whole number");
    }
}

double readAmount(const string &prompt)
{
    string line;
    cout << prompt;
    getline(cin, line);
    try
    {
        return stod(line);
    }
    catch (const exception &)
    {
        throw invalid_argument("\"" + line + "\" is not a valid amount");
    }
}

int main()
{
    Bank bank;
    cout << fixed << setprecision(2);
    int choice = -1;

    while (choice != 0)
    {
        cout << "\n1. Open  2. Deposit  3. Withdraw  4. Show all  5. Transfer  0. Exit" << endl;
        try
        {
            choice = readInt("Choice: ");
            if (choice == 1)
            {
                string title;
                cout << "Title: ";
                getline(cin, title);
                double amount = readAmount("Opening balance: ");
                int n = bank.open(title, amount);
                cout << "Account " << n << " opened." << endl;
            }
            else if (choice == 2 || choice == 3)
            {
                Account &acc = bank.find(readInt("Account number: "));
                double amount = readAmount("Amount: ");
                if (choice == 2)
                    acc.deposit(amount);
                else
                    acc.withdraw(amount);
                cout << "Done." << endl;
            }
            else if (choice == 4)
                bank.showAll();
            else if (choice == 5)
            {
                int fromNo = readInt("From account: ");
                int toNo = readInt("To account: ");
                double amount = readAmount("Amount: ");
                bank.transfer(fromNo, toNo, amount);
                cout << "Transferred." << endl;
            }
            else if (choice != 0)
                cout << "Please choose from the menu." << endl;
        }
        catch (const InsufficientFunds &e)
        {
            cout << "Refused: " << e.what() << ", short by Rs. " << e.shortBy() << endl;
        }
        catch (const BankError &e)
        {
            cout << "Bank error: " << e.what() << endl;
        }
        catch (const invalid_argument &e)
        {
            cout << "Input error: " << e.what() << endl;
        }
    }
    cout << "Goodbye." << endl;
    return 0;
}
