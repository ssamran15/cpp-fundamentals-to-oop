// P7.15: Total and average of every student
#include <iostream>
using namespace std;

int main()
{
    for (int s = 1; s <= 5; s++)
    {
        int total = 0;
        cout << "Marks of student " << s << " in 3 subjects: ";
        for (int j = 1; j <= 3; j++)
        {
            int marks;
            cin >> marks;
            total += marks;
        }
        cout << "  Total = " << total << ", Average = " << total / 3.0 << endl;
    }
    return 0;
}
