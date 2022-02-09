#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Struct definition
typedef struct
{
    char name[50];
    int age;
    long int mobile_number;
    char address[100];
    long int account_number;
    long int balance;
    char bank_name[100];
    char bank_branch_name[50];
    char pass[8];
} bank_info;

// sturct declaration
bank_info bank;

// function prototype
void welcome();
void main_manu();
void bank_manu();
void atm_manu();
void create_account();
void update_account();
void remove_account();
void account_info();
void widraw();
void deposit();
void check_balance();
int intcmp(int, int);
void exit_system();
void animation();

// main function
int main()
{
    welcome();
    main_manu();
    return 0;
}

// exit functino
void exit_system()
{
    exit(0);
}

// animaton function
void animation()
{
    printf("\r\t  Working.");
    sleep(1);
    printf("\r\t  Working..");
    sleep(1);
    printf("\r\t  Working...");
    sleep(1);
    printf("\r\t  Working....");
    sleep(1);
    printf("\r\t  Working.....");
    sleep(1);
    fflush(stdout);
}

// welcome function
void welcome()

{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("\n\t\t\t        |********************************************|");
    printf("\n\t\t\t        |                    Welcome                 |");
    printf("\n\t\t\t        |                      To                    |");
    printf("\n\t\t\t        |                Bank Management             |");
    printf("\n\t\t\t        |                    System                  |");
    printf("\n\t\t\t        **********************************************");
    printf("\n\t\t\t  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n");

    // simple animation
    while (1)
    {
        printf("\r\t\t\t  Loading.");
        sleep(1);
        printf("\r\t\t\t  Loading..");
        sleep(1);
        printf("\r\t\t\t  Loading...");
        sleep(1);
        printf("\r\t\t\t  Loading....");
        sleep(1);
        printf("\r\t\t\t  Loading.....");
        sleep(1);
        printf("\r\t\t\t Press any key to continue...");
        fflush(stdout);
        if (getch())
        {
            break;
        }
    }
}

// main manu function
void main_manu()
{
    int choice;
    // main manu options
    printf("\n\n\n1. Bank System\n");
    printf("2. ATM System\n");
    printf("3. Exit\n\n");
    printf(">>> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bank_manu();
        break;
    case 2:
        atm_manu();
        break;
    case 3:
        exit_system();
        break;
    default:
        printf("Invalid Input");
        exit_system();
        break;
    }
}

// bank manu function
void bank_manu()
{
    int choice;
    printf("\n\n\n1. Create Account\n");
    printf("2. Update Account\n");
    printf("3. Account Details\n");
    printf("4. Delete Account\n");
    printf("5. Main Manu\n");
    printf("6. Exit\n\n");
    printf(">>> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create_account();
        break;
    case 2:
        update_account();
        break;
    case 3:
        account_info();
        break;
    case 4:
        remove_account();
        break;
    case 5:
        main_manu();
        break;
    case 6:
        exit_system();
        break;
    default:
        printf("Invalid Input");
        exit_system();
        break;
    }
}

// atm manu function
void atm_manu()
{
    int choice;
    printf("\n\n\n1. Check Balance\n");
    printf("2. Withdraw\n");
    printf("3. Deposit\n");
    printf("4. Main Manu\n");
    printf("5. Exit\n");
    printf(">>> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        check_balance();
        break;
    case 2:
        widraw();
        break;
    case 3:
        deposit();
        break;
    case 4:
        main_manu();
        break;
    case 5:
        exit_system();
        break;
    default:
        printf("Invalid Input");
        exit_system();
        break;
    }
}

// create account function
void create_account()
{
    printf("\n\n=== Enter Account details below ===\n\n");

    // file open
    FILE *account;
    account = fopen("account_database.dat", "ab");
    if (account == NULL)
    {
        printf("File is not opened\n");
        exit_system();
    }

    // input account holder data
    printf("Bank Name : ");
    fflush(stdin);
    scanf("%[^\n]", &bank.bank_name);
    fflush(stdin);
    printf("Bank Branch Name : ");
    scanf("%[^\n]", &bank.bank_branch_name);
    fflush(stdin);
    printf("Account Holder Name : ");
    scanf("%[^\n]", &bank.name);
    fflush(stdin);
    printf("Age : ");
    scanf("%d", &bank.age);
    fflush(stdin);
    printf("Mobile Number : ");
    scanf("%d", &bank.mobile_number);
    fflush(stdin);
    printf("Account Holder Address : ");
    scanf("%[^\n]", &bank.address);
    fflush(stdin);
    printf("Bank Account Number (max 17) : ");
    scanf("%d", &bank.account_number);
    fflush(stdin);
    printf("Enter Password (max 8) : ");
    scanf("%[^\n]", &bank.pass);
    fflush(stdin);
    printf("Cash Deposit : ");
    scanf("%d", &bank.balance);
    fflush(stdin);

    // write account data
    fwrite(&bank, sizeof(bank), 1, account);
    animation();
    printf("\nAccount has been created successfully\n");

    // file close
    fclose(account);
    bank_manu();
}

// account info function
void account_info()
{
    int account_num;
    char pass[8];
    int found = 0;
    printf("\n\n=== Account Details ===\n\n");

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("\n=== Account Details Found ===\n\n");
        printf("Bank Name : %s\n", bank.bank_name);
        printf("Branch Name : %s\n", bank.bank_branch_name);
        printf("Account Holder Name : %s\n", bank.name);
        printf("Account Holder Age : %d\n", bank.age);
        printf("Account Holder Mobile Number : %d\n", bank.mobile_number);
        printf("Account Holder Address : %s\n", bank.address);
        printf("Current Balance : %d\n", bank.balance);
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    bank_manu();
}

// intcmp function
int intcmp(int a, int b)
{
    if (a == b)
        return 0;
    return 1;
}

// update account function
void update_account()
{
    int account_num;
    char pass[8];
    int found = 0;
    printf("\n\n=== Account Details ===\n\n");

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb+");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {

        printf("\n=== Account Found Enter new Details Below ===\n\n");
        fflush(stdin);
        printf("Account Holder Name : ");
        scanf("%[^\n]", &bank.name);
        fflush(stdin);
        printf("Age : ");
        scanf("%d", &bank.age);
        fflush(stdin);
        printf("Mobile Number : ");
        scanf("%d", &bank.mobile_number);
        fflush(stdin);
        printf("Account Holder Address : ");
        scanf("%[^\n]", &bank.address);
        fflush(stdin);
        printf("Password : ");
        scanf("%[^\n]", &bank.pass);
        fflush(stdin);

        // move file pointer
        fseek(database_open, -(long)sizeof(bank), 1);
        // write new info
        fwrite(&bank, sizeof(bank), 1, database_open);
        animation();
        printf("\nAccount update successfully\n");
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    bank_manu();
}

// remove account function
void remove_account()
{
    int account_num;
    char pass[8];
    int found = 0;
    printf("\n\n=== Account Details ===\n\n");

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb+");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {

        strcpy(bank.name, "");
        bank.age = 0;
        bank.mobile_number = 0;
        strcpy(bank.address, "");
        bank.account_number = 0;
        bank.balance = 0;
        strcpy(bank.bank_name, "");
        strcpy(bank.bank_branch_name, "");
        strcpy(bank.pass, "");

        // move file pointer
        fseek(database_open, -(long)sizeof(bank), 1);
        fwrite(&bank, sizeof(bank), 1, database_open);
        animation();
        printf("\n\nAccount Remove successfully\n");
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    bank_manu();
}

// check balance
void check_balance()
{
    int account_num;
    char pass[8];
    int found = 0;
    printf("\n\n=== Account Details ===\n\n");

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {

        printf("\n=== Account Details Found ===\n\n");
        printf("\nBank Name");
        printf("\t\tAccount Holder Name");
        printf("\t\t\t Balance");
        printf("\n=========================================================================");
        printf("\n%s", bank.bank_name);
        printf("\t\t\t\t%s", bank.name);
        printf("\t\t\t\t %dTK\n", bank.balance);
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    atm_manu();
}

// widraw function
void widraw()
{
    int account_num;
    char pass[8];
    int found = 0;
    long int money;
    long int left_balance;
    long int current_balance;

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb+");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Your Balance : %dTk\n", bank.balance);
        printf("Enter Ammount money to Widraw: ");
        scanf("%d", &money);

        current_balance = bank.balance;
        left_balance = current_balance - money;

        if (left_balance < 500)
        {
            printf("\nInsufficient Balance.");
            atm_manu();
        }
        bank.balance = left_balance;

        printf("\nYour Current Balance : %dTk", bank.balance);

        // move file pointer
        fseek(database_open, -(long)sizeof(bank), 1);
        // write new info
        fwrite(&bank, sizeof(bank), 1, database_open);
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    atm_manu();
}

// deposit function
void deposit()
{
    int account_num;
    char pass[8];
    int found = 0;
    long int money;
    long int current_balance;
    long int new_balance;

    // input account number
    printf("\nPlease Enter Account Number : ");
    scanf("%d", &account_num);
    fflush(stdin);
    printf("Enter Password : ");
    scanf("%[^\n]", &pass);
    fflush(stdin);

    // file open
    FILE *database_open;
    database_open = fopen("account_database.dat", "rb+");

    // check account number
    while (fread(&bank, sizeof(bank), 1, database_open) == 1)
    {
        if ((intcmp(bank.account_number, account_num) == 0) && (strcmp(bank.pass, pass) == 0))
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Your Balance : %dTk\n", bank.balance);
        printf("Enter Your Amount to Deposit : ");
        scanf("%d", &money);

        current_balance = bank.balance;
        new_balance = current_balance + money;
        bank.balance = new_balance;
        printf("\nYour Current Balance : %dTk\n", bank.balance);

        // move file pointer
        fseek(database_open, -(long)sizeof(bank), 1);
        // write new info
        fwrite(&bank, sizeof(bank), 1, database_open);
    }
    else
    {
        printf("Sorry, Your Account doesn't exist in our database\n");
    }
    // file close
    fclose(database_open);
    atm_manu();
}
