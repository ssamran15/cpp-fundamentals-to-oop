// P16.12: Ending the program with exit on invalid marks
#include <iostream>
#include <cstdlib>
using namespace std;

int readMarks(int student);

int main()
{
    int total = 0;
    for (int i = 1; i <= 5; i++)
        total += readMarks(i);

    cout << "Average = " << total / 5.0 << endl;
    return EXIT_SUCCESS;
}

int readMarks(int student)
{
    int marks;
    cout << "Marks of student " << student << ": ";
    cin >> marks;
    if (marks < 0 || marks > 100)
    {
        cout << "Invalid marks: " << marks << ". The program will end." << endl;
        exit(EXIT_FAILURE);         // ends the whole program, not just this function
    }
    return marks;
}
