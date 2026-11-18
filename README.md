# Gym Membership Management System

A simple C++ console application for recording gym members, assigning membership plans, calculating fees, and saving membership records to a text file.

## Aim

To design and develop a Gym Membership Management System that automates the process of managing members, calculating total membership fees, and saving details to a file accurately and efficiently.

## Objectives

1. Develop a simple Gym Membership Management System using C++.
2. Understand and demonstrate inheritance.
3. Store member information using file handling.
4. Calculate membership fees according to the selected plan.
5. Reduce manual work in managing gym records.

## Features

- Add memberships with a member ID, name, age, and mobile number.
- Choose from the available plans:

  | Duration | Fee |
  | --- | ---: |
  | 1 month | ₹1,000 |
  | 3 months | ₹2,500 |
  | 6 months | ₹4,500 |

- Display saved-in-memory memberships in a table and show their total membership value.
- Append membership records to `members.txt`.
- Use a menu to add, display, save, or exit. The program prints a message when it exits and reports invalid menu choices.

## Object-Oriented Programming Concepts

- **Inheritance:** `Membership` derives from the base class `Member`. `Member` holds personal details, while `Membership` manages the selected plan and fee.
- **File handling:** Membership details are written to `members.txt` so they can be retained after the program ends.
- **Vectors:** Membership records are stored in a vector while the program is running.

## Project Files

- `GymMembership.cpp` — C++ source code.
- `members.txt` — text file used to store membership records. Saving appends records to this file.

## Requirements

- A C++ compiler with C++11 support or later.

## Build and Run

From the directory containing `GymMembership.cpp`, compile and run:

```sh
g++ -std=c++11 GymMembership.cpp -o GymMembership
./GymMembership
```

On Windows with MinGW, run the compiled program with:

```sh
GymMembership.exe
```

The program creates or appends to `members.txt` in its current working directory when you select **Save to file**. Each save writes the memberships currently held in memory; saving more than once during the same run appends those records again.

## Conclusion

The Gym Membership Management System demonstrates the practical use of inheritance and file handling in C++. The base class stores personal information, and the derived class manages membership plans and fees. Membership details can be saved in a text file for persistent storage. This project provides a simple way to manage gym membership records while illustrating code reuse, inheritance, vectors, and basic file operations.