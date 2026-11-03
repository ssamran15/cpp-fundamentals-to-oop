// P11.13: Sorting city names
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int N = 5;
    char city[N][30];

    for (int i = 0; i < N; i++)
    {
        cout << "City " << i + 1 << ": ";
        cin.getline(city[i], 30);
    }

    char temp[30];
    for (int pass = 1; pass < N; pass++)
    {
        for (int i = 0; i < N - pass; i++)
        {
            if (strcmp(city[i], city[i + 1]) > 0)     // city[i] comes after city[i + 1]
            {
                strcpy(temp, city[i]);
                strcpy(city[i], city[i + 1]);
                strcpy(city[i + 1], temp);
            }
        }
    }

    cout << endl << "In alphabetical order:" << endl;
    for (int i = 0; i < N; i++)
        cout << city[i] << endl;
    return 0;
}
