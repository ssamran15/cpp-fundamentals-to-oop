# Chapter 19: Constructors and Destructors

Solutions to the Practice Programs of Chapter 19. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

Every program here was also checked with Valgrind: no memory leaks and no invalid memory use.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P19_1.cpp -o P19_1` (or press F11 in Dev-C++).

## P19.1: Fraction constructors

Write a class `Fraction` with a default constructor (giving 0/1) and a constructor with numerator and denominator that replaces a zero denominator with 1 and reduces the fraction to lowest terms. Add `show()`.

**Solution:** [P19_1.cpp](P19_1.cpp)

**Output**

```
Zero denominator replaced with 1
a = 0/1
b = 3/4
c = 2/5
d = 4/1
```

The first line of output comes from the constructor of `d`, which runs when `d` is declared, before anything is shown. The constructor also moves a negative sign from the denominator to the numerator, so -10/-25 becomes 2/5.

## P19.2: Complex constructors

Write a class `Complex` with overloaded constructors: no arguments (0 + 0i), one argument (real part only) and two arguments. Add a member function that returns the sum of two complex numbers.

**Solution:** [P19_2.cpp](P19_2.cpp)

**Output**

```
a = 0 + 0i
b = 4.5 + 0i
c = 3 - 2i
b + c = 7.5 - 2i
```

`add` builds its result with the two-argument constructor: `return Complex(re + c.re, im + c.im);`.

## P19.3: Date with default arguments

Write a class `Date` with one constructor that uses default arguments of 1, 1 and 2000, and validates the date (with leap years), using 1/1/2000 for an invalid date.

**Solution:** [P19_3.cpp](P19_3.cpp)

**Output**

```
d1: 1/1/2000
d2: 14/1/2000
d3: 14/8/2000
d4: 29/2/2024
d5: 1/1/2000
```

## P19.4: Array of books

Write a class `Book` whose constructor uses a member initializer list. Create an array of 3 books, giving each its values with `Book list[3] = { Book(...), Book(...), Book(...) };`, and display them.

**Solution:** [P19_4.cpp](P19_4.cpp)

**Output**

```
Computer Science Made Easy by Ahmad Raza, Rs. 950
Learning Databases by Hina Tariq, Rs. 1200
Networks for Beginners by Usman Ali, Rs. 780
```

`Book` has no default constructor, so an array such as `Book list[3];` without values would not compile. Each element must be given its values.

## P19.5: Constructor delegation

Write a class `Circle` in which `Circle()` delegates to `Circle(double r)` with a radius of 1. Display the area of both kinds of circle.

**Solution:** [P19_5.cpp](P19_5.cpp)

**Output**

```
Area of the default circle (r = 1): 3.14159
Area of a circle with r = 5: 78.5397
```

Only `Circle(double)` contains real code; it also replaces a radius of 0 or less with 1. `Circle()` simply passes 1 to it.

## P19.6: Stack with a dynamic array

Write a class `Stack` whose constructor receives the size and allocates a dynamic array, and whose destructor frees it. Provide `push`, `pop`, `isEmpty` and `isFull`.

**Solution:** [P19_6.cpp](P19_6.cpp)

**Output**

```
[stack of 4 created]
Pushed 10
Pushed 20
Pushed 30
Pushed 40
Stack full, 50 not pushed
Popping: 40 30 20 10
Empty now? yes
[stack freed]
```

The messages in square brackets come from the constructor and the destructor. The destructor runs by itself when `s` goes out of scope at the end of `main`. `Stack` objects must not be copied yet; Chapter 20 explains why.

## P19.7: Matrix with a dynamic 2D array

Write a class `Matrix` whose constructor receives the number of rows and columns and allocates a dynamic 2D array (Section 14.9), and whose destructor frees it correctly. Provide functions to input and display the matrix.

**Solution:** [P19_7.cpp](P19_7.cpp)

**Sample run**

```
Rows and columns: 3 4
Enter a 3 x 4 matrix:
1 2 3 4
5 6 7 8
9 10 11 12
The matrix:
    1    2    3    4
    5    6    7    8
    9   10   11   12
```

## P19.8: Tracer

Write a class `Tracer` whose constructor and destructor print a message with an id number. Use it to show what happens to objects declared inside a `for` loop body, inside a function called twice, and with `new` and `delete`.

**Solution:** [P19_8.cpp](P19_8.cpp)

**Output**

```
1. Inside a for loop body:
  Tracer 1 created
  (loop body 1)
  Tracer 1 destroyed
  Tracer 2 created
  (loop body 2)
  Tracer 2 destroyed
2. Inside a function called twice:
 work(10) starts
  Tracer 10 created
 work(10) ends
  Tracer 10 destroyed
 work(20) starts
  Tracer 20 created
 work(20) ends
  Tracer 20 destroyed
3. With new and delete:
  Tracer 99 created
  (p is in use)
  Tracer 99 destroyed
4. A local object of main:
  Tracer 100 created
End of main
  Tracer 100 destroyed
```

An object declared in a loop body is created and destroyed on every pass. A function's local object lives only while that call runs. An object made with `new` lives until `delete`. Tracer 100, a local of `main`, is destroyed after "End of main", when `main` returns.
