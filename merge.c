//MERGE SORT 
#include <stdio.h>

void merge(int a[],int lb, int mid, int ub)
{
    int i = lb;
    int j = mid+1;
    int k = lb;
    int b[100];
    while(i<=mid && j<=ub)
    {
        if (a[i]<=a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else 
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (i>mid)
    {
        while (j<=ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int i=lb;i<=ub;i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int a[], int lb, int ub)
{
    if (lb<ub)
    {
        int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void main()
{
    int a[100],n,b[100];
    int lb,ub;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lb=0;
    ub=n-1;
    mergesort(a,lb,ub);
    printf("the sorted elements are:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}

