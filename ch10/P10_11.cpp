// P10.11: Searching a roll number
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int roll[SIZE]  = {101, 104, 107, 110, 112, 115, 118, 121, 125, 130};
    int marks[SIZE] = { 78,  64,  91,  55,  83,  47,  70,  88,  62,  95};
    int r;

    cout << "Enter roll number: ";
    cin >> r;

    int pos = -1;
    for (int i = 0; i < SIZE; i++)
    {
        if (roll[i] == r)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << "Roll number " << r << " not found" << endl;
    else
        cout << "Marks of roll number " << r << ": " << marks[pos] << endl;
    return 0;
}
