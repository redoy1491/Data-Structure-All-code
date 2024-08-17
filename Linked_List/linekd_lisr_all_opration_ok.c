// Linked List all problem by me

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct Customer_List
{
    char name[40];
    int age;
    char sex;
    struct Customer_List *next;
} customer;

void Insert(customer *pointer, char name1[], int age1, char sex1)
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = (customer *)malloc(sizeof(customer));
    pointer = pointer->next;
    strcpy(pointer->name, name1);
    pointer->age = age1;
    pointer->sex = sex1;
    pointer->next = NULL;

    printf("\nData Insert Successfully\nName : %s\nAge : %d\nSex : %c\n", name1, age1, sex1);
}

void delete_by_name(customer *pointer, char name1[])
{
    customer *temp;
    int flag = 0;
    while (pointer->next != NULL) // go to the all node one by one(traversing)
    {
        if (strcmp(pointer->next->name, name1) == 0) // jei node delete korbo tar ager node theke take refrence korbo
        {
            temp = pointer->next;       // 1st----jei node delete korbo take point korbo
            pointer->next = temp->next; // 2nd-----porer node er shahte ager node er link connent korbo
            flag = 1;
            break; // 4th delete houe gele loop theke ber hoye jabo
        }
        pointer = pointer->next; // prottek node a jawar jonno link update korte hobe
    }
    if (flag == 0)
    {
        printf("\"%s\" is not present at the list\n", name1);
        return;
    }

    free(temp); // 3rd-----point kore node ke delete korbo
    printf("\"%s\" Datails is removed Successfully\n");
    return;
}

void Find(customer *pointer, char name1[])
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
        if (strcmp(pointer->name, name1) == 0)
        {
            printf("Customer Found\n");
            return;
        }
    }
    if (pointer->next = NULL)
    {
        printf("\"%s\" is not present at the list\n", name1);
        return;
    }
}

void Print_All(customer *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    printf("Name : %s\nAge : %d\nSex : %c\n", pointer->name, pointer->age, pointer->sex);
    Print_All(pointer->next);
}

void Update_customer_datail(customer *pointer, char name1[])
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
        if (strcmp(pointer->name, name1) == 0)
        {
            printf("Customer Found\n");
            printf("Enter New Name : ");
            gets(pointer->name);
            fflush(stdin);
            printf("Enter New Age : ");
            scanf("%d", &pointer->age);
            fflush(stdin);
            printf("Enter New Sex : ");
            scanf(" %c", &pointer->sex);
            fflush(stdin);
            printf("Data Updated Successfully\n");
        }
    }
    if (pointer->next = NULL)
    {
        printf("\"%s\" is not present at the list\n", name1);
        return;
    }
}

void Customer_count(customer *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    int count = 0;
    while (pointer != NULL)
    {
        count++;
        pointer = pointer->next;
    }
    printf("Total Customer Number : %d", count);
}

void Count_By_Age(customer *pointer, int age1)
{
    int count = 0;
    if (pointer == NULL)
    {
        return;
    }
    while (pointer != NULL)
    {
        if (pointer->age == age1)
        {
            count++;
        }
        pointer = pointer->next;
    }
    printf("No of Customers of %d: %d ", age1, count);
}

void Count_By_Sex(customer *pointer, char sex1)
{
    int count = 0;
    if (pointer == NULL)
    {
        return;
    }
    while (pointer != NULL)
    {
        if (pointer->sex == sex1)
        {
            count++;
        }
        pointer = (pointer->next);
    }
    printf("No of Customers of %c : %d ", sex1, count);
}

int main()
{
    customer *head, *temp;
    head = (customer *)malloc(sizeof(customer));
    temp = head;
    temp->next = NULL;

    printf("Menu Option for Single Link List\n\n");

    while (1)
    {
        printf("\nMain Menu\n");
        printf("=========\n");
        printf("1. Insert customer details\n");
        printf("2. Delete customer detail\n");
        printf("3. Find Customer detail\n");
        printf("4. Print customer detail\n");
        printf("5. Update customer detail\n");
        printf("6. Count customer\n");
        printf("7. Count customer by Age\n");
        printf("8. Count customer by Sex\n");
        printf("9. Exit\n");

        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            system("cls");
            printf("\nInsert customer details\n");
            int age;
            char name[40], sex;
            fflush(stdin);
            printf("Enter Name : ");
            gets(name);
            fflush(stdin);
            printf("Enter Age : ");
            scanf("%d", &age);
            fflush(stdin);
            printf("Enter Sex : ");
            scanf("%c", &sex);
            fflush(stdin);
            Insert(head, name, age, sex);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            printf("\nDelete customer detail\n");
            char name[40];
            fflush(stdin);
            printf("Enter Name : ");
            fflush(stdin);
            gets(name);
            delete_by_name(head, name);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            printf("\nFind Customer detail\n");
            char name[40];
            fflush(stdin);
            printf("Enter Name : ");
            gets(name);
            Find(head, name);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\nPrint customer detail\n");
            printf("The List Is :\n");
            Print_All(head->next);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            printf("\nUpdate customer detail\n");
            char name[40];
            fflush(stdin);
            printf("Enter Name : ");
            gets(name);
            Update_customer_datail(head, name);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 6:
        {
            system("cls");
            printf("\nCount customer by Age\n");
            printf("\nCount customer\n");
            Customer_count(head->next);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 7:
        {
            system("cls");
            int age;
            printf("Enter Age : ");
            scanf("%d", &age);
            Count_By_Age(head->next, age);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 8:
        {
            system("cls");
            printf("\nCount customer by Sex\n");
            char sex;
            printf("Enter Sex : ");
            scanf(" %c", &sex);
            fflush(stdin);
            Count_By_Sex(head->next, sex);
            printf("Enter any key for main menu...");
            getch();
            system("cls");
            break;
        }
        case 9:
            printf("\nProgram End\n");
            exit(9);
        }
    }
}
