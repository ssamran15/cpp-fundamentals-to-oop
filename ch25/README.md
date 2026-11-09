# Chapter 25: Friend Functions and Stream Operators

Solutions to the Practice Programs of Chapter 25. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P25_1.cpp -o P25_1` (or press F11 in Dev-C++).

## P25.1: Friend of two distance classes

Write two classes `DistanceMetric` (metres and centimetres) and `DistanceBritish` (feet and inches). Write a friend function of both classes that adds one distance of each kind and prints the result in metres and centimetres (1 foot = 0.3048 m).

**Solution:** [P25_1.cpp](P25_1.cpp)

**Output**

```
3 m 40 cm + 5 ft 6 in = 5 m 8 cm
0 m 75 cm + 10 ft 0 in = 3 m 80 cm
```

`class DistanceBritish;` at the top lets `DistanceMetric` name the other class in its friend declaration before that class is defined. The result is rounded to the nearest centimetre.

## P25.2: canAfford

Write a class `Product` (name, price) and a class `Customer` (name, budget). Write a friend function `canAfford()` of both classes that tells whether the customer can buy the product and, if so, how much money will be left.

**Solution:** [P25_2.cpp](P25_2.cpp)

**Output**

```
Ali and the mobile phone (Rs. 45000): cannot buy it, short by Rs. 15000
Ali and the school bag (Rs. 2500): can buy it, Rs. 27500 left
Sana and the mobile phone (Rs. 45000): can buy it, Rs. 7000 left
```

## P25.3: A member function as a friend

Write classes `Marks` (student name, marks in five subjects, grade) and `Examiner`. Make only the member function `Examiner::assignGrade(Marks &m)` a friend of `Marks`; it calculates the percentage and stores the grade.

**Solution:** [P25_3.cpp](P25_3.cpp)

**Output**

```
Before grading:
Ayesha: grade -
Hamza: grade -
Examiner: Ayesha has 84.4%
Examiner: Hamza has 48%
After grading:
Ayesha: grade A
Hamza: grade F
```

`Examiner` must be defined before `Marks`, because `Marks` names one of its member functions. `Examiner` in turn needs only the declaration `class Marks;`, and its function is defined after both classes.

## P25.4: Inspector friend class

Write a class `Bus` with a route, number of seats and number of passengers, and a friend class `Inspector` whose member function `check()` receives an array of buses, prints each bus and reports the overloaded ones.

**Solution:** [P25_4.cpp](P25_4.cpp)

**Output**

```
Okara - Lahore: 52 passengers, 45 seats  OVERLOADED by 7
Okara - Sahiwal: 40 passengers, 45 seats
Okara - Faisalabad: 30 passengers, 30 seats
Okara - Depalpur: 37 passengers, 30 seats  OVERLOADED by 7
2 of 4 buses are overloaded
```

The routes and figures are examples.

## P25.5: Complex with friend operators

Write a class `Complex` with friend operators `+`, `-` and `*`, and with `<<` and `>>`. `>>` reads the real and imaginary parts separated by a space, and `<<` prints the number in the form `3 + 4i` or `1 - 2i`.

**Solution:** [P25_5.cpp](P25_5.cpp)

**Sample run**

```
First complex number (real imaginary): 3 4
Second complex number (real imaginary): 1 -2
a = 3 + 4i, b = 1 - 2i
a + b = 4 + 2i
a - b = 2 + 6i
a * b = 11 - 2i
a + 5 = 8 + 4i
5 + a = 8 + 4i
```

Because `+` is a friend and not a member, `5 + a` works as well as `a + 5`: the constructor turns 5 into `Complex(5, 0)` on either side (Section 25.6.1).

## P25.6: Date stream operators

Write a class `Date` with `>>` that reads a date typed as `dd/mm/yyyy` (setting the fail state if the separators or values are wrong), `<<` that prints it as `15 Mar 2026` using an array of month names, and the comparison operators `==` and `<` as friends. Read two dates and print the earlier one.

**Solution:** [P25_6.cpp](P25_6.cpp)

**Sample run 1**

```
Enter two dates (dd/mm/yyyy dd/mm/yyyy): 15/03/2026 02/11/2025
The earlier date is 2 Nov 2025
```

**Sample run 2**

```
Enter two dates (dd/mm/yyyy dd/mm/yyyy): 15/03/2026 15-03-2026
Invalid date entered.
```

The day check is simple (1 to 31); a full check would use the days in each month, as in P19.3.

## P25.7: v * 3 and 3 * v

Write a class `Vector2D` with a member `operator*(double)` and a friend `operator*(double, const Vector2D &)`, so that both `v * 3` and `3 * v` work. Add `<<` to print the vector as `(x, y)`.

**Solution:** [P25_7.cpp](P25_7.cpp)

**Output**

```
v     = (2, -1.5)
v * 3 = (6, -4.5)
3 * v = (6, -4.5)
0.5 * v * 4 = (4, -3)
```

A member operator always has the object on its left, so `3 * v` needs a non-member. The friend simply calls the member version with the order swapped.

## P25.8: Student records

Write a class `Student` (name of one word, roll number, marks) with `>>` and `<<`. Read the records of five students into an array using `>>` and print them as a table using `<<`, followed by the name of the topper.

**Solution:** [P25_8.cpp](P25_8.cpp)

**Sample run**

```
Enter name, roll number and marks of 5 students:
Ayesha 101 78
Bilal 102 64
Fatima 103 91
Hamza 104 55
Sana 105 83

Name        Roll  Marks
Ayesha       101     78
Bilal        102     64
Fatima       103     91
Hamza        104     55
Sana         105     83
Topper: Fatima
```
