#include<stdio.h>

typedef struct employee{

    char name[20];
    int age;
    int salary;
    int bonus;

} employee;

void emp_bonus(employee emp[],int emp_num);
void file_write(employee emp[], int emp_num);

int main()
{
    employee emp[50];
    int emp_num;

    printf("Employees Number (max 50) : ");
    scanf("%d", &emp_num);
    fflush(stdin);

    for (int i = 0; i < emp_num;i++){

        printf("Enter name: ");
        scanf("%[^\n]", &emp[i].name);
        printf("Enter age : ");
        scanf("%d", &emp[i].age);
        printf("Enter salary : ");
        scanf("%d", &emp[i].salary);
        printf("Enter bonus : ");
        scanf("%d", &emp[i].bonus);
        fflush(stdin);
        printf("\n");
    }

    emp_bonus(emp,emp_num);
    file_write(emp, emp_num);

    return 0;
}


void emp_bonus(employee emp[],int emp_num){
    
    int total_selary = 0;

    for (int i = 0; i < emp_num;i++){
        if (emp[i].age > 50)
        {
            total_selary = ((emp[i].salary * 40) / 100) + emp[i].salary;
            printf("Name : %s\n", emp[i].name);
            printf("Total Salary : %d\n", total_selary);
        }

        else{
            total_selary = ((emp[i].salary * 25) / 100) + emp[i].salary;
            printf("Name : %s\n", emp[i].name);
            printf("Total Salary : %d\n", total_selary);
        }

        printf("\n");
    }
}


void file_write(employee emp[],int emp_num){

    FILE *fl;
    fl = fopen("Employee_Data.txt", "a");

    if(fl == NULL){
        printf("File failed to open\n");
        return;
    }

    else{

        for (int i = 0; i < emp_num;i++)
        {
            fprintf(fl, "Name : %s\n", emp[i].name);
            fprintf(fl, "Age : %d\n", emp[i].age);
        }

        fclose(fl);
    }
}

