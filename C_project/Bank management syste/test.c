#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// student struct definition
typedef struct
{
    char student_name[50];
    char id[20];
    char father_name[50];
    char mother_name[50];
    char email[50];
    char phone_number[15];
} student;

// mark_sheet struct definition
typedef struct
{
    char student_id[20];
    char exam_type[20];
    char sub1[5], sub2[5], sub3[5], sub4[5], sub5[5];
} mark_sheet;

// struct declaration
student s;
mark_sheet mark;

// function prototype
void welcome();            // welcome screen
void main_welcome();       // main menu
void add_student();        // add student info
void search_student();     // search student
void modify_student();     // student info modify
void generate_marksheet(); // mark_sheet manu
void delete_student();     // student info delete
void add_student_mark();   // add student mark
void show_student_mark();  // show student mark

// main function
int main()
{
    welcome();
    main_welcome();
    return 0;
}

// function definition
void welcome()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("\n\t\t\t        |********************************************|");
    printf("\n\t\t\t        |                    Welcome                 |");
    printf("\n\t\t\t        |                      To                    |");
    printf("\n\t\t\t        |               Student Management           |");
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
void main_welcome()
{
    int choice;
    // main manu choice options
    printf("\n\n\n1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Modify Student Record\n");
    printf("4. Generate Marksheet\n");
    printf("5. Delete Student Record\n");
    printf("6. Exit\n\n");
    printf(">>> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_student();
        break;
    case 2:
        search_student();
        break;
    case 3:
        modify_student();
        break;
    case 4:
        generate_marksheet();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Invalid Input");
        exit(1);
        break;
    }
}
void add_student()
{
    printf("\n\n=== Enter student details below ===\n\n");

    // file open
    FILE *student_file;
    student_file = fopen("student_database.txt", "ab+");
    if (student_file == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    // input student data
    printf("Student name : ");
    fflush(stdin);
    scanf("%[^\n]", &s.student_name);
    fflush(stdin);
    printf("Student ID : ");
    scanf("%[^\n]", &s.id);
    fflush(stdin);
    printf("Father's Name : ");
    scanf("%[^\n]", &s.father_name);
    fflush(stdin);
    printf("Mother's Name : ");
    scanf("%[^\n]", &s.mother_name);
    fflush(stdin);
    printf("E-mail : ");
    scanf("%[^\n]", &s.email);
    fflush(stdin);
    printf("Phone Number : ");
    scanf("%[^\n]", &s.phone_number);
    fflush(stdin);

    // write student data
    fwrite(&s, sizeof(s), 1, student_file);
    printf("\nStudent record added sucessfully");

    // file close
    fclose(student_file);
    main_welcome();
}
void search_student()
{
    printf("\n\n=== Search Recoard ===\n\n");
    char s_id[20];
    int found = 0;

    // input student id
    printf("\nEnter ID to Search: ");
    fflush(stdin);
    gets(s_id);

    // file open
    FILE *fp;
    fp = fopen("student_database.txt", "rb");

    // check student id
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(s_id, s.id) == 0)
        {
            found = 1;
            break;
        }
    }
    // if id found in our database
    if (found == 1)
    {
        printf("\n=== Student Record Found ===\n\n");
        printf("ID: %s\n", s.id);
        printf("Name: %s\n", s.student_name);
        printf("Father's Name : %s\n", s.father_name);
        printf("Mother's Name : %s\n", s.mother_name);
        printf("E-mail : %s\n", s.email);
        printf("Phone Number : %s\n", s.phone_number);
    }
    // if id not found in our database
    else
    {
        printf("Sorry, No Record Found");
    }

    // file close
    fclose(fp);
    main_welcome();
}
void modify_student()
{
    printf("\n\n=== Modify Recoard ===\n\n");
    char s_id[20];
    int found = 0;

    // input student id
    printf("\nEnter ID to Modify: ");
    fflush(stdin);
    gets(s_id);

    // file open
    FILE *fp;
    fp = fopen("student_database.txt", "rb+");

    // check student id
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(s_id, s.id) == 0)
        {
            found = 1;
            break;
        }
    }
    // if found
    if (found == 1)
    {
        printf("\n\n=== Enter New Info ==\n\n");
        printf("Student name : ");
        fflush(stdin);
        scanf("%[^\n]", &s.student_name);
        fflush(stdin);
        printf("Student ID : ");
        scanf("%[^\n]", &s.id);
        fflush(stdin);
        printf("Father's Name : ");
        scanf("%[^\n]", &s.father_name);
        fflush(stdin);
        printf("Mother's Name : ");
        scanf("%[^\n]", &s.mother_name);
        fflush(stdin);
        printf("E-mail : ");
        scanf("%[^\n]", &s.email);
        fflush(stdin);
        printf("Phone Number : ");
        scanf("%[^\n]", &s.phone_number);
        fflush(stdin);

        // move file pointer to a student id position
        fseek(fp, -sizeof(s), SEEK_CUR);
        // write new info
        fwrite(&s, sizeof(s), 1, fp);
        printf("\nRecord update successfully\n");
    }

    else
    {
        printf("Sorry, No Record Found\n");
    }

    // file close
    fclose(fp);
    main_welcome();
}
void delete_student()
{
    printf("\n\n=== Delete Record ===\n\n");
    char s_id[20];
    int found = 0;

    // input student id
    printf("\nEnter ID to Delete Record: ");
    fflush(stdin);
    gets(s_id);

    // file open
    FILE *fp;
    fp = fopen("student_database.txt", "rb+");

    // check student id
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(s_id, s.id) == 0)
        {
            found = 1;
            break;
        }
    }
    // if found
    if (found == 1)
    {

        strcpy(s.student_name, "");
        strcpy(s.mother_name, "");
        strcpy(s.mother_name, "");
        strcpy(s.email, "");
        strcpy(s.phone_number, "");
        strcpy(s.id, "");
        // move file pointer to student id positon
        fseek(fp, -sizeof(s), SEEK_CUR);
        // write empty data
        fwrite(&s, sizeof(s), 1, fp);
        printf("\nStudent Record delete sucessfully\n");
    }
    else
    {
        printf("Sorry, No Record Found\n");
    }

    // file close
    fclose(fp);
    main_welcome();
}
void generate_marksheet()
{
    int choice;
    // generate marksheet choice options
    printf("\n1. Add Student Mark Sheet\n");
    printf("2. Show Student Mark Sheet\n");
    printf("3. Main Manu\n");
    printf("4. Exit\n\n");
    printf(">>> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_student_mark();
        break;
    case 2:
        show_student_mark();
        break;
    case 3:
        main_welcome();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid Input");
        exit(1);
        break;
    }
}
void add_student_mark()
{
    char s_id[20];
    int found = 0;

    // input student id
    printf("\nEnter ID: ");
    fflush(stdin);
    gets(s_id);

    // file open
    FILE *fp, *fb;
    fp = fopen("student_database.txt", "rb");
    // check id in our student_database
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (strcmp(s_id, s.id) == 0)
        {
            found = 1;
            break;
        }
    }
    // file close
    fclose(fp);

    if (found == 1)
    {
        // mark file open
        fb = fopen("mark.txt", "ab+");
        if (fb == NULL)
        {
            printf("File is not opened\n");
            exit(1);
        }

        // general input
        strcpy(mark.student_id, s_id);
        printf("Exam type : ");
        scanf("%[^\n]", &mark.exam_type);
        fflush(stdin);

        // subject mark input
        printf("English : ");
        scanf("%[^\n]", &mark.sub1);
        fflush(stdin);
        printf("Physics : ");
        scanf("%[^\n]", &mark.sub2);
        fflush(stdin);
        printf("Math : ");
        scanf("%[^\n]", &mark.sub3);
        fflush(stdin);
        printf("Chemistry : ");
        scanf("%[^\n]", &mark.sub4);
        fflush(stdin);
        printf("Computer : ");
        scanf("%[^\n]", &mark.sub5);
        fflush(stdin);
        // write inpute data
        fwrite(&mark, sizeof(mark), 1, fb);
        printf("\nMarks added sucessfully\n");
    }
    else
    {
        printf("\nSorry, This ID not found in our student database\n");
    }

    // file close
    fclose(fb);
    generate_marksheet();
}
void show_student_mark()
{
    char student_id[15];
    char student_name[50];
    int found = 0, total;
    float avarage;

    fflush(stdin);
    // input student id
    printf("Student ID : ");
    scanf("%[^\n]", &student_id);
    fflush(stdin);

    // file open
    FILE *fb, *fl;
    fb = fopen("mark.txt", "rb");
    // check id in our mark database
    while (fread(&mark, sizeof(mark), 1, fb) == 1)
    {
        if (strcmp(student_id, mark.student_id) == 0)
        {
            found = 1;
            break;
        }
    }
    // if found
    if (found == 1)
    {
        // open student_database file
        fl = fopen("student_database.txt", "rb");
        // check student id
        while (fread(&s, sizeof(s), 1, fl) == 1)
        {
            if (strcmp(s.id, student_id) == 0)
            {
                // copy date from student_database to student_name[50]
                strcpy(student_name, s.student_name);
                break;
            }
        }
        // file close
        fclose(fl);
        // mark sheet print
        printf("\n\t    ===== Mark Sheet =====\n");
        printf("Name : %s", student_name);
        printf("\tExam : %s", mark.exam_type);
        printf("\t  ID : %s\n", mark.student_id);
        printf("===========================================\n");
        printf("\t\tEnglish   : %s\n", mark.sub1);
        printf("\t\tPhysics   : %s\n", mark.sub2);
        printf("\t\tMath      : %s\n", mark.sub3);
        printf("\t\tChemistry : %s\n", mark.sub4);
        printf("\t\tComputer  : %s\n", mark.sub5);
        printf("===========================================\n");
        // total mark
        total = atoi(mark.sub1) + atoi(mark.sub2) + atoi(mark.sub3) + atoi(mark.sub4) + atoi(mark.sub5); // atio() function convert string number to number
        // avarage
        avarage = (float)total / 5;
        printf("Total Marks: %d", total);
        printf("\tAvarage Marks : %.1f\n\n", avarage);
    }
    else
    {
        printf("\nSorry, This id does not found in our database.\n");
    }

    // file close
    fclose(fb);
    generate_marksheet();
}