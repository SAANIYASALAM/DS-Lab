#include <stdio.h>

void insertion_sort(int arr[], int n);
void display(int arr[], int n);

int main()
{
    printf("INSERION SORT\n");
    int arr[100], n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for (int i=0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    display(arr, n);
    
    return 0;
}

void insertion_sort(int arr[], int n)
{
    for(int i=0; i<n ; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1]= key;
    }
}

void display(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}