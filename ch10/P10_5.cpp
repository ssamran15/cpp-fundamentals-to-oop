// P10.5: Grade counts for 20 students
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 20;
    int marks[SIZE];
    int a = 0, b = 0, c = 0, f = 0;

    cout << "Enter the marks of " << SIZE << " students:" << endl;
    for (int i = 0; i < SIZE; i++)
        cin >> marks[i];

    for (int i = 0; i < SIZE; i++)
    {
        if (marks[i] >= 80)
            a++;
        else if (marks[i] >= 65)
            b++;
        else if (marks[i] >= 50)
            c++;
        else
            f++;
    }
    cout << "Grade A: " << a << endl;
    cout << "Grade B: " << b << endl;
    cout << "Grade C: " << c << endl;
    cout << "Grade F: " << f << endl;
    return 0;
}
