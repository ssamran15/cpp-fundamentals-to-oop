// P26.5: A multilevel hierarchy of students
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int roll;

public:
    Student(string n, int r) : name(n), roll(r)
    {
        cout << "[Student constructor]" << endl;
    }

    void show() const
    {
        cout << "Name: " << name << ", roll " << roll << endl;
    }
};

class Undergraduate : public Student
{
protected:
    string program;
    int semester;

public:
    Undergraduate(string n, int r, string p, int s) : Student(n, r), program(p), semester(s)
    {
        cout << "[Undergraduate constructor]" << endl;
    }

    void show() const
    {
        Student::show();
        cout << "Program: " << program << ", semester " << semester << endl;
    }
};

class FinalYearStudent : public Undergraduate
{
private:
    string project, supervisor;

public:
    FinalYearStudent(string n, int r, string p, int s, string pr, string sup)
        : Undergraduate(n, r, p, s), project(pr), supervisor(sup)
    {
        cout << "[FinalYearStudent constructor]" << endl;
    }

    void show() const
    {
        Undergraduate::show();
        cout << "Project: " << project << ", supervised by " << supervisor << endl;
    }
};

int main()
{
    FinalYearStudent f("Fatima Noor", 2207, "BS Computer Science", 8,
                       "Smart Attendance System", "Hina Tariq");
    cout << endl;
    f.show();
    return 0;
}
