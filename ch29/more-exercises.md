# Chapter 29: Multiple Inheritance, Class Relationships and UML

## More Exercises

These exercises continue the Exercises section of Chapter 29 in the book. The book has Q1 to Q7; the numbering continues here.

### Determine the output

**Q8.**

```cpp
#include <iostream>
using namespace std;
class Battery
{
public:
    int level() const { return 80; }
};
class Tank
{
public:
    int level() const { return 35; }
};
class HybridCar : public Battery, public Tank
{
public:
    int range() const { return Battery::level() * 2 + Tank::level() * 10; }
};
int main()
{
    HybridCar h;
    cout << h.Battery::level() << " " << h.Tank::level() << " " << h.range() << endl;
    return 0;
}
```

**Q9.**

```cpp
#include <iostream>
using namespace std;
class Base
{
public:
    static int made;
    Base() { made++; }
};
int Base::made = 0;
class Left : virtual public Base { };
class Right : virtual public Base { };
class Bottom : public Left, public Right { };
int main()
{
    Bottom b1, b2;
    cout << Base::made << endl;
    return 0;
}
```

**Q10.**

```cpp
#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
    string name;
    Player(string n) : name(n) {}
    ~Player() { cout << "~" << name << " "; }
};
class Team
{
private:
    Player *members[2];
public:
    Team(Player *a, Player *b) { members[0] = a; members[1] = b; }
    ~Team() { cout << "~Team "; }
};
int main()
{
    Player x("Ali"), y("Sana");
    {
        Team t(&x, &y);
    }
    cout << "| ";
    return 0;
}
```

**Q11.**

```cpp
#include <iostream>
using namespace std;
class Wheel
{
public:
    Wheel() { cout << "W"; }
    ~Wheel() { cout << "w"; }
};
class Cycle
{
private:
    Wheel front, back;
public:
    Cycle() { cout << "C"; }
    ~Cycle() { cout << "c"; }
};
int main()
{
    {
        Cycle c;
    }
    cout << endl;
    return 0;
}
```

### Find the error

**Q12.**

```cpp
#include <iostream>
using namespace std;
class Animal
{
public:
    int legs = 4;
};
class Horse : public Animal { };
class Donkey : public Animal { };
class Mule : public Horse, public Donkey { };
int main()
{
    Mule m;
    Animal *a = &m;
    cout << a->legs << endl;
    return 0;
}
```

**Q13.**

```cpp
#include <iostream>
using namespace std;
class Engine
{
public:
    void start() const { cout << "Started" << endl; }
};
class Car : public Engine, public Engine
{
};
int main()
{
    Car c;
    c.start();
    return 0;
}
```

**Q14.**

```cpp
#include <iostream>
#include <string>
using namespace std;
class Engine
{
private:
    int cc;
public:
    Engine(int c) : cc(c) {}
};
class Car
{
private:
    string model;
    Engine engine;
public:
    Car(string m, int c)
    {
        model = m;
        engine = Engine(c);
    }
};
int main()
{
    Car c("Sedan", 1300);
    return 0;
}
```
