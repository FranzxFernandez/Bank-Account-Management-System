#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int accountNumber;
    char *accountHolderName; // Array of account holder names
    float accountBalance;
} BankAccount;

void createAccount(BankAccount *account);
void deposit(BankAccount *account, float amount);
void withdraw(BankAccount *account, float amount);
void checkBalance(const BankAccount *account);
void displayAccount(const BankAccount *account);

int main()
{
    //system("cls");

    BankAccount account;
    int choice;
    float amount;
    bool exit = false;

    while (!exit)
    {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        (void)scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount(&account);
            break;
        case 2:
            printf("Enter the amount to deposit: ");
            (void)scanf("%f", &amount);
            deposit(&account, amount);
            break;
        case 3:
            printf("Enter the amount to withdraw: ");
            (void)scanf("%f", &amount);
            withdraw(&account, amount);
            break;
        case 4:
            checkBalance(&account);
            break;
        case 5:
            displayAccount(&account);
            break;
        case 6:
            exit = !exit;
            printf("\nClosing the program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    free(account.accountHolderName);
    return 0;
}

void createAccount(BankAccount *account)
{
    account->accountHolderName = (BankAccount *)malloc(100 * sizeof(char)); // dynamically allocated
    if (account->accountHolderName == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    printf("\nEnter the name of the account: ");
    fflush(stdin); // Clear the input buffer before fgets()
    fgets(account->accountHolderName, 100, stdin);

    // Remove newline character from accountHolderName
    size_t len = strlen(account->accountHolderName);
    if (len > 0 && account->accountHolderName[len - 1] == '\n')
    {
        account->accountHolderName[len - 1] = '\0';
    }

    printf("\nEnter the number of the account: ");
    (void)scanf("%d", &account->accountNumber);

    printf("\nEnter the Balance: ");
    (void)scanf("%f", &account->accountBalance);

    printf("\nAccount created successfully!\n");
}

void deposit(BankAccount *account, float amount)
{
    account->accountBalance += amount;
    printf("\nYou have successfully deposited %.2f$\n", amount);
}

void withdraw(BankAccount *account, float amount)
{
    if (account->accountBalance > 0 && account->accountBalance > amount)
    {
        account->accountBalance -= amount;
        printf("\nYou have successfully withdrawn %.2f$\n", amount);
    }
    else
    {
        printf("\nError withdrawn money. Try it again!\n");
    }
}

void checkBalance(const BankAccount *account)
{
    printf("\nYour balance is: %.2f$\n", account->accountBalance);
}

void displayAccount(const BankAccount *account)
{
    size_t nameLength = strlen("Account Holder Name: ") + strlen(account->accountHolderName);
    size_t numberLength = snprintf(NULL, 0, "Account Number: %d", account->accountNumber);
    size_t balanceLength = snprintf(NULL, 0, "Account Balance: %.2f", account->accountBalance);

    size_t maxLength = nameLength > numberLength ? nameLength : numberLength;
    maxLength = maxLength > balanceLength ? maxLength : balanceLength;

    // Print the first separator line
    for (size_t i = 0; i < maxLength; i++)
    {
        printf("=");
    }
    printf("\n");

    printf("Account Holder Name: %s\n", account->accountHolderName);
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Balance: %.2f\n", account->accountBalance);

    // Print the second separator line
    for (size_t i = 0; i < maxLength; i++)
    {
        printf("=");
    }
    printf("\n");
}
