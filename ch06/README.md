# Chapter 6: Decision Making

Solutions to the Practice Programs of Chapter 6. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P6_1.cpp -o P6_1` (or press F11 in Dev-C++).

## P6.1: Positive, negative or zero

Input a number and display whether it is positive, negative or zero.

**Solution:** [P6_1.cpp](P6_1.cpp)

**Sample run 1**

```
Enter a number: -7
Negative
```

**Sample run 2**

```
Enter a number: 0
Zero
```

## P6.2: Eligible to vote

Input the age of a person and display whether he or she is eligible to vote (18 or above).

**Solution:** [P6_2.cpp](P6_2.cpp)

**Sample run 1**

```
Enter age: 21
Eligible to vote
```

**Sample run 2**

```
Enter age: 16
Not eligible to vote yet; 2 more year(s) to go
```

## P6.3: Larger of two numbers

Input two numbers and display the larger one. If both are equal, display a suitable message.

**Solution:** [P6_3.cpp](P6_3.cpp)

**Sample run 1**

```
Enter two numbers: 25 40
Larger number: 40
```

**Sample run 2**

```
Enter two numbers: 12 12
Both numbers are equal
```

## P6.4: Divisible by 3 and 5

Input a number and display whether it is divisible by both 3 and 5.

**Solution:** [P6_4.cpp](P6_4.cpp)

**Sample run 1**

```
Enter a number: 45
45 is divisible by both 3 and 5
```

**Sample run 2**

```
Enter a number: 20
20 is not divisible by both 3 and 5
```

## P6.5: Profit or loss

Input the cost price and sale price of an item. Display whether there is a profit or a loss, and how much.

**Solution:** [P6_5.cpp](P6_5.cpp)

**Sample run 1**

```
Cost price: Rs. 1200
Sale price: Rs. 1500
Profit of Rs. 300
```

**Sample run 2**

```
Cost price: Rs. 1200
Sale price: Rs. 950
Loss of Rs. 250
```

## P6.6: Electricity bill

Input the units of electricity consumed and calculate the bill: first 100 units at Rs. 20 per unit, next 100 units at Rs. 25, and every unit above 200 at Rs. 30.

**Solution:** [P6_6.cpp](P6_6.cpp)

**Sample run 1**

```
Units consumed: 150
Bill: Rs. 3250
```

**Sample run 2**

```
Units consumed: 260
Bill: Rs. 6300
```

## P6.7: Income tax

Input the monthly salary of an employee and calculate income tax: no tax up to Rs. 50,000; 5% on salary above Rs. 50,000 up to Rs. 100,000; and 10% on salary above Rs. 100,000.

**Solution:** [P6_7.cpp](P6_7.cpp)

**Sample run 1**

```
Monthly salary: Rs. 80000
Income tax: Rs. 1500
```

**Sample run 2**

```
Monthly salary: Rs. 130000
Income tax: Rs. 5500
```

Each rate applies only to the part of the salary in its slab. For Rs. 130,000 the tax is 5% of 50,000 plus 10% of 30,000. These are practice rates, not real tax rates.

## P6.8: Valid triangle

Input three sides of a triangle. First check that a triangle can be formed (the sum of any two sides must be greater than the third). If it can, display whether it is equilateral, isosceles or scalene.

**Solution:** [P6_8.cpp](P6_8.cpp)

**Sample run 1**

```
Enter three sides: 5 5 8
Isosceles triangle
```

**Sample run 2**

```
Enter three sides: 2 3 9
These sides cannot form a triangle
```

## P6.9: Type of character

Input a character and display whether it is an uppercase letter, a lowercase letter, a digit or a special character. Use ASCII ranges.

**Solution:** [P6_9.cpp](P6_9.cpp)

**Sample run 1**

```
Enter a character: G
Uppercase letter
```

**Sample run 2**

```
Enter a character: #
Special character
```

## P6.10: Nature of roots

Input the coefficients a, b and c of a quadratic equation. Using the discriminant b^2 - 4ac, display whether the roots are real and different, real and equal, or imaginary, and display the real roots.

**Solution:** [P6_10.cpp](P6_10.cpp)

**Sample run 1**

```
Enter a, b and c: 1 -5 6
Roots are real and different: 3 and 2
```

**Sample run 2**

```
Enter a, b and c: 1 -4 4
Roots are real and equal: 2
```

**Sample run 3**

```
Enter a, b and c: 1 2 5
Roots are imaginary
```

## P6.11: Pass in every subject

Input the marks of a student in three subjects. The student passes only if he or she gets at least 40 in every subject. Display "Pass" or "Fail".

**Solution:** [P6_11.cpp](P6_11.cpp)

**Sample run 1**

```
Enter marks of three subjects: 65 40 72
Pass
```

**Sample run 2**

```
Enter marks of three subjects: 90 35 88
Fail
```

## P6.12: Hot, pleasant or cold

Input a temperature and display "Hot" (above 35), "Pleasant" (25 to 35) or "Cold" (below 25).

**Solution:** [P6_12.cpp](P6_12.cpp)

**Sample run 1**

```
Temperature: 38
Hot
```

**Sample run 2**

```
Temperature: 30
Pleasant
```

## P6.13: Conditional operator

Using the conditional operator only, display the larger of two numbers and whether a number is even or odd.

**Solution:** [P6_13.cpp](P6_13.cpp)

**Sample run**

```
Enter two numbers: 14 9
Larger number: 14
Enter a number: 7
7 is odd
```

## P6.14: Month name

Input a month number (1 to 12) and display the month name.

**Solution:** [P6_14.cpp](P6_14.cpp)

**Sample run 1**

```
Month number (1-12): 8
August
```

**Sample run 2**

```
Month number (1-12): 13
Invalid month number
```

## P6.15: Toll plaza

Display a menu for a toll plaza: C for car (Rs. 150), B for bus (Rs. 300), T for truck (Rs. 500). Input the vehicle type and display the toll. Accept both uppercase and lowercase letters.

**Solution:** [P6_15.cpp](P6_15.cpp)

**Sample run**

```
C. Car   B. Bus   T. Truck
Vehicle type: b
Toll: Rs. 300
```

## P6.16: Area menu

Display a menu: 1. Area of circle  2. Area of rectangle  3. Area of triangle. Input the user's choice, take the required measurements, and display the area.

**Solution:** [P6_16.cpp](P6_16.cpp)

**Sample run**

```
1. Area of circle
2. Area of rectangle
3. Area of triangle
Your choice: 2
Length and width: 12 8
Area = 96
```

Each `case` that declares variables is put inside its own braces `{ }`.

## P6.17: Vowel or consonant with switch

Input a character and use `switch` with grouped cases to display whether it is a vowel or a consonant.

**Solution:** [P6_17.cpp](P6_17.cpp)

**Sample run 1**

```
Enter a letter: E
E is a vowel
```

**Sample run 2**

```
Enter a letter: k
k is a consonant
```
