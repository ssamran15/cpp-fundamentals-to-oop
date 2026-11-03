// P11.6: Result sheet of 5 students
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int STUDENTS = 5, SUBJECTS = 3;
    int marks[STUDENTS][SUBJECTS];

    for (int i = 0; i < STUDENTS; i++)
    {
        cout << "Marks of student " << i + 1 << " in 3 subjects (out of 100): ";
        for (int j = 0; j < SUBJECTS; j++)
            cin >> marks[i][j];
    }

    cout << endl << fixed << setprecision(2);
    cout << setw(8) << "Student" << setw(6) << "S1" << setw(6) << "S2" << setw(6) << "S3"
         << setw(8) << "Total" << setw(8) << "%" << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        int total = 0;
        cout << setw(8) << i + 1;
        for (int j = 0; j < SUBJECTS; j++)
        {
            cout << setw(6) << marks[i][j];
            total += marks[i][j];
        }
        cout << setw(8) << total << setw(8) << total * 100.0 / (SUBJECTS * 100) << endl;
    }

    cout << endl;
    for (int j = 0; j < SUBJECTS; j++)
    {
        int highest = marks[0][j];
        for (int i = 1; i < STUDENTS; i++)
            if (marks[i][j] > highest)
                highest = marks[i][j];
        cout << "Highest in subject " << j + 1 << ": " << highest << endl;
    }
    return 0;
}
