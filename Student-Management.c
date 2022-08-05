#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student
{
    int studentID;
    char name[30],birthday[30],course[30],class[30];
};

struct Student listStudents[10000];
int numStudents = 0;

void readFile()
{
    FILE* fOut = fopen("Student.txt", "r");
    if(fOut)
    {
        for (;;)
        {
            fscanf(fOut,"%d,%[^,],%[^,],%[^,],%s\n",&listStudents[numStudents].studentID,listStudents[numStudents].name,listStudents[numStudents].birthday,listStudents[numStudents].course,listStudents[numStudents].class);
            numStudents ++;
            if(feof(fOut))
            {
                break;
            }
        }
    }
    fclose(fOut);
}

void writeFile()
{
    FILE* file = fopen("Student.txt", "w+");
    int i;
    for ( i=0; i < numStudents; i++)
    {
        fprintf(file,"%d,%s,%s,%s,%s\n", listStudents[i].studentID, listStudents[i].name, listStudents[i].birthday, listStudents[i].course, listStudents[i].class);
    }
    fclose(file);
}

void addStudent()
{
    struct Student student;
    printf("Enter student id: ");
    scanf("%d", &student.studentID);
    getchar();
    printf("Enter student name: ");
    gets(student.name);
    printf("Enter date of birth: ");
    gets(student.birthday);
    printf("Enter the course:");
    gets(student.course);
    printf("Enter the class: ");
    gets(student.class);
    listStudents[numStudents++] = student;
    printf ("Add new student successful\n\n ");
}

int updateStudentByID()
{
    int id;
    char tempName[30],tempBirthday[30],tempCourse[30],tempclass[30];
    printf("\nEnter the id of student you want to find: ");
    scanf("%d", &id);
    getchar();
    for (int i=0; i < numStudents ; i++)
    {
        if (id == listStudents[i].studentID)
        {
            printf("Enter student name: ");
            gets(tempName);
            strcpy(listStudents[i].name,tempName);
            printf("Enter date of birth: ");
            gets(tempBirthday);
            strcpy(listStudents[i].birthday,tempBirthday);
            printf("Enter the course: ");
            gets(tempCourse);
            strcpy(listStudents[i].course,tempCourse);
            printf("Enter the class: ");
            gets(tempclass);
            strcpy(listStudents[i].class,tempclass);
            printf("Update student with id %d successful\n\n", id);
            return 1;
        }
    }
    printf("Cannot update student with id %d\n\n",id);
    return 0;
}

int searchStudent()
{
    int id;
    char tempName[30];
    char tempClass[30];

    int choice = 0;

    printf("=============== SEARCH MENU ===============\n");
    printf("1. Search student by id.\n");
    printf("2. Search student by name.\n");
    printf("3. Search student by class.\n");
    printf("0. Exit.\n");
    printf("Your choose ? ");

    scanf("%d", &choice);
    getchar();

    switch(choice)
    {
    case 0:
        break;

    case 1:
        
        printf("\nEnter the id of the student you want to find: ");
        scanf("%d", &id);
        for(int i=0; i < numStudents; i++)
        {
            if (id == listStudents[i].studentID)
            {
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                printf("%-20s%-30s%-30s%-30s%-20s\n","Student ID","Student Name","Date of birth","Course","Class");
                printf("%-20d%-30s%-30s%-30s%-20s\n",listStudents[i].studentID,listStudents[i].name,listStudents[i].birthday,listStudents[i].course,listStudents[i].class);
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                return 1;
            }
        }
        printf("Cannot found student with id %d\n\n",id);
        return 0;

    case 2:
        
        printf("\nEnter the name of the student you want to find: ");
        gets(tempName);
        for(int i=0; i < numStudents; i++)
        {
            if (strcmp(tempName, listStudents[i].name) == 0)
            {
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                printf("%-20s%-30s%-30s%-30s%-20s\n","Student ID","Student Name","Date of birth","Course","Class");
                printf("%-20d%-30s%-30s%-30s%-20s\n",listStudents[i].studentID,listStudents[i].name,listStudents[i].birthday,listStudents[i].course,listStudents[i].class);
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                return 1;
            }
        }
        printf("Cannot found student with name %s\n\n",tempName);
        return 0;

    case 3:
        
        printf("\nEnter the class of the student you want to find: ");
        gets(tempClass);
        for(int i=0; i < numStudents; i++)
        {
            if (strcmp(tempClass, listStudents[i].class) == 0)
            {
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                printf("%-20s%-30s%-30s%-30s%-20s\n","Student ID","Student Name","Date of birth","Course","Class");
                printf("%-20d%-30s%-30s%-30s%-20s\n",listStudents[i].studentID,listStudents[i].name,listStudents[i].birthday,listStudents[i].course,listStudents[i].class);
                printf("------------------------------------------------------------"
                    "-----------------------------------------------------------------------\n");
                return 1;
            }
        }
        printf("Cannot found student with class %s\n\n",tempClass);
        return 0;

    default:
        printf("Wrong function, please choose again!\n");
        break;
    }
}

void viewListStudents()
{
    printf("------------------------------------------------------------"
           "-----------------------------------------------------------------------\n");
    printf("%-20s%-30s%-30s%-30s%-20s\n","Student Id","Student name","Date of birth","Course","Class");
    for(int i = 0; i < numStudents; i++)
    {
        printf("%-20d%-30s%-30s%-30s%-20s\n",listStudents[i].studentID,listStudents[i].name,listStudents[i].birthday,listStudents[i].course,listStudents[i].class);
    }
    printf("-------------------------------------------------------------"
           "----------------------------------------------------------------\n");
}

void sortByClass()
{

    for (int i=0 ; i < numStudents; i++)
    {
        for (int j= numStudents - 1; j > i; j--)
        {
            if (strcmp(listStudents[j].class,listStudents[j-1].class) < 0)
            {
                struct Student tempSV = listStudents[j];
                listStudents[j] = listStudents[j - 1];
                listStudents[j - 1] = tempSV;
            }
        }
    }
}

int main()
{
    int choice = 0;
    readFile();
    viewListStudents();

    do
    {
        printf("=============== MENU ===============\n");
        printf("1. Add student.\n");
        printf("2. Update student.\n");
        printf("3. Sort list.\n");
        printf("4. Search student.\n");
        printf("0. Exit.\n");
        printf("Your choose ? ");

        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 0:
            break;

        case 1:
            addStudent();
            writeFile();
            break;

        case 2:
            updateStudentByID();
            writeFile();
            break;

        case 3:
            sortByClass();
            writeFile();
            break;

        case 4:
            searchStudent();
            break;

        default:
            printf("Wrong function, please choose again!\n");
            break;
        }

    }
    while(choice);
    return 0;
}




























