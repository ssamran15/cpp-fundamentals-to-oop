// P18.7: Book.cpp - the implementation of the Book class
#include <iostream>
#include "Book.h"
using namespace std;

void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }

bool Book::setPrice(double p)
{
    if (p <= 0)
        return false;
    price = p;
    return true;
}

bool Book::setCopies(int c)
{
    if (c < 0)
        return false;
    copies = c;
    return true;
}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
double Book::getPrice() { return price; }
int Book::getCopies() { return copies; }

void Book::show()
{
    cout << title << " by " << author << ", Rs. " << price
         << ", " << copies << " copies" << endl;
}
