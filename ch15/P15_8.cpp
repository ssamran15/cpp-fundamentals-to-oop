// P15.8: Random access to employee records
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee
{
    int id;
    char name[30];
    double salary;
};

int main()
{
    Employee list[5] = { {1, "Asad Mehmood", 57000}, {2, "Rabia Saleem", 77500},
                         {3, "Imran Haider", 47000}, {4, "Nadia Akram", 76000},
                         {5, "Kamran Yousaf", 78000} };

    ofstream out("employees.dat", ios::binary);
    out.write(reinterpret_cast<char*>(list), sizeof(list));
    out.close();
    cout << "5 records written to employees.dat" << endl;

    int n;
    cout << "Record number (1 to 5): ";
    cin >> n;
    if (n < 1 || n > 5)
    {
        cout << "No such record" << endl;
        return 1;
    }

    ifstream in("employees.dat", ios::binary);
    Employee e;
    in.seekg((n - 1) * sizeof(Employee), ios::beg);     // jump straight to record n
    in.read(reinterpret_cast<char*>(&e), sizeof(Employee));
    in.close();

    cout << "ID: " << e.id << endl;
    cout << "Name: " << e.name << endl;
    cout << "Salary: Rs. " << fixed << setprecision(2) << e.salary << endl;
    return 0;
}
