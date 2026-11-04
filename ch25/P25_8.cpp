// P25.8: Reading and printing Student records with >> and <<
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
    string name;            // one word
    int roll;
    int marks;

public:
    Student() : name(""), roll(0), marks(0) {}

    int getMarks() const { return marks; }
    string getName() const { return name; }

    friend istream &operator>>(istream &in, Student &s);
    friend ostream &operator<<(ostream &out, const Student &s);
};

istream &operator>>(istream &in, Student &s)
{
    in >> s.name >> s.roll >> s.marks;
    return in;
}

ostream &operator<<(ostream &out, const Student &s)
{
    out << left << setw(10) << s.name << right << setw(6) << s.roll << setw(7) << s.marks;
    return out;
}

int main()
{
    Student list[5];
    cout << "Enter name, roll number and marks of 5 students:" << endl;
    for (int i = 0; i < 5; i++)
        cin >> list[i];

    cout << endl << left << setw(10) << "Name" << right << setw(6) << "Roll" << setw(7) << "Marks" << endl;
    int top = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << list[i] << endl;
        if (list[i].getMarks() > list[top].getMarks())
            top = i;
    }
    cout << "Topper: " << list[top].getName() << endl;
    return 0;
}
