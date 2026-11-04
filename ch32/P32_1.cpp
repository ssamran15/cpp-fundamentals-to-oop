// P32.1: Even and odd counts, then removing negative numbers
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> v;
    int x;
    cout << "Enter numbers (0 to stop): ";
    cin >> x;
    while (x != 0)
    {
        v.push_back(x);
        cin >> x;
    }

    int even = 0, odd = 0;
    for (int n : v)
    {
        if (n % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << "Even: " << even << ", odd: " << odd << endl;

    for (int i = 0; i < static_cast<int>(v.size()); )
    {
        if (v[i] < 0)
            v.erase(v.begin() + i);     // the next element moves into position i
        else
            i++;                        // move on only when nothing was erased
    }
    cout << "Without the negative numbers: ";
    print(v);
    return 0;
}
