// P16.8: Grades with enum class Grade
#include <iostream>
using namespace std;

enum class Grade { A, B, C, D, F };

Grade gradeOf(int marks);

int main()
{
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    cout << "Grade: ";
    switch (gradeOf(marks))
    {
        case Grade::A: cout << "A"; break;
        case Grade::B: cout << "B"; break;
        case Grade::C: cout << "C"; break;
        case Grade::D: cout << "D"; break;
        case Grade::F: cout << "F"; break;
    }
    cout << endl;
    return 0;
}

Grade gradeOf(int marks)
{
    if (marks >= 80) return Grade::A;
    if (marks >= 65) return Grade::B;
    if (marks >= 50) return Grade::C;
    if (marks >= 40) return Grade::D;
    return Grade::F;
}
