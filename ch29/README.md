# Chapter 29: Multiple Inheritance, Class Relationships and UML

Solutions to the Practice Programs of Chapter 29. Each program uses only what has been taught up to this chapter. Try each problem yourself before you look at the solution.

More exercises for this chapter (Determine the output, Find the error) are in [more-exercises.md](more-exercises.md).

To compile from the Command Prompt: `g++ -std=c++17 -Wall -Wextra P29_1.cpp -o P29_1` (or press F11 in Dev-C++).

## P29.1: SmartPhone from Phone and Camera

Write classes `Phone` (number, network) and `Camera` (megapixels), and a class `SmartPhone` derived from both that adds the storage size. Give every class a constructor with arguments and a display function, and show the order of constructor calls.

**Solution:** [P29_1.cpp](P29_1.cpp)

**Output**

```
[Phone constructor]
[Camera constructor]
[SmartPhone constructor]

Number: 0300-1112223 on CityNet
Camera: 48 MP
Storage: 128 GB
```

Base classes are built in the order they are listed in `class SmartPhone : public Phone, public Camera`, whatever order the initializer list uses. Writing the list in a different order makes GCC warn (`-Wreorder`, part of `-Wall`), so the list follows the class header. The network name is made up.

## P29.2: Result from Student and Sportsman

Write a class `Student` (name, marks out of 500) and a class `Sportsman` (sport, sports score). Derive a class `Result` from both that adds a bonus of 20 marks for a score of 80 or more and 10 marks for 50 or more, and prints the total.

**Solution:** [P29_2.cpp](P29_2.cpp)

**Output**

```
Hamza Ali (Cricket, score 86): 412 + bonus 20 = 432 / 500
Sana Tariq (Badminton, score 64): 437 + bonus 10 = 447 / 500
Usman Raza (Hockey, score 35): 398 + bonus 0 = 398 / 500
```

## P29.3: AmphibiousVehicle

Write a class `Vehicle` (registration number, speed), classes `LandVehicle` (wheels) and `WaterVehicle` (draught) derived from it as virtual bases, and a class `AmphibiousVehicle` derived from both. Show that only one `Vehicle` part exists.

**Solution:** [P29_3.cpp](P29_3.cpp)

**Output**

```
[Vehicle constructor]
AMP-07: 40 km/h, 6 wheels, draught 0.8 m
Vehicle part reached through LandVehicle and WaterVehicle is the same object
AMP-07: 55 km/h, 6 wheels, draught 0.8 m
```

The proof is threefold: the `Vehicle` constructor runs once, the two paths to the `Vehicle` part give the same address, and a speed changed through `LandVehicle` is the speed seen everywhere. With a virtual base, the most derived class (`AmphibiousVehicle`) calls the `Vehicle` constructor itself.

## P29.4: Two interfaces

Write two interfaces `Printable` and `Savable` and a class `Invoice` that implements both. Keep an array of `Printable *` and an array of `Savable *` that point to the same invoices, and call the functions through each.

**Solution:** [P29_4.cpp](P29_4.cpp)

**Output**

```
Printing:
Invoice 101: Okara Traders, Rs. 18500
Invoice 102: City Bookshop, Rs. 7250
Saving:
Saving invoice 101 to invoice_101.txt
Saving invoice 102 to invoice_102.txt
```

`save()` only prints a message; writing to a real file is covered in Chapter 30.

## P29.5: Doctor and Patient

Write classes `Doctor` and `Patient` with a two-way association: each patient keeps a pointer to the doctor, and each doctor keeps pointers to up to 10 patients. Print each doctor's patient list and each patient's doctor.

**Solution:** [P29_5.cpp](P29_5.cpp)

**Output**

```
Dr. Hina Tariq's patients: Ali, Bilal
Dr. Kamran Yousaf's patients: Sana
Ali is treated by Dr. Hina Tariq
Sana is treated by Dr. Kamran Yousaf
Bilal is treated by Dr. Hina Tariq
Fatima is treated by no doctor yet
```

`addPatient` also calls `setDoctor`, so the two directions of the link can never disagree. `Doctor::addPatient` is defined after `Patient`, because it calls a `Patient` member function.

## P29.6: Players outlive their team

Write classes `Team` and `Player` using aggregation. Show that when a team object is destroyed, its players still exist and can be added to another team.

**Solution:** [P29_6.cpp](P29_6.cpp)

**Output**

```
Okara Eagles: Hamza Usman Bilal
[Team Okara Eagles destroyed]
The players still exist: Hamza, Usman, Bilal
Sahiwal Stars: Hamza Bilal
[Team Sahiwal Stars destroyed]
```

## P29.7: House of rooms

Write a class `Room` (name, length, width) and a class `House` that is composed of up to six rooms. Read the rooms from the user and print each room's area and the total covered area.

**Solution:** [P29_7.cpp](P29_7.cpp)

**Sample run**

```
Number of rooms (up to 6): 4
Room 1 (name length width): Lounge 20 16
Room 2 (name length width): Bedroom 16 14
Room 3 (name length width): Kitchen 12 10
Room 4 (name length width): Bath 8 6

Lounge           320 sq ft
Bedroom          224 sq ft
Kitchen          120 sq ft
Bath              48 sq ft
Total covered area: 712 sq ft
```

## P29.8: Hospital in UML and C++

Draw a UML class diagram on paper for a small hospital system with classes `Person`, `Doctor`, `Patient`, `Ward` and `Hospital`, showing at least one example of each relationship of Section 29.5 with multiplicities. Then write the C++ classes and a `main()` that uses them.

**Solution:** [P29_8.cpp](P29_8.cpp)

**Output**

```
City Hospital, Okara: daily rounds
Medical ward, 2 patient(s):
  Dr. Hina Tariq (medicine) examines Ali for fever
  Dr. Hina Tariq (medicine) examines Bilal for asthma
Surgical ward, 1 patient(s):
  Dr. Kamran Yousaf (surgery) examines Sana for a broken arm
Children ward, 1 patient(s):
  Dr. Nadia Akram (child health) examines Zainab for a cough
```

The class diagram, with a table linking each relationship to the code, is in [P29.8.md](P29.8.md).
