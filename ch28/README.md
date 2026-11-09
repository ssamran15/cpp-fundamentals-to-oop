# Chapter 28: Virtual Tables and Run-Time Type Information

Solutions to the Practice Programs of Chapter 28. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P28_1.cpp -o P28_1` (or press F11 in Dev-C++).

## P28.1: Size of virtual functions

Write classes with no virtual function, one virtual function, and five virtual functions, each also having a `double` and an `int` data member. Print their sizes with `sizeof` and explain the results.

**Solution:** [P28_1.cpp](P28_1.cpp)

**Output**

```
sizeof(double) + sizeof(int) = 12
sizeof(void *)               = 8
No virtual function    : 16 bytes
One virtual function   : 24 bytes
Five virtual functions : 24 bytes
```

The `double` and `int` need 12 bytes, but the class takes 16 because it is padded to a multiple of 8, the size of a `double`. A class with any virtual function also holds one hidden pointer to its virtual table (8 bytes on a 64-bit system), so it grows to 24. Five virtual functions cost no more than one: there is still only one pointer per object, and the extra entries are in the single table shared by the whole class. The figures above are from 64-bit GCC; a 32-bit compiler gives smaller numbers.

## P28.2: Bonus for lecturers

Using the classes `Employee`, `Lecturer` and `Clerk` of Program 27.4, read a result bonus and add it to the salary of lecturers only, using `dynamic_cast` and a member function `giveBonus()` that exists only in `Lecturer`. Print all salaries.

**Solution:** [P28_2.cpp](P28_2.cpp)

**Sample run**

```
Result bonus for lecturers: Rs. 25000
Lecturer Hamza Ali: Rs. 138000
Clerk Imran: Rs. 50000
Lecturer Sana Tariq: Rs. 139000
Clerk Asad: Rs. 42000
```

The classes are those of Program 27.4, with a virtual destructor and `override` added and the `Principal` class left out. `dynamic_cast` gives `nullptr` for a clerk, so only lecturers receive the bonus.

## P28.3: Apps on smartphones

Write a class `Phone` and a derived class `SmartPhone` that has an extra function `installApp(string)`. In an array of `Phone *` holding both kinds, install an app on the smartphones only, and print a message for each ordinary phone instead.

**Solution:** [P28_3.cpp](P28_3.cpp)

**Output**

```
0300-1112223: installed Attendance (1 app(s) now)
0333-7778889: an ordinary phone, no apps
0321-4445556: installed Attendance (1 app(s) now)
0345-1212343: an ordinary phone, no apps
```

## P28.4: Counting shapes

Read a number of shapes from the user, each either a circle (`c radius`) or a rectangle (`r length width`), creating them with `new`. Count the shapes of each kind with `typeid`, and find the largest circle with `dynamic_cast`. Delete all the shapes at the end.

**Solution:** [P28_4.cpp](P28_4.cpp)

**Sample run**

```
Number of shapes: 5
Shape 1 (c radius / r length width): c 3
Shape 2 (c radius / r length width): r 4 6
Shape 3 (c radius / r length width): c 5.5
Shape 4 (c radius / r length width): r 2 9
Shape 5 (c radius / r length width): c 1
Circles: 3, rectangles: 2
Largest circle: radius 5.5, area 95.0331
```

`typeid(*shapes[i])` needs the `*`: `typeid(shapes[i])` would give the type of the pointer, `Shape *`, every time.

## P28.5: Library items

Write an abstract class `LibraryItem` with derived classes `Book` (pages), `Magazine` (issue number) and `CD` (minutes). Count the items of each kind with `typeid`, and print the total number of pages of all books using `dynamic_cast`.

**Solution:** [P28_5.cpp](P28_5.cpp)

**Output**

```
Book: Computer Science Made Easy, 420 pages
Magazine: Campus Science, issue 58
CD: Urdu Poetry Readings, 72 minutes
Book: Learning Databases, 365 pages
CD: C++ Video Lectures, 180 minutes
Book: Networks for Beginners, 290 pages

Books: 3, magazines: 1, CDs: 2
Total pages of all books: 1075
```

## P28.6: Patients

Write a class `Patient` with derived classes `IndoorPatient` (room number, days admitted) and `OutdoorPatient`. Each has a virtual `bill()`. Print all bills, then list the room numbers of indoor patients only.

**Solution:** [P28_6.cpp](P28_6.cpp)

**Output**

```
Bills:
  Rabia Saleem: Rs. 12500
  Nadia Akram: Rs. 800
  Kamran Yousaf: Rs. 23000
  Asad Mehmood: Rs. 800
Rooms of indoor patients:
  Rabia Saleem: room 204
  Kamran Yousaf: room 117
```

The rates (Rs. 2000 admission plus Rs. 3500 a day; Rs. 800 for an outdoor visit) are practice figures.

## P28.7: typeid chain or virtual function?

Write a program that describes each animal in an array of `Animal *` twice: first with an `if` chain using `typeid`, then with a virtual function `describe()`. Add a new class `Camel` and note which version needed changes.

**Solution:** [P28_7.cpp](P28_7.cpp)

**Output**

```
With typeid:
A cow gives milk.
A goat climbs rocks.
A camel crosses deserts.
With the virtual function:
A cow gives milk.
A goat climbs rocks.
A camel crosses deserts.
```

Adding `Camel` needed a change to `describeWithTypeid` (the extra `else if`, marked in the code), and the same would be true of every other `typeid` chain in a larger program. The virtual version needed no change at all: `Camel` only had to supply its own `describe()`. This is why virtual functions are usually preferred to `typeid` chains.

## P28.8: sameKind

Write a function `bool sameKind(const Shape &a, const Shape &b)` using `typeid`, and use it to compare pairs of shapes. Then explain why `dynamic_cast` could not be used to write the same function.

**Solution:** [P28_8.cpp](P28_8.cpp)

**Output**

```
c1 and c2: same kind
c1 and s1: different kinds
s1 and s1: same kind
```

`dynamic_cast` needs the target type written in the code, such as `dynamic_cast<const Circle *>(&a)`. It can answer "is this a Circle?" but not "is this the same type as that other object?", because the type of `b` is known only while the program runs. `sameKind` would need one test per class and would have to be changed for every new shape. `typeid` gives the actual type of each object, so two `typeid` results can be compared directly.
