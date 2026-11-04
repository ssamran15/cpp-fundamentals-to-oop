// P26.4: Lecturer and Clerk salaries
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double basic;

public:
    Employee(string n, double b) : name(n), basic(b) {}
    double salary() const { return basic; }
};

class Lecturer : public Employee
{
private:
    int extraLectures;

public:
    Lecturer(string n, double b, int e) : Employee(n, b), extraLectures(e) {}

    double salary() const           // overrides Employee::salary
    {
        return Employee::salary() + extraLectures * 1500.0;
    }

    void slip() const
    {
        cout << "Lecturer " << name << ": basic " << basic << " + "
             << extraLectures << " extra lectures = Rs. " << salary() << endl;
    }
};

class Clerk : public Employee
{
private:
    int overtimeHours;

public:
    Clerk(string n, double b, int h) : Employee(n, b), overtimeHours(h) {}

    double salary() const
    {
        return Employee::salary() + overtimeHours * 400.0;
    }

    void slip() const
    {
        cout << "Clerk " << name << ": basic " << basic << " + "
             << overtimeHours << " overtime hours = Rs. " << salary() << endl;
    }
};

int main()
{
    Lecturer l1("Hina Tariq", 95000, 6), l2("Usman Ali", 88000, 0);
    Clerk c1("Imran Haider", 42000, 15), c2("Asad Mehmood", 40000, 8);

    l1.slip();
    l2.slip();
    c1.slip();
    c2.slip();

    double total = l1.salary() + l2.salary() + c1.salary() + c2.salary();
    cout << "Total salary bill: Rs. " << total << endl;
    return 0;
}
