// AVL using C

//https://www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-82/

#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int data)
{
  struct Node *node = (struct Node *)
      malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int data)
{
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(data));

  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
                         height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && data < node->left->data)
    return rightRotate(node);

  if (balance < -1 && data > node->right->data)
    return leftRotate(node);

  if (balance > 1 && data > node->left->data)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && data < node->right->data)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node)
{
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int data)
{
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);

  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  else
  {
    if ((root->left == NULL) || (root->right == NULL))
    {
      struct Node *temp = root->left ? root->left : root->right;

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
      struct Node *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
                         height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
void print_inorder(struct Node *root)
{
  if (root != NULL)
  {
    printPreOrder(root->left);
    printf("%d ", root->data);
    printPreOrder(root->right);
  }
}

void print_postorder(struct Node *root)
{
  if (root != NULL)
  {
    printPreOrder(root->left);
    printf("%d ", root->data);
    printPreOrder(root->right);
    printf("%d ", root->data);
  }
}

int main()
{
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printf("\nAfter Insert All: \n");

  printf("\nPre-Oder : ");
  printPreOrder(root);

  printf("\nIn-Oder : ");
  print_inorder(root);

  printf("\nPost-Oder : ");
  print_postorder(root);

  root = deleteNode(root, 3);

  printf("\n\nAfter Delete: 3\n\n");
  printf("Pre-Oder : ");
  printPreOrder(root);

  printf("\nIn-Oder : ");
  print_inorder(root);

  printf("\nPost-Oder : ");
  print_postorder(root);

  return 0;
}