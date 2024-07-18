#include <stdio.h>

void binarysearch(int a[], int l, int h, int key)
{
    int mid;
    int flag=0;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(a[mid]==key)
        {
            flag=1;
            break;
        }
        else if(a[mid]>key)
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    if (flag==0)
    {
        printf("key not found\n");
    }
    else
    {
        printf("the key found\n");
    }
}


void main ()
{
    int a[100],n,key,flag;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the key to find\n");
    scanf("%d",&key);
    binarysearch(a,0,n-1,key);
}