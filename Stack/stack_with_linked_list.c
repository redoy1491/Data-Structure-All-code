//stack using link list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void push(node *stack, int data)
{

    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    while(stack->next!=NULL)
    {
        stack=stack->next;
    }
    stack->next=temp;
    printf("%d inserted!\n", data);
}

int pop(node *stack)
{
    int data;
    node *temp;

    if(stack->next == NULL)
    {
        printf("Stack is empty \n");
        return -1;
    }

    while(stack->next->next!=NULL)
    {
        stack=stack->next;
    }
    temp=stack->next;
    data=temp->data;
    stack->next=temp->next; /// temp->next has NULL in it.

    free(temp);                        /// we are actually doing is
                            /// stack->next =  NULL;
    return data;
}

int main()
{
    // stack using linked list
    node *stack;
    stack=(node*)malloc(sizeof(node));
    stack->next=NULL;

    push(stack, 7);
    push(stack, 3);
    push(stack, 9);
    printf("popped out: %d \n", pop(stack));
    printf("popped out: %d \n", pop(stack));
    printf("popped out: %d \n", pop(stack));
    printf("popped out: %d \n", pop(stack));
    return 0;
}


