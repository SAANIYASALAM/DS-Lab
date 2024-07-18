#include <stdio.h>

void sparse(int a[10][10], int m, int n)
{
    int i,j,s[10][10],k=1;
    s[0][0]=m;
    s[0][1]=n;
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
        }
    }
    s[0][2]=k-1;
    printf("tuple form:\n");
    for (i=0;i<k;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}

void transpose(int s[10][10], int m , int n)
{
    int i,j,t[10][10],k=1;
    t[0][0]=s[0][1];
    t[0][1]=s[0][0];
    t[0][2]=s[0][2];
    m= s[0][1];
    n= s[0][2];
    for (i=1;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[j][1]==i)
            {
                t[k][0]=s[j][1];
                t[k][1]=s[j][0];
                t[k][2]=s[j][2];
                k++;
            }
        }
    }
    printf("the transpose is:\n");
    for(int i=0;i<t[0][2];i++)
    {
        for(j=0;i<3;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i,j,a[10][10],m,n,s[10][10];
    printf("enter the no of rows and columns of the matrix:\n");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the matrix:\n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("the matrix:\n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    sparse(a,m,n);
    transpose(s,m,n);
}