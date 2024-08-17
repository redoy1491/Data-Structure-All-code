#include <stdio.h>
#include <stdlib.h>
typedef struct INNER
{
    int hieght_1;
    int width_1;
} inner_sq;
typedef struct OUTER
{
    int hieght;
    int width;
    inner_sq *small_sq;
    struct OUTER *next;
} outer_sq;
void push(outer_sq *pointer);
void pop(outer_sq *pointer);
void display(outer_sq *pointer);

int main()
{
    outer_sq *head = (outer_sq *)malloc(sizeof(outer_sq));
    head->next = NULL;
    while (1)
    {
        system("cls");

        printf("   ||MENU||\n");
        printf("1. Push Square\n");
        printf("2. Pop Square \n");
        printf("3. Display \n");
        printf("4. Exit\n");
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
            display(head->next);
            break;
        case 4:
            return 0;
        }
        fflush(stdin);
        printf("\nPress Enter To Continue...");
        getchar();
    }
}
void push(outer_sq *pointer)
{
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }

    pointer->next = (outer_sq *)malloc(sizeof(outer_sq));
    pointer = pointer->next;
    pointer->small_sq = (inner_sq *)malloc(sizeof(inner_sq));

    printf("Outer Square:\n>>");
    printf("Height:");
    scanf(" %d", &pointer->hieght);
    printf("Width:");
    scanf(" %d", &pointer->width);
    printf("Inner square:\n>>");
    printf("Height:");
    scanf(" %d", &pointer->small_sq->hieght_1);
    printf("Width:");
    scanf(" %d", &pointer->small_sq->width_1);
    printf("Successfully Inputted\n");

    pointer->next = NULL; // End marker diye dewa for future use
}
void pop(outer_sq *pointer)
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
    printf("H main = %d W main = %d\n", pointer->next->hieght, pointer->next->width);
    printf("H small = %d W small = %d\n", pointer->next->small_sq->hieght_1, pointer->next->small_sq->width_1);
    free(pointer->small_sq);
    free(pointer->next);
    pointer->next = NULL;
}
void display(outer_sq *pointer)
{
    if (pointer == NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack Data:");
    while (pointer != NULL)
    {
        printf("\nH main = %d W main = %d\n", pointer->hieght, pointer->width);
        printf("H small = %d W small = %d\n", pointer->small_sq->hieght_1, pointer->small_sq->width_1);
        pointer = pointer->next;
    }
    printf("\n\n");
}
