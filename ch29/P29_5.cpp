// P29.5: A two-way association between Doctor and Patient
#include <iostream>
#include <string>
using namespace std;

class Patient;

class Doctor
{
private:
    string name;
    Patient *patients[10];
    int count;

public:
    Doctor(string n) : name(n), count(0) {}
    string getName() const { return name; }
    void addPatient(Patient *p);
    void showPatients() const;
};

class Patient
{
private:
    string name;
    Doctor *doctor;

public:
    Patient(string n) : name(n), doctor(nullptr) {}
    string getName() const { return name; }

    void setDoctor(Doctor *d) { doctor = d; }

    void showDoctor() const
    {
        cout << name << " is treated by "
             << (doctor != nullptr ? doctor->getName() : "no doctor yet") << endl;
    }
};

void Doctor::addPatient(Patient *p)
{
    if (count == 10)
        return;
    patients[count++] = p;
    p->setDoctor(this);                 // keep both directions of the link in step
}

void Doctor::showPatients() const
{
    cout << name << "'s patients:";
    for (int i = 0; i < count; i++)
        cout << " " << patients[i]->getName() << (i < count - 1 ? "," : "");
    cout << endl;
}

int main()
{
    Doctor d1("Dr. Hina Tariq"), d2("Dr. Kamran Yousaf");
    Patient p1("Ali"), p2("Sana"), p3("Bilal"), p4("Fatima");

    d1.addPatient(&p1);
    d1.addPatient(&p3);
    d2.addPatient(&p2);

    d1.showPatients();
    d2.showPatients();
    p1.showDoctor();
    p2.showDoctor();
    p3.showDoctor();
    p4.showDoctor();
    return 0;
}
