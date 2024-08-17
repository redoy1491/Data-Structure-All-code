#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int id;
    char name[40];
    struct Node *next;
    struct Node *prev;
} node;

node *head = NULL;

void add_new_node()
{
    node *ptr = head;
    node *new_node = (node *)malloc(sizeof(node));
    fflush(stdin);
    printf("\nEnter Student ID : ");
    scanf("%d", &new_node->id);
    fflush(stdin);
    printf("Enter Student Name : ");
    scanf("%[^\n]s", new_node->name);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = ptr = new_node;
        return;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
}

void view_all_node()
{
    int flag = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("Name : %s", ptr->name);
        printf("---ID : %d\n", ptr->id);
        ptr = ptr->next;
        flag = 1;
    }
    if (flag == 0)
    {
        printf("List Is Empty\n");
    }
}

void delete_node()
{
}

int main()
{

    while (1)
    {
        printf("\n->Doubly Linked List<-\n");
        printf("1.Add New Node\n");
        printf("2.View All Node\n");
        printf("3.Delete A Node\n");
        printf("Enter Your Choice : ");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_new_node();
            break;
        case 2:
            view_all_node();
            break;
        case 3:
            delete_node();
            break;
        }
    }
}

// void deleteCard(int value)
// {
//     struct Card *current = head;
//     while (current != NULL)
//     {
//         if (current->value == value)
//         {
//             if (current == head)
//             {
//                 head = current->next;
//                 if (head != NULL)
//                     head->prev = NULL;
//             }
//             else
//             {
//                 current->prev->next = current->next;
//                 if (current->next != NULL)
//                     current->next->prev = current->prev;
//             }
//             free(current);
//             return;
//         }
//         current = current->next;
//     }
// }