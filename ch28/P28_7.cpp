// P28.7: Describing animals with typeid and with a virtual function
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal
{
public:
    virtual ~Animal() {}
    virtual void describe() const = 0;
};

class Cow : public Animal
{
public:
    void describe() const override { cout << "A cow gives milk." << endl; }
};

class Goat : public Animal
{
public:
    void describe() const override { cout << "A goat climbs rocks." << endl; }
};

class Camel : public Animal         // the class added later
{
public:
    void describe() const override { cout << "A camel crosses deserts." << endl; }
};

void describeWithTypeid(const Animal *a)
{
    if (typeid(*a) == typeid(Cow))
        cout << "A cow gives milk." << endl;
    else if (typeid(*a) == typeid(Goat))
        cout << "A goat climbs rocks." << endl;
    else if (typeid(*a) == typeid(Camel))           // this line had to be added for Camel
        cout << "A camel crosses deserts." << endl;
    else
        cout << "An unknown animal." << endl;
}

int main()
{
    Cow cow;
    Goat goat;
    Camel camel;
    Animal *animals[3] = { &cow, &goat, &camel };

    cout << "With typeid:" << endl;
    for (int i = 0; i < 3; i++)
        describeWithTypeid(animals[i]);

    cout << "With the virtual function:" << endl;
    for (int i = 0; i < 3; i++)
        animals[i]->describe();
    return 0;
}
