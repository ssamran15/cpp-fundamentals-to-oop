// P10.4: Positive and negative numbers in separate arrays
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int A[SIZE], B[SIZE], C[SIZE];
    int nb = 0, nc = 0;          // how many values are in B and C

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> A[i];

    for (int i = 0; i < SIZE; i++)
    {
        if (A[i] > 0)
            B[nb++] = A[i];
        else if (A[i] < 0)
            C[nc++] = A[i];
    }

    cout << "Positive (B): ";
    for (int i = 0; i < nb; i++)
        cout << B[i] << " ";
    cout << endl;

    cout << "Negative (C): ";
    for (int i = 0; i < nc; i++)
        cout << C[i] << " ";
    cout << endl;
    return 0;
}
