// P21.7: const roll numbers and a static class average
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    const int roll;
    string name;
    int marks;
    static int count;
    static int totalMarks;

public:
    Student(int r, string n, int m) : roll(r), name(n), marks(m)
    {
        count++;
        totalMarks += marks;
    }

    void show() const
    {
        cout << roll << "  " << name << "  " << marks << endl;
    }

    static double average()
    {
        if (count == 0)
            return 0;
        return static_cast<double>(totalMarks) / count;
    }

    static int getCount() { return count; }
};

int Student::count = 0;
int Student::totalMarks = 0;

int main()
{
    Student s1(101, "Ayesha", 78);
    Student s2(102, "Bilal", 64);
    Student s3(103, "Fatima", 91);
    Student s4(104, "Hamza", 55);

    s1.show();
    s2.show();
    s3.show();
    s4.show();
    cout << "Students: " << Student::getCount() << endl;
    cout << "Class average: " << Student::average() << endl;
    return 0;
}
