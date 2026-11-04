// P27.2: Virtual sound(), and what passing by value does
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual ~Animal() {}
    virtual void sound() const { cout << "(some sound)" << endl; }
};

class Cow : public Animal
{
public:
    void sound() const override { cout << "Cow: Moo" << endl; }
};

class Goat : public Animal
{
public:
    void sound() const override { cout << "Goat: Baa" << endl; }
};

class Cat : public Animal
{
public:
    void sound() const override { cout << "Cat: Meow" << endl; }
};

void byValue(Animal a)              // a copy of only the Animal part
{
    a.sound();
}

void byReference(const Animal &a)   // the real object
{
    a.sound();
}

int main()
{
    Cow cow;
    Goat goat;
    Cat cat;
    Animal *farm[3] = { &cow, &goat, &cat };

    cout << "Through Animal pointers:" << endl;
    for (int i = 0; i < 3; i++)
        farm[i]->sound();

    cout << "Passed by value:" << endl;
    byValue(cow);
    byValue(cat);

    cout << "Passed by reference:" << endl;
    byReference(cow);
    byReference(cat);
    return 0;
}
