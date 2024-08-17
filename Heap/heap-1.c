#include <stdio.h>

int tree_array_size = 11;
int heap_size = 10;

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

// function to get right child of a node of a tree
int get_right_child(int A[], int index)
{
    if ((((2 * index) + 1) < tree_array_size) && (index >= 1))
        return (2 * index) + 1;
    return -1;
}

// function to get left child of a node of a tree
int get_left_child(int A[], int index)
{
    if (((2 * index) < tree_array_size) && (index >= 1))
        return 2 * index;
    return -1;
}

// function to get the parent of a node of a tree
int get_parent(int A[], int index)
{
    if ((index > 1) && (index < tree_array_size))
    {
        return index / 2;
    }
    return -1;
}

void max_heapify(int A[], int index)
{
    int left_child_index = get_left_child(A, index);
    int right_child_index = get_right_child(A, index);

    // finding largest among index, left child and right child
    int largest = index;

    if ((left_child_index <= heap_size) && (left_child_index > 0))
    {
        if (A[left_child_index] > A[largest])
        {
            largest = left_child_index;
        }
    }

    if ((right_child_index <= heap_size && (right_child_index > 0)))
    {
        if (A[right_child_index] > A[largest])
        {
            largest = right_child_index;
        }
    }

    // largest is not the node, node is not a heap
    if (largest != index)
    {
        swap(&A[index], &A[largest]);
        max_heapify(A, largest);
    }
}

void build_max_heap(int A[])
{
    int i;
    for (i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(A, i);
    }
}

int main()
{
    // tree is starting from index 1 and not 0
    int A[] = {0, 15, 20, 7, 9, 5, 8, 6, 10, 2, 1};
    build_max_heap(A);
    int i;
    for (i = 1; i <= heap_size; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}
