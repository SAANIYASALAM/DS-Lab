// polynomial addition and multiplcation using arrays 

#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};
struct poly p1[10], p2[10], p3[10];

int readpoly(struct poly p[])
{
    int t;
    printf("enter the number of terms in the polynomial:\n");
    scanf("%d",&t);
    printf("enter the coeffeciet and exponent of the polynomial:\n");
    for (int i=0;i<t;i++)
    {
        scanf("%d%d",&p[i].coeff,&p[i].expo);
    }
    return t;
}

void displaypoly(struct poly p[], int t)
{
    int i;
    for (int i=0;i<t-1;i++)
    {
        printf("%dx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%dx^%d ", p[i].coeff , p[i].expo);
}

int addpoly(struct poly p1[], struct poly p2[], int t1, int t2)
{
    int i=0, j=0, k=0;
    while (i<t1 && j< t2)
    {
        if (p1[i].expo == p2[j].expo)
        {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff + p2[i].coeff;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else if (p2[j].expo > p1[i].expo)
        {
            p3[k].expo = p2[j].expo;
            p3[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
    }
    while (i<t1)
    {
        p3[k].expo = p1[i].expo;
        p3[k].coeff = p1[i].coeff;
        i++;
        k++;
    }
    while (j<t2)
    {
        p3[k].expo = p2[j].expo;
        p3[k].coeff = p3[j].coeff;
        j++;
        k++;
    }
    return k;
}

void main()
{
    int t1 = readpoly(p1);
    displaypoly(p1,t1);
    
    int t2 = readpoly(p2);
    displaypoly(p2,t2);
    
    int t3 = addpoly(p1,p2,t1,t2);
    printf("the added polynomial is:\n");
    displaypoly(p3,t3);
}


