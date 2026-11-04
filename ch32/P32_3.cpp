// P32.3: Program 27.8 with a vector<Student *>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double SEMESTER_FEE = 24000;      // practice figures only
const double SELF_FINANCE_CHARGES = 18000;

class Student                           // abstract base class
{
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}
    virtual ~Student() {}

    virtual double fee() const = 0;
    virtual string category() const = 0;

    void challan() const
    {
        cout << rollNo << "  " << name << " (" << category() << "): Rs. " << fee() << endl;
    }
};

class RegularStudent : public Student
{
public:
    RegularStudent(string n, int r) : Student(n, r) {}

    double fee() const override { return SEMESTER_FEE; }
    string category() const override { return "Regular"; }
};

class SelfFinanceStudent : public Student
{
public:
    SelfFinanceStudent(string n, int r) : Student(n, r) {}

    double fee() const override { return SEMESTER_FEE + SELF_FINANCE_CHARGES; }
    string category() const override { return "Self-finance"; }
};

class ScholarshipStudent : public Student
{
private:
    int waiver;                         // percentage of fee waived

public:
    ScholarshipStudent(string n, int r, int w) : Student(n, r), waiver(w) {}

    double fee() const override { return SEMESTER_FEE * (100 - waiver) / 100; }
    string category() const override
    {
        return "Scholarship " + to_string(waiver) + "%";
    }
};

int main()
{
    vector<Student *> list;             // grows as needed: no MAX

    cout << "Types: 1 Regular, 2 Self-finance, 3 Scholarship (name 0 0 to stop)" << endl;
    while (true)
    {
        string name;
        int roll, type;
        cout << "Student " << list.size() + 1 << " (name roll type): ";
        cin >> name >> roll >> type;
        if (type == 0)
            break;

        if (type == 2)
            list.push_back(new SelfFinanceStudent(name, roll));
        else if (type == 3)
        {
            int w;
            cout << "  Waiver percentage: ";
            cin >> w;
            list.push_back(new ScholarshipStudent(name, roll, w));
        }
        else
            list.push_back(new RegularStudent(name, roll));
    }

    cout << endl << "Fee challans" << endl;
    double total = 0;
    for (const Student *s : list)
    {
        s->challan();
        total += s->fee();
    }
    cout << "Total fee to be collected: Rs. " << total << endl;

    for (Student *s : list)
        delete s;
    return 0;
}
