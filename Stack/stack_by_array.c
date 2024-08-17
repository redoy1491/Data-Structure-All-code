/**Queue implementation using array*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 20

int stack[n];
int top = -1;

void push(int id)
{
    if (top >= n - 1)
        printf("\n\t\t\tStack is overflowing\n");
    else
    {
        top++;
        stack[top] = id;
        printf("\n\t\t\t%d id is stored\n", id);
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void pop()
{
    if (top == -1)
        printf("\n\t\t\tQueue is empty\n");
    else
    {
        printf("\n\t\t\t%d id is poped\n", stack[top]);
        top--;
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void display()
{
    if (top == -1)
        printf("\n\t\t\tQueue is empty\n");
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n\t\t\tID : %d", stack[i]);
        }
    }

    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n\n\t\t\tStack implementation using array");
        printf("\n\n\n\t\t\t1.Insert element to Stack\n");
        printf("\t\t\t2.Delete element from Stack\n");
        printf("\t\t\t3.Display all elements of Stack\n");
        printf("\t\t\t4.Quit\n");
        printf("\n\t\t\tEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int id;
            printf("\n\t\t\tEnter Your ID : ");
            scanf("%d", &id);
            push(id);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
        {
            printf("\n\t\t\texit....\n");
            exit(4);
            break;
        }
        default:
            printf("\n\t\t\tWrong choice\n");
        }
    }
}