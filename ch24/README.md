# Chapter 24: Operator Overloading II and Type Conversion

Solutions to the Practice Programs of Chapter 24. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P24_1.cpp -o P24_1` (or press F11 in Dev-C++).

## P24.1: Matrix with operator()

Write a class `Matrix` with a dynamic 2D array of a size given to the constructor, and `operator()(int r, int c)` in `const` and non-`const` versions, with bounds checking. Add a copy constructor, `operator=` and destructor.

**Solution:** [P24_1.cpp](P24_1.cpp)

**Output**

```
a:
   10   11   12
   20   21   22
[index (5, 1) out of range]
a after changing b and c:
   10   11   12
   20   21   22
b:
   -1   11   12
   20   21   22
c:
   10   11   12
   20   21  500
```

The non-`const` version returns `int &`, so `a(i, j) = ...` can change an element. The `const` version returns a copy and is the one used inside `show`, which receives a `const Matrix &`. A bad index prints a message and returns a dummy element, so nothing outside the array is touched; Chapter 33 shows how an exception does this better.

## P24.2: Polynomial

Write a class `Polynomial` that stores up to 10 coefficients. Use `operator[]` to set and get coefficients, and `operator()` to evaluate the polynomial at a given `x`.

**Solution:** [P24_2.cpp](P24_2.cpp)

**Output**

```
[power 12 not allowed]
p(x) = 3x^2 + 2x + 5
Coefficient of x: 2
p(0) = 5
p(1) = 10
p(2) = 21
p(3) = 38
```

`operator()` uses Horner's method: 3x^2 + 2x + 5 is worked out as (3x + 2)x + 5, which needs no powers.

## P24.3: Register

Write a class `Register` that holds the names of up to 50 students. Overload `[]` to return the name at a position, with bounds checking, in `const` and non-`const` versions, and use it to print the register.

**Solution:** [P24_3.cpp](P24_3.cpp)

**Output**

```
1. Ayesha Khan
2. Bilal Ahmed
3. Fatima Noor
4. Hamza Ali
After the correction, position 1: Bilal Ahmad
[no student at position 9]
Position 9 gave ""
```

Positions start at 0 inside the class, as in an array; `print` shows them from 1 for the reader.

## P24.4: Discount function object

Write a class `Discount` whose constructor receives a percentage and whose `operator()` returns a price after the discount. Apply an "Eid sale" discount to an array of prices.

**Solution:** [P24_4.cpp](P24_4.cpp)

**Output**

```
Eid sale, 30% off
Rs.  2500.00  ->  Rs.  1750.00
Rs.  1800.00  ->  Rs.  1260.00
Rs.  4200.00  ->  Rs.  2940.00
Rs.   950.00  ->  Rs.   665.00
Rs.  6000.00  ->  Rs.  4200.00
```

`eidSale(prices[i])` looks like a function call, but `eidSale` is an object that remembers its own percentage. The 30% figure is an example.

## P24.5: Time conversions

Write a class `Time` with an `explicit` conversion constructor from an `int` number of seconds and a conversion operator to `int` that returns the total seconds. Use them to find the difference between two times.

**Solution:** [P24_5.cpp](P24_5.cpp)

**Output**

```
From 8h 45m 20s to 11h 10m 5s
Difference: 8685 seconds = 2h 24m 45s
```

`finish - start` works because both `Time` objects convert to `int`. Going back needs `Time gap(difference);`, written out, because the constructor is `explicit`.

## P24.6: Kilogram and Pound

Write classes `Kilogram` and `Pound` (1 kg = 2.20462 lb) with conversion in both directions, one by a constructor and the other by a conversion operator.

**Solution:** [P24_6.cpp](P24_6.cpp)

**Output**

```
5 kg = 11.0231 lb
22 lb = 9.97904 kg
```

Both conversions live in `Pound`: the constructor `Pound(const Kilogram &)` turns kilograms into pounds, and `operator Kilogram()` turns pounds into kilograms. Putting both in one class avoids defining the same conversion twice, which would make the compiler report an ambiguity.

## P24.7: Money with explicit operator bool

Write a class `Money` with an `explicit` constructor from `double` and an `explicit operator bool()` that is true when the amount is greater than zero. Use it in an `if` and a `while` loop.

**Solution:** [P24_7.cpp](P24_7.cpp)

**Output**

```
The wallet has Rs. 1000
The second wallet is empty
Day 1: Rs. 700 left
Day 2: Rs. 400 left
Day 3: Rs. 100 left
Day 4: Rs. 0 left
Out of money after 4 days
```

An `explicit operator bool()` is still used automatically in conditions (`if`, `while`, `!`), but not in other places, so `int x = wallet;` is rejected. The stream classes use the same idea (Chapter 30).

## P24.8: Percentage

Write a class `Percentage` that stores a value from 0 to 100, with a conversion constructor from `double` (clamping values outside the range) and a conversion operator to `double` that returns the value as a fraction (for example 0.75 for 75%).

**Solution:** [P24_8.cpp](P24_8.cpp)

**Output**

```
75% as a fraction: 0.75
100% as a fraction: 1
0% as a fraction: 0
A 40% scholarship on Rs. 48000 is Rs. 19200
```

In `fee * scholarship`, the `Percentage` is converted to 0.40 automatically. The fee and scholarship figures are examples.
