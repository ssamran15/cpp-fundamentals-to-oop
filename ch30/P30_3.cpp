// P30.3: Employees in a CSV file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    double salary;

public:
    Employee() : id(0), name(""), salary(0) {}
    double getSalary() const { return salary; }

    friend ostream &operator<<(ostream &out, const Employee &e);
    friend istream &operator>>(istream &in, Employee &e);
};

ostream &operator<<(ostream &out, const Employee &e)
{
    out << e.id << "," << e.name << "," << e.salary;
    return out;
}

istream &operator>>(istream &in, Employee &e)    // reads one line: id,full name,salary
{
    string idText, salaryText;
    if (getline(in, idText, ',') && getline(in, e.name, ',') && getline(in, salaryText))
    {
        e.id = stoi(idText);
        e.salary = stod(salaryText);
    }
    return in;
}

int main()
{
    const int N = 5;
    Employee list[N];
    cout << "Enter " << N << " employees as id,full name,salary:" << endl;
    for (int i = 0; i < N; i++)
        cin >> list[i];

    ofstream out("employees.csv");
    for (int i = 0; i < N; i++)
        out << list[i] << endl;
    out.close();
    cout << "Saved to employees.csv" << endl;

    ifstream in("employees.csv");
    Employee e, best;
    bool first = true;
    while (in >> e)
    {
        if (first || e.getSalary() > best.getSalary())
            best = e;
        first = false;
    }
    in.close();
    cout << "Highest salary: " << best << endl;
    return 0;
}
