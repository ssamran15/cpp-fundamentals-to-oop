// P26.2: TextBook derived from Book
#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
    string title, author;
    double price;

public:
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    void show() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: Rs. " << price << endl;
    }
};

class TextBook : public Book
{
private:
    string subject, forClass;

public:
    TextBook(string t, string a, double p, string s, string c)
        : Book(t, a, p), subject(s), forClass(c) {}

    void show() const               // overrides Book::show
    {
        Book::show();               // the base part first
        cout << "Subject: " << subject << endl;
        cout << "Prescribed for: " << forClass << endl;
    }
};

int main()
{
    TextBook tb("Computer Science Made Easy", "Ahmad Raza", 950,
                "Computer Science", "BS 1st semester");
    tb.show();
    return 0;
}
