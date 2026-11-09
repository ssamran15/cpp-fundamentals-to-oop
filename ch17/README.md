# Chapter 17: From Procedural to Object-Oriented Programming

Solutions to the Practice Programs of Chapter 17. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P17_1.cpp -o P17_1` (or press F11 in Dev-C++).

## P17.1: Rectangle, two versions

Define a structure `Rectangle` with length and width. Write separate functions to calculate the area and perimeter, passing the structure by `const` reference. Then write a second version in which `area()` and `perimeter()` are member functions of the structure.

**Solution:** [P17_1.cpp](P17_1.cpp)

**Sample run**

```
Length and width: 12.5 8
Version 1: area = 100, perimeter = 41
Version 2: area = 100, perimeter = 41
```

Both versions are in one file. The second structure is named `Rectangle2` so that the two can sit side by side; in a real program you would keep only the second one.

## P17.2: Adding fractions

Define a structure `Fraction` and a function `Fraction add(const Fraction &a, const Fraction &b)` that returns the sum of two fractions in lowest terms.

**Solution:** [P17_2.cpp](P17_2.cpp)

**Sample run**

```
First fraction (numerator denominator): 1 6
Second fraction (numerator denominator): 3 10
1/6 + 3/10 = 7/15
```

## P17.3: Student with member functions

Define a structure `Student` with a name, marks in 5 subjects, and member functions `total()`, `percentage()` and `grade()`. Create three students and display a result sheet.

**Solution:** [P17_3.cpp](P17_3.cpp)

**Output**

```
Name         Total       %   Grade
Ayesha         422   84.40       A
Bilal          327   65.40       B
Hamza          240   48.00       F
```

`percentage()` calls `total()`, and `grade()` calls `percentage()`: member functions can use one another. The grades are A (80+), B (65 to 79), C (50 to 64) and F.

## P17.4: Stock value

Define a structure `Product` with a member function `stockValue()` (quantity times price). Store 5 products in an array and display the total value of the stock.

**Solution:** [P17_4.cpp](P17_4.cpp)

**Output**

```
Soap           40 x  120.00 =    4800.00
Rice 1kg       25 x  380.00 =    9500.00
Tea 250g       18 x  650.00 =   11700.00
Sugar 1kg      30 x  160.00 =    4800.00
Oil 1L         12 x  590.00 =    7080.00
Total value of the stock: Rs. 37880.00
```

## P17.5: Thermometer class

Write a class `Thermometer` with a private temperature in Celsius and public functions `set` (which refuses values below -273.15), `getCelsius` and `getFahrenheit`.

**Solution:** [P17_5.cpp](P17_5.cpp)

**Sample run 1**

```
Enter a temperature in Celsius: 37
37 C = 98.6 F
```

**Sample run 2**

```
Enter a temperature in Celsius: -300
Refused: below absolute zero. Keeping 0 C
0 C = 32 F
```

`set` returns `false` when it refuses, so `main` can report it. `main` calls `set(0)` first so that the object always holds a valid value; Chapter 19 shows how a constructor does this automatically.

## P17.6: Tasbeeh counter

Write a class `Tasbeeh` (a digital counter) with a private count and public functions `press()`, `reset()` and `show()`. In `main`, press it a number of times entered by the user and display the count.

**Solution:** [P17_6.cpp](P17_6.cpp)

**Sample run**

```
How many times to press? 33
Count: 33
After reset, Count: 0
```

`reset()` is called before the first press, because a new object's `count` has no value of its own yet. Constructors (Chapter 19) will remove the need for this.

## P17.7: Ceiling fan

Write a class `CeilingFan` with a private speed (0 to 5) and public functions `faster()`, `slower()`, `turnOff()` and `show()`. The speed must never go below 0 or above 5.

**Solution:** [P17_7.cpp](P17_7.cpp)

**Output**

```
Fan is off
Fan speed: 5
Fan speed: 3
Fan is off
```

Because `speed` is private, the only way to change it is through the four functions, and each of them keeps it inside 0 to 5.

## P17.8: Attributes and behaviours

(Design exercise, no code) For each of these objects, list at least four attributes and four behaviours, and say which attributes should be private: a mobile phone, a library book, an ATM, a cricket player.

**Sample answer:** [P17.8.md](P17.8.md)
