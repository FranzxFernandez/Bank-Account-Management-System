#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char accountHolderName[100];
    float accountBalance;
} BankAccount;

void createAccount(BankAccount *account);
void deposit(BankAccount *account, float amount);
void withdraw(BankAccount *account, float amount);
void checkBalance(const BankAccount *account);
void displayAccount(const BankAccount *account);


int main() {
    BankAccount account;
    int choice;
    float amount;

    while (1) {
        printf("Bank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;
            case 3:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 5:
                displayAccount(&account);
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

