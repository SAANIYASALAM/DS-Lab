#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left , *right;
};

struct node * create()
{
    int x;
    struct node* new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("enter the data (-1 if empty node):\n");
    scanf("%d",&x);
    if (x==-1)
    {
        return 0;
    }
    else 
    {
        new->data = x;
    }
    printf("enter the left child of %d :\n",x);
    new->left = create();
    printf("enter the right child of %d :\n",x);
    new->right = create();
    
    return new;
}

void preorder(struct node*root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node*root)
{
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void postorder(struct node*root)
{
    if (root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

void main()
{
    struct node * root;
    root = create();
    
    printf("\nthe preorder traversal is :\n");
    preorder (root);
    
    printf("\nthe inorder traversal is :\n");
    inorder (root);
    
    printf("\nthe postorder traversal is :\n");
    postorder (root);
}