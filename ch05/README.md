# Chapter 5: Operators and Expressions

Solutions to the Practice Programs of Chapter 5. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P5_1.cpp -o P5_1` (or press F11 in Dev-C++).

## P5.1: Five arithmetic results

Input two integers and display their sum, difference, product, quotient and remainder.

**Solution:** [P5_1.cpp](P5_1.cpp)

**Sample run**

```
Enter two integers: 17 5
17 + 5 = 22
17 - 5 = 12
17 * 5 = 85
17 / 5 = 3
17 % 5 = 2
```

The second number must not be 0. Checking it needs an `if` statement, which comes in Chapter 6.

## P5.2: Percentage with two decimals

Input the marks obtained in five subjects (each out of 100). Display the total and the percentage with two decimal places.

**Solution:** [P5_2.cpp](P5_2.cpp)

**Sample run**

```
Enter marks of five subjects: 72 85 64 90 78
Total      : 389 / 500
Percentage : 77.80%
```

## P5.3: Kilometres and metres

Input a distance in metres and display it in kilometres and metres. For example, 2750 m = 2 km 750 m.

**Solution:** [P5_3.cpp](P5_3.cpp)

**Sample run**

```
Distance in metres: 2750
2750 m = 2 km 750 m
```

## P5.4: Currency notes

Input an amount in rupees and display how many notes of Rs. 5000, 1000, 500, 100 and 50 make it up, and the remaining rupees. Use `/` and `%`.

**Solution:** [P5_4.cpp](P5_4.cpp)

**Sample run**

```
Amount in rupees: 18780
Rs. 5000 notes: 3
Rs. 1000 notes: 3
Rs. 500 notes : 1
Rs. 100 notes : 2
Rs. 50 notes  : 1
Remaining     : Rs. 30
```

## P5.5: Reverse a four-digit number

Input a four-digit number and display it in reverse order. For example, 4072 becomes 2704.

**Solution:** [P5_5.cpp](P5_5.cpp)

**Sample run**

```
Enter a four-digit number: 4072
Reversed: 2704
```

If the number ends in 0, such as 4070, the reversed number starts with 0 and is printed as 704.

## P5.6: Years, weeks and days

Input the number of days and display it in years, weeks and days (take a year as 365 days).

**Solution:** [P5_6.cpp](P5_6.cpp)

**Sample run**

```
Number of days: 1000
1000 days = 2 years, 38 weeks and 4 days
```

## P5.7: Bank balance

Start with a bank balance of Rs. 25,000. Use compound assignment operators to add a deposit, subtract a withdrawal and add 7% yearly profit, displaying the balance after each step.

**Solution:** [P5_7.cpp](P5_7.cpp)

**Sample run**

```
Starting balance: Rs. 25000
Deposit: Rs. 5000
Balance after deposit   : Rs. 30000
Withdrawal: Rs. 8000
Balance after withdrawal: Rs. 22000
Balance after profit    : Rs. 23540
```

## P5.8: Prefix and postfix

Input an integer and display its value after `++` and `--` are applied in both prefix and postfix form, with a short message explaining each result.

**Solution:** [P5_8.cpp](P5_8.cpp)

**Sample run**

```
Enter an integer: 10
y = x++  gives y = 10, x = 11  (y gets the old value, then x increases)
y = ++x  gives y = 11, x = 11  (x increases first, then y gets the new value)
y = x--  gives y = 10, x = 9  (y gets the old value, then x decreases)
y = --x  gives y = 9, x = 9  (x decreases first, then y gets the new value)
```

## P5.9: Batting average

Input the total runs scored by a batsman and the number of innings (both integers). Display the batting average with two decimal places.

**Solution:** [P5_9.cpp](P5_9.cpp)

**Sample run**

```
Total runs: 1543
Innings   : 37
Batting average: 41.70
```

Without `static_cast<double>`, 1543 / 37 would be integer division and give 41.

## P5.10: Lowercase to uppercase

Input a lowercase letter and display it in uppercase using its ASCII code.

**Solution:** [P5_10.cpp](P5_10.cpp)

**Sample run**

```
Enter a lowercase letter: g
Uppercase: G
```

## P5.11: Compound profit

Input the principal amount, profit rate and number of years. Display the amount using the compound profit formula A = P(1 + r/100)^n.

**Solution:** [P5_11.cpp](P5_11.cpp)

**Sample run**

```
Principal amount: Rs. 100000
Profit rate (% per year): 8
Number of years: 5
Amount after 5 years: Rs. 146932.81
```

## P5.12: Quadratic equation

Input the coefficients a, b and c of a quadratic equation whose roots are real, and display both roots using x = (-b +/- sqrt(b^2 - 4ac)) / 2a.

**Solution:** [P5_12.cpp](P5_12.cpp)

**Sample run**

```
Enter a, b and c: 1 -5 6
Root 1 = 3
Root 2 = 2
```

The problem says the roots are real, so b^2 - 4ac is not negative. Chapter 6 shows how to check this with `if`.

## P5.13: Heron's formula

Input the three sides of a triangle and display its area using Heron's formula.

**Solution:** [P5_13.cpp](P5_13.cpp)

**Sample run**

```
Enter the three sides: 7 8 9
Area = 26.8328
```
