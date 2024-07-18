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

void main()
{
    int i,j,a[10][10],m,n;
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
}