/**Queue implementation using Lined List*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front = 0;
node *rear = 0;
void do_enqueue(int id)
{

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = id;
    new_node->next = NULL;

    if ((front == 0) && (rear == 0))
    {
        front = rear = new_node;
        printf("\n\t\t\t-id is strode\n");
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        printf("\n\t\t\tid is strode\n");
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void dequeue()
{
    node *temp = front;
    if ((front == 0) && (rear == 0))
        printf("\n\t\t\tQueue is empty\n");

    else
    {
        printf("\n\t\t\t%d is dequeue\n", front->data);
        front = front->next;
        free(temp);
    }
    printf("\n\t\t\tEnter any key for main menu....");
    getch();
    system("cls");
}

void display()
{
    node *temp = front;
    node *ptr = front;
    if ((front == 0) && (rear == 0))
        printf("\n\t\t\tQueue is empty\n");

    else
    {
        while (temp != NULL)
        {
            printf("\n\t\t\tData : %d ", temp->data);
            temp = temp->next;
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
        printf("\n\n\n\t\t\tQueue implementation using Linked List");
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