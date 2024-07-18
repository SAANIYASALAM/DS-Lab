#include <stdio.h>
int A[100],size,top;

void push(int item)
{
    if(top==size-1)
    {
        printf("stsck overflow\n");
    }
    else
    {
        top= top+1;
        A[top]=item;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("stsck underflow\n");
    }
    else
    {
        printf("the popped eleent is %d",A[top]);
        top= top-1;
    }
}

void display()
{
    if(top==-1)
    {
        printf("no elements in the stack");
    }
    else
    {
        printf("the stack elements are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d ",A[i]);
        }
    }
}

void status()
{
    float free;
    if (top==-1)
    {
        printf("stack empty");
    }
    else
    {
        printf("stack peek element is %d",A[top]);
        if(top==size-1)
        {
            printf("stack full");
        }
        else
        {
            free= (float)(size-top-1)*100/size;
            printf("the free space is :%f",free);
        }
    }
}

void main ()
{
    int opt,item;
    top=-1;
    printf("enter the sice of the stack:");
    scanf("%d",&size);
    printf("choose any option\n1.push\n2.pop\n3.display\n4.free space");
    do
    {
        printf("enter the choice:\n");
        scanf("%d",&opt);
        switch (opt)
        {
            case 1: printf("enter the element to push");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: status();
                    break;
        }
        
    }while (opt!=5);
    
}




















