# Chapter 18: Classes and Objects

Solutions to the Practice Programs of Chapter 18. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P18_1.cpp -o P18_1` (or press F11 in Dev-C++).

## P18.1: Book class

Write a class `Book` with title, author, price and number of copies. Provide setters that refuse a price of zero or less and a negative number of copies, getters for all members, and a `show()` function.

**Solution:** [P18_1.cpp](P18_1.cpp)

**Output**

```
Computer Science Made Easy by Ahmad Raza, Rs. 950, 40 copies
Price -200 refused
Copies -5 refused
Using the getters: Computer Science Made Easy / Ahmad Raza / Rs. 875 / 40 copies
```

The setters for price and copies return `false` when they refuse a value, and the old value is kept.

## P18.2: Date class

Write a class `Date` with day, month and year. The function `setDate` must reject invalid dates, taking leap years into account. Display the date as dd/mm/yyyy.

**Solution:** [P18_2.cpp](P18_2.cpp)

**Sample run**

```
Enter day month year: 29 2 2024
Date set: 29/02/2024
Enter day month year: 29 2 2026
Invalid date, not accepted
Enter day month year: 31 4 2026
Invalid date, not accepted
```

`isLeap` and `daysInMonth` are private: they are helpers for `setDate`, not part of the class's interface. A leap year is divisible by 4 but not by 100, unless it is also divisible by 400.

## P18.3: BankAccount class

Write a class `BankAccount` with an account number (with a getter but no setter after it is first set), a title and a balance. Provide `deposit`, `withdraw` and a count of transactions made.

**Solution:** [P18_3.cpp](P18_3.cpp)

**Output**

```
Account 50231 (Bilal Ahmed): Rs. 20000, 0 transaction(s)
Withdrawal of 50000 refused
Account 50231 (Bilal Ahmed): Rs. 23500, 3 transaction(s)
Account number from the getter: 50231
```

The account number is set only by `open()`. Constructors (Chapter 19) and `const` members (Chapter 21) will give a cleaner way to fix a value once.

## P18.4: Distance class

Write a class `Distance` with feet and inches. The setter must convert inches of 12 or more into feet. Add a member function `add(Distance &d)` that adds another distance to this one.

**Solution:** [P18_4.cpp](P18_4.cpp)

**Sample run**

```
First distance (feet inches): 5 14
Stored as 6' 2"
Second distance (feet inches): 3 11
Stored as 3' 11"
Sum: 10' 1"
```

`add` can read `d.feet` and `d.inches` even though they are private, because it is a member function of the same class.

## P18.5: Result class

Write a class `Result` that stores the marks of a student in 5 subjects and has member functions for the highest, lowest and average marks and the grade. Define all member functions outside the class.

**Solution:** [P18_5.cpp](P18_5.cpp)

**Sample run**

```
Enter marks in 5 subjects: 78 85 64 91 70
Highest: 91
Lowest: 64
Average: 77.6
Grade: B
```

## P18.6: Cylinder with inline functions

Write a class `Cylinder` with radius and height, with short inline member functions for the volume and the surface area.

**Solution:** [P18_6.cpp](P18_6.cpp)

**Sample run**

```
Radius and height: 3.5 10
Volume = 384.845
Surface area = 296.88
```

## P18.7: Book in separate files

Split the `Book` class of P18.1 into `Book.h`, `Book.cpp` and `main.cpp`, and build it as a Dev-C++ project.

**Solution:** [P18_7/Book.h](P18_7/Book.h), [P18_7/Book.cpp](P18_7/Book.cpp), [P18_7/main.cpp](P18_7/main.cpp)

**Output**

```
Computer Science Made Easy by Ahmad Raza, Rs. 950, 40 copies
Price 0 refused
Price is still Rs. 950
```

In Dev-C++, create a Console Application project and add the three files, as in Section 18.8. From the Command Prompt: `g++ main.cpp Book.cpp -o book`.

## P18.8: Electricity bill

Write a class `ElectricityBill` that stores the units consumed and calculates the bill using these rates (example rates for practice, not an actual tariff): the first 100 units at Rs. 10 per unit, the next 100 units at Rs. 15, and every unit above 200 at Rs. 20.

**Solution:** [P18_8.cpp](P18_8.cpp)

**Sample run 1**

```
Units consumed: 80
Bill for 80 units: Rs. 800.00
```

**Sample run 2**

```
Units consumed: 175
Bill for 175 units: Rs. 2125.00
```

**Sample run 3**

```
Units consumed: 340
Bill for 340 units: Rs. 5300.00
```

For 340 units: 100 x 10 + 100 x 15 + 140 x 20 = 1000 + 1500 + 2800 = Rs. 5300.
