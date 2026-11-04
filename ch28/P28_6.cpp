// P28.6: Patient bills, then the rooms of indoor patients
#include <iostream>
#include <string>
using namespace std;

class Patient
{
protected:
    string name;

public:
    Patient(string n) : name(n) {}
    virtual ~Patient() {}
    virtual double bill() const = 0;
    string getName() const { return name; }
};

class IndoorPatient : public Patient
{
private:
    int room, days;

public:
    IndoorPatient(string n, int r, int d) : Patient(n), room(r), days(d) {}
    double bill() const override { return 2000 + days * 3500.0; }  // practice rates
    int getRoom() const { return room; }
};

class OutdoorPatient : public Patient
{
public:
    OutdoorPatient(string n) : Patient(n) {}
    double bill() const override { return 800; }                    // consultation only
};

int main()
{
    IndoorPatient a("Rabia Saleem", 204, 3), b("Kamran Yousaf", 117, 6);
    OutdoorPatient c("Nadia Akram"), d("Asad Mehmood");
    Patient *patients[4] = { &a, &c, &b, &d };

    cout << "Bills:" << endl;
    for (int i = 0; i < 4; i++)
        cout << "  " << patients[i]->getName() << ": Rs. " << patients[i]->bill() << endl;

    cout << "Rooms of indoor patients:" << endl;
    for (int i = 0; i < 4; i++)
    {
        IndoorPatient *ip = dynamic_cast<IndoorPatient *>(patients[i]);
        if (ip != nullptr)
            cout << "  " << ip->getName() << ": room " << ip->getRoom() << endl;
    }
    return 0;
}
