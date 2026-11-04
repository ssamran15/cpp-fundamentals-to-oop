# Chapter 27: Polymorphism and Abstract Classes

Solutions to the Practice Programs of Chapter 27. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P27_1.cpp -o P27_1` (or press F11 in Dev-C++).

## P27.1: Fares

Write a class `Vehicle` with virtual functions `name()` and `fare(double km)`, and derived classes `Rickshaw` (Rs. 50 plus Rs. 30 per km), `Taxi` (Rs. 150 plus Rs. 55 per km) and `Bus` (Rs. 40 for up to 10 km, then Rs. 3 per extra km). These are practice rates. Read a distance and print the fare for each vehicle using an array of `Vehicle *`.

**Solution:** [P27_1.cpp](P27_1.cpp)

**Sample run**

```
Distance in km: 12.5
Rickshaw  Rs. 425.00
Taxi      Rs. 837.50
Bus       Rs. 47.50
```

## P27.2: Animal sounds

Write a class `Animal` with a virtual function `sound()` and derived classes `Cow`, `Goat` and `Cat`. Store one object of each in an array of `Animal *` and call `sound()` in a loop. Then call a function that receives an `Animal` **by value** and explain the result.

**Solution:** [P27_2.cpp](P27_2.cpp)

**Output**

```
Through Animal pointers:
Cow: Moo
Goat: Baa
Cat: Meow
Passed by value:
(some sound)
(some sound)
Passed by reference:
Cow: Moo
Cat: Meow
```

Passed by value, the parameter `a` is a new `Animal` object made from only the `Animal` part of the cow or cat (object slicing). It really is an `Animal`, so `Animal::sound()` runs. Virtual functions work only through pointers and references, as the last two calls show.

## P27.3: Program 26.8 with a virtual show()

Rewrite Program 26.8 with `show()` made virtual. Show which of the three calls in that program now print the roll number, and which still do not.

**Solution:** [P27_3.cpp](P27_3.cpp)

**Output**

```
Library card -> Person: Ali Raza
Library card -> Student: Ayesha Khan, roll no 2417
Person: Ayesha Khan
Student: Ayesha Khan, roll no 2417
```

Calls 1 (`printCard(s)`, through a reference) and 3 (`ptr->show()`, through a pointer) now print the roll number. Call 2 (`copy.show()`) still does not: `copy` is a `Person` object made by slicing, so there is no roll number left to print.

## P27.4: Month-end processing

Write a class `Account` with a virtual function `monthEnd()` and derived classes `SavingsAccount` (adds profit), `CurrentAccount` (deducts a fixed service charge) and `StudentAccount` (no charge). Process an array of accounts at the end of the month and print all balances.

**Solution:** [P27_4.cpp](P27_4.cpp)

**Output**

```
Before month end:
Hina Tariq    Savings   Rs.  120000.00
Okara Traders Current   Rs.   85000.00
Usman Ali     Student   Rs.    4500.00
After month end:
Hina Tariq    Savings   Rs.  121200.00
Okara Traders Current   Rs.   84850.00
Usman Ali     Student   Rs.    4500.00
```

The profit rate (12% a year, added monthly) and the Rs. 150 service charge are practice figures. `StudentAccount` does not override `monthEnd()`, so it uses the empty base version.

## P27.5: Abstract Shape3D

Write an abstract class `Shape3D` with pure virtual functions `name()`, `volume()` and `surfaceArea()`, and concrete classes `Cube`, `Sphere` and `Cylinder`. Create the objects with `new` from values typed by the user, print their details through `Shape3D *` pointers, and delete them.

**Solution:** [P27_5.cpp](P27_5.cpp)

**Sample run**

```
Side of the cube: 3
Radius of the sphere: 2
Radius and height of the cylinder: 2 5

Cube: volume 27, surface area 54
Sphere: volume 33.5103, surface area 50.2654
Cylinder: volume 62.8318, surface area 87.9645
```

`4.0 / 3` is written with a `double` so that it gives 1.333... and not the integer 1.

## P27.6: Payment methods

Write an abstract class `Payment` with a pure virtual function `charges(double amount)` and concrete classes `CashPayment` (no charges), `CardPayment` (2% charges) and `WalletPayment` (Rs. 10 fixed charges), using practice rates. For a bill amount typed by the user, print the total payable by each method.

**Solution:** [P27_6.cpp](P27_6.cpp)

**Sample run**

```
Bill amount: Rs. 2500
Cash           charges Rs.    0.00   total Rs.   2500.00
Card           charges Rs.   50.00   total Rs.   2550.00
Mobile wallet  charges Rs.   10.00   total Rs.   2510.00
```

`total()` is an ordinary member function of the base class, but it calls the virtual `charges()`, so each method's own charges are used (Section 27.3.1).

## P27.7: Pay sheet

Write an abstract class `Employee` with a pure virtual function `pay()`, and concrete classes `Permanent` (monthly salary), `Visiting` (number of lectures times a rate) and `DailyWage` (days worked times a daily rate). Let the user choose the type of each of five employees, as in Program 27.8, and print a pay sheet.

**Solution:** [P27_7.cpp](P27_7.cpp)

**Sample run**

```
Types: 1 Permanent, 2 Visiting, 3 Daily wage
Employee 1 (name type): Hina 1
  Monthly salary: 95000
Employee 2 (name type): Usman 2
  Lectures and rate per lecture: 24 1500
Employee 3 (name type): Imran 3
  Days worked and daily rate: 26 1200
Employee 4 (name type): Sana 1
  Monthly salary: 88000
Employee 5 (name type): Bilal 2
  Lectures and rate per lecture: 16 1500

Pay sheet
Hina      Permanent   Rs.     95000
Usman     Visiting    Rs.     36000
Imran     Daily wage  Rs.     31200
Sana      Permanent   Rs.     88000
Bilal     Visiting    Rs.     24000
Total: Rs. 274200
```

## P27.8: Utility bills

Write an interface `UtilityBill` with pure virtual functions `company()` and `amount(int units)`, and classes `ElectricityBill`, `GasBill` and `WaterBill` with simple slab rates of your choice. Read the units for each and print the three bills and their total.

**Solution:** [P27_8.cpp](P27_8.cpp)

**Sample run**

```
Units used for City Electric Co.: 250
  Bill: Rs. 3900.00
Units used for City Gas Co.: 70
  Bill: Rs. 1700.00
Units used for City Water Board: 40
  Bill: Rs. 380.00
Total of the three bills: Rs. 5980.00
```

The company names and slab rates are made up. Electricity: Rs. 12 for the first 100 units, Rs. 18 for the next 200, Rs. 25 above 300. Gas: Rs. 20 for the first 50 units, Rs. 35 above. Water: Rs. 300 fixed plus Rs. 2 per unit.
