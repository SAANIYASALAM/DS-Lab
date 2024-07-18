//HEAP SORT 

#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int temp;
    int largest = i ;
    int l = (2*i)+1;
    int r = (2*i)+2;
    while (l<=n && a[l]>a[largest])
    {
        largest = l;
    }
    while (r<=n && a[r]>a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    int temp;
    for (int i=(n/2)-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for (int i=n;i>=1;i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a,n,1);
    }
    
    for ( int i=n-1;i>0;i--)
    {
        temp = a[0];
        a[0]=a[i];
        a[i]= temp;
    }
}

int main()
{
    int n,temp,a[100];
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("the sorted elements are:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}