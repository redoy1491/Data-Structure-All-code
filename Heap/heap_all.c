#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insert(int *heap, int *size, int value);
int deleteRoot(int *heap, int size);
void heapify(int *heap, int size, int i);
void printHeap(int *heap, int size);
void menu();
void heapSort(int *heap, int size);

int main()
{
    int heap[100]; // Array to store the heap elements
    int size = 0;  // Current size of the heap
    int choice, value;

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(heap, &size, value);
            break;
        case 2:
            size = deleteRoot(heap, size);
            break;
        case 3:
            printf("Current heap: ");
            printHeap(heap, size);
            break;
        case 4:
            printf("Sorted heap: ");
            heapSort(heap, size);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void menu()
{
    printf("\n--- Max Heap Operations ---\n");
    printf("1. Insert\n");
    printf("2. Delete Root\n");
    printf("3. Display Heap\n");
    printf("4. Heap Sort\n");
    printf("5. Exit\n");
}

// Function to insert a new value into the heap
void insert(int *heap, int *size, int value)
{
    if (*size >= 100)
    {
        printf("Heap is full\n");
        return;
    }

    // Insert the new element at the end of the heap
    heap[*size] = value;
    int i = *size;
    (*size)++; // Increase the size of the heap

    // Fix the max-heap property if it is violated
    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        // Swap heap[i] with heap[(i - 1) / 2]
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;

        i = (i - 1) / 2; // Move to the parent index
    }
}

// Function to delete the root of the heap and return the new size
int deleteRoot(int *heap, int size)
{
    if (size <= 0)
    {
        printf("Heap is empty\n");
        return size;
    }
    else if (size == 1)
    {
        return size - 1; // If there's only one element, remove it
    }

    // Move the last element to root and reduce heap size
    heap[0] = heap[size - 1];
    size--;

    // Fix the max-heap property from the root
    heapify(heap, size, 0);

    return size;
}

// Function to maintain the max-heap property
void heapify(int *heap, int size, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        // Swap heap[i] with heap[largest]
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(heap, size, largest);
    }
}

// Function to perform heap sort and display the sorted elements
void heapSort(int *heap, int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);

    // One by one extract elements from heap
    for (int i = size - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // Call heapify on the reduced heap
        heapify(heap, i, 0);
    }

    // Print the sorted elements
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Function to print the elements of the heap
void printHeap(int *heap, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
