// P21.2: Automatic employee IDs from a static counter
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    const int id;               // fixed for life
    string name;
    static int nextId;          // shared by all employees

public:
    Employee(string n) : id(nextId++), name(n) {}

    void show() const
    {
        cout << "ID " << id << ": " << name << endl;
    }
};

int Employee::nextId = 1001;    // the definition of the static member

int main()
{
    Employee e1("Asad Mehmood");
    Employee e2("Rabia Saleem");
    Employee e3("Imran Haider");

    e1.show();
    e2.show();
    e3.show();
    return 0;
}
