# Student Management System

A console-based Student Management System developed in C as part of the CodeAlpha C Programming Internship.

## Features

* Add student records
* Display all students
* Search students by ID
* Update student information
* Delete student records
* Prevent duplicate Student IDs
* Validate age and marks
* Store student records using file handling
* Load saved records when the program starts
* Menu-driven console interface

## Student Information

Each student record contains:

* Student ID
* Student Name
* Age
* Course
* Marks

## Technologies Used

* C Programming
* Structures
* Arrays
* Functions
* File Handling
* Binary File Storage
* GCC Compiler

## Validation

The program validates:

* Student ID must be positive
* Student IDs must be unique
* Age must be between 1 and 100
* Marks must be between 0 and 100

## File Handling

Student records are stored in:

`students.dat`

The program automatically loads previously saved records when it starts and saves changes after adding, updating, or deleting students.

## How to Run

Compile the program:

```bash
gcc student_management.c -o student_management
```

Run the program:

```bash
./student_management
```

On Windows PowerShell:

```powershell
.\student_management.exe
```

## Menu

```text
===== STUDENT MANAGEMENT SYSTEM =====

1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

## Internship Task

This project was developed as **Task 3** of the CodeAlpha C Programming Internship.

## Author

**Sohini Ball**

B.Tech Computer Science & Engineering Student
