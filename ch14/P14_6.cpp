// P14.6: A dynamic array of structures
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    int marks;
};

int main()
{
    int n;
    cout << "Number of students: ";
    cin >> n;

    Student *s = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << " roll number: ";
        cin >> s[i].roll;
        cin.ignore(100, '\n');
        cout << "Name: ";
        getline(cin, s[i].name);
        cout << "Marks: ";
        cin >> s[i].marks;
    }

    int top = 0;
    for (int i = 1; i < n; i++)
        if (s[i].marks > s[top].marks)
            top = i;

    cout << endl << "Topper: " << s[top].name << " (roll " << s[top].roll
         << ", " << s[top].marks << " marks)" << endl;

    delete[] s;
    return 0;
}
