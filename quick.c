#include<stdio.h>

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    int temp;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start ++;
        }
        while(a[end]>pivot)
        {
            end --;
        }
        if (start<end)
        {
            temp = a[start];
            a[start]= a[end];
            a[end]= temp;
        }
    }
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb<ub)
    {
        int loc = partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

void main()
{
    int a[100],n;
    int start,end,pivot,lb,ub;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lb=0;
    ub=n-1;
    quicksort(a,lb,ub);
    printf("the sorted elements are:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}