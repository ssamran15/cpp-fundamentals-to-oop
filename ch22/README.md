# Chapter 22: Composition, Aggregation and Arrays of Objects

Solutions to the Practice Programs of Chapter 22. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P22_1.cpp -o P22_1` (or press F11 in Dev-C++).

## P22.1: Circle with a Point centre

Write a class `Point` and a class `Circle` that contains a `Point` centre and a radius. Add a member function `bool contains(const Point &p) const` that checks whether a point lies inside the circle.

**Solution:** [P22_1.cpp](P22_1.cpp)

**Output**

```
Circle with centre (2, 3) and radius 5
(2, 3) is inside
(5, 7) is inside
(6, 7) is outside
(-4, 3) is outside
```

A point is inside when its distance from the centre is at most the radius. Comparing squares, `dx * dx + dy * dy <= radius * radius`, avoids `sqrt`. The point (5, 7) is exactly 5 units from the centre, on the edge, and counts as inside.

## P22.2: Student with an Address

Write a class `Address` (house, street, city) and a class `Student` that contains an `Address` and a name. Write constructors that pass the address details through the initializer list, and display a student.

**Solution:** [P22_2.cpp](P22_2.cpp)

**Output**

```
Ali Raza: House 12-B, Canal Road, Okara
Sana Tariq: House 45, Mall Road, Lahore
```

`Address` has no default constructor, so `Student` must build its `address` member in the initializer list: `address(h, s, c)`.

## P22.3: Flight duration

Write a class `Time` and a class `Flight` that contains a departure time and an arrival time. Add a function that returns the duration of the flight in minutes.

**Solution:** [P22_3.cpp](P22_3.cpp)

**Output**

```
Flight FL-301: 09:45 to 11:20, 95 minutes
Flight FL-785: 22:30 to 01:15, 165 minutes
```

For a flight that lands after midnight, the arrival is earlier on the clock than the departure, so one day (1440 minutes) is added. The flight numbers are made up.

## P22.4: Order of construction

Write a class `Computer` composed of `Processor`, `Memory` and `Disk` objects, each of whose constructors and destructors print a message, and show the order of construction and destruction.

**Solution:** [P22_4.cpp](P22_4.cpp)

**Output**

```
Creating the computer:
  Processor built
  Memory built
  Disk built
  Computer ready
Using the computer...
  Computer shutting down
  Disk removed
  Memory removed
  Processor removed
Done
```

The parts are built first, in the order they are declared in the class, and then the `Computer` constructor runs. Destruction is the exact reverse: the `Computer` destructor runs first, then the parts from last to first.

## P22.5: A player in two teams

Write a class `Player` and a class `Team` that holds pointers to up to 11 players. Create players independently and add the same player to a club team and a national team.

**Solution:** [P22_5.cpp](P22_5.cpp)

**Output**

```
Okara Eagles (2 players):
  Hamza Ali, 75 runs
  Usman Raza, 32 runs
National XI (2 players):
  Hamza Ali, 75 runs
  Bilal Ahmed, 48 runs
```

This is aggregation: the teams only point to the players, which exist on their own in `main`. Runs added to Hamza Ali once appear in both teams, because both point to the same object.

## P22.6: Library of book pointers

Write a class `Library` that holds pointers to `Book` objects created in `main`, with functions to add a book, list all books and search for a book by title.

**Solution:** [P22_6.cpp](P22_6.cpp)

**Sample run 1**

```
Books in the library:
  Computer Science Made Easy by Ahmad Raza
  Learning Databases by Hina Tariq
  Networks for Beginners by Usman Ali
Title to search: Learning Databases
Found:
  Learning Databases by Hina Tariq
```

**Sample run 2**

```
Books in the library:
  Computer Science Made Easy by Ahmad Raza
  Learning Databases by Hina Tariq
  Networks for Beginners by Usman Ali
Title to search: Data Structures
Not found
```

`search` returns a pointer to the book, or `nullptr` if no book has that title. The library does not delete the books, because it does not own them.

## P22.7: Dynamic array of employees

Input the number of employees, create a dynamic array of `Employee` objects (name, basic pay, allowances), and display a pay sheet sorted by gross pay.

**Solution:** [P22_7.cpp](P22_7.cpp)

**Sample run**

```
Number of employees: 3
Employee 1
Name: Asad Mehmood
Basic pay and allowances: 45000 12000
Employee 2
Name: Rabia Saleem
Basic pay and allowances: 62000 15500
Employee 3
Name: Imran Haider
Basic pay and allowances: 38000 9000

Name                 Basic  Allowances     Gross
Rabia Saleem         62000       15500     77500
Asad Mehmood         45000       12000     57000
Imran Haider         38000        9000     47000
```

`new Employee[n]` needs a default constructor. Objects are swapped with `=`, which is safe here because `Employee` holds no pointers (its `string` member copies itself correctly).

## P22.8: Transcript and GPA

Write a class `Subject` (name, credit hours, grade points) and a class `Transcript` that contains an array of 5 `Subject` objects and calculates the GPA as the credit-weighted average of the grade points.

**Solution:** [P22_8.cpp](P22_8.cpp)

**Output**

```
Transcript of Ayesha Khan
Subject                         Cr      GP
Programming Fundamentals         4    3.67
Calculus                         3    3.00
Applied Physics                  3    2.67
English Composition              3    3.33
Islamic Studies                  2    4.00
GPA: 3.31
```

GPA = (3.67 x 4 + 3.00 x 3 + 2.67 x 3 + 3.33 x 3 + 4.00 x 2) / 15 = 49.67 / 15 = 3.31. The subjects and grade points are examples.
