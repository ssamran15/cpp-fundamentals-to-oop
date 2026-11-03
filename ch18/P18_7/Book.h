// P18.7: Book.h - the interface of the Book class
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;
    int copies;

public:
    void setTitle(string t);
    void setAuthor(string a);
    bool setPrice(double p);
    bool setCopies(int c);

    string getTitle();
    string getAuthor();
    double getPrice();
    int getCopies();

    void show();
};

#endif
