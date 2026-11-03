// P12.10: Pay sheet sorted by gross salary
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee
{
    string name;
    double basic;
    double allowances;
};

double gross(const Employee &e);
void printSheet(const Employee e[], int n);

int main()
{
    const int N = 5;
    Employee emp[N] = {
        {"Asad Mehmood", 45000, 12000},
        {"Rabia Saleem", 62000, 15500},
        {"Imran Haider", 38000, 9000},
        {"Nadia Akram",  55000, 21000},
        {"Kamran Yousaf", 70000, 8000}
    };

    cout << "Pay sheet" << endl;
    printSheet(emp, N);

    // bubble sort by gross salary, highest first
    for (int pass = 1; pass < N; pass++)
        for (int i = 0; i < N - pass; i++)
            if (gross(emp[i]) < gross(emp[i + 1]))
            {
                Employee temp = emp[i];      // a whole structure can be assigned
                emp[i] = emp[i + 1];
                emp[i + 1] = temp;
            }

    cout << endl << "Sorted by gross salary" << endl;
    printSheet(emp, N);
    return 0;
}

double gross(const Employee &e)
{
    return e.basic + e.allowances;
}

void printSheet(const Employee e[], int n)
{
    cout << fixed << setprecision(0);
    cout << left << setw(15) << "Name" << right << setw(10) << "Basic"
         << setw(12) << "Allowances" << setw(10) << "Gross" << endl;
    for (int i = 0; i < n; i++)
        cout << left << setw(15) << e[i].name << right << setw(10) << e[i].basic
             << setw(12) << e[i].allowances << setw(10) << gross(e[i]) << endl;
}
