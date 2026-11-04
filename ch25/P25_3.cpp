// P25.3: Only Examiner::assignGrade may change a student's grade
#include <iostream>
#include <string>
using namespace std;

class Marks;                    // Examiner's member function needs this name

class Examiner
{
public:
    void assignGrade(Marks &m);
};

class Marks
{
private:
    string name;
    int marks[5];
    char grade;

public:
    Marks(string n, int a, int b, int c, int d, int e) : name(n), grade('-')
    {
        marks[0] = a; marks[1] = b; marks[2] = c; marks[3] = d; marks[4] = e;
    }

    void show() const
    {
        cout << name << ": grade " << grade << endl;
    }

    friend void Examiner::assignGrade(Marks &m);    // only this one function
};

void Examiner::assignGrade(Marks &m)
{
    int total = 0;
    for (int i = 0; i < 5; i++)
        total += m.marks[i];
    double percent = total / 5.0;       // each subject out of 100

    if (percent >= 80)      m.grade = 'A';
    else if (percent >= 65) m.grade = 'B';
    else if (percent >= 50) m.grade = 'C';
    else                    m.grade = 'F';

    cout << "Examiner: " << m.name << " has " << percent << "%" << endl;
}

int main()
{
    Marks s1("Ayesha", 78, 85, 91, 88, 80);
    Marks s2("Hamza", 45, 52, 40, 48, 55);

    cout << "Before grading:" << endl;
    s1.show();
    s2.show();

    Examiner ex;
    ex.assignGrade(s1);
    ex.assignGrade(s2);

    cout << "After grading:" << endl;
    s1.show();
    s2.show();
    return 0;
}
