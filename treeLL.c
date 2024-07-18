#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *lc,*rc;
}

createtree(struct tree*ptr)
{
    struct tree *lcptr,*rcptr;
    int ch;
    if (ptr!=NULL)
    {
        printf("enter the data:\n");
        scanf("%d",&ptr->data);
        ptr->lc=NULL;
        ptr->rc=NULL;
        printf("left child?%d\n",ptr->data);
        scanf("%d",&ch);
        if (ch==1)
        {
            lcptr = (struct tree*)malloc (sizeof(struct tree));
            ptr->lc = lcptr;
            createtree(lcptr);
        }
        printf("right child?%d\n",ptr->data);
        scanf("%d",&ch);
        if (ch==1)
        {
            rcptr = (struct tree*)malloc (sizeof(struct tree));
            ptr->rc = rcptr;
            createtree(rcptr);
        }
        printf("right child?%d\n",ptr->data);
        
    }
}

void inorder(struct tree*ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lc);
        printf("%d ",ptr->data);
        inorder(ptr->rc);
    }
}

void preorder(struct tree*ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}

void postorder(struct tree*ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lc);
        postorder(ptr->rc);
        printf("%d ",ptr->data);
    }
}


void main()
{
    struct tree* root;
    root = (struct tree*)malloc (sizeof(struct tree));
    createtree(root);
    printf("inorder:\n");
    inorder(root);
    printf("preorder:\n");
    preorder(root);
    printf("postorder:\n");
    postorder(root);
}