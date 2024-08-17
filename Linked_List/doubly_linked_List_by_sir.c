#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *head; // global variable - pointer to head node.

// Creates a new Node and returns pointer to it.
node *create_new_node(int x)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = x;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Inserts a Node at head of doubly linked list
void InsertAtHead(int x)
{
    node *new_node = create_new_node(x);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

// Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x)
{
    node *temp = head;
    node *new_node = create_new_node(x);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next; // Go To last Node
    temp->next = new_node;
    new_node->prev = temp;
}

// Prints all the elements in linked list in forward traversal order
void Print()
{
    node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Prints all elements in linked list in reverse traversal order.
void ReversePrint()
{
    node *temp = head;
    if (temp == NULL)
        return; // empty list, exit
    // Going to last Node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{

    /*test the implementation*/
    head = NULL; // empty list. set head as NULL.

    // Calling an Insert and printing list both in forward as well as reverse direction.
    InsertAtTail(2);
    Print();
    ReversePrint();
    InsertAtTail(4);
    Print();
    ReversePrint();
    InsertAtHead(6);
    Print();
    ReversePrint();
    InsertAtTail(8);
    Print();
    ReversePrint();
}
