#include <stdio.h>
void printsparse(int s[10][10], int k)
{
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}
void sparse(int a[10][10], int m, int n, int s[10][10])
{
    int i,j,k=1;
    s[0][0]=m;
    s[0][1]=n;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
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
    printsparse(s,k);
}

void addsparse(int s[10][10],int t[10][10])
{
    int r1,c1,r2,c2,m,n,i,j,k,r[10][3];
    r1=s[0][0];
    r2=t[0][0];
    c1=s[0][1];
    c2=t[0][1];
    if(r1!=r2&&c1!=c2)
    {
        printf("the addition not possible\n");
    }
    else
    {
        r[0][0]=s[0][0];
        r[0][1]=s[0][1];
        m=1;n=1;k=1;
        for (i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                if(s[m][0]==i&&s[m][1]==j&&t[n][0]==i&&t[n][1]==j)
                {
                    r[k][0]=s[m][0];
                    r[k][1]=s[m][1];
                    r[k][2]=s[m][2]+t[m][2];
                    m++;
                    n++;
                    k++;
                }
                else if (s[m][0]==i&&s[m][1]==j)
                {
                    r[k][0]=s[m][0];
                    r[k][1]=s[m][1];
                    r[k][2]=s[m][2];
                    m++;k++;
                }
                else if(t[n][0]==i&&t[n][1]==j)
                {
                    r[k][0]=t[n][0];
                    r[k][1]=t[n][1];
                    r[k][2]=t[n][2];
                    n++;k++;
                }
            }
        }
        r[0][2]=k-1;
    }
    
}
void main()
{
    int a[10][10],b[10][10],m1,n1,m2,n2,s[10][10],t[10][10];
    printf("enter the number of rows and columns of the first matrix:\n");
    scanf("%d%d",&m1,&n1);
    printf("enter te matrix:");
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("matrix1:\n");
    for (int i=0;i<m1;i++)
    {
        for (int j=0;j<n1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("the sparse matrix1 is:\n");
    sparse(a,m1,n1,s);
    printf("enter the number of rows and columns of the second matrix:\n");
    scanf("%d%d",&m2,&n2);
    printf("enter te matrix:");
    for (int i=0;i<m2;i++)
    {
        for (int j=0;j<n2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("matrix1:\n");
    for (int i=0;i<m2;i++)
    {
        for (int j=0;j<n2;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("the sparse matrix2 is:\n");
    sparse(b,m2,n2,t);
}