// P15.3: Adding grades to a marks file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char grade(int marks);

int main()
{
    ifstream in("marks.txt");
    if (!in)
    {
        cout << "Cannot open marks.txt" << endl;
        return 1;
    }
    ofstream out("result.txt");

    string name;
    int marks, count = 0;
    while (in >> name >> marks)
    {
        out << name << " " << marks << " " << grade(marks) << endl;
        count++;
    }
    in.close();
    out.close();

    cout << count << " records written to result.txt" << endl;
    return 0;
}

char grade(int marks)
{
    if (marks >= 80) return 'A';
    if (marks >= 65) return 'B';
    if (marks >= 50) return 'C';
    return 'F';
}
