// P20.5: A Person class with a dynamic C-string name
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;

public:
    Person(const char *n, int a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }

    Person(const Person &other)
    {
        name = new char[strlen(other.name) + 1];    // its own memory
        strcpy(name, other.name);
        age = other.age;
        cout << "  [copy constructor: copied " << name << "]" << endl;
    }

    ~Person()
    {
        delete[] name;
    }

    void show()
    {
        cout << "  " << name << ", " << age << " years" << endl;
    }
};

void printPerson(Person p)              // by value: p is a copy
{
    cout << "Inside printPerson:" << endl;
    p.show();
}                                       // p's destructor frees the copy's memory

int main()
{
    Person a("Muhammad Usman", 21);
    printPerson(a);

    cout << "Back in main, the original is unharmed:" << endl;
    a.show();
    cout << "Program ends safely" << endl;
    return 0;
}
