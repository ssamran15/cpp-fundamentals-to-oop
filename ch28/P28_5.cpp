// P28.5: Library items: counts with typeid, total pages with dynamic_cast
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class LibraryItem
{
protected:
    string title;

public:
    LibraryItem(string t) : title(t) {}
    virtual ~LibraryItem() {}
    virtual void show() const = 0;
};

class Book : public LibraryItem
{
private:
    int pages;

public:
    Book(string t, int p) : LibraryItem(t), pages(p) {}
    void show() const override { cout << "Book: " << title << ", " << pages << " pages" << endl; }
    int getPages() const { return pages; }
};

class Magazine : public LibraryItem
{
private:
    int issue;

public:
    Magazine(string t, int i) : LibraryItem(t), issue(i) {}
    void show() const override { cout << "Magazine: " << title << ", issue " << issue << endl; }
};

class CD : public LibraryItem
{
private:
    int minutes;

public:
    CD(string t, int m) : LibraryItem(t), minutes(m) {}
    void show() const override { cout << "CD: " << title << ", " << minutes << " minutes" << endl; }
};

int main()
{
    Book b1("Computer Science Made Easy", 420), b2("Learning Databases", 365);
    Magazine m1("Campus Science", 58);
    CD c1("Urdu Poetry Readings", 72), c2("C++ Video Lectures", 180);
    Book b3("Networks for Beginners", 290);

    LibraryItem *items[6] = { &b1, &m1, &c1, &b2, &c2, &b3 };

    int books = 0, magazines = 0, cds = 0;
    for (int i = 0; i < 6; i++)
    {
        items[i]->show();
        if (typeid(*items[i]) == typeid(Book))
            books++;
        else if (typeid(*items[i]) == typeid(Magazine))
            magazines++;
        else if (typeid(*items[i]) == typeid(CD))
            cds++;
    }
    cout << endl << "Books: " << books << ", magazines: " << magazines << ", CDs: " << cds << endl;

    int pages = 0;
    for (int i = 0; i < 6; i++)
    {
        const Book *b = dynamic_cast<const Book *>(items[i]);
        if (b != nullptr)
            pages += b->getPages();
    }
    cout << "Total pages of all books: " << pages << endl;
    return 0;
}
