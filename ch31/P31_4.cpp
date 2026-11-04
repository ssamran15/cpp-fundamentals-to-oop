// P31.4: maximum() and total() working with a Money class
#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
private:
    long paisa;

public:
    Money(long rupees = 0, int p = 0) : paisa(rupees * 100 + p) {}   // also the default constructor

    bool operator>(const Money &m) const { return paisa > m.paisa; }

    Money &operator+=(const Money &m)
    {
        paisa += m.paisa;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Money &m);
};

ostream &operator<<(ostream &out, const Money &m)
{
    out << "Rs. " << m.paisa / 100 << "." << setfill('0') << setw(2) << m.paisa % 100 << setfill(' ');
    return out;
}

// maximum() from Program 31.1, unchanged
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

// total() from Program 31.3, unchanged
template <typename T>
T total(const T a[], int n)
{
    T sum = T();                        // zero for numbers, "" for strings
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main()
{
    Money fee(24000), fine(350, 50);
    cout << "maximum(fee, fine) = " << maximum(fee, fine) << endl;

    Money bills[4] = { Money(1850), Money(480, 25), Money(650), Money(1180, 75) };
    cout << "total(bills, 4) = " << total(bills, 4) << endl;
    return 0;
}
