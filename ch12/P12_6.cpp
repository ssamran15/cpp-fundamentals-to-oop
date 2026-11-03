// P12.6: Sorting city names stored as string
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int N = 5;
    string city[N];

    for (int i = 0; i < N; i++)
    {
        cout << "City " << i + 1 << ": ";
        getline(cin, city[i]);
    }

    for (int pass = 1; pass < N; pass++)
        for (int i = 0; i < N - pass; i++)
            if (city[i] > city[i + 1])          // strings compare with > directly
            {
                string temp = city[i];
                city[i] = city[i + 1];
                city[i + 1] = temp;
            }

    cout << endl << "In alphabetical order:" << endl;
    for (int i = 0; i < N; i++)
        cout << city[i] << endl;
    return 0;
}
