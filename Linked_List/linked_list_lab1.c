// ALL in one
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Custom
{
    char name[50];
    int age;
    char sex;
    struct Custom *next;
} custom;

void insert(custom *pointer, char name[], int age, char sex)
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = (custom *)malloc(sizeof(custom));
    pointer = pointer->next;
    strcpy(pointer->name, name);
    pointer->age = age;
    pointer->sex = sex;
    pointer->next = NULL;

    printf("data Inserted!\n");
}

void delete(custom *pointer, char name[])
{
    while ((pointer->next != NULL) && strcmp((pointer->next->name), name) == 1)
    {
        pointer = pointer->next;
    }
    if (pointer->next == NULL)
    {
        printf("%s is not present in the list\n", name);
        return;
    }
    custom *temp;
    temp = pointer->next;

    pointer->next = temp->next;

    free(temp);

    printf("data element deleted!\n");
    return;
}

void print(custom *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    printf("Name: %s\n", pointer->name);
    printf("Age: %d\n", pointer->age);
    printf("Sex: %c\n", pointer->sex);
    print(pointer->next);
}
void find(custom *pointer, char name[])
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
        if (strcmp(pointer->name, name) == 0)
        {
            printf("Customer Found\n");
            return;
        }
    }
    if (pointer->next == NULL)
    {
        printf("%s is not present in the list\n", name);
        return;
    }
}
void update(custom *pointer, char name[])
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
        if (strcmp(pointer->name, name) == 0)
        {
            printf("Customer Found\n");
            printf("Enter new Name:");
            scanf(" %s", pointer->name);
            printf("Enter new Age:");
            scanf("%d", &pointer->age);
            printf("Enter new Sex:");
            scanf(" %c", &pointer->sex);
            printf("Data updated");
            return;
        }
    }
    if (pointer->next == NULL)
    {
        printf("%s is not present in the list\n", name);
        return;
    }
}

void countcustomer(custom *pointer)
{
    int count = 0;
    if (pointer == NULL)
    {
        return;
    }

    while (pointer != NULL)
    {
        count++;
        pointer = pointer->next;
    }

    printf("No of Customers: %d ", count);
}
void countcustomer1(custom *pointer, int age)
{
    int count = 0;
    if (pointer == NULL)
    {
        return;
    }

    while (pointer != NULL)
    {
        if (pointer->age == age)
            count++;
        pointer = pointer->next;
    }

    printf("No of Customers of %d: %d ", age, count);
}
void countcustomer2(custom *pointer, char sex)
{
    int count = 0;
    if (pointer == NULL)
    {
        return;
    }

    while (pointer != NULL)
    {
        if (pointer->sex == sex)
            count++;
        pointer = pointer->next;
    }

    printf("No of Customers of %c: %d ", sex, count);
}
int main()
{

    custom *start, *temp;
    start = (custom *)malloc(sizeof(custom));
    temp = start;
    temp->next = NULL;

    printf("Menu Option for Single Link List\n");

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Insert customer\n");
        printf("2. Delete customer\n");
        printf("3. Find Customer\n");
        printf("4. Print customer\n");
        printf("5. Update customer\n");
        printf("6. Count customer\n");
        printf("7. Count customer by Age\n");
        printf("8. Count customer by Sex\n");
        printf("9. Exit\n");

        int query;
        printf("Enter your choice:");
        scanf("%d", &query);
        if (query == 1)
        {
            int age;
            char name[100], sex;
            printf("Enter Name:");
            scanf(" %s", name);
            printf("Enter Age:");
            scanf("%d", &age);
            printf("Enter Sex:");
            scanf(" %c", &sex);
            insert(start, name, age, sex);
        }

        else if (query == 2)
        {
            char name[100];
            printf("Enter Name:");
            scanf(" %s", name);
            delete (start, name);
        }
        else if (query == 3)
        {
            char name[100];
            printf("Enter Name:");
            scanf(" %s", name);
            find(start, name);
        }
        else if (query == 4)
        {
            printf("The list is: \n");
            print(start->next);
            printf("\n");
        }
        else if (query == 5)
        {
            char name[100];
            printf("Enter Name:");
            scanf(" %s", name);
            update(start, name);
        }

        else if (query == 6)
        {
            countcustomer(start->next);
            printf("\n");
        }
        else if (query == 7)
        {
            int age;
            printf("Insert Age: ");
            scanf("%d", &age);
            countcustomer1(start->next, age);
            printf("\n");
        }
        else if (query == 8)
        {
            char sex;
            printf("Insert Sex: ");
            scanf("%s", &sex);
            countcustomer2(start->next, sex);
            printf("\n");
        }
        else if (query == 9)
        {
            break;
        }
    }
}
