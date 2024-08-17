#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for student record
typedef struct Student
{
    int id;
    float cgpa;
    char name[50];
    struct Student *prev;
    struct Student *next;
} Student;

// Function to create a new student node
Student* createNode(int id, float cgpa, const char *name)
{
    Student *newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    newNode->cgpa = cgpa;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new student record to the doubly linked list
void addStudent(Student **head_ref, int id, float cgpa, const char *name)
{
    Student *newNode = createNode(id, cgpa, name);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
    }
    else
    {
        Student *current = *head_ref;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to view all student records
void viewAllRecords(Student *head)
{
    if (head == NULL)
    {
        printf("No records found.\n");
        return;
    }
    printf("Student Records:\n");
    Student *current = head;
    while (current != NULL)
    {
        printf("ID: %d, Name: %s, CGPA: %.2f\n", current->id, current->name, current->cgpa);
        current = current->next;
    }
}

// Function to update a student record
void updateRecord(Student *head, int id, float new_cgpa)
{
    if (head == NULL)
    {
        printf("No records found.\n");
        return;
    }
    Student *current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            current->cgpa = new_cgpa;
            printf("Record updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Record not found.\n");
}

// Function to delete a student record
void deleteRecord(Student **head_ref, int id)
{
    if (*head_ref == NULL)
    {
        printf("No records found.\n");
        return;
    }
    Student *current = *head_ref;
    while (current != NULL)
    {
        if (current->id == id)
        {
            if (current->prev == NULL)
            {
                *head_ref = current->next;
            }
            else
            {
                current->prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            printf("Record deleted successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Record not found.\n");
}

// Function to count the number of student records
int countRecords(Student *head)
{
    int count = 0;
    Student *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Function to free memory allocated for student records
void freeRecords(Student *head)
{
    Student *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to display menu options
void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Add new student\n");
    printf("2. View all records\n");
    printf("3. Update record\n");
    printf("4. Delete record\n");
    printf("5. Count records\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Main function to handle user input
int main()
{
    Student *head = NULL;
    int choice, id;
    float cgpa;
    char name[50];

    // Initialize an empty node
    head = (Student*)malloc(sizeof(Student));

    while (true)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ID : ");
            scanf("%d",&id);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]s",name);
            fflush(stdin);
            printf("Enter CGPA : ");
            scanf("%f",&cgpa);
            fflush(stdin);
            addStudent(&head, id, cgpa, name);
            break;
        case 2:
            viewAllRecords(head->next); // Skip the empty node
            break;
        case 3:
            printf("Enter ID and new CGPA: ");
            scanf("%d %f", &id, &cgpa);
            updateRecord(head->next, id, cgpa); // Skip the empty node
            break;
        case 4:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecord(&head->next, id); // Skip the empty node
            break;
        case 5:
            printf("Total number of records: %d\n", countRecords(head->next)); // Skip the empty node
            break;
        case 6:
            freeRecords(head);
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
