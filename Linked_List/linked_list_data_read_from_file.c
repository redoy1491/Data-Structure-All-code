
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Phone_Book
{
    char name[30];
    int number;
    struct Phone_Book *next;
} phone;

void Add_New_Contact(phone *ptr)
{
    system("cls");
    printf("\n\n\n\t\t\tAdd New Contact\n");
    printf("\t\t\t---------------\n");
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = (phone *)malloc(sizeof(phone));
    ptr = ptr->next;
    fflush(stdin);
    printf("\n\t\t\tEnter Name : ");
    scanf("%[^\n]s", ptr->name);
    fflush(stdin);
    printf("\t\t\tEnter Phone Nuber : ");
    scanf("%d", &ptr->number);


    FILE *file = fopen("read_data_and_load.txt", "a+");
    fprintf(file, "%s %d\n", ptr->name, ptr->number);
    fclose(file);

    
    ptr->next = NULL;
    printf("\n\n\t\t\tContact Saved Successfully!");
    printf("\n\n\t\t\tEnter Any Key To Continue...");
    getch();
    system("cls");
}

void View_All_Contact(phone *ptr)
{
    system("cls");
    printf("\n\n\n\t\t\tView All Contact\n");
    printf("\t\t\t----------------\n");
    int count = 0;
    if (ptr->next == NULL)
    {
        printf("\n\t\t\tList Is Empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            printf("\n\t\t\tContact : %d", count + 1);
            printf("\n\t\t\t------------");
            printf("\n\t\t\tName : %s\n", ptr->name);
            printf("\t\t\tNubmer : %d\n", ptr->number);
            count++;
        }
        printf("\n\t\t\tNumber of Contact Saved : %d\n", count);
    }
    printf("\n\n\t\t\tEnter Any Key To Continue...");
    getch();
    system("cls");
}

void Update_Contact(phone *ptr)
{
    system("cls");
    printf("\n\n\n\t\t\tUpdate Contact\n");
    printf("\t\t\t---------------\n");
    char test_name[30];
    fflush(stdin);
    printf("\n\t\t\tEnter Name : ");
    scanf("%[^\n]s", test_name);
    if (ptr->next == NULL)
    {
        printf("\n\t\t\tList Is Empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            if (strcmp(test_name, ptr->name) == 0)
            {
                fflush(stdin);
                printf("\n\t\t\tEnter New Name : ");
                scanf("%[^\n]s", ptr->name);
                fflush(stdin);
                printf("\n\t\t\tEnter New Phone Nuber : ");
                scanf("%d", &ptr->number);
                printf("\n\t\t\tContact Update Successfylly!");
            }
        }
    }
    printf("\n\n\t\t\tEnter Any Key To Continue...");
    getch();
    system("cls");
}

void Search_Contact(phone *ptr)
{
    system("cls");
    printf("\n\n\n\t\t\tSearch Contact\n");
    printf("\t\t\t--------------\n");
    char test_name[30];
    int flag = 0;
    if (ptr->next == NULL)
    {
        printf("\n\t\t\tList Is Empty\n");
    }
    else
    {
        fflush(stdin);
        printf("\n\t\t\tEnter Name : ");
        scanf("%[^\n]s", test_name);
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            if (strcmp(test_name, ptr->name) == 0)
            {
                flag = 1;
                printf("\n\t\t\tContact Found\n");
                printf("\n\t\t\tName : %s", ptr->name);
                printf("\n\t\t\tPhone Nuber : %d", ptr->number);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tNOt Found");
        }
    }
    printf("\n\n\t\t\tEnter Any Key To Continue...");
    getch();
    system("cls");
}

void Delete_Contact(phone *ptr)
{
    system("cls");
    printf("\n\n\n\t\t\tDelete Contact\n");
    printf("\t\t\t--------------\n");
    phone *temp;
    char test_name[30];
    int flag = 0;
    if (ptr->next == NULL)
    {
        printf("\n\t\t\tList Is Empty\n");
    }
    else
    {
        fflush(stdin);
        printf("\n\t\t\tEnter Name : ");
        scanf("%[^\n]s", test_name);
        while (ptr->next != NULL) // go to the all node one by one(traversing)
        {
            if (strcmp(ptr->next->name, test_name) == 0) // jei node delete korbo tar ager node theke take refrence korbo
            {
                flag = 1;
                temp = ptr->next;       // 1st----jei node delete korbo take point korbo
                ptr->next = temp->next; // 2nd-----porer node er shahte ager node er link connent korbo
                free(temp);             // 3rd-----point kore node ke delete korbo
                printf("\n\t\t\t\"%s\" Datails is removed Successfully\n", test_name);
                break; // 4th delete houe gele loop theke ber hoye jabo
            }
            ptr = ptr->next; // prottek node a jawar jonno link update korte hobe
        }
        if (flag == 0)
        {
            printf("\n\t\t\tNOt Found");
        }
    }

    printf("\n\n\t\t\tEnter Any Key To Continue...");
    getch();
    system("cls");
}

void load_data_from_file(phone *ptr)
{
    int number;
    char name[30];
    FILE *file = fopen("read_data_and_load.txt", "r");

    while (fscanf(file, "%s %d\n", name, &number) != EOF)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = (phone *)malloc(sizeof(phone));
        ptr = ptr->next;
        strcpy(ptr->name, name);
        ptr->number = number;
        ptr->next = NULL;
    }

    fclose(file);
}

int main()
{
    phone *head;
    head = (phone *)malloc(sizeof(phone));
    head->next = NULL;

    load_data_from_file(head);

    while (1)
    {
        printf("\n\n\n\t\t\tWelcome To Phonebook\n");
        printf("\n\t\t\t1.Add New Contact");
        printf("\n\t\t\t2.View All Contact");
        printf("\n\t\t\t3.Update Contact");
        printf("\n\t\t\t4.Search Contact");
        printf("\n\t\t\t5.Delete Contact");
        printf("\n\t\t\t6.Quic Dail");
        printf("\n\t\t\t7.Show Call History");
        printf("\n\t\t\t8.Exit");

        printf("\n\n\t\t\tEnter Your Choice : ");
        switch (getch())
        {
        case '1':

            Add_New_Contact(head);
            break;
        case '2':
            View_All_Contact(head);
            break;
        case '3':
            Update_Contact(head);
            break;
        case '4':
            Search_Contact(head);
            break;
        case '5':
            Delete_Contact(head);
            break;
        }
    }
}
