# Chapter 26: Inheritance

Solutions to the Practice Programs of Chapter 26. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P26_1.cpp -o P26_1` (or press F11 in Dev-C++).

## P26.1: Shapes

Write a base class `Shape` with a name, and derived classes `Rectangle` (length, width) and `Circle` (radius). Each derived class has functions `area()`, `perimeter()` and `show()`. Create one object of each and display its details.

**Solution:** [P26_1.cpp](P26_1.cpp)

**Output**

```
Rectangle 12 x 7.5: area 90, perimeter 39
Circle of radius 4: area 50.2654, perimeter 25.1327
```

`name` is `protected`, so the derived classes can use it directly, while code outside the classes still cannot.

## P26.2: TextBook

Write a class `Book` (title, author, price) and a derived class `TextBook` that adds the subject and the class for which it is prescribed. `TextBook::show()` should call `Book::show()` and then print its own members.

**Solution:** [P26_2.cpp](P26_2.cpp)

**Output**

```
Title: Computer Science Made Easy
Author: Ahmad Raza
Price: Rs. 950
Subject: Computer Science
Prescribed for: BS 1st semester
```

## P26.3: Car and Truck

Write a class `Vehicle` (registration number, company, model year) and derived classes `Car` (number of seats) and `Truck` (load capacity in tons). Use constructors with arguments in all classes.

**Solution:** [P26_3.cpp](P26_3.cpp)

**Output**

```
Car: OKR-2471, Okara Motors, model 2022, 5 seats
Truck: LHR-8820, Valley Haulage, model 2019, load 12.5 tons
```

Each derived constructor passes the first three values to `Vehicle` in its initializer list. The company names and registration numbers are made up.

## P26.4: Salary slips

Write a class `Employee` (name, basic pay) and derived classes `Lecturer`, paid Rs. 1500 for each extra lecture, and `Clerk`, paid Rs. 400 for each overtime hour (practice rates). Each overrides `salary()` and has a `slip()` function. Print the slips of two lecturers and two clerks and the total salary bill.

**Solution:** [P26_4.cpp](P26_4.cpp)

**Output**

```
Lecturer Hina Tariq: basic 95000 + 6 extra lectures = Rs. 104000
Lecturer Usman Ali: basic 88000 + 0 extra lectures = Rs. 88000
Clerk Imran Haider: basic 42000 + 15 overtime hours = Rs. 48000
Clerk Asad Mehmood: basic 40000 + 8 overtime hours = Rs. 43200
Total salary bill: Rs. 283200
```

Each `salary()` starts from `Employee::salary()`, the base version, and adds its own extra pay.

## P26.5: Multilevel hierarchy

Write a multilevel hierarchy `Student` (name, roll number), `Undergraduate` (program, semester) and `FinalYearStudent` (project title, supervisor). Each constructor prints a message, and each `show()` calls the `show()` of its base class. Create a `FinalYearStudent` and display it.

**Solution:** [P26_5.cpp](P26_5.cpp)

**Output**

```
[Student constructor]
[Undergraduate constructor]
[FinalYearStudent constructor]

Name: Fatima Noor, roll 2207
Program: BS Computer Science, semester 8
Project: Smart Attendance System, supervised by Hina Tariq
```

The constructors run from the top of the hierarchy down: `Student` first, `FinalYearStudent` last. Each `show()` likewise prints its base part first.

## P26.6: SavingsAccount

Derive a class `SavingsAccount` from a class `Account`. Override `withdraw()` so that at most three withdrawals are allowed in a month and the balance never falls below Rs. 1000.

**Solution:** [P26_6.cpp](P26_6.cpp)

**Output**

```
This month:
Withdraw Rs. 2000
  done, balance Rs. 18000
Withdraw Rs. 3000
  done, balance Rs. 15000
Withdraw Rs. 1500
  done, balance Rs. 13500
Withdraw Rs. 1000
  refused: 3 withdrawals already made this month
Next month:
Withdraw Rs. 13000
  refused: balance would fall below Rs. 1000
Withdraw Rs. 12000
  done, balance Rs. 1500
```

The fourth withdrawal is refused by the monthly limit. After `newMonth()`, Rs. 13000 is refused because it would leave only Rs. 500, while Rs. 12000 leaves exactly Rs. 1500. The overriding `withdraw` does its own checks and then calls `Account::withdraw` for the real work.

## P26.7: 12-hour clock

Write a class `Time` (hours, minutes) with `show()` printing 24-hour time such as `14:05`, and a derived class `ClockTime` that overrides `show()` to print `2:05 PM`.

**Solution:** [P26_7.cpp](P26_7.cpp)

**Output**

```
14:05  ->  2:05 PM
00:30  ->  12:30 AM
09:45  ->  9:45 AM
12:00  ->  12:00 PM
23:59  ->  11:59 PM
```

Midnight (0:30) becomes 12:30 AM and noon (12:00) becomes 12:00 PM.

## P26.8: Grocery bill

Write a class `Product` (name, price) with `finalPrice()` and `show()`, and a derived class `PerishableProduct` that adds the number of days to expiry and gives 30% off when fewer than 3 days are left. Make a small grocery bill.

**Solution:** [P26_8.cpp](P26_8.cpp)

**Output**

```
Rice 5kg             1850.00
Soap                  120.00
Milk 1L               154.00  (30% off, 2 day(s) left)
Bread                 150.00
Yogurt 1kg            210.00  (30% off, 1 day(s) left)
----------------------------
Total                2484.00
```

Each object is used by its own type here. Putting all the products in one array of `Product` pointers would call `Product::finalPrice()` for every item and lose the discount; Chapter 27 fixes this with `virtual` functions.
