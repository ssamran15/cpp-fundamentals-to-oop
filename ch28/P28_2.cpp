// P28.2: A bonus for lecturers only, using dynamic_cast
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double basicPay;

public:
    Employee(string n, double b) : name(n), basicPay(b) {}
    virtual ~Employee() {}

    virtual double salary() const { return basicPay; }
    virtual string designation() const { return "Employee"; }

    void slip() const
    {
        cout << designation() << " " << name << ": Rs. " << salary() << endl;
    }
};

class Lecturer : public Employee
{
private:
    int extraLectures;
    double bonus;

public:
    Lecturer(string n, double b, int e) : Employee(n, b), extraLectures(e), bonus(0) {}

    double salary() const override { return basicPay + extraLectures * 1500.0 + bonus; }
    string designation() const override { return "Lecturer"; }

    void giveBonus(double amount) { bonus += amount; }      // only in Lecturer
};

class Clerk : public Employee
{
private:
    int overtimeHours;

public:
    Clerk(string n, double b, int h) : Employee(n, b), overtimeHours(h) {}

    double salary() const override { return basicPay + overtimeHours * 400.0; }
    string designation() const override { return "Clerk"; }
};

int main()
{
    Lecturer l1("Hamza Ali", 95000, 12), l2("Sana Tariq", 102000, 8);
    Clerk c1("Imran", 42000, 20), c2("Asad", 40000, 5);
    Employee *staff[4] = { &l1, &c1, &l2, &c2 };

    double bonus;
    cout << "Result bonus for lecturers: Rs. ";
    cin >> bonus;

    for (int i = 0; i < 4; i++)
    {
        Lecturer *lp = dynamic_cast<Lecturer *>(staff[i]);
        if (lp != nullptr)                  // the cast worked: this is a lecturer
            lp->giveBonus(bonus);
    }

    for (int i = 0; i < 4; i++)
        staff[i]->slip();
    return 0;
}
