// P24.7: Money with explicit operator bool
#include <iostream>
using namespace std;

class Money
{
private:
    double amount;

public:
    explicit Money(double a) : amount(a) {}

    explicit operator bool() const          // true when there is money left
    {
        return amount > 0;
    }

    void spend(double x)
    {
        if (x > amount)
            x = amount;                     // cannot spend more than is there
        amount -= x;
    }
    double get() const { return amount; }
};

int main()
{
    Money wallet(1000);
    Money empty(0);

    if (wallet)
        cout << "The wallet has Rs. " << wallet.get() << endl;
    if (!empty)
        cout << "The second wallet is empty" << endl;

    int day = 0;
    while (wallet)                          // spend Rs. 300 a day until nothing is left
    {
        day++;
        wallet.spend(300);
        cout << "Day " << day << ": Rs. " << wallet.get() << " left" << endl;
    }
    cout << "Out of money after " << day << " days" << endl;

    // int x = wallet;                      // error: the conversion is explicit
    // Money m = 500;                       // error: the constructor is explicit
    return 0;
}
