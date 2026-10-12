# Banking System

A console-based Bank Account Management System developed in C as part of the CodeAlpha C Programming Internship.

## Features

* Account creation on first run
* Deposit money
* Withdraw money
* Balance enquiry
* Insufficient balance protection
* Validation for invalid transaction amounts
* Persistent account data using file handling
* Menu-driven console interface

## Account Information

The system stores:

* Account Number
* Account Holder Name
* Account Balance

## Technologies Used

* C Programming
* Structures
* Functions
* File Handling
* Binary File Storage
* GCC Compiler

## Banking Operations

### Deposit

Allows the user to add money to the account.

The program rejects zero or negative deposit amounts.

### Withdraw

Allows the user to withdraw money from the account.

The program:

* Rejects zero or negative withdrawal amounts
* Prevents withdrawals greater than the available balance

### Balance Enquiry

Displays:

* Account Number
* Account Holder Name
* Current Balance

## File Handling

Account information is stored in:

`account.dat`

The program automatically saves account information after transactions and loads the saved account when the program starts.

This allows the balance to persist even after the program is closed and restarted.

## How to Run

Compile the program:

```bash
gcc banking_system.c -o banking_system
```

Run the program:

```bash
./banking_system
```

On Windows PowerShell:

```powershell
.\banking_system.exe
```

## Menu

```text
===== BANK ACCOUNT MANAGEMENT SYSTEM =====

1. Deposit
2. Withdraw
3. Balance Enquiry
4. Exit
```

## Project Structure

```text
CodeAlpha_BankingSystem/
│
├── banking_system.c
├── account.dat
├── README.md
└── .gitignore
```

## Internship Task

This project was developed as **Task 4** of the CodeAlpha C Programming Internship.

## Author

**Sohini Ball**

B.Tech Computer Science & Engineering Student
