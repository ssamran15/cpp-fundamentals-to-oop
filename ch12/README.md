# Chapter 12: Strings, Structures, typedef and Unions

Solutions to the Practice Programs of Chapter 12. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P12_1.cpp -o P12_1` (or press F11 in Dev-C++).

## P12.1: Capitalising each word

Input a full name and display it with every word starting with a capital letter. For example, "ayesha bibi khan" becomes "Ayesha Bibi Khan".

**Solution:** [P12_1.cpp](P12_1.cpp)

**Sample run 1**

```
Enter a full name: ayesha bibi khan
Proper form: Ayesha Bibi Khan
```

**Sample run 2**

```
Enter a full name: MUHAMMAD usman
Proper form: Muhammad Usman
```

The other letters are made small, so a name typed in capitals is also corrected.

## P12.2: Counting a word

Input a sentence and a word. Display how many times the word appears in the sentence, using `find` in a loop.

**Solution:** [P12_2.cpp](P12_2.cpp)

**Sample run**

```
Enter a sentence: the cat sat on the mat near the door
Enter a word: the
"the" appears 3 time(s)
```

`find` can take a second argument: the index to start searching from. Each search starts just after the previous match. The search is for the text, so "the" would also be counted inside a word such as "other".

## P12.3: Splitting an email address

Input an email address and display the user name (the part before `@`) and the domain (the part after it). Display an error if there is no `@`.

**Solution:** [P12_3.cpp](P12_3.cpp)

**Sample run 1**

```
Enter an email address: ali.raza@gmail.com
User name: ali.raza
Domain: gmail.com
```

**Sample run 2**

```
Enter an email address: ali.raza.gmail.com
Error: the address has no @
```

## P12.4: Checking a CNIC

Input a CNIC number in the form 35202-1234567-1 and check that it has 15 characters, dashes at the right places and digits everywhere else.

**Solution:** [P12_4.cpp](P12_4.cpp)

**Sample run 1**

```
Enter CNIC (e.g. 35202-1234567-1): 35202-1234567-1
The CNIC format is valid
```

**Sample run 2**

```
Enter CNIC (e.g. 35202-1234567-1): 35202-12345-671
Invalid: position 12 must be a digit
Invalid: a dash is needed at position 14
```

**Sample run 3**

```
Enter CNIC (e.g. 35202-1234567-1): 3520212345671
Invalid: a CNIC has 15 characters
```

## P12.5: Replacing a word

Input a sentence and replace every occurrence of a given word with another word.

**Solution:** [P12_5.cpp](P12_5.cpp)

**Sample run**

```
Enter a sentence: I like tea. Tea is hot and tea is cheap.
Word to replace: tea
Replace with: coffee
Result: I like coffee. Tea is hot and coffee is cheap.
2 replacement(s) made
```

After each replacement the search continues after the new word, so a new word that contains the old one does not cause an endless loop. The search is case-sensitive, so "Tea" is not replaced.

## P12.6: Sorting city names

Input five city names into an array of `string` and display them in alphabetical order.

**Solution:** [P12_6.cpp](P12_6.cpp)

**Sample run**

```
City 1: Okara
City 2: Lahore
City 3: Multan
City 4: Faisalabad
City 5: Dera Ghazi Khan

In alphabetical order:
Dera Ghazi Khan
Faisalabad
Lahore
Multan
Okara
```

Compare with P11.13: `string` values are compared with `>` and copied with `=`, so `strcmp` and `strcpy` are not needed.

## P12.7: Book structure

Define a structure `Book` with title, author, price and number of copies. Input the details of one book and display them.

**Solution:** [P12_7.cpp](P12_7.cpp)

**Sample run**

```
Title: Computer Science Made Easy
Author: Ahmad Raza
Price: 950
Copies: 40

Book details
Title  : Computer Science Made Easy
Author : Ahmad Raza
Price  : Rs. 950.00
Copies : 40
Stock value: Rs. 38000.00
```

## P12.8: Adding times

Define a structure `Time` with hours, minutes and seconds. Write a function that adds two `Time` values and returns the result, carrying seconds into minutes and minutes into hours.

**Solution:** [P12_8.cpp](P12_8.cpp)

**Sample run**

```
First time
Hours, minutes and seconds: 2 45 50
Second time
Hours, minutes and seconds: 1 30 25
2h 45m 50s + 1h 30m 25s = 4h 16m 15s
```

## P12.9: Result sheet with structures

Store the records (roll number, name, marks in 3 subjects) of 5 students in an array of structures. Display a result sheet with the total and percentage of each student, and the name of the topper.

**Solution:** [P12_9.cpp](P12_9.cpp)

**Output**

```
Roll  Name         S1   S2   S3   Total       %
101   Ayesha       78   85   91     254   84.67
102   Bilal        66   72   58     196   65.33
103   Fatima       88   94   90     272   90.67
104   Hamza        55   61   70     186   62.00
105   Sana         82   79   88     249   83.00

Topper: Fatima (272 marks)
```

The records are stored in the program as an initialised array. The marks are out of 100 in each subject, so the percentage is total / 3.

## P12.10: Pay sheet

Using an array of structures for employees (name, basic salary, allowances), display a pay sheet with gross salary and sort the employees by gross salary in descending order.

**Solution:** [P12_10.cpp](P12_10.cpp)

**Output**

```
Pay sheet
Name                Basic  Allowances     Gross
Asad Mehmood        45000       12000     57000
Rabia Saleem        62000       15500     77500
Imran Haider        38000        9000     47000
Nadia Akram         55000       21000     76000
Kamran Yousaf       70000        8000     78000

Sorted by gross salary
Name                Basic  Allowances     Gross
Kamran Yousaf       70000        8000     78000
Rabia Saleem        62000       15500     77500
Nadia Akram         55000       21000     76000
Asad Mehmood        45000       12000     57000
Imran Haider        38000        9000     47000
```

The employee data is stored in the program. `gross` takes the structure by `const` reference, so no copy is made.

## P12.11: Fractions

Define a structure `Fraction` with numerator and denominator. Write functions to add and multiply two fractions and to reduce a fraction to its lowest terms.

**Solution:** [P12_11.cpp](P12_11.cpp)

**Sample run 1**

```
First fraction (numerator denominator): 1 2
Second fraction (numerator denominator): 3 4
1/2 + 3/4 = 5/4
1/2 x 3/4 = 3/8
```

**Sample run 2**

```
First fraction (numerator denominator): 2 3
Second fraction (numerator denominator): 9 10
2/3 + 9/10 = 47/30
2/3 x 9/10 = 3/5
```

## P12.12: Nested structures

Define a structure `Address` (house, street, city) and a structure `Customer` that contains a name, a phone number and an `Address`. Input and display the data of two customers.

**Solution:** [P12_12.cpp](P12_12.cpp)

**Sample run**

```
Customer 1
Name: Ali Raza
Phone: 0300-1234567
House: 12-B
Street: Canal Road
City: Okara
Customer 2
Name: Sana Tariq
Phone: 0321-7654321
House: 45
Street: Mall Road
City: Lahore

Ali Raza, 0300-1234567
  House 12-B, Canal Road, Okara
Sana Tariq, 0321-7654321
  House 45, Mall Road, Lahore
```

A nested member is reached with two dots, such as `c.address.city`. The phone number is a `string` because it has a dash and a leading zero.

## P12.13: Billing with typedef

Use `typedef` to create the alias `Rupees` for `double` and write a small billing program that uses it for all amounts.

**Solution:** [P12_13.cpp](P12_13.cpp)

**Sample run**

```
Item 1 (name price quantity): Sugar 160 2
  Sugar: 2 x Rs. 160.00 = Rs. 320.00
Item 2 (name price quantity): Rice 340 3
  Rice: 3 x Rs. 340.00 = Rs. 1020.00
Item 3 (name price quantity): Tea 1250 1
  Tea: 1 x Rs. 1250.00 = Rs. 1250.00
Grand total: Rs. 2590.00
```

Item names are read with `cin >>`, so each name must be one word.

## P12.14: A union

Define a union with an `int`, a `float` and a `char` member. Store a value in each member in turn, printing it each time, and display the size of the union.

**Solution:** [P12_14.cpp](P12_14.cpp)

**Output**

```
As int:   2026
As float: 3.75
As char:  Z
Size of the union: 4 bytes
```

All members share the same memory, so only the value stored last is valid. The size of the union is the size of its largest member (`int` and `float`, 4 bytes each).
