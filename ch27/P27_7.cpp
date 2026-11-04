// P27.7: A pay sheet of permanent, visiting and daily-wage employees
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;

public:
    Employee(string n) : name(n) {}
    virtual ~Employee() {}
    virtual double pay() const = 0;
    virtual string type() const = 0;

    void line() const
    {
        cout << left << setw(10) << name << setw(12) << type() << right
             << "Rs. " << setw(9) << pay() << endl;
    }
};

class Permanent : public Employee
{
private:
    double salary;

public:
    Permanent(string n, double s) : Employee(n), salary(s) {}
    double pay() const override { return salary; }
    string type() const override { return "Permanent"; }
};

class Visiting : public Employee
{
private:
    int lectures;
    double rate;

public:
    Visiting(string n, int l, double r) : Employee(n), lectures(l), rate(r) {}
    double pay() const override { return lectures * rate; }
    string type() const override { return "Visiting"; }
};

class DailyWage : public Employee
{
private:
    int days;
    double dailyRate;

public:
    DailyWage(string n, int d, double r) : Employee(n), days(d), dailyRate(r) {}
    double pay() const override { return days * dailyRate; }
    string type() const override { return "Daily wage"; }
};

int main()
{
    const int N = 5;
    Employee *staff[N];

    cout << "Types: 1 Permanent, 2 Visiting, 3 Daily wage" << endl;
    for (int i = 0; i < N; i++)
    {
        string name;
        int type;
        cout << "Employee " << i + 1 << " (name type): ";
        cin >> name >> type;

        if (type == 2)
        {
            int l;
            double r;
            cout << "  Lectures and rate per lecture: ";
            cin >> l >> r;
            staff[i] = new Visiting(name, l, r);
        }
        else if (type == 3)
        {
            int d;
            double r;
            cout << "  Days worked and daily rate: ";
            cin >> d >> r;
            staff[i] = new DailyWage(name, d, r);
        }
        else
        {
            double s;
            cout << "  Monthly salary: ";
            cin >> s;
            staff[i] = new Permanent(name, s);
        }
    }

    cout << endl << "Pay sheet" << endl << fixed << setprecision(0);
    double total = 0;
    for (int i = 0; i < N; i++)
    {
        staff[i]->line();
        total += staff[i]->pay();
    }
    cout << "Total: Rs. " << total << endl;

    for (int i = 0; i < N; i++)
        delete staff[i];
    return 0;
}
