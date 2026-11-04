// P30.6: Books in a binary file, searched by code
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book
{
private:
    int code;
    char title[40];
    double price;

public:
    Book() : code(0), price(0) { title[0] = '\0'; }

    Book(int c, const char *t, double p) : code(c), price(p)
    {
        strncpy(title, t, 39);
        title[39] = '\0';
    }

    int getCode() const { return code; }

    void save(ofstream &out) const
    {
        out.write(reinterpret_cast<const char *>(this), sizeof(Book));
    }

    bool load(ifstream &in)
    {
        return static_cast<bool>(in.read(reinterpret_cast<char *>(this), sizeof(Book)));
    }

    void show() const
    {
        cout << code << "  " << title << "  Rs. " << price << endl;
    }
};

int main()
{
    Book books[10] = {
        Book(101, "Computer Science Made Easy", 950), Book(102, "Learning Databases", 1200),
        Book(103, "Networks for Beginners", 780),     Book(104, "Discrete Structures", 860),
        Book(105, "Calculus Workbook", 640),          Book(106, "English Composition", 520),
        Book(107, "Digital Logic", 900),              Book(108, "Operating Systems Notes", 1050),
        Book(109, "Web Basics", 700),                 Book(110, "Software Engineering", 990)
    };

    ofstream out("books.dat", ios::binary);
    for (int i = 0; i < 10; i++)
        books[i].save(out);
    out.close();
    cout << "10 books saved to books.dat" << endl;

    int wanted;
    cout << "Code to search: ";
    cin >> wanted;

    ifstream in("books.dat", ios::binary);
    Book b;
    bool found = false;
    while (b.load(in))
    {
        if (b.getCode() == wanted)
        {
            b.show();
            found = true;
            break;
        }
    }
    in.close();
    if (!found)
        cout << "No book with code " << wanted << endl;
    return 0;
}
