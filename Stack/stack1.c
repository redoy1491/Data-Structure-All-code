#include <stdio.h>
#include <stdlib.h>

typedef struct STACK
{
    int serial_number;
    char title[50];
    char publisher[50];
    struct STACK *next;
} stack;

void push(stack *pointer);
void pop(stack *pointer);
int count(stack *pointer);
void search_book(stack *pointer);
//---------------
int main()
{
    stack *head = (stack *)malloc(sizeof(stack));
    head->next = NULL;
    while (1)
    {
        system("cls");

        printf("   ||MENU||\n");
        printf("1. Push Book\n");
        printf("2. Pop Book\n");
        printf("3. Count Book\n");
        printf("4. Search Book\n");
        printf("5. Exit\n");
        int ch;
        scanf(" %d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            push(head);
            break;
        case 2:
            pop(head);
            break;
        case 3:
            printf("Number of books:%d\n", count(head->next));
            break;
        case 4:
            search_book(head->next);
            break;
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
    // linked list er seshe node create
    pointer->next = (stack *)malloc(sizeof(stack));
    pointer = pointer->next;

    printf("Serial Number:\n>>");
    scanf(" %d", &pointer->serial_number);
    fflush(stdin);

    printf("Title:\n>>");
    scanf(" %[^\n]s", pointer->title);
    fflush(stdin);

    printf("Publisher: \n>>");
    scanf(" %[^\n]s", pointer->publisher);
    fflush(stdin);
    printf("Successfully Input");

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
    printf("Serial Number: %d\n", pointer->next->serial_number);
    printf("Book title: %s\n", pointer->next->title);
    printf("Book Publisher: %s\n", pointer->next->publisher);
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
void search_book(stack *pointer)
{
    if (pointer == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Enter serial Number: \n>>");
    int serial;
    scanf(" %d", &serial);
    fflush(stdin);
    int found = 0;
    while (pointer != NULL)
    {
        if (pointer->serial_number == serial)
        {
            found = 1;
            printf("Book Found\n");
            printf("1.Book title: %s\n", pointer->title);
            printf("2.Book Publisher: %s\n", pointer->publisher);
            break;
        }
        pointer = pointer->next;
    }
    if (!found)
    {
        printf("Book not found\n");
    }
}