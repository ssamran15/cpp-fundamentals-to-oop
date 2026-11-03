// P22.6: A Library that holds pointers to Book objects
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title, author;

public:
    Book(string t, string a) : title(t), author(a) {}
    string getTitle() const { return title; }
    void show() const { cout << "  " << title << " by " << author << endl; }
};

class Library
{
private:
    const Book *books[50];
    int count;

public:
    Library() : count(0) {}

    bool add(const Book *b)
    {
        if (count == 50)
            return false;
        books[count++] = b;
        return true;
    }

    void listAll() const
    {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < count; i++)
            books[i]->show();
    }

    const Book *search(string title) const
    {
        for (int i = 0; i < count; i++)
            if (books[i]->getTitle() == title)
                return books[i];
        return nullptr;             // not found
    }
};

int main()
{
    Book b1("Computer Science Made Easy", "Ahmad Raza");
    Book b2("Learning Databases", "Hina Tariq");
    Book b3("Networks for Beginners", "Usman Ali");

    Library lib;
    lib.add(&b1);
    lib.add(&b2);
    lib.add(&b3);
    lib.listAll();

    string wanted;
    cout << "Title to search: ";
    getline(cin, wanted);
    const Book *found = lib.search(wanted);
    if (found != nullptr)
    {
        cout << "Found:" << endl;
        found->show();
    }
    else
        cout << "Not found" << endl;
    return 0;
}
