// palindrome by using stack & queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for stack
struct StackNode
{
    char data;
    struct StackNode *next;
};

// Node structure for queue
struct QueueNode
{
    char data;
    struct QueueNode *next;
};

// Stack functions
struct StackNode *createStackNode(char data)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct StackNode **top, char data)
{
    struct StackNode *newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

char pop(struct StackNode **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    struct StackNode *temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Queue functions
struct QueueNode *createQueueNode(char data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct QueueNode **front, struct QueueNode **rear, char data)
{
    struct QueueNode *newNode = createQueueNode(data);
    if (*front == NULL)
    {
        *front = newNode;
    }
    else
    {
        (*rear)->next = newNode;
    }
    *rear = newNode;
}

char dequeue(struct QueueNode **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return '\0';
    }
    struct QueueNode *temp = *front;
    *front = (*front)->next;
    char dequeued = temp->data;
    free(temp);
    return dequeued;
}

// Palindrome check function
void isPalindrome(char *str)
{
    struct StackNode *stackTop = NULL;
    struct QueueNode *queueFront = NULL;
    struct QueueNode *queueRear = NULL;

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(&stackTop, str[i]);
        enqueue(&queueFront, &queueRear, str[i]);
    }

    while (stackTop != NULL && queueFront != NULL)
    {
        char stackChar = pop(&stackTop);
        char queueChar = dequeue(&queueFront);
        if (stackChar != queueChar)
        {
            printf("%s is not a palindrome.\n", str);
            return;
        }
    }

    printf("%s is a palindrome.\n", str);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    isPalindrome(str);

    return 0;
}
