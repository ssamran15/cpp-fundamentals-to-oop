// P33.7: A library menu that never crashes
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class LibraryError : public runtime_error
{
public:
    LibraryError(const string &msg) : runtime_error(msg) {}
};

class BookNotFound : public LibraryError
{
public:
    BookNotFound(const string &title) : LibraryError("no book called \"" + title + "\"") {}
};

class BookAlreadyIssued : public LibraryError
{
private:
    string holder;

public:
    BookAlreadyIssued(const string &title, const string &who)
        : LibraryError("\"" + title + "\" is already issued"), holder(who) {}
    string issuedTo() const { return holder; }
};

class Book
{
public:
    string title;
    string issuedTo;                    // empty when the book is on the shelf

    Book(const string &t) : title(t), issuedTo("") {}
};

class Library
{
private:
    vector<Book> books;

    Book &find(const string &title)
    {
        for (Book &b : books)
            if (b.title == title)
                return b;
        throw BookNotFound(title);
    }

public:
    void add(const string &title) { books.push_back(Book(title)); }

    void issue(const string &title, const string &student)
    {
        Book &b = find(title);
        if (b.issuedTo != "")
            throw BookAlreadyIssued(title, b.issuedTo);
        b.issuedTo = student;
    }

    void giveBack(const string &title)
    {
        Book &b = find(title);
        if (b.issuedTo == "")
            throw LibraryError("\"" + title + "\" was not issued");
        b.issuedTo = "";
    }

    void list() const
    {
        for (const Book &b : books)
            cout << "  " << b.title << (b.issuedTo == "" ? "  (on the shelf)" : "  (with " + b.issuedTo + ")") << endl;
    }
};

int readChoice()
{
    string line;
    cout << "Choice: ";
    if (!getline(cin, line))
        return 0;                       // input has ended: treat as Exit
    try
    {
        return stoi(line);
    }
    catch (const exception &)
    {
        throw invalid_argument("\"" + line + "\" is not a menu number");
    }
}

int main()
{
    Library lib;
    lib.add("Computer Science Made Easy");
    lib.add("Learning Databases");
    lib.add("Networks for Beginners");

    int choice = -1;
    while (choice != 0)
    {
        cout << endl << "1. Issue  2. Return  3. List  0. Exit" << endl;
        try
        {
            choice = readChoice();
            string title, student;
            if (choice == 1)
            {
                cout << "Title: ";
                getline(cin, title);
                cout << "Student: ";
                getline(cin, student);
                lib.issue(title, student);
                cout << "Issued." << endl;
            }
            else if (choice == 2)
            {
                cout << "Title: ";
                getline(cin, title);
                lib.giveBack(title);
                cout << "Returned." << endl;
            }
            else if (choice == 3)
                lib.list();
            else if (choice != 0)
                cout << "Please choose from the menu." << endl;
        }
        catch (const BookAlreadyIssued &e)          // the most specific first
        {
            cout << "Refused: " << e.what() << " to " << e.issuedTo() << endl;
        }
        catch (const LibraryError &e)               // BookNotFound and the rest
        {
            cout << "Library error: " << e.what() << endl;
        }
        catch (const invalid_argument &e)
        {
            cout << "Input error: " << e.what() << endl;
        }
    }
    cout << "Goodbye." << endl;
    return 0;
}
