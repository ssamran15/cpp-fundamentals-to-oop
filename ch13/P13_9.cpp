// P13.9: Bubble sort in pointer notation
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> *(a + i);

    for (int pass = 1; pass < SIZE; pass++)
    {
        for (int j = 0; j < SIZE - pass; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                int temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }

    cout << "Sorted: ";
    for (int i = 0; i < SIZE; i++)
        cout << *(a + i) << " ";
    cout << endl;
    return 0;
}
