#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h> //for convert lowecase

// Structure for dictionary tree
typedef struct AVL_Dictionary
{
    char word[100];    // Key
    char meaning[200]; // Value
    struct AVL_Dictionary *left;
    struct AVL_Dictionary *right;
    int height;
} tree;

// Function to create a new tree
tree *createtree(char word[], char meaning[])
{
    tree *new_node = (tree *)malloc(sizeof(tree));
    if (new_node == NULL)
    {
        printf("\n\t\tMemory allocation failed.\n");
        return 0;
    }
    strcpy(new_node->word, word);
    strcpy(new_node->meaning, meaning);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

// Function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to get the height of a node
int height(tree *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int get_balance(tree *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Right rotate subtree rooted with y
tree *rotateRight(tree *y)
{
    tree *x = y->left;
    tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate subtree rooted with x
tree *rotateLeft(tree *x)
{
    tree *y = x->right;
    tree *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert a new tree into the AVL tree
tree *insert_word(tree *node, char word[], char meaning[])
{
    if (node == NULL)
        return createtree(word, meaning);

    // Case insensitive comparison
    int compare_ptr = strcasecmp(word, node->word);

    if (compare_ptr < 0)
        node->left = insert_word(node->left, word, meaning);
    else if (compare_ptr > 0)
        node->right = insert_word(node->right, word, meaning);
    else
        return node; // Duplicate word not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // Left Left Case
    if (balance > 1 && strcasecmp(word, node->left->word) < 0)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && strcasecmp(word, node->right->word) > 0)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && strcasecmp(word, node->left->word) > 0)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && strcasecmp(word, node->right->word) < 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Get the node with minimum value
tree *min_Value_tree(tree *node)
{
    tree *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Remove an tree from the AVL tree
tree *remove_word(tree *root, char word[])
{
    if (root == NULL)
        return root;

    int compare_ptr = strcasecmp(word, root->word);

    if (compare_ptr < 0)
        root->left = remove_word(root->left, word);
    else if (compare_ptr > 0)
        root->right = remove_word(root->right, word);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            tree *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            tree *temp = min_Value_tree(root->right);
            strcpy(root->word, temp->word);
            strcpy(root->meaning, temp->meaning);
            root->right = remove_word(root->right, temp->word);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Display dictionary entries --Inorder Traversal
void display_Dictionary(tree *root)
{
    if (root != NULL)
    {
        display_Dictionary(root->left);
        printf("\t\t%s----->%s\n", root->word, root->meaning);
        display_Dictionary(root->right);
    }
}

// Delete the AVL tree to free memory
void free_Dictionary(tree *root)
{
    if (root != NULL)
    {
        free_Dictionary(root->left);
        free_Dictionary(root->right);
        free(root);
    }
}

// Function to find the kth smallest key in the AVL tree
tree *kth_Smallest_Key(tree *root, int k)
{
    if (root == NULL)
        return NULL;

    tree *stack[100];
    int top = -1;
    tree *current = root;
    int count = 0;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        if (++count == k)
            return current;

        current = current->right;
    }
    return NULL;
}

int main()
{
    tree *root = NULL;

    while (1)
    {
        printf("\n\n\t\tAVL Dictionary:");
        printf("\n\t\t--------------\n");
        printf("\n\t\t1.Insert A Word.");
        printf("\n\t\t2.Find The Meaning Of A Word.");
        printf("\n\t\t3.Print All The Entries.");
        printf("\n\t\t4.Kth Smallest Key.");
        printf("\n\t\t5.Remove A Word.");
        printf("\n\t\t0.Exit.\n");
        printf("\n\t\tPlease choose an option : ");
        int option;
        scanf(" %d", &option);
        char word[10], meaning[20];
        int k;
        switch (option)
        {
        case 1:
        {
            system("cls");
            printf("\n\t\tEnter a word to insert: ");
            scanf("%s", word);
            // Convert word to lowercase
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);
            printf("\n\t\tEnter its meaning: ");
            scanf(" %[^\n]", meaning);
            root = insert_word(root, word, meaning);
            printf("\n\t\tWord inserted successfully.\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }

        case 2:
        {
            system("cls");
            printf("\n\t\tEnter a word to find its meaning : ");
            scanf("%s", word);

            // Convert word to lowercase
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);
            tree *ptr = root;

            while (ptr != NULL)
            {
                int compare_ptr = strcasecmp(word, ptr->word);
                if (compare_ptr == 0)
                {
                    printf("\n\t\tMeaning: %s\n", ptr->meaning);
                    break;
                }
                else if (compare_ptr < 0)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            if (ptr == NULL)
                printf("\n\t\tWord not found.\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }

        case 3:
        {
            system("cls");
            printf("\n\t\tAll Entries in the dictionary:\n");
            printf("\n\t\tWord----->meaning");
            printf("\n\t\t-----------------\n");
            display_Dictionary(root);
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }

        case 4:
        {
            system("cls");
            printf("\n\t\tEnter the value of k : ");
            scanf("%d", &k);
            tree *kthtree = kth_Smallest_Key(root, k);
            if (kthtree != NULL)
                printf("\n\t\tThe %dth smallest key is : %s\n", k, kthtree->word);
            else
                printf("\n\t\tInvalid value of k.\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            printf("\n\t\tEnter a word to remove : ");
            scanf("%s", word);

            // Convert word to lowercase
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);
            root = remove_word(root, word);
            printf("\n\t\tWord removed successfully.\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }

        case 0:
        {
            free_Dictionary(root);
            printf("\n\t\tExiting program.\n");
            exit(0);
        }
        default:
        {
            system("cls");
            printf("\n\t\tInvalid option. Please choose again.\n");
        }
        }
    }
    return 0;
}
