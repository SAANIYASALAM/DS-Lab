#include <stdio.h>

void tree(int a[], int i, int item)
{
    int ch, val;
    a[i]= item;
    printf("left child?(1/0)%d: \n",item);
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("enter the left child:\n");
        scanf("%d",&val);
        tree(a,2*i,val);
    }
    printf("right child?(1/0)%d: \n",item);
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("enter the value:");
        scanf("%d",&val);
        tree (a,2*i+1,val);
    }
}

void main()
{
    int a[100],item;
    for (int i=0;i<100;i++)
    {
        a[i]=-1;
    }
    printf("enter the root node: ");
    scanf("%d",&item);
    tree(a,1,item);
    printf("\nTREE\n");
    for (int i=1;i<16;i++)
    {
        if(a[i]==-1)
        {
            printf("- ");
        }
        else
        {
            printf("%d ",a[i]);
        }
    }
    
}