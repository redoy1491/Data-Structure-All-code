// Linked List Student Project
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Sudent_Datels
{
    int id;
    char name[40];
    // char depatrment[30];
    // int age;
    float cgpa;
    // char addres[30];
    struct Sudent_Datels *next;
} student;

void add_new_student(student *ptr)
{
    system("cls");
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = (student *)malloc(sizeof(student));
    ptr = ptr->next;
    printf("\n\n\n\t\t\tEnter Student ID : ");
    fflush(stdin);
    scanf("%d", &ptr->id);
    printf("\t\t\tEnter Student Name : ");
    fflush(stdin);
    scanf("%[^\n]s", ptr->name);
    printf("\t\t\tEnter Student CGPA : ");
    fflush(stdin);
    scanf("%f", &ptr->cgpa);
    ptr->next = NULL;
    printf("\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

void view_all_record(student *ptr)
{
    system("cls");
    if (ptr->next == NULL)
    {
        printf("\n\n\n\t\t\tThe List Empty\n");
    }
    int i = 1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        printf("\n\n\n\t\t\tStdent %d Information :\n", i);
        printf("\t\t\tID : %d\n", ptr->id);
        printf("\t\t\tName : %s\n", ptr->name);
        printf("\t\t\tCGPA : %.2f\n", ptr->cgpa);
        i++;
    }
    printf("\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

void dalete_record(student *ptr)
{
    system("cls");
    student *temp;
    int flag = 0;
    fflush(stdin);
    printf("\n\n\n\t\t\tEnter Name To Delete : ");
    char test_name[40];
    scanf("%[^\n]s", &test_name);
    while (ptr->next != NULL)
    {
        if (strcmp(ptr->next->name, test_name) == 0)
        {
            flag = 1;
            temp = ptr->next;
            ptr->next = temp->next;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
    {
        printf("\n\n\n\t\t\tList Is Empty\n");
        printf("\n\t\t\tEnter Any Key To Continue : ");
        getch();
        system("cls");
    }
    free(temp);
    printf("\n\t\t\t\"%s\" Datails is removed Successfully\n", test_name);
    printf("\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

void update_record(student *ptr)
{
    system("cls");
    int flag = 0;
    fflush(stdin);
    printf("\n\n\n\t\t\tEnter Name To Update : ");
    char test_name[40];
    scanf("%[^\n]s", &test_name);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (strcmp(ptr->name, test_name) == 0)
        {
            printf("\t\t\tEnter Student New ID : ");
            fflush(stdin);
            scanf("%d", &ptr->id);
            printf("\t\t\tEnter Student New Name : ");
            fflush(stdin);
            scanf("%[^\n]s", ptr->name);
            printf("\t\t\tEnter Student New CGPA : ");
            fflush(stdin);
            scanf("%f", &ptr->cgpa);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\t\t\t\"%s\" is not present at the list\n", test_name);
        printf("\n\t\t\tEnter Any Key To Continue : ");
        getch();
        system("cls");
        return;
    }
    printf("\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

void search_record(student *ptr)
{
    system("cls");
    int flag = 0;
    fflush(stdin);
    printf("\n\n\n\t\t\tEnter Name To Search : ");
    char test_name[40];
    scanf("%[^\n]s", &test_name);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (strcmp(ptr->name, test_name) == 0)
        {
            printf("\n\n\n\t\t\tStdent Information :\n");
            printf("\t\t\tID : %d\n", ptr->id);
            printf("\t\t\tName : %s\n", ptr->name);
            printf("\t\t\tCGPA : %.2f\n", ptr->cgpa);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\t\t\t\"%s\" is not present at the list\n", test_name);
        printf("\n\t\t\tEnter Any Key To Continue : ");
        getch();
        system("cls");
        return;
    }
    printf("\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

void count_total_student(student *ptr)
{
    system("cls");
    int count = 0, flag = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
        flag = 1;
    }
    if (flag == 0)
    {
        printf("\n\n\n\t\t\tNumber Of Total Student is : %d", count);
        printf("\n\t\t\tEnter Any Key To Continue : ");
        getch();
        system("cls");
        return;
    }
    else
    {
        printf("\n\n\n\t\t\tNumber Of Total Student is : %d", count);
    }
    printf("\n\n\t\t\tEnter Any Key To Continue : ");
    getch();
    system("cls");
}

int main()
{
    student *head;
    head = (student *)malloc(sizeof(student));
    head->next = NULL;

    while (1)
    {
        // system("cls");
        printf("\n\n\n\t\t\t---->Menu<----\n");
        printf("\t\t\t==============\n\n");
        printf("\t\t\t1. Add New Student\n");
        printf("\t\t\t2. View All Record\n");
        printf("\t\t\t3. Delete Record\n");
        printf("\t\t\t4. Update Record\n");
        printf("\t\t\t5. Search Record\n");
        printf("\t\t\t6. Count Total Student\n");
        printf("\t\t\t0. Exit\n\n");
        printf("\t\t\tEnter Your Choice : ");
        // int choice;
        // scanf("%d", &choice);

        switch (getch())
        {
        case '1':
            add_new_student(head);
            break;
        case '2':
            view_all_record(head);
            break;
        case '3':
            dalete_record(head);
            break;
        case '4':
            update_record(head);
            break;
        case '5':
            search_record(head);
            break;
        case '6':
            count_total_student(head);
            break;
        case '0':
            exit(0);
            break;
        default:
            system("cls");
            printf("\n\n\n\t\t\tWrong Choice!!\n");
            printf("\n\t\t\tEnter Any Key To Continue : ");
            getch();
            system("cls");
        }
    }
}