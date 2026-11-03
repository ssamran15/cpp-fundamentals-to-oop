// P22.7: A dynamic array of Employee objects, sorted by gross pay
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    double basic, allowances;

public:
    Employee() : name(""), basic(0), allowances(0) {}   // needed for new Employee[n]

    void input()
    {
        cout << "Name: ";
        getline(cin, name);
        cout << "Basic pay and allowances: ";
        cin >> basic >> allowances;
        cin.ignore(100, '\n');
    }

    double gross() const { return basic + allowances; }

    void show() const
    {
        cout << left << setw(16) << name << right << setw(10) << basic
             << setw(12) << allowances << setw(10) << gross() << endl;
    }
};

int main()
{
    int n;
    cout << "Number of employees: ";
    cin >> n;
    cin.ignore(100, '\n');

    Employee *staff = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Employee " << i + 1 << endl;
        staff[i].input();
    }

    for (int pass = 1; pass < n; pass++)        // highest gross first
        for (int i = 0; i < n - pass; i++)
            if (staff[i].gross() < staff[i + 1].gross())
            {
                Employee temp = staff[i];
                staff[i] = staff[i + 1];
                staff[i + 1] = temp;
            }

    cout << endl << fixed << setprecision(0);
    cout << left << setw(16) << "Name" << right << setw(10) << "Basic"
         << setw(12) << "Allowances" << setw(10) << "Gross" << endl;
    for (int i = 0; i < n; i++)
        staff[i].show();

    delete[] staff;
    return 0;
}
