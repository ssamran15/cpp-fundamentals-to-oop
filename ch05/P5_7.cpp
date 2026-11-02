// P5.7: Bank balance with compound assignment operators
#include <iostream>
using namespace std;

int main()
{
    double balance = 25000;
    double deposit, withdrawal;
    const double PROFIT_RATE = 7;       // percent per year (a practice rate)

    cout << "Starting balance: Rs. " << balance << endl;

    cout << "Deposit: Rs. ";
    cin >> deposit;
    balance += deposit;
    cout << "Balance after deposit   : Rs. " << balance << endl;

    cout << "Withdrawal: Rs. ";
    cin >> withdrawal;
    balance -= withdrawal;
    cout << "Balance after withdrawal: Rs. " << balance << endl;

    balance += balance * PROFIT_RATE / 100;
    cout << "Balance after profit    : Rs. " << balance << endl;
    return 0;
}
