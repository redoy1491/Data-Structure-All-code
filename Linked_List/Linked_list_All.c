#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    int data;
    struct Node *next;
} node;

int menu(void)
{
    system("cls");
    int op;
    printf("Linked List Operations\n");
    printf("---------------------------------\n");
    printf("1. Add element at end\n");        // ok
    printf("2. Add element at front\n");      // ok
    printf("3. Add element in after Node\n"); // ok
    /*
    //This Option has some potential problem that is not important for practical usage.
    //So, this fun work will we covered in another video if you want.
    printf("4. Add element in before Node\n");//ok
    */
    printf("5. Delete element from end\n");   // ok
    printf("6. Delete element from front\n"); // ok
    printf("7. Delete element\n");            // ok
    printf("8. Show all\n");                  // ok
    printf("9. Search info by Node id\n");    // ok
    printf("10. Show total number of Data nodes\n");
    printf("0. Exit\n");

    scanf("%d", &op);
    return op;
}

void add_end(node *head)
{
    system("cls");
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = temp;
}

void add_front(node **head)
{
    system("cls");
    printf("Adding in the front:\n");
    printf("---------------------------\n\n");
    node *temp;
    temp = (node *)malloc(sizeof(node));

    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);

    temp->next = *head; ///*(add_of_head) == add_of_first_node
    *head = temp;
}

void add_after(node *head)
{
    system("cls");
    printf("Enter The Node Data to insert new node after: ");
    int data;
    scanf("%d", &data);

    while (head->data != data)
    {
        head = head->next;

        if (head == NULL)
        {
            printf("\nDesired data not found. Please try again!\n\n\n");
            system("pause");
            return;
        }
    }

    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);

    temp->next = head->next;
    head->next = temp;
}

/*
void add_before(node *head, node**list_adr)
{
    system("cls");
    printf("Enter The Node Data to insert new node before: ");
    int data;
    scanf("%d", &data);

    if(head->data == data)
    {
        printf("Your Entered data was the first element of the head. SO,\n");
        system("pause");
        add_front(list_adr);
    }
    else if(head->next == NULL)
    {
        printf("\nDesired data not found. Please try again!\n\n\n");
        system("pause");
        return;
    }
    else
    {
        while(head->next->data != data)
        {
            head =head->next;

            if(head == NULL)
            {
                printf("\nDesired data not found. Please try again!\n\n\n");
                system("pause");
                return;
            }
        }

        node *temp;
        temp = (node*)malloc(sizeof(node));
        printf("Id: ");
        scanf("%d", &temp->id);
        printf("Data: ");
        scanf("%d", &temp->data);

        temp->next = head->next;
        head->next = temp;
    }
}
*/
void delete_end(node *head)
{
    system("cls");
    printf("Deleting from end\n");
    printf("---------------------\n");

    while (head->next->next != NULL)
    {
        head = head->next;
    }
    node *temp;
    temp = head->next;
    head->next = NULL;
    free(temp);
    printf("Data from end has been freed!\n");

    system("pause");
}

void delete_front(node **head)
{
    node *temp;

    temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
    printf("Data from front has been freed!\n");
    system("pause");
}

void delete_data(node *head)
{
    system("cls");
    printf("Enter The Node Data you want to delete: ");
    int data;
    scanf("%d", &data);

    if (head->data == data)
    {
        printf("\nYour data is in the front of the linked head.\nPlease use option 6 to delete the node.\n\n\n");
        system("pause");
        return;
    }
    /*else if(head->next == NULL)
    {
        printf("\nEntered data not found. Please Try Again!\n\n\n");
        system("pause");
        return;
    }*/

    node *temp;
    while (head != NULL && head->next != NULL)
    {
        if (head->next->data == data)
        {
            temp = head->next;
            head->next = temp->next;
            temp->next = NULL;

            free(temp);
            printf("Data: %d has been removed!\n\n\n", data);
            system("pause");
            return;
        }
        head = head->next;
    }
    printf("\nEntered data not found. Please Try Again!\n\n\n");
    system("pause");
}

void search_node(node *head)
{
    system("cls");
    printf("Enter node id to search: ");
    int id;
    scanf("%d", &id);

    while (head->id != id)
    {
        head = head->next;

        if (head == NULL)
        {
            printf("Entered Node not found. Please Try again!\n\n\n");
            system("pause");
            return;
        }
    }

    printf("Node Found!\n\n");
    printf("Node ID: %d\n", head->id);
    printf("Node Data: %d\n\n\n", head->data);

    system("pause");
}

void total_nodes(node *head)
{
    system("cls");
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    printf("There are total of %d node(s) in the linked head.\n\n\n", count);

    system("pause");
}

void display_all(node *head)
{
    system("cls");
    printf("All Data with ID\n");
    printf("-----------------------\n");

    if (head == NULL)
    {
        printf("The List is empty.\n");
        system("pause");
        return;
    }
    else
    {
        while (head != NULL)
        {
            printf("ID-%d \t Data-%d\n", head->id, head->data);
            head = head->next;
        }
    }
    system("pause");
}

int main(void)
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->id = 1000;
    head->data = 0;
    head->next = NULL;

    int op;
    while (1)
    {
        int op = menu();
        if (op == 0)
        {
            free(head);
            break;
        }

        switch (op)
        {
        case 1:
            add_end(head);
            break;
        case 2:
            add_front(&head);
            break;
        case 3:
            add_after(head);
            break;
        /*case 4:
            add_before(head, &head);
            break;*/
        case 5:
            delete_end(head);
            break;
        case 6:
            delete_front(&head);
            break;
        case 7:
            delete_data(head);
            break;
        case 8:
            display_all(head);
            break;
        case 9:
            search_node(head);
            break;
        case 10:
            total_nodes(head);
            break;
        case 11:
            break;
        }
    }

    return 0;
}
