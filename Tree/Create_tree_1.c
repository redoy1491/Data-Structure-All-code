#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dataey;
    struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->dataey = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->dataey);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given dataey in BST */
struct Node *insert(struct Node *node, int dataey)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(dataey);

    /* Otherwise, recur down the tree */
    if (dataey < node->dataey)
        node->left = insert(node->left, dataey);
    else
        node->right = insert(node->right, dataey);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a binary search tree and a dataey, this function deletes the dataey and returns the new root */
struct Node *deleteNode(struct Node *root, int data)
{
    // Base case
    if (root == NULL)
        return root;

    // If the dataey to be deleted is smaller than the root's dataey, then it lies in the left subtree
    if (data < root->dataey)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    // If the dataey to be deleted is greater than the root's dataey, then it lies in the right subtree
    else if (data > root->dataey)
    {
        root->right = deleteNode(root->right, data);
        return root;
    }

    // If dataey is same as root's dataey, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL)
    {
        struct Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node *temp = root->left;
        free(root);
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    struct Node *succParent = root;
    struct Node *succ = root->right;
    while (succ->left != NULL)
    {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->dataey = succ->dataey;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    free(succ);
    return root;
}

// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Original BST: ");
    inorder(root);

    printf("\n\nDelete a Leaf Node: 20\n");
    root = deleteNode(root, 20);
    printf("Modified BST tree after deleting Leaf Node:\n");
    inorder(root);

    printf("\n\nDelete Node with single child: 70\n");
    root = deleteNode(root, 70);
    printf("Modified BST tree after deleting single child Node:\n");
    inorder(root);

    printf("\n\nDelete Node with both child: 50\n");
    root = deleteNode(root, 50);
    printf("Modified BST tree after deleting both child Node:\n");
    inorder(root);

    return 0;
}
