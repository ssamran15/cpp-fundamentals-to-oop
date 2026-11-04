// P30.7: Program 30.7 with a "Delete record" choice
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

class Student
{
private:
    int rollNo = 0;
    char name[30] = "";
    double cgpa = 0;

public:
    void input()
    {
        cout << "Roll no: ";
        cin >> rollNo;
        cin.ignore(100, '\n');              // remove the Enter key
        cout << "Name: ";
        cin.getline(name, 30);
        cout << "CGPA: ";
        cin >> cgpa;
    }
    int getRollNo() const { return rollNo; }
    void setCgpa(double g) { cgpa = g; }
    void show() const { cout << "  " << rollNo << "  " << name << "  " << cgpa << endl; }
};

class StudentFile
{
private:
    const char *fileName;

public:
    StudentFile(const char *f) : fileName(f) {}

    void add(const Student &s)
    {
        ofstream out(fileName, ios::binary | ios::app);
        out.write(reinterpret_cast<const char *>(&s), sizeof(Student));
    }

    void listAll()
    {
        ifstream in(fileName, ios::binary);
        Student s;
        int n = 0;
        while (in.read(reinterpret_cast<char *>(&s), sizeof(Student)))
        {
            s.show();
            n++;
        }
        cout << "  " << n << " record(s)" << endl;
    }

    int find(int roll, Student &result)     // record number, or -1
    {
        ifstream in(fileName, ios::binary);
        Student s;
        int pos = 0;
        while (in.read(reinterpret_cast<char *>(&s), sizeof(Student)))
        {
            if (s.getRollNo() == roll)
            {
                result = s;
                return pos;
            }
            pos++;
        }
        return -1;
    }

    bool updateCgpa(int roll, double g)
    {
        Student s;
        int pos = find(roll, s);
        if (pos == -1)
            return false;
        s.setCgpa(g);
        fstream f(fileName, ios::in | ios::out | ios::binary);
        f.seekp(pos * sizeof(Student), ios::beg);
        f.write(reinterpret_cast<const char *>(&s), sizeof(Student));
        return true;
    }

    bool remove(int roll)                   // the new function
    {
        ifstream in(fileName, ios::binary);
        ofstream temp("temp.dat", ios::binary);
        Student s;
        bool found = false;
        while (in.read(reinterpret_cast<char *>(&s), sizeof(Student)))
        {
            if (s.getRollNo() == roll)
                found = true;               // skip this one
            else
                temp.write(reinterpret_cast<const char *>(&s), sizeof(Student));
        }
        in.close();
        temp.close();

        if (found)
        {
            std::remove(fileName);          // delete the old file
            std::rename("temp.dat", fileName);   // the copy takes its place
        }
        else
            std::remove("temp.dat");        // nothing changed: throw the copy away
        return found;
    }
};

int main()
{
    StudentFile db("students.dat");
    int choice;

    do
    {
        cout << endl << "1 Add  2 List  3 Search  4 Update CGPA  5 Delete  0 Exit: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;
            s.input();
            db.add(s);
        }
        else if (choice == 2)
            db.listAll();
        else if (choice >= 3 && choice <= 5)
        {
            int roll;
            cout << "Roll no: ";
            cin >> roll;
            Student s;
            if (choice == 3)
            {
                if (db.find(roll, s) == -1)
                    cout << "  Not found" << endl;
                else
                    s.show();
            }
            else if (choice == 4)
            {
                double g;
                cout << "New CGPA: ";
                cin >> g;
                cout << (db.updateCgpa(roll, g) ? "  Updated" : "  Not found") << endl;
            }
            else
                cout << (db.remove(roll) ? "  Deleted" : "  Not found") << endl;
        }
    } while (choice != 0);

    return 0;
}
