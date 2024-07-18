#include <stdio.h>
void main ()
{
    printf("BUBBLE SORT\n");
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
        for (int j=0 ; j<n-i-1 ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("the sorted array is:\n");
    for (int i=0; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
}