# Chapter 23: Operator Overloading I

Solutions to the Practice Programs of Chapter 23. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P23_1.cpp -o P23_1` (or press F11 in Dev-C++).

## P23.1: Complex operators

Write a class `Complex` with overloaded `+`, `-`, `*`, `==` and unary `-`. Test each operator.

**Solution:** [P23_1.cpp](P23_1.cpp)

**Output**

```
a     = 3 + 2i
b     = 1 - 4i
a + b = 4 - 2i
a - b = 2 + 6i
a * b = 11 - 10i
-a    = -3 - 2i
a == c? yes
a == b? no
```

(3 + 2i)(1 - 4i) = 3 - 12i + 2i - 8i^2 = 3 + 8 - 10i = 11 - 10i, since i^2 = -1. Unary `-` takes no parameter, which is how C++ tells it apart from subtraction.

## P23.2: Fraction operators

Write a class `Fraction` with overloaded `+`, `-`, `*`, `/`, `==` and `<`, keeping every result in lowest terms.

**Solution:** [P23_2.cpp](P23_2.cpp)

**Output**

```
1/2 + 3/4 = 5/4
1/2 - 3/4 = -1/4
1/2 * 3/4 = 3/8
1/2 / 3/4 = 2/3
1/2 == 2/4? yes
1/2 < 3/4? yes
3/4 < 1/2? no
```

Every result is built with the constructor, which calls `reduce()`, so all fractions stay in lowest terms. That is why `==` can simply compare numerators and denominators, and why 2/4 equals 1/2.

## P23.3: Time operators

Write a class `Time` (hours, minutes, seconds) with `+` (adding two times), `+=` (adding seconds) and `<`, and use `<` to find the earliest of five times.

**Solution:** [P23_3.cpp](P23_3.cpp)

**Output**

```
1:45:30 + 0:20:45 = 2:06:15
After b += 90: 0:22:15
Earliest of the five: 8:50:10
```

`+=` changes the object and returns `*this` by reference, like the built-in `+=`. `+` leaves both operands unchanged and returns a new `Time`.

## P23.4: 2 x 2 matrices

Write a class `Matrix2` for 2 x 2 matrices with `+`, `*` (matrix multiplication) and `==`.

**Solution:** [P23_4.cpp](P23_4.cpp)

**Output**

```
x + y:
  [6 8]
  [10 12]
x * y:
  [19 22]
  [43 50]
y * x:
  [23 34]
  [31 46]
x * y == y * x? no
x * identity == x? yes
```

The output shows that matrix multiplication is not commutative: x * y and y * x are different.

## P23.5: Date ++

Write a class `Date` with prefix and postfix `++` that move to the next day, rolling over into the next month and year, with leap years handled.

**Solution:** [P23_5.cpp](P23_5.cpp)

**Output**

```
Day after 28/2/2024: 29/2/2024
Next day: 1/3/2024
d2++ gave 31/12/2025, d2 is now 1/1/2026
Day after 28/2/2026: 1/3/2026
```

Postfix `++` keeps a copy of the old date, moves the object on with prefix `++`, and returns the copy. So `before = d2++` gives the old date while `d2` itself moves on.

## P23.6: Odometer ++

Write a class `Odometer` with a six-digit reading and prefix and postfix `++`; after 999999 the reading returns to 000000.

**Solution:** [P23_6.cpp](P23_6.cpp)

**Output**

```
999997 -> 999998
999998 -> 999999
999999 -> 000000
000000 -> 000001
After ++car: 000002
```

`% 1000000` brings 1000000 back to 0. `setfill('0')` and `setw(6)` print the reading with leading zeros; the fill character is put back to a space afterwards.

## P23.7: MyString operators

Write a class `MyString` that stores text in a dynamic `char` array, with a constructor, copy constructor, destructor, `operator=`, `operator+` (joining two strings), `operator+=` and `operator==`.

**Solution:** [P23_7.cpp](P23_7.cpp)

**Output**

```
first + second: Govt. Graduate College
After += place: Govt. Graduate College, Okara
copy:           Govt. Graduate College, Okara
copy == name? yes
copy == first? no
After copy = copy: Govt. Graduate College, Okara
```

`operator=` follows the four steps of Program 23.6: check for self-assignment, free the old memory, allocate and copy, return `*this`. `+=` is written using `+` and `=`.

## P23.8: Complete Stack

Write a class `Stack` with a dynamic array and complete it with a copy constructor, `operator=` and destructor. Show that after `s2 = s1;`, pushing onto `s2` does not change `s1`.

**Solution:** [P23_8.cpp](P23_8.cpp)

**Output**

```
s1: [ 10 20 30 ]  (top on the right)
s2: [ 10 20 30 40 50 ]  (top on the right)
Popped 30 from s1
s1: [ 10 20 ]  (top on the right)
s2: [ 10 20 30 40 50 ]  (top on the right)
s3 (copy of s2): [ 10 20 30 40 50 ]  (top on the right)
```

`s2` started with room for 3, but after `s2 = s1` it has s1's size of 5 and its own copy of the items, so it can take two more. This class now follows the Rule of Three.
