#include <stdio.h>
#include <stdlib.h>

typedef struct BST_NODE
{
    int data;
    struct BST_NODE *left;
    struct BST_NODE *right; 
} tree;

// Function to create a new tree node
tree *createNode(int data)
{
    tree *new_Node = (tree *)malloc(sizeof(tree));
    new_Node->data = data;
    new_Node->left = NULL;
    new_Node->right = NULL;
    return new_Node;
}

// Function to insert a new node into the tree
tree *insert(tree *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to print the tree in inorder traversal
void inorder_Traversal(tree *root)
{
    if (root != NULL)
    {
        inorder_Traversal(root->left);
        printf("%d ", root->data);
        inorder_Traversal(root->right);
    }
}

// Function to print the tree in preorder traversal
void preorder_Traversal(tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_Traversal(root->left);
        preorder_Traversal(root->right);
    }
}

// Function to print the tree in postorder traversal
void postorder_Traversal(tree *root)
{
    if (root != NULL)
    {
        postorder_Traversal(root->left);
        postorder_Traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free memory allocated for the tree nodes
void free_Tree_node(tree *root)
{
    if (root != NULL)
    {
        free_Tree_node(root->left);
        free_Tree_node(root->right);
        free(root);
    }
}

int main()
{
    // Create an empty tree
    tree *root = NULL;

    // Insert some elements into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 55);
    root = insert(root, 10);
    root = insert(root, 65);
    root = insert(root, 100);

    // Print the tree in inorder traversal
    printf("Inorder traversal of the tree  : ");
    inorder_Traversal(root);
    printf("\n\n");

    // Print the tree in preorder traversal
    printf("Preorder traversal of the tree : ");
    preorder_Traversal(root);
    printf("\n\n");

    // Print the tree in postorder traversal
    printf("postorder traversal of the tree: ");
    postorder_Traversal(root);
    printf("\n\n");

    // Free memory allocated for the tree nodes
    free_Tree_node(root);
    return 0;
}
