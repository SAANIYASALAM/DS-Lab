#include <stdio.h>

struct poly
{
  int coeff;
  int expo;
} p1[10], p2[10], p3[10];

int addpoly (struct poly[], struct poly[], int, int, struct poly[]);
void displaypoly (struct poly[], int terms);
int readpoly (struct poly[]);

void main ()
{
    int t1,t2,t3;
    
    printf("FIRST POLYNOMIAL\n");
    t1 = readpoly(p1);
    printf("P1:\n");
    displaypoly(p1,t1);
    
    printf("\nSECOND POLYNOMIAL\n");
    t2 = readpoly(p2);
    printf("P2:\n");
    displaypoly(p2,t2);
    
    printf("\nRESULTANT POLYNOMIAL IS:\n");
    t3 = addpoly(p1,p2,t1,t2,p3);
    printf("P3:\n");
    displaypoly(p3,t3);
}

int readpoly(struct poly p[10])
{
    int t;
    printf("enter the number of terms in the polynomial\n");
    scanf("%d",&t);
    printf("Enter the coeffecient and exponent of the polynomial in decreasing order of coeffecient\n");
    for(int i=0; i<t ; i++)
    {
        printf("enter the %d coeffecient:\n",i+1);
        scanf("%d",&p[i].coeff);
        printf("enter the %d exponent:\n",i+1);
        scanf("%d",&p[i].expo);
    }
    return(t);
}

int addpoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10])
{
    int i=0,j=0,k=0;
    while (i<t1 && j<t2)
    {
        if (p1[i].expo==p2[j].expo)
        {
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            k++ ; j++ ; i++ ;
        }
        else if (p1[i].expo>p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            k++; i++;
        }
        else if (p2[j].expo>p1[i].expo)
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            k++; j++;
        }
    }
    while (i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        k++; i++;
    }
    while (j<t2)
    {
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++; k++;
    }
    return(k);
}

void displaypoly(struct poly p[10], int term)
{
    for (int i=0;i<term-1;i++)
    {
        printf("%d x^%d + ",p[i].coeff,p[i].expo);
    }
    printf("%d x^%d",p[term-1].coeff,p[term-1].expo);
}



































