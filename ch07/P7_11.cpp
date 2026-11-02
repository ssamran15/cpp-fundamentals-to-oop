// P7.11: Passed, failed and class average
#include <iostream>
using namespace std;

int main()
{
    int passed = 0, failed = 0;
    double total = 0;

    cout << "Enter marks of 10 students: ";
    for (int i = 1; i <= 10; i++)
    {
        int marks;
        cin >> marks;
        total += marks;
        if (marks >= 50)
            passed++;
        else
            failed++;
    }

    cout << "Passed       : " << passed << endl;
    cout << "Failed       : " << failed << endl;
    cout << "Class average: " << total / 10 << endl;
    return 0;
}
