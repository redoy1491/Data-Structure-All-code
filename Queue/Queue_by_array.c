/**Queue implementation using array*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 20

int queue[n];
int front = -1;
int rear = -1;

void do_enqueue(int id)
{
    if ((front == -1) && (rear == -1))
    {
        front = 0;
        rear = 0;
        queue[rear] = id;
        printf("\n\t\t\t-id is strode\n");
    }

    else if (rear == n - 1)
    {
        printf("\n\t\t\tQueue is overflowing\n");
    }
    else
    {
        rear++;
        queue[rear] = id;
        printf("\n\t\t\tid is strode\n");
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
        printf("\n\t\t\tQueue is empty\n");

    else if (front == rear)
        {
            printf("\n\t\t\t%d is dequeue\n", queue[rear]);
            front=rear=-1;
        }
    else
    {
        printf("\n\t\t\t%d is dequeue\n", queue[front]);
        front++;
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void display()
{
    if (front == -1 && rear == -1)
        printf("\n\t\t\tQueue is empty\n");

    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("\n\t\t\tData : %d ", queue[i]);
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
        printf("\n\n\n\t\t\tQueue implementation using array");
        printf("\n\n\n\t\t\t1.Insert element to queue\n");
        printf("\t\t\t2.Delete element from queue\n");
        printf("\t\t\t3.Display all elements of queue\n");
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
            do_enqueue(id);
            break;
        }
        case 2:
            dequeue();
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