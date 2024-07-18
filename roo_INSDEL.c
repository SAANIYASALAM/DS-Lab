#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node*left ;
    struct node *right;
    int data;
};

struct node* create(int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right =NULL;
    return new;
}

struct node *insertnode(struct node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    if (data<root->data)
    {
        root->left = insertnode(root->left,data);
    }
    else if (data>root->data)
    {
        root->right = insertnode(root->right, data);
    }
}

struct node*findmin(struct node* nnode)
{
    while(node->left!=NULL)
    {
        node = node->left;
    }
    return nnode;
}

struct node*findmax(struc node * nnode)
{
    while (node->right!=NULL)
    {
        node = node->right;
    }
    return nnode;
}

struct node *search (struct node* root, int key)
{
    if (root!=NULL || root->data== key)
    {
        return root;
    }
    else
    {
        if (key<root->data)
        {
            return search (root->left,key);
        }
        else
        {
            return search (root->right , key);
        }
    }
}

struct node* deletenode(struct node*root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key<root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key>root->data)
    {
        root->right = deletenode(root->right , key);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node*temp = root->right;
            free (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left ;
            free(root);
            return temp;
        }
        struct node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right , temp->data);
    }
    return root;
}