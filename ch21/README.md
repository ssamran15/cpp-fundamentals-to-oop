# Chapter 21: const and static Members

Solutions to the Practice Programs of Chapter 21. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P21_1.cpp -o P21_1` (or press F11 in Dev-C++).

## P21.1: const member functions

Write a class `Circle` with `const` member functions `area`, `circumference` and `getRadius`. Write a non-member function `void printCircle(const Circle &c)` and use it with an ordinary object and a `const` object.

**Solution:** [P21_1.cpp](P21_1.cpp)

**Output**

```
Radius 5: area 78.5397, circumference 31.4159
Radius 2.5: area 19.6349, circumference 15.708
Radius 7: area 153.938, circumference 43.9823
```

`printCircle` works for both objects because it calls only `const` member functions. Removing the `//` before `fixed.setRadius(7);` gives a compile error, since `setRadius` may change the object.

## P21.2: Automatic employee IDs

Write a class `Employee` whose `const` employee ID is assigned automatically from a static counter starting at 1001, so that every new employee gets the next number.

**Solution:** [P21_2.cpp](P21_2.cpp)

**Output**

```
ID 1001: Asad Mehmood
ID 1002: Rabia Saleem
ID 1003: Imran Haider
```

`id(nextId++)` gives the new employee the current value and then moves the counter on. A `const` member can be set only in the initializer list.

## P21.3: const Date

Write a class `Date` with `const` member functions `isLeapYear()`, `daysInMonth()` and `show()`. Declare `const Date independenceDay(14, 8, 1947);` and display it with the number of days in its month.

**Solution:** [P21_3.cpp](P21_3.cpp)

**Output**

```
Independence Day: 14/8/1947
Days in that month: 31
Leap year? no
```

## P21.4: Static tax rate

Write a class `Product` with a static tax rate and a static function `setTaxRate`. Display the price with tax for three products, change the tax rate once, and display them again.

**Solution:** [P21_4.cpp](P21_4.cpp)

**Output**

```
Tax rate 17.00%
Soap        Rs.   120.00  with tax Rs.   140.40
Tea 250g    Rs.   650.00  with tax Rs.   760.50
Oil 1L      Rs.   590.00  with tax Rs.   690.30

Tax rate 18.00%
Soap        Rs.   120.00  with tax Rs.   141.60
Tea 250g    Rs.   650.00  with tax Rs.   767.00
Oil 1L      Rs.   590.00  with tax Rs.   696.20
```

The tax rates of 17% and 18% are example figures for practice.

## P21.5: Counting cars

Write a class `Car` that uses a static data member to count how many `Car` objects currently exist, and a static member function `showCount()`. Create cars in `main`, inside a block and with `new`, and show the count after each step.

**Solution:** [P21_5.cpp](P21_5.cpp)

**Output**

```
Cars now: 0
After creating a and b: Cars now: 2
Inside the block: Cars now: 3
After the block: Cars now: 2
After new: Cars now: 3
After delete: Cars now: 2
```

The constructor adds 1 and the destructor takes 1 away, so `count` always equals the number of cars alive. A full version would also add 1 in a copy constructor; this program never copies a car.

## P21.6: Static converter

Write a class `Converter` that has only static member functions: `celsiusToFahrenheit`, `fahrenheitToCelsius`, `kmToMiles` and `milesToKm`. Use them without creating any object.

**Solution:** [P21_6.cpp](P21_6.cpp)

**Output**

```
37 C = 98.6 F
212 F = 100 C
130 km = 80.7782 miles
26.2 miles = 42.1648 km
```

## P21.7: Class average

Write a class `Student` with a `const` roll number, and static members holding the number of students and the total of their marks, with a static function that returns the class average.

**Solution:** [P21_7.cpp](P21_7.cpp)

**Output**

```
101  Ayesha  78
102  Bilal  64
103  Fatima  91
104  Hamza  55
Students: 4
Class average: 72
```

## P21.8: Token machine

Write a function `int nextToken()` that uses a static local variable to return 1, 2, 3, ... on successive calls, as a bank's token machine would. Then rewrite it as a class `TokenMachine` with a static data member.

**Solution:** [P21_8.cpp](P21_8.cpp)

**Output**

```
Function version: 1 2 3 4 
Class version:    1 2 3 4 
After reset:      1
```

Both versions remember the last token between calls. The class version can also offer `reset()`, which the function version cannot, because no other code can reach its static local variable.
