
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct TREE
{
    char data;
    struct TREE *left, *right;
} tree;

tree *create_node()
{
    char x;
    tree *new_node = (tree *)malloc(sizeof(tree));
    printf("\n\t\tEnter Data : ");
    scanf("% c", &x);
    if (x == '0')
    {
        printf("\t\tTerminated\n");
        return 0;
    }
    new_node->data = x;
    printf("\n\t\tEnter left child of %c", x);
    new_node->left = create_node();
    printf("\n\t\tEnter right child of %c", x);
    new_node->right = create_node();
}

void Inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}

void Preorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    fflush(stdin);
    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}
int main()
{
    tree *root = NULL;

    while (1)
    {
        printf("\n\n\t\t\tTree Data Structure");
        printf("\n\t\t\t-------------------");
        printf("\n\n\t\t1.Create Tree\n");
        printf("\t\t2.Inorder\n");
        printf("\t\t3.Preorder\n");
        printf("\t\t4.Postorder\n");
        printf("\n\t\tEnter Any : ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            system("cls");
            printf("\n\n\t\t\tCreate Tree");
            printf("\n\t\t\t-----------\n");
            printf("\n\t\tFor Terminate Tree Press (-1)\n");
            root = create_node();
            if (root == NULL)
            {
                printf("\n\t\tTree Dosent Create\n");
            }
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n\n\t\t\tInorder");
            printf("\n\t\t\t-------\n");
            if (root == NULL)
            {
                printf("\n\n\t\tFirstly You  Must Create A Tree Then You Can Find Inorder\n");
            }
            else
            {
                Inorder(root);
            }
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n\n\t\t\tPreorder");
            printf("\n\t\t\t--------\n");
            if (root == NULL)
            {
                printf("\n\n\t\tFirstly You  Must Create A Tree Then You Can Find Preorder\n");
            }
            else
            {
                Preorder(root);
            }
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n\n\t\t\tPostorder");
            printf("\n\t\t\t---------\n");
            if (root == NULL)
            {
                printf("\n\n\t\tFirstly You  Must Create A Tree Then You Can Find Postorder\n");
            }
            else
            {
                Postorder(root);
            }
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            break;
        }
        }
    }
}