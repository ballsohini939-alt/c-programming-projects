#include <stdio.h>
#include <stdlib.h>
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};
struct Account account;
void deposit();
void withdraw();
void balanceEnquiry();
void saveAccount();
void loadAccount();
int main() {
    int choice;
    loadAccount();
    do {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Enquiry\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                balanceEnquiry();
                break;

            case 4:
                saveAccount();
                printf("\nThank you for using the Banking System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
void deposit() {
    float amount;
    printf("\n===== DEPOSIT =====\n");
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("\nInvalid amount. Deposit must be greater than 0.\n");
        return;
    }
    account.balance = account.balance + amount;
    saveAccount();
    printf("\nAmount deposited successfully!\n");
    printf("Current Balance: %.2f\n", account.balance);
}

void withdraw() {
    float amount;
    printf("\n===== WITHDRAW =====\n");
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("\nInvalid amount. Withdrawal must be greater than 0.\n");
        return;
    }
    if (amount > account.balance) {
        printf("\nInsufficient balance.\n");
        printf("Current Balance: %.2f\n", account.balance);
        return;
    }
    account.balance = account.balance - amount;
    saveAccount();
    printf("\nAmount withdrawn successfully!\n");
    printf("Current Balance: %.2f\n", account.balance);
}

void balanceEnquiry() {
    printf("\n===== BALANCE ENQUIRY =====\n");
    printf("Account Number : %d\n", account.accountNumber);
    printf("Account Holder : %s\n", account.name);
    printf("Balance        : %.2f\n", account.balance);
}

void saveAccount() {
    FILE *file;
    file = fopen("account.dat", "wb");
    if (file == NULL) {
        printf("\nError: Unable to save account data.\n");
        return;
    }
    fwrite(
        &account,
        sizeof(struct Account),
        1,
        file
    );
    fclose(file);
}

void loadAccount() {
    FILE *file;
    file = fopen("account.dat", "rb");
    if (file == NULL) {
        account.accountNumber = 1001;
        printf("Enter Account Holder Name: ");
        scanf(" %[^\n]", account.name);
        account.balance = 0;
        saveAccount();
        return;
    }
    fread(
        &account,
        sizeof(struct Account),
        1,
        file
    );
    fclose(file);
}