// P17.3: Student structure with member functions
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    int marks[5];

    int total()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        return sum;
    }

    double percentage()
    {
        return total() * 100.0 / 500;   // 5 subjects of 100 marks
    }

    char grade()
    {
        double p = percentage();
        if (p >= 80) return 'A';
        if (p >= 65) return 'B';
        if (p >= 50) return 'C';
        return 'F';
    }
};

int main()
{
    Student s[3] = {
        {"Ayesha", {78, 85, 91, 88, 80}},
        {"Bilal",  {66, 72, 58, 61, 70}},
        {"Hamza",  {45, 52, 40, 48, 55}}
    };

    cout << fixed << setprecision(2);
    cout << left << setw(10) << "Name" << right << setw(8) << "Total"
         << setw(8) << "%" << setw(8) << "Grade" << endl;
    for (int i = 0; i < 3; i++)
        cout << left << setw(10) << s[i].name << right << setw(8) << s[i].total()
             << setw(8) << s[i].percentage() << setw(8) << s[i].grade() << endl;
    return 0;
}
