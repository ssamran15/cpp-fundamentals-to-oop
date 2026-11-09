# Chapter 4: Variables, Data Types and Input/Output

Solutions to the Practice Programs of Chapter 4. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P4_1.cpp -o P4_1` (or press F11 in Dev-C++).

## P4.1: Total and percentage

Input the marks of a student in five subjects. Display the total marks and the percentage (out of 500).

**Solution:** [P4_1.cpp](P4_1.cpp)

**Sample run**

```
Enter marks of five subjects: 72 85 64 90 78
Total marks: 389
Percentage : 77.8%
```

## P4.2: Total bill

Input the price of one item and the quantity bought. Display the total bill.

**Solution:** [P4_2.cpp](P4_2.cpp)

**Sample run**

```
Price of one item: 250
Quantity: 4
Total bill: Rs. 1000
```

## P4.3: Fahrenheit to Celsius

Input a temperature in Fahrenheit and display it in Celsius using C = (F - 32) x 5 / 9.

**Solution:** [P4_3.cpp](P4_3.cpp)

**Sample run**

```
Temperature in Fahrenheit: 98.6
Temperature in Celsius   : 37
```

## P4.4: Area of a triangle

Input the base and height of a triangle and display its area.

**Solution:** [P4_4.cpp](P4_4.cpp)

**Sample run**

```
Base and height: 10 7
Area of the triangle = 35
```

## P4.5: Swapping two numbers

Input two numbers in variables `a` and `b`, swap their values using a third variable, and display both values before and after swapping.

**Solution:** [P4_5.cpp](P4_5.cpp)

**Sample run**

```
Enter a and b: 5 9
Before swapping: a = 5, b = 9
After swapping : a = 9, b = 5
```

## P4.6: ASCII code

Input a character and display its ASCII code.

**Solution:** [P4_6.cpp](P4_6.cpp)

**Sample run**

```
Enter a character: A
ASCII code of A is 65
```

## P4.7: Next three letters

Input an uppercase letter and display the next three letters of the alphabet.

**Solution:** [P4_7.cpp](P4_7.cpp)

**Sample run**

```
Enter an uppercase letter: K
Next three letters: L M N
```

Adding 1 to a `char` gives the next character in the ASCII table. For X, Y or Z the result goes past Z; a later chapter shows how to wrap round with an `if`.

## P4.8: Sizes of data types

Display the size of `int`, `double` and `char` on your computer using `sizeof`.

**Solution:** [P4_8.cpp](P4_8.cpp)

**Output**

```
Size of int   : 4 bytes
Size of double: 8 bytes
Size of char  : 1 byte
```

These are the sizes with GCC (Dev-C++). `char` is always 1 byte; the others may differ on other compilers.

## P4.9: Circle with a constant

Input the radius of a circle and display its area and circumference. Store pi in a `const`.

**Solution:** [P4_9.cpp](P4_9.cpp)

**Sample run**

```
Radius: 7
Area          = 153.938
Circumference = 43.9823
```

## P4.10: GST amount

GST is 18%. Store it in a `const`, input the price of a product, and display the GST amount and the final price.

**Solution:** [P4_10.cpp](P4_10.cpp)

**Sample run**

```
Price of the product: Rs. 2500
GST (18%)  : Rs. 450
Final price: Rs. 2950
```

18% is the rate given in the problem, used here as a practice rate.

## P4.11: Grocery bill

Input the prices of three grocery items (sugar, rice and tea) and print them as a neat bill with the item names, using `setw`. Show prices with 2 decimal places.

**Solution:** [P4_11.cpp](P4_11.cpp)

**Sample run**

```
Price of sugar: 160
Price of rice : 345.5
Price of tea  : 1250

Item             Price
Sugar           160.00
Rice            345.50
Tea            1250.00
Total          1755.50
```

## P4.12: Salary slip

Input the basic salary of an employee. House rent is 45% and medical allowance is 10% of the basic salary. Print a salary slip with all values right-aligned in one column.

**Solution:** [P4_12.cpp](P4_12.cpp)

**Sample run**

```
Basic salary: 40000

        SALARY SLIP
Basic salary :     40000.00
House rent   :     18000.00
Medical      :      4000.00
Gross salary :     62000.00
```
