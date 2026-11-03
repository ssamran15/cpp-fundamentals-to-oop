// P12.9: Result sheet with an array of structures
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    int marks[3];
};

int main()
{
    const int N = 5;
    Student s[N] = {
        {101, "Ayesha", {78, 85, 91}},
        {102, "Bilal",  {66, 72, 58}},
        {103, "Fatima", {88, 94, 90}},
        {104, "Hamza",  {55, 61, 70}},
        {105, "Sana",   {82, 79, 88}}
    };

    int topper = 0, topTotal = -1;
    cout << fixed << setprecision(2);
    cout << left << setw(6) << "Roll" << setw(10) << "Name" << right
         << setw(5) << "S1" << setw(5) << "S2" << setw(5) << "S3"
         << setw(8) << "Total" << setw(8) << "%" << endl;

    for (int i = 0; i < N; i++)
    {
        int total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2];
        cout << left << setw(6) << s[i].roll << setw(10) << s[i].name << right;
        for (int j = 0; j < 3; j++)
            cout << setw(5) << s[i].marks[j];
        cout << setw(8) << total << setw(8) << total / 3.0 << endl;

        if (total > topTotal)
        {
            topTotal = total;
            topper = i;
        }
    }
    cout << endl << "Topper: " << s[topper].name << " (" << topTotal << " marks)" << endl;
    return 0;
}
