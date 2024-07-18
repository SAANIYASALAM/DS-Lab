#include <stdio.h>
void main ()
{
    printf("SELECTION SORT\n");
    int arr[100],n, temp;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements of the array\n");
    for (int i=0;i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i =0; i<n ; i++)
    {
        for (int j=i+1 ; j<n ; j++)
        {
            if (arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("the sorted array is:\n");
    for (int i=0; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
}