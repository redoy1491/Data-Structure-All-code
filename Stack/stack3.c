#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK
{
    char foodname[50];
    float price;
    struct STACK *next;
} stack;

void push(stack *pointer);
void pop(stack *pointer);
int count(stack *pointer);
void search_food(stack *pointer);
void highest_priced_food(stack *pointer);
void lowest_priced_food(stack *pointer);
//---------------
int main()
{
    stack *head = (stack *)malloc(sizeof(stack));
    head->next = NULL;
    while (1)
    {
        system("cls");

        printf("   ||MENU||\n");
        printf("   --------\n");
        printf("1. Push FOOD ITEM\n");
        printf("2. Pop FOOD ITEM\n");
        printf("3. Count FOOD ITEM\n");
        printf("4. Search FOOD ITEM\n");
        printf("5. Lowest Priced Food product\n");
        printf("6. Highest Priced Food product\n");
        printf("7. Exit\n");
        printf("Enter Your choice : ");
        int ch;
        scanf(" %d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            push(head);   //insert at end a node
            break;
        case 2:
            pop(head);    //delete at last data 
            break;
        case 3:
            printf("Number of FOOD ITEM:%d\n", count(head->next));
            break;
        case 4:
            search_food(head->next);
            break;
        case 5:
            lowest_priced_food(head->next);
            break;
        case 6:
            highest_priced_food(head->next);
            break;
        case 7:
            return 0;
        }
        fflush(stdin);
        printf("\nPress Enter To Continue...");
        getchar();
    }
}
void push(stack *pointer)
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }

    pointer->next = (stack *)malloc(sizeof(stack));
    pointer = pointer->next;

    printf("FOODNAME : ");
    scanf(" %[^\n]s", pointer->foodname);
    fflush(stdin);

    printf("Price : ");
    scanf(" %f", &pointer->price);
    fflush(stdin);

    printf("Successfully Inputted\n");

    pointer->next = NULL; // End marker diye dewa for future use
}
void pop(stack *pointer)
{
    if (pointer->next == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while (pointer->next->next != NULL)
    {
        pointer = pointer->next;
    }
    printf("Successfully Popped The Last Data\n");
    printf("1.FOOD title: %s\n", pointer->next->foodname);
    printf("2.FOOD PRICE: %.2f\n", pointer->next->price);
    free(pointer->next); // free memory of last node
    pointer->next = NULL;
}
int count(stack *pointer)
{
    if (pointer == NULL)
    {
        return 0;
    }
    int count = 0;
    while (pointer != NULL)
    {
        pointer = pointer->next;
        count++;
    }
    return count;
}
void search_food(stack *pointer)
{
    if (pointer == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Enter Food name: \n>>");
    char name[50];
    fflush(stdin);
    scanf(" %[^\n]", name);
    fflush(stdin);
    int found = 0;
    while (pointer != NULL)
    {
        if (strcmp(pointer->foodname, name) == 0)
        {
            found = 1;
            printf("FOOD Found\n");
            printf("1.FOOD NAME: %s\n", pointer->foodname);
            printf("2.FOOD Price: %.2f\n", pointer->price);
            break;
        }
        pointer = pointer->next;
    }
    if (!found)
    {
        printf("FOOD not found\n");
    }
}
void lowest_priced_food(stack *pointer)
{
    if (pointer == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    stack *temp = (stack *)malloc(sizeof(stack));
    temp = pointer;
    while (pointer != NULL)
    {
        if (temp->price > pointer->price)
        {
            temp = pointer;
        }
        pointer = pointer->next;
    }
    printf("Lowest price food is:\n");
    printf("Name: %s\n", temp->foodname);
    printf("Price: %.2f\n", temp->price);
}
void highest_priced_food(stack *pointer)
{
    if (pointer == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    stack *temp = (stack *)malloc(sizeof(stack));
    temp = pointer;
    while (pointer != NULL)
    {
        if (temp->price < pointer->price)
        {
            temp = pointer;
        }
        pointer = pointer->next;
    }
    printf("Highest price food is:\n");
    printf("Name: %s\n", temp->foodname);
    printf("Price: %.2f\n", temp->price);
}
