#include <stdio.h>

#define n 10

int stack1[n], stack2[n];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == n - 1)
    {
        printf("Queue Is Overflow\n");
    }
    else
    {
        top1++;
        stack1[top1] = data;
    }
}
int pop1()
{
    return stack1[top1--];
}

int pop2()
{
    return stack2[top2--];
}

void push2(int data)
{
    if (top2 == n - 1)
    {
        printf("Overflow Condition\n");
    }
    else
    {
        top2++;
        stack2[top2] = data;
    }
}

void enqueue(int data)
{
    push1(data);
    count++;
}



void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Stack Is Empty\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
        int b = pop2();
        printf("First Out : %d\n", b);
        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}



void display()
{
    printf("Print All Value\n");
    for (int i = 0; i <= top1; i++)
    {
        printf("Data : %d\n", stack1[i]);
    }
}

int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();
    enqueue(7);
    display();
}